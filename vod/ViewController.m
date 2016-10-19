//
//  ViewController.m
//  vod
//
//  Created by 王博 on 16/7/18.
//  Copyright © 2016年 FlashHandR4L. All rights reserved.
//

#import "ViewController.h"
#import "libnetclient.h"
#import "avcodec.h"
#import "swscale.h"
#import "OpenGLView20.h"
#define INVALID_HANDLE_VALUE (HANDLE)-1

static ViewController *selfMirror=nil;
static CGColorSpaceRef colorSpace;
static int bitmapInfo = kCGBitmapByteOrderDefault;
static CGColorRenderingIntent renderingIntent = kCGRenderingIntentDefault;
static  AVCodec *codec;
static AVCodecContext *c= NULL;
static struct SwsContext * sws;

@interface ViewController ()
{
    OpenGLView20 *glView;
}
@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    colorSpace = CGColorSpaceCreateDeviceRGB();
    [self.view setBackgroundColor:[UIColor blackColor]];
//    _videoLayer=[CALayer new];
//    [_videoLayer setFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
//    [self.view.layer addSublayer:_videoLayer];
//    [_videoLayer setBorderWidth:2];
//    [_videoLayer setBorderColor:[UIColor greenColor].CGColor];
//    [_videoLayer setMasksToBounds:YES];
//    [_videoLayer setCornerRadius:10];
    
    //初始化
    glView = [[OpenGLView20 alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.width*720/1280)];
    [self.view addSubview:glView];
    //设置视频原始尺寸
    [glView setVideoSize:1280 height:720];
    //渲染yuv

    
    avcodec_register_all();

    codec=avcodec_find_decoder(AV_CODEC_ID_H264);
    
    
    c = avcodec_alloc_context3(codec);
    if (avcodec_open2(c, codec,NULL) < 0) {
        fprintf(stderr, "could not open codec\n");
        exit(1);
    }
    
    sws = sws_getContext(1280, 720,
                                      AV_PIX_FMT_YUV420P, 1280, 720,
                                      AV_PIX_FMT_RGB32, 0, 0, 0, 0);

    
    int client=[libnetclient Network_ClientInit];
    HDEVICE l=0;
    char addr[]="d00245217";
    char user[]="Admin";
    char pwd[]="100688";
    int code=[libnetclient Network_ClientLogin:&l addr:addr port:6001 user:user pwd:pwd];
    NSLog(@"success？%d",code);
    LiveConnect cConnectInfo;
    cConnectInfo.dwChannel = 0;
    cConnectInfo.hPlayWnd = NULL;
    // 启动实时流
    HANDLE m_hLive = 0 ;
    int nRet=[libnetclient Network_ClientStartLive:&m_hLive dev:l info:&cConnectInfo callback:ReadDatacbf private:1];
        if (nRet != eRetSuccess || INVALID_HANDLE_VALUE == m_hLive){
            NSLog(@"完蛋");
        }

    
    // Do any additional setup after loading the view, typically from a nib.
    selfMirror= self;
    
}

static int CALLBACK ReadDatacbf(HLIVE hStream, BYTE *pDataBuf, DWORD dwDataLen, DWORD dwUserData){
    [selfMirror receivedRawVideoFrame:pDataBuf withSize:dwDataLen];
    return 0;
}

-(void)receivedRawVideoFrame:(uint8_t *)frame withSize:(uint32_t)frameSize{
    uint8_t headLength=44;
    uint8_t *header_part=(uint8_t *)malloc(sizeof(uint8_t) * headLength);
    frame_header_t *header=(frame_header_t *)memcpy(header_part, frame, headLength);
    int width=(*header).width;
    int height=(*header).height;
    uint8_t *body_part=(uint8_t *)malloc(sizeof(uint8_t) * frameSize-44);
    uint8_t *body=(uint8_t *)memcpy(body_part, &frame[44], frameSize-44);
    AVFrame *codec_frame=av_frame_alloc();
    int bytes_num = avpicture_get_size(AV_PIX_FMT_RGB24, (*header).width, (*header).height);
    uint8_t* buff = (uint8_t*)av_malloc(bytes_num);
    avpicture_fill((AVPicture*)frame, buff, AV_PIX_FMT_RGB24,width, height);

    
    int got_picture;
    AVPacket avpkt;
    av_init_packet(&avpkt);
    avpkt.size=frameSize-headLength;
    avpkt.data=body;
   int len = avcodec_decode_video2(c, codec_frame, &got_picture, &avpkt);
    if (len < 0) {
//        fprintf(stderr, "Error while decoding frame %d\n", codec_frame);
        NSLog(@"错了");
        return ;
    }
    char *buf = (char *)malloc(codec_frame->width * codec_frame->height * 3 / 2);
//
//    int w, h, i;
    char *y, *u, *v;
    y = buf;
    u = y + width * height;
    v = u + width * height / 4;

    memcpy(y , codec_frame->data[0], width * height);
    memcpy(u , codec_frame->data[1] , width * height / 4);
    memcpy(v , codec_frame->data[2] , width * height / 4);
//
//    
//    NSMutableData *y=[[NSMutableData alloc]initWithBytes:codec_frame->data[0] length:width*height];
//    [y appendBytes:codec_frame->data[1] length:width*height / 4];
//    [y appendBytes:codec_frame->data[2] length:width*height / 4];
    [glView displayYUV420pData:buf width:1280 height:720];
        free(buf);


//    AVPicture pic,yuv;
//    avpicture_alloc(&pic,AV_PIX_FMT_RGB32,1280,720);
//    avpicture_fill(&yuv,codec_frame->data,PIX_FMT_YUV420P,width,height);
//
//    sws_scale(sws, yuv.data, yuv.linesize, 0, height, pic.data, pic.linesize);
//    CVPixelBufferRef pixelBuffer=[self yuvPixelBufferWithData:codec_frame->data width:1280 heigth:720];
//    
//    CIImage *ciImage = [[CIImage alloc] initWithCVPixelBuffer:pixelBuffer];
//
//    UIImage *image= [UIImage imageWithCIImage:ciImage];//:newImage scale:1.0  orientation:UIImageOrientationRight];
    
//    CGContextRef context = CGBitmapContextCreate(NULL,
//                                                 (*header).width,
//                                                 (*header).height,
//                                                 8,
//                                                 (*header).width*4,
//                                                 colorSpace,
//                                                 bitmapInfo);
//    size_t bufferLength = width * height * 3;
//    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, pic.data, bufferLength, NULL);
////
//    CGImageRef iref = CGImageCreate(width,
//                                    height,
//                                    8,
//                                    24,
//                                    width*3,
//                                    colorSpace,
//                                    bitmapInfo, 
//                                    provider,
//                                    NULL,
//                                    NO,
//                                    renderingIntent);
//    [_videoLayer setContents:(__bridge id)image.CGImage];
//    CGDataProviderRelease(provider);
    
    free(body_part);
    free(header_part);
    av_free(codec_frame);

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
@end

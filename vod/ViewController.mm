//
//  ViewController.m
//  vod
//
//  Created by 王博 on 16/7/18.
//  Copyright © 2016年 FlashHandR4L. All rights reserved.
//

#import "ViewController.h"
#import <VideoToolbox/VideoToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import "libnetclient.h"
#define INVALID_HANDLE_VALUE (HANDLE)-1
static NSString * const naluTypesStrings[] =
{
    @"0: Unspecified (non-VCL)",
    @"1: Coded slice of a non-IDR picture (VCL)",    // P frame
    @"2: Coded slice data partition A (VCL)",
    @"3: Coded slice data partition B (VCL)",
    @"4: Coded slice data partition C (VCL)",
    @"5: Coded slice of an IDR picture (VCL)",      // I frame
    @"6: Supplemental enhancement information (SEI) (non-VCL)",
    @"7: Sequence parameter set (non-VCL)",         // SPS parameter
    @"8: Picture parameter set (non-VCL)",          // PPS parameter
    @"9: Access unit delimiter (non-VCL)",
    @"10: End of sequence (non-VCL)",
    @"11: End of stream (non-VCL)",
    @"12: Filler data (non-VCL)",
    @"13: Sequence parameter set extension (non-VCL)",
    @"14: Prefix NAL unit (non-VCL)",
    @"15: Subset sequence parameter set (non-VCL)",
    @"16: Reserved (non-VCL)",
    @"17: Reserved (non-VCL)",
    @"18: Reserved (non-VCL)",
    @"19: Coded slice of an auxiliary coded picture without partitioning (non-VCL)",
    @"20: Coded slice extension (non-VCL)",
    @"21: Coded slice extension for depth view components (non-VCL)",
    @"22: Reserved (non-VCL)",
    @"23: Reserved (non-VCL)",
    @"24: STAP-A Single-time aggregation packet (non-VCL)",
    @"25: STAP-B Single-time aggregation packet (non-VCL)",
    @"26: MTAP16 Multi-time aggregation packet (non-VCL)",
    @"27: MTAP24 Multi-time aggregation packet (non-VCL)",
    @"28: FU-A Fragmentation unit (non-VCL)",
    @"29: FU-B Fragmentation unit (non-VCL)",
    @"30: Unspecified (non-VCL)",
    @"31: Unspecified (non-VCL)",
};
static ViewController *selfMirror=nil;

@interface ViewController ()
@property (nonatomic, assign) CMVideoFormatDescriptionRef formatDesc;
@property (nonatomic, assign) VTDecompressionSessionRef decompressionSession;
@property (nonatomic, retain) AVSampleBufferDisplayLayer *videoLayer;
@property (nonatomic, assign) size_t spsSize;
@property (nonatomic, assign) size_t ppsSize;
@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    _videoLayer = [[AVSampleBufferDisplayLayer alloc] init];
    _videoLayer.frame = self.view.frame;
    _videoLayer.bounds = self.view.bounds;
    _videoLayer.videoGravity = AVLayerVideoGravityResizeAspect;
    
   
    CMTimebaseRef controlTimebase;
    CMTimebaseCreateWithMasterClock(CFAllocatorGetDefault(), CMClockGetHostTimeClock(), &controlTimebase);
    
    //videoLayer.controlTimebase = controlTimebase;
    CMTimebaseSetTime(self.videoLayer.controlTimebase, kCMTimeZero);
    CMTimebaseSetRate(self.videoLayer.controlTimebase, 1.0);
    
    [[self.view layer] addSublayer:_videoLayer];
    
    int client=[libnetclient Network_ClientInit];
    HDEVICE l=0;
    char addr[]="d00245217";
    char user[]="Admin";
    char pwd[]="100688";
    int code=[libnetclient Network_ClientLogin:&l addr:addr port:6001 user:user pwd:pwd];
    NSLog(@"success？%d",code);
    LiveConnect cConnectInfo;
    cConnectInfo.dwChannel = 1;
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

+(void)dc{
    
}
static int CALLBACK ReadDatacbf(HLIVE hStream, BYTE *pDataBuf, DWORD dwDataLen, DWORD dwUserData){
    [selfMirror receivedRawVideoFrame:pDataBuf withSize:dwDataLen isIFrame:0];
    return 0;
}

-(void)receivedRawVideoFrame:(uint8_t *)frame withSize:(uint32_t)frameSize isIFrame:(int)isIFrame
{
    OSStatus status;
    
    uint8_t *data = NULL;
    uint8_t *pps = NULL;
    uint8_t *sps = NULL;
    
    int startCodeIndex = 0;
    int secondStartCodeIndex = 0;
    size_t thirdStartCodeIndex = 0;
    
    long blockLength = 0;
    
    CMSampleBufferRef sampleBuffer = NULL;
    CMBlockBufferRef blockBuffer = NULL;
    uint8_t headLength=44;
    uint8_t *header_part=(uint8_t *)malloc(sizeof(uint8_t) * headLength);
    frame_header_t *header=(frame_header_t *)memcpy(header_part, frame, headLength);
    uint8_t *body_part=(uint8_t *)malloc(sizeof(uint8_t) * frameSize-44);
    uint8_t *body=(uint8_t *)memcpy(body_part, &frame[44], frameSize-44);
    status =CMVideoFormatDescriptionCreate(kCFAllocatorDefault, kCMVideoCodecType_422YpCbCr8,  (*header).width, (*header).height, NULL, &_formatDesc);

    NSLog(@"\t\t Creation of CMVideoFormatDescription: %@", (status == noErr) ? @"successful!" : @"failed...");
    if(status != noErr) NSLog(@"\t\t Format Description ERROR type: %d", (int)status);
    if((status == noErr) && (_decompressionSession == NULL))
    {
        [self createDecompSession];
    }
    
    blockLength = frameSize-headLength;
    data = (uint8_t*)malloc(blockLength);
    data = (uint8_t*)memcpy(data, &frame[44], blockLength);
    
    // again, replace the start header with the size of the NALU
//    uint32_t dataLength32 = htonl (blockLength - 4);
//    memcpy (data, &dataLength32, sizeof (uint32_t));
    
    status = CMBlockBufferCreateWithMemoryBlock(NULL, data,  // memoryBlock to hold data. If NULL, block will be alloc when needed
                                                blockLength,  // overall length of the mem block in bytes
                                                kCFAllocatorNull, NULL,
                                                0,     // offsetToData
                                                blockLength,  // dataLength of relevant data bytes, starting at offsetToData
                                                0, &blockBuffer);
    
    NSLog(@"\t\t BlockBufferCreation: \t %@", (status == kCMBlockBufferNoErr) ? @"successful!" : @"failed...");

    // now create our sample buffer from the block buffer,
    if(status == noErr)
    {
        const size_t sampleSize = blockLength;
        status = CMSampleBufferCreate(kCFAllocatorDefault,
                                      blockBuffer, true, NULL, NULL,
                                      _formatDesc, 1, 0, NULL, 1,
                                      &sampleSize, &sampleBuffer);
        
        NSLog(@"\t\t SampleBufferCreate: \t %@", (status == noErr) ? @"successful!" : @"failed...");
    }
    
    if(status == noErr)
    {
        // set some values of the sample buffer's attachments
        CFArrayRef attachments = CMSampleBufferGetSampleAttachmentsArray(sampleBuffer, YES);
        CFMutableDictionaryRef dict = (CFMutableDictionaryRef)CFArrayGetValueAtIndex(attachments, 0);
        CFDictionarySetValue(dict, kCMSampleAttachmentKey_DisplayImmediately, kCFBooleanTrue);
        
        // either send the samplebuffer to a VTDecompressionSession or to an AVSampleBufferDisplayLayer
//        [self render:sampleBuffer];
    }
    
    // free memory to avoid a memory leak, do the same for sps, pps and blockbuffer
    if (NULL != data)
    {
        free (data);
        data = NULL;
    }

}
-(void) createDecompSession
{
    // make sure to destroy the old VTD session
    _decompressionSession = NULL;
//    VTDecompressionOutputCallbackRecord callBackRecord;
//    callBackRecord.decompressionOutputCallback = decompressionSessionDecodeFrameCallback;
    VTDecompressionOutputCallbackRecord outputCallback = {
        .decompressionOutputCallback = decompressionSessionDecodeFrameCallback,
        .decompressionOutputRefCon = NULL
    };
    
    CFDictionaryRef attrs = NULL;
    const void *keys[] = { kCVPixelBufferPixelFormatTypeKey };
    uint32_t v = kCVPixelFormatType_420YpCbCr8BiPlanarFullRange;
    const void *values[] = { CFNumberCreate(NULL, kCFNumberSInt32Type, &v) };
    attrs = CFDictionaryCreate(NULL, keys, values, 1, NULL, NULL);
    
    OSStatus status =  VTDecompressionSessionCreate(NULL, _formatDesc, NULL,
                                                    NULL,
                                                    &outputCallback, &_decompressionSession);
    NSLog(@"Video Decompression Session Create: \t %@", (status == noErr) ? @"successful!" : @"failed...");
    if(status != noErr) NSLog(@"\t\t VTD ERROR type: %d", (int)status);
}
void decompressionSessionDecodeFrameCallback(void *decompressionOutputRefCon,
                                             void *sourceFrameRefCon,
                                             OSStatus status,
                                             VTDecodeInfoFlags infoFlags,
                                             CVImageBufferRef imageBuffer,
                                             CMTime presentationTimeStamp,
                                             CMTime presentationDuration)
{
    ViewController *streamManager = (__bridge ViewController *)decompressionOutputRefCon;
    
    if (status != noErr)
    {
        NSError *error = [NSError errorWithDomain:NSOSStatusErrorDomain code:status userInfo:nil];
        NSLog(@"Decompressed error: %@", error);
    }
    else
    {
        NSLog(@"Decompressed sucessfully");
        
        // do something with your resulting CVImageBufferRef that is your decompressed frame
//        [streamManager displayDecodedFrame:imageBuffer];
    }
}

- (void) render:(CMSampleBufferRef)sampleBuffer
{
    VTDecodeFrameFlags flags = kVTDecodeFrame_EnableAsynchronousDecompression;
    VTDecodeInfoFlags flagOut;
    NSDate* currentTime = [NSDate date];
    VTDecompressionSessionDecodeFrame(_decompressionSession, sampleBuffer, flags,
                                      (void*)CFBridgingRetain(currentTime), &flagOut);
    
    CFRelease(sampleBuffer);

     [_videoLayer enqueueSampleBuffer:sampleBuffer];

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

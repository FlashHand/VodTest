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
#define INVALID_HANDLE_VALUE (HANDLE)-1

static ViewController *selfMirror=nil;

@interface ViewController ()
@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    
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

static int CALLBACK ReadDatacbf(HLIVE hStream, BYTE *pDataBuf, DWORD dwDataLen, DWORD dwUserData){
    [selfMirror receivedRawVideoFrame:pDataBuf withSize:dwDataLen];
    return 0;
}

-(void)receivedRawVideoFrame:(uint8_t *)frame withSize:(uint32_t)frameSize{
    uint8_t headLength=44;
    uint8_t *header_part=(uint8_t *)malloc(sizeof(uint8_t) * headLength);
    frame_header_t *header=(frame_header_t *)memcpy(header_part, frame, headLength);
    uint8_t *body_part=(uint8_t *)malloc(sizeof(uint8_t) * frameSize-44);
    uint8_t *body=(uint8_t *)memcpy(body_part, &frame[44], frameSize-44);

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

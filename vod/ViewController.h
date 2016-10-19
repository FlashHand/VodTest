//
//  ViewController.h
//  vod
//
//  Created by 王博 on 16/7/18.
//  Copyright © 2016年 FlashHandR4L. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
@property CALayer *videoLayer;
-(void)receivedRawVideoFrame:(uint8_t *)frame withSize:(uint32_t)frameSize;
@end


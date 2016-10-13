//
//  libnetclient.h
//  libnetclient
//
//  Created by xiaoyi on 14-12-16.
//  Copyright (c) 2014年 leo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "hsx_netclient.h"
#import "gkP2PClient.h"


@interface libnetclient : NSObject
// 初始化
+(int)Network_ClientInit;

// 反初始化
+(int)Network_ClientUnInit;

// 获取当前SDK的版本信息
+(int)Network_ClientGetVersion:(BYTE *)pVersionInfo limitLen:(int)nInfoLen;

// 登录设备
+(int)Network_ClientLogin:(HDEVICE *)pDev addr:(char *)pSeverAddr port:(DWORD)dwCmdPort user:(char *)pUserName pwd:(char *)pPassword;

// 登出设备
+(int)Network_ClientLogout:(HDEVICE)hDev;

// 设备控制
+(int)Network_ClientDeviceControl:(HDEVICE)hDev code:(eDeviceCtrlCode)eCtrlCode param:(DWORD) dwParam;

// 设置事件回调
+(int)Network_ClientSetEventCB:(HDEVICE)hDev callback:(CB_DeviceEvent)cbfEvent private:(DWORD) dwUserData;

// 分辨率改变时，需要更新视频，否则图像无法显示
//DVR_NET_API int __stdcall Network_ClientRefreshVideo(IN HDEVICE hDev);


// 启动实时流
+(int)Network_ClientStartLive:(HLIVE *)pStream dev:(HDEVICE)hDev info:(LiveConnect *)pClientInfo callback:(CB_StreamData)cDatacbf private:(DWORD)dwUserData;

// 停止实时流
+(int)Network_ClientStopLive:(HLIVE) hStream;

// 实时流控制
+(int)Network_ClientLiveControl:(HLIVE) hStream code:(eLiveCtrlCode)eCode param:(void *)pParam;

// 设置实时流图像叠加绘制回调
//DVR_NET_API int __stdcall Network_ClientSetLiveDrawCB(HLIVE hStream, IN HWND hWnd, IN CB_DrawFun cbfDraw, DWORD dwUserData);

// 设置实时流数据回调, bMustCBMainStream，该参数只在设备支持多码流的情况下有效: true--必须回调主码流；false--直接回调预览数据
// bNeedSound, 回调是否需要声音
//+(int)Network_ClientSetLiveDataCB:(HLIVE)hStream callback:(CB_StreamData)cDatacbf private:(DWORD)dwUserData mainStream:(int)bMustCBMainStream sound:(int) bNeedSound;

// 预览连接方式为子码流/自动选择时，设置随显示窗口的大小自适应选择码流；预览连接方式为主码流时，调用该接口无效
//DVR_NET_API int __stdcall Network_ClientSubcodeAdapt(HLIVE hStream, int nWndWidth, int nWndHeight);



// 获取一个月中有录像的有哪些天
+(int)Network_ClientGetMonthRecDate:(HDEVICE)hDev year:(DWORD)dwYear month:(DWORD)dwMonth mask:(DWORD *)dwRecDateMask;

// 获取某一天有录像的时间
// 以分钟为单位返回录像时间，所以dwBufLen必须>=(24 * 60)
+(int)Network_ClientGetDayRecTime:(HDEVICE) hDev date:(TimeInfo *)pRecDate timeBuf:(BYTE *)pRecTimeBuf len:(DWORD) dwBufLen ch:(DWORD) dwChannel;

// 启动回放
//+(int)Network_ClientStartPlayback:(HPLAYBACK *)pPlayback dev:(HANDLE) hDev ch:(DWORD)dwChannel type:(DWORD )dwFileType begin:(TimeInfo *)pBeginTime end:(TimeInfo *)pEndTime win:(HWND) hWnd;

+(int)Network_ClientStartPlaybackEx:(HPLAYBACK *)pPlayback dev:(HANDLE) hDev ch:(DWORD)dwChannel type:(DWORD )dwFileType begin:(TimeInfo *)pBeginTime end:(TimeInfo *)pEndTime callback:(CB_PlaybackData)cDatacbf;


//  停止回放
+(int)Network_ClientStopPlayback:(HPLAYBACK)hPlayback;

// 回放控制
+(int)Network_ClientPlaybackControl:(HPLAYBACK)hPlayback code:(ePlaybackCtrlCode) dwControlCode param:(void *)pParam;



// 启动下载
//DVR_NET_API int __stdcall Network_ClientStartDownload(OUT HDOWNLOAD *pDownload, HANDLE hDev, char *pDevFileName, char *pSavedFileName, TimeInfo *pBeginTime, TimeInfo *pEndTime);

// 停止下载
//DVR_NET_API int __stdcall Network_ClientStopDownload(HDOWNLOAD hDownload);

// 获取下载状态
//DVR_NET_API int __stdcall Network_ClientGetDownloadStatus(IN HDOWNLOAD hDownload, DWORD *dwProgress);


// PTZ控制
+(int)Network_ClientPTZControl:(HDEVICE)hDev ch:(DWORD)dwChannle control:(PtzControlInfo *)pControlInfo;

// 透明通道传输数据, nDataLen <= 2048(字节)
//DVR_NET_API int __stdcall Network_ClientTransparentSend(HDEVICE hDev, DWORD dwBuadRate, BYTE *pDataBuf, int nDataLen);

// 获取设备配置
// 注意：在缓冲区长度允许的范围内(参见MAX_CFG_INFO_LEN)，可同时设置或获取多个相同的配置
// 比如要获取dvr_channel_cfg，如果通道掩码为二进制的0101,则m_acCfg中得数据为dvr_channel_cfg1, dvr_channel_cfg3
+(int)Network_ClientGetDeviceConfig:(HDEVICE)hDev cmd:(DWORD)dwCommand channelMask:(DWORD)dwChannelMask saveAt:(BYTE *)pCfgBuf maxLen:(DWORD)dwBufLen;

// 设置设备配置
+(int)Network_ClientSetDeviceConfig:(HDEVICE)hDev cmd:(DWORD)dwCommand channelMask:(DWORD)dwChannelMask config:(BYTE *)pCfgBuf len:(DWORD)dwCfgLen;



// 启动升级
//DVR_NET_API int __stdcall Network_ClientStartUpgrade(OUT HUPGRADE *pUpgrade, IN HANDLE hDev, const char *pFileName);

// 停止升级
//DVR_NET_API int __stdcall Network_ClientStopUpgrade(HUPGRADE hUpgrade);

// 获取升级状态
//DVR_NET_API int __stdcall Network_ClientGetUpgradeStatus(IN HUPGRADE hUpgrade, OUT DWORD *dwProgress);



// 启动日志查询
//DVR_NET_API int __stdcall Network_ClientStartLogQuery(OUT HQUERY *pLog, HANDLE hDev, eLogQueryMode eQueryMode, DWORD dwChannel, eLogQueryMainType eMainType, eLogQuerySubType eSubType, TimeInfo *pQueryTime);

// 获取日志查询结果 dwLogCnt >= 0 && dwLogCnt <= 100
//DVR_NET_API int __stdcall Network_ClientGetLogQueryResult(IN HQUERY hLog, INOUT DWORD *dwLogCnt, OUT BYTE *pLogBuf, IN DWORD dwBufLen);

// 停止日志查询
//DVR_NET_API int __stdcall Network_ClientStopLogQuery(HQUERY hLog);



// 启动文件查询
//DVR_NET_API int __stdcall Network_ClientStartFileQuery(OUT HQUERY *pFileQuery, HANDLE hDev, DWORD dwChannel, DWORD dwFileType, TimeInfo *pBeginTime, TimeInfo *pEndTime);

// 获取文件查询结果 dwFileCnt >= 0 && dwFileCnt <= 50
//DVR_NET_API int __stdcall Network_ClientGetFileQueryResult(IN HQUERY hFileQuery, INOUT DWORD *dwFileCnt, OUT BYTE *pFileBuf, IN DWORD dwBufLen);

// 停止文件查询
//DVR_NET_API int __stdcall Network_ClientStopFileQuery(HQUERY hFileQuery);



// 启动语音对讲
//DVR_NET_API int __stdcall Network_ClientStartVoice(OUT HVOICE *pVoice, IN HANDLE hDev, IN HWND hWnd);

// 停止语音对讲
//DVR_NET_API int __stdcall Network_ClientStopVoice(IN HVOICE hVoice);

// 设置语音对讲音量 bHighOrLow: true--提高音量 false--降低音量
//DVR_NET_API int __stdcall Network_ClientSetVoiceVolumn(IN HVOICE hVoice, bool bHighOrLow);



// 启动设备发现, nInterval--发送探测包的周期，单位：ms (nInterval >= 1000)
//DVR_NET_API int __stdcall Network_ClientStartDiscovery(OUT HDISCOVERY *pDiscovery, int nInterval, CB_Discovery cbfDiscovery, DWORD dwUserData, eDiscoveryType eType);

// 停止设备发现
//DVR_NET_API int __stdcall Network_ClientStopDiscovery(IN HDISCOVERY hDiscovery);

// 刷新设备发现
//DVR_NET_API int __stdcall Network_ClientRefreshDiscovery(IN HDISCOVERY hDiscovery);



// 检查总体通道属性配置所需性能是否超过系统的最大性能
// *pExceedCIFCnt为0表示当前配置可以满足，否则大于0表示当前配置所需性能无法满足，超出部分为*pExceedCIFCnt（单位：CIF, 帧每秒）
//DVR_NET_API int __stdcall Network_ClientCheckChAttrResLimit(OUT int *pExceedCIFCnt, HANDLE hDev, IN ChannelAttrResInfo *pResInfo);

// 检查总体录像画质配置所需性能是否超过系统的最大性能
// *pExceedCIFCnt为0表示当前配置可以满足，否则大于0表示当前配置所需性能无法满足，超出部分为*pExceedCIFCnt（单位：CIF, 帧每秒）
//DVR_NET_API int __stdcall Network_ClientCheckRecQualityResLimit(OUT int *pExceedCIFCnt, HANDLE hDev, IN RecQualityResInfo *pResInfo);



#ifndef WIN32
// set live rgb callback
//DVR_NET_API int __stdcall Network_ClientSetLiveRgbCB(HLIVE hStream, CB_RGBVideoFrame cbf, DWORD dwUserData);

// set playback rgb callback
//DVR_NET_API int __stdcall Network_ClientSetPlaybackRgbCB(HPLAYBACK hPlayback, CB_RGBVideoFrame cbf, DWORD dwUserData);
#endif


// 设置设备端分屏模式
//DVR_NET_API int __stdcall Network_ClientSetDeviceScreenDisplay(IN HDEVICE hDevice, DeviceScreenDisplay *pScreenDisplay);


// 初始化，只需要调用一次
+(int)P2P_Init;
// 反初始化，只需要调用一次
+(int)P2P_UnInit;


// 获取连接信息
// 当连接方式返回为直连时，也可以使用p2p的方式，但建议使用直连的方式，以提高网络效率
+(int)P2P_GetConnectInfo:(OUT P2PConnectInfo *)pConnectInfo for:(const char *)pDomainName;

// 创建p2p，网络断开重连时，需要重新创建p2p
+(int) P2P_Create:(OUT HP2P *)pP2p withInfo:(IN P2PConnectInfo *)p2p_info for:(IN char *)pDomainName;

// 创建p2p连接
+(int) P2P_Connect:(OUT HSOCK *)pSock onHandle:(IN HP2P)hP2p;

// p2p断开连接
+(int) P2P_Disconnect:(HSOCK)hSock;

// 阻塞发送，发送完指定长度的字节返回成功，否则返回失败
+(int) P2P_Send:(HSOCK)hSock data:(IN char *)send_buf lenght:(IN int) send_len;

// 超时或接收完指定长度的字节返回成功，否则返回失败
// recv_len: 作为入参时表示想要接收的字节数；作为出参时表示实际接收到的字节数
// timeout: 超时时间, 单位秒，当timeout为INFINITE时，表示阻塞接收指定长度的字节
// msg_peek: 为true时，其作用同MSG_PEEK标志
+(int) P2P_Recv:(HSOCK)hSock saveAt:(IN char *)recv_buf lenght:(INOUT int *)recv_len wait:(DWORD) timeout flag:(bool)msg_peek;

// 销毁p2p
+(int) P2P_Destroy:(HP2P) hP2p;


//out:
//status ＝ 0, 未连接
//status ＝ 1, 已连接
+(int) P2P_GetConnectStatus:(int)hP2p status:(OUT int *)status;

@end

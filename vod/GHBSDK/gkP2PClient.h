#ifndef GK_P2P__H_H
#define GK_P2P__H_H

#include "p2p_define.h"
//#include "platform.h"

#ifdef __cplusplus
#define GK_P2P_API extern "C"
#else
#define GK_P2P_API
#endif


#ifdef WIN32
#include <windows.h>
#else // ifndef win32
#ifndef HANDLE
#define HANDLE unsigned int
#endif

#ifndef __stdcall
#define __stdcall
#endif

#ifndef INFINITE
#define INFINITE 0XFFFFFFFF
#endif
#endif // end of (ifdef win32)


////////////////////////////////////////////////////////////////////////////////
// 宏定义
////////////////////////////////////////////////////////////////////////////////

// 输入参数
#define IN
// 输出参数
#define OUT
// 输入输出参数
#define INOUT

// p2p对象
#define HP2P			HANDLE

// p2p句柄
#define HSOCK			HANDLE

// 最大域名长度
#define	MAX_P2P_DOMAINNAME_LEN		(32)



// 连接信息
typedef struct tagP2PConnectInfo
{   
	eP2PConnectType eType;			// 连接方式
	char acIpAddr[32];				// 目标设备ip
	int 	nPort;						// 目标设备端口
	int 	try_lan;                    //1:在局域网，0：不在局域网
	int 	try_udp;                    //1:可以进行udp连接  0:不可以进行udp连接
	char acIplan[32];               //局域网私有地
	node_uid_t  target_uid ;        //目标uid;
	int   result;                   //获取链接信息的返回结果
	node_uid_t  partner_uid ;        //目标uid;
	char partner_ip[32];
	int 	partner_port;
	int 	server_ip;
	int 	server_port;
	char p2p_version[32];
	char reserve[24];
}P2PConnectInfo;

////////////////////////////////////////////////////////////////////////////////
// 接口定义
////////////////////////////////////////////////////////////////////////////////

#ifndef WIN32
#pragma GCC visibility push(default)
#endif

// 初始化，只需要调用一次
//GK_P2P_API int __stdcall P2P_Init();
GK_P2P_API int __stdcall P2P_Init();
// 反初始化，只需要调用一次
GK_P2P_API int __stdcall P2P_UnInit();


// 获取连接信息
// 当连接方式返回为直连时，也可以使用p2p的方式，但建议使用直连的方式，以提高网络效率
GK_P2P_API int __stdcall P2P_GetConnectInfo(OUT P2PConnectInfo *pConnectInfo, IN const char *pDomainName);

// 创建p2p，网络断开重连时，需要重新创建p2p
GK_P2P_API int __stdcall P2P_Create(OUT HP2P *pP2p, IN P2PConnectInfo *p2p_info ,IN char *pDomainName);

// 创建p2p连接
GK_P2P_API int __stdcall P2P_Connect(OUT HSOCK *pSock, IN HP2P hP2p);

// p2p断开连接
GK_P2P_API int __stdcall P2P_Disconnect(IN HSOCK hSock);

// 阻塞发送，发送完指定长度的字节返回成功，否则返回失败
GK_P2P_API int __stdcall P2P_Send(IN HSOCK hSock, IN char *send_buf, IN int send_len);

// 超时或接收完指定长度的字节返回成功，否则返回失败
// recv_len: 作为入参时表示想要接收的字节数；作为出参时表示实际接收到的字节数
// timeout: 超时时间, 单位秒，当timeout为INFINITE时，表示阻塞接收指定长度的字节
// msg_peek: 为true时，其作用同MSG_PEEK标志
GK_P2P_API int __stdcall P2P_Recv(IN HSOCK hSock, OUT char *recv_buf, INOUT int *recv_len, DWORD timeout, bool msg_peek);

//接收UDP数据包
//GK_P2P_API int __stdcall P2P_UdpRecv(IN HSOCK hSock, OUT char *recv_buf,INOUT int *recv_len,DWORD timeout = INFINITE,bool msg_peek = false);
// 销毁p2p
GK_P2P_API int __stdcall P2P_Destroy(IN HP2P hP2p);


//david for compile
//GK_P2P_API int __stdcall P2P_GetConnectStatus(IN HP2P hP2p, int * status);

GK_P2P_API int __stdcall P2P_GetConnectStatus(IN int hP2p, int * status);

//added for p2p dns
GK_P2P_API int __stdcall  P2P_SetDnsInfo(const char * domain_name, const char* ip, time_t ts);
GK_P2P_API p2p_dns_info_t* __stdcall  P2P_GetDnsInfo(int index);
GK_P2P_API int __stdcall  P2P_GetDnsCntMax();
#ifndef WIN32
#pragma GCC visibility pop
#endif


#endif

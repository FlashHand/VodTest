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
// �궨��
////////////////////////////////////////////////////////////////////////////////

// �������
#define IN
// �������
#define OUT
// �����������
#define INOUT

// p2p����
#define HP2P			HANDLE

// p2p���
#define HSOCK			HANDLE

// �����������
#define	MAX_P2P_DOMAINNAME_LEN		(32)



// ������Ϣ
typedef struct tagP2PConnectInfo
{   
	eP2PConnectType eType;			// ���ӷ�ʽ
	char acIpAddr[32];				// Ŀ���豸ip
	int 	nPort;						// Ŀ���豸�˿�
	int 	try_lan;                    //1:�ھ�������0�����ھ�����
	int 	try_udp;                    //1:���Խ���udp����  0:�����Խ���udp����
	char acIplan[32];               //������˽�е�
	node_uid_t  target_uid ;        //Ŀ��uid;
	int   result;                   //��ȡ������Ϣ�ķ��ؽ��
	node_uid_t  partner_uid ;        //Ŀ��uid;
	char partner_ip[32];
	int 	partner_port;
	int 	server_ip;
	int 	server_port;
	char p2p_version[32];
	char reserve[24];
}P2PConnectInfo;

////////////////////////////////////////////////////////////////////////////////
// �ӿڶ���
////////////////////////////////////////////////////////////////////////////////

#ifndef WIN32
#pragma GCC visibility push(default)
#endif

// ��ʼ����ֻ��Ҫ����һ��
//GK_P2P_API int __stdcall P2P_Init();
GK_P2P_API int __stdcall P2P_Init();
// ����ʼ����ֻ��Ҫ����һ��
GK_P2P_API int __stdcall P2P_UnInit();


// ��ȡ������Ϣ
// �����ӷ�ʽ����Ϊֱ��ʱ��Ҳ����ʹ��p2p�ķ�ʽ��������ʹ��ֱ���ķ�ʽ�����������Ч��
GK_P2P_API int __stdcall P2P_GetConnectInfo(OUT P2PConnectInfo *pConnectInfo, IN const char *pDomainName);

// ����p2p������Ͽ�����ʱ����Ҫ���´���p2p
GK_P2P_API int __stdcall P2P_Create(OUT HP2P *pP2p, IN P2PConnectInfo *p2p_info ,IN char *pDomainName);

// ����p2p����
GK_P2P_API int __stdcall P2P_Connect(OUT HSOCK *pSock, IN HP2P hP2p);

// p2p�Ͽ�����
GK_P2P_API int __stdcall P2P_Disconnect(IN HSOCK hSock);

// �������ͣ�������ָ�����ȵ��ֽڷ��سɹ������򷵻�ʧ��
GK_P2P_API int __stdcall P2P_Send(IN HSOCK hSock, IN char *send_buf, IN int send_len);

// ��ʱ�������ָ�����ȵ��ֽڷ��سɹ������򷵻�ʧ��
// recv_len: ��Ϊ���ʱ��ʾ��Ҫ���յ��ֽ�������Ϊ����ʱ��ʾʵ�ʽ��յ����ֽ���
// timeout: ��ʱʱ��, ��λ�룬��timeoutΪINFINITEʱ����ʾ��������ָ�����ȵ��ֽ�
// msg_peek: Ϊtrueʱ��������ͬMSG_PEEK��־
GK_P2P_API int __stdcall P2P_Recv(IN HSOCK hSock, OUT char *recv_buf, INOUT int *recv_len, DWORD timeout, bool msg_peek);

//����UDP���ݰ�
//GK_P2P_API int __stdcall P2P_UdpRecv(IN HSOCK hSock, OUT char *recv_buf,INOUT int *recv_len,DWORD timeout = INFINITE,bool msg_peek = false);
// ����p2p
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

#ifndef P2P_DEFINE_H
#define P2P_DEFINE_H

#ifdef WIN32

#else // ifndef win32

#ifndef DWORD
#define DWORD unsigned int
#endif

#endif // end of (ifdef win32)


////////////////////////////////////////////////////////////////////////////////
// ö�ٶ���
////////////////////////////////////////////////////////////////////////////////

// �ӿڷ����붨��
typedef enum eP2PRetCode
{
	ret_p2p_ok = 0,					    // �ɹ�
	ret_p2p_failed = 10000,				// ʧ��
	ret_p2p_version_mismatch,			// �汾��ƥ��

	ret_p2p_not_init,					// �ͻ���sdkδ��ʼ��
	ret_p2p_unsupported,                // ��֧�ֵĲ���
	ret_p2p_has_started,				// �Ѿ�����
	ret_p2p_not_start,					// δ����

	ret_p2p_invalid_param,				// ������Ч
	ret_p2p_invalid_handle,				// ���ֵ��Ч
	ret_p2p_no_resource,				// ��Դ����
	ret_p2p_buf_too_small,				// ������̫С

	ret_p2p_network_error,				// �������
	ret_p2p_cmd_timeout,				// ���ʱ
	ret_p2p_reply_error,				// �豸�˻ظ�����
	ret_p2p_disconnect,					// ���ӶϿ�
	ret_p2p_udp_connect,                //udpֱ��
    ret_p2p_udp_transfer,               //udp�м�ڵ�ת��
}eP2PRetCode;

// ���ӷ�ʽ
typedef enum eP2PConnectType
{
	eConnectMustP2P = 0,		// ֻ��ʹ��p2p�ķ�ʽ
	eConnectDirect = 1,			// ����ʹ��p2p�ķ�ʽ��������ʹ��ֱ���ķ�ʽ
}eP2PConnectType;

// udp ���ӷ�ʽ
typedef  enum eUDPConnectType
{
	 eUDPConnDirect = 0 , //UDPֱ��
	 eUDPConnTransfer = 1,//UDP�м�ڵ�ת��
}eUDPConnectType;


typedef enum 
{
	eConnnectTcp = 0 , //tcp ����
	eConnectUdp = 1,    //udp ����
}eConnect_type;


////////////////////////////////////////////////////////////////////////////////
// �ṹ�嶨��
////////////////////////////////////////////////////////////////////////////////
typedef struct node_uid_s{
	char uid[16];
}node_uid_t;

typedef struct p2p_dns_info_s
{
    int 	in_use;
    char    domain_name[64];
    int     ip_int;
    char    ip_str[32];
    unsigned int     validate_ts;
    int     reserve1;
    int     reserve2;
}p2p_dns_info_t;

#endif

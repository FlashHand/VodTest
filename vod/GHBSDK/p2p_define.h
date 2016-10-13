#ifndef P2P_DEFINE_H
#define P2P_DEFINE_H

#ifdef WIN32

#else // ifndef win32

#ifndef DWORD
#define DWORD unsigned int
#endif

#endif // end of (ifdef win32)


////////////////////////////////////////////////////////////////////////////////
// 枚举定义
////////////////////////////////////////////////////////////////////////////////

// 接口返回码定义
typedef enum eP2PRetCode
{
	ret_p2p_ok = 0,					    // 成功
	ret_p2p_failed = 10000,				// 失败
	ret_p2p_version_mismatch,			// 版本不匹配

	ret_p2p_not_init,					// 客户端sdk未初始化
	ret_p2p_unsupported,                // 不支持的操作
	ret_p2p_has_started,				// 已经启动
	ret_p2p_not_start,					// 未启动

	ret_p2p_invalid_param,				// 参数无效
	ret_p2p_invalid_handle,				// 句柄值无效
	ret_p2p_no_resource,				// 资源不足
	ret_p2p_buf_too_small,				// 缓冲区太小

	ret_p2p_network_error,				// 网络错误
	ret_p2p_cmd_timeout,				// 命令超时
	ret_p2p_reply_error,				// 设备端回复错误
	ret_p2p_disconnect,					// 连接断开
	ret_p2p_udp_connect,                //udp直连
    ret_p2p_udp_transfer,               //udp中间节点转发
}eP2PRetCode;

// 连接方式
typedef enum eP2PConnectType
{
	eConnectMustP2P = 0,		// 只能使用p2p的方式
	eConnectDirect = 1,			// 可以使用p2p的方式，但建议使用直连的方式
}eP2PConnectType;

// udp 连接方式
typedef  enum eUDPConnectType
{
	 eUDPConnDirect = 0 , //UDP直连
	 eUDPConnTransfer = 1,//UDP中间节点转发
}eUDPConnectType;


typedef enum 
{
	eConnnectTcp = 0 , //tcp 连接
	eConnectUdp = 1,    //udp 连接
}eConnect_type;


////////////////////////////////////////////////////////////////////////////////
// 结构体定义
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

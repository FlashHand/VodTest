//added by xiaoyi
#ifndef LIB_NETCLIENT_DEF_H
#define LIB_NETCLIENT_DEF_H

#ifndef DWORD
#define DWORD unsigned
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif



typedef enum eNetClientRetCode
{
	eRetSuccess = 0,						// ≥…π¶
	eRetFailed,								//  ß∞‹
	eRetFailVersion,						// ∞Ê±æ≤ª∆•≈‰
	eRetFailBoardType,						// ∞Â–Õ≤ª∆•≈‰£¨Œﬁ∑®…˝º∂
    
	eRetFailSdkNotInit,						// øÕªß∂ÀsdkŒ¥≥ı ºªØ
	eRetFailUnsupported,                    // ≤ª÷ß≥÷µƒ≤Ÿ◊˜
	eRetFailHasStarted,						// “—æ≠∆Ù∂Ø
	eRetFailNotStart,						// Œ¥∆Ù∂Ø
    
	eRetFailInvalidParameter,				// ≤Œ ˝Œﬁ–ß
	eRetFailInvalidHandle,					// æ‰±˙÷µŒﬁ–ß
	eRetFailInvalidFile,					// Œƒº˛Œﬁ–ß
	eRetFailNoResource,						// ◊ ‘¥≤ª◊„
    
	eRetFailUserName,						// ”√ªß√˚¥ÌŒÛ£¨‘§¡Ù
	eRetFailUserPwd,						// ”√ªß√‹¬Î¥ÌŒÛ£¨‘§¡Ù
	eRetFailIpNotAllowed,					// ≤ª‘ –Ìµƒipµÿ÷∑£¨‘§¡Ù
	eRetFailTooManyLoginedUser,				// µ«¬º”√ªßπ˝∂‡£¨‘§¡Ù
    
	eRetFailNetworkError,					// Õ¯¬Á¥ÌŒÛ
	eRetFailCmdTimeout,						// √¸¡Ó≥¨ ±
	eRetFailReplyError,						// …Ë±∏∂Àªÿ∏¥¥ÌŒÛ
	eRetFailDisconnect,						// ¡¨Ω”∂œø™
    
	eRetFailDecodeShow,						// Ω‚¬Îœ‘ æ ß∞‹
	eRetFailAudioCapture,					// “Ù∆µ≤∂ªÒ ß∞‹
	eRetFailVoicePlay,						// ”Ô“Ù≤•∑≈ ß∞‹
	eRetFailNotFind,						// Œ¥’“µΩ
    
	eRetChangeIPCWorkMode,					// ’˝‘⁄–ﬁ∏ƒIPCµƒπ§◊˜ƒ£ Ω,±ÿ–Îµ»¥˝60√Î“‘∫Û‘Ÿƒ‹…˙–ß.
	eRetChangeIPCCodec,						// ’˝‘⁄–ﬁ∏ƒIPCµƒ±‡¬Î∑Ω Ω,±ÿ–Îµ»¥˝30√Î◊Û”“
	eRetChangeIPCROI,						// ’˝‘⁄–ﬁ∏ƒROI,–Ë“™µ»¥˝
    
	eRetFailNoRight = 1000,					// √ª”–»®œﬁ
    eRetFailChannelDisabled,				// 通道被禁用
    eRetFailSameIPLoginLimit,				// 同一ip地址登陆次数过多
}eNetClientRetCode;

//typedef enum
//{
//	eIPCType_Begin = 0,
//	
//	eIPCType_AutoAdapt,			// 自动适匹IPC的类型,用户应该尽量使用确切的类型,否则会因为支持类型的增多影响成功连接的时间
//	eIPCType_AMTK_V5,			// A-MTK V5型,一般指MTK 1.3Mega的IPC,软件版板是5.0的
//	eIPCType_AMTK_V6,			// A-MTK V6型,一般指MTK 2.0Mega的IPC,软件版板是6.0的
//	eIPCType_GK,
//	eIPCType_ONVIF,
//	eIPCType_IPUX,				// IPUX厂家的,这个设备似乎比较菜.只支持一个码流.
//	eIPCType_ONVIF_TST,			// 天视通ONVIF协议,不设置参数.因为设置参数会导致其不正常.
//	eIPCType_TST,
//	eIPCType_End
//}eIPC_Type;


typedef enum
{
	eRequestPacket = 0,
	eReplyPacket,
};


#define STREAM_HEAD_MAGIC 0x55aa5a5a	

typedef enum
{
	VIDEO_FRAME_I = 0,
	VIDEO_FRAME_P = 1,
	AUDIO_FRAME	= 2,

	// ◊®√≈Œ™Õ¯¬Áªÿ∑≈Œƒº˛ ˝æ›∂¡»°ÃÌº”µƒ¿‡–Õ
	VIDEO_FRAME_I_EXTEND = 3,	// Œ¥ÕÍ¥˝–¯µƒI÷°
	VIDEO_FRAME_P_EXTEND = 4,	// Œ¥ÕÍ¥˝–¯µƒP÷°
	AUDIO_FRAME_EXTEND = 5,		// Œ¥ÕÍ¥˝–¯µƒ“Ù∆µ÷°
}frame_type_e;

typedef enum
{
    // 视频编码格式
    ENCODE_TYPE_GM_H264 = 0,
    ENCODE_TYPE_HIS_H264,
    
    // 音频编码格式
    ENCODE_TYPE_ADPCM_IMA=100,
    ENCODE_TYPE_PCM,
    ENCODE_TYPE_HIS_G726,
    
    ENCODE_TYPE_AUDIO_G711 =200,
    ENCODE_TYPE_AUDIO_G711_A,
    ENCODE_TYPE_AUDIO_G711_U,
    
    ENCODE_TYPE_AUDIO_G726 =300,
    ENCODE_TYPE_AUDIO_G726_24K,
    ENCODE_TYPE_AUDIO_G726_32K,
    
    ENCODE_TYPE_UNKNOW = -1,
}encode_type_e;

typedef enum
{
	VENC_STR_NONE		 = 0,
	VENC_STR_MAIN        = 0x00000001,	//主码流
	VENC_STR_AUX         = 0x00000002,	//子码流
	VENC_STR_AUX1        = 0x00000004,	//子码流1
	VENC_STR_AUX2        = 0x00000008,	//子码流2
	VENC_STR_AUX3        = 0x00000010,	//子码流3
}venc_str_e;


#define NETWORK_STREAM_HEAD_MAGIC 0x55aa5a5a
typedef struct frame_header_s{
	int magic;			//NETWORK_PKG_HEAD_MAGIC
	char channel;		//channel no, not be mask	
	char reserve2;
	char reserve3;
	char seek_flag; //¿œ∞Ê±æ≤ª÷ß≥÷seek flag£¨¥ÀŒªŒ™0£¨ –¬∞Ê±æ»± °Œ™1
	int frame_type;	
	int stream_type;	
	int encode_type;
	unsigned int frame_no;
	unsigned int width;
	unsigned int height;

	//struct timeval timestamp;	// ±º‰¥Í
    unsigned int timestamp_sec;
    unsigned int timestamp_usec;
    
	unsigned int length;	// ˝æ›≥§∂»£¨≤ª∞¸¿®÷°Õ∑
}frame_header_t;

typedef enum
{
	READ_ONLY_I	 = 1,
	READ_ONLY_VIDEO = 2,
	READ_ALL_DATA = 3,
	READ_ONLY_AUDIO = 4,
}frame_read_mod_e;

typedef struct network_header_s
{
	DWORD magic;		// Õ¯¬ÁÕ∑magic£¨”√”⁄≤Ó¥Ì¥¶¿Ì
	DWORD sequence;		//  ˝æ›∞¸µƒ–Ú¡–∫≈£¨ªÿ”¶∞¸”¶∫Õ«Î«Û∞¸œ‡Õ¨
	DWORD cmd;			//  ˝æ›∞¸≤Ÿ◊˜id
	DWORD is_reply;		// ªÿ”¶∞¸÷√1£¨«Î«Û∞¸÷√0
	DWORD login_id;		// «Î«Û∞¸”––ß£¨ªÿ”¶∞¸÷√0
	DWORD channel_mask; // bitmask
	DWORD result;		// ∞¸Ω·π˚, 0±Ì æ≥…π¶£¨∆‰À˚±Ì æ¥ÌŒÛ¬Î
	DWORD length;		// ’˝Œƒ≥§∂»£¨≤ª∞¸¿®∞¸Õ∑
}network_header_t;


#endif





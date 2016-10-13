
#ifndef HSX_CONFIG_DEFINE_H
#define HSX_CONFIG_DEFINE_H


#include "./hsx_netclient.h"


////////////////////////////////////////////////////////////////////////////////
// ≈‰÷√÷–µƒ∫Í∂®“Â
////////////////////////////////////////////////////////////////////////////////

#define max_user_cnt				(10)				// ◊Ó¥Û”√ªß ˝£¨∆‰÷–∞¸∫¨“ª∏ˆπ‹¿Ì‘±”√ªß
#define max_normal_user_cnt			(max_user_cnt -1)	// ◊Ó¥Ûµƒ∆’Õ®”√ªß ˝£¨ «≥˝»•π‹¿Ì‘±“‘Õ‚µƒ”√ªß ˝
#define max_user_name_len			(32)				// ◊Ó¥Û”√ªß√˚≥∆≥§∂»
#define max_user_pwd_len			(32)				// ◊Ó¥Û”√ªß√‹¬Î≥§∂»

#define max_name_len				(32)				// ◊Ó¥Ûµƒ√˚≥∆≥§∂»
#define max_address_len				(64)				// ◊Ó¥Ûµÿ÷∑≥§∂»
#define max_hdd_cnt					(8)					// ◊Ó¥Û÷ß≥÷µƒ”≤≈Ã∏ˆ ˝
#define max_alarm_out_cnt			(4)					// ◊Ó¥Û±®æØ ‰≥ˆ∏ˆ ˝

#define motion_area_rect_row		(12)				// ’˚∏ˆ ”∆µ«¯”Ú±ª∑÷∏Ó≥…12*16µƒøÈ£¨“‘øÈŒ™µ•Œª¿¥…Ë÷√“∆∂Ø’Ï≤‚«¯”Ú
#define motion_area_rect_column		(16)
#define max_mosaic_area_cnt			(4)					// ◊Ó¥Ûø…“‘…Ë÷√µƒ¬Ì»¸øÀ«¯”Úµƒ∏ˆ ˝
#define day_per_week				(7)					// √ø÷‹µƒÃÏ ˝
#define hour_per_day				(24)				// √øÃÏµƒ–° ± ˝

#define max_ptz_protocol_cnt		(16)				// ◊Ó¥Û÷ß≥÷µƒ‘∆Ã®–≠“È∏ˆ ˝
#define max_preset_point_cnt		(255)				// ◊Ó¥Û‘§÷√µ„∏ˆ ˝
#define max_cruise_preset_cnt		(16)				// —≤∫Ωœﬂ¬∑÷–µƒ◊Ó¥Û‘§÷√µ„∏ˆ ˝

#define max_ddns_protocol_cnt		(32)				// ◊Ó¥Ûddns–≠“È∏ˆ ˝

#define max_email_username_len		(64)				// ◊Ó¥Ûemail”√ªß√˚≥§∂»
#define max_email_userpass_len		(32)				// ◊Ó¥Ûemail”√ªß√‹¬Î≥§∂»
#define max_email_receiver_cnt		(3)					// ◊Ó¥Û÷ß≥÷µƒ” º˛Ω” ’’ﬂ∏ˆ ˝

#define max_wifi_search_cnt			(16)				// wifi◊Ó¥ÛÀ—À˜∏ˆ ˝
#define max_spare_domain_cnt		(1)					// ◊Ó¥Û±∏”√”Ú√˚ ˝
#define max_usb_disk_cnt			(4)					// ◊Ó¥Û÷ß≥÷µƒu≈Ã∏ˆ ˝
#define MAX_IPC_SEARCH_CNT          (128)               // ◊Ó∂‡À—Àÿ128∏ˆIPC

////////////////////////////////////////////////////////////////////////////////
// ≈‰÷√√¸¡Óid
////////////////////////////////////////////////////////////////////////////////
enum msg_dvr_ctrl_id
{
	msg_get_wifi_search_info = 908,						// ªÒ»°wifiÀ—À˜–≈œ¢
	msg_get_usb_disk_info = 910,						// ªÒ»°U≈Ã–≈œ¢
	msg_get_ipc_info =912 ,                                  // ªÒ»°Ipc–≈œ¢

    msg_set_network_io_output,                          //控制io output的输出
    msg_set_network_remote_key_ctrl,                    //远端模拟遥控器控制

	msg_get_device_cfg = 1000,							// ªÒ»°…Ë±∏≈‰÷√
	msg_set_device_cfg,									// …Ë÷√…Ë±∏≈‰÷√

	msg_get_dst_cfg,									// ªÒ»°DST≈‰÷√
	msg_set_dst_cfg,									// …Ë÷√DST≈‰÷√

	msg_get_ntp_cfg,									// ªÒ»°NTP≈‰÷√
	msg_set_ntp_cfg,									// …Ë÷√NTP≈‰÷√

	msg_get_disk_cfg,									// ªÒ»°”≤≈Ã≈‰÷√
	msg_set_disk_cfg,									// …Ë÷√”≤≈Ã≈‰÷√

	msg_get_user_cfg,									// ªÒ»°”√ªß≈‰÷√
	msg_set_user_cfg,									// …Ë÷√”√ªß≈‰÷√

	msg_get_channel_basic_cfg,							// ªÒ»°Õ®µ¿ª˘±æ≈‰÷√
	msg_set_channel_basic_cfg,							// …Ë÷√Õ®µ¿ª˘±æ≈‰÷√
	msg_get_channel_ptz_cfg,							// ªÒ»°Õ®µ¿PTZ≈‰÷√
	msg_set_channel_ptz_cfg,							// …Ë÷√Õ®µ¿PTZ≈‰÷√

	msg_get_record_schedule_cfg,						// ªÒ»°¬ºœÒº∆ªÆ≈‰÷√
	msg_set_record_schedule_cfg,						// …Ë÷√¬ºœÒº∆ªÆ≈‰÷√
	msg_get_record_quality_cfg,							// ªÒ»°¬ºœÒª≠÷ ≈‰÷√
	msg_set_record_quality_cfg,							// …Ë÷√¬ºœÒª≠÷ ≈‰÷√

	msg_get_alarm_in_cfg,								// ªÒ»°±®æØ ‰»Î≈‰÷√
	msg_set_alarm_in_cfg,								// …Ë÷√±®æØ ‰»Î≈‰÷√
		
	msg_get_network_basic_cfg,							// ªÒ»°Õ¯¬Áª˘±æ≈‰÷√
	msg_set_network_basic_cfg,							// …Ë÷√Õ¯¬Áª˘±æ≈‰÷√
	msg_get_network_advanced_cfg,						// ªÒ»°Õ¯¬Á∏ﬂº∂≈‰÷√
	msg_set_network_advanced_cfg,						// …Ë÷√Õ¯¬Á∏ﬂº∂≈‰÷√

	msg_get_channel_attr_cfg,							// ªÒ»°Õ®µ¿ Ù–‘≈‰÷√
	msg_set_channel_attr_cfg,							// …Ë÷√Õ®µ¿ Ù–‘≈‰÷√

	msg_get_ipc_cfg,									// ªÒ»°IPC≈‰÷√									
	msg_set_ipc_cfg,									// …Ë÷√IPC≈‰÷√

	msg_get_network_wireless_cfg,						// ªÒ»°Õ¯¬ÁŒﬁœﬂ≈‰÷√
	msg_set_network_wireless_cfg,						// …Ë÷√Õ¯¬ÁŒﬁœﬂ≈‰÷√

	msg_get_adftp_cfg,                                 // ªÒ»°ADFTP≈‰÷√
	msg_set_adftp_cfg,                                 // …Ë÷√ADFTP≈‰÷√
	
   

    msg_set_execute_cmd=1036,                                       //√¸¡Ó––…Ë÷√
	msg_get_device_info = 1100,							// ªÒ»°…Ë±∏–≈œ¢
	msg_get_channel_info,								// ªÒ»°Õ®µ¿–≈œ¢
	msg_get_alarm_in_info,								// ªÒ»°±®æØ ‰»Î–≈œ¢
	msg_get_network_info,								// ªÒ»°Õ¯¬Á–≈œ¢
	msg_get_wireless_info,								// ªÒ»°Œﬁœﬂ–≈œ¢
};

////////////////////////////////////////////////////////////////////////////////
// ≈‰÷√–≈œ¢Ω·ππÃÂ∂®“Â
////////////////////////////////////////////////////////////////////////////////

#pragma pack(push)
#pragma pack(1) 


//  ”∆µ÷∆ Ω
typedef enum 
{
	VIDEO_STD_NTSC        = 0x00000001,					// NTSC
	VIDEO_STD_PAL         = 0x00000002,					// PAL
	VIDEO_STD_SECAM       = 0x00000004,					// SECAM
}video_stand_e;  


/*	
	…Ë±∏≈‰÷√
	ªÒ»°…Ë±∏≈‰÷√µƒ√¸¡ÓidŒ™msg_get_device_cfg
	…Ë÷√…Ë±∏≈‰÷√µƒ√¸¡ÓidŒ™msg_set_device_cfg
*/
typedef struct
{
	char dvr_name[max_name_len];						// dvr…Ë±∏√˚≥∆, ◊¢“‚ π”√µƒ «utf-8±‡¬Î
	long dvr_id;										// dvr…Ë±∏id£®”√”⁄“£øÿ∆˜…Ë÷√£©
	long video_standard;								//  ”∆µ÷∆ Ω£¨«Î≤Œøºvideo_stand_e√∂æŸ¿‡–Õ∂®“Â

	float latitude;										// …Ë±∏À˘‘⁄Œ≥∂» [-90, 90] £¨Œﬁ–ß÷µ£∫360
	float longitude;									// …Ë±∏À˘‘⁄æ≠∂» [-180, 180]£¨Œﬁ–ß÷µ£∫360

	// …Ë±∏ ±º‰
	DWORD year;											//	ƒÍ£¨»Á2011
	DWORD month;										//	‘¬£¨0-11
	DWORD day;											//	»’£¨1-
	DWORD hour;											//	 ±£¨0-23
	DWORD minute;										//	∑÷£¨0-59
	DWORD second;										//	√Î£¨0-59
	
}dvr_device_cfg, *lpdvr_device_cfg;

// ”≤≈Ã◊¥Ã¨
typedef enum
{
	DISK_STAT_ERROR	 	= -1,							// ¥ÌŒÛ
	DISK_STAT_NORMAL 	= 0,							// ’˝≥£
	DISK_STAT_WRITE 	= 1,							// ’˝‘⁄–¥»Î
	DISK_STAT_FORMAT 	= 2,							// ’˝‘⁄∏Ò ΩªØ
}disk_state_e;


// Õ¯¬Áƒ‹¡¶∂®“Â
typedef enum
{
	SUPPORT_CH_ATTR			= (1 << 0),					//  «∑Ò÷ß≥÷Õ®µ¿ Ù–‘
	SUPPORT_SYNC_PLAYBACK	= (1 << 1),					//  «∑Ò÷ß≥÷Õ¨≤Ωªÿ∑≈
	SUPPORT_ADVANCED_CFG	= (1 << 2),					/*  «∑Ò÷ß≥÷∏ﬂº∂≈‰÷√£¨∂‘”⁄ƒ˙ π”√µƒÕ¯¬Áø‚∞Ê±æ£¨“ª∞„«Èøˆœ¬∂º «÷ß≥÷∏ﬂº∂≈‰÷√µƒ;
														µ´∂‘”⁄±»Ωœ¿œµƒÕ¯¬Áø‚ª·≤ª÷ß≥÷dst°¢ntpµ»≈‰÷√£¨’‚÷÷«Èøˆ£¨Ω®“Èƒ˙…˝º∂dvr…Ë±∏*/
	SUPPORT_MULTI_STREAM    = (1 << 3),					//  «∑Ò÷ß≥÷∂‡¬Î¡˜
	SUPPORT_WIFI			= (1 << 4),					//  «∑Ò÷ß≥÷wifi
	SUPPORT_3G				= (1 << 5),					//  «∑Ò÷ß≥÷3G
	SUPPORT_P2P				= (1 << 6),					//  «∑Ò÷ß≥÷P2P
	PN_REBOOT				= (1 << 7),					// –ﬁ∏ƒ÷∆ Ω «∑Ò–Ë“™÷ÿ∆Ù
	NVR_CH_ATTR_EX			= (1 << 8),					
	CHANGE_RESOLUTION_REBOOT  =(1 << 9) ,               //–ﬁ∏ƒ∑÷±Ê¬ –Ë“™÷ÿ∆Ù
}net_capability_e;


//  ”∆µ∑÷±Ê¬ 
typedef enum
{
	ENC_SIZE_NOT_CARE = 0,		//Œ¨≥÷‘≠¿¥≥ﬂ¥Á≤ª±‰
	ENC_SIZE_CIF 	= 0x02,		//352*288
	ENC_SIZE_HD1	= 0x04,		//704*288
	ENC_SIZE_D1		= 0x08,		//704*576
	ENC_SIZE_720P	= 0x10,		//1280*720
	ENC_SIZE_1080P	= 0x20,		//1920*1080
	ENC_SIZE_SXGA	= 0x40,		//1280*1024
	ENC_SIZE_VGA	= 0x80,		//640*480
	ENC_SIZE_QVGA	= 0x100,	//320*240
	ENC_SIZE_QQVGA	= 0x200,	//176*128
	ENC_SIZE_1280x960 = 0x400,	//1280*960
	ENC_SIZE_960P = ENC_SIZE_1280x960,
	ENC_SIZE_960H   = 0x800,   //928x576
	ENC_SIZE_AUTO	= 0x1000,	//ipc ◊‘∂Ø ∂±≥ﬂ¥Á
	ENC_SIZE_3M = 0x2000,		//2304*1296
	ENC_SIZE_3stdM = 0x4000,	//2048*1536
	ENC_SIZE_5M = 0x8000,		//2592*1920
	ENC_SIZE_5stdM = 0x10000,	//2560*1920
}enc_size_e;

// ±‡Ω‚¬Î◊ ‘¥ ‹œﬁ¿‡–Õ
typedef enum
{
	AD_LIMIT_BY_ENC_PERFOR, //  ‹œﬁ”⁄ø’œ–±‡¬Î◊ ‘¥
	AD_LIMIT_BY_ANALOGO,	//  ‹œﬁ”⁄ø’œ–ƒ£ƒ‚Õ®µ¿
	AD_LIMIT_BY_NONE,		// ≤ª ‹œﬁ
}ad_ch_resource_type;


/*	
	…Ë±∏–≈œ¢£®÷ª∂¡£©
	ªÒ»°…Ë±∏–≈œ¢µƒ√¸¡ÓidŒ™msg_get_device_info
*/
typedef struct
{
	char board_name[max_name_len];						// ∞Â◊”√˚≥∆£®”√”⁄…˝º∂∞¸µƒ–£—È£©
	DWORD board_id;										// ∞Â–Õid
	DWORD serial_number;								// –Ú¡–∫≈
	char mac[max_name_len];								// …Ë±∏macµÿ÷∑£¨»Á£∫00:0b:74:9f:5f:33

	char software_version_base[max_name_len];			// ª˘¥°»Ìº˛∞Ê±æ£¨”√”⁄…˝º∂∞¸µƒ–£—È£¨∏Ò Ω:÷˜∞Ê±æ.¥Œ∞Ê±æ.–ﬁ∂©∞Ê±æ£¨»Á1.0.0
	char software_version_main[max_name_len];			// »Ìº˛∞Ê±æ£¨»Á1.0.0
	char software_build_date[max_name_len];				// »Ìº˛…˙≥…»’∆⁄
	char hardware_version[max_name_len];				// ”≤º˛∞Ê±æ£¨»Á1.0.0
	char hardware_build_date[max_name_len];				// ”≤º˛…˙≥…»’∆⁄
	
	DWORD video_analog_cnt_max;							// ƒ£ƒ‚Õ®µ¿◊Ó¥Û∏ˆ ˝
	DWORD video_digital_cnt_max;						//  ˝◊÷Õ®µ¿◊Ó¥Û∏ˆ ˝

	DWORD spot_cnt;										// spot∏ˆ ˝								
	DWORD audio_enc_cnt;								/* “Ù∆µÕ®µ¿∏ˆ ˝, ±Ì æ«∞audio_enc_cnt∏ˆ ”∆µÕ®µ¿÷ß≥÷“Ù∆µ,
														   ◊¢“‚£∫∂‘”⁄hvr/nvr…Ë±∏£¨∏√≤Œ ˝Œﬁ–ß*/
	DWORD audio_talk_cnt;								// ”Ô“Ù∂‘Ω≤∏ˆ ˝

	DWORD alarm_in_cnt;									// ±®æØ ‰»Î∏ˆ ˝	
	DWORD alarm_out_cnt;								// ±®æØ ‰≥ˆ∏ˆ ˝	

	DWORD video_enc_resolution;							/*  ”∆µ±‡¬Îƒ‹¡¶£®∑÷±Ê¬ £©£¨enc_size_e¿‡–Õµƒ◊È∫œ, 
														   ◊¢“‚£∫µ±net_capability÷ß≥÷Õ®µ¿ Ù–‘ ±£¨“‘∏˜Õ®µ¿ Ù–‘ƒ⁄µƒ∑÷±Ê¬ ƒ‹¡¶Œ™÷˜*/
	DWORD video_analog_performance;						// ƒ£ƒ‚ ”∆µ±‡¬Î–‘ƒ‹
	DWORD video_analog_digital_performance;				// ƒ£ƒ‚ ˝◊÷ ”∆µπ´”√±‡¬Î–‘ƒ‹
	DWORD video_digital_performance;					//  ˝◊÷ ”∆µ±‡¬Î–‘ƒ‹

	DWORD disk_cnt;										// ”≤≈Ã∏ˆ ˝
	DWORD capacity[max_hdd_cnt];						// ”≤≈Ã◊‹»›¡ø£¨µ•ŒªMB		
	DWORD useable[max_hdd_cnt];							// ”≤≈Ãø… π”√»›¡ø£¨µ•ŒªMB		
	DWORD write_status[max_hdd_cnt];					// ”≤≈Ã◊¥Ã¨£¨≤Œº˚disk_state_e
	char disk_type[max_hdd_cnt][max_name_len];			// ”≤≈Ã¿‡–Õ

	DWORD is_support_ch_auth;							// …Ë±∏ «∑Ò÷ß≥÷Õ®µ¿»®œﬁ
	DWORD net_capability;								// Õ¯¬Áƒ‹¡¶£¨net_capability_e¿‡–Õµƒ◊È∫œ
	ad_ch_resource_type ad_ch_res_type;					// ±‡Ω‚¬Î◊ ‘¥ ‹œﬁ¿‡–Õ
    int merge_ability ;                              //  «∑Ò÷ß≥÷∆¥Ω”¡˜ 1-÷ß≥÷ 0 - ≤ª÷ß≥÷

}dvr_device_info, *lpdvr_device_info;


/*	
	U≈Ã–≈œ¢£®÷ª∂¡£©
	ªÒ»°U≈Ã–≈œ¢µƒ√¸¡ÓidŒ™msg_get_usb_disk_info
*/
typedef struct
{
	long disk_cnt;										// u≈Ã∏ˆ ˝
	long capacity[max_usb_disk_cnt];					// u≈Ã◊‹»›¡ø£¨µ•ŒªMB		
	long useable[max_usb_disk_cnt];						// u≈Ãø… π”√»›¡ø£¨µ•ŒªMB		
	long write_status[max_usb_disk_cnt];				// u≈Ã◊¥Ã¨£¨≤Œº˚disk_state_e
	char disk_type[max_usb_disk_cnt][max_name_len];		// u≈Ã¿‡–Õ

}dvr_usb_disk_info;


/*	
	DST≈‰÷√
	ªÒ»°DST≈‰÷√µƒ√¸¡ÓidŒ™msg_get_dst_cfg
	…Ë÷√DST≈‰÷√µƒ√¸¡ÓidŒ™msg_set_dst_cfg
*/
typedef struct
{
	// œƒ¡Ó ±DST
	DWORD dst_enable;									//  «∑Òø™∆Ùœƒ¡Ó ±£¨0--πÿ±’ 1--ø™∆Ù
	DWORD adjust_time_len_s;							// µ˜’˚µƒ ±º‰≥§∂» (√Î)

	// œƒ¡Ó ±∆ º ±º‰
	int begin_month;									// [0,11]
	int begin_week_index;								// [1-5]
	int begin_week_day;									// [0-6]
	int begin_hour;										// [0-23]
	int begin_minute;									// [0-59]
	int begin_second;									// [0-59]

	// œƒ¡Ó ±Ω· ¯ ±º‰
	int end_month;										// [0,11]
	int end_week_index;									// [1-5]
	int end_week_day;									// [0-6]
	int end_hour;										// [0-23]
	int end_minute;										// [0-59]
	int end_second;										// [0-59]	

}dvr_dst_cfg, *lpdvr_dst_cfg;



/*	
	NTP≈‰÷√
	ªÒ»°NTP≈‰÷√µƒ√¸¡ÓidŒ™msg_get_ntp_cfg
	…Ë÷√NTP≈‰÷√µƒ√¸¡ÓidŒ™msg_set_ntp_cfg
*/
typedef struct
{
	int ntp_enable;										//  «∑Òø™∆ÙÕ¯¬Á ±º‰Õ¨≤Ω£¨0--πÿ±’ 1--ø™∆Ù
	int interval;										// Õ¨≤Ω ±º‰º‰∏Ù (24*3600 - 7*24*3600 √Î)
	int timezone_hour;									//  ±«¯£¨ ±(0-11)
	int timezone_min;									//  ±«¯£¨∑÷(0-59)

	char server[256];									// NTP∑˛ŒÒ∆˜

}dvr_ntp_cfg, *lpdvr_ntp_cfg;	



/*	
	”≤≈Ã≈‰÷√
	ªÒ»°”≤≈Ã≈‰÷√µƒ√¸¡ÓidŒ™msg_get_disk_cfg
	…Ë÷√”≤≈Ã≈‰÷√µƒ√¸¡ÓidŒ™msg_set_disk_cfg
*/
typedef struct
{
	int overwrite_enable;								//  «∑Òø™∆Ù”≤≈Ã∏≤∏«

}dvr_disk_cfg, *lpdvr_disk_cfg;



// ”√ªß»®œﬁ
typedef enum
{	
	eAuthority_Undefined		= 0x00,
	eAuthority_Configuration	= 0x01,					// œµÕ≥≈‰÷√»®œﬁ
	eAuthority_PTZControl		= 0x02,					// ‘∆Ã®øÿ÷∆»®œﬁ
	eAuthority_Playback			= 0x04,					// ªÿ∑≈»®œﬁ
	eAuthority_Backup			= 0x08,					// ±∏∑›»®œﬁ
	eAuthority_All				= eAuthority_Configuration | eAuthority_PTZControl | eAuthority_Playback | eAuthority_Backup,
}eAuthority;

/*	
	”√ªß≈‰÷√
	ªÒ»°”√ªß≈‰÷√µƒ√¸¡ÓidŒ™msg_get_user_cfg
	…Ë÷√”√ªß≈‰÷√µƒ√¸¡ÓidŒ™msg_set_user_cfg
*/
typedef struct
{
	int ch_auth_enable;									//  «∑Ò∆Ù”√Õ®µ¿»®œﬁ°£÷ª”–…Ë±∏”–¥Àƒ‹¡¶ ±≤≈ƒ‹∆Ù”√Õ®µ¿»®œﬁ

	char admin_name[max_user_name_len];					// π‹¿Ì‘±√˚≥∆£®÷ª∂¡£©£¨÷ªƒ‹ «"Admin"	
	char admin_pass[max_user_pwd_len];					// π‹¿Ì‘±√‹¬Î
	DWORD admin_auth;									// π‹¿Ì‘±»®œﬁ£®÷ª∂¡£©£¨π‹¿Ì‘±”µ”–À˘”–»®œﬁ£¨≤Œº˚eAuthority
	DWORD admin_ch_auth_mask;							// Õ®µ¿»®œﬁ—⁄¬Î

	DWORD user_cnt;										// ∆’Õ®”√ªßµƒ∏ˆ ˝
	char user_name[max_normal_user_cnt][max_user_name_len];	// ∆’Õ®”√ªßµƒ”√ªß√˚≥∆£¨”√ªß√˚≥∆≤ªŒ™ø’µƒ”√ªßº¥Œ™”––ß”√ªß
	char user_pass[max_normal_user_cnt][max_user_pwd_len];	// ∆’Õ®”√ªßµƒ”√ªß√‹¬Î
	DWORD user_auth[max_normal_user_cnt];				// ∆’Õ®”√ªßµƒ»®œﬁ,≤Œº˚eAuthority√∂æŸ¿‡–Õµƒ∂®“Â
	DWORD user_ch_auth_mask[max_normal_user_cnt];		// ∆’Õ®”√ªßµƒÕ®µ¿»®œﬁ—⁄¬Î
	
}dvr_user_cfg, *lpdvr_user_cfg;





/*	
	Õ®µ¿ª˘±æ≈‰÷√
	ªÒ»°Õ®µ¿ª˘±æ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_channel_basic_cfg
	…Ë÷√Õ®µ¿ª˘±æ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_channel_basic_cfg
*/
typedef struct
{	
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º
	char name[max_name_len];							// Õ®µ¿√˚≥∆, ◊¢“‚ π”√µƒ «utf-8±‡¬Î

	// …´≤ µ˜Ω⁄
	DWORD brightness;									// ¡¡∂» 0-255
	DWORD contrast;										// ∂‘±»∂» 0-255
	DWORD saturation;									// ±•∫Õ∂» 0-255
	DWORD hue;											// …´∂» 0-255	
	DWORD sharpness;									// »Ò∂»£®«ÂŒ˙∂»£© 0-255

	// –≈∫≈∂™ ß±®æØ 
	DWORD vl_trigger_record_mask;						// ¡™∂Ø¬ºœÒµƒÕ®µ¿—⁄¬Î£¨»Á∂˛Ω¯÷∆0101±Ì æ¥•∑¢µ⁄1°¢3Õ®µ¿µƒ¬ºœÒ
	DWORD vl_trigger_alarm_out_mask;					// ¡™∂Ø±®æØ ‰≥ˆµƒÕ®µ¿—⁄¬Î£¨∫¨“ÂÕ¨…œ
	DWORD vl_trigger_live;								// ¡™∂Ø‘§¿¿µƒÕ®µ¿∫≈£¨¥”0ø™ º£¨(DWORD)-1±Ì æπÿ±’¡™∂Ø‘§¿¿
	DWORD vl_trigger_buzzer;							// ¡™∂Ø∑‰√˘∆˜±®æØ
	DWORD vl_trigger_email;								// ¡™∂Ø” º˛Õ®∏Ê

	// “∆∂Ø’Ï≤‚ 
	DWORD motion_en;									//  «∑Ò¥Úø™“∆∂Ø’Ï≤‚£¨0--πÿ±’ 1--ø™∆Ù
	BYTE motion_area[motion_area_rect_row][motion_area_rect_column];// “∆∂Ø’Ï≤‚«¯”Ú£¨“‘∫ÍøÈŒ™µ•Œª£¨0--≥∑∑¿ 1--≤º∑¿
	DWORD motion_senstivity;							// “∆∂Ø’Ï≤‚¡È√Ù∂»£¨0-4£¨ ˝÷µ‘Ω¥Û¡È√Ù∂»‘Ω∏ﬂ
	DWORD mt_trigger_record_mask;						// ¡™∂Ø¬ºœÒµƒÕ®µ¿—⁄¬Î£¨»Á∂˛Ω¯÷∆0101±Ì æ¥•∑¢µ⁄1°¢3Õ®µ¿µƒ¬ºœÒ
	DWORD mt_trigger_alarm_out_mask;					// ¡™∂Ø±®æØ ‰≥ˆµƒÕ®µ¿—⁄¬Î£¨∫¨“ÂÕ¨…œ
	DWORD mt_trigger_live;								// ¡™∂Ø‘§¿¿µƒÕ®µ¿∫≈£¨¥”0ø™ º£¨(DWORD)-1±Ì æπÿ±’¡™∂Ø‘§¿¿
	DWORD mt_trigger_buzzer;							// ¡™∂Ø∑‰√˘∆˜±®æØ						
	DWORD mt_trigger_mail;								// ¡™∂Ø” º˛Õ®∏Ê

	//¬Ì»¸øÀ
	DWORD mosaic_cnt;									// ¬Ì»¸øÀµƒ∏ˆ ˝
	DWORD mosaic_x[max_mosaic_area_cnt];				// ¬Ì»¸øÀ«¯”Úµƒx◊¯±Í, [±»¿˝£¨∑÷ƒ∏πÃ∂®Œ™16£¨’‚¿Ô «∑÷◊”µƒ÷µ£∫0-16£¨œ¬Õ¨]
	DWORD mosaic_y[max_mosaic_area_cnt];				// ¬Ì»¸øÀ«¯”Úµƒy◊¯±Í
	DWORD mosaic_w[max_mosaic_area_cnt];				// ¬Ì»¸øÀ«¯”ÚµƒøÌ∂»
	DWORD mosaic_h[max_mosaic_area_cnt];				// ¬Ì»¸øÀ«¯”Úµƒ∏ﬂ∂»

}dvr_channel_basic_cfg, *lpdvr_channel_basic_cfg;

/*	
	Õ®µ¿PTZ≈‰÷√
	ªÒ»°Õ®µ¿PTZ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_channel_ptz_cfg
	…Ë÷√Õ®µ¿PTZ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_channel_ptz_cfg
*/
typedef struct
{
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º
	//	PTZ
	DWORD speed;										// ‘∆Ã®“∆∂ØµƒÀŸ∂»£¨1-16
	DWORD baudrate;										// ≤®Ãÿ¬ £¨1200, 2400, 4800, 9600
	DWORD databit;										//  ˝æ›Œª
	DWORD stopbit;										// Õ£÷πŒª
	DWORD parity;										// –£—ÈŒª
	DWORD address;										// ‘∆Ã®µÿ÷∑
	DWORD flowcontrol;									// ¡˜øÿ

	DWORD protocol_index;								// µ±«∞Õ®µ¿µƒ‘∆Ã®–≠“ÈÀ˜“˝	
	DWORD protocol_cnt;									// ‘∆Ã®–≠“È∏ˆ ˝
	char protocol_name[max_ptz_protocol_cnt][max_name_len]; // ÷ß≥÷µƒ‘∆Ã®–≠“È√˚≥∆

	DWORD cruise_preset_cnt;							// —≤∫Ω‘§÷√µ„∏ˆ ˝
	DWORD cruise_preset[max_cruise_preset_cnt];			// —≤∫Ω‘§÷√µ„id£¨¥”0ø™ º
	DWORD delay_time[max_cruise_preset_cnt];			// Õ£¡Ù ±º‰(√Î), 1-(24*3600)

}dvr_channel_ptz_cfg, *lpdvr_channel_ptz_cfg;



// ipc¿‡–Õ
typedef enum eIPCType
{
	eIpcType_None,				// ≤ª «IPC
	eIPCType_AutoAdapt = 1,		// ◊‘∂Ø  ∆•IPCµƒ¿‡–Õ,”√ªß”¶∏√æ°¡ø π”√»∑«–µƒ¿‡–Õ,∑Ò‘Úª·“ÚŒ™÷ß≥÷¿‡–Õµƒ‘ˆ∂‡”∞œÏ≥…π¶¡¨Ω”µƒ ±º‰ (‘§¡Ù)
	eIPCType_AMTK_V5,			// A-MTK V5–Õ,“ª∞„÷∏MTK 1.3MegaµƒIPC,»Ìº˛∞Ê∞Â «5.0µƒ (‘§¡Ù)
	eIPCType_AMTK_V6,			// A-MTK V6–Õ,“ª∞„÷∏MTK 2.0MegaµƒIPC,»Ìº˛∞Ê∞Â «6.0µƒ
	eIPCType_GK,
	eIPCType_ONVIF,
	eIPCType_IPUX,				// IPUX≥ßº“µƒ,÷ª÷ß≥÷“ª∏ˆ¬Î¡˜.
	eIPCType_ONVIF_TST,			// ÃÏ ”Õ®ONVIF–≠“È
}eIPCType;

typedef enum eDeviceType
{
	eType_DAHUA,
	eType_WAPA,
	eType_HAIXIN,
	eType_HANWEI,
	eType_GK,
	eType_TST,
	eType_IPNC,				//∂˜—µ
	eType_Unknow,
}eDevice_Type;

/*	
	Õ®µ¿ Ù–‘≈‰÷√
	ªÒ»°Õ®µ¿ Ù–‘≈‰÷√µƒ√¸¡ÓidŒ™msg_get_channel_attr_cfg
	…Ë÷√Õ®µ¿ Ù–‘≈‰÷√µƒ√¸¡ÓidŒ™msg_set_channel_attr_cfg
*/
typedef struct
{
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º
	int enable;											// µ±«∞Õ®µ¿ «∑Ò“—æ≠∆Ù”√.
	int is_ipcam;										// µ±«∞Õ®µ¿ «±æµÿÕ®µ¿ªπ «IPCAMÕ®µ¿. 0--±æµÿ 1--IPÕ®µ¿£®÷ª∂¡£©
	int ipcam_port;										// IPCAMµƒ–≈¡Ó∂Àø⁄.
	int ipcam_channel;									// IPCAMµƒÕ®µ¿∫≈,“ª∞„Œ™0.
	int ipcam_resolution;								// IPCAMµƒ±‡¬Î∑÷±Ê¬ 
	DWORD video_enc_resolution;							//  ”∆µ±‡¬Îƒ‹¡¶£®∑÷±Ê¬ £©£¨enc_size_e¿‡–Õµƒ◊È∫œ

	DWORD ipcam_ipaddr;									// IPCAMµƒIPµÿ÷∑.
	char ipcam_username[max_user_name_len];				// µ«¬ΩIPCAMµƒ”√ªß√˚
	char ipcam_password[max_user_pwd_len];				// µ«¬ΩIPCAMµƒ”√ªß√‹¬Î
	eIPCType ipcam_type;// IPCAM¿‡–Õ
	eDevice_Type device_type;		// IPCµƒ¿‡–Õ
	int channel;
	int protocol;

}dvr_channel_attr_cfg, *lpdvr_channel_attr_cfg;


// ipcπ§◊˜ƒ£ Ω
 typedef enum
 {
 	IPC_AE_INDOOR_MODE = 0, // “ƒ⁄ƒ£ Ω
 	IPC_AE_OUTDOOR_MODE = 1, // “Õ‚ƒ£ Ω
 }ipc_ae_work_mode;

 typedef enum
 {
	 ICR_WORK_BY_CHECK_LEVEL,	// ◊‘∂Ø£¨∏˘æ›µ∆∞ÂºÏ≤‚µÁ—π∫Õœ‡πÿ≈‰÷√¿¥π§◊˜
	 ICR_WORK_FORCE_DAY,		// «ø÷∆≤ …´
	 ICR_WORK_FORCE_NIGHT,		// «ø÷∆∫⁄∞◊
 }icr_wrok_mode;

/*	
	IPC≈‰÷√
	ªÒ»°IPC≈‰÷√µƒ√¸¡ÓidŒ™msg_get_ipc_cfg
	…Ë÷√IPC≈‰÷√µƒ√¸¡ÓidŒ™msg_set_ipc_cfg
*/
typedef struct
{
	// ◊‘∂Ø∆ÿπ‚
	ipc_ae_work_mode work_mode;							// π§◊˜ƒ£ Ω
	long outdoor_day;									//  “ƒ⁄∞◊ÃÏ 1-100
	long outdoor_night;									//  “ƒ⁄∫⁄“π	1-100
	long indoor_day;									// ªßÕ‚∞◊ÃÏ1-100									
	long indoor_night;									// ªßÕ‚∫⁄“π1-100
	long frequence;										// µÁ‘¥∆µ¬  50HZ/60HZ

	// …´≤ ƒ£ Ω
	char fixed_mode_start_hour;							// ∆ º–° ±£¨0-23,default 18
	char fixed_mode_start_min;							// ∆ º∑÷÷”£¨0-59,default 0
	char fixed_mode_end_hour;							// Ω· ¯–° ±£¨0-23,default 21
	char fixed_mode_end_min;							// Ω· ¯∑÷÷”£¨0-59,default 0
	long fixed_mode;									// «ø÷∆Œ™∫Œ÷÷ƒ£ Ω, ≤Œº˚icr_wrok_mode

}dvr_ipc_cfg, *lpdvr_ipc_cfg;


/*
	Õ®µ¿–≈œ¢£®÷ª∂¡£©
	ªÒ»°Õ®µ¿–≈œ¢µƒ√¸¡ÓidŒ™msg_get_channel_info
*/
typedef struct
{
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º

	DWORD is_recording;									//  «∑Ò’˝‘⁄¬ºœÒ£¨0--Œ¥¬ºœÒ 1--’˝‘⁄¬ºœÒ
	DWORD record_type;									// ¬ºœÒ¿‡–Õ£¨≤Œº˚record_type_e√∂æŸ¿‡–Õ∂®“Â
	DWORD record_resolution;							// ¬ºœÒ∑÷±Ê¬ £¨ ≤Œº˚enc_size_e√∂æŸ¿‡–Õµƒ∂®“Â
	DWORD record_fps;									//  µº ÷°¬ £¨µ•Œªfps
	DWORD record_kpbs;									//  µº ¬Î¬ £¨µ•Œªkbps

	DWORD is_videolost;									// –≈∫≈ «∑Ò∂™ ß
	DWORD is_motion;									// µ±«∞ «∑Ò”–“∆∂Ø ¬º˛
	
}dvr_channel_info, *lpdvr_channel_info;





// ¬ºœÒ¡˜¿‡–Õ
typedef enum
{
	eRecordSourceType_VideoOnly,						//  ”∆µ¡˜	
	eRecordSourceType_VideoAudio,						// “Ù ”∆µ∏¥∫œ¡˜
	eRecordSourceType_Undefined							// Œ¥∂®“Â
}eRecordSourceType;

/*	
	¬ºœÒº∆ªÆ≈‰÷√
	ªÒ»°¬ºœÒº∆ªÆ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_record_schedule_cfg
	…Ë÷√¬ºœÒº∆ªÆ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_record_schedule_cfg
*/
typedef struct 
{
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º

	DWORD stream_type;									// ¬ºœÒµƒ¡˜¿‡–Õ£¨≤Œº˚eRecordSourceType√∂æŸ¿‡–Õ∂®“Â
	DWORD prerecord_time;								// ‘§¬º ±º‰	
	DWORD delayrecord_time;								// —”≥Ÿ¬ºœÒ ±º‰		
	BYTE schedule[day_per_week][hour_per_day];			// “ª÷‹µƒ¬ºœÒº∆ªÆ£¨“‘–° ±Œ™µ•ŒªΩ¯––…Ë÷√£¨¬ºœÒ¿‡–Õ≤Œº˚record_type_e

}dvr_record_schedule_cfg;

/*	
	¬ºœÒª≠÷ ≈‰÷√
	ªÒ»°¬ºœÒª≠÷ ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_record_quality_cfg
	…Ë÷√¬ºœÒª≠÷ ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_record_quality_cfg
*/
typedef struct 
{
	int video_channel;									// Õ®µ¿∫≈£¨¥”0ø™ º

	int bitrate;										/* ∆’Õ®¬ºœÒ¬Î¬ , µ•Œªkbps£¨
														   »°÷µ∑∂Œß£∫256, 384, 512, 640, 768, 1024, 1536, 2048, 2560, 3072, 4096, 5120, 6144 */
	int framerate;										// ∆’Õ®¬ºœÒ÷°¬ £¨1-30 £®FPS£©
	int resolution;										// ∆’Õ®¬ºœÒ∑÷±Ê¬ £¨≤Œº˚enc_size_e

	int event_bitrate;									/*  ¬º˛¬ºœÒ¬Î¬ , µ•Œªkbps£¨
														   »°÷µ∑∂Œß£∫256, 384, 512, 640, 768, 1024, 1536, 2048, 2560, 3072, 4096, 5120, 6144 */
	int event_framerate;								//  ¬º˛¬ºœÒ÷°¬ £¨1-30 £®FPS£©
	int event_resolution;								//  ¬º˛¬ºœÒ∑÷±Ê¬ £¨≤Œº˚enc_size_e
						 
}dvr_record_quality_cfg; 





/*	
	±®æØ ‰»Î≈‰÷√
	ªÒ»°±®æØ ‰»Î≈‰÷√µƒ√¸¡ÓidŒ™msg_get_alarm_in_cfg
	…Ë÷√±®æØ ‰»Î≈‰÷√µƒ√¸¡ÓidŒ™msg_set_alarm_in_cfg
*/
typedef struct
{
	int alarm_in_channel;								// ±®æØ ‰»ÎÕ®µ¿∫≈£¨¥”0ø™ º
	DWORD device_type;									// ±®æØ…Ë±∏¿‡–Õ£¨0--≥£±’ 1--≥£ø™
	BYTE schedule[day_per_week][hour_per_day];			// “ª÷‹µƒ±®æØº∆ªÆ£¨“‘–° ±Œ™µ•ŒªΩ¯––…Ë÷√£¨0--≥∑∑¿ 1--≤º∑¿

	DWORD trigger_record_mask;							// ¡™∂Ø¬ºœÒµƒÕ®µ¿—⁄¬Î£¨»Á∂˛Ω¯÷∆0101±Ì æ¥•∑¢µ⁄1°¢3Õ®µ¿µƒ¬ºœÒ
	DWORD trigger_alarm_out_mask;						// ¡™∂Ø±®æØ ‰≥ˆµƒÕ®µ¿—⁄¬Î£¨∫¨“ÂÕ¨…œ
	DWORD trigger_live;									// ¡™∂Ø‘§¿¿µƒÕ®µ¿∫≈£¨¥”0ø™ º£¨(DWORD)-1±Ì æπÿ±’¡™∂Ø‘§¿¿
	DWORD trigger_preset;								// ¡™∂Øµƒ‘§÷√µ„À˜“˝£¨¥”0ø™ º
	DWORD trigger_buzzer;								// ¡™∂Ø∑‰√˘∆˜±®æØ
	DWORD trigger_mail;									// ¡™∂Ø” º˛Õ®∏Ê

}dvr_alarm_in_cfg, *lpdvr_alarm_in_cfg;

/*	
	±®æØ ‰»Î–≈œ¢£®÷ª∂¡£©
	ªÒ»°±®æØ ‰»Î–≈œ¢µƒ√¸¡ÓidŒ™msg_get_alarm_in_info
*/
typedef struct
{
	int alarm_in_channel;								// ±®æØ ‰»ÎÕ®µ¿∫≈£¨¥”0ø™ º
	DWORD device_type;									// ±®æØ…Ë±∏¿‡–Õ£¨0--≥£±’ 1--≥£ø™
	DWORD status;										// …Ë±∏◊¥Ã¨£¨0--’˝≥£ 1--±®æØ
}dvr_alarm_in_info, *lpdvr_alarm_in_info;




/*	
	Õ¯¬Áª˘±æ≈‰÷√
	ªÒ»°Õ¯¬Áª˘±æ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_network_basic_cfg
	…Ë÷√Õ¯¬Áª˘±æ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_network_basic_cfg
*/
typedef struct 
{
	int ip;												// ipµÿ÷∑
	int submask;										// ◊”Õ¯—⁄¬Î
	int gateway;										// Õ¯πÿ
	int dns1;											// DNS1
	int dns2;											// DNS2

	int http_port;										// http∂Àø⁄£¨ƒ¨»œ80
	int cmd_port;										// –≈¡Ó∂Àø⁄£¨ƒ¨»œ6001
	int data_port;										// √ΩÃÂ∂Àø⁄£¨ƒ¨»œ6002
	int mobile_port;									//  ÷ª˙∂Àø⁄£¨ƒ¨»œ6003
	
	int upnp_enable;									// UPnP…Ë÷√£¨0--πÿ±’ 1--ø™∆Ù
	int dhcp_enable;									// IPªÒ»°∑Ω Ω£¨0--æ≤Ã¨≈‰÷√ 1--∂ØÃ¨ªÒ»°
	int p2p_enable;										//  «∑Ò∆Ù”√P2P, 0--Ω˚”√£¨1--∆Ù”√

}dvr_network_basic_cfg, *lpdvr_network_basic_cfg;

/*	
	Õ¯¬Á∏ﬂº∂≈‰÷√
	ªÒ»°Õ¯¬Á∏ﬂº∂≈‰÷√µƒ√¸¡ÓidŒ™msg_get_network_advanced_cfg
	…Ë÷√Õ¯¬Á∏ﬂº∂≈‰÷√µƒ√¸¡ÓidŒ™msg_set_network_advanced_cfg
*/
typedef struct  
{
	DWORD pppoe_enable;									//  «∑Òø™∆Ù≤¶∫≈£¨0--πÿ±’ 1--ø™∆Ù
	char pppoe_user[max_user_name_len];					// pppoe”√ªß√˚
	char pppoe_pass[max_user_pwd_len];					// pppoe”√ªß√‹¬Î

	DWORD ddns_enable;									//  «∑Òø™∆Ù∂ØÃ¨”Ú√˚£¨0--πÿ±’ 1--ø™∆Ù
	DWORD server_index;									// µ±«∞ π”√µƒddns”Ú√˚∑˛ŒÒ∆˜À˜“˝
	char domain_name[max_name_len];						// …Ë±∏”Ú√˚
	char ddns_user[max_user_name_len];					// ddns”√ªß√˚
	char ddns_pass[max_user_pwd_len];					// ddns”√ªß√‹¬Î
	DWORD server_cnt;									// ”Ú√˚∑˛ŒÒ∆˜∏ˆ ˝			
	char server_info[max_ddns_protocol_cnt][max_address_len]; // ”Ú√˚∑˛ŒÒ∆˜–≈œ¢

	// email
	DWORD email_enable;									//  «∑Ò∆Ù”√” º˛£¨0--πÿ±’ 1--ø™∆Ù
	char email_server[max_address_len];					// ∑¢ÀÕ” º˛∑˛ŒÒ∆˜£®SMTP£©
	DWORD email_port;									// ∑˛ŒÒ∆˜∂Àø⁄
	DWORD ssl_enable;									//  «∑Ò–Ë“™∞≤»´¡¨Ω”£¨0--πÿ±’ 1--ø™∆Ù
	char email_sender[max_address_len];					// ∑¢º˛»À” œ‰
	char email_user[max_email_username_len];			// ”√ªß√˚≥∆
	char email_pass[max_email_userpass_len];			// ”√ªß√‹¬Î
	char email_receiver[max_email_receiver_cnt][max_address_len]; //  ’º˛»À” œ‰
	int  need_snapshot;									// ∏Ω¥¯◊•Õº£¨0--πÿ±’ 1--ø™∆Ù

	// subcode
	DWORD subcode_enable;								//  «∑Òø™∆Ù◊”¬Î¡˜£¨0--πÿ±’ 1--ø™∆Ù
	DWORD framerate_by_fps;								// ◊”¬Î¡˜÷°¬ £¨µ•Œªfps£¨∑∂Œß1-30
	DWORD bitrate_by_kbps;								// ◊”¬Î¡˜¬Î¬ £¨µ•Œªkbps£¨∑∂Œß10-512

}dvr_network_advanced_cfg;

// 3G ∑˛ŒÒÃ·π©…Ã¿‡–Õ
typedef enum provider_type_s
{
	NET_3G_AUTO,
	NET_3G_TD_SCDMA,
	NET_3G_WCDMA,		// ÷–π˙¡™Õ®
	NET_3G_CDMA_1x,		// ÷–π˙µÁ–≈
	NET_3G_GPRS,		// ÷–π˙“∆∂Ø
	NET_3G_EVDO,
}provider_type_t;

/*	
	Õ¯¬ÁŒﬁœﬂ≈‰÷√
	ªÒ»°Õ¯¬ÁŒﬁœﬂ≈‰÷√µƒ√¸¡ÓidŒ™msg_get_network_wireless_cfg
	…Ë÷√Õ¯¬ÁŒﬁœﬂ≈‰÷√µƒ√¸¡ÓidŒ™msg_set_network_wireless_cfg
*/
typedef struct
{
	// wifi
	long wifi_enable;									//  «∑Ò∆Ù”√WIFI£¨0--πÿ±’ 1--ø™∆Ù
	char wifi_pass[32];									// ∑√Œ µƒwifiÕ¯¬Áµƒ√‹¬Î
	char wifi_ssid[32];									// ∑√Œ µƒwifiÕ¯¬ÁµƒSSID
	long wifi_auto_join;								//  «∑Ò◊‘∂Øº”»Î
	long wifi_enable_dhcp;								// wifi∂Àø⁄ «∑Ò πƒ‹dhcp
	long wifi_static_ip;								// »Áπ˚ πƒ‹dhcp£¨∏√œÓ∫ˆ¬‘
	long wifi_static_submask;							// »Áπ˚ πƒ‹dhcp£¨∏√œÓ∫ˆ¬‘
	long wifi_static_gw;								// »Áπ˚ πƒ‹dhcp£¨∏√œÓ∫ˆ¬‘
	long wifi_static_dns1;								// »Áπ˚ πƒ‹dhcp£¨∏√œÓ∫ˆ¬‘
	long wifi_static_dns2;								// »Áπ˚ πƒ‹dhcp£¨∏√œÓ∫ˆ¬‘

	// 3Gπ¶ƒ‹
	long net3g_enable;									//  «∑Òø™∆Ù,1,ø™∆Ù,0,Ω˚”√.
	provider_type_t net3g_provider_type;				// ∑˛ŒÒÃ·π©…Ã¿‡–Õ
	char net3g_dial_number[32];							// ∫≈¬Î
	char net3g_username[32];							// ”√ªß√˚
	char net3g_password[32];							// √‹¬Î
	char net3g_apn[32];									// APN

}dvr_network_wireless_cfg;


/*	
	Õ¯¬Á–≈œ¢£®÷ª∂¡£©
	ªÒ»°Õ¯¬Á–≈œ¢µƒ√¸¡ÓidŒ™msg_get_network_info
*/
typedef struct
{
	int ip;												// ipµÿ÷∑
	int submask;										// ◊”Õ¯—⁄¬Î
	int gateway;										// Õ¯πÿ
	int dns1;											// DNS1
	int dns2;											// DNS2
	char mac[max_name_len];								// …Ë±∏macµÿ÷∑£¨»Á£∫00:0b:74:9f:5f:33

	// pppoe info
	int pppoe_status;									// ≤¶∫≈◊¥Ã¨£¨0--Œ¥¡¨Ω” 1--¡¨Ω”
	int pppoe_ip;										// ≤¶∫≈ip
	int pppoe_submask;									// pppoe◊”Õ¯—⁄¬Î
	int pppoe_gateway;									// pppoeÕ¯πÿ

	// ◊‘¥¯”Ú√˚
	char own_domain_name[64];							// ”Ú√˚√˚≥∆
	time_t last_update_time;							// ◊Ó∫Û“ª∏ˆ≥…π¶À¢–¬ipµƒ ±º‰£¨∆Ù∂Øµƒ ±∫ÚŒ™0
	char spare_domain_name[max_spare_domain_cnt][64];	// ±∏”√”Ú√˚√˚≥∆
	time_t spare_last_update_time[max_spare_domain_cnt];// ±∏”√”Ú√˚◊Ó∫Û“ª¥Œ÷ÿ–¬À¢–¬ipµƒ ±º‰

}dvr_network_info, *lpdvr_network_info;


/*	
	Œﬁœﬂ–≈œ¢£®÷ª∂¡£©
	ªÒ»°Œﬁœﬂ–≈œ¢µƒ√¸¡ÓidŒ™msg_get_wireless_info
*/
typedef struct
{
	// wifi
	char wifi_ssid[32];									// SSID
	long wifi_connect_status;							//  «∑Ò¡¨Ω”
	long wifi_ip;										// wifi ipµÿ÷∑								
	long wifi_submask;									// wifi ◊”Õ¯—⁄¬Î
	long wifi_gw;										// wifi Õ¯πÿ
	long wifi_dns1;										// wifi DNS1
	long wifi_dns2;										// wifi DNS2

	// 3G
	long net3g_status;									//  «∑Ò¡¨Ω”…œ
	long net3g_ip;										// IP
	long net3g_submask;									// ◊”Õ¯—⁄¬Î
	long net3g_gateway;									// Õ¯πÿ
	int net3g_reserved[128];							// ±£¡Ù”√

}dvr_network_wireless_info;


/*	
	wifiÀ—À˜–≈œ¢£®÷ª∂¡£©
	ªÒ»°wifiÀ—À˜–≈œ¢µƒ√¸¡ÓidŒ™msg_get_wifi_search_info
*/
typedef struct
{
	long count;											// ≤È’“µΩµƒwifiÕ¯¬Áµƒ◊‹ ˝
	char ssid[max_wifi_search_cnt][32];					// ssid
	long quality[max_wifi_search_cnt];					// –≈∫≈«ø∂»£¨0-100£¨0-◊Ó»ı£¨100-◊Ó«ø
	long encryption[max_wifi_search_cnt];				//  «∑Òº”√‹£¨0-no£¨1-yes
	long is_join[max_wifi_search_cnt];					//  «∑Ò“—º”»Î£¨0-no 1-yes
	long state[max_wifi_search_cnt];					// ¡¨Ω”◊¥Ã¨£¨0-no 1-yes
}wifi_search_info;

typedef struct {
	int auto_update; // «∑Ò ÷∂Ø∏¸–¬
	char server_ip[64]; //ftp∑˛ŒÒ∆˜IP
	int ADFTP_port; // adftp ∂Àø⁄
	int  manual_update; //  ÷∂Ø∏¸–¬
	char ADFTP_usrname[32]; //adftp ”√ªß√˚
	char ADFTP_password[32]; //adftp √‹¬Î
	int  connect_status; //¡¨Ω”◊¥Ã¨
	int system_version; //œµÕ≥∞Ê±æ
	int year; 
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int update_status; //∏¸–¬◊¥Ã¨
	char	 reserved[64]; //”√”⁄‘§¡Ù
}dvr_adftp_cfg;


typedef struct tagExecuteCmd
{
 char buf[512]; //linux √¸¡Ó––◊÷∑˚¥Æ
}dvr_cmd_line;


typedef struct
{
	char usrname[32];  //”√ªß√˚
	char password[32]; //√‹¬Î
	char mac_address[32]; //mac µÿ÷∑
	char ip_address[32];  //ip µÿ÷∑
	int  http_port; //http∂Àø⁄ 
    int  cmd_port;  //√¸¡Ó∂Àø⁄
	int  media_port;  //√ΩÃÂ∂Àø⁄
	int  phone_port;  // ÷ª˙∂Àø⁄
	int ipc_type;					// eIPC_Type
	int board_type;				// ∞Ê–ÕID(≤ŒøºœµÕ≥SDK÷–µƒ∂®“Â)
	int device_type;				// …Ë±∏¿‡–Õ(≤ŒøºœµÕ≥SDK÷–µƒ∂®“Âhsx_device_type)
	int ipc_protocol;   //–≠“È¿‡–Õ
	int reserved[12];	//‘§¡Ù
}ipc_search_info;

typedef enum
{
	HSX_UNKOWN_DEV = 0,	//≤ª»œ ∂µƒ…Ë±∏
	HSX_GM818X_DVR,		//GM818Xµƒdvr
	HSX_GM812X_IPC,		//GM812Xµƒipc
	HSX_HI3520_DVR,		//hisiliconµƒdvr
	HSX_HI3520_HVR,		//hisiliconµƒhvr
	HSX_HI3520_NVR,		//hisiliconµƒnvr
	HSX_GM818X_NVR,

	HSX_HI3531_HVR,
	HSX_HI3531_NVR,
	//¿œ≤˙∆∑£¨“—æ≠≥ˆ»•¡À£¨¥ÏæÕ¥Ï£¨≤ª∂ØÀ˚¡À£¨–¬µƒ∂ºª·∑µªÿœ¬√ÊÀƒ÷÷£¨
	//œ‡µ±”⁄“ªπ≤13÷÷≤˙∆∑
	//–¬≤˙∆∑∞¥’’œ¬√Ê√Ë ˆ¥¶¿Ì£¨”…”⁄…œ≤„”√char¿¥¥´µ›£¨∂®“Â≤ªƒ‹≥¨π˝255
	HSX_PRODUCT_DVR = 50,
	HSX_PRODUCT_HVR = 100,
	HSX_PRODUCT_NVR = 150,
	HSX_PRODUCT_IPC = 200,
}hsx_device_type;

typedef struct 
{
  ipc_search_info ipc_info[MAX_IPC_SEARCH_CNT]; 
  int total_cnt;
}ipc_search_info_result;

typedef enum
{
	BITCTL_MOD_UNCFG = -1,	//Œ¨≥÷‘≠¿¥≤Œ ˝≤ª±‰
	BITCTL_MOD_VBR = 0,		//vbr
	BITCTL_MOD_CBR = 1,		//cbr
	BITCTL_MOD_HBR = 2,		//hbr
}bit_ctlmod_e;

typedef struct
{
	int	 start_ch;			//÷∏√˜∆ ºÕ®µ¿∫≈  ¥”0ø™ º
	int	  rect_num;	       // ‰≥ˆÕ®µ¿µƒ ˝ƒø  4/9/16/25
	bit_ctlmod_e	bit_ctl;		//¬Î¬ øÿ÷∆∑Ω Ω
	int 			    bit_kbps;		//¬Î¬ kbps
	int 			    frame_rate; 	//÷°¬ 
	enc_size_e		enc_size;		//±‡¬Î≥ﬂ¥Á
	unsigned int channel;
	long stream;	
	char        reverse[64] ;	
}merge_channel_cfg;


typedef struct
{
    int key_id;
    int action;
}pkg_remote_key_t;

#pragma pack(pop)

#endif


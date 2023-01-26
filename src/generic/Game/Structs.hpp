#pragma once

#ifdef __cplusplus
#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#define XFILE_BLOCK_SIZE 0x7FC0
#define XFILE_CHUNK_SIZE 0x8000

#define XFILE_MAGIC_RAW 0x3030317576734154
#define XFILE_MAGIC_SIGNED 0x3030313066664154
#define XFILE_MAGIC_UNSIGNED 0x3030317566664154

#define XFILE_IV_MAGIC_IDENTIFIER 0x3137734245454850	// PHEEBs71

namespace Game
{
#pragma warning(push)
#pragma warning(disable: 4324)
#endif

	typedef float vec2_t[2];
	typedef float vec3_t[3];
	typedef float vec4_t[4];

	typedef vec4_t float44[4];

	enum XAssetType
	{
		ASSET_TYPE_XMODELPIECES = 0x0,
		ASSET_TYPE_PHYSPRESET = 0x1,
		ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
		ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
		ASSET_TYPE_XANIMPARTS = 0x4,
		ASSET_TYPE_XMODEL = 0x5,
		ASSET_TYPE_MATERIAL = 0x6,
		ASSET_TYPE_TECHNIQUE_SET = 0x7,
		ASSET_TYPE_IMAGE = 0x8,
		ASSET_TYPE_SOUND = 0x9,
		ASSET_TYPE_SOUND_PATCH = 0xA,
		ASSET_TYPE_CLIPMAP = 0xB,
		ASSET_TYPE_CLIPMAP_PVS = 0xC,
		ASSET_TYPE_COMWORLD = 0xD,
		ASSET_TYPE_GAMEWORLD_SP = 0xE,
		ASSET_TYPE_GAMEWORLD_MP = 0xF,
		ASSET_TYPE_MAP_ENTS = 0x10,
		ASSET_TYPE_GFXWORLD = 0x11,
		ASSET_TYPE_LIGHT_DEF = 0x12,
		ASSET_TYPE_UI_MAP = 0x13,
		ASSET_TYPE_FONT = 0x14,
		ASSET_TYPE_FONTICON = 0x15,
		ASSET_TYPE_MENULIST = 0x16,
		ASSET_TYPE_MENU = 0x17,
		ASSET_TYPE_LOCALIZE_ENTRY = 0x18,
		ASSET_TYPE_WEAPON = 0x19,
		ASSET_TYPE_WEAPONDEF = 0x1A,
		ASSET_TYPE_WEAPON_VARIANT = 0x1B,
		ASSET_TYPE_WEAPON_FULL = 0x1C,
		ASSET_TYPE_ATTACHMENT = 0x1D,
		ASSET_TYPE_ATTACHMENT_UNIQUE = 0x1E,
		ASSET_TYPE_WEAPON_CAMO = 0x1F,
		ASSET_TYPE_SNDDRIVER_GLOBALS = 0x20,
		ASSET_TYPE_FX = 0x21,
		ASSET_TYPE_IMPACT_FX = 0x22,
		ASSET_TYPE_AITYPE = 0x23,
		ASSET_TYPE_MPTYPE = 0x24,
		ASSET_TYPE_MPBODY = 0x25,
		ASSET_TYPE_MPHEAD = 0x26,
		ASSET_TYPE_CHARACTER = 0x27,
		ASSET_TYPE_XMODELALIAS = 0x28,
		ASSET_TYPE_RAWFILE = 0x29,
		ASSET_TYPE_STRINGTABLE = 0x2A,
		ASSET_TYPE_LEADERBOARD = 0x2B,
		ASSET_TYPE_XGLOBALS = 0x2C,
		ASSET_TYPE_DDL = 0x2D,
		ASSET_TYPE_GLASSES = 0x2E,
		ASSET_TYPE_EMBLEMSET = 0x2F,
		ASSET_TYPE_SCRIPTPARSETREE = 0x30,
		ASSET_TYPE_KEYVALUEPAIRS = 0x31,
		ASSET_TYPE_VEHICLEDEF = 0x32,
		ASSET_TYPE_MEMORYBLOCK = 0x33,
		ASSET_TYPE_ADDON_MAP_ENTS = 0x34,
		ASSET_TYPE_TRACER = 0x35,
		ASSET_TYPE_SKINNEDVERTS = 0x36,
		ASSET_TYPE_QDB = 0x37,
		ASSET_TYPE_SLUG = 0x38,
		ASSET_TYPE_FOOTSTEP_TABLE = 0x39,
		ASSET_TYPE_FOOTSTEPFX_TABLE = 0x3A,
		ASSET_TYPE_ZBARRIER = 0x3B,
		ASSET_TYPE_COUNT = 0x3C,
		ASSET_TYPE_STRING = 0x3C,
		ASSET_TYPE_ASSETLIST = 0x3D,
		ASSET_TYPE_REPORT = 0x3E,
		ASSET_TYPE_DEPEND = 0x3F,
		ASSET_TYPE_FULL_COUNT = 0x40,
		ASSET_TYPE_INVALID = -1,
	};

	enum bdLobbyErrorCode
	{
		BD_NO_ERROR = 0x0,
		BD_TOO_MANY_TASKS = 0x1,
		BD_NOT_CONNECTED = 0x2,
		BD_SEND_FAILED = 0x3,
		BD_HANDLE_TASK_FAILED = 0x4,
		BD_START_TASK_FAILED = 0x5,
		BD_RESULT_EXCEEDS_BUFFER_SIZE = 0x64,
		BD_ACCESS_DENIED = 0x65,
		BD_EXCEPTION_IN_DB = 0x66,
		BD_MALFORMED_TASK_HEADER = 0x67,
		BD_INVALID_ROW = 0x68,
		BD_EMPTY_ARG_LIST = 0x69,
		BD_PARAM_PARSE_ERROR = 0x6A,
		BD_PARAM_MISMATCHED_TYPE = 0x6B,
		BD_SERVICE_NOT_AVAILABLE = 0x6C,
		BD_CONNECTION_RESET = 0x6D,
		BD_INVALID_USER_ID = 0x6E,
		BD_LOBBY_PROTOCOL_VERSION_FAILURE = 0x6F,
		BD_LOBBY_INTERNAL_FAILURE = 0x70,
		BD_LOBBY_PROTOCOL_ERROR = 0x71,
		BD_LOBBY_FAILED_TO_DECODE_UTF8 = 0x72,
		BD_LOBBY_ASCII_EXPECTED = 0x73,
		BD_ASYNCHRONOUS_ERROR = 0xC8,
		BD_STREAMING_COMPLETE = 0xC9,
		BD_MEMBER_NO_PROPOSAL = 0x12C,
		BD_TEAMNAME_ALREADY_EXISTS = 0x12D,
		BD_MAX_TEAM_MEMBERSHIPS_LIMITED = 0x12E,
		BD_MAX_TEAM_OWNERSHIPS_LIMITED = 0x12F,
		BD_NOT_A_TEAM_MEMBER = 0x130,
		BD_INVALID_TEAM_ID = 0x131,
		BD_INVALID_TEAM_NAME = 0x132,
		BD_NOT_A_TEAM_OWNER = 0x133,
		BD_NOT_AN_ADMIN_OR_OWNER = 0x134,
		BD_MEMBER_PROPOSAL_EXISTS = 0x135,
		BD_MEMBER_EXISTS = 0x136,
		BD_TEAM_FULL = 0x137,
		BD_VULGAR_TEAM_NAME = 0x138,
		BD_TEAM_USERID_BANNED = 0x139,
		BD_TEAM_EMPTY = 0x13A,
		BD_INVALID_TEAM_PROFILE_QUERY_ID = 0x13B,
		BD_TEAMNAME_TOO_SHORT = 0x13C,
		BD_UNIQUE_PROFILE_DATA_EXISTS_ALREADY = 0x13D,
		BD_INVALID_LEADERBOARD_ID = 0x190,
		BD_INVALID_STATS_SET = 0x191,
		BD_EMPTY_STATS_SET_IGNORED = 0x193,
		BD_NO_DIRECT_ACCESS_TO_ARBITRATED_LBS = 0x194,
		BD_STATS_WRITE_PERMISSION_DENIED = 0x195,
		BD_STATS_WRITE_TYPE_DATA_TYPE_MISMATCH = 0x196,
		BD_NO_STATS_FOR_USER = 0x197,
		BD_INVALID_ACCESS_TO_UNRANKED_LB = 0x198,
		BD_INVALID_EXTERNAL_TITLE_ID = 0x199,
		BD_DIFFERENT_LEADERBOARD_SCHEMAS = 0x19A,
		BD_TOO_MANY_LEADERBOARDS_REQUESTED = 0x19B,
		BD_ENTITLEMENTS_ERROR = 0x19C,
		BD_ENTITLEMENTS_INVALID_TITLEID = 0x19D,
		BD_ENTITLEMENTS_INVALID_LEADERBOARDID = 0x19E,
		BD_ENTITLEMENTS_INVALID_GET_MODE_FOR_TITLE = 0x19F,
		BD_ENTITLEMENTS_URL_CONNECTION_ERROR = 0x1A0,
		BD_ENTITLEMENTS_CONFIG_ERROR = 0x1A1,
		BD_ENTITLEMENTS_NAMED_PARENT_ERROR = 0x1A2,
		BD_ENTITLEMENTS_NAMED_KEY_ERROR = 0x1A3,
		BD_TOO_MANY_ENTITY_IDS_REQUESTED = 0x1A4,
		BD_INVALID_TITLE_ID = 0x1F4,
		BD_MESSAGING_INVALID_MAIL_ID = 0x258,
		BD_SELF_BLOCK_NOT_ALLOWED = 0x259,
		BD_GLOBAL_MESSAGE_ACCESS_DENIED = 0x25A,
		BD_GLOBAL_MESSAGES_USER_LIMIT_EXCEEDED = 0x25B,
		BD_AUTH_NO_ERROR = 0x2BC,
		BD_AUTH_BAD_REQUEST = 0x2BD,
		BD_AUTH_SERVER_CONFIG_ERROR = 0x2BE,
		BD_AUTH_BAD_TITLE_ID = 0x2BF,
		BD_AUTH_BAD_ACCOUNT = 0x2C0,
		BD_AUTH_ILLEGAL_OPERATION = 0x2C1,
		BD_AUTH_INCORRECT_LICENSE_CODE = 0x2C2,
		BD_AUTH_CREATE_USERNAME_EXISTS = 0x2C3,
		BD_AUTH_CREATE_USERNAME_ILLEGAL = 0x2C4,
		BD_AUTH_CREATE_USERNAME_VULGAR = 0x2C5,
		BD_AUTH_CREATE_MAX_ACC_EXCEEDED = 0x2C6,
		BD_AUTH_MIGRATE_NOT_SUPPORTED = 0x2C7,
		BD_AUTH_TITLE_DISABLED = 0x2C8,
		BD_AUTH_ACCOUNT_EXPIRED = 0x2C9,
		BD_AUTH_ACCOUNT_LOCKED = 0x2CA,
		BD_AUTH_UNKNOWN_ERROR = 0x2CB,
		BD_AUTH_INCORRECT_PASSWORD = 0x2CC,
		BD_AUTH_IP_NOT_IN_ALLOWED_RANGE = 0x2CD,
		BD_AUTH_WII_TOKEN_VERIFICATION_FAILED = 0x2CE,
		BD_AUTH_WII_AUTHENTICATION_FAILED = 0x2CF,
		BD_AUTH_IP_KEY_LIMIT_REACHED = 0x2D0,
		BD_AUTH_INVALID_GSPID = 0x2D1,
		BD_AUTH_INVALID_IP_RANGE_ID = 0x2D2,
		BD_AUTH_3DS_TOKEN_VERIFICATION_FAILED = 0x2D1,
		BD_AUTH_3DS_AUTHENTICATION_FAILED = 0x2D2,
		BD_AUTH_STEAM_APP_ID_MISMATCH = 0x2D3,
		BD_AUTH_ABACCOUNTS_APP_ID_MISMATCH = 0x2D4,
		BD_AUTH_CODO_USERNAME_NOT_SET = 0x2D5,
		BD_AUTH_WIIU_TOKEN_VERIFICATION_FAILED = 0x2D6,
		BD_AUTH_WIIU_AUTHENTICATION_FAILED = 0x2D7,
		BD_AUTH_CODO_USERNAME_NOT_BASE64 = 0x2D8,
		BD_AUTH_CODO_USERNAME_NOT_UTF8 = 0x2D9,
		BD_AUTH_TENCENT_TICKET_EXPIRED = 0x2DA,
		BD_NO_PROFILE_INFO_EXISTS = 0x320,
		BD_FRIENDSHIP_NOT_REQUSTED = 0x384,
		BD_NOT_A_FRIEND = 0x385,
		BD_SELF_FRIENDSHIP_NOT_ALLOWED = 0x387,
		BD_FRIENDSHIP_EXISTS = 0x388,
		BD_PENDING_FRIENDSHIP_EXISTS = 0x389,
		BD_USERID_BANNED = 0x38A,
		BD_FRIENDS_FULL = 0x38C,
		BD_FRIENDS_NO_RICH_PRESENCE = 0x38D,
		BD_RICH_PRESENCE_TOO_LARGE = 0x38E,
		BD_NO_FILE = 0x3E8,
		BD_PERMISSION_DENIED = 0x3E9,
		BD_FILESIZE_LIMIT_EXCEEDED = 0x3EA,
		BD_FILENAME_MAX_LENGTH_EXCEEDED = 0x3EB,
		BD_CHANNEL_DOES_NOT_EXIST = 0x44D,
		BD_CHANNEL_ALREADY_SUBSCRIBED = 0x44E,
		BD_CHANNEL_NOT_SUBSCRIBED = 0x44F,
		BD_CHANNEL_FULL = 0x450,
		BD_CHANNEL_SUBSCRIPTIONS_FULL = 0x451,
		BD_CHANNEL_NO_SELF_WHISPERING = 0x452,
		BD_CHANNEL_ADMIN_REQUIRED = 0x453,
		BD_CHANNEL_TARGET_NOT_SUBSCRIBED = 0x454,
		BD_CHANNEL_REQUIRES_PASSWORD = 0x455,
		BD_CHANNEL_TARGET_IS_SELF = 0x456,
		BD_CHANNEL_PUBLIC_BAN_NOT_ALLOWED = 0x457,
		BD_CHANNEL_USER_BANNED = 0x458,
		BD_CHANNEL_PUBLIC_PASSWORD_NOT_ALLOWED = 0x459,
		BD_CHANNEL_PUBLIC_KICK_NOT_ALLOWED = 0x45A,
		BD_EVENT_DESC_TRUNCATED = 0x4B0,
		BD_CONTENT_UNLOCK_UNKNOWN_ERROR = 0x514,
		BD_UNLOCK_KEY_INVALID = 0x515,
		BD_UNLOCK_KEY_ALREADY_USED_UP = 0x516,
		BD_SHARED_UNLOCK_LIMIT_REACHED = 0x517,
		BD_DIFFERENT_HARDWARE_ID = 0x518,
		BD_INVALID_CONTENT_OWNER = 0x519,
		BD_CONTENT_UNLOCK_INVALID_USER = 0x51A,
		BD_KEY_ARCHIVE_INVALID_WRITE_TYPE = 0x5DC,
		BD_KEY_ARCHIVE_EXCEEDED_MAX_IDS_PER_REQUEST = 0x5DD,
		BD_BANDWIDTH_TEST_TRY_AGAIN = 0x712,
		BD_BANDWIDTH_TEST_STILL_IN_PROGRESS = 0x713,
		BD_BANDWIDTH_TEST_NOT_PROGRESS = 0x714,
		BD_BANDWIDTH_TEST_SOCKET_ERROR = 0x715,
		BD_INVALID_SESSION_NONCE = 0x76D,
		BD_ARBITRATION_FAILURE = 0x76F,
		BD_ARBITRATION_USER_NOT_REGISTERED = 0x771,
		BD_ARBITRATION_NOT_CONFIGURED = 0x772,
		BD_CONTENTSTREAMING_FILE_NOT_AVAILABLE = 0x7D0,
		BD_CONTENTSTREAMING_STORAGE_SPACE_EXCEEDED = 0x7D1,
		BD_CONTENTSTREAMING_NUM_FILES_EXCEEDED = 0x7D2,
		BD_CONTENTSTREAMING_UPLOAD_BANDWIDTH_EXCEEDED = 0x7D3,
		BD_CONTENTSTREAMING_FILENAME_MAX_LENGTH_EXCEEDED = 0x7D4,
		BD_CONTENTSTREAMING_MAX_THUMB_DATA_SIZE_EXCEEDED = 0x7D5,
		BD_CONTENTSTREAMING_DOWNLOAD_BANDWIDTH_EXCEEDED = 0x7D6,
		BD_CONTENTSTREAMING_NOT_ENOUGH_DOWNLOAD_BUFFER_SPACE = 0x7D7,
		BD_CONTENTSTREAMING_SERVER_NOT_CONFIGURED = 0x7D8,
		BD_CONTENTSTREAMING_INVALID_APPLE_RECEIPT = 0x7DA,
		BD_CONTENTSTREAMING_APPLE_STORE_NOT_AVAILABLE = 0x7DB,
		BD_CONTENTSTREAMING_APPLE_RECEIPT_FILENAME_MISMATCH = 0x7DC,
		BD_CONTENTSTREAMING_HTTP_ERROR = 0x7E4,
		BD_CONTENTSTREAMING_FAILED_TO_START_HTTP = 0x7E5,
		BD_CONTENTSTREAMING_LOCALE_INVALID = 0x7E6,
		BD_CONTENTSTREAMING_LOCALE_MISSING = 0x7E7,
		BD_VOTERANK_ERROR_EMPTY_RATING_SUBMISSION = 0x7EE,
		BD_VOTERANK_ERROR_MAX_VOTES_EXCEEDED = 0x7EF,
		BD_VOTERANK_ERROR_INVALID_RATING = 0x7F0,
		BD_MAX_NUM_TAGS_EXCEEDED = 0x82A,
		BD_TAGGED_COLLECTION_DOES_NOT_EXIST = 0x82B,
		BD_EMPTY_TAG_ARRAY = 0x82C,
		BD_INVALID_QUERY_ID = 0x834,
		BD_NO_ENTRY_TO_UPDATE = 0x835,
		BD_SESSION_INVITE_EXISTS = 0x836,
		BD_INVALID_SESSION_ID = 0x837,
		BD_ATTACHMENT_TOO_LARGE = 0x838,
		BD_INVALID_GROUP_ID = 0xAF0,
		BD_UCD_SERVICE_ERROR = 0xC80,
		BD_UCD_SERVICE_DISABLED = 0xC81,
		BD_UCD_UNINTIALIZED_ERROR = 0xC82,
		BD_UCD_ACCOUNT_ALREADY_REGISTERED = 0xC83,
		BD_UCD_ACCOUNT_NOT_REGISTERED = 0xC84,
		BD_UCD_AUTH_ATTEMPT_FAILED = 0xC85,
		BD_UCD_ACCOUNT_LINKING_ERROR = 0xC86,
		BD_UCD_ENCRYPTION_ERROR = 0xC87,
		BD_UCD_ACCOUNT_DATA_INVALID = 0xC88,
		BD_UCD_ACCOUNT_DATA_INVALID_FIRSTNAME = 0xC89,
		BD_UCD_ACCOUNT_DATA_INVALID_LASTNAME = 0xC8A,
		BD_UCD_ACCOUNT_DATA_INVALID_DOB = 0xC8B,
		BD_UCD_ACCOUNT_DATA_INVALID_EMAIL = 0xC8C,
		BD_UCD_ACCOUNT_DATA_INVALID_COUNTRY = 0xC8D,
		BD_UCD_ACCOUNT_DATA_INVALID_POSTCODE = 0xC8E,
		BD_YOUTUBE_SERVICE_ERROR = 0xCE5,
		BD_YOUTUBE_SERVICE_COMMUNICATION_ERROR = 0xCE6,
		BD_YOUTUBE_USER_DENIED_AUTHORIZATION = 0xCE7,
		BD_YOUTUBE_AUTH_MAX_TIME_EXCEEDED = 0xCE8,
		BD_YOUTUBE_USER_UNAUTHORIZED = 0xCE9,
		BD_YOUTUBE_UPLOAD_MAX_TIME_EXCEEDED = 0xCEA,
		BD_YOUTUBE_DUPLICATE_UPLOAD = 0xCEB,
		BD_YOUTUBE_FAILED_UPLOAD = 0xCEC,
		BD_YOUTUBE_ACCOUNT_ALREADY_REGISTERED = 0xCED,
		BD_YOUTUBE_ACCOUNT_NOT_REGISTERED = 0xCEE,
		BD_YOUTUBE_CONTENT_SERVER_ERROR = 0xCEF,
		BD_YOUTUBE_UPLOAD_DOES_NOT_EXIST = 0xCF0,
		BD_YOUTUBE_NO_LINKED_ACCOUNT = 0xCF1,
		BD_YOUTUBE_DEVELOPER_TAGS_INVALID = 0xCF2,
		BD_FACEBOOK_LITE_AUTH_ATTEMPT_FAILED = 0xD49,
		BD_FACEBOOK_LITE_AUTH_TOKEN_INVALID = 0xD4A,
		BD_FACEBOOK_LITE_PHOTO_DOES_NOT_EXIST = 0xD4B,
		BD_FACEBOOK_LITE_PHOTO_INVALID = 0xD4C,
		BD_FACEBOOK_LITE_PHOTO_ALBUM_FULL = 0xD4D,
		BD_FACEBOOK_LITE_UNAVAILABLE = 0xD4E,
		BD_FACEBOOK_LITE_ERROR = 0xD4F,
		BD_FACEBOOK_LITE_TIMED_OUT = 0xD50,
		BD_FACEBOOK_LITE_DISABLED_FOR_USER = 0xD51,
		BD_FACEBOOK_LITE_ACCOUNT_AMBIGUOUS = 0xD52,
		BD_FACEBOOK_LITE_MAXIMUM_ACCOUNTS_REACHED = 0xD53,
		BD_FACEBOOK_LITE_LOGIN_APPROVALS_ENABLED = 0xD54,
		BD_TWITTER_AUTH_ATTEMPT_FAILED = 0xDAD,
		BD_TWITTER_AUTH_TOKEN_INVALID = 0xDAE,
		BD_TWITTER_UPDATE_LIMIT_REACHED = 0xDAF,
		BD_TWITTER_UNAVAILABLE = 0xDB0,
		BD_TWITTER_ERROR = 0xDB1,
		BD_TWITTER_TIMED_OUT = 0xDB2,
		BD_TWITTER_DISABLED_FOR_USER = 0xDB3,
		BD_TWITTER_ACCOUNT_AMBIGUOUS = 0xDB4,
		BD_TWITTER_MAXIMUM_ACCOUNTS_REACHED = 0xDB5,
		BD_FACEBOOK_AUTH_ATTEMPT_FAILED = 0xE11,
		BD_FACEBOOK_AUTH_TOKEN_INVALID = 0xE12,
		BD_FACEBOOK_PHOTO_DOES_NOT_EXIST = 0xE13,
		BD_FACEBOOK_PHOTO_INVALID = 0xE14,
		BD_FACEBOOK_PHOTO_ALBUM_FULL = 0xE15,
		BD_FACEBOOK_UNAVAILABLE = 0xE16,
		BD_FACEBOOK_ERROR = 0xE17,
		BD_FACEBOOK_TIMED_OUT = 0xE18,
		BD_FACEBOOK_DISABLED_FOR_USER = 0xE19,
		BD_FACEBOOK_ACCOUNT_AMBIGUOUS = 0xE1A,
		BD_FACEBOOK_MAXIMUM_ACCOUNTS_REACHED = 0xE1B,
		BD_FACEBOOK_INVALID_NUM_PICTURES_REQUESTED = 0xE1C,
		BD_FACEBOOK_VIDEO_DOES_NOT_EXIST = 0xE1D,
		BD_FACEBOOK_ACCOUNT_ALREADY_REGISTERED = 0xE1E,
		BD_APNS_INVALID_PAYLOAD = 0xE74,
		BD_MAX_CONSOLEID_LENGTH_EXCEEDED = 0xEE1,
		BD_MAX_WHITELIST_LENGTH_EXCEEDED = 0xEE2,
		BD_USERGROUP_NAME_ALREADY_EXISTS = 0x1770,
		BD_INVALID_USERGROUP_ID = 0x1771,
		BD_USER_ALREADY_IN_USERGROUP = 0x1772,
		BD_USER_NOT_IN_USERGROUP = 0x1773,
		BD_INVALID_USERGROUP_MEMBER_TYPE = 0x1774,
		BD_TOO_MANY_MEMBERS_REQUESTED = 0x1775,
		BD_USERGROUP_NAME_TOO_SHORT = 0x1776,
		BD_RICH_PRESENCE_DATA_TOO_LARGE = 0x1A90,
		BD_RICH_PRESENCE_TOO_MANY_USERS = 0x1A91,
		BD_SUBSCRIPTION_TOO_MANY_USERS = 0x1B58,
		BD_SUBSCRIPTION_TICKET_PARSE_ERROR = 0x1B59,
		BD_CODO_ID_INVALID_DATA = 0x1BBC,
		BD_INVALID_MESSAGE_FORMAT = 0x1BBD,
		BD_TLOG_TOO_MANY_MESSAGES = 0x1BBE,
		BD_MARKETPLACE_ERROR = 0x1F40,
		BD_MARKETPLACE_RESOURCE_NOT_FOUND = 0x1F41,
		BD_MARKETPLACE_INVALID_PARAMETER = 0x1F43,
		BD_MARKETPLACE_RESOURCE_CONFLICT = 0x1F44,
		BD_MARKETPLACE_STORAGE_ERROR = 0x1F45,
		BD_MARKETPLACE_INTEGRITY_ERROR = 0x1F46,
		BD_MARKETPLACE_INSUFFICIENT_FUNDS_ERROR = 0x1F47,
		BD_MARKETPLACE_MMP_SERVICE_ERROR = 0x1F48,
		BD_MARKETPLACE_PRECONDITION_REQUIRED = 0x1F49,
		BD_MARKETPLACE_ITEM_MULTIPLE_PURCHASE_ERROR = 0x1F4A,
		BD_MARKETPLACE_MISSING_REQUIRED_ENTITLEMENT = 0x1F4B,
		BD_MARKETPLACE_VALIDATION_ERROR = 0x1F4C,
		BD_LEAGUE_INVALID_TEAM_SIZE = 0x1FA4,
		BD_LEAGUE_INVALID_TEAM = 0x1FA5,
		BD_LEAGUE_INVALID_SUBDIVISION = 0x1FA6,
		BD_LEAGUE_INVALID_LEAGUE = 0x1FA7,
		BD_LEAGUE_TOO_MANY_RESULTS_REQUESTED = 0x1FA8,
		BD_LEAGUE_METADATA_TOO_LARGE = 0x1FA9,
		BD_LEAGUE_TEAM_ICON_TOO_LARGE = 0x1FAA,
		BD_LEAGUE_TEAM_NAME_TOO_LONG = 0x1FAB,
		BD_LEAGUE_ARRAY_SIZE_MISMATCH = 0x1FAC,
		BD_LEAGUE_SUBDIVISION_MISMATCH = 0x2008,
		BD_LEAGUE_INVALID_WRITE_TYPE = 0x2009,
		BD_LEAGUE_INVALID_STATS_DATA = 0x200A,
		BD_LEAGUE_SUBDIVISION_UNRANKED = 0x200B,
		BD_LEAGUE_CROSS_TEAM_STATS_WRITE_PREVENTED = 0x200C,
		BD_LEAGUE_INVALID_STATS_SEASON = 0x200D,
		BD_COMMERCE_ERROR = 0x206C,
		BD_COMMERCE_RESOURCE_NOT_FOUND = 0x206D,
		BD_COMMERCE_STORAGE_INVALID_PARAMETER = 0x206E,
		BD_COMMERCE_APPLICATION_INVALID_PARAMETER = 0x206F,
		BD_COMMERCE_RESOURCE_CONFLICT = 0x2070,
		BD_COMMERCE_STORAGE_ERROR = 0x2071,
		BD_COMMERCE_INTEGRITY_ERROR = 0x2072,
		BD_COMMERCE_MMP_SERVICE_ERROR = 0x2073,
		BD_COMMERCE_PERMISSION_DENIED = 0x2074,
		BD_COMMERCE_INSUFFICIENT_FUNDS_ERROR = 0x2075,
		BD_COMMERCE_UNKNOWN_CURRENCY = 0x2076,
		BD_COMMERCE_INVALID_RECEIPT = 0x2077,
		BD_COMMERCE_RECEIPT_USED = 0x2078,
		BD_COMMERCE_TRANSACTION_ALREADY_APPLIED = 0x2079,
		BD_COMMERCE_INVALID_CURRENCY_TYPE = 0x207A,
		BD_GMSG_INVALID_CATEGORY_ID = 0x27D8,
		BD_GMSG_CATEGORY_MEMBERSHIPS_LIMIT = 0x27D9,
		BD_GMSG_NONMEMBER_POST_DISALLOWED = 0x27DA,
		BD_GMSG_CATEGORY_DISALLOWS_CLIENT_TYPE = 0x27DB,
		BD_GMSG_PAYLOAD_TOO_BIG = 0x27DC,
		BD_GMSG_MEMBER_POST_DISALLOWED = 0x27DD,
		BD_GMSG_OVERLOADED = 0x27DE,
		BD_GMSG_USER_PERCATEGORY_POST_RATE_EXCEEDED = 0x27DF,
		BD_GMSG_USER_GLOBAL_POST_RATE_EXCEEDED = 0x27E0,
		BD_GMSG_GROUP_POST_RATE_EXCEEDED = 0x27E1,
		BD_MAX_ERROR_CODE = 0x27E2,
	};

	struct DObjAnimMat
	{
		vec4_t quat;
		vec3_t trans;
		float transWeight;
	};

	struct XSurfaceVertexInfo
	{
		__int16 vertCount[4];
		unsigned __int16 *vertsBlend;
		float *tensionData;
	};

	union GfxColor
	{
		unsigned int packed;
		char array[4];
	};

	union PackedTexCoords
	{
		unsigned int packed;
		struct TexCoords
		{
			unsigned short texX;
			unsigned short texY;
		};
	};

	union PackedUnitVec
	{
		unsigned int packed;
		char array[4];
	};

	struct GfxPackedVertex
	{
		vec3_t xyz;
		float binormalSign;
		GfxColor color;
		PackedTexCoords texCoord;
		PackedUnitVec normal;
		PackedUnitVec tangent;
	};

	struct XSurfaceCollisionAabb
	{
		unsigned __int16 mins[3];
		unsigned __int16 maxs[3];
	};

	struct XSurfaceCollisionNode
	{
		XSurfaceCollisionAabb aabb;
		unsigned __int16 childBeginIndex;
		unsigned __int16 childCount;
	};

	struct XSurfaceCollisionLeaf
	{
		unsigned __int16 triangleBeginIndex;
	};

	struct XSurfaceCollisionTree
	{
		vec3_t trans;
		vec3_t scale;
		unsigned int nodeCount;
		XSurfaceCollisionNode *nodes;
		unsigned int leafCount;
		XSurfaceCollisionLeaf *leafs;
	};

	struct XRigidVertList
	{
		unsigned __int16 boneOffset;
		unsigned __int16 vertCount;
		unsigned __int16 triOffset;
		unsigned __int16 triCount;
		XSurfaceCollisionTree *collisionTree;
	};

	struct __declspec(align(16)) XSurface
	{
		char tileMode;
		char vertListCount;
		unsigned __int16 flags;
		unsigned __int16 vertCount;
		unsigned __int16 triCount;
		unsigned __int16 baseVertIndex;
		unsigned __int16 *triIndices;
		XSurfaceVertexInfo vertInfo;
		GfxPackedVertex *verts0;
		ID3D11Buffer *vb0;
		XRigidVertList *vertList;
		ID3D11Buffer *indexBuffer;
		int partBits[5];
	};

	struct GfxDrawSurfFields
	{
		__int64 _bf0;
	};

	union GfxDrawSurf
	{
		GfxDrawSurfFields fields;
		unsigned __int64 packed;
	};

	struct MaterialInfo
	{
		const char *name;
		unsigned int gameFlags;
		char pad;
		char sortKey;
		char textureAtlasRowCount;
		char textureAtlasColumnCount;
		GfxDrawSurf drawSurf;
		unsigned int surfaceTypeBits;
		unsigned int layeredSurfaceTypes;
		unsigned __int16 hashIndex;
		int surfaceFlags;
		int contents;
	};

	struct MaterialStreamRouting
	{
		char source;
		char dest;
	};

	struct MaterialVertexStreamRouting
	{
		MaterialStreamRouting data[16];
		ID3D11InputLayout *decl[20];
	};

	struct MaterialVertexDeclaration
	{
		char streamCount;
		bool hasOptionalSource;
		bool isLoaded;
		MaterialVertexStreamRouting routing;
	};

	struct GfxVertexShaderLoadDef
	{
		char *program;
		unsigned int programSize;
	};

	struct MaterialVertexShaderProgram
	{
		ID3D11VertexShader *vs;
		GfxVertexShaderLoadDef loadDef;
	};

	struct MaterialVertexShader
	{
		const char *name;
		MaterialVertexShaderProgram prog;
	};

	struct GfxPixelShaderLoadDef
	{
		char *program;
		unsigned int programSize;
	};

	struct MaterialPixelShaderProgram
	{
		ID3D11PixelShader *ps;
		GfxPixelShaderLoadDef loadDef;
	};

	struct MaterialPixelShader
	{
		const char *name;
		MaterialPixelShaderProgram prog;
	};

	union MaterialArgumentLocation
	{
		unsigned __int16 offset;
		char samplerIndex;
	};

	struct MaterialArgumentCodeConst
	{
		unsigned __int16 index;
		char firstRow;
		char rowCount;
	};

	union MaterialArgumentDef
	{
		const float *literalConst;
		MaterialArgumentCodeConst codeConst;
		unsigned int codeSampler;
		unsigned int nameHash;
	};

	struct MaterialShaderArgument
	{
		unsigned __int16 type;
		MaterialArgumentLocation location;
		unsigned __int16 size;
		unsigned __int16 buffer;
		MaterialArgumentDef u;
	};

	struct MaterialPass
	{
		MaterialVertexDeclaration *vertexDecl;
		MaterialVertexShader *vertexShader;
		MaterialPixelShader *pixelShader;
		char perPrimArgCount;
		char perObjArgCount;
		char stableArgCount;
		char customSamplerFlags;
		char precompiledIndex;
		char materialType;
		MaterialShaderArgument *args;
	};

	struct MaterialTechnique
	{
		const char *name;
		unsigned __int16 flags;
		unsigned __int16 passCount;
		MaterialPass passArray[1];
	};

	struct MaterialTechniqueSet
	{
		const char *name;
		char worldVertFormat;
		MaterialTechnique *techniques[36];
	};

	struct GfxImageLoadDef
	{
		char levelCount;
		char flags;
		int format;
		int resourceSize;
		char data[1];
	};

	union GfxTexture
	{
		ID3D11ShaderResourceView *basemap;
		GfxImageLoadDef *loadDef;
	};

	struct Picmip
	{
		char platform[2];
	};

	struct CardMemory
	{
		int platform[2];
	};

	struct GfxStreamedPartInfo
	{
		unsigned int levelCountAndSize;
		unsigned int hash;
		unsigned __int16 width;
		unsigned __int16 height;
		unsigned int offset;
		union
		{
			int size;
			int ipakIndex;
		};
		union
		{
			int adjacentLeft;
			int adjacentRight;
			int compressed;
			int valid;
		};
	};

	struct GfxImage
	{
		GfxTexture texture;
		char mapType;
		char semantic;
		char category;
		bool delayLoadPixels;
		Picmip picmip;
		bool noPicmip;
		char track;
		CardMemory cardMemory;
		unsigned __int16 width;
		unsigned __int16 height;
		unsigned __int16 depth;
		char levelCount;
		char streaming;
		unsigned int baseSize;
		char *pixels;
		GfxStreamedPartInfo streamedParts[1];
		char streamedPartCount;
		unsigned int loadedSize;
		char skippedMipLevels;
		const char *name;
		unsigned int hash;
	};

	struct MaterialTextureDef
	{
		unsigned int nameHash;
		char nameStart;
		char nameEnd;
		char samplerState;
		char semantic;
		char isMatureContent;
		char pad[3];
		GfxImage *image;
	};

	struct MaterialConstantDef
	{
		unsigned int nameHash;
		char name[12];
		vec4_t literal;
	};

	struct GfxStateBits
	{
		unsigned int loadBits[2];
		ID3D11BlendState *blendState;
		ID3D11DepthStencilState *depthStencilState;
		ID3D11RasterizerState *rasterizerState;
	};

	struct Material
	{
		MaterialInfo info;
		char stateBitsEntry[36];
		char textureCount;
		char constantCount;
		char stateBitsCount;
		char stateFlags;
		char cameraRegion;
		char probeMipBits;
		MaterialTechniqueSet *techniqueSet;
		MaterialTextureDef *textureTable;
		MaterialConstantDef *constantTable;
		GfxStateBits *stateBitsTable;
		Material *thermalMaterial;
	};

	struct XModelLodInfo
	{
		float dist;
		unsigned __int16 numsurfs;
		unsigned __int16 surfIndex;
		int partBits[5];
	};

	struct XModelCollTri_s
	{
		vec4_t plane;
		vec4_t svec;
		vec4_t tvec;
	};

	struct XModelCollSurf_s
	{
		XModelCollTri_s *collTris;
		int numCollTris;
		vec3_t mins;
		vec3_t maxs;
		int boneIdx;
		int contents;
		int surfFlags;
	};

	struct XBoneInfo
	{
		vec3_t bounds[2];
		vec3_t offset;
		float radiusSquared;
		char collmap;
	};

	struct PhysPreset
	{
		const char *name;
		int flags;
		float mass;
		float bounce;
		float friction;
		float bulletForceScale;
		float explosiveForceScale;
		const char *sndAliasPrefix;
		float piecesSpreadFraction;
		float piecesUpwardVelocity;
		int canFloat;
		float gravityScale;
		vec3_t centerOfMassOffset;
		vec3_t buoyancyBoxMin;
		vec3_t buoyancyBoxMax;
	};

	struct cplane_s
	{
		vec3_t normal;
		float dist;
		char type;
		char signbits;
		char pad[2];
	};

	struct cbrushside_t
	{
		cplane_s *plane;
		int cflags;
		int sflags;
	};

	struct BrushWrapper
	{
		vec3_t mins;
		int contents;
		vec3_t maxs;
		unsigned int numsides;
		cbrushside_t *sides;
		int axial_cflags[2][3];
		int axial_sflags[2][3];
		unsigned int numverts;
		vec3_t *verts;
		cplane_s *planes;
	};

	struct PhysGeomInfo
	{
		BrushWrapper *brush;
		int type;
		vec3_t orientation[3];
		vec3_t offset;
		vec3_t halfLengths;
	};

	struct PhysGeomList
	{
		unsigned int count;
		PhysGeomInfo *geoms;
		int contents;
	};

	struct Collmap
	{
		PhysGeomList *geomList;
	};

	enum ConstraintType
	{
		CONSTRAINT_NONE = 0x0,
		CONSTRAINT_POINT = 0x1,
		CONSTRAINT_DISTANCE = 0x2,
		CONSTRAINT_HINGE = 0x3,
		CONSTRAINT_JOINT = 0x4,
		CONSTRAINT_ACTUATOR = 0x5,
		CONSTRAINT_FAKE_SHAKE = 0x6,
		CONSTRAINT_LAUNCH = 0x7,
		CONSTRAINT_ROPE = 0x8,
		CONSTRAINT_LIGHT = 0x9,
		NUM_CONSTRAINT_TYPES = 0xA,
	};

	enum AttachPointType
	{
		ATTACH_POINT_WORLD = 0x0,
		ATTACH_POINT_DYNENT = 0x1,
		ATTACH_POINT_ENT = 0x2,
		ATTACH_POINT_BONE = 0x3,
	};

	struct PhysConstraint
	{
		unsigned __int16 targetname;
		ConstraintType type;
		AttachPointType attach_point_type1;
		int target_index1;
		unsigned __int16 target_ent1;
		const char *target_bone1;
		AttachPointType attach_point_type2;
		int target_index2;
		unsigned __int16 target_ent2;
		const char *target_bone2;
		vec3_t offset;
		vec3_t pos;
		vec3_t pos2;
		vec3_t dir;
		int flags;
		int timeout;
		int min_health;
		int max_health;
		float distance;
		float damp;
		float power;
		vec3_t scale;
		float spin_scale;
		float minAngle;
		float maxAngle;
		Material *material;
		int constraintHandle;
		int rope_index;
		int centity_num[4];
	};

	struct PhysConstraints
	{
		const char *name;
		unsigned int count;
		PhysConstraint data[16];
	};

	struct XModel
	{
		const char *name;
		char numBones;
		char numRootBones;
		char numsurfs;
		char lodRampType;
		unsigned __int16 *boneNames;
		char *parentList;
		__int16 *quats;
		float *trans;
		char *partClassification;
		DObjAnimMat *baseMat;
		XSurface *surfs;
		Material **materialHandles;
		XModelLodInfo lodInfo[4];
		XModelCollSurf_s *collSurfs;
		int numCollSurfs;
		int contents;
		XBoneInfo *boneInfo;
		float radius;
		vec3_t mins;
		vec3_t maxs;
		__int16 numLods;
		__int16 collLod;
		float *himipInvSqRadii;
		int memUsage;
		int flags;
		bool bad;
		PhysPreset *physPreset;
		char numCollmaps;
		Collmap *collmaps;
		PhysConstraints *physConstraints;
		vec3_t lightingOriginOffset;
		float lightingOriginRange;
	};

	struct XModelPiece
	{
		XModel *model;
		vec3_t offset;
	};

	struct XModelPieces
	{
		const char *name;
		int numpieces;
		XModelPiece *pieces;
	};

	struct FxSpawnDefLooping
	{
		int intervalMsec;
		int count;
	};

	struct FxIntRange
	{
		int base;
		int amplitude;
	};

	struct FxSpawnDefOneShot
	{
		FxIntRange count;
	};

	union FxSpawnDef
	{
		FxSpawnDefLooping looping;
		FxSpawnDefOneShot oneShot;
	};

	struct FxFloatRange
	{
		float base;
		float amplitude;
	};

	struct FxElemAtlas
	{
		char behavior;
		char index;
		char fps;
		char loopCount;
		char colIndexBits;
		char rowIndexBits;
		unsigned __int16 entryCountAndIndexRange;
	};

	struct FxElemVec3Range
	{
		vec3_t base;
		vec3_t amplitude;
	};

	struct FxElemVelStateInFrame
	{
		FxElemVec3Range velocity;
		FxElemVec3Range totalDelta;
	};

	const struct FxElemVelStateSample
	{
		FxElemVelStateInFrame local;
		FxElemVelStateInFrame world;
	};

	struct FxElemVisualState
	{
		char color[4];
		float rotationDelta;
		float rotationTotal;
		float size[2];
		float scale;
	};

	const struct FxElemVisStateSample
	{
		FxElemVisualState base;
		FxElemVisualState amplitude;
	};

	struct FxElemMarkVisuals
	{
		Material *materials[2];
	};

	struct FxEffectDef;

	union FxEffectDefRef
	{
		FxEffectDef *handle;
		const char *name;
	};

	struct GfxLightImage
	{
		GfxImage *image;
		char samplerState;
	};

	struct GfxLightDef
	{
		const char *name;
		GfxLightImage attenuation;
		int lmapLookupStart;
	};

	union FxElemVisuals
	{
		const void *anonymous;
		Material *material;
		XModel *model;
		FxEffectDefRef effectDef;
		const char *soundName;
		GfxLightDef *lightDef;
	};

	union FxElemDefVisuals
	{
		FxElemMarkVisuals *markArray;
		FxElemVisuals *array;
		FxElemVisuals instance;
	};

	struct FxTrailVertex
	{
		vec2_t pos;
		vec2_t normal;
		float texCoord;
	};

	struct FxTrailDef
	{
		int scrollTimeMsec;
		int repeatDist;
		int splitDist;
		int vertCount;
		FxTrailVertex *verts;
		int indCount;
		unsigned __int16 *inds;
	};

	struct FxSpotLightDef
	{
		float fovInnerFraction;
		float startRadius;
		float endRadius;
	};

	union FxElemExtendedDefPtr
	{
		FxTrailDef *localTrailDef;
		FxTrailDef *trailDef;
		FxSpotLightDef *localSpotLightDef;
		FxSpotLightDef *spotLightDef;
		void *unknownDef;
	};

	struct FxBillboardTrim
	{
		float topWidth;
		float bottomWidth;
	};

	union FxElemDefUnion
	{
		FxBillboardTrim billboard;
		FxIntRange cloudDensityRange;
	};

	struct FxElemSpawnSound
	{
		const char *spawnSound;
	};

	const struct FxElemDef
	{
		int flags;
		FxSpawnDef spawn;
		FxFloatRange spawnRange;
		FxFloatRange fadeInRange;
		FxFloatRange fadeOutRange;
		float spawnFrustumCullRadius;
		FxIntRange spawnDelayMsec;
		FxIntRange lifeSpanMsec;
		FxFloatRange spawnOrigin[3];
		FxFloatRange spawnOffsetRadius;
		FxFloatRange spawnOffsetHeight;
		FxFloatRange spawnAngles[3];
		FxFloatRange angularVelocity[3];
		FxFloatRange initialRotation;
		unsigned int rotationAxis;
		FxFloatRange gravity;
		FxFloatRange reflectionFactor;
		FxElemAtlas atlas;
		float windInfluence;
		char elemType;
		char visualCount;
		char velIntervalCount;
		char visStateIntervalCount;
		FxElemVelStateSample *velSamples;
		FxElemVisStateSample *visSamples;
		FxElemDefVisuals visuals;
		vec3_t collMins;
		vec3_t collMaxs;
		FxEffectDefRef effectOnImpact;
		FxEffectDefRef effectOnDeath;
		FxEffectDefRef effectEmitted;
		FxFloatRange emitDist;
		FxFloatRange emitDistVariance;
		FxEffectDefRef effectAttached;
		FxElemExtendedDefPtr extended;
		char sortOrder;
		char lightingFrac;
		char unused[2];
		unsigned __int16 alphaFadeTimeMsec;
		unsigned __int16 maxWindStrength;
		unsigned __int16 spawnIntervalAtMaxWind;
		unsigned __int16 lifespanAtMaxWind;
		FxElemDefUnion u;
		FxElemSpawnSound spawnSound;
		vec2_t billboardPivot;
	};

	const struct FxEffectDef
	{
		const char *name;
		unsigned __int16 flags;
		char efPriority;
		__int16 elemDefCountLooping;
		__int16 elemDefCountOneShot;
		__int16 elemDefCountEmission;
		int totalSize;
		int msecLoopingLife;
		int msecNonLoopingLife;
		FxElemDef *elemDefs;
		vec3_t boundingBoxDim;
		vec3_t boundingBoxCentre;
		float occlusionQueryDepthBias;
		int occlusionQueryFadeIn;
		int occlusionQueryFadeOut;
		FxFloatRange occlusionQueryScaleRange;
	};

	struct DestructibleStage
	{
		unsigned __int16 showBone;
		float breakHealth;
		float maxTime;
		unsigned int flags;
		FxEffectDef *breakEffect;
		const char *breakSound;
		const char *breakNotify;
		const char *loopSound;
		XModel *spawnModel[3];
		PhysPreset *physPreset;
	};

	struct DestructiblePiece
	{
		DestructibleStage stages[5];
		char parentPiece;
		float parentDamagePercent;
		float bulletDamageScale;
		float explosiveDamageScale;
		float meleeDamageScale;
		float impactDamageScale;
		float entityDamageTransfer;
		PhysConstraints *physConstraints;
		int health;
		const char *damageSound;
		FxEffectDef *burnEffect;
		const char *burnSound;
		unsigned __int16 enableLabel;
		int hideBones[5];
	};

	struct DestructibleDef
	{
		const char *name;
		XModel *model;
		XModel *pristineModel;
		int numPieces;
		DestructiblePiece *pieces;
		int clientOnly;
	};

	union XAnimIndices
	{
		char *_1;
		unsigned __int16 *_2;
		void *data;
	};

	struct XAnimNotifyInfo
	{
		unsigned __int16 name;
		float time;
	};

	union XAnimDynamicFrames
	{
		char(*_1)[3];
		unsigned __int16(*_2)[3];
	};

	union XAnimDynamicIndices
	{
		char _1[1];
		unsigned __int16 _2[1];
	};

	struct XAnimPartTransFrames
	{
		vec3_t mins;
		vec3_t size;
		XAnimDynamicFrames frames;
		XAnimDynamicIndices indices;
	};

	union XAnimPartTransData
	{
		XAnimPartTransFrames frames;
		vec3_t frame0;
	};

	struct XAnimPartTrans
	{
		unsigned __int16 size;
		char smallTrans;
		XAnimPartTransData u;
	};

	struct XAnimDeltaPartQuatDataFrames2
	{
		__int16(*frames)[2];
		XAnimDynamicIndices indices;
	};

	union XAnimDeltaPartQuatData2
	{
		XAnimDeltaPartQuatDataFrames2 frames;
		__int16 frame0[2];
	};

	struct XAnimDeltaPartQuat2
	{
		unsigned __int16 size;
		XAnimDeltaPartQuatData2 u;
	};

	struct XAnimDeltaPartQuatDataFrames
	{
		__int16(*frames)[4];
		XAnimDynamicIndices indices;
	};

	union XAnimDeltaPartQuatData
	{
		XAnimDeltaPartQuatDataFrames frames;
		__int16 frame0[4];
	};

	struct XAnimDeltaPartQuat
	{
		unsigned __int16 size;
		XAnimDeltaPartQuatData u;
	};

	struct XAnimDeltaPart
	{
		XAnimPartTrans *trans;
		XAnimDeltaPartQuat2 *quat2;
		XAnimDeltaPartQuat *quat;
	};

	struct XAnimParts
	{
		const char *name;
		unsigned __int16 dataByteCount;
		unsigned __int16 dataShortCount;
		unsigned __int16 dataIntCount;
		unsigned __int16 randomDataByteCount;
		unsigned __int16 randomDataIntCount;
		unsigned __int16 numframes;
		bool bLoop;
		bool bDelta;
		bool bDelta3D;
		bool bLeftHandGripIK;
		unsigned int streamedFileSize;
		char boneCount[10];
		char notifyCount;
		char assetType;
		bool isDefault;
		unsigned int randomDataShortCount;
		unsigned int indexCount;
		float framerate;
		float frequency;
		float primedLength;
		float loopEntryTime;
		unsigned __int16 *names;
		char *dataByte;
		__int16 *dataShort;
		int *dataInt;
		__int16 *randomDataShort;
		char *randomDataByte;
		int *randomDataInt;
		XAnimIndices indices;
		XAnimNotifyInfo *notify;
		XAnimDeltaPart *deltaPart;
	};

	struct XAnimParent
	{
		unsigned __int16 flags;
		unsigned __int16 children;
	};

	struct XAnimEntry
	{
		unsigned __int16 bCreated;
		unsigned __int16 numAnims;
		unsigned __int16 firstParamIxPlusOne;
		unsigned __int16 paramCount;
		unsigned __int16 parent;

		union
		{
			XAnimParts *parts;
			XAnimParent animParent;
		};
	};

	struct XAnimParam
	{
		char strName[16];
		float fValue;
	};

	struct XAnim_s
	{
		const char *debugName;
		unsigned int size;
		unsigned int paramSize;
		XAnimParam *params;
		const char **debugAnimNames;
		bool *wasLoggedIfMissing;
		XAnimEntry entries[1];
	};

	struct XAnimTree_s
	{
		XAnim_s *anims;
		unsigned __int16 children;
		__int16 inst;
	};

	struct SndAlias
	{
		const char *name;
		unsigned int id;
		const char *subtitle;
		const char *secondaryname;
		unsigned int assetId;
		const char *assetFileName;
		unsigned int flags0;
		unsigned int flags1;
		unsigned int duck;
		unsigned int contextType;
		unsigned int contextValue;
		unsigned int stopOnPlay;
		unsigned int futzPatch;
		unsigned __int16 fluxTime;
		unsigned __int16 startDelay;
		unsigned __int16 reverbSend;
		unsigned __int16 centerSend;
		unsigned __int16 volMin;
		unsigned __int16 volMax;
		unsigned __int16 pitchMin;
		unsigned __int16 pitchMax;
		unsigned __int16 distMin;
		unsigned __int16 distMax;
		unsigned __int16 distReverbMax;
		unsigned __int16 envelopMin;
		unsigned __int16 envelopMax;
		unsigned __int16 envelopPercentage;
		__int16 fadeIn;
		__int16 fadeOut;
		__int16 dopplerScale;
		char minPriorityThreshold;
		char maxPriorityThreshold;
		char probability;
		char occlusionLevel;
		char minPriority;
		char maxPriority;
		char pan;
		char limitCount;
		char entityLimitCount;
		char duckGroup;
	};

	struct SndAliasList
	{
		const char *name;
		unsigned int id;
		SndAlias *head;
		int count;
		int sequence;
	};

	struct SndIndexEntry
	{
		unsigned __int16 value;
		unsigned __int16 next;
	};

	struct SndRadverb
	{
		char name[32];
		unsigned int id;
		float smoothing;
		float earlyTime;
		float lateTime;
		float earlyGain;
		float lateGain;
		float returnGain;
		float earlyLpf;
		float lateLpf;
		float inputLpf;
		float dampLpf;
		float wallReflect;
		float dryGain;
		float earlySize;
		float lateSize;
		float diffusion;
		float returnHighpass;
	};

	struct SndDuck
	{
		char name[32];
		unsigned int id;
		float fadeIn;
		float fadeOut;
		float startDelay;
		float distance;
		float length;
		unsigned int fadeInCurve;
		unsigned int fadeOutCurve;
		float *attenuation;
		float *filter;
		int updateWhilePaused;
	};

	struct SndAssetBankHeader
	{
		unsigned int magic;
		unsigned int version;
		unsigned int entrySize;
		unsigned int checksumSize;
		unsigned int dependencySize;
		unsigned int entryCount;
		unsigned int dependencyCount;
		unsigned int pad32;
		__int64 fileSize;
		__int64 entryOffset;
		__int64 checksumOffset;
		char checksumChecksum[16];
		char dependencies[512];
		char padding[1464];
	};

#pragma pack(push, 1)
	struct SndRuntimeAssetBank
	{
		const char *zone;
		const char *language;
		int fileHandle;
		SndAssetBankHeader header;
		unsigned int entryOffset;
		char linkTimeChecksum[16];
		char filename[256];
		bool indicesLoaded;
		bool indicesAllocated;
	};
#pragma pack(pop)

	struct SndAssetBankEntry
	{
		unsigned int id;
		unsigned int size;
		unsigned int offset;
		unsigned int frameCount;
		char frameRateIndex;
		char channelCount;
		char looping;
		char format;
	};

	struct SndLoadedAssets
	{
		const char *zone;
		const char *language;
		unsigned int loadedCount;
		unsigned int entryCount;
		SndAssetBankEntry *entries;
		unsigned int dataSize;
		char *data;
	};

	struct SndDialogScriptIdLookup
	{
		unsigned int scriptId;
		unsigned int aliasId;
	};

	enum SndBankState
	{
		SND_BANK_STATE_NEW = 0x0,
		SND_BANK_STATE_STREAM_HEADER = 0x1,
		SND_BANK_STATE_STREAM_TOC = 0x2,
		SND_BANK_STATE_LOADED_HEADER = 0x3,
		SND_BANK_STATE_LOADED_TOC = 0x4,
		SND_BANK_STATE_LOADED_ASSET_WAIT = 0x5,
		SND_BANK_STATE_LOADED_ASSETS = 0x6,
		SND_BANK_STATE_READY_TO_USE = 0x7,
		SND_BANK_STATE_ERROR = 0x8,
	};

	struct SndBank
	{
		const char *name;
		unsigned int aliasCount;
		SndAliasList *alias;
		SndIndexEntry *aliasIndex;
		unsigned int radverbCount;
		SndRadverb *radverbs;
		unsigned int duckCount;
		SndDuck *ducks;
		SndRuntimeAssetBank streamAssetBank;
		SndRuntimeAssetBank loadAssetBank;
		SndLoadedAssets loadedAssets;
		unsigned int scriptIdLookupCount;
		SndDialogScriptIdLookup *scriptIdLookups;
		SndBankState state;
		int streamRequestId;
		bool pendingIo;
		bool ioError;
		bool runtimeAssetLoad;
	};

	struct SndPatch
	{
		char *name;
		unsigned int elementCount;
		unsigned int *elements;
	};

	struct ClipMaterial
	{
		const char *name;
		int surfaceFlags;
		int contentFlags;
	};

	struct cLeafBrushNodeLeaf_t
	{
		unsigned __int16 *brushes;
	};

	struct cLeafBrushNodeChildren_t
	{
		float dist;
		float range;
		unsigned __int16 childOffset[2];
	};

	union cLeafBrushNodeData_t
	{
		cLeafBrushNodeLeaf_t leaf;
		cLeafBrushNodeChildren_t children;
	};

	struct cLeafBrushNode_s
	{
		char axis;
		__int16 leafBrushCount;
		int contents;
		cLeafBrushNodeData_t data;
	};

	struct __declspec(align(8)) cbrush_t
	{
		vec3_t mins;
		int contents;
		vec3_t maxs;
		unsigned int numsides;
		cbrushside_t *sides;
		int axial_cflags[2][3];
		int axial_sflags[2][3];
		unsigned int numverts;
		vec3_t *verts;
	};

	struct Bounds
	{
		vec3_t midPoint;
		vec3_t halfSize;
	};

	struct ClipInfo
	{
		int planeCount;
		cplane_s *planes;
		unsigned int numMaterials;
		ClipMaterial *materials;
		unsigned int numBrushSides;
		cbrushside_t *brushsides;
		unsigned int leafbrushNodesCount;
		cLeafBrushNode_s *leafbrushNodes;
		unsigned int numLeafBrushes;
		unsigned __int16 *leafbrushes;
		unsigned int numBrushVerts;
		vec3_t *brushVerts;
		unsigned int nuinds;
		unsigned __int16 *uinds;
		unsigned __int16 numBrushes;
		cbrush_t *brushes;
		Bounds *brushBounds;
		int *brushContents;
	};

	struct cStaticModelWritable
	{
		unsigned __int16 nextModelInWorldSector;
	};

	struct cStaticModel_s
	{
		cStaticModelWritable writable;
		XModel *xmodel;
		int contents;
		vec3_t origin;
		vec3_t invScaledAxis[3];
		vec3_t absmin;
		vec3_t absmax;
	};

	struct cNode_t
	{
		cplane_s *plane;
		__int16 children[2];
	};

	struct cLeaf_s
	{
		unsigned __int16 firstCollAabbIndex;
		unsigned __int16 collAabbCount;
		int brushContents;
		int terrainContents;
		vec3_t mins;
		vec3_t maxs;
		int leafBrushNode;
		__int16 cluster;
	};

	const struct CollisionPartition
	{
		char triCount;
		int firstTri;
		int nuinds;
		int fuind;
	};

	union CollisionAabbTreeIndex
	{
		int firstChildIndex;
		int partitionIndex;
	};

	struct CollisionAabbTree
	{
		vec3_t origin;
		unsigned __int16 materialIndex;
		unsigned __int16 childCount;
		vec3_t halfSize;
		CollisionAabbTreeIndex u;
	};

	struct cmodel_t
	{
		vec3_t mins;
		vec3_t maxs;
		float radius;
		ClipInfo *info;
		cLeaf_s leaf;
	};

	struct TriggerModel
	{
		int contents;
		unsigned __int16 hullCount;
		unsigned __int16 firstHull;
	};

	struct TriggerHull
	{
		Bounds bounds;
		int contents;
		unsigned __int16 slabCount;
		unsigned __int16 firstSlab;
	};

	struct TriggerSlab
	{
		vec3_t dir;
		float midPoint;
		float halfSize;
	};

	struct MapTriggers
	{
		unsigned int count;
		TriggerModel *models;
		unsigned int hullCount;
		TriggerHull *hulls;
		unsigned int slabCount;
		TriggerSlab *slabs;
	};

	struct MapEnts
	{
		const char *name;
		char *entityString;
		int numEntityChars;
		MapTriggers trigger;
	};

	enum DynEntityType
	{
		DYNENT_TYPE_INVALID = 0x0,
		DYNENT_TYPE_CLUTTER = 0x1,
		DYNENT_TYPE_DESTRUCT = 0x2,
		DYNENT_TYPE_COUNT = 0x3,
	};

	struct GfxPlacement
	{
		vec4_t quat;
		vec3_t origin;
	};

	struct DynEntityDef
	{
		DynEntityType type;
		GfxPlacement pose;
		XModel *xModel;
		XModel *destroyedxModel;
		unsigned __int16 brushModel;
		unsigned __int16 physicsBrushModel;
		FxEffectDef *destroyFx;
		unsigned int destroySound;
		XModelPieces *destroyPieces;
		PhysPreset *physPreset;
		__int16 physConstraints[4];
		int health;
		int flags;
		int contents;
		unsigned __int16 targetname;
		unsigned __int16 target;
	};

	struct DynEntityPose
	{
		GfxPlacement pose;
		float radius;
	};

	struct DynEntityClient
	{
		int physObjId;
		unsigned __int16 flags;
		unsigned __int16 lightingHandle;
		int health;
		unsigned __int16 burnTime;
		unsigned __int16 fadeTime;
		int physicsStartTime;
	};

	struct DynEntityServer
	{
		unsigned __int16 flags;
		int health;
	};

	struct DynEntityColl
	{
		unsigned __int16 sector;
		unsigned __int16 nextEntInSector;
		vec3_t linkMins;
		vec3_t linkMaxs;
		int contents;
	};

	struct par_t
	{
		vec3_t p;
		vec3_t p0;
		vec3_t p_prev;
		int flags;
	};

	enum rope_constraint_e
	{
		ROPE_PAIR_CONSTRAINT = 0x0,
		ROPE_WORLD_CONSTRAINT = 0x1,
		ROPE_DENTITY_CONSTRAINT = 0x2,
		ROPE_CENTITY_CONSTRAINT = 0x3,
	};

	struct constraint_t
	{
		vec3_t p;
		rope_constraint_e type;
		int entity_index;
		int bone_name_hash;
		char pi1;
		char pi2;
	};

	struct rope_frame_verts_t
	{
		int num_verts;
		vec3_t v[50];
	};

	struct rope_client_verts_t
	{
		rope_frame_verts_t frame_verts[2];
		unsigned int frame_index;
	};

	struct rope_t
	{
		par_t m_particles[25];
		constraint_t m_constraints[30];
		int m_entity_anchors[3];
		int m_num_particles;
		int m_num_constraints;
		int m_num_entity_anchors;
		int m_num_draw_verts;
		rope_client_verts_t m_client_verts;
		vec3_t m_min;
		vec3_t m_max;
		vec3_t m_start;
		vec3_t m_end;
		int m_in_use;
		int m_visible;
		int m_dist_constraint;
		int m_flags;
		Material *m_material;
		float m_seglen;
		float m_length;
		float m_width;
		float m_scale;
		float m_force_scale;
		int m_health;
		int m_frame;
		int m_stable_count;
		int m_static_rope;
		unsigned __int16 m_lightingHandle;
	};

	struct clipMap_t
	{
		const char *name;
		int isInUse;
		ClipInfo info;
		ClipInfo *pInfo;
		unsigned int numStaticModels;
		cStaticModel_s *staticModelList;
		unsigned int numNodes;
		cNode_t *nodes;
		unsigned int numLeafs;
		cLeaf_s *leafs;
		unsigned int vertCount;
		vec3_t *verts;
		int triCount;
		unsigned __int16 *triIndices;
		char *triEdgeIsWalkable;
		int partitionCount;
		CollisionPartition *partitions;
		int aabbTreeCount;
		CollisionAabbTree *aabbTrees;
		unsigned int numSubModels;
		cmodel_t *cmodels;
		int numClusters;
		int clusterBytes;
		char *visibility;
		int vised;
		MapEnts *mapEnts;
		cbrush_t *box_brush;
		cmodel_t box_model;
		unsigned __int16 originalDynEntCount;
		unsigned __int16 dynEntCount[4];
		DynEntityDef *dynEntDefList[2];
		DynEntityPose *dynEntPoseList[2];
		DynEntityClient *dynEntClientList[2];
		DynEntityServer *dynEntServerList[2];
		DynEntityColl *dynEntCollList[4];
		int num_constraints;
		PhysConstraint *constraints;
		int max_ropes;
		rope_t *ropes;
		unsigned int checksum;
	};

	struct ComPrimaryLight
	{
		char type;
		char canUseShadowMap;
		char exponent;
		char priority;
		__int16 cullDist;
		char useCookie;
		char shadowmapVolume;
		vec3_t color;
		vec3_t dir;
		vec3_t origin;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		float cosHalfFovExpanded;
		float rotationLimit;
		float translationLimit;
		float mipDistance;
		float dAttenuation;
		float roundness;
		vec4_t diffuseColor;
		vec4_t falloff;
		vec4_t angle;
		vec4_t aAbB;
		vec4_t cookieControl0;
		vec4_t cookieControl1;
		vec4_t cookieControl2;
		const char *defName;
	};

	struct ComWorld
	{
		const char *name;
		int isInUse;
		unsigned int primaryLightCount;
		ComPrimaryLight *primaryLights;
	};

	struct cmd_function_s
	{
		cmd_function_s *next;
		const char *name;
		const char *autoCompleteDir;
		const char *autoCompleteExt;
		void(__cdecl *function)();
	};

	enum nodeType
	{
		NODE_BADNODE = 0x0,
		NODE_PATHNODE = 0x1,
		NODE_COVER_STAND = 0x2,
		NODE_COVER_CROUCH = 0x3,
		NODE_COVER_CROUCH_WINDOW = 0x4,
		NODE_COVER_PRONE = 0x5,
		NODE_COVER_RIGHT = 0x6,
		NODE_COVER_LEFT = 0x7,
		NODE_COVER_PILLAR = 0x8,
		NODE_AMBUSH = 0x9,
		NODE_EXPOSED = 0xA,
		NODE_CONCEALMENT_STAND = 0xB,
		NODE_CONCEALMENT_CROUCH = 0xC,
		NODE_CONCEALMENT_PRONE = 0xD,
		NODE_REACQUIRE = 0xE,
		NODE_BALCONY = 0xF,
		NODE_SCRIPTED = 0x10,
		NODE_NEGOTIATION_BEGIN = 0x11,
		NODE_NEGOTIATION_END = 0x12,
		NODE_TURRET = 0x13,
		NODE_GUARD = 0x14,
		NODE_NUMTYPES = 0x15,
		NODE_DONTLINK = 0x15,
	};

	struct pathlink_s
	{
		float fDist;
		unsigned __int16 nodeNum;
		char disconnectCount;
		char negotiationLink;
		char flags;
		char ubBadPlaceCount[5];
	};

	struct pathnode_constant_t
	{
		nodeType type;
		int spawnflags;
		unsigned __int16 targetname;
		unsigned __int16 script_linkName;
		unsigned __int16 script_noteworthy;
		unsigned __int16 target;
		unsigned __int16 animscript;
		int animscriptfunc;
		vec3_t vOrigin;
		float fAngle;
		vec2_t forward;
		float fRadius;
		float minUseDistSq;
		__int16 wOverlapNode[2];
		unsigned __int16 totalLinkCount;
		pathlink_s *Links;
	};

	struct SentientHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	struct pathnode_dynamic_t
	{
		SentientHandle pOwner;
		int iFreeTime;
		int iValidTime[3];
		int dangerousNodeTime[3];
		int inPlayerLOSTime;
		__int16 wLinkCount;
		__int16 wOverlapCount;
		__int16 turretEntNumber;
		__int16 userCount;
		bool hasBadPlaceLink;
	};

	struct pathnode_t;

	struct pathnode_transient_t
	{
		int iSearchFrame;
		pathnode_t *pNextOpen;
		pathnode_t *pPrevOpen;
		pathnode_t *pParent;
		float fCost;
		float fHeuristic;
		union
		{
			float nodeCost;
			int linkIndex;
		};
	};

	struct pathnode_t
	{
		pathnode_constant_t constant;
		pathnode_dynamic_t dynamic;
		pathnode_transient_t transient;
	};

	struct pathbasenode_t
	{
		vec3_t vOrigin;
		unsigned int type;
	};

	struct pathnode_tree_nodes_t
	{
		int nodeCount;
		unsigned __int16 *nodes;
	};

	struct pathnode_tree_t;

	union pathnode_tree_info_t
	{
		pathnode_tree_t *child[2];
		pathnode_tree_nodes_t s;
	};

	struct pathnode_tree_t
	{
		int axis;
		float dist;
		pathnode_tree_info_t u;
	};

	typedef pathnode_tree_t *pathnode_tree_ptr;

	struct PathData
	{
		unsigned int nodeCount;
		unsigned int originalNodeCount;
		pathnode_t *nodes;
		pathbasenode_t *basenodes;
		int visBytes;
		char *pathVis;
		int smoothBytes;
		char *smoothCache;
		int nodeTreeCount;
		pathnode_tree_t *nodeTree;
	};

	struct GameWorldSp
	{
		const char *name;
		PathData path;
	};

	struct GameWorldMp
	{
		const char *name;
		PathData path;
	};

	struct GfxStreamingAabbTree
	{
		vec4_t mins;
		vec4_t maxs;
		float maxStreamingDistance;
		unsigned __int16 firstItem;
		unsigned __int16 itemCount;
		unsigned __int16 firstChild;
		unsigned __int16 childCount;
		unsigned __int16 smodelCount;
		unsigned __int16 surfaceCount;
	};

	struct GfxWorldStreamInfo
	{
		int aabbTreeCount;
		GfxStreamingAabbTree *aabbTrees;
		int leafRefCount;
		int *leafRefs;
	};

	struct GfxWorldSun
	{
		unsigned int control;
		vec3_t angles;
		vec4_t ambientColor;
		vec4_t sunCd;
		vec4_t sunCs;
		vec4_t skyColor;
		float exposure;
	};

	struct GfxWorldFog
	{
		float baseDist;
		float halfDist;
		float baseHeight;
		float halfHeight;
		float sunFogPitch;
		float sunFogYaw;
		float sunFogInner;
		float sunFogOuter;
		vec3_t fogColor;
		float fogOpacity;
		vec3_t sunFogColor;
		float sunFogOpacity;
	};

	struct SunLightParseParams
	{
		char name[64];
		GfxWorldSun initWorldSun[1];
		float fogTransitionTime;
		GfxWorldFog initWorldFog[1];
	};

	struct __declspec(align(16)) GfxLight
	{
		char type;
		char canUseShadowMap;
		char shadowmapVolume;
		__int16 cullDist;
		vec3_t color;
		vec3_t dir;
		vec3_t origin;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		int exponent;
		unsigned int spotShadowIndex;
		float dAttenuation;
		float roundness;
		vec3_t angles;
		float spotShadowHiDistance;
		vec4_t diffuseColor;
		vec4_t shadowColor;
		vec4_t falloff;
		vec4_t aAbB;
		vec4_t cookieControl0;
		vec4_t cookieControl1;
		vec4_t cookieControl2;
		__declspec(align(16)) float44 viewMatrix;
		float44 projMatrix;
		GfxLightDef *def;
	};

	struct GfxLightCorona
	{
		vec3_t origin;
		float radius;
		vec3_t color;
		float intensity;
	};

	struct GfxShadowMapVolume
	{
		unsigned int control;
		unsigned int padding1;
		unsigned int padding2;
		unsigned int padding3;
	};

	struct GfxVolumePlane
	{
		vec4_t plane;
	};

	struct GfxExposureVolume
	{
		unsigned int control;
		float exposure;
		float luminanceIncreaseScale;
		float luminanceDecreaseScale;
		float featherRange;
		float featherAdjust;
	};

	struct GfxWorldFogVolume
	{
		vec3_t mins;
		unsigned int control;
		vec3_t maxs;
		float fogTransitionTime;
		unsigned int controlEx;
		GfxWorldFog volumeWorldFog[1];
	};

	struct GfxWorldFogModifierVolume
	{
		unsigned int control;
		unsigned __int16 minX;
		unsigned __int16 minY;
		unsigned __int16 minZ;
		unsigned __int16 maxX;
		unsigned __int16 maxY;
		unsigned __int16 maxZ;
		unsigned int controlEx;
		float transitionTime;
		float depthScale;
		float heightScale;
		vec4_t colorAdjust;
	};

	struct GfxLutVolume
	{
		vec3_t mins;
		unsigned int control;
		vec3_t maxs;
		float lutTransitionTime;
		unsigned int lutIndex;
	};

	struct GfxSkyDynamicIntensity
	{
		float angle0;
		float angle1;
		float factor0;
		float factor1;
	};

	struct GfxWorldDpvsPlanes
	{
		int cellCount;
		cplane_s *planes;
		unsigned __int16 *nodes;
		unsigned int *sceneEntCellBits;
	};

	struct GfxAabbTree
	{
		vec3_t mins;
		vec3_t maxs;
		unsigned __int16 childCount;
		unsigned __int16 surfaceCount;
		unsigned __int16 startSurfIndex;
		unsigned __int16 smodelIndexCount;
		unsigned __int16 *smodelIndexes;
		int childrenOffset;
	};

	struct GfxPortal;

	struct GfxPortalWritable
	{
		bool isQueued;
		bool isAncestor;
		char recursionDepth;
		char hullPointCount;
		vec2_t *hullPoints;
		GfxPortal *queuedParent;
	};

	struct DpvsPlane
	{
		vec4_t coeffs;
		char side[3];
		char pad;
	};

	struct GfxCell;

	struct GfxPortal
	{
		GfxPortalWritable writable;
		DpvsPlane plane;
		GfxCell *cell;
		vec3_t *vertices;
		char vertexCount;
		vec3_t hullAxis[2];
		vec3_t bounds[2];
	};

	struct GfxCell
	{
		vec3_t mins;
		vec3_t maxs;
		int aabbTreeCount;
		GfxAabbTree *aabbTree;
		int portalCount;
		GfxPortal *portals;
		char reflectionProbeCount;
		char *reflectionProbes;
	};

	struct GfxLightingSH
	{
		vec4_t V0;
		vec4_t V1;
		vec4_t V2;
	};

	struct GfxReflectionProbeVolumeData
	{
		vec4_t volumePlanes[6];
	};

	struct GfxReflectionProbe
	{
		vec3_t origin;
		GfxLightingSH lightingSH;
		GfxImage *reflectionImage;
		GfxReflectionProbeVolumeData *probeVolumes;
		unsigned int probeVolumeCount;
		float mipLodBias;
	};

	struct GfxLightmapArray
	{
		GfxImage *primary;
		GfxImage *secondary;
	};

	struct GfxWorldVertexData0
	{
		char *data;
		ID3D11Buffer *vb;
	};

	struct GfxWorldVertexData1
	{
		char *data;
		ID3D11Buffer *vb;
	};

	struct GfxWorldDraw
	{
		unsigned int reflectionProbeCount;
		GfxReflectionProbe *reflectionProbes;
		GfxTexture *reflectionProbeTextures;
		int lightmapCount;
		GfxLightmapArray *lightmaps;
		GfxTexture *lightmapPrimaryTextures;
		GfxTexture *lightmapSecondaryTextures;
		unsigned int vertexCount;
		unsigned int vertexDataSize0;
		GfxWorldVertexData0 vd0;
		unsigned int vertexDataSize1;
		GfxWorldVertexData1 vd1;
		int indexCount;
		unsigned __int16 *indices;
		ID3D11Buffer *indexBuffer;
	};

	struct GfxLightGridEntry
	{
		unsigned __int16 colorsIndex;
		char primaryLightIndex;
		char visibility;
	};

	struct GfxCompressedLightGridColors
	{
		char rgb[56][3];
	};

	struct GfxCompressedLightGridCoeffs
	{
		unsigned __int16 coeffs[9][3];
	};

	struct GfxSkyGridVolume
	{
		vec3_t mins;
		vec3_t maxs;
		vec3_t lightingOrigin;
		unsigned __int16 colorsIndex;
		char primaryLightIndex;
		char visibility;
	};

	struct GfxLightGrid
	{
		unsigned int sunPrimaryLightIndex;
		unsigned __int16 mins[3];
		unsigned __int16 maxs[3];
		float offset;
		unsigned int rowAxis;
		unsigned int colAxis;
		unsigned __int16 *rowDataStart;
		unsigned int rawRowDataSize;
		char *rawRowData;
		unsigned int entryCount;
		GfxLightGridEntry *entries;
		unsigned int colorCount;
		GfxCompressedLightGridColors *colors;
		unsigned int coeffCount;
		GfxCompressedLightGridCoeffs *coeffs;
		unsigned int skyGridVolumeCount;
		GfxSkyGridVolume *skyGridVolumes;
	};

	struct GfxBrushModelWritable
	{
		vec3_t mins;
		float padding1;
		vec3_t maxs;
		float padding2;
	};

	struct GfxBrushModel
	{
		GfxBrushModelWritable writable;
		vec3_t bounds[2];
		unsigned int surfaceCount;
		unsigned int startSurfIndex;
	};

	struct MaterialMemory
	{
		Material *material;
		int memory;
	};

	struct sunflare_t
	{
		bool hasValidData;
		Material *spriteMaterial;
		Material *flareMaterial;
		float spriteSize;
		float flareMinSize;
		float flareMinDot;
		float flareMaxSize;
		float flareMaxDot;
		float flareMaxAlpha;
		int flareFadeInTime;
		int flareFadeOutTime;
		float blindMinDot;
		float blindMaxDot;
		float blindMaxDarken;
		int blindFadeInTime;
		int blindFadeOutTime;
		float glareMinDot;
		float glareMaxDot;
		float glareMaxLighten;
		int glareFadeInTime;
		int glareFadeOutTime;
		vec3_t sunFxPosition;
	};

	struct $D5CE1A3EB2B8FD372BC3B42B9754BDC5
	{
		char state;
		char lod;
		unsigned __int16 surfId;
	};

	union XModelDrawInfo
	{
		$D5CE1A3EB2B8FD372BC3B42B9754BDC5 _s0;
		unsigned int packed;
	};

	struct GfxSceneDynModel
	{
		XModelDrawInfo info;
		unsigned __int16 dynEntId;
		char primaryLightIndex;
		char reflectionProbeIndex;
	};

	struct BModelDrawInfo
	{
		unsigned __int16 surfId;
	};

	struct GfxSceneDynBrush
	{
		BModelDrawInfo info;
		unsigned __int16 dynEntId;
	};

	union _m128
	{
		float m128_f32[4];
		unsigned __int64 m128_u64[2];
		char m128_i8[16];
		__int16 m128_i16[8];
		int m128_i32[4];
		__int64 m128_i64[2];
		char m128_u8[16];
		unsigned __int16 m128_u16[8];
		unsigned int m128_u32[4];
	};

	struct vector3
	{
		_m128 x;
		_m128 y;
		_m128 z;
	};

	struct vector4
	{
		vector3 baseclass_0;
		_m128 w;
	};

	union $AE792E9EE4F902DF462622579837C52B
	{
		vector4 mat;
		float disk_mat[16];
	};

	struct SSkinShaders
	{
		char *pixelShaderAlign;
		char *pixelShader;
		char *vertexShader;
		int pixelShaderSize;
		int vertexShaderSize;
	};

	struct half
	{
		unsigned __int16 v;
	};

	struct $EE6D73BC9350C8DA9C34B6E333CC6326
	{
		half x;
		half y;
		half z;
		half w;
	};

	union $2A25B0377388A949989EDF0EF7E0081A
	{
		$EE6D73BC9350C8DA9C34B6E333CC6326 _s0;
		unsigned __int64 v;
	};

	struct half4
	{
		$2A25B0377388A949989EDF0EF7E0081A ___u0;
	};

	struct $E448320BCEA46AD67EC23F7C01651314
	{
		half x;
		half y;
	};

	union $0C92BD51F6FA95F95AEACD505AFB5208
	{
		$E448320BCEA46AD67EC23F7C01651314 _s0;
		unsigned int v;
	};

	struct half2
	{
		$0C92BD51F6FA95F95AEACD505AFB5208 ___u0;
	};

	struct SSkinVert
	{
		half4 pos_bone;
		PackedUnitVec normal;
		half2 uv;
	};

	struct SSkinModel
	{
		int numVerts;
		int numTris;
		SSkinVert *verts;
		unsigned __int16 *tris;
	};

	struct SSkinAnim
	{
		int bones;
		int width;
		int frames;
		float *data;
	};

	struct SSkinInstance
	{
		$AE792E9EE4F902DF462622579837C52B ___u0;
		SSkinShaders *shaders;
		SSkinModel *model;
		SSkinAnim *anim;
		SSkinVert *instVerts;
		float frame;
		int pad1;
		int pad2;
		int pad3;
	};

	struct GfxShadowGeometry
	{
		unsigned __int16 surfaceCount;
		unsigned __int16 smodelCount;
		unsigned __int16 *sortedSurfIndex;
		unsigned __int16 *smodelIndex;
	};

	struct GfxLightRegionAxis
	{
		vec3_t dir;
		float midPoint;
		float halfSize;
	};

	struct GfxLightRegionHull
	{
		float kdopMidPoint[9];
		float kdopHalfSize[9];
		unsigned int axisCount;
		GfxLightRegionAxis *axis;
	};

	struct GfxLightRegion
	{
		unsigned int hullCount;
		GfxLightRegionHull *hulls;
	};

	struct GfxStaticModelInst
	{
		vec3_t mins;
		vec3_t maxs;
		vec3_t lightingOrigin;
	};

	struct srfTriangles_t
	{
		vec3_t mins;
		int vertexDataOffset0;
		vec3_t maxs;
		int vertexDataOffset1;
		int firstVertex;
		float himipRadiusInvSq;
		unsigned __int16 vertexCount;
		unsigned __int16 triCount;
		int baseIndex;
	};

	struct GfxSurface
	{
		srfTriangles_t tris;
		Material *material;
		char lightmapIndex;
		char reflectionProbeIndex;
		char primaryLightIndex;
		char flags;
		vec3_t bounds[2];
	};

	struct GfxPackedPlacement
	{
		vec3_t origin;
		vec3_t axis[3];
		float scale;
	};

	struct GfxLightingSHQuantized
	{
		unsigned __int16 V0[4];
		unsigned __int16 V1[4];
		unsigned __int16 V2[4];
	};

	struct GfxStaticModelLmapVertexInfo
	{
		unsigned int *lmapVertexColors;
		ID3D11Buffer *lmapVertexColorsVB;
		unsigned __int16 numLmapVertexColors;
	};

	struct GfxStaticModelDrawInst
	{
		float cullDist;
		GfxPackedPlacement placement;
		XModel *model;
		int flags;
		float invScaleSq;
		unsigned __int16 lightingHandle;
		unsigned __int16 colorsIndex;
		GfxLightingSHQuantized lightingSH;
		char primaryLightIndex;
		char visibility;
		char reflectionProbeIndex;
		unsigned int smid;
		GfxStaticModelLmapVertexInfo lmapVertexInfo[4];
	};

	struct GfxWorldDpvsStatic
	{
		unsigned int smodelCount;
		unsigned int staticSurfaceCount;
		unsigned int litSurfsBegin;
		unsigned int litSurfsEnd;
		unsigned int litTransSurfsBegin;
		unsigned int litTransSurfsEnd;
		unsigned int emissiveOpaqueSurfsBegin;
		unsigned int emissiveOpaqueSurfsEnd;
		unsigned int emissiveTransSurfsBegin;
		unsigned int emissiveTransSurfsEnd;
		unsigned int smodelVisDataCount;
		unsigned int surfaceVisDataCount;
		char *smodelVisData[3];
		char *surfaceVisData[3];
		char *smodelVisDataCameraSaved;
		char *surfaceVisDataCameraSaved;
		unsigned __int16 *sortedSurfIndex;
		GfxStaticModelInst *smodelInsts;
		GfxSurface *surfaces;
		GfxStaticModelDrawInst *smodelDrawInsts;
		GfxDrawSurf *surfaceMaterials;
		char *surfaceCastsSunShadow;
		char *surfaceCastsShadow;
		char *smodelCastsShadow;
		volatile int usageCount;
	};

	struct GfxWorldDpvsDynamic
	{
		unsigned int dynEntClientWordCount[2];
		unsigned int dynEntClientCount[2];
		unsigned int *dynEntCellBits[2];
		char *dynEntVisData[2][3];
		volatile int usageCount;
	};

	struct GfxWaterBuffer
	{
		unsigned int bufferSize;
		vec4_t *buffer;
	};

	struct Occluder
	{
		unsigned int flags;
		char name[16];
		vec3_t points[4];
	};

	struct GfxOutdoorBounds
	{
		vec3_t bounds[2];
	};

	struct GfxHeroLight
	{
		char type;
		char unused[3];
		vec3_t color;
		vec3_t dir;
		vec3_t origin;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		int exponent;
	};

	struct GfxHeroLightTree
	{
		vec3_t mins;
		vec3_t maxs;
		int leftNode;
		int rightNode;
	};

	struct GfxWorld
	{
		const char *name;
		const char *baseName;
		int planeCount;
		int nodeCount;
		int surfaceCount;
		GfxWorldStreamInfo streamInfo;
		const char *skyBoxModel;
		SunLightParseParams sunParse;
		GfxLight *sunLight;
		unsigned int sunPrimaryLightIndex;
		unsigned int primaryLightCount;
		unsigned int coronaCount;
		GfxLightCorona *coronas;
		unsigned int shadowMapVolumeCount;
		GfxShadowMapVolume *shadowMapVolumes;
		unsigned int shadowMapVolumePlaneCount;
		GfxVolumePlane *shadowMapVolumePlanes;
		unsigned int exposureVolumeCount;
		GfxExposureVolume *exposureVolumes;
		unsigned int exposureVolumePlaneCount;
		GfxVolumePlane *exposureVolumePlanes;
		unsigned int worldFogVolumeCount;
		GfxWorldFogVolume *worldFogVolumes;
		unsigned int worldFogVolumePlaneCount;
		GfxVolumePlane *worldFogVolumePlanes;
		unsigned int worldFogModifierVolumeCount;
		GfxWorldFogModifierVolume *worldFogModifierVolumes;
		unsigned int worldFogModifierVolumePlaneCount;
		GfxVolumePlane *worldFogModifierVolumePlanes;
		unsigned int lutVolumeCount;
		GfxLutVolume *lutVolumes;
		unsigned int lutVolumePlaneCount;
		GfxVolumePlane *lutVolumePlanes;
		GfxSkyDynamicIntensity skyDynIntensity;
		GfxWorldDpvsPlanes dpvsPlanes;
		int cellBitsCount;
		GfxCell *cells;
		GfxWorldDraw draw;
		GfxLightGrid lightGrid;
		int modelCount;
		GfxBrushModel *models;
		vec3_t mins;
		vec3_t maxs;
		unsigned int checksum;
		int materialMemoryCount;
		MaterialMemory *materialMemory;
		sunflare_t sun;
		vec4_t outdoorLookupMatrix[4];
		GfxImage *outdoorImage;
		unsigned int *cellCasterBits;
		GfxSceneDynModel *sceneDynModel;
		GfxSceneDynBrush *sceneDynBrush;
		unsigned int *primaryLightEntityShadowVis;
		unsigned int *primaryLightDynEntShadowVis[2];
		unsigned int numSiegeSkinInsts;
		SSkinInstance *siegeSkinInsts;
		GfxShadowGeometry *shadowGeom;
		GfxLightRegion *lightRegion;
		GfxWorldDpvsStatic dpvs;
		GfxWorldDpvsDynamic dpvsDyn;
		float waterDirection;
		GfxWaterBuffer waterBuffers[2];
		Material *waterMaterial;
		Material *coronaMaterial;
		Material *ropeMaterial;
		Material *lutMaterial;
		unsigned int numOccluders;
		Occluder *occluders;
		unsigned int numOutdoorBounds;
		GfxOutdoorBounds *outdoorBounds;
		unsigned int heroLightCount;
		unsigned int heroLightTreeCount;
		GfxHeroLight *heroLights;
		GfxHeroLightTree *heroLightTree;
		unsigned int lightingFlags;
		int lightingQuality;
	};

	struct Glyph
	{
		unsigned __int16 letter;
		char x0;
		char y0;
		char dx;
		char pixelWidth;
		char pixelHeight;
		float s0;
		float t0;
		float s1;
		float t1;
	};

	struct KerningPairs
	{
		unsigned __int16 wFirst;
		unsigned __int16 wSecond;
		int iKernAmount;
	};

	struct Font_s
	{
		const char *fontName;
		int pixelHeight;
		int isScalingAllowed;
		int glyphCount;
		int kerningPairsCount;
		Material *material;
		Material *glowMaterial;
		Glyph *glyphs;
		KerningPairs *kerningPairs;
	};

	struct FontIconName
	{
		const char *string;
		int hash;
	};

	struct FontIconEntry
	{
		FontIconName fontIconName;
		Material *fontIconMaterialHandle;
		int fontIconSize;
		float xScale;
		float yScale;
	};

	struct FontIconAlias
	{
		int aliasHash;
		int buttonHash;
	};

	struct FontIcon
	{
		const char *name;
		int numEntries;
		int numAliasEntries;
		FontIconEntry *fontIconEntry;
		FontIconAlias *fontIconAlias;
	};

	struct rectDef_s
	{
		float x;
		float y;
		float w;
		float h;
		int horzAlign;
		int vertAlign;
	};

	struct windowDef_t
	{
		const char *name;
		rectDef_s rect;
		rectDef_s rectClient;
		const char *group;
		char style;
		char border;
		char modal;
		char frameSides;
		float frameTexSize;
		float frameSize;
		int ownerDraw;
		int ownerDrawFlags;
		float borderSize;
		int staticFlags;
		int dynamicFlags[1];
		int nextTime;
		vec4_t foreColor;
		vec4_t backColor;
		vec4_t borderColor;
		vec4_t outlineColor;
		float rotation;
		Material *background;
	};

	struct ScriptCondition
	{
		bool fireOnTrue;
		int constructID;
		int blockID;
		ScriptCondition *next;
	};

	enum expDataType
	{
		VAL_INT = 0x0,
		VAL_FLOAT = 0x1,
		VAL_STRING = 0x2,
		VAL_ADDRESS = 0x3,
		VAL_DVAR = 0x4,
	};

	enum dvarType_t
	{
		DVAR_TYPE_INVALID = 0x0,
		DVAR_TYPE_BOOL = 0x1,
		DVAR_TYPE_FLOAT = 0x2,
		DVAR_TYPE_FLOAT_2 = 0x3,
		DVAR_TYPE_FLOAT_3 = 0x4,
		DVAR_TYPE_FLOAT_4 = 0x5,
		DVAR_TYPE_INT = 0x6,
		DVAR_TYPE_ENUM = 0x7,
		DVAR_TYPE_STRING = 0x8,
		DVAR_TYPE_COLOR = 0x9,
		DVAR_TYPE_INT64 = 0xA,
		DVAR_TYPE_LINEAR_COLOR_RGB = 0xB,
		DVAR_TYPE_COLOR_XYZ = 0xC,
		DVAR_TYPE_COUNT = 0xD,
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		__int64 integer64;
		unsigned __int64 unsignedInt64;
		float value;
		vec4_t vector;
		const char *string;
		char color[4];
	};

	union DvarLimits
	{
		union
		{
			struct
			{
				int stringCount;
				const char * * strings;
			} enumeration;

			struct
			{
				int min;
				int max;
			} integer;

			struct
			{
				__int64 min;
				__int64 max;
			} integer64;

			struct
			{
				float min;
				float max;
			} value;

			struct
			{
				float min;
				float max;
			} vector;
		};
	};

	struct dvar_t
	{
		const char *name;
		const char *description;
		int hash;
		unsigned int flags;
		dvarType_t type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		dvar_t *hashNext;
	};

	union operandInternalDataUnion
	{
		int intVal;
		float floatVal;
		const char *string;
		dvar_t *dvar;
	};

	struct Operand
	{
		expDataType dataType;
		operandInternalDataUnion internals;
	};

	union expressionRpnDataUnion
	{
		Operand constant;
		void *cmd;
		int cmdIdx;
	};

	struct expressionRpn
	{
		int type;
		expressionRpnDataUnion data;
	};

	struct ExpressionStatement
	{
		char *filename;
		int line;
		int numRpn;
		expressionRpn *rpn;
	};

	struct GenericEventScript
	{
		ScriptCondition *prerequisites;
		ExpressionStatement condition;
		int type;
		bool fireOnTrue;
		const char *action;
		int blockID;
		int constructID;
		GenericEventScript *next;
	};

	struct GenericEventHandler
	{
		const char *name;
		GenericEventScript *eventScript;
		GenericEventHandler *next;
	};

	struct ItemKeyHandler
	{
		int key;
		GenericEventScript *keyScript;
		ItemKeyHandler *next;
	};

	struct textExp_s
	{
		ExpressionStatement textExp;
	};

	struct columnInfo_s
	{
		int elementStyle;
		int maxChars;
		rectDef_s rect;
	};

	struct MenuCell
	{
		int type;
		int maxChars;
		char *stringValue;
	};

	struct MenuRow
	{
		MenuCell *cells;
		char *eventName;
		char *onFocusEventName;
		bool disableArg;
		int status;
		int name;
	};

	struct listBoxDef_s
	{
		int mousePos;
		int cursorPos[1];
		int startPos[1];
		int endPos[1];
		int drawPadding;
		float elementWidth;
		float elementHeight;
		int numColumns;
		float special;
		columnInfo_s columnInfo[16];
		int notselectable;
		int noScrollBars;
		int usePaging;
		vec4_t selectBorder;
		vec4_t disableColor;
		vec4_t focusColor;
		vec4_t elementHighlightColor;
		vec4_t elementBackgroundColor;
		Material *selectIcon;
		Material *backgroundItemListbox;
		Material *highlightTexture;
		int noBlinkingHighlight;
		MenuRow *rows;
		int maxRows;
		int rowCount;
	};

	struct multiDef_s
	{
		const char *dvarList[32];
		const char *dvarStr[32];
		float dvarValue[32];
		int count;
		int actionOnEnterPressOnly;
		int strDef;
	};

	struct profileMultiDef_s
	{
		const char *profileVarList[32];
		const char *profileVarStr[32];
		float profileVarValue[32];
		int count;
		int actionOnEnterPressOnly;
		int strDef;
	};

	struct editFieldDef_s
	{
		int cursorPos[1];
		float minVal;
		float maxVal;
		float defVal;
		float range;
		int maxChars;
		int maxCharsGotoNext;
		int maxPaintChars;
		int paintOffset;
	};

	struct enumDvarDef_s
	{
		const char *enumDvarName;
	};

	union focusDefData_t
	{
		listBoxDef_s *listBox;
		multiDef_s *multi;
		profileMultiDef_s *profileMulti;
		editFieldDef_s *editField;
		enumDvarDef_s *enumDvar;
		void *data;
	};

	struct focusItemDef_s
	{
		const char *mouseEnterText;
		const char *mouseExitText;
		const char *mouseEnter;
		const char *mouseExit;
		ItemKeyHandler *onKey;
		focusDefData_t focusTypeData;
	};

	struct gameMsgDef_s
	{
		int gameMsgWindowIndex;
		int gameMsgWindowMode;
	};

	union textDefData_t
	{
		focusItemDef_s *focusItemDef;
		gameMsgDef_s *gameMsgDef;
		void *data;
	};

	struct textDef_s
	{
		rectDef_s textRect[1];
		int alignment;
		int fontEnum;
		int itemFlags;
		int textAlignMode;
		float textalignx;
		float textaligny;
		float textscale;
		float textpadding;
		int textStyle;
		vec4_t fontColor;
		vec4_t glowColor;
		vec4_t shadowColor;
		float fontBlur;
		float glowSize;
		float shadowSize;
		vec2_t shadowOffset;
		const char *text;
		textExp_s *textExpData;
		textDefData_t textTypeData;
	};

	struct imageDef_s
	{
		ExpressionStatement materialExp;
	};

	struct ownerDrawDef_s
	{
		ExpressionStatement dataExp;
	};

	union itemDefData_t
	{
		textDef_s *textDef;
		imageDef_s *imageDef;
		focusItemDef_s *blankButtonDef;
		ownerDrawDef_s *ownerDrawDef;
		void *data;
	};

	struct rectData_s
	{
		ExpressionStatement rectXExp;
		ExpressionStatement rectYExp;
		ExpressionStatement rectWExp;
		ExpressionStatement rectHExp;
	};

	struct animParamsDef_t
	{
		const char *name;
		rectDef_s rectClient;
		float borderSize;
		vec4_t foreColor;
		vec4_t backColor;
		vec4_t borderColor;
		vec4_t outlineColor;
		float textScale;
		float rotation;
		GenericEventHandler *onEvent;
	};

	struct UIAnimInfo
	{
		int animStateCount;
		animParamsDef_t **animStates;
		animParamsDef_t currentAnimState;
		animParamsDef_t nextAnimState;
		int animating;
		int animStartTime;
		int animDuration;
	};

	struct menuDef_t;

	struct itemDef_s
	{
		windowDef_t window;
		int type;
		int dataType;
		int imageTrack;
		const char *dvar;
		const char *profileVar;
		const char *dvarTest;
		const char *enableDvar;
		int dvarFlags;
		itemDefData_t typeData;
		menuDef_t *parent;
		rectData_s *rectExpData;
		ExpressionStatement visibleExp;
		unsigned __int64 showBits;
		unsigned __int64 hideBits;
		ExpressionStatement forecolorAExp;
		int ui3dWindowId;
		GenericEventHandler *onEvent;
		UIAnimInfo *animInfo;
	};

	struct menuDef_t
	{
		windowDef_t window;
		const char *font;
		int fullScreen;
		int ui3dWindowId;
		int itemCount;
		int fontIndex;
		int cursorItem[1];
		int fadeCycle;
		int priority;
		float fadeClamp;
		float fadeAmount;
		float fadeInAmount;
		float blurRadius;
		int openSlideSpeed;
		int closeSlideSpeed;
		int openSlideDirection;
		int closeSlideDirection;
		rectDef_s initialRectInfo;
		int openFadingTime;
		int closeFadingTime;
		int fadeTimeCounter;
		int slideTimeCounter;
		GenericEventHandler *onEvent;
		ItemKeyHandler *onKey;
		ExpressionStatement visibleExp;
		unsigned __int64 showBits;
		unsigned __int64 hideBits;
		const char *allowedBinding;
		const char *soundName;
		int imageTrack;
		int control;
		vec4_t focusColor;
		vec4_t disableColor;
		ExpressionStatement rectXExp;
		ExpressionStatement rectYExp;
		itemDef_s **items;
	};

	struct MenuList
	{
		const char *name;
		int menuCount;
		menuDef_t **menus;
	};

	struct CStringEdPackage
	{
		int m_bEndMarkerFound_ParseOnly;
		std::string m_strCurrentEntryRef_ParseOnly;
		std::string m_strCurrentEntryEnglish_ParseOnly;
		std::string m_strCurrentFileRef_ParseOnly;
		std::map<std::string, std::string> m_StringEntries;
	};

	struct LocalizeEntry
	{
		const char *value;
		const char *name;
	};

	enum weapType_t
	{
		WEAPTYPE_BULLET = 0x0,
		WEAPTYPE_GRENADE = 0x1,
		WEAPTYPE_PROJECTILE = 0x2,
		WEAPTYPE_BINOCULARS = 0x3,
		WEAPTYPE_GAS = 0x4,
		WEAPTYPE_BOMB = 0x5,
		WEAPTYPE_MINE = 0x6,
		WEAPTYPE_MELEE = 0x7,
		WEAPTYPE_RIOTSHIELD = 0x8,
		WEAPTYPE_NUM = 0x9,
	};

	enum weapClass_t
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_MG = 0x1,
		WEAPCLASS_SMG = 0x2,
		WEAPCLASS_SPREAD = 0x3,
		WEAPCLASS_PISTOL = 0x4,
		WEAPCLASS_GRENADE = 0x5,
		WEAPCLASS_ROCKETLAUNCHER = 0x6,
		WEAPCLASS_TURRET = 0x7,
		WEAPCLASS_NON_PLAYER = 0x8,
		WEAPCLASS_GAS = 0x9,
		WEAPCLASS_ITEM = 0xA,
		WEAPCLASS_MELEE = 0xB,
		WEAPCLASS_KILLSTREAK_ALT_STORED_WEAPON = 0xC,
		WEAPCLASS_PISTOL_SPREAD = 0xD,
		WEAPCLASS_NUM = 0xE,
	};

	enum PenetrateType
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4,
	};

	enum ImpactType
	{
		IMPACT_TYPE_NONE = 0x0,
		IMPACT_TYPE_BULLET_SMALL = 0x1,
		IMPACT_TYPE_BULLET_LARGE = 0x2,
		IMPACT_TYPE_BULLET_AP = 0x3,
		IMPACT_TYPE_BULLET_XTREME = 0x4,
		IMPACT_TYPE_SHOTGUN = 0x5,
		IMPACT_TYPE_GRENADE_BOUNCE = 0x6,
		IMPACT_TYPE_GRENADE_EXPLODE = 0x7,
		IMPACT_TYPE_RIFLE_GRENADE = 0x8,
		IMPACT_TYPE_ROCKET_EXPLODE = 0x9,
		IMPACT_TYPE_ROCKET_EXPLODE_XTREME = 0xA,
		IMPACT_TYPE_PROJECTILE_DUD = 0xB,
		IMPACT_TYPE_MORTAR_SHELL = 0xC,
		IMPACT_TYPE_TANK_SHELL = 0xD,
		IMPACT_TYPE_BOLT = 0xE,
		IMPACT_TYPE_BLADE = 0xF,
		IMPACT_TYPE_COUNT = 0x10,
	};

	enum weapInventoryType_t
	{
		WEAPINVENTORY_PRIMARY = 0x0,
		WEAPINVENTORY_OFFHAND = 0x1,
		WEAPINVENTORY_ITEM = 0x2,
		WEAPINVENTORY_ALTMODE = 0x3,
		WEAPINVENTORY_MELEE = 0x4,
		WEAPINVENTORY_DWLEFTHAND = 0x5,
		WEAPINVENTORYCOUNT = 0x6,
	};

	enum weapFireType_t
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPE_BURSTFIRE5 = 0x5,
		WEAPON_FIRETYPE_STACKED = 0x6,
		WEAPON_FIRETYPE_MINIGUN = 0x7,
		WEAPON_FIRETYPE_CHARGESHOT = 0x8,
		WEAPON_FIRETYPE_JETGUN = 0x9,
		WEAPON_FIRETYPECOUNT = 0xA,
	};

	enum weapClipType_t
	{
		WEAPON_CLIPTYPE_BOTTOM = 0x0,
		WEAPON_CLIPTYPE_TOP = 0x1,
		WEAPON_CLIPTYPE_LEFT = 0x2,
		WEAPON_CLIPTYPE_DP28 = 0x3,
		WEAPON_CLIPTYPE_PTRS = 0x4,
		WEAPON_CLIPTYPE_LMG = 0x5,
		WEAPON_CLIPTYPECOUNT = 0x6,
	};

	enum barrelType_t
	{
		BARREL_TYPE_SINGLE = 0x0,
		BARREL_TYPE_DUAL = 0x1,
		BARREL_TYPE_DUAL_ALTERNATE = 0x2,
		BARREL_TYPE_QUAD = 0x3,
		BARREL_TYPE_QUAD_ALTERNATE = 0x4,
		BARREL_TYPE_QUAD_DOUBLE_ALTERNATE = 0x5,
		BARREL_TYPE_COUNT = 0x6,
	};

	enum OffhandClass
	{
		OFFHAND_CLASS_NONE = 0x0,
		OFFHAND_CLASS_FRAG_GRENADE = 0x1,
		OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
		OFFHAND_CLASS_FLASH_GRENADE = 0x3,
		OFFHAND_CLASS_GEAR = 0x4,
		OFFHAND_CLASS_SUPPLYDROP_MARKER = 0x5,
		OFFHAND_CLASS_COUNT = 0x6,
	};

	enum OffhandSlot
	{
		OFFHAND_SLOT_NONE = 0x0,
		OFFHAND_SLOT_LETHAL_GRENADE = 0x1,
		OFFHAND_SLOT_TACTICAL_GRENADE = 0x2,
		OFFHAND_SLOT_EQUIPMENT = 0x3,
		OFFHAND_SLOT_SPECIFIC_USE = 0x4,
		OFFHAND_SLOT_COUNT = 0x5,
	};

	enum weapStance_t
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3,
	};

	enum activeReticleType_t
	{
		VEH_ACTIVE_RETICLE_NONE = 0x0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
		VEH_ACTIVE_RETICLE_MISSILE_LOCK = 0x3,
		VEH_ACTIVE_RETICLE_COUNT = 0x4,
	};

	enum weaponIconRatioType_t
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3,
	};

	enum ammoCounterClipType_t
	{
		AMMO_COUNTER_CLIP_NONE = 0x0,
		AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
		AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
		AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
		AMMO_COUNTER_CLIP_ROCKET = 0x4,
		AMMO_COUNTER_CLIP_BELTFED = 0x5,
		AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
		AMMO_COUNTER_CLIP_COUNT = 0x7,
	};

	enum weapOverlayReticle_t
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2,
	};

	enum WeapOverlayInteface_t
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3,
	};

	enum weapProjExposion_t
	{
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_NONE = 0x3,
		WEAPPROJEXP_DUD = 0x4,
		WEAPPROJEXP_SMOKE = 0x5,
		WEAPPROJEXP_HEAVY = 0x6,
		WEAPPROJEXP_FIRE = 0x7,
		WEAPPROJEXP_NAPALMBLOB = 0x8,
		WEAPPROJEXP_BOLT = 0x9,
		WEAPPROJEXP_SHRAPNELSPAN = 0xA,
		WEAPPROJEXP_NUM = 0xB,
	};

	enum WeapStickinessType
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_ALL_NO_SENTIENTS = 0x2,
		WEAPSTICKINESS_GROUND = 0x3,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x4,
		WEAPSTICKINESS_FLESH = 0x5,
		WEAPSTICKINESS_COUNT = 0x6,
	};

	enum WeapRotateType
	{
		WEAPROTATE_GRENADE_ROTATE = 0x0,
		WEAPROTATE_BLADE_ROTATE = 0x1,
		WEAPROTATE_CYLINDER_ROTATE = 0x2,
		WEAPROTATE_COUNT = 0x3,
	};

	enum guidedMissileType_t
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_BALLISTIC = 0x4,
		MISSILE_GUIDANCE_WIREGUIDED = 0x5,
		MISSILE_GUIDANCE_TVGUIDED = 0x6,
		MISSILE_GUIDANCE_DRONE = 0x7,
		MISSILE_GUIDANCE_HEATSEEKING = 0x8,
		MISSILE_GUIDANCE_COUNT = 0x9,
	};

	enum tracerType_t
	{
		TRACERTYPE_LASER = 0x0,
		TRACERTYPE_SMOKE = 0x1,
		TRACERTYPE_NUM = 0x2,
	};

	struct TracerDef
	{
		const char *name;
		tracerType_t type;
		Material *material;
		unsigned int drawInterval;
		float speed;
		float beamLength;
		float beamWidth;
		float screwRadius;
		float screwDist;
		float fadeTime;
		float fadeScale;
		float texRepeatRate;
		vec4_t colors[5];
	};

	struct flameTable
	{
		float flameVar_streamChunkGravityStart;
		float flameVar_streamChunkGravityEnd;
		float flameVar_streamChunkMaxSize;
		float flameVar_streamChunkStartSize;
		float flameVar_streamChunkEndSize;
		float flameVar_streamChunkStartSizeRand;
		float flameVar_streamChunkEndSizeRand;
		float flameVar_streamChunkDistScalar;
		float flameVar_streamChunkDistSwayScale;
		float flameVar_streamChunkDistSwayVelMax;
		float flameVar_streamChunkSpeed;
		float flameVar_streamChunkDecel;
		float flameVar_streamChunkVelocityAddScale;
		float flameVar_streamChunkDuration;
		float flameVar_streamChunkDurationScaleMaxVel;
		float flameVar_streamChunkDurationVelScalar;
		float flameVar_streamChunkSizeSpeedScale;
		float flameVar_streamChunkSizeAgeScale;
		float flameVar_streamChunkSpawnFireIntervalStart;
		float flameVar_streamChunkSpawnFireIntervalEnd;
		float flameVar_streamChunkSpawnFireMinLifeFrac;
		float flameVar_streamChunkSpawnFireMaxLifeFrac;
		float flameVar_streamChunkFireMinLifeFrac;
		float flameVar_streamChunkFireMinLifeFracStart;
		float flameVar_streamChunkFireMinLifeFracEnd;
		float flameVar_streamChunkDripsMinLifeFrac;
		float flameVar_streamChunkDripsMinLifeFracStart;
		float flameVar_streamChunkDripsMinLifeFracEnd;
		float flameVar_streamChunkRotationRange;
		float flameVar_streamSizeRandSinWave;
		float flameVar_streamSizeRandCosWave;
		float flameVar_streamDripsChunkInterval;
		float flameVar_streamDripsChunkMinFrac;
		float flameVar_streamDripsChunkRandFrac;
		float flameVar_streamSmokeChunkInterval;
		float flameVar_streamSmokeChunkMinFrac;
		float flameVar_streamSmokeChunkRandFrac;
		float flameVar_streamChunkCullDistSizeFrac;
		float flameVar_streamChunkCullMinLife;
		float flameVar_streamChunkCullMaxLife;
		float flameVar_streamFuelSizeStart;
		float flameVar_streamFuelSizeEnd;
		float flameVar_streamFuelLength;
		float flameVar_streamFuelNumSegments;
		float flameVar_streamFuelAnimLoopTime;
		float flameVar_streamFlameSizeStart;
		float flameVar_streamFlameSizeEnd;
		float flameVar_streamFlameLength;
		float flameVar_streamFlameNumSegments;
		float flameVar_streamFlameAnimLoopTime;
		float flameVar_streamPrimaryLightRadius;
		float flameVar_streamPrimaryLightRadiusFlutter;
		float flameVar_streamPrimaryLightR;
		float flameVar_streamPrimaryLightG;
		float flameVar_streamPrimaryLightB;
		float flameVar_streamPrimaryLightFlutterR;
		float flameVar_streamPrimaryLightFlutterG;
		float flameVar_streamPrimaryLightFlutterB;
		float flameVar_fireLife;
		float flameVar_fireLifeRand;
		float flameVar_fireSpeedScale;
		float flameVar_fireSpeedScaleRand;
		float flameVar_fireVelocityAddZ;
		float flameVar_fireVelocityAddZRand;
		float flameVar_fireVelocityAddSideways;
		float flameVar_fireGravity;
		float flameVar_fireGravityEnd;
		float flameVar_fireMaxRotVel;
		float flameVar_fireFriction;
		float flameVar_fireEndSizeAdd;
		float flameVar_fireStartSizeScale;
		float flameVar_fireEndSizeScale;
		float flameVar_fireBrightness;
		float flameVar_dripsLife;
		float flameVar_dripsLifeRand;
		float flameVar_dripsSpeedScale;
		float flameVar_dripsSpeedScaleRand;
		float flameVar_dripsVelocityAddZ;
		float flameVar_dripsVelocityAddZRand;
		float flameVar_dripsVelocityAddSideways;
		float flameVar_dripsGravity;
		float flameVar_dripsGravityEnd;
		float flameVar_dripsMaxRotVel;
		float flameVar_dripsFriction;
		float flameVar_dripsEndSizeAdd;
		float flameVar_dripsStartSizeScale;
		float flameVar_dripsEndSizeScale;
		float flameVar_dripsBrightness;
		float flameVar_smokeLife;
		float flameVar_smokeLifeRand;
		float flameVar_smokeSpeedScale;
		float flameVar_smokeVelocityAddZ;
		float flameVar_smokeGravity;
		float flameVar_smokeGravityEnd;
		float flameVar_smokeMaxRotation;
		float flameVar_smokeMaxRotVel;
		float flameVar_smokeFriction;
		float flameVar_smokeEndSizeAdd;
		float flameVar_smokeStartSizeAdd;
		float flameVar_smokeOriginSizeOfsZScale;
		float flameVar_smokeOriginOfsZ;
		float flameVar_smokeFadein;
		float flameVar_smokeFadeout;
		float flameVar_smokeMaxAlpha;
		float flameVar_smokeBrightness;
		float flameVar_smokeOriginOffset;
		float flameVar_collisionSpeedScale;
		float flameVar_collisionVolumeScale;
		const char *name;
		Material *fire;
		Material *smoke;
		Material *heat;
		Material *drips;
		Material *streamFuel;
		Material *streamFuel2;
		Material *streamFlame;
		Material *streamFlame2;
		const char *flameOffLoopSound;
		const char *flameIgniteSound;
		const char *flameOnLoopSound;
		const char *flameCooldownSound;
	};

	struct WeaponCamoSet
	{
		GfxImage *solidCamoImage;
		GfxImage *patternCamoImage;
		vec2_t patternOffset;
		float patternScale;
	};

	struct WeaponCamoMaterial
	{
		unsigned __int16 replaceFlags;
		unsigned __int16 numBaseMaterials;
		Material **baseMaterials;
		Material **camoMaterials;
		float shaderConsts[8];
	};

	struct WeaponCamoMaterialSet
	{
		unsigned int numMaterials;
		WeaponCamoMaterial *materials;
	};

	struct WeaponCamo
	{
		const char *name;
		GfxImage *solidBaseImage;
		GfxImage *patternBaseImage;
		WeaponCamoSet *camoSets;
		unsigned int numCamoSets;
		WeaponCamoMaterialSet *camoMaterials;
		unsigned int numCamoMaterials;
	};

	struct WeaponDef
	{
		const char *szOverlayName;
		XModel **gunXModel;
		XModel *handXModel;
		const char *szModeName;
		unsigned __int16 *notetrackSoundMapKeys;
		unsigned __int16 *notetrackSoundMapValues;
		int playerAnimType;
		weapType_t weapType;
		weapClass_t weapClass;
		PenetrateType penetrateType;
		ImpactType impactType;
		weapInventoryType_t inventoryType;
		weapFireType_t fireType;
		weapClipType_t clipType;
		barrelType_t barrelType;
		int itemIndex;
		const char *parentWeaponName;
		int iJamFireTime;
		int overheatWeapon;
		float overheatRate;
		float cooldownRate;
		float overheatEndVal;
		bool coolWhileFiring;
		bool fuelTankWeapon;
		int iTankLifeTime;
		OffhandClass offhandClass;
		OffhandSlot offhandSlot;
		weapStance_t stance;
		FxEffectDef *viewFlashEffect;
		FxEffectDef *worldFlashEffect;
		FxEffectDef *barrelCooldownEffect;
		int barrelCooldownMinCount;
		vec3_t vViewFlashOffset;
		vec3_t vWorldFlashOffset;
		const char *pickupSound;
		const char *pickupSoundPlayer;
		const char *ammoPickupSound;
		const char *ammoPickupSoundPlayer;
		const char *projectileSound;
		const char *pullbackSound;
		const char *pullbackSoundPlayer;
		const char *fireSound;
		const char *fireSoundPlayer;
		const char *fireLoopSound;
		const char *fireLoopSoundPlayer;
		const char *fireLoopEndSound;
		const char *fireLoopEndSoundPlayer;
		const char *fireStartSound;
		const char *fireStopSound;
		const char *fireKillcamSound;
		const char *fireStartSoundPlayer;
		const char *fireStopSoundPlayer;
		const char *fireKillcamSoundPlayer;
		const char *fireLastSound;
		const char *fireLastSoundPlayer;
		const char *emptyFireSound;
		const char *emptyFireSoundPlayer;
		const char *crackSound;
		const char *whizbySound;
		const char *meleeSwipeSound;
		const char *meleeSwipeSoundPlayer;
		const char *meleeHitSound;
		const char *meleeMissSound;
		const char *rechamberSound;
		const char *rechamberSoundPlayer;
		const char *reloadSound;
		const char *reloadSoundPlayer;
		const char *reloadEmptySound;
		const char *reloadEmptySoundPlayer;
		const char *reloadStartSound;
		const char *reloadStartSoundPlayer;
		const char *reloadEndSound;
		const char *reloadEndSoundPlayer;
		const char *rotateLoopSound;
		const char *rotateLoopSoundPlayer;
		const char *rotateStopSound;
		const char *rotateStopSoundPlayer;
		const char *deploySound;
		const char *deploySoundPlayer;
		const char *finishDeploySound;
		const char *finishDeploySoundPlayer;
		const char *breakdownSound;
		const char *breakdownSoundPlayer;
		const char *finishBreakdownSound;
		const char *finishBreakdownSoundPlayer;
		const char *detonateSound;
		const char *detonateSoundPlayer;
		const char *nightVisionWearSound;
		const char *nightVisionWearSoundPlayer;
		const char *nightVisionRemoveSound;
		const char *nightVisionRemoveSoundPlayer;
		const char *altSwitchSound;
		const char *altSwitchSoundPlayer;
		const char *raiseSound;
		const char *raiseSoundPlayer;
		const char *firstRaiseSound;
		const char *firstRaiseSoundPlayer;
		const char *adsRaiseSoundPlayer;
		const char *adsLowerSoundPlayer;
		const char *putawaySound;
		const char *putawaySoundPlayer;
		const char *overheatSound;
		const char *overheatSoundPlayer;
		const char *adsZoomSound;
		const char *shellCasing;
		const char *shellCasingPlayer;
		const char **bounceSound;
		const char *standMountedWeapdef;
		const char *crouchMountedWeapdef;
		const char *proneMountedWeapdef;
		int standMountedIndex;
		int crouchMountedIndex;
		int proneMountedIndex;
		FxEffectDef *viewShellEjectEffect;
		FxEffectDef *worldShellEjectEffect;
		FxEffectDef *viewLastShotEjectEffect;
		FxEffectDef *worldLastShotEjectEffect;
		vec3_t vViewShellEjectOffset;
		vec3_t vWorldShellEjectOffset;
		vec3_t vViewShellEjectRotation;
		vec3_t vWorldShellEjectRotation;
		Material *reticleCenter;
		Material *reticleSide;
		int iReticleCenterSize;
		int iReticleSideSize;
		int iReticleMinOfs;
		activeReticleType_t activeReticleType;
		vec3_t vStandMove;
		vec3_t vStandRot;
		vec3_t vDuckedOfs;
		vec3_t vDuckedMove;
		vec3_t vDuckedSprintOfs;
		vec3_t vDuckedSprintRot;
		vec2_t vDuckedSprintBob;
		float fDuckedSprintCycleScale;
		vec3_t vSprintOfs;
		vec3_t vSprintRot;
		vec2_t vSprintBob;
		float fSprintCycleScale;
		vec3_t vLowReadyOfs;
		vec3_t vLowReadyRot;
		vec3_t vRideOfs;
		vec3_t vRideRot;
		vec3_t vDtpOfs;
		vec3_t vDtpRot;
		vec2_t vDtpBob;
		float fDtpCycleScale;
		vec3_t vMantleOfs;
		vec3_t vMantleRot;
		vec3_t vSlideOfs;
		vec3_t vSlideRot;
		vec3_t vDuckedRot;
		vec3_t vProneOfs;
		vec3_t vProneMove;
		vec3_t vProneRot;
		vec3_t vStrafeMove;
		vec3_t vStrafeRot;
		float fPosMoveRate;
		float fPosProneMoveRate;
		float fStandMoveMinSpeed;
		float fDuckedMoveMinSpeed;
		float fProneMoveMinSpeed;
		float fPosRotRate;
		float fPosProneRotRate;
		float fStandRotMinSpeed;
		float fDuckedRotMinSpeed;
		float fProneRotMinSpeed;
		XModel **worldModel;
		XModel *worldClipModel;
		XModel *rocketModel;
		XModel *mountedModel;
		XModel *additionalMeleeModel;
		Material *fireTypeIcon;
		Material *hudIcon;
		weaponIconRatioType_t hudIconRatio;
		Material *indicatorIcon;
		weaponIconRatioType_t indicatorIconRatio;
		Material *ammoCounterIcon;
		weaponIconRatioType_t ammoCounterIconRatio;
		ammoCounterClipType_t ammoCounterClip;
		int iStartAmmo;
		int iMaxAmmo;
		int shotCount;
		const char *szSharedAmmoCapName;
		int iSharedAmmoCapIndex;
		int iSharedAmmoCap;
		bool unlimitedAmmo;
		bool ammoCountClipRelative;
		int damage[6];
		float damageRange[6];
		int minPlayerDamage;
		float damageDuration;
		float damageInterval;
		int playerDamage;
		int iMeleeDamage;
		int iDamageType;
		unsigned __int16 explosionTag;
		int iFireDelay;
		int iMeleeDelay;
		int meleeChargeDelay;
		int iDetonateDelay;
		int iSpinUpTime;
		int iSpinDownTime;
		float spinRate;
		const char *spinLoopSound;
		const char *spinLoopSoundPlayer;
		const char *startSpinSound;
		const char *startSpinSoundPlayer;
		const char *stopSpinSound;
		const char *stopSpinSoundPlayer;
		bool applySpinPitch;
		int iFireTime;
		int iLastFireTime;
		int iRechamberTime;
		int iRechamberBoltTime;
		int iHoldFireTime;
		int iDetonateTime;
		int iMeleeTime;
		int iBurstDelayTime;
		int meleeChargeTime;
		int iReloadTimeRight;
		int iReloadTimeLeft;
		int reloadShowRocketTime;
		int iReloadEmptyTimeLeft;
		int iReloadAddTime;
		int iReloadEmptyAddTime;
		int iReloadQuickAddTime;
		int iReloadQuickEmptyAddTime;
		int iReloadStartTime;
		int iReloadStartAddTime;
		int iReloadEndTime;
		int iDropTime;
		int iRaiseTime;
		int iAltDropTime;
		int quickDropTime;
		int quickRaiseTime;
		int iFirstRaiseTime;
		int iEmptyRaiseTime;
		int iEmptyDropTime;
		int sprintInTime;
		int sprintLoopTime;
		int sprintOutTime;
		int lowReadyInTime;
		int lowReadyLoopTime;
		int lowReadyOutTime;
		int contFireInTime;
		int contFireLoopTime;
		int contFireOutTime;
		int dtpInTime;
		int dtpLoopTime;
		int dtpOutTime;
		int crawlInTime;
		int crawlForwardTime;
		int crawlBackTime;
		int crawlRightTime;
		int crawlLeftTime;
		int crawlOutFireTime;
		int crawlOutTime;
		int slideInTime;
		int deployTime;
		int breakdownTime;
		int iFlourishTime;
		int nightVisionWearTime;
		int nightVisionWearTimeFadeOutEnd;
		int nightVisionWearTimePowerUp;
		int nightVisionRemoveTime;
		int nightVisionRemoveTimePowerDown;
		int nightVisionRemoveTimeFadeInStart;
		int fuseTime;
		int aiFuseTime;
		int lockOnRadius;
		int lockOnSpeed;
		bool requireLockonToFire;
		bool noAdsWhenMagEmpty;
		bool avoidDropCleanup;
		unsigned int stackFire;
		float stackFireSpread;
		float stackFireAccuracyDecay;
		const char *stackSound;
		float autoAimRange;
		float aimAssistRange;
		bool mountableWeapon;
		float aimPadding;
		float enemyCrosshairRange;
		bool crosshairColorChange;
		float moveSpeedScale;
		float adsMoveSpeedScale;
		float sprintDurationScale;
		weapOverlayReticle_t overlayReticle;
		WeapOverlayInteface_t overlayInterface;
		float overlayWidth;
		float overlayHeight;
		float fAdsBobFactor;
		float fAdsViewBobMult;
		bool bHoldBreathToSteady;
		float fHipSpreadStandMin;
		float fHipSpreadDuckedMin;
		float fHipSpreadProneMin;
		float hipSpreadStandMax;
		float hipSpreadDuckedMax;
		float hipSpreadProneMax;
		float fHipSpreadDecayRate;
		float fHipSpreadFireAdd;
		float fHipSpreadTurnAdd;
		float fHipSpreadMoveAdd;
		float fHipSpreadDuckedDecay;
		float fHipSpreadProneDecay;
		float fHipReticleSidePos;
		float fAdsIdleAmount;
		float fHipIdleAmount;
		float adsIdleSpeed;
		float hipIdleSpeed;
		float fIdleCrouchFactor;
		float fIdleProneFactor;
		float fGunMaxPitch;
		float fGunMaxYaw;
		float swayMaxAngle;
		float swayLerpSpeed;
		float swayPitchScale;
		float swayYawScale;
		float swayHorizScale;
		float swayVertScale;
		float swayShellShockScale;
		float adsSwayMaxAngle;
		float adsSwayLerpSpeed;
		float adsSwayPitchScale;
		float adsSwayYawScale;
		bool sharedAmmo;
		bool bRifleBullet;
		bool armorPiercing;
		bool bAirburstWeapon;
		bool bBoltAction;
		bool bUseAltTagFlash;
		bool bUseAntiLagRewind;
		bool bIsCarriedKillstreakWeapon;
		bool aimDownSight;
		bool bRechamberWhileAds;
		bool bReloadWhileAds;
		float adsViewErrorMin;
		float adsViewErrorMax;
		bool bCookOffHold;
		bool bClipOnly;
		bool bCanUseInVehicle;
		bool bNoDropsOrRaises;
		bool adsFireOnly;
		bool cancelAutoHolsterWhenEmpty;
		bool suppressAmmoReserveDisplay;
		bool laserSight;
		bool laserSightDuringNightvision;
		bool bHideThirdPerson;
		bool bHasBayonet;
		bool bDualWield;
		bool bExplodeOnGround;
		bool bThrowBack;
		bool bRetrievable;
		bool bDieOnRespawn;
		bool bNoThirdPersonDropsOrRaises;
		bool bContinuousFire;
		bool bNoPing;
		bool bForceBounce;
		bool bUseDroppedModelAsStowed;
		bool bNoQuickDropWhenEmpty;
		bool bKeepCrosshairWhenADS;
		bool bUseOnlyAltWeaoponHideTagsInAltMode;
		bool bAltWeaponAdsOnly;
		bool bAltWeaponDisableSwitching;
		Material *killIcon;
		weaponIconRatioType_t killIconRatio;
		bool flipKillIcon;
		bool bNoPartialReload;
		bool bSegmentedReload;
		bool bNoADSAutoReload;
		int iReloadAmmoAdd;
		int iReloadStartAdd;
		const char *szSpawnedGrenadeWeaponName;
		const char *szDualWieldWeaponName;
		unsigned int dualWieldWeaponIndex;
		int iDropAmmoMin;
		int iDropAmmoMax;
		int iDropClipAmmoMin;
		int iDropClipAmmoMax;
		int iShotsBeforeRechamber;
		bool blocksProne;
		bool bShowIndicator;
		int isRollingGrenade;
		int useBallisticPrediction;
		int isValuable;
		int isTacticalInsertion;
		bool isReviveWeapon;
		bool bUseRigidBodyOnVehicle;
		int iExplosionRadius;
		int iExplosionRadiusMin;
		int iIndicatorRadius;
		int iExplosionInnerDamage;
		int iExplosionOuterDamage;
		float damageConeAngle;
		int iProjectileSpeed;
		int iProjectileSpeedUp;
		int iProjectileSpeedRelativeUp;
		int iProjectileSpeedForward;
		float fProjectileTakeParentVelocity;
		int iProjectileActivateDist;
		float projLifetime;
		float timeToAccelerate;
		float projectileCurvature;
		XModel *projectileModel;
		weapProjExposion_t projExplosion;
		FxEffectDef *projExplosionEffect;
		bool projExplosionEffectForceNormalUp;
		FxEffectDef *projExplosionEffect2;
		bool projExplosionEffect2ForceNormalUp;
		FxEffectDef *projExplosionEffect3;
		bool projExplosionEffect3ForceNormalUp;
		FxEffectDef *projExplosionEffect4;
		bool projExplosionEffect4ForceNormalUp;
		FxEffectDef *projExplosionEffect5;
		bool projExplosionEffect5ForceNormalUp;
		FxEffectDef *projDudEffect;
		const char *projExplosionSound;
		const char *projDudSound;
		const char *mortarShellSound;
		const char *tankShellSound;
		bool bProjImpactExplode;
		bool bProjSentientImpactExplode;
		bool bProjExplodeWhenStationary;
		bool bBulletImpactExplode;
		WeapStickinessType stickiness;
		WeapRotateType rotateType;
		bool plantable;
		bool hasDetonator;
		bool timedDetonation;
		bool bNoCrumpleMissile;
		bool rotate;
		bool bKeepRolling;
		bool holdButtonToThrow;
		bool offhandHoldIsCancelable;
		bool freezeMovementWhenFiring;
		float lowAmmoWarningThreshold;
		bool bDisallowAtMatchStart;
		float meleeChargeRange;
		bool bUseAsMelee;
		bool isCameraSensor;
		bool isAcousticSensor;
		bool isLaserSensor;
		bool isHoldUseGrenade;
		float *parallelBounce;
		float *perpendicularBounce;
		FxEffectDef *projTrailEffect;
		vec3_t vProjectileColor;
		guidedMissileType_t guidedMissileType;
		float maxSteeringAccel;
		int projIgnitionDelay;
		FxEffectDef *projIgnitionEffect;
		const char *projIgnitionSound;
		float fAdsAimPitch;
		float fAdsCrosshairInFrac;
		float fAdsCrosshairOutFrac;
		int adsGunKickReducedKickBullets;
		float adsGunKickReducedKickPercent;
		float fAdsGunKickPitchMin;
		float fAdsGunKickPitchMax;
		float fAdsGunKickYawMin;
		float fAdsGunKickYawMax;
		float fAdsGunKickAccel;
		float fAdsGunKickSpeedMax;
		float fAdsGunKickSpeedDecay;
		float fAdsGunKickStaticDecay;
		float fAdsViewKickPitchMin;
		float fAdsViewKickPitchMax;
		float fAdsViewKickMinMagnitude;
		float fAdsViewKickYawMin;
		float fAdsViewKickYawMax;
		float fAdsRecoilReductionRate;
		float fAdsRecoilReductionLimit;
		float fAdsRecoilReturnRate;
		float fAdsViewScatterMin;
		float fAdsViewScatterMax;
		float fAdsSpread;
		int hipGunKickReducedKickBullets;
		float hipGunKickReducedKickPercent;
		float fHipGunKickPitchMin;
		float fHipGunKickPitchMax;
		float fHipGunKickYawMin;
		float fHipGunKickYawMax;
		float fHipGunKickAccel;
		float fHipGunKickSpeedMax;
		float fHipGunKickSpeedDecay;
		float fHipGunKickStaticDecay;
		float fHipViewKickPitchMin;
		float fHipViewKickPitchMax;
		float fHipViewKickMinMagnitude;
		float fHipViewKickYawMin;
		float fHipViewKickYawMax;
		float fHipViewScatterMin;
		float fHipViewScatterMax;
		float fAdsViewKickCenterDuckedScale;
		float fAdsViewKickCenterProneScale;
		float fAntiQuickScopeTime;
		float fAntiQuickScopeScale;
		float fAntiQuickScopeSpreadMultiplier;
		float fAntiQuickScopeSpreadMax;
		float fAntiQuickScopeSwayFactor;
		float fightDist;
		float maxDist;
		const char *accuracyGraphName[2];
		vec2_t *accuracyGraphKnots[2];
		vec2_t *originalAccuracyGraphKnots[2];
		int accuracyGraphKnotCount[2];
		int originalAccuracyGraphKnotCount[2];
		int iPositionReloadTransTime;
		float leftArc;
		float rightArc;
		float topArc;
		float bottomArc;
		float accuracy;
		float aiSpread;
		float playerSpread;
		float minTurnSpeed[2];
		float maxTurnSpeed[2];
		float pitchConvergenceTime;
		float yawConvergenceTime;
		float suppressTime;
		float maxRange;
		float fAnimHorRotateInc;
		float fPlayerPositionDist;
		const char *szUseHintString;
		const char *dropHintString;
		int iUseHintStringIndex;
		int dropHintStringIndex;
		float horizViewJitter;
		float vertViewJitter;
		float cameraShakeScale;
		int cameraShakeDuration;
		int cameraShakeRadius;
		float explosionCameraShakeScale;
		int explosionCameraShakeDuration;
		int explosionCameraShakeRadius;
		const char *szScript;
		float destabilizationRateTime;
		float destabilizationCurvatureMax;
		int destabilizeDistance;
		float *locationDamageMultipliers;
		const char *fireRumble;
		const char *meleeImpactRumble;
		const char *reloadRumble;
		const char *explosionRumble;
		TracerDef *tracerType;
		TracerDef *enemyTracerType;
		float adsDofStart;
		float adsDofEnd;
		float hipDofStart;
		float hipDofEnd;
		float scanSpeed;
		float scanAccel;
		int scanPauseTime;
		const char *flameTableFirstPerson;
		const char *flameTableThirdPerson;
		flameTable *flameTableFirstPersonPtr;
		flameTable *flameTableThirdPersonPtr;
		FxEffectDef *tagFx_preparationEffect;
		FxEffectDef *tagFlash_preparationEffect;
		bool doGibbing;
		float maxGibDistance;
		float altScopeADSTransInTime;
		float altScopeADSTransOutTime;
		int iIntroFireTime;
		int iIntroFireLength;
		FxEffectDef *meleeSwipeEffect;
		FxEffectDef *meleeImpactEffect;
		FxEffectDef *meleeImpactNoBloodEffect;
		const char *throwBackType;
		WeaponCamo *weaponCamo;
		float customFloat0;
		float customFloat1;
		float customFloat2;
		int customBool0;
		int customBool1;
		int customBool2;
	};

	enum eAttachment
	{
		ATTACHMENT_NONE = 0x0,
		ATTACHMENT_ACOG = 0x1,
		ATTACHMENT_DUALCLIP = 0x2,
		ATTACHMENT_DUALOPTIC = 0x3,
		ATTACHMENT_DW = 0x4,
		ATTACHMENT_EXTBARREL = 0x5,
		ATTACHMENT_EXTCLIP = 0x6,
		ATTACHMENT_EXTRAMAGS = 0x7,
		ATTACHMENT_FASTADS = 0x8,
		ATTACHMENT_FASTRELOAD = 0x9,
		ATTACHMENT_FMJ = 0xA,
		ATTACHMENT_GL = 0xB,
		ATTACHMENT_GRIP = 0xC,
		ATTACHMENT_HOLO = 0xD,
		ATTACHMENT_IR = 0xE,
		ATTACHMENT_IRONSIGHTS = 0xF,
		ATTACHMENT_LONGBREATH = 0x10,
		ATTACHMENT_MK = 0x11,
		ATTACHMENT_MMS = 0x12,
		ATTACHMENT_RANGEFINDER = 0x13,
		ATTACHMENT_REFLEX = 0x14,
		ATTACHMENT_RF = 0x15,
		ATTACHMENT_SELECTFIRE = 0x16,
		ATTACHMENT_SILENCER = 0x17,
		ATTACHMENT_STACKFIRE = 0x18,
		ATTACHMENT_STALKER = 0x19,
		ATTACHMENT_STEADYAIM = 0x1A,
		ATTACHMENT_SWAYREDUC = 0x1B,
		ATTACHMENT_TACKNIFE = 0x1C,
		ATTACHMENT_VZOOM = 0x1D,
		ATTACHMENT_TYPE_COUNT = 0x1E,
		ATTACHMENT_INVALID = 0x1E,
	};

	enum eAttachmentPoint
	{
		ATTACHMENT_POINT_NONE = 0x0,
		ATTACHMENT_POINT_TOP = 0x1,
		ATTACHMENT_POINT_FIRST = 0x1,
		ATTACHMENT_POINT_BOTTOM = 0x2,
		ATTACHMENT_POINT_TRIGGER = 0x3,
		ATTACHMENT_POINT_MUZZLE = 0x4,
		ATTACHMENT_POINT_GUNPERK = 0x5,
		ATTACHMENT_POINT_COUNT = 0x6,
		ATTACHMENT_POINT_INVALID = 0x6,
	};

	struct WeaponAttachment
	{
		const char *szInternalName;
		const char *szDisplayName;
		eAttachment attachmentType;
		eAttachmentPoint attachmentPoint;
		PenetrateType penetrateType;
		weapFireType_t fireType;
		int firstRaisePriority;
		float fHipIdleAmount;
		bool bAltWeaponAdsOnly;
		bool bAltWeaponDisableSwitching;
		float altScopeADSTransInTime;
		float altScopeADSTransOutTime;
		bool bSilenced;
		bool bDualMag;
		bool laserSight;
		bool bInfraRed;
		bool bUseAsMelee;
		bool bDualWield;
		bool sharedAmmo;
		float fDamageRangeScale;
		float fAdsZoomFov1;
		float fAdsZoomFov2;
		float fAdsZoomFov3;
		float fAdsZoomInFrac;
		float fAdsZoomOutFrac;
		float fAdsTransInTimeScale;
		float fAdsTransOutTimeScale;
		float fAdsRecoilReductionRate;
		float fAdsRecoilReductionLimit;
		float fAdsViewKickCenterSpeedScale;
		float fAdsIdleAmountScale;
		bool swayOverride;
		float swayMaxAngle;
		float swayLerpSpeed;
		float swayPitchScale;
		float swayYawScale;
		float swayHorizScale;
		float swayVertScale;
		bool adsSwayOverride;
		float adsSwayMaxAngle;
		float adsSwayLerpSpeed;
		float adsSwayPitchScale;
		float adsSwayYawScale;
		float fAdsSwayHorizScale;
		float fAdsSwayVertScale;
		float adsMoveSpeedScale;
		float fHipSpreadMinScale;
		float fHipSpreadMaxScale;
		float strafeRotR;
		float standMoveF;
		vec3_t vStandRot;
		float fFireTimeScale;
		float fReloadTimeScale;
		float fReloadEmptyTimeScale;
		float fReloadAddTimeScale;
		float fReloadQuickTimeScale;
		float fReloadQuickEmptyTimeScale;
		float fReloadQuickAddTimeScale;
		bool mmsWeapon;
		bool mmsInScope;
		float mmsFOV;
		float mmsAspect;
		float mmsMaxDist;
		float clipSizeScale;
		int iClipSize;
		unsigned int stackFire;
		float stackFireSpread;
		float stackFireAccuracyDecay;
		unsigned int perks[2];
		float customFloat0;
		float customFloat1;
		float customFloat2;
		int customBool0;
		int customBool1;
		int customBool2;
	};

	struct WeaponAttachmentUnique
	{
		const char *szInternalName;
		eAttachment attachmentType;
		int siblingLink;
		int childLink;
		int combinedAttachmentTypeMask;
		const char *szAltWeaponName;
		unsigned int altWeaponIndex;
		const char *szDualWieldWeaponName;
		unsigned int dualWieldWeaponIndex;
		unsigned __int16 *hideTags;
		XModel *viewModel;
		XModel *viewModelAdditional;
		XModel *viewModelADS;
		XModel *worldModel;
		XModel *worldModelAdditional;
		const char *viewModelTag;
		const char *worldModelTag;
		vec3_t viewModelOffsets;
		vec3_t worldModelOffsets;
		vec3_t viewModelRotations;
		vec3_t worldModelRotations;
		vec3_t viewModelAddOffsets;
		vec3_t worldModelAddOffsets;
		vec3_t viewModelAddRotations;
		vec3_t worldModelAddRotations;
		WeaponCamo *weaponCamo;
		bool disableBaseWeaponAttachment;
		bool disableBaseWeaponClip;
		bool overrideBaseWeaponAttachmentOffsets;
		vec3_t viewModelOffsetBaseAttachment;
		vec3_t worldModelOffsetBaseAttachment;
		Material *overlayMaterial;
		Material *overlayMaterialLowRes;
		weapOverlayReticle_t overlayReticle;
		int iFirstRaiseTime;
		int iAltRaiseTime;
		int iAltDropTime;
		int iReloadAmmoAdd;
		int iReloadStartAdd;
		bool bSegmentedReload;
		const char **szXAnims;
		int animationOverrides[3];
		float *locationDamageMultipliers;
		int soundOverrides;
		const char *fireSound;
		const char *fireSoundPlayer;
		const char *fireLoopSound;
		const char *fireLoopSoundPlayer;
		const char *fireLoopEndSound;
		const char *fireLoopEndSoundPlayer;
		const char *fireStartSound;
		const char *fireStopSound;
		const char *fireStartSoundPlayer;
		const char *fireStopSoundPlayer;
		const char *fireLastSound;
		const char *fireLastSoundPlayer;
		const char *fireKillcamSound;
		const char *fireKillcamSoundPlayer;
		int effectOverrides;
		FxEffectDef *viewFlashEffect;
		FxEffectDef *worldFlashEffect;
		TracerDef *tracerType;
		TracerDef *enemyTracerType;
		float adsDofStart;
		float adsDofEnd;
		int iAmmoIndex;
		int iClipIndex;
		bool bOverrideLeftHandIK;
		bool bOverrideLeftHandProneIK;
		vec3_t ikLeftHandOffset;
		vec3_t ikLeftHandRotation;
		vec3_t ikLeftHandProneOffset;
		vec3_t ikLeftHandProneRotation;
		float customFloat0;
		float customFloat1;
		float customFloat2;
		int customBool0;
		int customBool1;
		int customBool2;
	};

	struct WeaponVariantDef
	{
		const char *szInternalName;
		int iVariantCount;
		WeaponDef *weapDef;
		const char *szDisplayName;
		const char *szAltWeaponName;
		const char *szAttachmentUnique;
		WeaponAttachment **attachments;
		WeaponAttachmentUnique **attachmentUniques;
		const char **szXAnims;
		unsigned __int16 *hideTags;
		XModel **attachViewModel;
		XModel **attachWorldModel;
		const char **attachViewModelTag;
		const char **attachWorldModelTag;
		float attachViewModelOffsets[24];
		float attachWorldModelOffsets[24];
		float attachViewModelRotations[24];
		float attachWorldModelRotations[24];
		vec3_t stowedModelOffsets;
		vec3_t stowedModelRotations;
		unsigned int altWeaponIndex;
		int iAttachments;
		bool bIgnoreAttachments;
		int iClipSize;
		int iReloadTime;
		int iReloadEmptyTime;
		int iReloadQuickTime;
		int iReloadQuickEmptyTime;
		int iAdsTransInTime;
		int iAdsTransOutTime;
		int iAltRaiseTime;
		const char *szAmmoDisplayName;
		const char *szAmmoName;
		int iAmmoIndex;
		const char *szClipName;
		int iClipIndex;
		float fAimAssistRangeAds;
		float fAdsSwayHorizScale;
		float fAdsSwayVertScale;
		float fAdsViewKickCenterSpeed;
		float fHipViewKickCenterSpeed;
		float fAdsZoomFov1;
		float fAdsZoomFov2;
		float fAdsZoomFov3;
		float fAdsZoomInFrac;
		float fAdsZoomOutFrac;
		float fOverlayAlphaScale;
		float fOOPosAnimLength[2];
		bool bSilenced;
		bool bDualMag;
		bool bInfraRed;
		bool bTVGuided;
		unsigned int perks[2];
		bool bAntiQuickScope;
		Material *overlayMaterial;
		Material *overlayMaterialLowRes;
		Material *dpadIcon;
		weaponIconRatioType_t dpadIconRatio;
		bool noAmmoOnDpadIcon;
		bool mmsWeapon;
		bool mmsInScope;
		float mmsFOV;
		float mmsAspect;
		float mmsMaxDist;
		vec3_t ikLeftHandIdlePos;
		vec3_t ikLeftHandOffset;
		vec3_t ikLeftHandRotation;
		bool bUsingLeftHandProneIK;
		vec3_t ikLeftHandProneOffset;
		vec3_t ikLeftHandProneRotation;
		vec3_t ikLeftHandUiViewerOffset;
		vec3_t ikLeftHandUiViewerRotation;
	};

	struct cspField_t
	{
		const char *szName;
		int iOffset;
		int iFieldType;
	};

	struct WeaponFullDef
	{
		WeaponVariantDef weapVariantDef;
		WeaponDef weapDef;
		WeaponAttachment *attachments[63];
		WeaponAttachmentUnique *attachmentUniques[95];
		XModel *gunXModel[16];
		const char *szXAnims[88];
		unsigned __int16 hideTags[32];
		unsigned __int16 notetrackSoundMapKeys[20];
		unsigned __int16 notetrackSoundMapValues[20];
		XModel *worldModel[16];
		XModel *attachViewModel[8];
		XModel *attachWorldModel[8];
		const char *attachViewModelTag[8];
		const char *attachWorldModelTag[8];
		float parallelBounce[32];
		float perpendicularBounce[32];
		float locationDamageMultipliers[21];
		char weaponCamo[64];
	};

	enum SndMenuCategory
	{
		SND_CATEGORY_SFX = 0x0,
		SND_CATEGORY_MUSIC = 0x1,
		SND_CATEGORY_VOICE = 0x2,
		SND_CATEGORY_UI = 0x3,
		SND_CATEGORY_CINEMATIC = 0x4,
		SND_CATEGORY_COUNT = 0x5,
	};

	struct SndVolumeGroup
	{
		char name[32];
		char parentName[32];
		unsigned int id;
		int parentIndex;
		SndMenuCategory category;
		unsigned __int16 attenuationSp;
		unsigned __int16 attenuationMp;
	};

	struct SndCurve
	{
		char name[32];
		unsigned int id;
		vec2_t points[8];
	};

	struct SndPan
	{
		char name[32];
		unsigned int id;
		float front;
		float back;
		float center;
		float lfe;
		float left;
		float right;
	};

	struct SndDuckGroup
	{
		char name[32];
		unsigned int id;
	};

	struct SndContext
	{
		unsigned int type;
		unsigned int values[8];
	};

	struct SndMaster
	{
		char name[32];
		unsigned int id;
		int lowE;
		float lowG;
		float lowF;
		float lowQ;
		int peak1E;
		float peak1G;
		float peak1F;
		float peak1Q;
		int peak2E;
		float peak2G;
		float peak2F;
		float peak2Q;
		int hiE;
		float hiG;
		float hiF;
		float hiQ;
		float eqG;
		int compE;
		float compPG;
		float compMG;
		float compT;
		float compR;
		float compTA;
		float compTR;
		int limitE;
		float limitPG;
		float limitMG;
		float limitT;
		float limitR;
		float limitTA;
		float limitTR;
		float busReverbG;
		float busFxG;
		float busVoiceG;
		float busPfutzG;
		float busHdrfxG;
		float busUiG;
		float busMusicG;
		float busMovieG;
		float busVcsG;
		int busReverbE;
		int busFxE;
		int busVoiceE;
		int busPfutzE;
		int busHdrfxE;
		int busUiE;
		int busMusicE;
		int busMovieE;
		int hdrfxCompE;
		int voiceEqE;
		int voiceCompE;
	};

	struct SndSidechainDuck
	{
		char name[32];
		unsigned int id;
		float g;
		float f;
		float q;
		float ta;
		float tr;
		float tf;
	};

	struct SndFutz
	{
		char name[32];
		unsigned int id;
		float bpfF;
		float bpfQ;
		float lsG;
		float lsF;
		float lsQ;
		float dist;
		float preG;
		float postG;
		float th;
		float tg;
		float clippre;
		float clippost;
		float blend;
		unsigned int startAliasId;
		unsigned int stopAliasId;
		unsigned int loopAliasId;
	};

	struct SndDriverGlobals
	{
		const char *name;
		unsigned int groupCount;
		SndVolumeGroup *groups;
		unsigned int curveCount;
		SndCurve *curves;
		unsigned int panCount;
		SndPan *pans;
		unsigned int duckGroupCount;
		SndDuckGroup *duckGroups;
		unsigned int contextCount;
		SndContext *contexts;
		unsigned int masterCount;
		SndMaster *masters;
		unsigned int voiceDuckCount;
		SndSidechainDuck *voiceDucks;
		unsigned int futzCount;
		SndFutz *futzes;
	};

	struct FxImpactEntry
	{
		FxEffectDef *nonflesh[32];
		FxEffectDef *flesh[4];
	};

	struct FxImpactTable
	{
		const char *name;
		FxImpactEntry *table;
	};

	struct RawFile
	{
		const char *name;
		int len;
		const char *buffer;
	};

	struct StringTableCell
	{
		const char *string;
		int hash;
	};

	struct StringTable
	{
		const char *name;
		int columnCount;
		int rowCount;
		StringTableCell *values;
		__int16 *cellIndex;
	};

	enum LbColType
	{
		LBCOL_TYPE_NUMBER = 0x0,
		LBCOL_TYPE_TIME = 0x1,
		LBCOL_TYPE_LEVELXP = 0x2,
		LBCOL_TYPE_PRESTIGE = 0x3,
		LBCOL_TYPE_BIGNUMBER = 0x4,
		LBCOL_TYPE_PERCENT = 0x5,
		LBCOL_TYPE_TIME_FULL = 0x6,
		LBCOL_TYPE_COUNT = 0x7,
	};

	enum LbAggType
	{
		LBAGG_TYPE_MIN = 0x0,
		LBAGG_TYPE_MAX = 0x1,
		LBAGG_TYPE_ADD = 0x2,
		LBAGG_TYPE_REPLACE = 0x3,
		LBAGG_TYPE_COUNT = 0x4,
	};

	struct LbColumnDef
	{
		const char *name;
		int colId;
		int dwColIndex;
		bool hidden;
		const char *statName;
		LbColType type;
		int precision;
		LbAggType agg;
		const char *localization;
		int uiCalColX;
		int uiCalColY;
	};

	enum LbUpdateType
	{
		LBUPDATE_TYPE_NORMAL = 0x0,
		LBUPDATE_TYPE_RANK = 0x1,
		LBUPDATE_TYPE_COMBINE = 0x2,
		LBUPDATE_TYPE_COUNT = 0x3,
	};

	struct LeaderboardDef
	{
		const char *name;
		unsigned int id;
		int columnCount;
		int dwColumnCount;
		int xpColId;
		int prestigeColId;
		LbColumnDef *columns;
		LbUpdateType updateType;
		int trackTypes;
	};

	struct gump_info_t
	{
		char *name;
		int size;
	};

	struct overlay_info_t
	{
		char *name;
		int size;
	};

	struct XGlobals
	{
		const char *name;
		int xanimStreamBufferSize;
		int cinematicMaxWidth;
		int cinematicMaxHeight;
		int extracamResolution;
		vec4_t screenClearColor;
		int bigestGumpSize;
		int gumpsCount;
		gump_info_t gumps[32];
		int bigestOverlaySize;
		int overlayCount;
		overlay_info_t overlays[32];
	};

	struct ddlMemberDef_t
	{
		const char *name;
		int size;
		int offset;
		int type;
		int externalIndex;
		unsigned int rangeLimit;
		unsigned int serverDelta;
		unsigned int clientDelta;
		int arraySize;
		int enumIndex;
		int permission;
	};

	struct ddlHash_t
	{
		int hash;
		int index;
	};

	struct ddlStructDef_t
	{
		const char *name;
		int size;
		int memberCount;
		ddlMemberDef_t *members;
		ddlHash_t *hashTable;
	};

	struct ddlEnumDef_t
	{
		const char *name;
		int memberCount;
		const char **members;
		ddlHash_t *hashTable;
	};

	struct ddlDef_t
	{
		int version;
		int size;
		ddlStructDef_t *structList;
		int structCount;
		ddlEnumDef_t *enumList;
		int enumCount;
		ddlDef_t *next;
	};

	struct ddlRoot_t
	{
		const char *name;
		ddlDef_t *ddlDef;
	};

	struct GlassDef
	{
		const char *name;
		int maxHealth;
		float thickness;
		float minShardSize;
		float maxShardSize;
		float shardLifeProbablility;
		int maxShards;
		Material *pristineMaterial;
		Material *crackedMaterial;
		Material *shardMaterial;
		const char *crackSound;
		const char *shatterShound;
		const char *autoShatterShound;
		FxEffectDef *crackEffect;
		FxEffectDef *shatterEffect;
	};

	struct Glass
	{
		unsigned int numCellIndices;
		unsigned __int16 cellIndices[6];
		GlassDef *glassDef;
		unsigned int index;
		unsigned int brushModel;
		vec3_t origin;
		vec3_t angles;
		vec3_t absmin;
		vec3_t absmax;
		bool isPlanar;
		char numOutlineVerts;
		char binormalSign;
		vec2_t *outline;
		vec3_t outlineAxis[3];
		vec3_t outlineOrigin;
		float uvScale;
		float thickness;
	};

	struct Glasses
	{
		const char *name;
		unsigned int numGlasses;
		Glass *glasses;
		char *workMemory;
		unsigned int workMemorySize;
		unsigned int smallAllocatorBlocks;
		unsigned int maxGroups;
		unsigned int maxShards;
		unsigned int maxPhysics;
		unsigned int shardMemorySize;
		unsigned int maxFreeCmd;
		unsigned int numSlots;
		unsigned int numVerts;
		unsigned int numIndices;
	};

	struct EmblemLayer
	{
		int cost;
		int unlockLevel;
		int unlockPLevel;
	};

	struct EmblemCategory
	{
		const char *name;
		const char *description;
	};

	struct EmblemIconType
	{
		const char *name;
		const char *description;
	};

	struct EmblemBGCategory
	{
		const char *name;
		const char *description;
	};

	struct EmblemIcon
	{
		GfxImage *image;
		const char *description;
		float outlineSize;
		int cost;
		int unlockLevel;
		int unlockPLevel;
		int unclassifyAt;
		int sortKey;
		unsigned __int16 iconType;
		unsigned __int16 category;
	};

	struct EmblemBackground
	{
		Material *material;
		const char *description;
		int cost;
		int unlockLevel;
		int unlockPLevel;
		int unclassifyAt;
		int sortKey;
		unsigned __int16 bgCategory;
		int mtxIndex;
	};

	struct EmblemSet
	{
		int colorCount;
		int layerCount;
		EmblemLayer layers[32];
		int categoryCount;
		EmblemCategory categories[16];
		int iconTypeCount;
		EmblemIconType iconTypes[16];
		int bgCategoryCount;
		EmblemBGCategory bgCategories[16];
		int iconCount;
		EmblemIcon icons[1024];
		int backgroundCount;
		EmblemBackground backgrounds[550];
		int backgroundLookupCount;
		__int16 backgroundLookup[550];
	};

	struct ScriptParseTree
	{
		const char *name;
		int len;
		char *buffer;
	};

	struct KeyValuePair
	{
		int keyHash;
		int namespaceHash;
		const char *value;
	};

	struct KeyValuePairs
	{
		const char *name;
		int numVariables;
		KeyValuePair *keyValuePairs;
	};

	struct view_limits_t
	{
		float horizSpanLeft;
		float horizSpanRight;
		float vertSpanUp;
		float vertSpanDown;
		float horizResistLeft;
		float horizResistRight;
		float vertResistUp;
		float vertResistDown;
	};

	enum DevEventType
	{
		EVENT_ACTIVATE = 0x0,
		EVENT_DEACTIVATE = 0x1,
		EVENT_ACCEPT = 0x2,
		EVENT_UPDATE = 0x3,
		EVENT_DRAW = 0x4,
		EVENT_SAVE = 0x5,
	};

	enum errorParm_t
	{
		ERR_FATAL = 0x0,
		ERR_DROP = 0x1,
		ERR_FROM_STARTUP = 0x2,
		ERR_SERVERDISCONNECT = 0x3,
		ERR_DISCONNECT = 0x4,
		ERR_SCRIPT = 0x5,
		ERR_SCRIPT_DROP = 0x6,
		ERR_LOCALIZATION = 0x7,
	};

	enum LocalClientNum_t
	{
		INVALID_LOCAL_CLIENT = 0xFFFFFFFF,
		LOCAL_CLIENT_FIRST = 0x0,
		LOCAL_CLIENT_0 = 0x0,
		ONLY_LOCAL_CLIENT = 0x0,
		LOCAL_CLIENT_COUNT = 0x1,
	};

	enum ControllerIndex_t
	{
		INVALID_CONTROLLER_PORT = 0xFFFFFFFF,
		CONTROLLER_INDEX_FIRST = 0x0,
		CONTROLLER_INDEX_0 = 0x0,
		CONTROLLER_INDEX_COUNT = 0x1,
	};

	struct DevGraph
	{
		vec2_t *knots;
		int *knotCount;
		int knotCountMax;
		int selectedKnot;
		void(__cdecl *eventCallback)(DevGraph *, DevEventType, LocalClientNum_t);
		void(__cdecl *textCallback)(DevGraph *, const float, const float, char *, const int);
		void *data;
		bool disableEditingEndPoints;
	};

	struct GraphFloat
	{
		char name[64];
		vec2_t knots[32];
		int knotCount;
		float scale;
		DevGraph devguiGraph;
	};

	enum TractionType
	{
		TRACTION_TYPE_FRONT = 0x0,
		TRACTION_TYPE_BACK = 0x1,
		TRACTION_TYPE_ALL_WD = 0x2,
		NUM_TRACTION_TYPES = 0x3,
	};

	struct VehicleParameter
	{
		float m_speed_max;
		float m_accel_max;
		float m_reverse_scale;
		float m_steer_angle_max;
		float m_steer_angle_speed_scale;
		float m_steer_speed;
		float m_wheel_radius;
		float m_susp_spring_k;
		float m_susp_damp_k;
		float m_susp_adj;
		float m_susp_hard_limit;
		float m_susp_min_height;
		float m_tire_fric_fwd;
		float m_tire_fric_side;
		float m_tire_fric_brake;
		float m_tire_fric_hand_brake;
		float m_body_mass;
		float m_roll_stability;
		float m_pitch_stability;
		float m_pitch_roll_resistance;
		float m_yaw_resistance;
		float m_upright_strength;
		float m_tilt_fakey;
		float m_peel_out_max_speed;
		float m_tire_damp_coast;
		float m_tire_damp_brake;
		float m_tire_damp_hand;
		float m_auto_hand_brake_min_speed;
		TractionType m_traction_type;
		const char *m_name;
		vec3_t m_bbox_min;
		vec3_t m_bbox_max;
		vec3_t m_mass_center_offset;
		vec3_t m_buoyancybox_min;
		vec3_t m_buoyancybox_max;
		float m_water_speed_max;
		float m_water_accel_max;
		float m_water_turn_accel;
		float m_water_turn_speed_max;
		float m_water_ebrake_power;
		vec3_t m_boat_motor_offset;
		float m_boat_speed_rise;
		float m_boat_speed_tilt;
		float m_boat_side_fric_scale;
		float m_boat_forward_fric_scale;
		float m_boat_vertical_fric_scale;
		float m_jump_force;
		float m_tire_fric_side_max;
		bool m_drive_on_walls;
		float m_linear_drag_scale;
		float m_angular_drag_scale;
	};

	struct VehicleDriveBySound
	{
		int apex;
		const char *name;
		unsigned int alias;
	};

	struct VehicleEngineSound
	{
		const char *name;
		unsigned int alias;
		float params[5];
	};

	struct VehicleGearData
	{
		float minRPM;
		float maxRPM;
		float ratio;
	};

	struct VehicleEngine
	{
		float idleRpms;
		float maxRpms;
		float maxTorque;
		float brakingCoeff;
		vec4_t loadFadeParams;
		float loadScale;
		float loadSmoothing;
		float throttleLag;
		float pitchScale;
		VehicleEngineSound onload[5];
		VehicleEngineSound offload[5];
		int numGears;
		int loopLastGear;
		VehicleGearData gears[10];
	};

	struct VehicleAntenna
	{
		float springK;
		float damp;
		float length;
		float gravity;
	};

	const struct VehicleDef
	{
		const char *name;
		__int16 type;
		int remoteControl;
		int bulletDamage;
		int armorPiercingDamage;
		int grenadeDamage;
		int projectileDamage;
		int projectileSplashDamage;
		int heavyExplosiveDamage;
		__int16 cameraMode;
		int autoRecenterOnAccel;
		int thirdPersonDriver;
		int thirdPersonUseVehicleRoll;
		int thirdPersonCameraPitchVehicleRelative;
		int thirdPersonCameraHeightWorldRelative;
		float thirdPersonCameraRange;
		float thirdPersonCameraMinPitchClamp;
		float thirdPersonCameraMaxPitchClamp;
		float thirdPersonCameraHeight[2];
		float thirdPersonCameraPitch[2];
		int cameraAlwaysAutoCenter;
		float cameraAutoCenterLerpRate;
		float cameraAutoCenterMaxLerpRate;
		float thirdPersonCameraSpringDistance;
		float thirdPersonCameraSpringTime;
		float thirdPersonCameraHandbrakeTurnRateInc;
		float cameraFOV;
		float cameraRollFraction;
		vec3_t tagPlayerOffset;
		int killcamCollision;
		float killcamDist;
		float killcamZDist;
		float killcamMinDist;
		float killcamZTargetOffset;
		float killcamFOV;
		float killcamNearBlur;
		float killcamNearBlurStart;
		float killcamNearBlurEnd;
		float killcamFarBlur;
		float killcamFarBlurStart;
		float killcamFarBlurEnd;
		int isDrivable;
		int numberOfSeats;
		int numberOfGunners;
		int seatSwitchOrder[11];
		int driverControlledGunPos;
		float entryPointRadius[5];
		float texScrollScale;
		float wheelRotRate;
		float extraWheelRotScale;
		int wheelChildTakesSteerYaw;
		float maxSpeed;
		float maxSpeedVertical;
		float accel;
		float accelVertical;
		float rotRate;
		float rotAccel;
		float maxBodyPitch;
		float maxBodyRoll;
		float collisionDamage;
		float collisionSpeed;
		float suspensionTravel;
		float heliCollisionScalar;
		float viewPitchOffset;
		float viewInfluence;
		float tiltFromAcceleration[2];
		float tiltFromDeceleration[2];
		float tiltFromVelocity[2];
		float tiltSpeed[2];
		const char *turretWeapon;
		view_limits_t turretViewLimits;
		float turretRotRate;
		int turretClampPlayerView;
		int turretLockTurretToPlayerView;
		const char *gunnerWeapon[4];
		unsigned __int16 gunnerWeaponIndex[4];
		float gunnerRotRate;
		vec2_t gunnerRestAngles[4];
		view_limits_t passengerViewLimits[6];
		const char *sndNames[2];
		unsigned int sndIndices[2];
		const char *sndMaterialNames[3];
		float skidSpeedMin;
		float skidSpeedMax;
		const char *futzName;
		float futzBlend;
		int animType;
		const char *animSet;
		int scriptedAnimationEntry;
		float mantleAngles[4];
		unsigned __int16 extraWheelTags[4];
		unsigned __int16 driverHideTag;
		XModel *attachmentModels[4];
		unsigned __int16 attachmentTags[4];
		XModel *deathAttachmentModels[4];
		unsigned __int16 deathAttachmentTags[4];
		float tracerOffset[2];
		XModel *model;
		XModel *viewModel;
		XModel *deathModel;
		XModel *enemyModel;
		float modelSwapDelay;
		FxEffectDef *exhaustFx;
		int oneExhaust;
		FxEffectDef *treadFx[32];
		FxEffectDef *deathFx;
		unsigned __int16 deathFxTag;
		const char *deathFxSound;
		FxEffectDef *lightFx[4];
		unsigned __int16 lightFxTag[4];
		FxEffectDef *friendlyLightFx;
		unsigned __int16 friendlyLightFxTag;
		FxEffectDef *enemyLightFx;
		unsigned __int16 enemyLightFxTag;
		float radiusDamageMin;
		float radiusDamageMax;
		float radiusDamageRadius;
		const char *shootShock;
		const char *shootRumble;
		float deathQuakeScale;
		float deathQuakeDuration;
		float deathQuakeRadius;
		const char *rumbleType;
		float rumbleScale;
		float rumbleDuration;
		float rumbleRadius;
		float rumbleBaseTime;
		float rumbleAdditionalTime;
		int healthDefault;
		int healthMin;
		int healthMax;
		int eTeam;
		int boostAccelMultiplier;
		float boostDuration;
		float boostSpeedIncrease;
		int addToCompass;
		int addToCompassEnemy;
		const char *compassIcon;
		Material *compassIconMaterial;
		const char *gasButtonName;
		int gasButton;
		const char *reverseBrakeButtonName;
		int reverseBrakeButton;
		const char *handBrakeButtonName;
		int handBrakeButton;
		const char *attackButtonName;
		int attackButton;
		const char *attackSecondaryButtonName;
		int attackSecondaryButton;
		const char *boostButtonName;
		int boostButton;
		const char *moveUpButtonName;
		int moveUpButton;
		const char *moveDownButtonName;
		int moveDownButton;
		const char *switchSeatButtonName;
		int switchSeatButton;
		const char *steerGraphName;
		GraphFloat *steerGraph;
		const char *accelGraphName;
		GraphFloat *accelGraph;
		int isNitrous;
		int isFourWheelSteering;
		int useCollmap;
		float radius;
		float minHeight;
		float maxHeight;
		float max_fric_tilt_angle;
		float max_fric_tilt;
		int noDirectionalDamage;
		int fakeBodyStabilizer;
		float vehHelicopterBoundsRadius;
		float vehHelicopterDecelerationFwd;
		float vehHelicopterDecelerationSide;
		float vehHelicopterDecelerationUp;
		float vehHelicopterTiltFromControllerAxes;
		float vehHelicopterTiltFromFwdAndYaw;
		float vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt;
		float vehHelicopterTiltMomentum;
		int vehHelicopterQuadRotor;
		int vehHelicopterAccelTwardsView;
		float maxRotorArmMovementAngle;
		float maxRotorArmRotationAngle;
		int vehHelicopterMaintainHeight;
		int vehHelicopterMaintainMaxHeight;
		float vehHelicopterMaintainHeightLimit;
		float vehHelicopterMaintainHeightAccel;
		float vehHelicopterMaintainHeightMinimum;
		float vehHelicopterMaintainHeightMaximum;
		float vehHelicopterMaintainCeilingMinimum;
		int joltVehicle;
		int joltVehicleDriver;
		float joltMaxTime;
		float joltTime;
		float joltWaves;
		float joltIntensity;
		VehicleParameter nitrousVehParams;
		float driveBySoundRadius[2];
		VehicleDriveBySound driveBySounds[40];
		int doFootSteps;
		int isSentient;
		VehicleEngine engine;
		VehicleAntenna antenna[2];
		char *csvInclude;
		float customFloat0;
		float customFloat1;
		float customFloat2;
		int customBool0;
		int customBool1;
		int customBool2;
	};

	struct MemoryBlock
	{
		const char *name;
		bool mainMem;
		bool videoMem;
		bool streamMem;
		unsigned int size;
		unsigned int alignment;
		char *data;
	};

	struct AddonMapEnts
	{
		const char *name;
		char *entityString;
		int numEntityChars;
		MapTriggers trigger;
		ClipInfo *info;
		unsigned int numSubModels;
		cmodel_t *cmodels;
		GfxBrushModel *models;
	};

	struct SkinnedVertsDef
	{
		const char *name;
		unsigned int maxSkinnedVerts;
	};

	struct Qdb
	{
		const char *name;
		int len;
		char *buffer;
	};

	struct Slug
	{
		const char *name;
		int len;
		char *buffer;
	};

	struct FootstepTableDef
	{
		const char *name;
		unsigned int sndAliasTable[32][7];
	};

	struct FootstepFXTableDef
	{
		const char *name;
		FxEffectDef *footstepFX[32];
	};

	struct ZBarrierBoard
	{
		XModel *pBoardModel;
		XModel *pAlternateBoardModel;
		XModel *pUpgradedBoardModel;
		const char *pTearAnim;
		const char *pBoardAnim;
		FxEffectDef *repairEffect1;
		FxEffectDef *repairEffect2;
		vec3_t repairEffect1Offset;
		vec3_t repairEffect2Offset;
		unsigned int boardRepairSound;
		unsigned int boardRepairHoverSound;
		unsigned int pauseAndRepeatRepSound;
		float minPause;
		float maxPause;
		unsigned __int16 zombieBoardTearStateName;
		unsigned __int16 zombieBoardTearSubStateName;
		unsigned int numRepsToPullProBoard;
	};

	struct ZBarrierDef
	{
		const char *name;
		unsigned int generalRepairSound1;
		unsigned int generalRepairSound2;
		unsigned int upgradedGeneralRepairSound1;
		unsigned int upgradedGeneralRepairSound2;
		unsigned int delayBetweenRepSounds;
		float delayBetweenRepSoundsDuration;
		unsigned int earthquakeOnRepair;
		float earthquakeMinScale;
		float earthquakeMaxScale;
		float earthquakeMinDuration;
		float earthquakeMaxDuration;
		float earthquakeRadius;
		int numBoardsInBarrier;
		unsigned int autoHideOpenPieces;
		unsigned int taunts;
		unsigned int reachThroughAttacks;
		unsigned __int16 zombieTauntAnimState;
		unsigned __int16 zombieReachThroughAnimState;
		int numAttackSlots;
		float attackSpotHorzOffset;
		ZBarrierBoard boards[6];
	};

	union XAssetHeader
	{
		void *data;
		XModelPieces *xmodelPieces;
		PhysPreset *physPreset;
		PhysConstraints *physConstraints;
		DestructibleDef *destructibleDef;
		XAnimParts *parts;
		XModel *model;
		Material *material;
		MaterialPixelShader *pixelShader;
		MaterialVertexShader *vertexShader;
		MaterialTechniqueSet *techniqueSet;
		GfxImage *image;
		SndBank *sound;
		SndPatch *soundPatch;
		clipMap_t *clipMap;
		ComWorld *comWorld;
		GameWorldSp *gameWorldSp;
		GameWorldMp *gameWorldMp;
		MapEnts *mapEnts;
		GfxWorld *gfxWorld;
		GfxLightDef *lightDef;
		Font_s *font;
		FontIcon *fontIcon;
		MenuList *menuList;
		menuDef_t *menu;
		LocalizeEntry *localize;
		WeaponVariantDef *weapon;
		WeaponAttachment *attachment;
		WeaponAttachmentUnique *attachmentUnique;
		WeaponCamo *weaponCamo;
		SndDriverGlobals *sndDriverGlobals;
		FxEffectDef *fx;
		FxImpactTable *impactFx;
		RawFile *rawfile;
		StringTable *stringTable;
		LeaderboardDef *leaderboardDef;
		XGlobals *xGlobals;
		ddlRoot_t *ddlRoot;
		Glasses *glasses;
		//TextureList *textureList;
		void *textureList;
		EmblemSet *emblemSet;
		ScriptParseTree *scriptParseTree;
		KeyValuePairs *keyValuePairs;
		VehicleDef *vehicleDef;
		MemoryBlock *memoryBlock;
		AddonMapEnts *addonMapEnts;
		TracerDef *tracerDef;
		SkinnedVertsDef *skinnedVertsDef;
		Qdb *qdb;
		Slug *slug;
		FootstepTableDef *footstepTableDef;
		FootstepFXTableDef *footstepFXTableDef;
		ZBarrierDef *zbarrierDef;
	};

	struct XAsset
	{
		XAssetType type;
		XAssetHeader header;
	};

	struct ScriptStringList
	{
		int count;
		const char **strings;
	};

	struct XAssetList
	{
		ScriptStringList stringList;
		int dependCount;
		const char **depends;
		int assetCount;
		XAsset *assets;
	};

	struct XAssetEntry
	{
		XAsset asset;
		char zoneIndex;
		bool inuse;
		unsigned __int16 nextHash;
		unsigned __int16 nextOverride;
		unsigned __int16 usageFrame;
	};

	union XAssetEntryPoolEntry
	{
		XAssetEntry entry;
		XAssetEntryPoolEntry *next;
	};

	enum DB_ZONE_LOADTYPES
	{
		DB_ZONE_PRE_GFX = 0x00000001,
		DB_ZONE_PATCH = 0x00000002,
		DB_ZONE_PATCH_LOC = 0x00000004,
		DB_ZONE_CODE = 0x00000008,
		DB_ZONE_CODE_LOC = 0x00000010,
		DB_ZONE_CODE_RES = 0x00000020,
		DB_ZONE_DEV = 0x00000040,
		DB_ZONE_COMMON = 0x00000080,
		DB_ZONE_COMMON_PATCH = 0x00000100,
		DB_ZONE_COMMON_LOC = 0x00000200,
		DB_ZONE_LOAD = 0x00000400,
		DB_ZONE_SHARED_PATCH = 0x00000800,
		DB_ZONE_SHARED = 0x00001000,
		DB_ZONE_SHARED_LOC = 0x00002000,
		DB_ZONE_LEVEL_PATCH = 0x00004000,
		DB_ZONE_LEVEL = 0x00008000,
		DB_ZONE_LEVEL_LOC = 0x00010000,
		DB_ZONE_LEVELOVERLAY_PATCH = 0x00020000,
		DB_ZONE_LEVELOVERLAY = 0x00040000,
		DB_ZONE_LEVELOVERLAY_LOC = 0x00080000,
		DB_ZONE_WEAPONS = 0x00100000,
		DB_ZONE_GUMP = 0x00200000,
		DB_ZONE_LOW_MARKER = 0x00400000,
		DB_ZONE_CUSTOM_TYPE = 0x00800000, // Custom type
		DB_ZONE_MYCHANGES = 0x01000000,
		DB_ZONE_FRONTEND = 0x02000000,
		DB_ZONE_FRONTEND_LOC = 0x04000000,
		DB_ZONE_PATCH_UI = 0x08000000,
		DB_ZONE_PATCH_UI_LOC = 0x10000000,
		DB_ZONE_FFOTD = 0x20000000,
		DB_ZONE_HIGH_MARKER = 0x40000000,
		DB_FLAG_STRICTFREE = 0x80000000,
	};

	struct XZoneInfo
	{
		const char *name;
		int allocFlags;
		int freeFlags;
	};

	struct XZoneInfoInternal
	{
		char name[64];
		int flags;
	};

	enum XZoneState
	{
		XZONE_UNLOADING = 0xFFFFFFFF,
		XZONE_EMPTY = 0x0,
		XZONE_LOADING = 0x1,
		XZONE_LOADED = 0x2,
		XZONE_COMPLETE = 0x3,
	};

	struct XZoneName
	{
		char name[64];
		int flags;
		int fileSize;
		XZoneState state;
	};

	enum XFILE_BLOCK_TYPES
	{
		XFILE_BLOCK_TEMP = 0x0,
		XFILE_BLOCK_RUNTIME_VIRTUAL = 0x1,
		XFILE_BLOCK_RUNTIME_PHYSICAL = 0x2,
		XFILE_BLOCK_DELAY_VIRTUAL = 0x3,
		XFILE_BLOCK_DELAY_PHYSICAL = 0x4,
		XFILE_BLOCK_VIRTUAL = 0x5,
		XFILE_BLOCK_PHYSICAL = 0x6,
		XFILE_BLOCK_STREAMER_RESERVE = 0x7,
		MAX_XFILE_COUNT = 0x8,

		XFILE_BLOCK_INVALID = -1
	};

	struct XBlock
	{
		char *data;
		unsigned int size;
	};

	struct XZone
	{
		unsigned __int16 index;
		int flags;
		XBlock blocks[MAX_XFILE_COUNT];
	};

	struct __declspec(align(128)) DB_LOAD_STREAM
	{
		char decompressedData[32768];
		char checksum[32];
		char *compressedData;
		int compressedDataAvail;
		int decompressedDataAvail;
		int decompressedDataOffset;
		bool busy;
	};

	struct DBDecompressCmd_t
	{
		int which;
		DB_LOAD_STREAM *stream;
		char *ioBuffer;
		char iv[8];
	};

	struct __declspec(align(128)) DB_LoadData
	{
		int f;
		const char *filename;
		XBlock *blocks;
		int flags;
		void(__cdecl *interrupt)();
		int allocType;
		unsigned __int64 readOffset;
		unsigned __int64 endOffset;
		char *ioBuffer;
		int ioBufferOffset;
		char *compressData;
		int tail;
		int head;
		DBDecompressCmd_t cmd[4];
		__declspec(align(128)) DB_LOAD_STREAM stream[4];
		int next_buffer;
		int locks[4];
		bool loadPending[4];
		bool abort;
		int requiredVersion;
		int lastError;
		int startTime;
	};

	struct XFile
	{
		unsigned int size;
		unsigned int externalSize;
		unsigned int blockSize[MAX_XFILE_COUNT];
	};

	enum Q_DATA_TYPE
	{
		Q_DATA_TYPE_INT = 0x0,
		Q_DATA_TYPE_FLOAT = 0x1,
		Q_DATA_TYPE_BLOB = 0x2,
		Q_DATA_TYPE_STRING = 0x3,
		Q_DATA_TYPE_ISTRING = 0x4,
	};

	struct Q_COLUMN
	{
		Q_DATA_TYPE column_type;
		char *column_name;
	};

	struct Q_TABLE
	{
		char *name;
		unsigned int column_count;
		unsigned int primary_key_column;
		Q_COLUMN *column;
		unsigned int row_count;
		void *data;
	};

	struct Q_DB
	{
		char *name;
		unsigned int table_count;
		Q_TABLE *tables;
	};

	struct Q_DB_HEADER
	{
		char magic_version[8];
		unsigned int fixup_count;
		unsigned int fixup_offset;
		unsigned int string_count;
		void *strings;
		unsigned int num_db;
		Q_DB *db;
	};

	enum consoleChannel_e
	{
		CON_CHANNEL_DONT_FILTER = 0x0,
		CON_CHANNEL_ERROR = 0x1,
		CON_CHANNEL_GAMENOTIFY = 0x2,
		CON_CHANNEL_BOLDGAME = 0x3,
		CON_CHANNEL_OBJNOTIFY = 0x4,
		CON_CHANNEL_SUBTITLE = 0x5,
		CON_CHANNEL_OBITUARY = 0x6,
		CON_CHANNEL_COOPINFO = 0x7,
		CON_CHANNEL_LOGFILEONLY = 0x8,
		CON_CHANNEL_CONSOLEONLY = 0x9,
		CON_CHANNEL_SYSTEM = 0xA,
		CON_CHANNEL_NETWORK = 0xB,
		CON_CHANNEL_TASK = 0xC,
		CON_CHANNEL_GFX = 0xD,
		CON_CHANNEL_SOUND = 0xE,
		CON_CHANNEL_FILES = 0xF,
		CON_CHANNEL_UI = 0x10,
		CON_CHANNEL_AI = 0x11,
		CON_CHANNEL_ANIM = 0x12,
		CON_CHANNEL_PHYS = 0x13,
		CON_CHANNEL_FX = 0x14,
		CON_CHANNEL_SCRIPT = 0x15,
		CON_CHANNEL_TL = 0x16,
		CON_CHANNEL_PERFORMANCE = 0x17,
		CON_CHANNEL_DEVGUI = 0x18,
		CON_CHANNEL_CLIENT = 0x19,
		CON_CHANNEL_SERVER = 0x1A,
		CON_CHANNEL_PLAYERWEAP = 0x1B,
		CON_CHANNEL_LIVE = 0x1C,
		CON_CHANNEL_FROMSCRIPT = 0x1D,
		CON_CHANNEL_SPAWNSYSTEM = 0x1E,
		CON_CHANNEL_LEADERBOARDS = 0x1F,
		CON_CHANNEL_DDL = 0x20,
		CON_CHANNEL_SPU = 0x21,
		CON_CHANNEL_GAMERPROFILE = 0x22,
		CON_CHANNEL_PRESENCE = 0x23,
		CON_CHANNEL_RUMBLE = 0x24,
		CON_CHANNEL_UNLOCKABLES = 0x25,
		CON_CHANNEL_VOICE = 0x26,
		CON_CHANNEL_HTTP = 0x27,
		CON_CHANNEL_GFWL = 0x28,
		CON_CHANNEL_IPAK = 0x29,
		CON_CHANNEL_WEBM = 0x2A,
		CON_CHANNEL_PROBER = 0x2B,
		CON_CHANNEL_MIPSTER = 0x2C,
		CON_CHANNEL_STEAM = 0x2D,
		CON_CHANNEL_SOCIAL = 0x2E,
		CON_CHANNEL_DCACHE = 0x2F,
		CON_CHANNEL_RSTREAM = 0x30,
		CON_CHANNEL_SCHEDULER = 0x31,
		CON_CHANNEL_MATCHRECORD = 0x32,
		CON_CHANNEL_MIGRATE = 0x33,
		CON_BUILTIN_CHANNEL_COUNT = 0x34,
		CON_FIRST_DEBUG_CHANNEL = 0x2E,
	};

	struct IPakSection
	{
		unsigned int type;
		unsigned int offset;
		unsigned int size;
		unsigned int itemCount;
	};

	struct IPakLoadedPackfile
	{
		char name[64];
		IPakSection data;
		IPakSection index;
		int fh;
		int refCount;
	};

	struct IPakHeader
	{
		unsigned int magic;
		unsigned int version;
		unsigned int size;
		unsigned int sectionCount;
	};

	struct IPakIndexEntry
	{
		unsigned int checksum;
		unsigned int fileID;
		unsigned int offset;
		unsigned int size;
	};

	struct IPakWorkData
	{
		IPakLoadedPackfile *pak;
		int indexReadOffset;
		int activeBuffer;
		unsigned int currentEntry;
		unsigned __int16 imageParts[4816];
		IPakIndexEntry indexBuffer[2][4096];
		int indexBufferOffset[2];
		int indexBufferState[2];
	};

	struct IPakDataChunkHeader
	{
		char offset[3];
		char numCommands;
		unsigned int commands[31]; // commands are top 24 bits are blocksize, bottom 8 are encrypted or not
	};

	struct GfxImageFileHeader
	{
		char tag[3];
		char version;
		char format;
		char flags;
		__int16 dimensions[3];
		float gamma;
		char maxGlossForMip[16];
		int fileSizeForPicmip[8];
	};

	struct WinConData
	{
		HWND hWnd;
		HWND hwndBuffer;
		HWND codLogo;
		HFONT hfBufferFont;
		HWND hwndInputLine;
		char errorString[512];
		char consoleText[512];
		char returnedText[512];
		int windowWidth;
		int windowHeight;
		int(__stdcall *SysInputLineWndProc)(HWND, unsigned int, unsigned int, int);
	};

	enum fsMode_t
	{
		FS_READ = 0x0,
		FS_WRITE = 0x1,
		FS_APPEND = 0x2,
		FS_APPEND_SYNC = 0x3,
	};

	enum FsListBehavior_e
	{
		FS_LIST_PURE_ONLY = 0x0,
		FS_LIST_ALL = 0x1,
	};

	enum scriptInstance_t
	{
		SCRIPTINSTANCE_SERVER = 0x0,
		SCRIPTINSTANCE_CLIENT = 0x1,
		SCRIPT_INSTANCE_MAX = 0x2,
	};

	enum bdNATType : unsigned char
	{
		BD_NAT_UNKNOWN = 0x0,
		BD_NAT_OPEN = 0x1,
		BD_NAT_MODERATE = 0x2,
		BD_NAT_STRICT = 0x3,
	};

#pragma pack(push, 1)
	struct bdAuthTicket
	{
		unsigned int m_magicNumber;
		char m_type;
		unsigned int m_titleID;
		unsigned int m_timeIssued;
		unsigned int m_timeExpires;
		unsigned __int64 m_licenseID;
		unsigned __int64 m_userID;
		char m_username[64];
		char m_sessionKey[24];
		char m_usingHashMagicNumber[3];
		char m_hash[4];
	};
#pragma pack(pop)

	union netip_t
	{
		char ip[4];
		unsigned int inaddr;
	};

	enum netadrtype_t
	{
		NA_BOT = 0x0,
		NA_BAD = 0x1,
		NA_LOOPBACK = 0x2,
		NA_BROADCAST = 0x3,
		NA_IP = 0x4,
	};

	enum netsrc_t
	{
		NS_NULL = 0xFFFFFFFF,
		NS_CLIENT1 = 0x0,
		NS_CLIENT2 = 0x1,
		NS_CLIENT3 = 0x2,
		NS_CLIENT4 = 0x3,
		NS_SERVER = 0x4,
		NS_MAXCLIENTS = 0x4,
		NS_PACKET = 0x5,
	};

	struct netadr_t
	{
		netip_t addr;
		unsigned __int16 port;
		netadrtype_t type;
		netsrc_t localNetID;
		unsigned __int16 serverID;
	};

	struct msg_t
	{
		int overflowed;
		int readOnly;
		char *data;
		char *splitData;
		int maxsize;
		int cursize;
		int splitSize;
		int readcount;
		int bit;
		int lastEntityRef;
		int flush;
		netsrc_t targetLocalNetID;
	};

	// Copied from Quake
	// not all are equal to COD's

	enum keyNum_t
	{
		K_NONE = 0x0,
		K_FIRSTGAMEPADBUTTON_RANGE_1 = 0x1,
		K_BUTTON_A = 0x1,
		K_BUTTON_B = 0x2,
		K_BUTTON_X = 0x3,
		K_BUTTON_Y = 0x4,
		K_BUTTON_LSHLDR = 0x5,
		K_BUTTON_RSHLDR = 0x6,
		K_LASTGAMEPADBUTTON_RANGE_1 = 0x6,
		K_BS = 0x8,
		K_TAB = 0x9,
		K_NL = 0xA,
		K_ENTER = 0xD,
		K_FIRSTGAMEPADBUTTON_RANGE_2 = 0xE,
		K_BUTTON_START = 0xE,
		K_BUTTON_BACK = 0xF,
		K_BUTTON_LSTICK = 0x10,
		K_BUTTON_RSTICK = 0x11,
		K_BUTTON_LTRIG = 0x12,
		K_BUTTON_RTRIG = 0x13,
		K_DPAD_UP = 0x14,
		K_FIRSTDPAD = 0x14,
		K_DPAD_DOWN = 0x15,
		K_DPAD_LEFT = 0x16,
		K_DPAD_RIGHT = 0x17,
		K_BUTTON_RTRIG_PUSH = 0x18,
		K_BUTTON_LTRIG_PUSH = 0x19,
		K_BUTTON_LSTICK_ALTIMAGE2 = 0x10,
		K_BUTTON_RSTICK_ALTIMAGE2 = 0x11,
		K_BUTTON_LSTICK_ALTIMAGE = 0xBC,
		K_NUNCHUK_RIGHT = 0xBC,
		K_BUTTON_RSTICK_ALTIMAGE = 0xBD,
		K_WIIUMOTE_RIGHT = 0xBD,
		K_LASTDPAD = 0x17,
		K_DPAD_LEFTRIGHT = 0x18,
		K_DPAD_UPDOWN = 0x19,
		K_LASTGAMEPADBUTTON_RANGE_2 = 0x19,
		K_CODPOINTS = 0x1A,
		K_ESCAPE = 0x1B,
		K_FIRSTGAMEPADBUTTON_RANGE_3 = 0x1C,
		K_APAD_UP = 0x1C,
		K_FIRSTAPAD = 0x1C,
		K_APAD_DOWN = 0x1D,
		K_APAD_LEFT = 0x1E,
		K_APAD_RIGHT = 0x1F,
		K_LASTAPAD = 0x1F,
		K_LASTGAMEPADBUTTON_RANGE_3 = 0x1F,
		K_SPACE = 0x20,
		K_BACKSPACE = 0x7F,
		K_ASCII_FIRST = 0x80,
		K_ASCII_181 = 0x80,
		K_ASCII_191 = 0x81,
		K_ASCII_223 = 0x82,
		K_ASCII_224 = 0x83,
		K_ASCII_225 = 0x84,
		K_ASCII_228 = 0x85,
		K_ASCII_229 = 0x86,
		K_ASCII_230 = 0x87,
		K_ASCII_231 = 0x88,
		K_ASCII_232 = 0x89,
		K_ASCII_233 = 0x8A,
		K_ASCII_236 = 0x8B,
		K_ASCII_241 = 0x8C,
		K_ASCII_242 = 0x8D,
		K_ASCII_243 = 0x8E,
		K_ASCII_246 = 0x8F,
		K_ASCII_248 = 0x90,
		K_ASCII_249 = 0x91,
		K_ASCII_250 = 0x92,
		K_ASCII_252 = 0x93,
		K_END_ASCII_CHARS = 0x94,
		K_COMMAND = 0x96,
		K_CAPSLOCK = 0x97,
		K_POWER = 0x98,
		K_PAUSE = 0x99,
		K_UPARROW = 0x9A,
		K_DOWNARROW = 0x9B,
		K_LEFTARROW = 0x9C,
		K_RIGHTARROW = 0x9D,
		K_ALT = 0x9E,
		K_CTRL = 0x9F,
		K_SHIFT = 0xA0,
		K_INS = 0xA1,
		K_DEL = 0xA2,
		K_PGDN = 0xA3,
		K_PGUP = 0xA4,
		K_HOME = 0xA5,
		K_END = 0xA6,
		K_F1 = 0xA7,
		K_F2 = 0xA8,
		K_F3 = 0xA9,
		K_F4 = 0xAA,
		K_F5 = 0xAB,
		K_F6 = 0xAC,
		K_F7 = 0xAD,
		K_F8 = 0xAE,
		K_F9 = 0xAF,
		K_F10 = 0xB0,
		K_F11 = 0xB1,
		K_F12 = 0xB2,
		K_F13 = 0xB3,
		K_F14 = 0xB4,
		K_F15 = 0xB5,
		K_KP_HOME = 0xB6,
		K_KP_UPARROW = 0xB7,
		K_KP_PGUP = 0xB8,
		K_KP_LEFTARROW = 0xB9,
		K_KP_5 = 0xBA,
		K_KP_RIGHTARROW = 0xBB,
		K_KP_END = 0xBC,
		K_KP_DOWNARROW = 0xBD,
		K_KP_PGDN = 0xBE,
		K_KP_ENTER = 0xBF,
		K_KP_INS = 0xC0,
		K_KP_DEL = 0xC1,
		K_KP_SLASH = 0xC2,
		K_KP_MINUS = 0xC3,
		K_KP_PLUS = 0xC4,
		K_KP_NUMLOCK = 0xC5,
		K_KP_STAR = 0xC6,
		K_KP_EQUALS = 0xC7,
		K_MOUSE1 = 0xC8,
		K_MOUSE2 = 0xC9,
		K_MOUSE3 = 0xCA,
		K_MOUSE4 = 0xCB,
		K_MOUSE5 = 0xCC,
		K_MWHEELDOWN = 0xCD,
		K_MWHEELUP = 0xCE,
		K_AUX1 = 0xCF,
		K_AUX2 = 0xD0,
		K_AUX3 = 0xD1,
		K_AUX4 = 0xD2,
		K_AUX5 = 0xD3,
		K_AUX6 = 0xD4,
		K_AUX7 = 0xD5,
		K_AUX8 = 0xD6,
		K_AUX9 = 0xD7,
		K_AUX10 = 0xD8,
		K_AUX11 = 0xD9,
		K_AUX12 = 0xDA,
		K_AUX13 = 0xDB,
		K_AUX14 = 0xDC,
		K_AUX15 = 0xDD,
		K_AUX16 = 0xDE,
		K_LAST_KEY = 0xDF,
	};

	// The menu code needs to get both key and char events, but
	// to avoid duplicating the paths, the char events are just
	// distinguished by or'ing in K_CHAR_FLAG (ugly)
#define	K_CHAR_FLAG		1024

	struct gentity_t;

	struct trajectory_t
	{
		char trType;
		int trTime;
		int trDuration;
		vec3_t trBase;
		vec3_t trDelta;
	};

	struct LerpEntityStateTurret
	{
		vec3_t gunAngles;
		int ownerNum;
		float heatVal;
		int overheating;
		float pivotOffset;
		int flags;
	};

	struct LerpEntityStateLoopFx
	{
		float cullDist;
		int period;
	};

	union LerpEntityStateActor_index
	{
		int actorNum;
		int corpseNum;
	};

	struct LerpEntityStateActor_proneInfo
	{
		__int16 fBodyPitch;
	};

	struct LerpEntityStateActor
	{
		LerpEntityStateActor_index index;
		int species;
		int team;
		int enemy;
		int freeCameraLockOnAllowed;
		LerpEntityStateActor_proneInfo proneInfo;
		unsigned __int16 aiType;
	};

	struct LerpEntityStatePrimaryLight
	{
		char colorAndExp[4];
		float intensity;
		float radius;
		float cosHalfFovOuter;
		float cosHalfFovInner;
		unsigned int mixerIndex;
	};

	union Weapon
	{
		unsigned int weaponData;
	};

	struct LerpEntityStatePlayer
	{
		float leanf;
		int movementDir;
		int moveType;
		Weapon primaryWeapon;
		Weapon stowedWeapon;
		Weapon offhandWeapon;
		Weapon meleeWeapon;
		char meleeWeaponCamo;
		char meleeWeaponModel;
		char vehicleType;
		char vehicleAnimBoneIndex;
		char vehicleSeat;
		char stowedWeaponCamo;
		char weaponHeat;
		char proneLegsAngle;
	};

	struct LerpEntityStateVehicleGunnerAngles
	{
		__int16 pitch;
		__int16 yaw;
	};

	struct LerpEntityStateVehicleRotorArm
	{
		__int16 pitch;
		__int16 roll;
	};

	union $DDE6850FA3B86A9C87C6DBFCDF4AD649
	{
		LerpEntityStateVehicleGunnerAngles gunnerAngles[4];
		LerpEntityStateVehicleRotorArm rotors[4];
	};

	union $ABF14481B6CB3C635AAEF83DF0F35947
	{
		__int16 throttle;
		__int16 bodyPitch;
	};

	struct LerpEntityStateVehicle
	{
		float steerYaw;
		float bodyRoll;
		$DDE6850FA3B86A9C87C6DBFCDF4AD649 ___u2;
		$ABF14481B6CB3C635AAEF83DF0F35947 ___u3;
		__int16 gunPitch;
		__int16 gunYaw;
		char targetRotorSpeed;
	};

	struct LerpEntityStateMissile
	{
		int launchTime;
		int parentClientNum;
		int fuseTime;
		int forcedDud;
		float autoDetonateTime;
	};

	struct LerpEntityStateScriptMover
	{
		char attachTagIndex[4];
		int attachedTagIndex;
		__int16 attachModelIndex[4];
		__int16 animScriptedAnim;
		__int16 attachedEntNum;
		int attachedEntTime;
		__int16 exploderIndex;
		unsigned __int16 scale;
		char flags;
		unsigned __int16 aiType;
	};

	struct LerpEntityStateBulletHit
	{
		vec3_t start;
	};

	struct LerpEntityStateEarthquake
	{
		float scale;
		float radius;
		int duration;
	};

	struct LerpEntityStateCustomExplode
	{
		int startTime;
		int effectIndex;
	};

	struct LerpEntityStateExplosion
	{
		float innerRadius;
		float magnitude;
		float innerDamage;
		int dummy;
		float outerDamage;
	};

	struct LerpEntityStateExplosionJolt
	{
		float innerRadius;
		vec3_t impulse;
	};

	struct LerpEntityStateJetThrust
	{
		vec3_t thrustDir;
		int dummy;
		float dotLimit;
	};

	struct LerpEntityStatePhysicsJitter
	{
		float innerRadius;
		float minDisplacement;
		float maxDisplacement;
	};

	struct LerpEntityStateDestructibleHit
	{
		unsigned int modelState[3];
	};

	struct LerpEntityStateCreateDynEnt
	{
		int model;
		int fxId;
		int mature;
	};

	struct LerpEntityStateStreamerHint
	{
		float factor;
	};

	struct LerpEntityStateZBarrierPiece
	{
		char flags;
		char animTime;
	};

	struct LerpEntityStateZBarrier
	{
		unsigned int barrierTypeIndex;
		LerpEntityStateZBarrierPiece pieces[6];
	};

	struct LerpEntityStateAnonymous
	{
		int data[9];
	};

	union LerpEntityStateTypeUnion
	{
		LerpEntityStateTurret turret;
		LerpEntityStateLoopFx loopFx;
		LerpEntityStateActor actor;
		LerpEntityStatePrimaryLight primaryLight;
		LerpEntityStatePlayer player;
		LerpEntityStateVehicle vehicle;
		LerpEntityStateMissile missile;
		LerpEntityStateScriptMover scriptMover;
		LerpEntityStateBulletHit bulletHit;
		LerpEntityStateEarthquake earthquake;
		LerpEntityStateCustomExplode customExplode;
		LerpEntityStateExplosion explosion;
		LerpEntityStateExplosionJolt explosionJolt;
		LerpEntityStateJetThrust jetThrust;
		LerpEntityStatePhysicsJitter physicsJitter;
		LerpEntityStateDestructibleHit destructibleHit;
		LerpEntityStateCreateDynEnt createDynEnt;
		LerpEntityStateStreamerHint streamerHint;
		LerpEntityStateZBarrier zbarrier;
		LerpEntityStateAnonymous anonymous;
	};

	union LerpEntityState_faction
	{
		char iHeadIconTeam;
		__int16 teamAndOwnerIndex;
	};

	struct LerpEntityState
	{
		int eFlags;
		int eFlags2;
		trajectory_t pos;
		trajectory_t apos;
		LerpEntityStateTypeUnion u;
		__int16 useCount;
		LerpEntityState_faction faction;
		unsigned int clientFields;
	};

	struct renderOptions_s
	{
		unsigned int s;
	};

	struct actorAnimState_t
	{
		__int16 state;
		char subState;
		float fLeanAmount;
		float fAimUpDown;
		float fAimLeftRight;
	};

	struct playerAnimState_t
	{
		int legsAnim;
		int torsoAnim;
		float fTorsoPitch;
		float fWaistPitch;
	};

	struct vehicleState_t
	{
		__int16 flags;
		char vehicleDefIndex;
		char treeId;
		__int16 animId;
		__int16 attachModelIndex[2];
		char attachTagIndex[2];
	};

	struct hardlineHint_t
	{
		char team;
		char perk;
		char hint;
	};

	struct scriptMoverState_t
	{
		char fov;
		char treeId;
		__int16 animId;
	};

	struct fxLightingState_t
	{
		float primaryLightFraction;
		int lightingOriginOffset;
	};

	union entityState_s_un2
	{
		actorAnimState_t animState;
		playerAnimState_t anim;
		vehicleState_t vehicleState;
		hardlineHint_t hardline;
		scriptMoverState_t moverState;
		fxLightingState_t fx;
	};

	union entityState_s_un3
	{
		int hintString;
		int vehicleXModel;
		unsigned int secondBcAlias;
		unsigned int soundTag;
	};

	struct clientLinkInfo_t
	{
		__int16 parentEnt;
		char tagIndex;
		char flags;
	};

	union entityState_s_index
	{
		__int16 brushmodel;
		__int16 xmodel;
		__int16 primaryLight;
		unsigned __int16 bone;
	};

	union entityState_s_un1
	{
		char scale;
		char eventParm2;
		char helicopterStage;
		char destructibleid;
		char zombieShrinkOn;
	};

	struct entityState_s
	{
		int number;
		LerpEntityState lerp;
		int time2;
		unsigned int loopSoundId;
		int solid;
		renderOptions_s renderOptions;
		entityState_s_un2 un2;
		entityState_s_un3 un3;
		unsigned int partBits[5];
		clientLinkInfo_t clientLinkInfo;
		int clientMask[1];
		char events[4];
		unsigned int eventParms[4];
		unsigned int eventParm;
		__int16 eType;
		__int16 groundEntityNum;
		entityState_s_index index;
		__int16 otherEntityNum;
		__int16 attackerEntityNum;
		__int16 enemyModel;
		Weapon weapon;
		Weapon lastStandPrevWeapon;
		unsigned __int16 targetname;
		__int16 loopSoundFade;
		__int16 eventSequence;
		char surfType;
		char clientNum;
		char iHeadIcon;
		char weaponModel;
		entityState_s_un1 un1;
	};

	struct EntHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	struct entityShared_t
	{
		char linked;
		char bmodel;
		char svFlags;
		char inuse;
		int broadcastTime;
		vec3_t mins;
		vec3_t maxs;
		int contents;
		vec3_t absmin;
		vec3_t absmax;
		vec3_t currentOrigin;
		vec3_t currentAngles;
		EntHandle ownerNum;
		int eventTime;
	};

	struct PlayerVehicleState
	{
		vec3_t origin;
		vec3_t angles;
		vec3_t velocity;
		vec3_t angVelocity;
		vec2_t tilt;
		vec2_t tiltVelocity;
		float targetHeightDelta;
		float lastGroundHeight;
		int entity;
		int flags;
		bool fullPhysics;
	};

	enum ClientNum_t
	{
		INVALID_CLIENT_INDEX = 0xFFFFFFFF,
		CLIENT_INDEX_FIRST = 0x0,
		CLIENT_INDEX_0 = 0x0,
		CLIENT_INDEX_1 = 0x1,
		CLIENT_INDEX_2 = 0x2,
		CLIENT_INDEX_3 = 0x3,
		CLIENT_INDEX_4 = 0x4,
		CLIENT_INDEX_5 = 0x5,
		CLIENT_INDEX_6 = 0x6,
		CLIENT_INDEX_7 = 0x7,
		CLIENT_INDEX_8 = 0x8,
		CLIENT_INDEX_9 = 0x9,
		CLIENT_INDEX_10 = 0xA,
		CLIENT_INDEX_11 = 0xB,
		CLIENT_INDEX_12 = 0xC,
		CLIENT_INDEX_13 = 0xD,
		CLIENT_INDEX_14 = 0xE,
		CLIENT_INDEX_15 = 0xF,
		CLIENT_INDEX_16 = 0x10,
		CLIENT_INDEX_17 = 0x11,
		CLIENT_INDEX_18 = 0x12,
		CLIENT_INDEX_19 = 0x13,
		CLIENT_INDEX_20 = 0x14,
		CLIENT_INDEX_21 = 0x15,
		CLIENT_INDEX_22 = 0x16,
		CLIENT_INDEX_23 = 0x17,
		CLIENT_INDEX_24 = 0x18,
		CLIENT_INDEX_25 = 0x19,
		CLIENT_INDEX_26 = 0x1A,
		CLIENT_INDEX_27 = 0x1B,
		CLIENT_INDEX_28 = 0x1C,
		CLIENT_INDEX_29 = 0x1D,
		CLIENT_INDEX_30 = 0x1E,
		CLIENT_INDEX_31 = 0x1F,
		CLIENT_INDEX_COUNT = 0x12,
	};

	enum OffhandSecondaryClass
	{
		PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
		PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
		PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
	};

	enum OffhandPrimaryClass
	{
		PLAYER_OFFHAND_PRIMARY_FRAG = 0x0,
		PLAYER_OFFHAND_PRIMARY_GEAR = 0x1,
		PLAYER_OFFHAND_PRIMARIES_TOTAL = 0x2,
	};

	struct PlayerHeldWeapon
	{
		Weapon weapon;
		renderOptions_s options;
		float heatPercent;
		int fuelTankTime;
		int adsZoomSelect;
		bool overHeating;
		bool needsRechamber;
		bool heldBefore;
		bool quickReload;
		bool blockWeaponPickup;
		char model;
	};

	struct AmmoPool
	{
		int count;
	};

	struct AmmoClip
	{
		int count;
	};

	enum ViewLockTypes
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	};

	enum locSel_t
	{
		LOC_SEL_NONE = 0x0,
		LOC_SEL_ARTILLERY = 0x1,
		LOC_SEL_AIRSTRIKE = 0x2,
		LOC_SEL_MORTAR = 0x3,
		LOC_SEL_NAPALM = 0x4,
		LOC_SEL_COMLINK = 0x5,
	};

	struct SprintState
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
		int sprintDuration;
		int sprintCooldown;
	};

	struct MantleState
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};

	enum ActionSlotType
	{
		ACTIONSLOTTYPE_DONOTHING = 0x0,
		ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
		ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
		ACTIONSLOTTYPE_NIGHTVISION = 0x3,
		ACTIONSLOTTYPECOUNT = 0x4,
	};

	struct ActionSlotParam_SpecifyWeapon
	{
		Weapon weapon;
	};

	struct ActionSlotParam
	{
		ActionSlotParam_SpecifyWeapon specifyWeapon;
	};

	enum objectiveState_t
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_NUMSTATES = 0x3,
	};

	struct objective_t
	{
		objectiveState_t state;
		vec3_t origin;
		__int16 entNum;
		vec2_t size;
		int icon;
		__int16 ownerNum;
		unsigned __int16 name;
		__int16 teamMask;
		char progress;
		int clientUseMask[1];
		char gamemodeFlags;
		char flags;
		char teamNum;
	};

	struct $C96EA5EC2ACBB9C0BF22693F316ACC67
	{
		char r;
		char g;
		char b;
		char a;
	};

	union hudelem_color_t
	{
		$C96EA5EC2ACBB9C0BF22693F316ACC67 _s0;
		int rgba;
	};

	struct hudelem_s
	{
		float x;
		float y;
		float z;
		float fontScale;
		float fromFontScale;
		int fontScaleStartTime;
		hudelem_color_t color;
		hudelem_color_t fromColor;
		int fadeStartTime;
		int scaleStartTime;
		float fromX;
		float fromY;
		int moveStartTime;
		int time;
		int duration;
		float value;
		float sort;
		hudelem_color_t glowColor;
		int fxBirthTime;
		unsigned int flags;
		__int16 targetEntNum;
		__int16 fontScaleTime;
		__int16 fadeTime;
		__int16 label;
		__int16 width;
		__int16 height;
		__int16 fromWidth;
		__int16 fromHeight;
		__int16 scaleTime;
		__int16 moveTime;
		__int16 text;
		unsigned __int16 fxLetterTime;
		unsigned __int16 fxDecayStartTime;
		unsigned __int16 fxDecayDuration;
		unsigned __int16 fxRedactDecayStartTime;
		unsigned __int16 fxRedactDecayDuration;
		char type;
		char font;
		char alignOrg;
		char alignScreen;
		char materialIndex;
		char offscreenMaterialIdx;
		char fromAlignOrg;
		char fromAlignScreen;
		char soundID;
		char ui3dWindow;
	};

	struct playerState_s_hud
	{
		hudelem_s current[31];
		hudelem_s archival[31];
	};

	struct playerState_s
	{
		int commandTime;
		int pm_type;
		int bobCycle;
		int pm_flags;
		__int64 weapFlags;
		int otherFlags;
		int pm_time;
		unsigned int loopSoundId;
		int loopSoundFade;
		vec3_t origin;
		vec3_t velocity;
		int remoteEyesEnt;
		int remoteEyesTagname;
		int remoteControlEnt;
		int weaponTime;
		int weaponDelay;
		int weaponTimeLeft;
		int weaponDelayLeft;
		int weaponIdleTime;
		int grenadeTimeLeft;
		int throwBackGrenadeOwner;
		int throwBackGrenadeTimeLeft;
		int weaponRestrictKickTime;
		bool mountAvailable;
		bool bRunLeftGun;
		bool bCarryingTurret;
		vec3_t mountPos;
		float mountDir;
		bool bThirdPerson;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		vec3_t delta_angles;
		int groundEntityNum;
		int moverEntityNum;
		int moverTimestamp;
		int groundType;
		vec3_t vLadderVec;
		int jumpTime;
		float jumpOriginZ;
		int slideTime;
		int moveType;
		int legsTimer;
		int torsoTimer;
		__int16 legsAnim;
		__int16 torsoAnim;
		int legsAnimDuration;
		int torsoAnimDuration;
		int damageTimer;
		int damageDuration;
		int dmgDirection;
		int dmgType;
		int corpseIndex;
		int movementDir;
		int eFlags;
		int eFlags2;
		PlayerVehicleState vehicleState;
		__int16 predictableEventSequence;
		__int16 predictableEventSequenceOld;
		int predictableEvents[4];
		unsigned int predictableEventParms[4];
		__int16 unpredictableEventSequence;
		__int16 unpredictableEventSequenceOld;
		int unpredictableEvents[4];
		unsigned int unpredictableEventParms[4];
		ClientNum_t clientNum;
		Weapon offHandWeapon;
		OffhandSecondaryClass offhandSecondary;
		OffhandPrimaryClass offhandPrimary;
		renderOptions_s renderOptions;
		int momentum;
		Weapon weapon;
		Weapon lastStandPrevWeapon;
		Weapon lastWeaponAltModeSwitch;
		Weapon stowedWeapon;
		char unusedCompatibilityPadding;
		Weapon meleeWeapon;
		int weaponstate;
		int weaponstateLeft;
		unsigned int weaponShotCount;
		unsigned int weaponShotCountLeft;
		float fWeaponPosFrac;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		float weaponSpinLerp;
		int viewmodelIndex;
		vec3_t viewangles;
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		vec2_t viewAngleClampBase;
		vec2_t viewAngleClampRange;
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int stats[4];
		PlayerHeldWeapon heldWeapons[15];
		AmmoPool ammoNotInClip[15];
		AmmoClip ammoInClip[15];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		ViewLockTypes viewlocked;
		__int16 viewlocked_entNum;
		int vehiclePos;
		int vehicleType;
		int vehicleAnimBoneIndex;
		int linkFlags;
		vec3_t linkAngles;
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int cursorHintWeapon;
		int iCompassPlayerInfo;
		unsigned int spyplaneTypeEnabled;
		unsigned int satelliteTypeEnabled;
		int locationSelectionInfo;
		locSel_t locationSelectionType;
		SprintState sprintState;
		int lastDtpEnd;
		float fTorsoPitch;
		float fWaistPitch;
		float holdBreathScale;
		int holdBreathTimer;
		int chargeShotTimer;
		unsigned int chargeShotLevel;
		unsigned int shotsFiredFromChamber;
		float quickScopeScale;
		int quickScopeTimer;
		unsigned int clientFields;
		unsigned int clientFields2;
		unsigned int clientFields3;
		unsigned int entityStateClientFields;
		float moveSpeedScaleMultiplier;
		MantleState mantleState;
		int vehicleAnimStage;
		int vehicleEntryPoint;
		unsigned int scriptedAnim;
		int scriptedAnimTime;
		int meleeChargeEnt;
		int meleeChargeDist;
		int meleeChargeTime;
		int weapLockFlags;
		int weapLockedEntnum;
		unsigned int airburstMarkDistance;
		unsigned int perks[2];
		ActionSlotType actionSlotType[4];
		ActionSlotParam actionSlotParam[4];
		Weapon inventoryWeapon;
		__int16 wiiumoteAimX;
		__int16 wiiumoteAimY;
		char wiiuControllerType;
		char vehicleDefIndex;
		int entityEventSequence;
		int weapAnim;
		int weapAnimLeft;
		float aimSpreadScale;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		int waterlevel;
		int smokeColorIndex;
		int hudElemLastAssignedSoundID;
		int adsZoomSelect;
		int adsZoomLatchTime;
		bool adsZoomLatchState;
		int adsPrevZoomSelect;
		int adsPrevZoomSelectTime;
		int artilleryInboundIconLocation;
		float visionSetLerpRatio;
		int poisoned;
		int binoculars;
		int scriptCursorHintString;
		objective_t objective[32];
		int deltaTime;
		int killCamEntity;
		int killCamTargetEntity;
		int introShotsFired;
		playerState_s_hud hud;
	};

	enum sessionState_t
	{
		SESS_STATE_PLAYING = 0x0,
		SESS_STATE_DEAD = 0x1,
		SESS_STATE_SPECTATOR = 0x2,
		SESS_STATE_INTERMISSION = 0x3,
	};

	enum clientConnected_t
	{
		CON_DISCONNECTED = 0x0,
		CON_CONNECTING = 0x1,
		CON_CONNECTED = 0x2,
	};

	template <size_t bits>
	struct bitarray
	{
		int array[bits / 32];
	};

	union $60971AFD306BE716C67F4ED6B7576D56
	{
		float rollmove;
		__int16 damageKick[2];
	};

#pragma pack(push, 1)
	struct usercmd_s
	{
		int serverTime;
		bitarray<64> button_bits;
		int angles[3];
		Weapon weapon;
		Weapon offHandWeapon;
		Weapon lastWeaponAltModeSwitch;
		char forwardmove;
		char rightmove;
		char upmove;
		char pitchmove;
		char yawmove;
		__int16 gunPitch;
		__int16 gunYaw;
		__int16 wiiumoteAimX;
		__int16 wiiumoteAimY;
		char wiiuControllerType;
		unsigned __int16 meleeChargeEnt;
		char meleeChargeDist;
		$60971AFD306BE716C67F4ED6B7576D56 ___u18;
		char selectedLocation[2];
		char selectedYaw;
		unsigned __int16 airburstMarkDistance;
		unsigned __int16 lastInput;
	};
#pragma pack(pop)

	struct playerTeamState_t
	{
		int location;
	};

	enum team_t
	{
		TEAM_FREE = 0x0,
		TEAM_BAD = 0x0,
		TEAM_ALLIES = 0x1,
		TEAM_AXIS = 0x2,
		TEAM_THREE = 0x3,
		TEAM_FOUR = 0x4,
		TEAM_FIVE = 0x5,
		TEAM_SIX = 0x6,
		TEAM_SEVEN = 0x7,
		TEAM_EIGHT = 0x8,
		TEAM_NUM_PLAYING_TEAMS = 0x9,
		TEAM_SPECTATOR = 0x9,
		TEAM_NUM_TEAMS = 0xA,
		TEAM_LOCALPLAYERS = 0xB,
		TEAM_FIRST_PLAYING_TEAM = 0x1,
		TEAM_LAST_PLAYING_TEAM = 0x8,
	};

	enum ffa_team_t
	{
		TEAM_FFA_NONE = 0x0,
		TEAM_FFA_AXIS = 0x1,
		TEAM_FFA_ALLIES = 0x2,
		TEAM_FFA_THREE = 0x3,
	};

	union $137F9095F7597C63EB19E8F61F5887B0
	{
		int prestige;
		int lastDaysPlayed;
	};

	struct netUInt64
	{
		unsigned int low;
		unsigned int high;
	};

	union $BA4CE55F498CD55FA8AE89CF1967B938
	{
		unsigned __int64 xuid;
		netUInt64 xuid64;
	};

	union $5A03B06D77C49A0599F537661E2DFCE9
	{
		unsigned __int64 leagueTeamID;
		netUInt64 leagueTeamID64;
	};

	union $C87BBC0E10708D6368CF77B7E7A71262
	{
		unsigned __int64 leagueSubdivisionID;
		netUInt64 leagueSubdivisionID64;
	};

	enum VehicleAnimState
	{
		VEHICLEANIMSTATE_IDLE = 0x0,
		VEHICLEANIMSTATE_ENTRY = 0x1,
		VEHICLEANIMSTATE_CHANGEPOS = 0x2,
		VEHICLEANIMSTATE_EXIT = 0x3,
		VEHICLEANIMSTATECOUNT = 0x4,
	};

	struct score_s
	{
		int ping;
		int status_icon;
		int place;
		int score;
		int kills;
		int assists;
		int deaths;
		int wagerWinnings;
		int scoreboardColumns[5];
		int downs;
		int revives;
		int headshots;
		int scoreMultiplier;
		int currentStreak;
	};

	struct clientState_s
	{
		ClientNum_t clientIndex;
		team_t team;
		ffa_team_t ffaTeam;
		int modelindex;
		int riotShieldNext;
		int attachModelIndex[6];
		int attachTagIndex[6];
		char name[32];
		float maxSprintTimeMultiplier;
		int rank;
		$137F9095F7597C63EB19E8F61F5887B0 ___u10;
		int lastDamageTime;
		int lastStandStartTime;
		int turnedHumanTime;
		int beingRevived;
		$BA4CE55F498CD55FA8AE89CF1967B938 ___u15;
		$5A03B06D77C49A0599F537661E2DFCE9 ___u16;
		int leagueDivisionID;
		$C87BBC0E10708D6368CF77B7E7A71262 ___u18;
		int leagueSubdivisionRank;
		unsigned int perks[2];
		int voiceConnectivityBits;
		char clanAbbrev[8];
		int attachedVehEntNum;
		int attachedVehSeat;
		int needsRevive;
		int clanAbbrevEV;
		VehicleAnimState vehAnimState;
		score_s score;
		int clientUIVisibilityFlags;
		int offhandWeaponVisible;
	};

	struct clientSession_t
	{
		sessionState_t sessionState;
		ClientNum_t forceSpectatorClient;
		int killCamEntity;
		int killCamTargetEntity;
		int archiveTime;
		unsigned __int16 scriptPersId;
		clientConnected_t connected;
		usercmd_s cmd;
		usercmd_s oldcmd;
		int localClient;
		int predictItemPickup;
		char newnetname[32];
		int maxHealth;
		int enterTime;
		playerTeamState_t teamState;
		int voteCount;
		int teamVoteCount;
		float moveSpeedScaleMultiplier;
		int viewmodelIndex;
		int noSpectate;
		int teamInfo;
		clientState_s cs;
		int psOffsetTime;
		int scoreboardColumnCache[26];
	};

	struct viewClamp
	{
		vec2_t start;
		vec2_t current;
		vec2_t goal;
	};

	struct viewClampState
	{
		viewClamp min;
		viewClamp max;
		float accelTime;
		float decelTime;
		float totalTime;
		float startTime;
	};

	struct gclient_t
	{
		playerState_s ps;
		playerState_s lastPlayerPS;
		clientSession_t sess;
		ClientNum_t spectatorClient;
		int flags;
		int lastCmdTime;
		bitarray<64> button_bits;
		bitarray<64> oldbutton_bits;
		bitarray<64> latched_button_bits;
		bitarray<64> button_bitsSinceLastFrame;
		float fGunPitch;
		float fGunYaw;
		int damage_blood;
		vec3_t damage_from;
		int damage_fromWorld;
		int inactivityTime;
		int inactivityWarning;
		int lastVoiceTime;
		int outWaterTime;
		int switchSeatTime;
		float currentAimSpreadScale;
		int dropWeaponTime;
		EntHandle pLookatEnt;
		vec4_t prevLinkedInvQuat;
		bool prevLinkAnglesSet;
		bool link_doCollision;
		bool link_useTagAnglesForViewAngles;
		bool link_useBaseAnglesForViewClamp;
		float linkAnglesFrac;
		viewClampState link_viewClamp;
		EntHandle useHoldEntity;
		int useHoldTime;
		int useButtonDone;
		int iLastCompassPlayerInfoEnt;
		int compassPingTime;
		int damageTime;
		float v_dmg_roll;
		float v_dmg_pitch;
		vec3_t swayViewAngles;
		vec3_t swayOffset;
		vec3_t swayAngles;
		vec3_t baseAngles;
		vec3_t baseOrigin;
		vec3_t recoilAngles;
		float fLastIdleFactor;
		int weaponIdleTime;
		vec3_t recoilSpeed;
		int previousRecoilTime;
		float previousRecoilRatio;
		int lastServerTime;
		int lastSpawnTime;
		Weapon lastWeapon;
		bool previouslyFiring;
		bool previouslyUsingNightVision;
		bool previouslyDTP;
		bool previouslyBeganWeaponRaise;
		bool previouslySprinting;
		unsigned int hasSpyplane;
		unsigned int hasSatellite;
		int revive;
		int reviveTime;
		int disallowVehicleUsage;
		unsigned __int16 attachShieldTagName;
		int lastStand;
		int lastStandTime;
	};

	struct ActorFlags
	{
		unsigned int allBits;
	};

	struct sentient_t
	{
		gentity_t *ent;
		team_t eTeam;
		EntHandle scriptOwner;
		int iThreatBias;
		int iThreatBiasGroupIndex;
		bool bIgnoreMe;
		bool bIgnoreAll;
		bool bIgnoreForFriendlyFire;
		bool originChanged;
		vec3_t oldOrigin;
		float maxVisibleDist;
		float surprisedByMeDistSq;
		int iEnemyNotifyTime;
		int attackerCount;
		EntHandle lastAttacker;
		EntHandle syncedMeleeEnt;
		EntHandle targetEnt;
		EntHandle scriptTargetEnt;
		unsigned __int16 scriptTargetTag;
		float entityTargetThreat;
		int meleeAttackerSpot[4];
		float attackerAccuracy;
		bool ignoreRandomBulletDamage;
		bool turretInvulnerability;
		pathnode_t *pClaimedNode;
		pathnode_t *pPrevClaimedNode;
		pathnode_t *pNearestNode;
		char bNearestNodeValid;
		char bNearestNodeBad;
		vec3_t vNearestNodeCheckPos;
		bool inuse;
		int banNodeTime;
		bool bInMeleeCharge;
	};

	enum AISpecies
	{
		AI_SPECIES_DOG = 0x0,
		AI_SPECIES_BIGDOG = 0x1,
		AI_SPECIES_ZOMBIE = 0x2,
		AI_SPECIES_ZOMBIE_DOG = 0x3,
		MAX_AI_SPECIES = 0x4,
		AI_SPECIES_ALL = 0x4,
	};

	enum ai_state_t
	{
		AIS_INVALID = 0x0,
		AIS_KEEPCURRENT = 0x0,
		AIS_EXPOSED = 0x1,
		AIS_TURRET = 0x2,
		AIS_GRENADE_RESPONSE = 0x3,
		AIS_BADPLACE_FLEE = 0x4,
		AIS_COVERARRIVAL = 0x5,
		AIS_DEATH = 0x6,
		AIS_DEFAULT = 0x1,
		AIS_SETABLE_FIRST = 0x1,
		AIS_SETABLE_LAST = 0x6,
		AIS_PAIN = 0x7,
		AIS_REACT = 0x8,
		AIS_SCRIPTEDANIM = 0x9,
		AIS_CUSTOMANIM = 0xA,
		AIS_NEGOTIATION = 0xB,
		AIS_PUSHABLE_FIRST = 0x7,
		AIS_PUSHABLE_LAST = 0xB,
		AIS_COUNT = 0xC,
	};

	enum ai_substate_t
	{
		STATE_EXPOSED_COMBAT = 0x64,
		STATE_EXPOSED_NONCOMBAT = 0x65,
		STATE_EXPOSED_REACQUIRE_MOVE = 0x66,
		STATE_EXPOSED_REACQUIRE_DONE = 0x67,
		STATE_EXPOSED_FLASHBANGED = 0x68,
		STATE_EXPOSED_REACTION = 0x69,
		STATE_DEATH_PRECLEANUP = 0xC8,
		STATE_DEATH_POSTCLEANUP = 0xC9,
		STATE_GRENADE_FLEE = 0x12C,
		STATE_GRENADE_TAKECOVER = 0x12D,
		STATE_GRENADE_COWER = 0x12E,
		STATE_GRENADE_COMBAT = 0x12F,
		STATE_GRENADE_COVERATTACK = 0x130,
		STATE_GRENADE_ACQUIRE = 0x131,
		STATE_GRENADE_THROWBACK = 0x132,
	};

	enum ai_state_transition_t
	{
		AIS_TRANSITION_CANONICAL = 0xFFFFFFFF,
		AIS_TRANSITION_NONE = 0x0,
		AIS_TRANSITION_SET = 0x1,
		AIS_TRANSITION_PUSH = 0x2,
		AIS_TRANSITION_POP = 0x3,
	};

	struct ai_transition_cmd_t
	{
		ai_state_transition_t eTransition;
		ai_state_t eState;
	};

	struct actorState_s
	{
		int actorIndex;
		int entityNum;
		int modelindex;
		int attachModelIndex[6];
		int attachTagIndex[6];
		unsigned int attachIgnoreCollision;
		char name[32];
		int animScriptedAnim;
	};

	struct ActorState
	{
		ai_state_t eState[6];
		ai_substate_t eSubState[6];
		unsigned int stateLevel;
		int iStateTime;
		int preThinkTime;
		ai_transition_cmd_t StateTransitions[13];
		unsigned int transitionCount;
		ai_state_t eSimulatedState[6];
		unsigned int simulatedStateLevel;
		actorState_s as;
	};

	struct ActorShoot
	{
		float accuracy;
		float playerSightAccuracy;
		unsigned int missCount;
		unsigned int hitCount;
		float debugLastAccuracy;
		int lastShotTime;
		bool lastCanShootEnemyResult;
		int lastCanShootEnemyTime;
		int bPerfectAim;
		int bIgnoreLocationalDamage;
		float debugWeaponAccuracy;
	};

	struct ActorOrientation
	{
		float fDesiredBodyYaw;
		float fLookPitch;
		float fLookYaw;
		vec3_t vLookForward;
		vec3_t vLookRight;
		vec3_t vLookUp;
		float yawVeloc;
		int allowPitchAngle;
		float turnRate;
		int bNotifyTurnDone;
		float maxFaceEnemyDistSq;
		char relativeDir;
		char prevRelativeDir;
		bool faceMotion;
		bool gunBlockedByWall;
		int dontTurnTime;
		bool lockScriptOrient;
		bool fixedLinkYawOnly;
	};

	enum ai_orient_mode_t
	{
		AI_ORIENT_INVALID = 0x0,
		AI_ORIENT_DONT_CHANGE = 0x1,
		AI_ORIENT_TO_MOTION = 0x2,
		AI_ORIENT_TO_ENEMY = 0x3,
		AI_ORIENT_TO_ENEMY_OR_MOTION = 0x4,
		AI_ORIENT_TO_ENEMY_OR_MOTION_SIDESTEP = 0x5,
		AI_ORIENT_TO_GOAL = 0x6,
		AI_ORIENT_COUNT = 0x7,
	};

	struct ai_orient_t
	{
		ai_orient_mode_t eMode;
		float fDesiredLookPitch;
		float fDesiredLookYaw;
		float fDesiredBodyYaw;
	};

	struct ActorPainDeath
	{
		int iPainTime;
		bool allowPain;
		bool blockingPain;
		bool allowDeath;
		bool delayedDeath;
		int iDamageTaken;
		int iDamageYaw;
		vec3_t damageDir;
		unsigned __int16 damageHitLoc;
		unsigned __int16 damageWeapon;
		unsigned __int16 damageMod;
		int deathContents;
		int bDropWeapon;
		bool forceRagdollImmediate;
		int minPainDamage;
		bool dieQuietly;
	};

	struct ActorProne
	{
		unsigned __int16 animProneLow;
		unsigned __int16 animProneLevel;
		unsigned __int16 animProneHigh;
		int bProneOK;
		float fInvProneAnimLowPitch;
		float fInvProneAnimHighPitch;
		float fProneLastDiff;
		char feetDirection;
	};

	union $A899A4A44C693354E5CF33C9EDFF92AE
	{
		float fTorsoPitch;
		float fBodyPitch;
	};

	union $8F7A1F2A0E788339D3BE9A175DA5EAEF
	{
		float fWaistPitch;
		float fBodyRoll;
	};

	struct actor_prone_info_s
	{
		bool bCorpseOrientation;
		bool orientPitch;
		bool prone;
		int iProneTime;
		int iProneTrans;
		float fBodyHeight;
		$A899A4A44C693354E5CF33C9EDFF92AE ___u6;
		$8F7A1F2A0E788339D3BE9A175DA5EAEF ___u7;
	};

	struct ActorCachedInfo
	{
		int time;
		vec3_t pos;
		vec3_t dir;
	};

	struct ActorLookAtInfo
	{
		vec3_t vLookAtPos;
		float fLookAtTurnAngle;
		float fLookAtTurnSpeed;
		float fLookAtTurnAccel;
		float fLookAtAnimYawLimit;
		float fLookAtYawLimit;
		unsigned __int16 animLookAtStraight;
		unsigned __int16 animLookAtLeft;
		unsigned __int16 animLookAtRight;
		bool bDoLookAt;
		bool bLookAtSetup;
		int iLookAtBlendEndTime;
		float fLookAtAnimBlendRate;
		float fLookAtLimitBlendRate;
	};

	struct ActorCoverArrivalInfo
	{
		int arrivalNotifyRequested;
		int animscriptOverrideRunTo;
		vec3_t animscriptOverrideRunToPos;
		vec2_t offsetIncrement;
		int offsetAdjustCount;
		float arrivalYaw;
		EntHandle scriptedArrivalEnt;
	};

	struct ActorNodeSelect
	{
		int numCoverNodesInGoal;
		int iPotentialCoverNodeCount;
		bool keepNodeDuringScriptedAnim;
		unsigned __int16 potentialCoverNode[10];
		unsigned __int16 potentialAmbushNode[32];
		int iPotentialAmbushNodeCount;
		int nextFindBestCoverTime;
		int coverSearchInterval;
		bool requestDifferentCover;
		bool keepClaimedNode;
		bool keepClaimedNodeIfValid;
		pathnode_t *pPotentialReacquireNode[10];
		int iPotentialReacquireNodeCount;
		pathnode_t *pPotentialCoverNode[32];
		bool doDangerReact;
		int dangerReactGoalTime;
		int dangerReactDuration;
	};

	struct ActorSight
	{
		float fovDot;
		float fMaxSightDistSqrd;
		int ignoreCloseFoliage;
		bool lastEnemySightPosValid;
		vec3_t lastEnemySightPos;
		vec3_t anglesToLikelyEnemyPath;
		int faceLikelyEnemyPathNeedCheckTime;
		int faceLikelyEnemyPathNeedRecalculateTime;
		pathnode_t *faceLikelyEnemyPathNode;
		int iTraceCount;
		unsigned __int16 vis_blockers[72];
		float fovDotBusy;
		int latency;
		float upAimLimit;
		float downAimLimit;
		float rightAimLimit;
		float leftAimLimit;
	};

	struct ActorString
	{
		unsigned __int16 properName;
		unsigned __int16 weaponName;
		unsigned __int16 primaryWeaponName;
		unsigned __int16 secondaryWeaponName;
		unsigned __int16 sideArmName;
		unsigned __int16 anim_pose;
		unsigned __int16 scriptState;
		unsigned __int16 lastScriptState;
		unsigned __int16 stateChangeReason;
		int iUseHintString;
	};

	struct ActorAnimSets
	{
		unsigned __int16 aimLow;
		unsigned __int16 aimLevel;
		unsigned __int16 aimHigh;
		unsigned __int16 shootLow;
		unsigned __int16 shootLevel;
		unsigned __int16 shootHigh;
	};

	enum ai_stance_e
	{
		STANCE_BAD = 0x0,
		STANCE_STAND = 0x1,
		STANCE_CROUCH = 0x2,
		STANCE_PRONE = 0x4,
		STANCE_ANY = 0x7,
	};

	struct scr_animscript_t
	{
		int func;
		int endFunc;
		unsigned __int16 name;
	};

	enum ai_traverse_mode_t
	{
		AI_TRAVERSE_INVALID = 0x0,
		AI_TRAVERSE_GRAVITY = 0x1,
		AI_TRAVERSE_NOGRAVITY = 0x2,
		AI_TRAVERSE_NOCLIP = 0x3,
		AI_TRAVERSE_COUNT = 0x4,
	};

	enum ai_animmode_t
	{
		AI_ANIM_UNKNOWN = 0x0,
		AI_ANIM_MOVE_CODE = 0x1,
		AI_ANIM_USE_POS_DELTAS = 0x2,
		AI_ANIM_USE_ANGLE_DELTAS = 0x3,
		AI_ANIM_USE_BOTH_DELTAS = 0x4,
		AI_ANIM_USE_BOTH_DELTAS_NOCLIP = 0x5,
		AI_ANIM_USE_BOTH_DELTAS_NOGRAVITY = 0x6,
		AI_ANIM_USE_BOTH_DELTAS_ZONLY_PHYSICS = 0x7,
		AI_ANIM_NOPHYSICS = 0x8,
		AI_ANIM_POINT_RELATIVE = 0x9,
	};

	struct ActorAnimation
	{
		ai_stance_e eAllowedStances;
		unsigned __int16 AnimScriptHandle;
		scr_animscript_t *pAnimScriptFunc;
		scr_animscript_t *pPrevAnimScriptFunc;
		scr_animscript_t AnimScriptSpecific;
		ai_traverse_mode_t eTraverseMode;
		char moveMode;
		bool useCombatScriptAtCover;
		bool prevAnimScriptTerminated;
		bool safeToChangeScript;
		bool bUseGoalWeight;
		ai_animmode_t eAnimMode;
		ai_animmode_t eScriptSetAnimMode;
		float fAnimTranslationScale;
	};

	struct pathpoint_t
	{
		vec3_t vOrigPoint;
		vec2_t fDir2D;
		float fOrigLength;
		int iNodeNum;
	};

	struct path_t
	{
		pathpoint_t pts[32];
		__int16 wPathLen;
		__int16 wOrigPathLen;
		__int16 wDodgeCount;
		__int16 wNegotiationStartNode;
		__int16 lookaheadNextNode;
		__int16 pathChangeNotifyNode;
		__int16 wDodgeEntity;
		vec3_t vFinalGoal;
		vec3_t vStartPos;
		vec3_t lookaheadDir;
		vec3_t lookaheadPos;
		float fLookaheadDist;
		float fLookaheadAmount;
		float fLookaheadDistToNextNode;
		int minLookAheadNodes;
		int flags;
		int iPathTime;
		int iPathClearedTime;
		team_t eTeam;
		float fCurrLength;
		vec3_t vCurrPoint;
		int iPathEndTime;
		float pathEndAnimDistSq;
		bool pathEndAnimNotified;
		bool lookaheadHitsStairs;
		bool useChokePoints;
		vec2_t pathChangeTracePos;
		int randomPercent;
		int owner;
		float physRadius;
		float physHeight;
	};

	struct path_trim_t
	{
		int iIndex;
		int iDelta;
	};

	enum ai_badplace_t
	{
		AI_BADPLACE_NONE = 0x0,
		AI_BADPLACE_NORMAL = 0x1,
		AI_BADPLACE_REALLYBAD = 0x2,
	};

	struct actor_t;

	struct ActorNavigation
	{
		float fWalkDist;
		float fWalkDistFacingMotion;
		float badPlaceAwareness;
		path_t Path;
		path_trim_t TrimInfo;
		int iFollowMin;
		int iFollowMax;
		float fInterval;
		int pathWaitTime;
		int iTeamMoveWaitTime;
		int iTeamMoveDodgeTime;
		int stoppedWaitStartTime;
		EntHandle stoppedWaitEnt;
		actor_t *pPileUpActor;
		gentity_t *pPileUpEnt;
		int bDontAvoidPlayer;
		float sideMove;
		bool noDodgeMove;
		int mayMoveTime;
		float nodeOffsetDist;
		vec3_t nodeOffsetPos;
		vec2_t prevMoveDir;
		float leanAmount;
		EntHandle pCloseEnt;
		ai_badplace_t aiBadPlace;
		bool isInBadPlace;
		char badplaceRecheckPathLen;
	};

	enum AlertLevel
	{
		AI_ALERTNESS_ASLEEP = 0x0,
		AI_ALERTNESS_NONCOMBAT = 0x1,
		AI_ALERTNESS_ALERT = 0x2,
		AI_ALERTNESS_COMBAT = 0x3,
		NUM_ALERT_LEVELS = 0x4,
	};

	enum CombatMode
	{
		AI_COMBAT_COVER = 0x0,
		AI_COMBAT_NO_COVER = 0x1,
		AI_COMBAT_COVER_ONLY = 0x2,
		AI_COMBAT_AMBUSH = 0x3,
		AI_COMBAT_AMBUSH_NODES_ONLY = 0x4,
		AI_COMBAT_EXPOSED_NODES_ONLY = 0x5,
		AI_COMBAT_ANY_EXPOSED_NODES_ONLY = 0x6,
		NUM_COMBAT_MODES = 0x7,
	};

	struct ActorCombat
	{
		int exposedStartTime;
		int exposedDuration;
		bool provideCoveringFire;
		scr_animscript_t *pAttackScriptFunc;
		float pathEnemyLookahead;
		float pathEnemyFightDist;
		float meleeAttackDist;
		bool useEnemyGoal;
		bool useMeleeAttackSpot;
		vec3_t goodShootPos;
		int goodShootPosValid;
		float engageMinDist;
		float engageMinFalloffDist;
		float engageMaxDist;
		float engageMaxFalloffDist;
		bool noGrenadeReturnThrow;
		AlertLevel alertLevel;
		CombatMode combatMode;
		int exposedResumeTime;
		int stopPathTime;
		int ambushStartTime;
		bool doingAmbush;
		bool currentAmbushNodeInvalid;
		bool allAmbushNodesFailed;
		bool noAttackerAccuracyMod;
		bool canFlank;
		bool isWounded;
		bool damageShield;
		float frontShieldAngleCos;
	};

	struct ActorReact
	{
		int iReactTime;
		int nextAllowedReactTime;
		bool allowReact;
		vec3_t reactOrigin;
		int lastHitTime;
		float newEnemyReactionDistSq;
		vec3_t newEnemyReactionPos;
		bool newEnemyReaction;
	};

	struct potential_threat_t
	{
		bool isEnabled;
		vec2_t direction;
	};

	struct ActorSecondaryTarget
	{
		EntHandle entity;
		vec2_t dirToEnt;
		float distToEnt;
		pathnode_t *node;
	};

	struct ActorThreat
	{
		int hasThreateningEnemy;
		int bPacifist;
		int iPacifistWait;
		potential_threat_t potentialThreat;
		int threatUpdateTime;
		SentientHandle pFavoriteEnemy;
		int bDrawOnCompass;
		int bActivateCrosshair;
		float highlyAwareRadius;
		bool ignoreExplosionEvents;
		int numSecondaryTarget;
		ActorSecondaryTarget secondaryTargets[2];
		bool allEnemiesInSimilarDir;
		int goodEnemyOnly;
		float footstepDetectDistSq;
		float footstepDetectDistWalkSq;
		float footstepDetectDistSprintSq;
	};

	struct ActorGrenade
	{
		float grenadeAwareness;
		EntHandle pGrenade;
		unsigned __int16 GrenadeTossMethod;
		int bGrenadeTossValid;
		int bGrenadeTargetValid;
		int iGrenadeAmmo;
		vec3_t vGrenadeTossPos;
		vec3_t vGrenadeTargetPos;
		vec3_t vGrenadeTossVel;
		EntHandle throwBackGrenadeKilledOriginalOwner;
		int bThrowbackGrenades;
		EntHandle pGrenadeFlee;
		int flashBanged;
		float flashBangedStrength;
		int flashBangImmunity;
		int grenadeExistTime;
		Weapon GrenadeWeapon;
		bool grenadeTossWithBounce;
		vec3_t pickupPos;
	};

	struct ActorTurret
	{
		gentity_t *pTurret;
		unsigned __int16 turretAnim;
		char turretAnimSet;
	};

	struct actor_goal_s
	{
		vec3_t pos;
		vec3_t ang;
		float radius;
		float height;
		pathnode_t *node;
		gentity_t *volume;
	};

	enum aiGoalSources
	{
		AI_GOAL_SRC_SCRIPT_GOAL = 0x0,
		AI_GOAL_SRC_SCRIPT_ENTITY_GOAL = 0x1,
		AI_GOAL_SRC_ENEMY = 0x2,
	};

	struct ActorGoal
	{
		actor_goal_s codeGoal;
		aiGoalSources codeGoalSrc;
		actor_goal_s scriptGoal;
		EntHandle scriptGoalEnt;
		bool goalPosChanged;
		bool commitToFixedNode;
		bool ignoreForFixedNodeSafeCheck;
		bool fixedNode;
		float fixedNodeSafeRadius;
		float fixedNodeSafeVolumeRadiusSq;
		EntHandle fixedNodeSafeVolume;
		int moveHistoryIndex;
		bool moveHistoryConsistent;
		vec2_t moveHistory[10];
	};

	struct ActorSuppression
	{
		int ignoreSuppression;
		int suppressionWait;
		int suppressionDuration;
		int suppressionStartTime;
		float suppressionMeter;
	};

	enum DelayedWeapDropState
	{
		ACTOR_WEAP_DROP_NONE = 0x0,
		ACTOR_WEAP_DROP_GRAB_INITIAL_VALUE = 0x1,
		ACTOR_WEAP_DROP_FINISH = 0x2,
	};

	struct ActorDelayedWeaponDrop
	{
		vec3_t matrix[4];
		int time;
		unsigned __int16 tagName;
		DelayedWeapDropState state;
		int weaponIndex;
	};

	struct vis_cache_t
	{
		bool bVisible;
		int iLastUpdateTime;
		int iLastVisTime;
	};

	struct sentient_info_t
	{
		vis_cache_t VisCache;
		int iLastAttackMeTime;
		int lastKnownPosTime;
		int attackTime;
		bool surprised;
		vec3_t vLastKnownPos;
		pathnode_t *pLastKnownNode;
		int iPathTestTime;
		bool bPathTestResult;
	};

	struct ai_suppression_t
	{
		int iTime;
		sentient_t *pSuppressor;
		vec3_t clipPlane;
		int movementOnly;
	};

	enum aiphys_t
	{
		AIPHYS_BAD = 0x0,
		AIPHYS_NORMAL_ABSOLUTE = 0x1,
		AIPHYS_NORMAL_RELATIVE = 0x2,
		AIPHYS_NOCLIP = 0x3,
		AIPHYS_NOGRAVITY = 0x4,
		AIPHYS_ZONLY_PHYSICS_RELATIVE = 0x5,
		AIPHYS_ZONLY_PHYSICS_ABSOLUTE = 0x6,
	};

	struct visitor_base_t;

	struct visitor_base_tVtbl
	{
		void *(__thiscall *__vecDelDtor)(visitor_base_t *_this, unsigned int);
	};

	struct visitor_base_t
	{
		visitor_base_tVtbl *vfptr;
	};

	union $21C1E9479C665B64954A8451F26470F1
	{
		CollisionAabbTree *tree;
		cbrush_t *brush;
	};

	struct col_prim_t
	{
		int type;
		$21C1E9479C665B64954A8451F26470F1 ___u1;
	};

	struct hybrid_vector
	{
		__m128 vec;
	};

	struct TraceCheckCount
	{
		unsigned __int16 global;
		unsigned __int16 *partitions;
		unsigned __int16 *brushes;
	};

	struct TraceThreadInfo
	{
		TraceCheckCount checkcount;
		cbrush_t *box_brush;
		cmodel_t *box_model;
		PhysGeomList **geoms;
	};

	struct colgeom_visitor_t
	{
		visitor_base_t baseclass_0;
		__declspec(align(16)) hybrid_vector m_mn;
		hybrid_vector m_mx;
		hybrid_vector m_p0;
		hybrid_vector m_p1;
		hybrid_vector m_delta;
		hybrid_vector m_rvec;
		float m_radius;
		int m_mask;
		TraceThreadInfo *m_threadInfo;
	};

	template <size_t count>
	struct __declspec(align(16)) colgeom_visitor_inlined_t
	{
		colgeom_visitor_t baseclass_0;
		int nprims;
		bool overflow;
		col_prim_t prims[count];
	};

	struct phys_vec3
	{
		float x;
		float y;
		float z;
		float w;
	};

	const struct cached_simplex_info
	{
		phys_vec3 m_indices[3];
	};

	struct phys_memory_heap
	{
		char *m_buffer_start;
		char *m_buffer_end;
		char *m_buffer_cur;
		char *m_user_start;
	};

	struct phys_vec2
	{
		float x;
		float y;
	};

	struct __declspec(align(16)) contact_manifold_mesh_point
	{
		phys_vec3 m_p;
		phys_vec2 m_contact_p;
	};

	struct __declspec(align(16)) phys_contact_manifold
	{
		phys_vec3 m_feature_normal;
		phys_vec3 m_feature_hitp;
		phys_vec3 m_feature_hitn;
		float m_feature_distance_eps;
		float m_sin_feautre_angular_eps_sq;
		int m_close_mesh_point_count;
		phys_memory_heap *m_allocator;
		contact_manifold_mesh_point *m_list_mesh_point;
		int m_list_mesh_point_count;
		contact_manifold_mesh_point **m_list_sorted_mesh_point;
		contact_manifold_mesh_point **m_list_contact_point;
		int m_list_contact_point_count;
	};

	struct phys_mat44;
	const struct phys_gjk_geom;

	struct phys_gjk_geomVtbl
	{
		void(__thiscall *support)(phys_gjk_geom *_this, phys_vec3 *, phys_vec3 *, phys_vec3 *);
		void(__thiscall *get_simplex)(phys_gjk_geom *_this, cached_simplex_info *, const int, phys_vec3 *, phys_vec3 *);
		void(__thiscall *set_simplex)(phys_gjk_geom *_this, phys_vec3 *, const int, phys_vec3 *, cached_simplex_info *);
		phys_vec3 *(__thiscall *get_center)(phys_gjk_geom *_this, phys_vec3 *result);
		void(__thiscall *get_feature)(phys_gjk_geom *_this, phys_contact_manifold *);
		const float(__thiscall *get_geom_radius)(phys_gjk_geom *_this);
		void(__thiscall *calc_aabb)(phys_gjk_geom *_this, phys_mat44 *, phys_vec3 *, phys_vec3 *);
		const bool(__thiscall *ray_cast)(phys_gjk_geom *_this, phys_vec3 *, phys_vec3 *, const float, float *, phys_vec3 *);
		bool(__thiscall *is_polyhedron)(phys_gjk_geom *_this);
	};

	const struct phys_gjk_geom
	{
		phys_gjk_geomVtbl *vfptr;
	};

	struct phys_mat44
	{
		phys_vec3 x;
		phys_vec3 y;
		phys_vec3 z;
		phys_vec3 w;
	};

	struct __declspec(align(16)) gjk_base_t
	{
		phys_gjk_geom baseclass_0;
		__declspec(align(16)) phys_vec3 m_aabb_mn_loc;
		phys_vec3 m_aabb_mx_loc;
		unsigned int m_gjk_geom_id;
		phys_mat44 *m_xform_;
		gjk_base_t *m_next_geom;
		unsigned int m_flags;
		int stype;
		int m_contents;
	};

	enum gjccc_create_type_e
	{
		CT_CYLINDER = 0x0,
		CT_COLLMAP = 0x1,
	};

	struct gjccc_create_t
	{
		gjccc_create_type_e type;
		vec3_t *mins;
		vec3_t *maxs;
		PhysGeomList *collmap;
	};

	const struct gjkcc_input_t
	{
		unsigned int gjkcc_id;
		bool is_server_thread;
		colgeom_visitor_inlined_t<300> *proximity_data;
		int proximity_mask;
		int m_ent_num;
		unsigned int m_gjk_query_flags;
		gjk_base_t *m_gjk_cg;
		phys_mat44 *m_mat;
		gjccc_create_t *create_info;
	};

	enum AI_STAIRS_STATE
	{
		AI_STAIRS_NONE = 0x0,
		AI_STAIRS_UP = 0x1,
		AI_STAIRS_DOWN = 0x2,
		NUM_STAIRS_STATES = 0x3,
	};

	struct actor_physics_t
	{
		vec3_t vOrigin;
		vec3_t vVelocity;
		unsigned __int16 groundEntNum;
		int iFootstepTimer;
		int bHasGroundPlane;
		float groundplaneSlope;
		int iSurfaceType;
		vec3_t vWishDelta;
		int bIsAlive;
		int iEntNum;
		aiphys_t ePhysicsType;
		float fGravity;
		int iMsec;
		vec3_t vMins;
		vec3_t vMaxs;
		bool prone;
		int iTraceMask;
		int foliageSoundTime;
		int iNumTouch;
		int iTouchEnts[32];
		int iHitEntnum;
		vec3_t vHitOrigin;
		vec3_t vHitNormal;
		char bStuck;
		char bDeflected;
		gjkcc_input_t *m_gjkcc_input;
		__declspec(align(16)) colgeom_visitor_inlined_t<300> proximity_data;
		bool pathGoingDown;
		AI_STAIRS_STATE stairsState;
		int groundEntityTimestamp;
	};

	struct ActorCoverInfluenceInfo
	{
		pathnode_t *node;
		float weightAdjust;
		int timeAdded;
	};

	struct __declspec(align(16)) actor_t
	{
		ActorFlags flags;
		gentity_t *ent;
		sentient_t *sentient;
		AISpecies species;
		ActorState state;
		ActorShoot shoot;
		ActorOrientation orientation;
		ai_orient_t CodeOrient;
		ai_orient_t ScriptOrient;
		ActorPainDeath painDeath;
		ActorProne prone;
		actor_prone_info_s ProneInfo;
		ActorCachedInfo eyeInfo;
		ActorCachedInfo muzzleInfo;
		ActorLookAtInfo lookAtInfo;
		ActorCoverArrivalInfo arrivalInfo;
		ActorNodeSelect nodeSelect;
		ActorSight sight;
		ActorString string;
		ActorAnimSets animSets;
		ActorAnimation anim;
		ActorNavigation navigation;
		ActorCombat combat;
		ActorReact react;
		ActorThreat threat;
		ActorGrenade grenade;
		ActorTurret turret;
		ActorGoal goal;
		ActorSuppression suppression;
		ActorDelayedWeaponDrop weapDrops[2];
		sentient_info_t sentientInfo[72];
		ai_suppression_t Suppressant[4];
		__declspec(align(16)) actor_physics_t Physics;
		const char *pszDebugInfo;
		ActorCoverInfluenceInfo cover_influencers[8];
	};

	enum TurretRotateState
	{
		TURRET_ROTATE_STOPPED = 0x0,
		TURRET_ROTATE_STOPPING = 0x1,
		TURRET_ROTATE_MOVING = 0x2,
	};

	struct TurretInfo
	{
		bool inuse;
		int state;
		int flags;
		int fireTime;
		EntHandle manualTarget;
		EntHandle target;
		vec3_t targetPos;
		int targetTime;
		vec3_t missOffsetNormalized;
		float arcmin[2];
		float arcmax[2];
		float initialYawmin;
		float initialYawmax;
		float forwardAngleDot;
		float dropPitch;
		float scanningPitch;
		int convergenceTime[2];
		int suppressTime;
		float maxRangeSquared;
		SentientHandle detachSentient;
		int stance;
		int prevStance;
		int fireSndDelay;
		float accuracy;
		vec3_t userOrigin;
		int prevSentTarget;
		float aiSpread;
		float playerSpread;
		team_t eTeam;
		float heatVal;
		bool overheating;
		int fireBarrel;
		float scanSpeed;
		float scanDecelYaw;
		int scanPauseTime;
		vec3_t originError;
		vec3_t anglesError;
		float pitchCap;
		int triggerDown;
		unsigned int fireSnd;
		unsigned int fireSndPlayer;
		unsigned int startFireSnd;
		unsigned int startFireSndPlayer;
		unsigned int loopFireEnd;
		unsigned int loopFireEndPlayer;
		unsigned int rotateLoopSnd;
		unsigned int rotateLoopSndPlayer;
		unsigned int rotateStopSnd;
		unsigned int rotateStopSndPlayer;
		int sndIsFiring;
		vec3_t targetOffset;
		float onTargetAngle;
		TurretRotateState turretRotateState;
		vec3_t previousAngles;
	};

	struct DestructibleBurnData
	{
		int burnTime;
		unsigned int fx;
		int sndId;
	};

	struct DESTRUCTIBLE_PIECE_INFO
	{
		__int16 health;
		int xdollHandle;
		unsigned int fx;
		DestructibleBurnData burnData;
	};

	struct DestructibleState
	{
		LerpEntityStateDestructibleHit state;
		int time;
	};

	struct Destructible
	{
		int entNum;
		DESTRUCTIBLE_PIECE_INFO *pieceArray;
		int oldestBurnTime;
		char destructiblePoseID;
		int pieceCount;
		DestructibleDef *ddef;
		unsigned int flags;
		DestructibleState states[5];
		char bHasBeenHit;
	};

	struct vehicle_spline_node_t
	{
		__int16 nextIdx;
		__int16 prevIdx;
		float length;
		vec3_t dir;
		float t;
	};

	struct vehicle_path_node_t
	{
		__int16 numLinks;
		__int16 firstLinkIndex;
	};

	union $985D68EE007AE70B9BF8699519B57281
	{
		vehicle_spline_node_t splineNode;
		vehicle_path_node_t pathNode;
	};

	struct vehicle_node_t
	{
		unsigned __int16 name;
		unsigned __int16 target;
		unsigned __int16 target2;
		unsigned __int16 script_linkname;
		unsigned __int16 script_noteworthy;
		__int16 index;
		int flags;
		float speed;
		float lookAhead;
		vec3_t origin;
		vec3_t angles;
		float radius;
		float tension;
		$985D68EE007AE70B9BF8699519B57281 ___u13;
	};

	struct vehicle_custom_path_t
	{
		__int16 pathOrder[128];
		__int16 pathLinkIdx[128];
		char inUse;
	};

	enum path_type_e
	{
		PT_OLD_SPLINE = 0x0,
		PT_SPLINE = 0x1,
	};

	struct vehicle_pathpos_t
	{
		__int16 nodeIdx;
		__int16 prevIdx;
		__int16 endOfPath;
		float frac;
		float speed;
		float lookAhead;
		float slide;
		float width;
		float manualTime;
		float widthLookAheadFrac;
		float distanceTraveled;
		vec3_t origin;
		vec3_t angles;
		vec3_t lookPos;
		vec3_t origin_on_spline;
		vec3_t angles_on_spline;
		vec3_t lookPos_on_spline;
		int use_spline_speed;
		vehicle_node_t switchNode[2];
		int flags;
		vehicle_custom_path_t *customPath;
		float customGoalLength;
		vec3_t customGoalDir;
		path_t *aiPath;
		path_type_e path_type;
		__int16 startNodeIdx;
		float t;
		float tot_len;
		float tot_time;
	};

	struct vehicle_physic_t
	{
		vec3_t origin;
		vec3_t prevOrigin;
		vec3_t angles;
		vec3_t prevAngles;
		vec3_t maxAngleVel;
		float yawAccel;
		float yawDecel;
		vec3_t mins;
		vec3_t maxs;
		vec3_t vel;
		vec3_t bodyVel;
		vec3_t rotVel;
		vec3_t accel;
		float maxPitchAngle;
		float maxRollAngle;
		float wheelZVel[6];
		float wheelZPos[6];
		int wheelSurfType[6];
		vec3_t bodyTilt;
		vec3_t worldTilt;
		vec3_t worldTiltVel;
		float heliLockHeight;
		float curveLength;
		int curveID;
		float curveStep;
		float curveTime;
		float timeStep;
	};

	enum VehicleMoveState
	{
		VEH_MOVESTATE_STOP = 0x0,
		VEH_MOVESTATE_MOVE = 0x1,
		VEH_MOVESTATE_HOVER = 0x2,
		VEH_MOVESTATE_PLANE_ONCURVE = 0x3,
		VEH_MOVESTATE_PLANE_FREE = 0x4,
	};

	enum VehicleTurretState
	{
		VEH_TURRET_STOPPED = 0x0,
		VEH_TURRET_STOPPING = 0x1,
		VEH_TURRET_MOVING = 0x2,
	};

	struct VehicleTurret
	{
		int fireTime;
		int fireBarrel;
		float barrelOffset;
		int flags;
		float heatVal;
		float turretOnTargetRange;
		int overheating;
		int weaponShotCount;
		VehicleTurretState turretState;
	};

	struct VehicleJitter
	{
		int jitterPeriodMin;
		int jitterPeriodMax;
		int jitterEndTime;
		vec3_t jitterOffsetRange;
		vec3_t jitterDeltaAccel;
		vec3_t jitterAccel;
		vec3_t jitterPos;
	};

	struct VehicleHover
	{
		float hoverRadius;
		float hoverSpeed;
		float hoverAccel;
		vec3_t hoverGoalPos;
		int useHoverAccelForAngles;
	};

	struct VehicleTarget
	{
		int valid;
		int hasTargetYaw;
		int targetEnt;
		int lookAtEnt;
		vec3_t targetOrigin;
		vec3_t targetOffset;
		float targetYaw;
	};

	struct VehicleGunnerTags
	{
		int turret;
		int barrel;
		int flash;
		int flash2;
	};

	struct VehicleTags
	{
		int player;
		int popout;
		int body;
		int turret;
		int turret_base;
		int barrel;
		int flash[4];
		VehicleGunnerTags gunnerTags[4];
		int wheel[6];
		int seats[11];
		int entryPoints[5];
	};

	struct VehicleSeat
	{
		int _occupantEntNum;
	};

	template <typename T>
	struct phys_link_list_base
	{
		T *m_next_link;
	};

	struct rigid_body;

	struct __declspec(align(16)) pulse_sum_node
	{
		phys_link_list_base<pulse_sum_node> baseclass_0;
		__declspec(align(16)) phys_mat44 m_world_inv_inertia;
		phys_vec3 t_vel;
		phys_vec3 a_vel;
		float m_inv_mass;
		rigid_body *m_rb;
	};

	struct rigid_body_constraint
	{
		rigid_body *b1;
		rigid_body *b2;
		rigid_body_constraint *m_next;
	};

	struct pulse_sum_cache
	{
		float m_pulse_sum;
	};

	struct __declspec(align(8)) rigid_body_constraint_point
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b1_r_loc;
		phys_vec3 m_b2_r_loc;
		pulse_sum_cache m_ps_cache_list[3];
		float m_stress;
		float m_spring_k;
		float m_damp_k;
		bool m_spring_enabled;
	};

	struct __declspec(align(16)) rigid_body_constraint_hinge
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b1_r_loc;
		phys_vec3 m_b2_r_loc;
		phys_vec3 m_b1_axis_loc;
		phys_vec3 m_b2_axis_loc;
		phys_vec3 m_b1_a1_loc;
		phys_vec3 m_b1_a2_loc;
		phys_vec3 m_b1_ref_loc;
		phys_vec3 m_b2_ref_min_loc;
		phys_vec3 m_b2_ref_max_loc;
		float m_damp_k;
		unsigned int m_flags;
		pulse_sum_cache m_ps_cache[8];
	};

	struct __declspec(align(16)) rigid_body_constraint_distance
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b1_r_loc;
		phys_vec3 m_b2_r_loc;
		float m_min_distance;
		float m_max_distance;
		float m_next_max_distance;
		float m_max_distance_vel;
		float m_damp_coef;
		unsigned int m_flags;
		pulse_sum_cache m_ps_cache_list[3];
	};

	struct __declspec(align(8)) ragdoll_joint_limit_info
	{
		phys_vec3 m_b1_ud_loc;
		float m_b1_ud_limit_co_;
		float m_b1_ud_limit_si_;
		float m_b1_ud_active_limit_co_;
	};

	struct __declspec(align(16)) rigid_body_constraint_ragdoll
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b1_r_loc;
		phys_vec3 m_b2_r_loc;
		unsigned int m_flags;
		pulse_sum_cache m_ps_cache_list[10];
		__declspec(align(8)) phys_vec3 m_b1_axis_loc;
		phys_vec3 m_b2_axis_loc;
		phys_vec3 m_b1_a1_loc;
		phys_vec3 m_b1_a2_loc;
		phys_vec3 m_b1_ref_loc;
		phys_vec3 m_b2_ref_min_loc;
		phys_vec3 m_b2_ref_max_loc;
		ragdoll_joint_limit_info m_joint_limits[2];
		int m_joint_limits_count;
		float m_damp_k;
	};

	struct __declspec(align(16)) pulse_sum_normal
	{
		phys_link_list_base<pulse_sum_normal> baseclass_0;
		__declspec(align(16)) phys_vec3 m_ud;
		phys_vec3 m_b1_r;
		phys_vec3 m_b2_r;
		phys_vec3 m_b1_ap;
		phys_vec3 m_b2_ap;
		float m_pulse_sum_min;
		float m_pulse_sum_max;
		float m_pulse_sum;
		float m_right_side;
		float m_big_dirt;
		float m_cfm;
		float m_denom;
		float m_pulse_limit_ratio;
		unsigned int m_flags;
		pulse_sum_normal *m_pulse_parent;
		pulse_sum_node *m_b1;
		pulse_sum_node *m_b2;
		pulse_sum_cache *m_pulse_sum_cache;
	};

	struct rigid_body_constraint_wheel
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b2_hitp_loc;
		phys_vec3 m_b2_hitn_loc;
		phys_vec3 m_b1_wheel_center_loc;
		phys_vec3 m_b1_suspension_dir_loc;
		phys_vec3 m_b1_wheel_axis_loc;
		float m_wheel_radius;
		float m_fwd_fric_k;
		float m_side_fric_k;
		float m_side_fric_max;
		float m_suspension_stiffness_k;
		float m_suspension_damp_k;
		float m_hard_limit_dist;
		float m_roll_stability_factor;
		float m_pitch_stability_factor;
		float m_turning_radius_ratio_max_speed;
		float m_turning_radius_ratio_accel;
		float m_desired_speed_k;
		float m_acceleration_factor_k;
		float m_braking_factor_k;
		float m_wheel_vel;
		float m_wheel_fwd;
		float m_wheel_pos;
		float m_wheel_displaced_center_dist;
		float m_wheel_normal_force;
		unsigned int m_wheel_state;
		unsigned int m_wheel_flags;
		pulse_sum_cache m_ps_cache_list[4];
		pulse_sum_normal *m_ps_suspension;
		pulse_sum_normal *m_ps_side_fric;
		pulse_sum_normal *m_ps_fwd_fric;
	};

	struct __declspec(align(16)) rigid_body_constraint_angular_actuator
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_mat44 m_target_mat;
		phys_mat44 m_next_target_mat;
		phys_vec3 m_a_vel;
		float m_power;
		float m_power_scale;
		bool m_enabled;
		pulse_sum_cache m_ps_cache_list[3];
	};

	struct __declspec(align(16)) rigid_body_constraint_upright
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_vec3 m_b1_forward_axis_loc;
		phys_vec3 m_b1_right_axis_loc;
		phys_vec3 m_b1_up_axis_loc;
		phys_vec3 m_b1_lean_axis_loc;
		phys_vec3 m_b2_up_axis_loc;
		phys_vec3 m_last_t_vel;
		phys_vec3 m_last_a_vel;
		float m_avg_side_force;
		float m_avg_normal_force;
		float m_lean_angle_calc_delta_t;
		float m_lean_angle;
		float m_lean_angle_multiplier;
		float m_max_lean_angle;
		float m_moving_average_total_time;
		bool m_enabled;
		pulse_sum_cache m_ps_cache_list[1];
	};

	struct rigid_body_constraint_custom_orientation
	{
		rigid_body_constraint baseclass_0;
		pulse_sum_cache m_ps_cache_list[5];
		bool m_active;
		bool m_no_orientation_correction;
		float m_torque_resistance_pitch_roll;
		float m_torque_resistance_yaw;
		float m_torque_resistance_yaw_max_collision_speed;
		float m_upright_strength;
	};

	struct user_rigid_body;

	struct __declspec(align(8)) rigid_body_constraint_custom_path
	{
		rigid_body_constraint baseclass_0;
		__declspec(align(8)) phys_mat44 m_path_mat;
		phys_vec3 b1_r_loc;
		user_rigid_body *m_urb;
		int m_timestamp;
		float m_spring_scale;
		pulse_sum_cache m_list_psc[4];
	};

	struct contact_point_info_pulse_sum_cache_info
	{
		pulse_sum_cache m_ps_cache_list[3];
	};

	struct __declspec(align(8)) broad_phase_base
	{
		phys_vec3 m_trace_aabb_min_whace;
		phys_vec3 m_trace_aabb_max_whace;
		phys_vec3 m_trace_translation;
		unsigned int m_flags;
		broad_phase_base *m_list_bpb_next;
		broad_phase_base *m_list_bpb_cluster_next;
		void *m_sap_node;
		void *m_user_data;
		unsigned int m_env_collision_flags;
		unsigned int m_my_collision_type_flags;
	};

	struct rigid_body;

	struct __declspec(align(8)) broad_phase_info
	{
		broad_phase_base baseclass_0;
		rigid_body *m_rb;
		phys_mat44 *m_rb_to_world_xform;
		phys_mat44 *m_cg_to_world_xform;
		phys_mat44 *m_cg_to_rb_xform;
		phys_gjk_geom *m_gjk_geom;
		unsigned int m_gjk_geom_id;
		int m_surface_type;
	};

	struct phys_gjk_geom_id_pair_key
	{
		unsigned int m_id1;
		unsigned int m_id2;
	};

	struct phys_gjk_cache_info
	{
		phys_vec3 m_support_dir;
		cached_simplex_info m_support_a;
		cached_simplex_info m_support_b;
		int m_support_count;
		phys_gjk_geom_id_pair_key m_key;
		unsigned int m_flags;
	};

	struct phys_collision_pair
	{
		phys_link_list_base<phys_collision_pair> baseclass_0;
		broad_phase_info *m_bpi1;
		broad_phase_info *m_bpi2;
		float m_hit_time;
		phys_gjk_cache_info *m_gjk_ci;
	};

	struct rigid_body_constraint_contact;

	struct __declspec(align(16)) contact_point_info
	{
		phys_vec3 m_normal;
		float m_fric_coef;
		float m_bounce_coef;
		float m_max_restitution_vel;
		int m_flags;
		int m_point_pair_count;
		phys_vec3 *m_list_b1_r_loc;
		phys_vec3 *m_list_b2_r_loc;
		contact_point_info_pulse_sum_cache_info *m_list_pulse_sum_cache_info;
		contact_point_info *m_next_link;
		const void *m_rb2_entity;
		float m_translation_lambda;
		phys_collision_pair *m_pcp;
		rigid_body_constraint_contact *m_rbc_contact;
	};

	template <typename T>
	struct phys_simple_link_list
	{
		T *m_first;
	};

	template <typename T>
	struct phys_inplace_avl_tree_node
	{
		T *m_left;
		T *m_right;
		int m_balance;
	};

	struct rigid_body_pair_key
	{
		rigid_body *m_b1;
		rigid_body *m_b2;
	};

	struct rigid_body_constraint_contact
	{
		rigid_body_constraint baseclass_0;
		phys_simple_link_list<contact_point_info> m_list_contact_point_info_buffer_1;
		phys_simple_link_list<contact_point_info> m_list_contact_point_info_buffer_2;
		unsigned int m_solver_priority;
		phys_inplace_avl_tree_node<rigid_body_constraint_contact> m_avl_tree_node;
		rigid_body_pair_key m_avl_key;
	};

	struct rb_inplace_partition_node
	{
		rigid_body_constraint_point *m_rbc_point_first;
		rigid_body_constraint_hinge *m_rbc_hinge_first;
		rigid_body_constraint_distance *m_rbc_dist_first;
		rigid_body_constraint_ragdoll *m_rbc_ragdoll_first;
		rigid_body_constraint_wheel *m_rbc_wheel_first;
		rigid_body_constraint_angular_actuator *m_rbc_angular_actuator_first;
		rigid_body_constraint_upright *m_rbc_upright_first;
		rigid_body_constraint_custom_orientation *m_rbc_custom_orientation_first;
		rigid_body_constraint_custom_path *m_rbc_custom_path_first;
		rigid_body_constraint_contact *m_rbc_contact_first;
		rigid_body *m_partition_head;
		rigid_body *m_partition_tail;
		rigid_body *m_next_node;
		int m_partition_size;
	};

	struct rigid_body
	{
		phys_vec3 m_last_position;
		phys_vec3 m_moved_vec;
		float m_smallest_lambda;
		__declspec(align(16)) phys_mat44 m_mat;
		phys_vec3 m_inv_inertia;
		phys_vec3 m_gravity_acc_vec;
		phys_vec3 m_t_vel;
		phys_vec3 m_a_vel;
		phys_vec3 m_last_t_vel;
		phys_vec3 m_last_a_vel;
		phys_vec3 m_force_sum;
		phys_vec3 m_torque_sum;
		float m_inv_mass;
		float m_max_avel;
		float m_max_delta_t;
		unsigned int m_flags;
		unsigned int m_tick;
		pulse_sum_node *m_node;
		int m_constraint_count;
		int m_contact_count;
		int m_stable_min_contact_count;
		float m_stable_energy_time;
		float m_largest_vel_sq;
		float m_t_drag_coef;
		float m_a_drag_coef;
		void *m_userdata;
		rb_inplace_partition_node m_partition_node;
	};

	struct user_rigid_body
	{
		rigid_body baseclass_0;
		phys_mat44 *m_dictator;
		__declspec(align(16)) phys_mat44 m_dictator_mat;
	};

	struct gjk_geom_list_t
	{
		gjk_base_t *m_first_geom;
		int m_geom_count;
	};

	enum PhysicsOwnerType
	{
		PHYS_OWNER_DYNENT = 0x0,
		PHYS_OWNER_ENTITY = 0x1,
		PHYS_OWNER_GLASS = 0x2,
		PHYS_OWNER_PARTICLE = 0x3,
		PHYS_OWNER_RAGDOLL = 0x4,
		PHYS_OWNER_XDOLL = 0x5,
		PHYS_OWNER_COUNT = 0x6,
	};

	struct hitinfo_t
	{
		int hittime;
		vec3_t hitp;
		vec3_t hitn;
		int stype;
		int entnum;
		float intensity;
	};

	struct NitrousVehicle;

	struct PhysObjUserData
	{
		rigid_body *body;
		NitrousVehicle *vehicle;
		gjk_geom_list_t m_gjk_geom_list;
		PhysObjUserData *m_next_link;
		__declspec(align(16)) phys_mat44 cg2rb;
		phys_mat44 m2w;
		broad_phase_base *m_bpb;
		vec3_t tvel;
		vec3_t avel;
		float friction;
		float bounce;
		int id;
		int underwater;
		int buoyancy;
		int timeBuoyant;
		int timeRipple;
		unsigned __int16 trDuration;
		unsigned __int16 refcount;
		float m_time_since_last_event;
		float m_time_since_last_reeval;
		int m_flags;
		float mass;
		vec3_t buoyancyBoxMin;
		vec3_t buoyancyBoxMax;
		vec3_t centerOfMassOffset;
		int owner;
		PhysicsOwnerType owner_type;
		hitinfo_t hitinfo;
	};

	struct VehicleStun
	{
		bool m_changed_this_frame;
		float m_stun_time;
		float m_last_throttle;
		float m_throttle_stun_time;
		float m_last_brake;
		float m_brake_stun_time;
	};

	struct __declspec(align(16)) NitrousVehicleController
	{
		enum VehicleHorseControlState
		{
			LEFT_STICK_STEERS_HORSE_AND_CAMERA = 0x0,
			LEFT_STICK_STEERS_HORSE_RIGHT_STICK_CAMERA = 0x1,
			RIGHT_STICK_STEERS_HORSE_AND_CAMERA = 0x2,
		};

		phys_vec3 m_script_goal_position;
		float m_script_goal_radius;
		float m_script_goal_speed;
		float m_drive_path_speed;
		float m_horse_target_speed;
		VehicleHorseControlState m_horse_control_state;
		float m_stopped_time;
		float m_stuck_time;
		__declspec(align(8)) phys_vec3 m_stuck_position;
		usercmd_s m_cmd;
		vec3_t m_cmd_viewangles;
		bool m_cmd_valid;
		bool m_stop_at_goal;
		float m_jump_held_time;
		vec2_t m_jump_input;
		VehicleStun m_stun;
	};

	struct minspec_mutex
	{
		volatile unsigned int m_token;
	};

	enum WheelEffectState
	{
		WHEEL_STATE_ROLLING = 0x0,
		WHEEL_STATE_AIRBORN = 0x1,
		WHEEL_STATE_SKIDDING = 0x2,
		WHEEL_STATE_MAX = 0x3,
	};

	struct WheelState
	{
		WheelEffectState m_state;
		WheelEffectState m_last_state;
		float m_state_time;
		float m_rate;
	};

	struct /*__declspec(align(8))*/ NitrousVehicle
	{
		PhysObjUserData *m_phys_user_data;
		WheelState m_wheel_state[4];
		__declspec(align(16)) phys_mat44 m_wheel_orig_relpo[6];
		int m_wheel_damage[6];
		int m_wheel_surf_types[6];
		float m_wheel_yaw[6];
		float m_steer_factor;
		float m_steer_scale;
		VehicleParameter *m_parameter;
		float m_throttle;
		float m_brake;
		float m_hand_brake;
		float m_script_brake;
		int m_boost_start_time;
		float m_boost_time_pool;
		float m_forward_vel;
		phys_vec3 m_ground_vel;
		float m_hand_brake_friction_time;
		gentity_t *m_owner;
		int m_entnum;
		VehicleDef *m_vehicle_def;
		XModel *m_xmodel;
		rigid_body_constraint_custom_orientation *m_orientation_constraint;
		rigid_body_constraint_custom_path *m_vpc;
		int m_flags;
		int m_notify_flags;
		int m_server_notify_flags;
		vec3_t m_collision_hitp;
		vec3_t m_collision_hitn;
		float m_collision_intensity;
		int m_collision_stype;
		int m_collision_entnum;
		__declspec(align(8)) phys_mat44 m_mat;
		NitrousVehicleController mVehicleController;
		float m_fake_rpm;
		int m_num_colliding_wheels;
		float m_current_side_fric_scale;
		float m_current_fwd_fric_scale;
		float m_stuck_time;
		int m_lastNetworkTime;
		int m_lastErrorReductionTime;
		vec3_t m_networkErrorOrigin;
		vec3_t m_networkErrorAngles;
		int m_trackDistAccumLeftInches;
		int m_trackDistAccumRightInches;
		int m_sfx_state_flags;
		float m_speed_scale;
		float m_drivepath_scale;
		int m_throttle_held_down;
		bool m_throttle_time_started;
		vec3_t m_last_origin;
		vec3_t m_last_angles;
		minspec_mutex m_mutex;
		int id;
		int refcount;
		rigid_body_constraint_wheel *m_wheels[6];
		float m_desired_speed_factor;
		float m_acceleration_factor;
		float m_power_braking_factor;
		float m_braking_factor;
		float m_coasting_factor;
		float m_reference_wheel_radius;
		float m_steer_current_angle;
		float m_steer_max_angle;
		float m_steer_speed;
		phys_vec3 m_steer_front_pt_loc;
		float m_steer_front_back_length;
		float m_min_turning_radius;
		unsigned int m_state_flags;
	};

	enum TraceHitType
	{
		TRACE_HITTYPE_NONE = 0x0,
		TRACE_HITTYPE_ENTITY = 0x1,
		TRACE_HITTYPE_DYNENT_MODEL = 0x2,
		TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
		TRACE_HITTYPE_GLASS = 0x4,
	};

	struct __declspec(align(16)) vehicle_cache_t
	{
		vec3_t lastOrigin;
		vec3_t lastAngles;
		int hit_indices[6];
		int hit_sflags[6];
		vec3_t hit_normals[6];
		float hit_fractions[6];
		TraceHitType hit_type[6];
		unsigned __int16 hit_id[6];
		colgeom_visitor_inlined_t<300> proximity_data;
		int wheel_mask;
	};

	struct __declspec(align(16)) vehicle_t
	{
		vehicle_pathpos_t pathPos;
		int pathOffsetFlags;
		vec3_t pathOffsetTransform[4];
		vec3_t pathFixedOffset;
		vec3_t pathVariableOffset;
		vec3_t pathVariableOffsetTargetPrev;
		vec3_t pathVariableOffsetTarget;
		float pathVariableOffsetRate;
		float pathVariableOffsetTime;
		vehicle_physic_t phys;
		int entNum;
		__int16 defIndex;
		int flags;
		team_t team;
		VehicleMoveState moveState;
		VehicleTurret turret;
		float turretRotScale;
		VehicleJitter jitter;
		VehicleHover hover;
		VehicleTurret gunnerTurrets[4];
		VehicleJitter gunnerJitter[4];
		float minigunRotationSpeed;
		unsigned __int16 lookAtText0;
		unsigned __int16 lookAtText1;
		int manualMode;
		float manualSpeed;
		float manualAccel;
		float manualDecel;
		float speed;
		float maxSpeedOverride;
		float maxDragSpeed;
		float turningAbility;
		int hasTarget;
		int hasTargetYaw;
		int hasGoalYaw;
		int stopAtGoal;
		int stopping;
		int targetEnt;
		EntHandle lookAtEnt;
		vec3_t targetOrigin;
		vec3_t targetOffset;
		float targetYaw;
		vec3_t goalPosition;
		float goalYaw;
		float prevGoalYaw;
		float yawOverShoot;
		int yawSlowDown;
		float pathTransitionTime;
		float maxPathTransitionTime;
		vec3_t pathTransitionOffset;
		vec3_t pathTransitionAngleOffset;
		int hasDefaultPitch;
		float defaultPitch;
		float hasGoalRoll;
		float goalRoll;
		float goalRollTime;
		float currentRollTime;
		int numRolls;
		VehicleTarget gunnerTargets[4];
		float nearGoalNotifyDist;
		vec2_t joltDir;
		float joltTime;
		float joltWave;
		float joltSpeed;
		float joltDecel;
		VehicleTags boneIndex;
		int turretHitNum;
		VehicleSeat seats[11];
		float modelSwapDelay;
		int oneExhaust;
		float deathQuakeScale;
		float deathQuakeDuration;
		float deathQuakeRadius;
		int secTurretAiControlled;
		int addToCompass;
		NitrousVehicle *nitrousVehicle;
		vehicle_cache_t vehicle_cache;
		float heliHeightLockOffset;
		float lastViewOffset;
		int driveBySoundIndex[2];
		float driveBySoundDelay[2];
		float driveBySoundTimeout[2];
		sentient_t *sentient;
		ActorSight sight;
		ActorThreat threat;
		sentient_info_t sentientInfo[72];
	};

	struct flame_timed_damage_t
	{
		gentity_t *attacker;
		int damage;
		float damageDuration;
		float damageInterval;
		int start_timestamp;
		int end_timestamp;
		int lastupdate_timestamp;
	};

	struct item_ent_t
	{
		int ammoCount;
		int clipAmmoCount;
		Weapon weapon;
	};

	struct trigger_ent_t
	{
		int threshold;
		int accumulate;
		int timestamp;
		int singleUserEntIndex;
		char perk;
		bool requireLookAt;
		bool ignoreTeam;
		bool excludeTeam;
		int exposureIndex;
		float exposureLerpToLighter;
		float exposureLerpToDarker;
		vec3_t exposureFeather;
	};

	struct mover_positions_t
	{
		float decelTime;
		float speed;
		float midTime;
		vec3_t pos1;
		vec3_t pos2;
		vec3_t pos3;
	};

	struct mover_slidedata_t
	{
		vec3_t mins;
		vec3_t maxs;
		vec3_t velocity;
	};

	union $538A64D31793DA7494E85D8CCF3A9F54
	{
		mover_positions_t pos;
		mover_slidedata_t slide;
	};

	struct mover_ent_t
	{
		$538A64D31793DA7494E85D8CCF3A9F54 ___u0;
		mover_positions_t angle;
	};

	struct corpse_ent_t
	{
		int deathAnimStartTime;
	};

	enum MissileStage
	{
		MISSILESTAGE_SOFTLAUNCH = 0x0,
		MISSILESTAGE_ASCENT = 0x1,
		MISSILESTAGE_DESCENT = 0x2,
	};

	enum MissileFlightMode
	{
		MISSILEFLIGHTMODE_TOP = 0x0,
		MISSILEFLIGHTMODE_DIRECT = 0x1,
	};

	struct $F77C35275B1C89CAB0A36141425CBDF2
	{
		vec3_t curvature;
		vec3_t targetOffset;
		MissileStage stage;
		MissileFlightMode flightMode;
	};

	struct $72842387414CD44A01249CD18A7BDEE4
	{
		int effectIndex;
	};

	union $30E2FE9AC2D5CA9B1DD39A5DED8EFC2C
	{
		$F77C35275B1C89CAB0A36141425CBDF2 missile;
		$72842387414CD44A01249CD18A7BDEE4 grenade;
	};

	struct missile_ent_t
	{
		int timestamp;
		float time;
		int timeOfBirth;
		float travelDist;
		vec3_t surfaceNormal;
		team_t team;
		char flags;
		int antilagTimeOffset;
		int timeAlive;
		float airburstActivationDistance;
		$30E2FE9AC2D5CA9B1DD39A5DED8EFC2C grenade;
		int forcedDud;
		float grenadeWobbleCycle;
		float grenadeCurve;
		int destructibleBounceCount;
	};

	struct blend_ent_t
	{
		vec3_t pos;
		vec3_t vel;
		vec4_t viewQuat;
		bool changed;
		float posAccelTime;
		float posDecelTime;
		float angleAccelTime;
		float angleDecelTime;
		float startTime;
		float posTotalTime;
		float angleTotalTime;
	};

	struct animscripted_t
	{
		vec3_t axis[4];
		vec3_t originError;
		vec3_t originErrorReduction;
		vec3_t anglesError;
		vec3_t anglesErrorReduction;
		unsigned __int16 anim;
		unsigned __int16 root;
		char bStarted;
		char mode;
		int startTime;
		int lerpTime;
		float fHeightOfs;
		float fEndPitch;
		float fEndRoll;
		float fOrientLerp;
	};

	struct actor_ent_t
	{
		int spawnTime;
		animscripted_t *scripted;
	};

	struct spawner_ent_t
	{
		int team;
		int timestamp;
	};

	struct zbarrier_piece_t
	{
		char state;
		char scalar;
		char nextState;
		int startTime;
	};

	struct zbarrier_ent_t
	{
		zbarrier_piece_t pieces[6];
	};

	union $4BE5A40934689114AA8300BA957D5844
	{
		item_ent_t item[2];
		trigger_ent_t trigger;
		mover_ent_t mover;
		corpse_ent_t corpse;
		missile_ent_t missile;
		blend_ent_t blend;
		actor_ent_t actorInfo;
		spawner_ent_t spawner;
		zbarrier_ent_t zbarrier;
	};

	struct gentity_t_snd_wait
	{
		unsigned __int16 notifyString;
		unsigned int index;
		char stoppable;
		int basetime;
		int duration;
	};

	struct tagInfo_t
	{
		gentity_t *parent;
		gentity_t *next;
		unsigned __int16 name;
		bool blendToParent;
		bool blendOnlyYaw;
		bool collisionPhysics;
		int index;
		vec3_t axis[4];
		vec3_t parentInvAxis[4];
	};

	struct gentity_t
	{
		entityState_s s;
		entityShared_t r;
		gclient_t *client;
		actor_t *actor;
		sentient_t *sentient;
		TurretInfo *pTurretInfo;
		Destructible *destructible;
		vehicle_t *vehicle;
		unsigned __int16 model;
		char physicsObject;
		char takedamage;
		char active;
		char nopickup;
		char handler;
		char team;
		char avoidHandle;
		unsigned __int16 classname;
		unsigned __int16 target;
		unsigned __int16 targetname;
		unsigned __int16 script_noteworthy;
		unsigned int attachIgnoreCollision;
		int spawnflags;
		int flags;
		int eventTime;
		int freeAfterEvent;
		int unlinkAfterEvent;
		int clipmask;
		int processedFrame;
		EntHandle parent;
		int nextthink;
		int health;
		int maxHealth;
		int damage;
		flame_timed_damage_t flame_timed_damage[4];
		int last_timed_radius_damage;
		int count;
		$4BE5A40934689114AA8300BA957D5844 ___u36;
		EntHandle missileTargetEnt;
		gentity_t_snd_wait snd_wait;
		tagInfo_t *tagInfo;
		gentity_t *tagChildren;
		unsigned __int16 attachModelNames[19];
		unsigned __int16 attachTagNames[19];
		XAnimTree_s *pAnimTree;
		unsigned __int16 disconnectedLinks;
		int iDisconnectTime;
		int useCount;
		int physObjId;
		gentity_t *nextFree;
		int birthTime;
		int ikPlayerclipTerrainTime;
		int ikDisableTerrainMappingTime;
	};

	struct __declspec(align(128)) cg_t
	{
		int clientNum;
		// ...
	};

    struct ReliableCommands
    {
        int sequence;
        int acknowledge;
        char *commands[128];
        int commandBufferNext;
        char commandBuffer[16384];
    };
    struct netProfilePacket_t
    {
        int iTime;
        int iSize;
        int bFragment;
    };
    struct netProfileStream_t
    {
        netProfilePacket_t packets[60];
        int iCurrPacket;
        int iBytesPerSecond;
        int iLastBPSCalcTime;
        int iCountedPackets;
        int iCountedFragments;
        int iFragmentPercentage;
        int iLargestPacket;
        int iSmallestPacket;
    };
    struct netProfileInfo_t
    {
        netProfileStream_t send;
        netProfileStream_t recieve;
    };
    struct netchan_t
    {
        int outgoingSequence;
        Game::netsrc_t sock;
        int dropped;
        int incomingSequence;
        Game::netadr_t remoteAddress;
        int qport;
        int fragmentSequence;
        int fragmentLength;
        char *fragmentBuffer;
        int fragmentBufferSize;
        int unsentFragments;
        int unsentOnLoan;
        int unsentFragmentStart;
        int unsentLength;
        char *unsentBuffer;
        int unsentBufferSize;
        int reliable_fragments;
        char fragment_send_count[128];
        unsigned int fragment_ack[4];
        int lowest_send_count;
        netProfileInfo_t prof;
    };
    struct clientConnection_t
    {
        int qport;
        ClientNum_t clientNum;
        int lastPacketSentTime;
        int lastPacketTime;
        Game::netadr_t serverAddress;
        int connectTime;
        int connectPacketCount;
        char serverMessage[256];
        int challenge;
        int checksumFeed;
        ReliableCommands reliableCommands;
        int serverMessageSequence;
        int serverCommandSequence;
        int lastExecutedServerCommand;
        char serverCommands[128][1024];
        bool isServerRestarting;
        bool areTexturesLoaded;
        bool waitForMovie;
        bool hostCompromised;
        netchan_t netchan;
        char netchanOutgoingBuffer[2048];
        char netchanIncomingBuffer[65536];
        netProfileInfo_t OOBProf;
        __int64 statPacketsToSend;
        int statPacketSendTime[41];
    };

    struct bdSecurityID
    {
        char ab[8];
    };
    struct XNADDR
    {
        char addrBuff[37];
    };
    struct bdSecurityKey
    {
        char ab[16];
    };
    struct XSESSION_INFO
    {
        bdSecurityID sessionID;
        XNADDR hostAddress;
        bdSecurityKey keyExchangeKey;
    };

	union $54FFFBD4E33C1C3B3F8B53E0A896B6CC
	{
		char ip[4];
		unsigned int inaddr;
	};

	struct PartyInfo
	{
		int flags;
		XSESSION_INFO info;
		netadr_t serverAddr;
		int occupiedPublicSlots;
		int occupiedPrivateSlots;
		int numPublicSlots;
		int numPrivateSlots;
		float skill;
		int geo1;
		int geo2;
		int geo3;
		int geo4;
		int ping;
		int avgPing;
		unsigned __int64 xuid;
		int upload;
	};

	enum ProberMode
	{
		PROBER_UNDEFINED = 0x0,
		PROBER_SEARCH = 0x1,
		PROBER_MERGE = 0x2,
		PROBER_INVITE = 0x3,
		PROBER_NEWLOBBY = 0x4,
		PROBER_CLIENT = 0x5,
	};

	enum ProberState
	{
		STATE_IDLE = 0x0,
		STATE_WAITING_FOR_HOSTS = 0x1,
		STATE_QOS_IN_PROGRESS = 0x2,
		STATE_QOS_COMPLETE = 0x3,
		STATE_ASSOCIATING = 0x4,
		STATE_HANDSHAKING = 0x5,
		STATE_HOST_FAILED = 0x6,
		STATE_NO_HOSTS = 0x7,
		STATE_SEARCH_EXHAUSTED = 0x8,
		STATE_CLIENT_ASSOCIATING = 0x9,
		STATE_CLIENT_HANDSHAKING = 0xA,
		STATE_CLIENT_CONNECTED = 0xB,
		STATE_CLIENT_FAILED = 0xC,
		STATE_HOST_ACCEPT = 0xD,
		STATE_CLIENTS_AGREE = 0xE,
		STATE_ALL_IN = 0xF,
		STATE_ERROR = 0x10,
	};

	struct SessionStaticData
	{
		char *sessionName;
		bool registerUsersWithVoice;
		bool isDedicated;
	};

	struct ClientInfo
	{
		bool registered;
		bool voiceRegistered;
		unsigned __int64 xuid;
		int natType;
		netadr_t addr;
		int voiceConnectivityBits;
		int lastConnectivityTestTime[1];
		bool friends;
		int flags;
		bool muted;
		int performanceValue;
		bool privateSlot;
	};

	struct RegisteredUser
	{
		bool active;
		unsigned __int64 xuid;
		bool privateSlot;
		int performanceValue;
	};

	struct SessionDynamicData
	{
		bool sessionHandle;
		XSESSION_INFO sessionInfo;
		bool keysGenerated;
		bool sessionStartCalled;
		unsigned __int64 sessionNonce;
		int privateSlots;
		int publicSlots;
		int flags;
		bool qosListenEnabled;
		ClientInfo users[19];
		ControllerIndex_t sessionCreateController;
		int sessionDeleteTime;
		int actualPublicSlots;
		int voiceConnectivityBits;
		RegisteredUser internalRegisteredUsers[19];
	};

	struct SessionData
	{
		SessionStaticData staticData;
		SessionDynamicData dyn;
	};

	struct MigrateMemberData
	{
		ClientNum_t nominee;
		int nomineeUpload;
		int nomineeNAT;
		bool nomineeOnLSP;
		bool heardFrom;
		int lastHeardFrom;
		int lastSentTo;
		bool inSameGeographicalRegion;
	};

	struct MigrateData
	{
		int indexBits;
		int startTime;
		MigrateMemberData memberData[18];
	};

	enum connstate_t
	{
		CA_DISCONNECTED = 0x0,
		CA_CINEMATIC = 0x1,
		CA_UICINEMATIC = 0x2,
		CA_LOGO = 0x3,
		CA_CONNECTING = 0x4,
		CA_CHALLENGING = 0x5,
		CA_CONNECTED = 0x6,
		CA_SENDINGSTATS = 0x7,
		CA_LOADING = 0x8,
		CA_PRIMED = 0x9,
		CA_ACTIVE = 0xA,
	};

	struct PartySceNpId
	{
		char handle[20];
		char opt[8];
		char reserved[8];
	};

	struct liveAddr
	{
		XNADDR xnaddr;
	};

	struct platformNetAdr
	{
		netadr_t netAddr;
		liveAddr liveaddr;
	};

	union $4CC444478A5CF1CA3E666352329DBEA9
	{
		int rank;
		int rankPosition;
	};

	union $6F592E3A475AB50E77AAA300354707EA
	{
		int prestige;
		int divisionID;
		int daysLastPlayed;
	};

	struct PartyMemberTeam
	{
		int team;
		int switchTeam;
		int switchTeamTime;
		int lastTeam;
	};

	struct PartyMember
	{
		char status;
		int ackedMembers;
		int lastPacketTime;
		int lastHeartbeatTime;
		int lastPartyStateAck;
		int lastDemoHeartBeatTime;
		unsigned int challenge;
		int subpartyIndex;
		connstate_t reportedConnState;
		bool invited;
		bool headsetPresent;
		bool inLivePartyVoice;
		bool inLivePartyTalking;
		bool finishedLoadingDemo;
		bool isReady;
		bool isGuest;
		bool isSplitscreenClient;
		int natType;
		unsigned __int64 player;
		char gamertag[32];
		ControllerIndex_t localControllerIndex;
		int playerEmblem;
		PartySceNpId npid;
		char clanAbbrev[5];
		bool clanAbbrev_IsEliteValidated;
		int codPoints;
		unsigned int affinityBits;
		platformNetAdr platformAddr;
		int availableMapPackFlags;
		bdSecurityID privatePartyId;
		$4CC444478A5CF1CA3E666352329DBEA9 ___u30;
		$6F592E3A475AB50E77AAA300354707EA ___u31;
		int deaths;
		float skillRating;
		float skillVariance;
		PartyMemberTeam teamInfo;
		int score;
		int vetoedMap;
		int downloadPercent;
		bool readyForPlayback;
		int maximumPing;
		int specialFlags;
		int clanTagFeature;
		int voiceConnectivityBits;
		unsigned __int64 leagueTeamID;
		int leagueMemberCount;
		int searchStartUTC;
		int uploadBandwidth;
		char probation;
		char recentPlaylistEntries[3];
		unsigned int serverchallenge;
		int serverChallengeDeadline;
	};

	struct PartyMemberProfile
	{
		int updateTime;
		int sendTime;
		int ackTime;
		int acked;
		char DDL[1024];
	};

	enum PartyLeagueState
	{
		LEAGUE_WAITING_FOR_STATS = 0x0,
		LEAGUE_FORMING_TEAMS = 0x1,
		LEAGUE_CANNOT_FORM_TEAMS = 0x2,
		LEAGUE_SENDING_OUTCOMES = 0x3,
		LEAGUE_READY_TO_GO = 0x4,
	};

	enum LeagueDataState
	{
		LEAGUE_DATA_REQUESTING_BASE = 0x0,
		LEAGUE_DATA_BASE_RECEIVED = 0x1,
		LEAGUE_DATA_SENDING_OUTCOMES = 0x2,
		LEAGUE_DATA_OUTCOMES_ACKED = 0x3,
	};

	struct LeagueStats
	{
		int rankPoints;
		int rank;
		float floats[3];
		int ints[8];
	};

	struct LeagueOutcomes
	{
		LeagueStats base;
		LeagueStats winner;
		LeagueStats loser;
	};

	struct PartyMemberLeagueData
	{
		LeagueDataState state;
		int stateChangeTime;
		int stateUpdateTime;
		unsigned __int64 teamID;
		unsigned __int64 subdivisionID;
		int divisionID;
		int memberCount;
		char teamName[32];
		LeagueOutcomes outcomes;
	};

	struct PartyLeagueTeamData
	{
		unsigned __int64 teamID;
		bool valid;
		char name[32];
	};

	struct SubpartyMember
	{
		int memberIndex;
		char *gamertag;
		int lastTeam;
		unsigned int affinityBits;
	};

	struct SubpartyInfo
	{
		SubpartyMember members[18];
		bool links[18];
		int count;
		float skill;
		int skillRanking;
		int searchStartUTC;
		int score;
		int team;
	};

	struct lobbyBanSlot_t
	{
		unsigned __int64 bannedXuid;
		int banTime;
	};

	struct PartyHostDetails
	{
		netadr_t addr;
		XSESSION_INFO sessionInfo;
		unsigned __int64 xuid;
		int lastPacketTime;
		int lastPacketSentTime;
		int numPrivateSlots;
		int numPublicSlots;
		ClientNum_t hostNum;
		bool accepted;
		unsigned int challenge;
		bool isDedicated;
	};

	struct PartyHostData
	{
		int partyStateChangeTime;
		int stateSequenceNumber;
		int expectedPlayers;
		int vetoPassTime;
		int uiState;
		int uiEvent;
		int uiEventTime;
		int sessionSendTime;
		int lastValidLeagueTime;
		char votePossible;
		bool preloadingMap;
		bool firstLobby;
		bool migrateAfterRound;
		bool stopAfterRound;
		bool readyToStart;
		bool initialAckComplete;
	};

	enum MergeDedicatedState
	{
		MERGE_DEDICATED_COMPLETE = 0x0,
		MERGE_DEDICATED_NOT_REQUESTED = 0x1,
		MERGE_DEDICATED_REQUESTED = 0x2,
		MERGE_DEDICATED_IN_PROGRESS = 0x3,
	};

	struct partyMergeData_t
	{
		int timeSinceLastJoin;
		int lastSessionSearch;
		MergeDedicatedState dedicatedState;
	};

	struct PartyStatePacket_s
	{
		int sequenceNumber;
		int totalSize;
		int size;
		int offset;
	};

	struct PartyData_s
	{
		SessionData *session;
		SessionData *presenceSession;
		MigrateData migrateData;
		PartyMember partyMembers[19];
		PartyMemberProfile partyProfiles[19];
		PartyLeagueState leagueState;
		PartyMemberLeagueData memberLeagueData[19];
		PartyLeagueTeamData leagueTeamData[9];
		SubpartyInfo subparties[19];
		int subpartyCount;
		lobbyBanSlot_t lobbyBans[16];
		int partyJoinTime;
		PartyHostDetails currentHost;
		PartyHostDetails potentialHost;
		PartyHostData hostData;
		__declspec(align(8)) partyMergeData_t mergeData;
		float qosPercent;
		int qosSuccesses;
		int qosTotal;
		int localPlayerFlags[1];
		int lastMemberUpdateTime[1];
		int memberUpdateInterval[1];
		int areWeHost;
		int joiningAnotherParty;
		int inParty;
		int party_systemActive;
		int veto;
		bool enteringStartReadyState;
		bool ready;
		int wagerTime;
		int allowedTeams;
		bool teamBased;
		unsigned __int64 demoFileId;
		int demoFileSize;
		bool demoIsUserFile;
		bool finishedLoadingDemo;
		bool retryDemoDownload;
		unsigned __int64 demoAuthorXUID;
		int partyId;
		int nextSessionSearchTime;
		int mapPackSearchFlags;
		int mapPackFlags;
		unsigned __int64 leagueTeamID;
		char leagueTeamName[32];
		int lastPartyStateTime;
		int gameStartTime;
		int interEndTime;
		int partyTimer;
		int restartMatchmakingTimer;
		int goResumeTime;
		int hostTimeouts;
		char lobbyFlags;
		PartyData_s *partyToNotify;
		bool registeredWithArbitration;
		bool rejoining;
		char stateMsgBuf[7200];
		PartyStatePacket_s partyStatePackets[6];
		char lastEntries[8];
		int currentEntry;
		int lastQosEntry;
		bool qosDataReady;
		int lobbyBeginTime;
		bool stateParsed;
		int soundEvents;
		int hostChangelist;
		int partyStartTimeMs;
		int nextChallengeSend;
		unsigned int serverChallenge;
	};

	enum searchSessionMode_t
	{
		SEARCH_SESSION_MODE_INVALID = 0x0,
		SEARCH_SESSION_MODE_PUBLIC = 0x1,
		SEARCH_SESSION_MODE_LEAGUE = 0x2,
		SEARCH_SESSION_MODE_LOBBY_MERGE = 0x3,
		SEARCH_SESSION_MODE_DEDICATED_SERVER = 0x4,
		SEARCH_SESSION_MODE_COUNT = 0x5,
	};

	struct PartyProber
	{
		PartyInfo hosts[50];
		int hostCount;
		ProberMode mode;
		ProberState state;
		ControllerIndex_t controllerIndex;
		int partyId;
		PartyData_s *partyToNotify;
		searchSessionMode_t searchMode;
		int minPlayers;
		int requiredFlags;
		int searchStartUTC;
		netadr_t masterAddr;
		int echoChallenge;
		PartyInfo echoHost;
		int echoHostNum;
		int clientDisagreeTime[18];
		int clientAgreeTime[18];
		int clientPacketTime;
		int clientWaitStart;
		int hostIndex;
		netadr_t hostAddr;
		unsigned int hostChallenge;
		int hostNum;
		int nextSearchTime;
		int packetStartTime;
		int packetRecvTime;
		int packetSendTime;
		int retryCount;
		char errorMessage[256];
	};

#pragma pack(push, 1)

	enum XFilePlatform
	{
		// These seem to have the same version as XBOX360
		PLATFORM_PS3,
		PLATFORM_WIIU,

		PLATFORM_XBOX360 = 0x92, // 0x92000000 if taking care of endianness
		PLATFORM_PC = 0x93,

		PLATFORM_CUSTOM = 0x1337,
	};

	struct XFileHeaderRaw
	{
		uint64_t magic;
		XFilePlatform platform;
	};

	struct XFileHeaderUnsigned
	{
		XFileHeaderRaw r;
		uint64_t identifier;
		uint32_t empty; // Seems to be always 0. Padding?
		char name[32];
	};

	struct XFileHeaderSigned
	{
		XFileHeaderUnsigned u;
		uint8_t signature[0x100];
	};

	struct XFileBlock
	{
		DWORD size;
		uint8_t data[1];
	};

	struct XFileSigned
	{
		XFileHeaderSigned header;
		XFileBlock block;
	};

	struct ZoneHeader
	{
		XFile xFile;
		XAssetList assetList;
	};

#pragma pack(pop)

// #pragma pack(push, 1)
    struct PredictedVehicleDef
    {
        bool fullPhysics;
        vec3_t origin;
        vec3_t angles;
        vec3_t tVel;
        vec3_t aVel;
        int serverTime;
    };
// #pragma pack(pop)

    struct clientHeader_t
    {
        int state;
        int sendAsActive;
        int deltaMessage;
        int rateDelayed;
        int hasAckedBaselineData;
        int hugeSnapshotSent;
        netchan_t netchan;
        vec3_t predictedOrigin;
        int predictedOriginServerTime;
        int migrationState;
        PredictedVehicleDef predictedVehicle;
    };

    struct svscmd_info_t
    {
        char *cmd;
        int time;
        int type;
    };

    struct clientSnapshot_t
    {
        playerState_s ps;
        int entityCount;
        int clientCount;
        int actorCount;
        int matchStateIndex;
        int firstEntityIndex;
        int firstClientIndex;
        int firstActorIndex;
        int messageSent;
        int messageAcked;
        int messageSize;
        int serverTime;
        int physicsTime;
        int timeDelta;
        int baselineSnap;
    };

    struct client_t
    {
        void $() { sizeof(*this); }
        clientHeader_t header;
        const char *dropReason;
        char userinfo[1024];
        char reliableCommandBuffer[16384];
        int reliableCommandBufferNext;
        svscmd_info_t reliableCommandInfo[128];
        int reliableSequence;
        int reliableAcknowledge;
        int reliableSent;
        int messageAcknowledge;
        int gamestateMessageNum;
        usercmd_s lastUsercmd;
        int lastClientCommand;
        char lastClientCommandString[1024];
        gentity_t *gentity;                     
        char name[32];
        char clanAbbrev[5];
        int clanAbbrev_IsEliteValidated;
        unsigned __int64 xuid;
        unsigned __int64 teamid;
        unsigned int doubleXPGroupMask;
        unsigned int availableMappackFlags;
        int nextReliableTime;
        int nextReliableCount;
        char reservedSlot;
        int lastPacketTime;
        int lastConnectTime;
        int nextSnapshotTime;
        int lastSnapshotTime;
        int timeoutCount;
        clientSnapshot_t frames[16];
        int ping;
        int pingMin;
        int pingMax;
        int unackCount;
        int rate;
        int pureAuthentic;
        int packetUploadCount;
        __declspec(align(128)) char netchanOutgoingBuffer[65536];
        char netchanIncomingBuffer[2048];
        int guid;
        unsigned __int16 scriptId;
        bool bIsSplitscreenClient;
        bool bIsSecondScreenClient;
        int bIsTestClient;
        int serverId;
        int natType;
        char stats[50176];
        char purchasedItems[32];
        int unlockedAttachments[64];
        char bonusCardsActive[10];
        char modifiedStatBytes[6272];
        int statsSentIndex;
        int statsModified;
        __int64 statPacketsReceived;
        int statsValidated;
        bool liveAuthorized;
        int liveAuthFlags;
        char liveAuthFailCount;
        int liveAuthTimestamp;
        unsigned __int64 liveUserID;
        bool tempPacketDebugging;
        int snapshotHistoryTime;
        int snapshotHistoryFrames;
        int messageHistorySize;
        int demoPacketCount;
        int demoPacketSizes[8];
        int demoPacketIsFragment[8];
        int demoReliableCmdSize;
        char demoReliableCmdItemChars[16];
        int demoReliableCmdItemSize[16];
        int demoReliableCmdCount;
        unsigned int lastHashedXP;
        int lastSmallDeltaTime;
        int lastSnapSentTime;
    };

    struct color
    {
        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };

    struct persistentStats
    {
        char statsBuffer[50176];
        bool isChecksumValid;
        bool statsWriteNeeded;
        bool statsValidatedWithDDL;
        bool statsFetched;
        bool disableUpload;
    };

    enum ddlReturnCodes_e
    {
        DDL_RC_SUCCESS = 0x0,
        DDL_RC_ERROR = 0xFFFFFFFF,
        DDL_RC_BUFFER_IO_ERROR = 0xFFFFFFFE,
        DDL_RC_STATE_INVALID = 0xFFFFFFFD,
        DDL_RC_MEMBER_NULL = 0xFFFFFFFC,
        DDL_RC_MEMBER_INVALID = 0xFFFFFFFB,
        DDL_RC_OFFSET_INVALID = 0xFFFFFFFA,
        DDL_RC_TRUNCATED = 0xFFFFFFF9,
    };

    enum statsLocation
    {
        STATS_LOCATION_NORMAL = 0x0,
        STATS_LOCATION_FORCE_NORMAL = 0x1,
        STATS_LOCATION_BACKUP = 0x2,
        STATS_LOCATION_STABLE = 0x3,
        STATS_LOCATION_OTHERPLAYER = 0x4,
        STATS_LOCATION_COUNT = 0x5,
    };

    struct ddlState_t
    {
        int absoluteOffset;
        int arrayIndex;
        ddlMemberDef_t *member;
        ddlDef_t *ddl;
        ddlReturnCodes_e returnCode;
    };

    typedef struct _gscFunction
    {
        DWORD crc32;                            // 0x00 - CRC32 of function bytecode
        DWORD start;                            // 0x04 - A relative pointer to the GSC bytecode start of this function
        WORD name;                              // 0x08 - A relative pointer to the name of this function
        BYTE numOfParameters;                   // 0x0A -
        BYTE flag;                              // 0x0B -
        /*
        Possible flag values (not sure if all of them):

        - If flag & 1, function loaded (I think?)
        */
    } gscFunction;

    typedef struct _COD9_GSC
    {
        BYTE identifier[8];                     // 0x00 - It's the same always
        BYTE unknown1[4];                       // 0x08 - I think it's some kind of checksum
        DWORD includeStructs;                   // 0x0C - A relative pointer to an array of includeStruct structs, amount = numOfIncludes
        DWORD usinganimtreeStructs;             // 0x10 - A relative pointer to an array of usinganimtreeStruct structs, amount = numOfUsinganimtree
        DWORD codeSectionStart;                 // 0x14 - A relative pointer to where the GSC bytecode starts (gscFunctions)
        DWORD gscStrings;                       // 0x18 - A relative pointer to an array of gscString structs, amount = numOfStrings
        DWORD gscFunctions;                     // 0x1C - A relative pointer to an array of gscFunction structs, amount = numOfFunctions
        DWORD externalFunctions;                // 0x20 - A relative pointer to an array of externalFunction structs, amount = numOfExternalFunctions
        DWORD gscRelocations;                   // 0x24 - A relative pointer to an array of gscRelocation structs, amount = numOfRelocations
        DWORD size;                             // 0x28 -
        DWORD codeSectionSize;                  // 0x2C - Size of the executable bytecode
        WORD name;                              // 0x30 - A relative pointer to the name of this gsc (with full path and extension, null terminated)
        WORD numOfStrings;                      // 0x32 - IMPORTANT: Includes everything except #include strings, #using_animtree strings and function name strings
        WORD numOfFunctions;                    // 0x34 - Number of functions in this script file
        WORD numOfExternalFunctions;            // 0x36 - Number of functions imported
        WORD numOfRelocations;                  // 0x38 - Number of patches in the GSC code/file
        BYTE unknown4[2];                       // 0x3A - ?
        BYTE numOfIncludes;                     // 0x3C - Number of included source files
        BYTE numOfUsinganimtree;                // 0x3D - Number of included animation trees
        BYTE _padding[2];                       // 0x3E - Struct padding
    } COD9_GSC; // size: 64 bytes

    enum hitLocation_t
    {
        HITLOC_NONE = 0x0,
        HITLOC_HELMET = 0x1,
        HITLOC_HEAD = 0x2,
        HITLOC_NECK = 0x3,
        HITLOC_TORSO_UPR = 0x4,
        HITLOC_TORSO_MID = 0x5,
        HITLOC_TORSO_LWR = 0x6,
        HITLOC_R_ARM_UPR = 0x7,
        HITLOC_L_ARM_UPR = 0x8,
        HITLOC_R_ARM_LWR = 0x9,
        HITLOC_L_ARM_LWR = 0xA,
        HITLOC_R_HAND = 0xB,
        HITLOC_L_HAND = 0xC,
        HITLOC_R_LEG_UPR = 0xD,
        HITLOC_L_LEG_UPR = 0xE,
        HITLOC_R_LEG_LWR = 0xF,
        HITLOC_L_LEG_LWR = 0x10,
        HITLOC_R_FOOT = 0x11,
        HITLOC_L_FOOT = 0x12,
        HITLOC_GUN = 0x13,
        HITLOC_SHIELD = 0x14,
        HITLOC_NUM = 0x15,
    };

    enum meansOfDeath_t
    {
        MOD_UNKNOWN = 0x0,
        MOD_PISTOL_BULLET = 0x1,
        MOD_RIFLE_BULLET = 0x2,
        MOD_GRENADE = 0x3,
        MOD_GRENADE_SPLASH = 0x4,
        MOD_PROJECTILE = 0x5,
        MOD_PROJECTILE_SPLASH = 0x6,
        MOD_MELEE = 0x7,
        MOD_BAYONET = 0x8,
        MOD_HEAD_SHOT = 0x9,
        MOD_CRUSH = 0xA,
        MOD_TELEFRAG = 0xB,
        MOD_FALLING = 0xC,
        MOD_SUICIDE = 0xD,
        MOD_TRIGGER_HURT = 0xE,
        MOD_EXPLOSIVE = 0xF,
        MOD_IMPACT = 0x10,
        MOD_BURNED = 0x11,
        MOD_HIT_BY_OBJECT = 0x12,
        MOD_DROWN = 0x13,
        MOD_GAS = 0x14,
        MOD_NUM = 0x15,
    };

    struct BuiltinFunctionDef
    {
        const char *actionString;
        unsigned int constId;
        int min_args;
        int max_args;
        void(__cdecl *actionFunc)();
        Game::scriptInstance_t type;
    };

    enum class ClassNum : std::uint16_t
    {
        entity,
        hudelem,
        pathnode,
        vehicle,
        dynent,

        max,
    };

    struct scr_entref_t
    {
        unsigned __int16 entnum;
        ClassNum classnum;
        LocalClientNum_t client;
    };

    struct BuiltinMethodDef
    {
        const char *actionString;
        unsigned int constId;
        int min_args;
        int max_args;
        void(__cdecl *actionFunc)(scr_entref_t);
        int type;
    };

    struct VariableStackBuffer
    {
        char *pos;
        char *creationPos;
        int waitTime;
        unsigned __int16 size;
        unsigned __int16 bufLen;
        unsigned __int16 localId;
        char buf[1];
    };

    union VariableUnion
    {
        int intValue;
        unsigned int uintValue;
        float floatValue;
        unsigned int stringValue;
        const float *vectorValue;
        char *codePosValue;
        unsigned int pointerValue;
        VariableStackBuffer *stackValue;
        unsigned int entityOffset;
    };

    struct VariableValue
    {
        int type;
        VariableUnion u;
    };

    struct gscProfileInfo_t
    {
        unsigned int inclusive_time;
        unsigned int exclusive_time;
        unsigned int hit_count;
    };

    struct SCR_PROFILER_DATA
    {
        gscProfileInfo_t *profileInfo[8];
        int profileInfoCount;
    };

    struct function_stack_t
    {
        char *pos;
        VariableValue *top;
        unsigned int localId;
        unsigned int localVarCount;
        VariableValue *startTop;
        // SCR_PROFILER_DATA profileData;
    };

    struct function_frame_t
    {
        function_stack_t fs;
        char *creationPos;
    };

    struct scrVmPub_t
    {
        unsigned int *localVars;
        VariableValue *maxstack;
        int function_count;
        function_frame_t *function_frame;
        VariableValue *top;
        bool debugCode;
        bool abort_on_error;
        bool terminal_error;
        bool block_execution;
        unsigned int inparamcount;
        unsigned int outparamcount;
        unsigned int breakpointOutparamcount;
        bool showError;
        function_frame_t function_frame_start[32];
        VariableValue stack[2048];
        void(__cdecl *notifyListeners[1])(unsigned int, unsigned int);
    };

    enum fieldtype_t
    {
        F_INT = 0x0,
        F_SHORT = 0x1,
        F_BYTE = 0x2,
        F_FLOAT = 0x3,
        F_LSTRING = 0x4,
        F_STRING = 0x5,
        F_VECTOR = 0x6,
        F_ENTITY = 0x7,
        F_ENTHANDLE = 0x8,
        F_ACTOR = 0x9,
        F_SENTIENT = 0xA,
        F_SENTIENTHANDLE = 0xB,
        F_CLIENT = 0xC,
        F_PATHNODE = 0xD,
        F_ACTORGROUP = 0xE,
        F_VECTORHACK = 0xF,
        F_OBJECT = 0x10,
        F_XMODEL_INDEX = 0x11,
        F_XMODEL = 0x12,
        F_BITFLAG = 0x13,
        F_FX = 0x14,
    };

    struct GfxSkinCacheEntry
    {
        unsigned int frameCount;
        int skinnedCachedOffset;
        unsigned __int16 numSkinnedVerts;
        unsigned __int16 ageCount;
    };

    struct clientControllers_t
    {
        vec3_t angles[6];
        vec3_t tag_origin_angles;
        vec3_t tag_origin_offset;
    };

    struct CEntPlayerInfo
    {
        clientControllers_t *control;
        char tag[6];
        float waterHeight;
        int nextWaterHeightCheck;
        int nextRippleTime;
    };

    struct CEntTurretAngles
    {
        float pitch;
        float yaw;
        float barrelPitch;
    };

    union $8881F8B9B9745D8A0D51B30E12AE0899
    {
        CEntTurretAngles angles;
        vec3_t viewAngles;
    };

    struct CEntTurretInfo
    {
        $8881F8B9B9745D8A0D51B30E12AE0899 ___u0;
        bool playerUsing;
        float minigunRotation;
        float minigunRotationSpeed;
        char tag_aim;
        char tag_aim_animated;
        char tag_flash;
        char tag_spin;
        char tag_turret;
        char tag_barrel;
        float barrelPitch;
        float pivotOffset;
        float firingOffset;
        char tag_aim_pivot;
        char tag_weapon;
    };

    struct CEntVehicleDefGround
    {
        float wheelHeight[6];
        float nitrousWheelRotation[6];
        __int16 nitrousWheelYaw[6];
        char tag_extra_tank_wheels[4];
    };

    struct CEntVehicleRotor
    {
        float rotation;
        float speed;
        char tag;
        char orientation;
        char armTag;
        float armRotation;
    };

    struct CEntVehicleDefAir
    {
        CEntVehicleRotor rotor[4];
    };

    union $DDFE80AE35AB3F66A64EFC458D0A39ED
    {
        CEntVehicleDefGround ground;
        CEntVehicleDefAir air;
    };

    struct CEntVehicleDef
    {
        float barrelRecoil;
        __int16 pitch;
        __int16 roll;
        __int16 barrelYaw;
        __int16 barrelPitch;
        __int16 steerYaw;
        __int16 steerPitch;
        __int16 gunnerPitch[4];
        __int16 gunnerYaw[4];
        __int16 minigunRotation;
        __int16 antennaPitch[2];
        __int16 antennaRoll[2];
        char wheelBoneIndex[6];
        char tag_body;
        char tag_turret;
        char tag_barrel;
        char tag_barrel_recoil;
        char tag_gunner_turret[4];
        char tag_gunner_barrel[4];
        char tag_player;
        char tag_minigun_spin;
        char tag_antennas[2];
        $DDFE80AE35AB3F66A64EFC458D0A39ED ___u22;
    };

    struct CEntFx
    {
        int triggerTime;
        unsigned int effect;
    };

    union $B5C6484BFC4A9A509FCDCE318554591E
    {
        float height;
        float yaw;
    };

    struct CEntActorInfo
    {
        int proneType;
        float pitch;
        float roll;
        char headBone;
        $B5C6484BFC4A9A509FCDCE318554591E ___u4;
        float waterHeight;
        int nextWaterHeightCheck;
        int nextRippleTime;
        float lookAtBlend;
        char lookAtFlags;
    };

    struct CEntGeneral
    {
        int contents;
        bool linked;
        vec3_t mins;
        vec3_t maxs;
    };

    union $6DCAC28DCBF7B63C461B9EFCE53C6FF6
    {
        CEntPlayerInfo player;
        CEntTurretInfo turret;
        CEntVehicleDef vehicle;
        CEntFx fx;
        CEntActorInfo actor;
        CEntGeneral general;
    };

    struct ShaderConstantSet
    {
        vec4_t value[7];
        char constantSource[7];
        char used;
    };

    struct cpose_t
    {
        unsigned __int16 lightingHandle;
        char eType;
        char eTypeUnion;
        char localClientNum;
        char isRagdoll;
        int ragdollHandle;
        int physObjId;
        int physUserBody;
        int killcamRagdollHandle;
        int physUserBodyProneFeet;
        char destructiblePose;
        int startBurnTime;
        float wetness;
        int cullIn;
        vec3_t origin;
        vec3_t angles;
        vec3_t absmin;
        vec3_t absmax;
        GfxSkinCacheEntry skinCacheEntry;
        $6DCAC28DCBF7B63C461B9EFCE53C6FF6 ___u19;
        ShaderConstantSet constantSet;
    };

    struct $4E48DA81AE6944637E6E45560C08B001
    {
        unsigned __int32 relativeAnglesSet : 1;
        unsigned __int32 identityLinkto : 1;
    };

    union $D4F728D1B967197453543DD7D1CB7091
    {
        unsigned int packed_bits;
        $4E48DA81AE6944637E6E45560C08B001 __s1;
    };

    struct cLinkInfo_s
    {
        vec3_t axis[4];
        int linkEnt;
        int linkTag;
        vec3_t relativeAngles;
        $D4F728D1B967197453543DD7D1CB7091 ___u4;
    };

    struct cgVehicleWheelEffect
    {
        int surfaceType;
        int lastSurfaceType;
    };

    enum VehicleEngineState
    {
        VEH_ENGINE_STATE_IDLE = 0x0,
        VEH_ENGINE_STATE_IN_GEAR = 0x1,
        VEH_ENGINE_STATE_SHIFT_UP = 0x2,
        VEH_ENGINE_STATE_SHIFT_DOWN = 0x3,
    };

    struct Engine
    {
        float throttle;
        float load;
        int currentGear;
        float rpms;
        float targetDownShiftRPM;
        float inAirTime;
        bool onGround;
        VehicleEngineState state;
    };

    struct cgVehicle_t
    {
        int lastGunnerFire[4];
        int wheelSurfType[6];
        int fireTime;
        int flags;
        float materialTime;
        float materialTime2;
        vehicle_cache_t *vehicle_cache;
        cgVehicleWheelEffect wheelEffects[3];
        unsigned int notes[2];
        int driveBySoundIndex[2];
        float driveBySoundDelay[2];
        float driveBySoundTimeout[2];
        float prevTurretPitch;
        float prevTurretYaw;
        float prevGunnerPitch[4];
        float prevGunnerYaw[4];
        float prevAngularVelocity[5];
        Engine engine;
        float minigunRotationSpeed;
        vec3_t gunSoundOrigins[5];
        char wasFiring;
        vec3_t antennaPos[2];
        vec3_t antennaVel[2];
        vec3_t antennaParentBoneWorldAxis[2][3];
        vec3_t antennaRelativePos[2];
        vec3_t poseAxis[4];
    };

    struct cached_client_tag_t
    {
        int time;
        vec3_t lastLocalTagOrigin;
        bool visible;
        int predictedTime;
        vec3_t predictedPosition;
        vec3_t predictedAngles;
    };

    struct ClientTagCache
    {
        cached_client_tag_t aim_head_tag;
        cached_client_tag_t aim_highest_tag;
        cached_client_tag_t tag_flash;
    };

    struct AimTargetCache
    {
        int lastUpdateTime;
        float targetHeight;
    };

    struct cgScriptMover_s
    {
        float decelTime;
        float aDecelTime;
        float speed;
        float aSpeed;
        float midTime;
        float aMidTime;
        vec3_t pos1;
        vec3_t pos2;
        vec3_t pos3;
        vec3_t apos1;
        vec3_t apos2;
        vec3_t apos3;
    };

    struct canimscripted_t
    {
        vec3_t axis[4];
        unsigned __int16 anim;
        char bStarted;
    };

    struct centity_t;
    struct _cgZBarrierPiece_t
    {
        centity_t *pPiece;
        XModel *curXModel;
        void(__cdecl *pStateLogic)(LocalClientNum_t, cg_t *, centity_t *, ZBarrierDef *, _cgZBarrierPiece_t *, LerpEntityStateZBarrierPiece *, unsigned int);
        int timeVal;
        int intVal;
        char state;
        char prevState;
        char subState;
        char nextSubState;
        char curAnim;
        bool flagsChanged;
    };

    struct cgZBarrier_s
    {
        bool forceUpdateForDemoJump;
        _cgZBarrierPiece_t pieces[6];
    };

    union $E5F00115C9C447EB243E515D96FCD8A7
    {
        WeaponDef *weapDef;
        WeaponAttachmentUnique *attachment;
    };

    struct WeaponDobjInfo
    {
        enum Slot
        {
            HELD = 0x0,
            STOWED = 0x1,
            MELEE = 0x2,
        };
        struct ModelMask
        {
            WeaponDobjInfo::Slot slot;
            bool weapon;
            $E5F00115C9C447EB243E515D96FCD8A7 ___u2;
            unsigned int dobjModelMask;
        };

        char numModelMasks;
        WeaponDobjInfo::Slot addingSlot;
        __int16 lastAddedModel;
        WeaponDobjInfo::ModelMask modelMasks[8];
    };

    struct DroppedWeaponDobjInfo
    {
        int entnum;
        WeaponDobjInfo weaponDobjInfo;
    };

    struct $2C268F07489A8B2B324034942807AD28
    {
        unsigned __int32 applyLeftHandIK : 1;
        unsigned __int32 nextValid : 1;
        unsigned __int32 bMuzzleFlash : 1;
        unsigned __int32 bMuzzleFlashLeft : 1;
        unsigned __int32 bMuzzleFlashLastShot : 1;
        unsigned __int32 bShellEject : 1;
        unsigned __int32 bShellEjectLeft : 1;
        unsigned __int32 bTrailMade : 1;
        unsigned __int32 isBurning : 1;
        unsigned __int32 skipBloodImpacts : 1;
        unsigned __int32 heroBloodImpact : 1;
        unsigned __int32 scriptThreaded : 1;
        unsigned __int32 clientRumbleLoop : 1;
        unsigned __int32 didOverheatFx : 1;
        unsigned __int32 leftFootstep : 1;
        unsigned __int32 rightFootstep : 1;
        unsigned __int32 leftRearFootstep : 1;
        unsigned __int32 rightRearFootstep : 1;
        unsigned __int32 bIsTrigger : 1;
        unsigned __int32 bIsTriggerRadius : 1;
        unsigned __int32 bIsTriggerBox : 1;
        unsigned __int32 bIsOneShot : 1;
        unsigned __int32 bIsPlaneOnRadar : 1;
        unsigned __int32 bFloatLonger : 1;
        unsigned __int32 bForceBuoyancy : 1;
        unsigned __int32 bIgnoreRagdoll : 1;
        unsigned __int32 bClientFlagsNeedProcessing : 1;
        unsigned __int32 bUpdatedSinceReset : 1;
        unsigned __int32 bUpdateToggle : 1;
        unsigned __int32 bZombieEyeGlowHasBeenTurnedOn : 1;
        unsigned __int32 bFakeEntityMoving : 1;
        unsigned __int32 bFakeEntityTurning : 1;
        unsigned __int32 bFakeEntityRemoved : 1;
        unsigned __int32 originAnglesError : 1;
        unsigned __int32 partOfZBarrier : 1;
        unsigned __int32 linkRelativeAngles : 1;
        unsigned __int32 sndTurretWasFiring : 1;
        unsigned __int32 clientMainThreaded : 1;
        unsigned __int32 renderInThirdPersonSpectate : 1;
        unsigned __int32 overrideLightingOrigin : 1;
        unsigned __int32 forceNotSimple : 1;
    };

    union $11702CD5E47195B9D77913842C0F63DA
    {
        unsigned int packed_bits[2];
        $2C268F07489A8B2B324034942807AD28 __s1;
    };

    struct centity_t
    {
        cpose_t pose;
        LerpEntityState prevState;
        entityState_s nextState;
        __int16 previousEventSequence;
        int miscTime;
        int lastMuzzleFlash;
        int numShotsFiredLast;
        unsigned __int16 attachModelNames[2];
        unsigned __int16 attachTagNames[2];
        XAnimTree_s *tree;
        Destructible *destructible;
        NitrousVehicle *nitrousVeh;
        cLinkInfo_s *linkInfo;
        cgVehicle_t *vehicle;
        ClientTagCache *clientTagCache;
        AimTargetCache *aimTargetInfo;
        cgScriptMover_s *cScriptMover;
        canimscripted_t *scripted;
        cgZBarrier_s *zbarrier;
        DroppedWeaponDobjInfo *droppedWeaponDobjInfo;
        int nextSlideFX;
        unsigned __int16 flagIndex;
        unsigned __int16 flagState;
        Material *compassMaterial;
        int lastTrailTime;
        unsigned int fxTrailHandle;
        unsigned int fxProjExplosion;
        unsigned int fxHeartbeat;
        unsigned int fxLaserSight;
        vec3_t oldLinkOrigin;
        vec3_t originError;
        vec3_t anglesError;
        char tracerDrawRateCounter;
        centity_t *updateDelayedNext;
        unsigned __int16 classname;
        unsigned int stepSound;
        char footstepSurfaceOverride;
        char deployedRiotshieldHits[8];
        $11702CD5E47195B9D77913842C0F63DA ___u38;
    };

    struct cent_field_s
    {
        const char *name;
        unsigned int constId;
        int ofs;
        int size[1];
        fieldtype_t type;
        void(__cdecl *setter)(centity_t *, cent_field_s *);
        void(__cdecl *getter)(centity_t *, cent_field_s *);
    };

    union $48F18C9B5E91F84575999A8D859164D3
    {
        void(__cdecl *floatCallbackFunc)(LocalClientNum_t, unsigned int, float, float, bool, bool, const char *, bool);
        void(__cdecl *uintCallbackFunc)(LocalClientNum_t, unsigned int, unsigned int, unsigned int, bool, bool, const char *, bool);
    };

    struct clientFieldCodeCallback_s
    {
        unsigned __int32 bHasCodeCallback : 1;
        unsigned __int32 bCodeCallbackIsFloatVal : 1;
        $48F18C9B5E91F84575999A8D859164D3 ___u2;
    };

    struct clientField_s
    {
        int scriptCallbackFunc;
        clientFieldCodeCallback_s codeCallbackFunc;
        unsigned __int16 nameHash;
        unsigned int fieldOffset;
        unsigned int fieldType;
        float floatMin;
        float floatMax;
        unsigned int accessMask;
        int bSplitscreenHostOnly;
        int bCallbacksFor0WhenNew;
        char bitOffset;
        unsigned int numBits;
        unsigned int version;
    };

    struct ent_field_t
    {
        const char *name;
        int ofs;
        int size[1];
        fieldtype_t type;
        void(__cdecl *callback)(gentity_t *, int);
    };

    struct client_fields_s
    {
        typedef gclient_t* Ptr;

        const char *name;
        unsigned int constId;
        int ofs;
        int size[1];
        fieldtype_t type;
        unsigned int whichbits;
        void(__cdecl *setter)(gclient_t *, client_fields_s *);
        void(__cdecl *getter)(gclient_t *, client_fields_s *);
    };

    struct actor_fields_s
    {
        typedef actor_t* Ptr;

        const char *name;
        unsigned int constId;
        int ofs;
        int size[1];
        fieldtype_t type;
        void(__cdecl *setter)(actor_t *, actor_fields_s *);
        void(__cdecl *getter)(actor_t *, actor_fields_s *);
    };

    struct game_hudelem_s
    {
        hudelem_s elem;
        ClientNum_t clientNum;
        int team;
        int archived;
    };

    struct game_hudelem_field_t
    {
        typedef game_hudelem_s* Ptr;

        const char *name;
        unsigned int constId;
        int ofs;
        int size;
        fieldtype_t type;
        int mask;
        int shift;
        void(__cdecl *setter)(game_hudelem_s *, int);
        void(__cdecl *getter)(game_hudelem_s *, int);
    };


#ifdef __cplusplus
}
#pragma warning(pop)
#endif

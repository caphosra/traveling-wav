// Constant values
#define TVGW_RIFF 0x46464952
#define TVGW_WAVE 0x45564157
#define TVGW_FMT 0x20746D66
#define TVGW_DATA 0x61746164

#if defined(TVGW_DLL_EXPORT)
#   define TVGW_API extern "C" __declspec(dllexport)
#elif defined(TVGW_DLL_IMPORT)
#   define TVGW_API extern "C" __declspec(dllimport)
#else
#   define TVGW_API extern "C"
#endif

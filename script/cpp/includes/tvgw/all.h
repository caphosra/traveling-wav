// Constant values
#define TVGW_RIFF 0x46464952
#define TVGW_WAVE 0x45564157
#define TVGW_FMT 0x20746D66
#define TVGW_DATA 0x61746164

#include"tvgw/filedata.h"

#if !TVGW_WITHOUT_FILE_LOAD
#include"tvgw/fileload.h"
#endif

#if !TVGW_WITHOUT_FILE_WRITE
#include"tvgw/filewrite.h"
#endif

#if !TVGW_WITHOUT_CONVERTER
#include"tvgw/converter.h"
#endif

#include"tvgw/dispose.h"

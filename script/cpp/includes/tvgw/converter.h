#include"tvgw/filedata.h"

//
// Generate a chunk from the format contents
//
extern "C" void tvgw_ConvertToFormatChunk(TVGW_File_Chunk* chunk, TVGW_Format_Contents* fmt);

//
// Generate a chunk from the byte codes
//
extern "C" void tvgw_ConvertToDataChunk(TVGW_File_Chunk* chunk, unsigned int dataSize, char* data);

//
// Get format data from the chunk
//
extern "C" TVGW_Format_Contents* tvgw_GetAsFormatContents(TVGW_File_Chunk* chunk);

//
// Generate the RIFF file contents from the chunks
//
extern "C" TVGW_RIFF_File* tvgw_ConvertToRIFF(unsigned int fileType, unsigned int chunkCount, TVGW_File_Chunk** chunks);

//
// Generate the wav file contents from the chunks (This function equals "tvgw_ConvertToRIFF(TVGW_WAVE, chunks)")
//
extern "C" TVGW_RIFF_File* tvgw_ConvertToWav(unsigned int chunkCount, TVGW_File_Chunk** chunks);

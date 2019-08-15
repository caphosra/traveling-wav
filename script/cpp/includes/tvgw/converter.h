#pragma once

#include"tvgw/constant.h"
#include"tvgw/structs.h"

//
// Generate a chunk from the format contents
//
TVGW_API void tvgw_ConvertToFormatChunk(TVGW_File_Chunk* chunk, TVGW_Format_Contents* fmt);

//
// Generate a chunk from the byte codes
//
TVGW_API void tvgw_ConvertToDataChunk(TVGW_File_Chunk* chunk, unsigned int dataSize, char* data);

//
// Get format data from the chunk
//
TVGW_API TVGW_Format_Contents* tvgw_GetAsFormatContents(TVGW_File_Chunk* chunk);

//
// Generate the RIFF file contents from the chunks
//
TVGW_API TVGW_RIFF_File* tvgw_ConvertToRIFF(unsigned int fileType, unsigned int chunkCount, TVGW_File_Chunk** chunks);

//
// Generate the wav file contents from the chunks (This function equals "tvgw_ConvertToRIFF(TVGW_WAVE, chunks)")
//
TVGW_API TVGW_RIFF_File* tvgw_ConvertToWav(unsigned int chunkCount, TVGW_File_Chunk** chunks);

#pragma once

#include"tvgw/filedata.h"

#include<fstream>

// 
// Write the content to the file
//
// - RETURN : 0(Run Successfully) or -1(Error Code)
extern "C" int tvgw_WriteFile(const char* filename, TVGW_RIFF_File* filedata);

// 
// Write the chunk to the file
// (You shouldn't use this directly - this function will be called in "writeFile")
//
// - RETURN : 0(Run Successfully) or -1(Error Code)
extern "C" int tvgw_WriteFileChunk(std::ofstream* fout, TVGW_File_Chunk* chunk);

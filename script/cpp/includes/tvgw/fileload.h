#pragma once

#include"tvgw/constant.h"
#include"tvgw/structs.h"

#include<fstream>

//
// Load all contents of the RIFF file
//
// - RETURN : 0(Run Successfully) or -1(Error Code)
extern "C" int tvgw_LoadFile(const char* filename, TVGW_RIFF_File* filedata);

// 
// Load the RIFF file by chunk
// (You shouldn't use this directly - this function will be called in "loadFile")
//
// - RETURN : 0(Run Successfully), 1(EndOfFile) or -1(Error Code)
extern "C" int tvgw_LoadFileChunk(std::ifstream* fin, TVGW_File_Chunk* chunk);

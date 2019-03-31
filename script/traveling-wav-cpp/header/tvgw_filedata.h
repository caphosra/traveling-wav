#pragma once

//
// This expresses the file which was formated as Resource Interchange File Format(RIFF)
//
struct TVGW_RIFF_File;

//
// This expresses the chunk of the file which was formated as Resource Interchange File Format(RIFF)
//
struct TVGW_File_Chunk;

//
// Format chunk (fmt)
//
struct TVGW_Format_Contents;

#pragma pack(4)
struct TVGW_RIFF_File
{
    unsigned int RIFF;
    unsigned int fileSize;
    unsigned int fileType;

    unsigned int chunkCount;
    TVGW_File_Chunk** chunks;
};
#pragma pack()

#pragma pack(4)
struct TVGW_File_Chunk
{
    unsigned int chunkName; 
    unsigned int chunkSize;
    char* data;
};
#pragma pack()

#pragma pack(4)
struct TVGW_Format_Contents
{
    short formatTag;
    unsigned short channels;
    unsigned int sampleRate;
    unsigned int bytePerSec;
    unsigned short blockAlign;
    unsigned short bitsWidth;
};
#pragma pack()

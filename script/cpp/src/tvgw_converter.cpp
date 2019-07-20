#include"tvgw/converter.h"

extern "C" void tvgw_ConvertToFormatChunk(TVGW_File_Chunk* chunk, TVGW_Format_Contents* fmt){
    // fmt[space]
    chunk->chunkName = TVGW_FMT;
    chunk->chunkSize = sizeof(TVGW_Format_Contents);

    chunk->data = (char*)fmt;
}

extern "C" void tvgw_ConvertToDataChunk(TVGW_File_Chunk* chunk, unsigned int dataSize, char* data){
    // data
    chunk->chunkName = TVGW_DATA;
    chunk->chunkSize = dataSize;

    chunk->data = data;
}

extern "C" TVGW_Format_Contents* tvgw_GetAsFormatContents(TVGW_File_Chunk* chunk){
    return (TVGW_Format_Contents*)chunk->data;
}

extern "C" TVGW_RIFF_File* tvgw_ConvertToRIFF(unsigned int fileType, unsigned int chunkCount, TVGW_File_Chunk** chunks){
    auto riff_contents = new TVGW_RIFF_File;

    // Counted the word "WAVE"
    int fileSize = sizeof(unsigned int);

    for(unsigned int counter = 0; counter < chunkCount; counter++){
        fileSize += (sizeof(unsigned int) * 2 + chunks[counter]->chunkSize);
    }

    riff_contents->RIFF = TVGW_RIFF;
    riff_contents->fileSize = fileSize;
    riff_contents->fileType = fileType;
    riff_contents->chunkCount = chunkCount;
    riff_contents->chunks = chunks;

    return riff_contents;
}

extern "C" TVGW_RIFF_File* tvgw_ConvertToWav(unsigned int chunkCount, TVGW_File_Chunk** chunks){
    return tvgw_ConvertToRIFF(TVGW_WAVE, chunkCount, chunks);
}

#include"tvgw/all.h"

extern "C" void tvgw_Dispose(TVGW_RIFF_File* filedata){
    int chunkCount = filedata->chunkCount;
    for(int counter = 0; counter < chunkCount; counter++){
        auto chunk = filedata->chunks[counter];
        delete[] chunk->data;
        delete chunk;
    }
    delete[] filedata->chunks;
    delete filedata;
}
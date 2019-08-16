#include<vector>
#include<fstream>
#include<iostream>

#include"tvgw/fileload.h"

extern "C" int tvgw_LoadFile(const char* filename, TVGW_RIFF_File* filedata){
    std::ifstream fin(filename, std::ios::binary);

    fin.read((char*)filedata, sizeof(unsigned int) * 3);

    std::vector<TVGW_File_Chunk*> chunks_tmp;
    while(!fin.eof()){
        TVGW_File_Chunk* chunk = new TVGW_File_Chunk;
        int exit_code = tvgw_LoadFileChunk(&fin, chunk);
        if(exit_code == -1){
            return -1;
        }
        else if(exit_code == 1){
            delete chunk;
            break;
        }
        else{
            chunks_tmp.push_back(chunk);
        }
    }

    int counter = 0;
    int size = chunks_tmp.size();
    TVGW_File_Chunk** chunks = (TVGW_File_Chunk**)new char[sizeof(TVGW_File_Chunk*) * chunks_tmp.size()];
    for(counter = 0; counter < size; counter++){
        chunks[counter] = chunks_tmp[counter];
    }
    
    chunks_tmp.~vector();

    filedata->chunkCount = counter;
    filedata->chunks = chunks;

    fin.close();
    return 0;
}

extern "C" int tvgw_LoadFileChunk(std::ifstream* fin, TVGW_File_Chunk* chunk){
    char* chunk_ptr = (char*)chunk;

    fin->read(chunk_ptr, sizeof(unsigned int) * 2);

    if(fin->eof()){
        return 1;
    }

    chunk->data = new char[chunk->chunkSize];
    if(chunk->data == NULL){
        return -1;
    }
    else{
        for(unsigned int i = 0; i < chunk->chunkSize; i++){
            fin->read(chunk->data + i, sizeof(char));
        }
    }
    return 0;
}

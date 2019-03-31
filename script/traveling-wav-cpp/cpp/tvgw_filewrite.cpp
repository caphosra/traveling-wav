#include<vector>
#include<fstream>

#include"../header/tvgw_filewrite.h"

extern "C" int tvgw_WriteFile(const char* filename, TVGW_RIFF_File* filedata){
    std::ofstream fout(filename, std::ios::binary);

    fout.write((char*)filedata, sizeof(unsigned int) * 3);

    for(int counter = 0; counter < filedata->chunkCount; counter++){
        tvgw_WriteFileChunk(&fout, filedata->chunks[counter]);
    }

    fout.close();
    return 0;
}

extern "C" int tvgw_WriteFileChunk(std::ofstream* fout, TVGW_File_Chunk* chunk){
    fout->write((char*)chunk, sizeof(unsigned int) * 2);

    fout->write(chunk->data, sizeof(char) * chunk->chunkSize);
    return 0;
}

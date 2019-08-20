# Traveling Wav (A library to load or create wav file)

[![Build Status](https://dev.azure.com/capra314cabra/TravelingWav/_apis/build/status/capra314cabra.traveling-wav?branchName=master)](https://dev.azure.com/capra314cabra/TravelingWav/_build/latest?definitionId=1&branchName=master)  
[![License](https://img.shields.io/badge/License-MIT-lightgray)](https://github.com/capra314cabra/traveling-wav/blob/master/LICENSE)

Using this library, you can quickly write code to create or read simple wav file(*.wav).

## Description

This library enables you to read, write or create wav file without confusing binary files! :ok_hand: Even if you are not good at file operations, you can write code intuitively.  
Also this can be used for managing [RIFF file](https://en.wikipedia.org/wiki/Resource_Interchange_File_Format) such as *.wav, *.avi, *.ani. It means that you can use this not only for wav file but for other files.

## Usage

### Load file

``` C++
// #include<tvgw/fileload>

// Allocate memory for result.
auto riff_file = new TVGW_RIFF_File;

// Call tvgw_LoadFile function.
int result = tvgw_LoadFile("somemusic.wav", &riff_file);

if (result == 0)
{
    // Load file successfully.
}
```

### Write file

``` C++
// #include<tvgw/filewrite>

// Create format chunk.
auto format_chunk = new TVGW_File_Chunk;
tvgw_ConvertToFormatChunk(&format_chunk, &fmt);

// Create data chunk.
auto music_data_chunk = new TVGW_File_Chunk;
tvgw_ConvertToDataChunk(&music_data_chunk, dataSize, data);

// Create RIFF format data.
auto chunks = new TVGW_File_Chunk[2];
chunks[0] = format_chunk;
chunks[1] = music_data_chunk;
auto filedata = * tvgw_ConvertToWav(2, chunks);

// Call tvgw_WriteFile function
int result = tvgw_WriteFile("somemusic.wav", &filedata);

if (result == 0)
{
    // Load file successfully.
}
```

## Install

1. Go to [Release Page](https://github.com/capra314cabra/traveling-wav/releases) and
download the files.
(or go to [GitHub](https://github.com/capra314cabra/traveling-wav) and download source codes)
2. Include the files to your project.

Only this.

## Contribution

We always welcome you to join us.  
And, when you want to contribute this, you can do so by doing following action. 

1. Fork it
2. Create your feature branch (git checkout -b feature/my-change)
3. Commit your changes (git commit -am 'Add some feature')
4. Push to the branch (git push origin feature/my-change)
5. Create new Pull Request

## Licence

[MIT](https://github.com/capra314cabra/traveling-wav/blob/master/LICENSE)

## Author

[capra314cabra](https://github.com/capra314cabra)

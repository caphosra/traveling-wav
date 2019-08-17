using System;
using System.Runtime.InteropServices;

namespace TravelingWav.Native
{
    public partial class TVGWWrapper
    {
        [StructLayout(LayoutKind.Sequential, Pack=4)]
        public struct TVGW_RIFF_File
        {
            public uint RIFF;
            public uint fileSize;
            public uint fileType;
            public uint chunkCount;
            /* TVGW_File_Chunk** */ public IntPtr chunks;
        }

        [StructLayout(LayoutKind.Sequential, Pack=4)]
        public struct TVGW_File_Chunk
        {
            public uint chunkName; 
            public uint chunkSize;
            /* char* */ public IntPtr data;
        }

        [StructLayout(LayoutKind.Sequential, Pack=4)]
        public struct TVGW_Format_Contents
        {
            public short formatTag;
            public ushort channels;
            public uint sampleRate;
            public uint bytePerSec;
            public ushort blockAlign;
            public ushort bitsWidth;
        }
    }
}
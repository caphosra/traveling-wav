using System;
using System.Linq;
using System.Runtime.InteropServices;
using System.Collections.Generic;

namespace TravelingWav.Native
{
    public partial class TVGWWrapper
    {
        private static partial class UnmanagedMethods
        {
            /// <summary>
            /// Generate a chunk from the format contents
            /// </summary>
            /// <param name="chunk">TVGW_File_Chunk*</param>
            /// <param name="fmt">TVGW_Format_Contents*</param>
            [DllImport("tvgw")]
            public static extern void tvgw_ConvertToFormatChunk(ref TVGW_File_Chunk chunk, ref TVGW_Format_Contents fmt);

            /// <summary>
            /// Generate a chunk from the byte codes
            /// </summary>
            /// <param name="chunk">TVGW_File_Chunk*</param>
            /// <param name="dataSize">uint</param>
            /// <param name="data">char*</param>
            [DllImport("tvgw")]
            public static extern void tvgw_ConvertToDataChunk(ref TVGW_File_Chunk chunk, uint dataSize, in byte data);

            /// <summary>
            /// Get format data from the chunk
            /// </summary>
            /// <param name="chunk">TVGW_File_Chunk*</param>
            /// <returns>TVGW_Format_Contents*</returns>
            [DllImport("tvgw")]
            public static extern ref TVGW_Format_Contents tvgw_GetAsFormatContents(ref TVGW_File_Chunk chunk);

            /// <summary>
            /// Generate the RIFF file contents from the chunks
            /// </summary>
            /// <param name="fileType">uint</param>
            /// <param name="chunkCount">uint</param>
            /// <param name="chunks">TVGW_File_Chunk**</param>
            /// <returns>TVGW_RIFF_File*</returns>
            [DllImport("tvgw")]
            public static extern ref TVGW_RIFF_File tvgw_ConvertToRIFF(uint fileType, uint chunkCount, IntPtr chunks);

            /// <summary>
            /// Generate the wav file contents from the chunks (This function equals "tvgw_ConvertToRIFF(TVGW_WAVE, chunks)")
            /// </summary>
            /// <param name="chunkCount">uint</param>
            /// <param name="chunks">TVGW_File_Chunk**</param>
            /// <returns>TVGW_RIFF_File*</returns>
            [DllImport("tvgw")]
            public static extern ref TVGW_RIFF_File tvgw_ConvertToWav(uint chunkCount, IntPtr chunks);

            /// <summary>
            /// The file type of wav
            /// </summary>
            public const uint TVGW_WAVE = 0x45564157;
        }

        /// <summary>
        /// Generate a chunk from the format contents
        /// </summary>
        public void ConvertToFormatChunk(ref TVGW_File_Chunk chunk, ref TVGW_Format_Contents fmt)
        {
            UnmanagedMethods.tvgw_ConvertToFormatChunk(ref chunk, ref fmt);
        }

        /// <summary>
        /// Generate a chunk from the byte codes
        /// </summary>
        public void ConvertToDataChunk(ref TVGW_File_Chunk chunk, uint dataSize, Span<byte> data)
        {
            ref byte bytedata = ref MemoryMarshal.GetReference(data);
            UnmanagedMethods.tvgw_ConvertToDataChunk(ref chunk, dataSize, bytedata);
        }

        /// <summary>
        /// Generate a chunk from the byte codes
        /// </summary>
        public void ConvertToDataChunk(ref TVGW_File_Chunk chunk, Span<byte> data)
        {
            ref byte bytedata = ref MemoryMarshal.GetReference(data);
            UnmanagedMethods.tvgw_ConvertToDataChunk(ref chunk, (uint)data.Length, bytedata);
        }

        /// <summary>
        /// Get format data from the chunk
        /// </summary>
        public ref TVGW_Format_Contents GetAsFormatContents(ref TVGW_File_Chunk chunk)
        {
            return ref UnmanagedMethods.tvgw_GetAsFormatContents(ref chunk);
        }

        /// <summary>
        /// Generate the RIFF file contents from the chunks
        /// </summary>

        public ref TVGW_RIFF_File ConvertToRiff(uint fileType, uint chunkCount, IEnumerable<TVGW_File_Chunk> chunks)
        {
            var chunksSize = Marshal.SizeOf(typeof(TVGW_File_Chunk)) * (int)chunkCount;
            var pointersSize = Marshal.SizeOf(typeof(IntPtr)) * (int)chunkCount;

            var allocateSize = chunksSize + pointersSize;

            var allocatedSpacesLocation = Marshal.AllocHGlobal(allocateSize);

            var pointersLocation = allocatedSpacesLocation;
            var chunksLocation = allocatedSpacesLocation + pointersSize;

            var chunksWithCounter = chunks.Select((chunk, count) => (chunk, count));
            foreach (var chunk in chunksWithCounter)
            {
                var chunkLocation = chunksLocation + Marshal.SizeOf(typeof(TVGW_File_Chunk)) * chunk.count;
                var pointerLocation = pointersLocation + Marshal.SizeOf(typeof(IntPtr)) * chunk.count;

                Marshal.StructureToPtr(chunk.chunk, chunkLocation, fDeleteOld: false);
                Marshal.StructureToPtr(chunkLocation, pointerLocation, fDeleteOld: false);
            }

            ref var riff = ref UnmanagedMethods.tvgw_ConvertToRIFF(fileType, chunkCount, allocatedSpacesLocation);

            Marshal.FreeHGlobal(allocatedSpacesLocation);

            return ref riff;
        }

        /// <summary>
        /// Generate the wav file contents from the chunks (This function equals "tvgw_ConvertToRIFF(TVGW_WAVE, chunks)")
        /// </summary>
        public ref TVGW_RIFF_File ConvertToWav(uint chunkCount, IEnumerable<TVGW_File_Chunk> chunks)
        {
            return ref ConvertToRiff(UnmanagedMethods.TVGW_WAVE, chunkCount, chunks);
        }
    }
}

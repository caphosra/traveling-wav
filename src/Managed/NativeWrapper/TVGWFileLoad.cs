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
            /// Load all contents of the RIFF file
            /// </summary>
            /// <param name="filename">const char*</param>
            /// <param name="filedata">TVGW_RIFF_File*</param>
            /// <returns>0(Run Successfully) or -1(Error Code)</returns>
            [DllImport("tvgw")]
            public static extern int tvgw_LoadFile(string filename, ref TVGW_RIFF_File filedata);
        }

        /// <summary>
        /// Load all contents of the RIFF file
        /// </summary>
        public int LoadFile(string filename, ref TVGW_RIFF_File filedata)
        {
            return UnmanagedMethods.tvgw_LoadFile(filename, ref filedata);
        }
    }
}
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
            /// Write the content to the file
            /// </summary>
            /// <param name="filename">const char*</param>
            /// <param name="filedata">TVGW_RIFF_File*</param>
            /// <returns>0(Run Successfully) or -1(Error Code)</returns>
            [DllImport("tvgw")]
            public static extern int tvgw_WriteFile(string filename, ref TVGW_RIFF_File filedata);
        }

        /// <summary>
        /// Write the content to the file
        /// </summary>
        public static int WriteFile(string filename, ref TVGW_RIFF_File filedata)
        {
            return UnmanagedMethods.tvgw_WriteFile(filename, ref filedata);
        }
    }
}
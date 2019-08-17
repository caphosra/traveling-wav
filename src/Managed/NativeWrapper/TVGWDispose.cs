using System.Runtime.InteropServices;

namespace TravelingWav.Native
{
    public partial class TVGWWrapper
    {
        private static partial class UnmanagedMethods
        {
            /// <summary>
            /// Dispose the instance of TVGW_RIFF_File
            /// </summary>
            /// <param name="filedata">TVGW_RIFF_File*</param>
            [DllImport("tvgw")]
            public static extern void tvgw_Dispose(ref TVGW_RIFF_File filedata);
        }

        /// <summary>
        /// Dispose the instance of TVGW_RIFF_File
        /// </summary>
        public void Dispose(ref TVGW_RIFF_File filedata)
        {
            UnmanagedMethods.tvgw_Dispose(ref filedata);
        }
    }
}
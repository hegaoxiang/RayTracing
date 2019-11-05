using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace YBREditor
{
    class NativeMethods
    {
        const string editorDllName = "TTest.dll";

        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public unsafe static extern void EditorMain(IntPtr instancePtrAddress, IntPtr hPrevInstancePtrAddress, IntPtr hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);
        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public unsafe static extern void WndProc(IntPtr hWndPtrAddress, int msg, int wParam, int lParam);
        [DllImport(editorDllName, CallingConvention = CallingConvention.Cdecl)]
        public static extern void RenderFrame();
    }
}

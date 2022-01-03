using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Threading.Tasks;

namespace CppAnCs
{
    internal class LuaAPI
    {
        public const string GreenLua = "C:/Users/Tom/source/repos/LuaC/Debug/GreenLua.dll";

        [DllImport(GreenLua, CallingConvention = CallingConvention.Cdecl)]
        internal static extern int GreenLua_test();
        //int test = LuaAPI.GreenLua_test();

        ////public static int test = 6;

        //[DllImport(GreenLua, CallingConvention = CallingConvention.Cdecl)]
        //public static extern IntPtr GreenLua_state();


        //[DllImport(GreenLua, CallingConvention = CallingConvention.Cdecl)]
        //public static extern void GreenLua_openLibs(IntPtr L);


        //[DllImport(GreenLua, CallingConvention = CallingConvention.Cdecl)]
        //public static extern int GreenLua_dofile(IntPtr L, string path);


        //[DllImport(GreenLua, CallingConvention = CallingConvention.Cdecl)]
        //static extern string GreenLua_checkLua(IntPtr L, int r);

        //public static bool checkLua(IntPtr L, int r)
        //{
        //    //if (GreenLua_checkLua(L, r) != "OK")
        //        Console.Write($"Return {GreenLua_checkLua(L, r)}");
        //    //return false;
        //    return true;
        //}

        public static int getIsActive()
        {
            return GreenLua_test();
        }

    }
}

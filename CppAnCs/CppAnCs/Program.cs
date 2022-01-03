using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CppAnCs
{
    public class Program
    {
        static void Main(string[] args)
        {
            string luaPath = "";


            //IntPtr L = LuaAPI.GreenLua_state();
            //LuaAPI.GreenLua_openLibs(L);

            //LuaAPI.checkLua(L, LuaAPI.GreenLua_dofile(L, luaPath));




            int test = LuaAPI.getIsActive();

            //int input1, input2;

            Console.Write($"Input Number 1: {test}");

            //if (!int.TryParse(Console.ReadLine(), out input1))
            //{
            //    Console.WriteLine("Bad argument, defaul used!");
            //    input1 = 5;
            //}

            //Console.Write("Input Number 2: ");

            //if (!int.TryParse(Console.ReadLine(), out input2))
            //{
            //    Console.WriteLine("Bad argument, defaul used!");
            //    input2 = 2;
            //}

            //int output = AddNumbers(input1, input2);

            //Console.WriteLine($"Result: {output}");
            Console.ReadLine();
        }
    }
}

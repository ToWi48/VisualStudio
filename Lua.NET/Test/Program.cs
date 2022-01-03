using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Linq.Expressions;
using System.Reflection;
using GreenLua;

namespace Test {
	class Program {
		static string ReadLine(string Prompt) {
			Console.Write(Prompt);
			return Console.ReadLine();
		}

		static int Wrapped(string S, double D) {
			Console.WriteLine("String: {0}", S);
			Console.WriteLine("Number: {0}", D);
			return 42;
		}

		static int Print(lua_StatePtr S)
		{
			string id = Lua.lua_tostring(S, -1);

			Console.WriteLine("Print: {0}", id);

			Lua.lua_pop(S, 1);

			return 0;
		}

		static int Test(lua_StatePtr S) 
		{
			int id = Lua.lua_tointeger(S, -1);

			Console.WriteLine("Rotate Id: {0}", id);

			Lua.lua_pop(S, 1);

			Lua.lua_pushnumber(S, 9);
			Lua.lua_pushnumber(S, 8);
			Lua.lua_pushnumber(S, 7);

			return 3;
		}

		static void Main(string[] args) {
			Console.Title = "Test";
			Console.WriteLine("Running {0} bit {1}", IntPtr.Size * 8, Lua.VERSION);
			lua_StatePtr L = Lua.lua_newstate((UD, Ptr, OSize, NSize) => {
				if ((int)NSize == 0) {
					Marshal.FreeHGlobal(Ptr);
					return IntPtr.Zero;
				}
				if (Ptr == IntPtr.Zero)
					return Marshal.AllocHGlobal(NSize);
				return Marshal.ReAllocHGlobal(Ptr, NSize);
			}, IntPtr.Zero);
			Lua.luaL_openlibs(L);

			//Lua.lua_register(L, "print", Print);
			//Lua.lua_register(L, "test", Test);

			if (Lua.VERSION == LuaVersion.LuaJIT) { // LuaJIT print doesn't work :V
				Advanced.SetGlobal(L, "write", new Action<string>(Console.Write));
				Lua.luaL_dostring(L, "local _write = write write = nil function print(...) for _,v in pairs({...}) do _write(tostring(v)) _write('\\t') end _write('\\n') end");
			}
			Lua.luaL_dostring(L, "function printt(t) for k,v in pairs(t) do print(k, ' - ', v) end end");

			int b = Lua.luaL_loadstringpath(L, "print('Tom ist toll1'); local x,y,z = test(55); print(x); print(y); print(z)", "Mega/");
			int i = Lua.luaL_dostring(L, "print('Tom ist toll1'); local x,y,z = test(55); print(x); print(y); print(z)");

			string Str;
			while ((Str = ReadLine("> ")).Length > 0) {
				try {
					if (Lua.luaL_dostring(L, Str) != 0)
						Console.WriteLine(Lua.lua_tostring(L, -1));
				} catch (Exception E) {
					Console.WriteLine(E.Message);
				}
			}

			Console.WriteLine("Done!");
			Console.ReadLine();
		}
	}
}
#include <iostream>
#include <string>

extern "C"
{
#include "Lua54/include/lua.h"
#include "Lua54/include/lauxlib.h"
#include "Lua54/include/lualib.h"
}

#ifdef _WIN32
	#pragma comment(lib, "Lua54/liblua54.a")
#endif


int main()
{
	std::string cmd = "a = 7 + 11";

	lua_State* L = luaL_newstate();

	int r = luaL_dostring(L, cmd.c_str());

	if (r == LUA_OK)
	{
		lua_getglobal(L, "a");

		if (lua_isnumber(L, -1))
		{
			float a_in_cpp = (float)lua_tonumber(L, -1);
			std::cout << "a_in_cpp = " << a_in_cpp << std::endl;
		}
	}
	else
	{
		std::string errormsg = lua_tostring(L, -1);
		std::cout << errormsg << std::endl;
	}

	system("pause");
	lua_close(L);
	return 0;
}
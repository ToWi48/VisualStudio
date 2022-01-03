//#define GreenLua _declspec(dllexport);
//
// @Author Tom Wieﬂner
// @date 09.04.21
// 
// this file is part of the Global Company title
// 
// copyright by Tom Wieﬂner, using only with premission!
//

#include <stdio.h>
#include <string.h>
#include "Lua/include/lua.h"
#include "Lua/include/lualib.h"
#include "Lua/include/lauxlib.h"

#ifdef _WIN32
	#pragma comment(lib, "Lua/liblua54.a")
#endif

//GreenLua int GreenLua_test()
//{
//	return 88;
//}

//// eportet C functions - push
//GreenLua int GreenLua_pushstring(lua_State* L, char* key)
//{
//	lua_pushstring(L, key);
//}
//
//GreenLua int GreenLua_pushinteger(lua_State* L, int key)
//{
//	lua_pushinteger(L, key);
//}
//
//GreenLua int GreenLua_pushnumber(lua_State* L, double key)
//{
//	lua_pushnumber(L, key);
//}
//
//GreenLua int GreenLua_pushboolean(lua_State* L, int key)
//{
//	lua_pushboolean(L, key);
//}
//
//
//// exported C functions - to
//GreenLua char* GreenLua_tostring(lua_State* L, int key)
//{
//	return lua_tostring(L, key);
//}
//
//GreenLua int GreenLua_tointeger(lua_State* L, int key)
//{
//	return lua_tointeger(L, key);
//}
//
//GreenLua double GreenLua_tonumber(lua_State* L, int key)
//{
//	return lua_tonumber(L, key);
//}
//
//GreenLua int GreenLua_toboolean(lua_State* L, int key)
//{
//	return lua_toboolean(L, key);
//}
//
//
//// exported C functions - is
//GreenLua int GreenLua_isstring(lua_State* L, int key)
//{
//	return lua_isstring(L, key);
//}
//
//GreenLua int GreenLua_isinteger(lua_State* L, int key)
//{
//	return lua_isinteger(L, key);
//}
//
//GreenLua int GreenLua_isnumber(lua_State* L, int key)
//{
//	return lua_isnumber(L, key);
//}
//
//GreenLua int GreenLua_isboolean(lua_State* L, int key)
//{
//	return lua_isboolean(L, key);
//}
//
//// exported C functions - do
//GreenLua int GreenLua_dofile(lua_State* L, char* key)
//{
//	return luaL_dofile(L, key);
//}
//
//
//// exported C functions - global
//GreenLua int GreenLua_getglobal(lua_State* L, char* key)
//{
//	return lua_getglobal(L, key);
//}
//
//GreenLua void GreenLua_setglobal(lua_State* L, int key)
//{
//	lua_setglobal(L, key);
//}
//
//
//// exported C functions - register
//GreenLua void GreenLua_register(lua_State* L, lua_CFunction name, int func)
//{
//	lua_register(L, (lua_CFunction)name, func);
//}
//
//
//// exported C functions - call
//GreenLua void GreenLua_call(lua_State* L, int get, int set)
//{
//	lua_call(L, get, set);
//}
//
//
//// exported C functions - state
//GreenLua lua_State* GreenLua_state()
//{
//	return luaL_newstate();
//}
//
//
//// exported C functions - close
//GreenLua void GreenLua_close(lua_State* L)
//{
//	lua_close(L);
//}
//
//
//// exported C functions - openLibs
//GreenLua void GreenLua_openLibs(lua_State* L)
//{
//	luaL_openlibs(L);
//}
//
//
//// exported C functions - openLibs
//GreenLua char* GreenLua_checkLua(lua_State* L, int r)
//{
//	char* errormsg = "OK";
//	if (r != LUA_OK)
//	{
//		errormsg = lua_tostring(L, -1);
//		printf("Green: %s", errormsg);
//		return 0;
//	}
//	return errormsg;
//}
//
//
//


//
//// check lua

//
//// compile loaded lua
//void include(lua_State* L)
//{
//	char* filename = lua_tostring(L, -1); // last argument backwards
//	CheckLua(L, luaL_dofile(L, filename));
//}
//
//void addLuaString(lua_State* L, char* key, char* value)
//{
//	lua_pushstring(L, value);
//	lua_setglobal(L, key);
//}
//
//void addLuaNumber(lua_State* L, char* key, double value)
//{
//	lua_pushnumber(L, value);
//	lua_setglobal(L, key);
//}
//
//void addLuaInteger(lua_State* L, char* key, int value)
//{
//	lua_pushinteger(L, value);
//	lua_setglobal(L, key);
//}
//
//void addLuainten(lua_State* L, char* key, int value)
//{
//	lua_pushboolean(L, value);
//	lua_setglobal(L, key);
//}
//
//// lua C API
//void addCVariables(lua_State* L)
//{
//	addLuaString(L, "g_appPath", "C:/Users/Tom/source/repos/LuaC++/LuaC++/");
//}
//
//void addCFuncs(lua_State* L)
//{
//	lua_register(L, "include", include);
//}
//
//// call lua function
//int callLUAUpdate(lua_State* L, double deltaTime)
//{
//	lua_getglobal(L, "update");
//	lua_pushnumber(L, deltaTime);
//	lua_call(L, 1, 0);
//}
//
//

int CheckLua(lua_State* L, int r)
{
	if (r != LUA_OK)
	{
		//char* errormsg = lua_tostring(L, -1);
		//printf("Green: %s", errormsg);
		return 0;
	}
	return 1;
}

void Print(lua_State* L)
{
	int t = lua_gettop(L);
	char* text = lua_tostring(L, 1);
	lua_pop(L, 1);
	printf("Num: %d\n", t);
	printf("Print: %s\n", text);
}

int GetRotation(lua_State* L)
{
	printf("getRotation\n");
	int id = lua_tointeger(L, -1);
	lua_pop(L, 1);
	printf("PrintLn: %d\n", id);

	lua_pushnumber(L, 9);

	return 1;
}

int main() {
    lua_State* L = luaL_newstate();

	luaL_openlibs(L);
	//addCVariables(L);
	//addCFuncs(L);

	lua_register(L, "print", Print);
	//luaL_register(L, Print, "print");
	lua_register(L, "getRotation", GetRotation);

	int t = CheckLua(L, luaL_dofile(L, "C:/Users/Tom/source/repos/LuaC++/LuaC++/demo.lua"));

	// load main lua


	//lua_getglobal(L, "print");
	//lua_call(L, 0, 1);
	//lua_setglobal(L, "a");

	if (t)
	{
		if (lua_isnumber(L, -1))
		{
			float a_in_cpp = (float)lua_tonumber(L, -1);
			printf("Ausgabe: %lf", a_in_cpp);
		}
	}
	printf("Ausgabe: %s", lua_tostring(L, -1));
    lua_close(L);
    return 0;
}
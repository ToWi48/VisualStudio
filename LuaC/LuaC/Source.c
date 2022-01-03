//#define GreenLua _declspec(dllexport)

 // @Author Tom Wieﬂner
 // @date 09.04.21
 //
 // copilation based on x64!
 //  
 // this file is part of the Global Company title
 //
 // copyright by Tom Wieﬂner, using only with premission!

//hhhhh

#include <stdio.h>
#include <string.h>
#include "Lua/include/lua.h"
#include "Lua/include/lualib.h"
#include "Lua/include/lauxlib.h"

#ifdef _WIN32
	#pragma comment(lib, "Lua/liblua54.a")
#endif

//// eportet C functions - push
//GreenLua const char* GreenLua_pushstring(lua_State* L, char* key)
//{
//	return lua_pushstring(L, key);
//}

//GreenLua void GreenLua_pushinteger(lua_State* L, int key)
//{
//	lua_pushinteger(L, key);
//}

//GreenLua void GreenLua_pushnumber(lua_State* L, double key)
//{
//	lua_pushnumber(L, key);
//}
//
//GreenLua void GreenLua_pushboolean(lua_State* L, int key)
//{
//	lua_pushboolean(L, key);
//}
//
//
//// exported C functions - to
//GreenLua const char* GreenLua_tostring(lua_State* L, int key)
//{
//	return lua_tostring(L, key);
//}
//
//GreenLua lua_Integer GreenLua_tointeger(lua_State* L, int key)
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
//GreenLua void GreenLua_setglobal(lua_State* L, const char* key)
//{
//	lua_setglobal(L, key);
//}
//
//
//// exported C functions - register
//GreenLua void GreenLua_register(lua_State* L, char* name, lua_CFunction func)
//{
//	lua_register(L, name, func);
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
// exported C functions - state
//GreenLua lua_State* GreenLua_state()
//{
//	return luaL_newstate();
//}


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
//GreenLua const char* GreenLua_checkLua(lua_State* L, int r)
//{
//	const char* errormsg = "OK";
//	if (r != LUA_OK)
//	{
//		errormsg = lua_tostring(L, -1);
//		printf("Green: %s", errormsg);
//		return 0;
//	}
//	return errormsg;
//}
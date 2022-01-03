#pragma once

#ifdef LUAJITDLL_EXPORTS
#define LUAJITDLL_API __declspec(dllexport)
#else
#define LUAJITDLL_API __declspec(dllimport)
#endif
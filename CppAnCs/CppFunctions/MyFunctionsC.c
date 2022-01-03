#define GreenLua _declspec(dllexport)

GreenLua int GreenLua_test()
{
	return 77;
}

GreenLua int SubNumbers(int a, int b)
{
	return a - b;
}
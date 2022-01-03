using System;
using System.Text;
using System.Reflection;
using System.Threading;
using KeraLua;
using NLua;
using NLua.Exceptions;
using Lua = NLua.Lua;
using LuaFunction = NLua.LuaFunction;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

namespace NLuaTom
{
    class Program
    {
        static public void ToTest(string s)
        {
            Console.WriteLine(s);
        }
        static public void TestThreading()
        {
            using (NLua.Lua lua = new NLua.Lua())
            {
                object lua_locker = new object();
                //DoWorkClass doWork = new DoWorkClass();
                lua.RegisterFunction("dowork", typeof(Program).GetMethod("ToTest"));
                bool failureDetected = false;
                int completed = 0;
                int iterations = 10;

                for (int i = 0; i < iterations; i++)
                {
                    ThreadPool.QueueUserWorkItem(new WaitCallback(delegate (object o)
                    {
                        try
                        {
                            lock (lua_locker)
                            {
                                lua.DoString("dowork('Mega')");
                            }
                        }
                        catch (Exception e)
                        {
                            Console.Write(e);
                            failureDetected = true;
                        }

                        completed++;
                    }));
                }

                while (completed < iterations && !failureDetected)
                    Thread.Sleep(50);
            }
        }

        static void Main(string[] args)
        {
            TestThreading();
            Console.Read();
            //if( state.DoString("return 10 + 3*(5 + 2)")[0] is double myState)
            //{
            //    var res = myState;
            //    Console.WriteLine(Convert.ToString(res));
            //    Console.ReadLine();
            //}
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace LoadTester
{
    class Program
    {
        public const string LoadBalancerUrl = "http://104.196.213.144/load.php";
        public const int NumThreads = 500;
        public const int SleepTime = 0;

        private bool _run;

        static void Main(string[] args)
        {
            var p = new Program();
            p.Run();
        }

        public void Run()
        {
            _run = true;

            for (var i = 0; i < NumThreads; i++)
            {
                var thread = new Thread(TestLoad)
                {
                    Priority = ThreadPriority.AboveNormal,
                    IsBackground = true
                };

                thread.Start();
            }

            Console.WriteLine("Press ENTER to terminate load tester");
            Console.ReadLine();

            _run = false;
        }

        private void TestLoad()
        {
            while (_run)
            {
                var request = WebRequest.Create(LoadBalancerUrl);

                var response = (System.Net.HttpWebResponse)request.GetResponse();
                var responseCode = response.StatusCode.ToString();
                response.Close();

                Thread.Sleep(SleepTime);
            }
        }
    }
}

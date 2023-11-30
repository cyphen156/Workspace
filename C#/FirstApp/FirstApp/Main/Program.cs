using System;
using System.Collections.Generic; // 제네릭 컬렉션을 위한 네임스페이스
using Class;

namespace MyApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<object> list = new List<object>();
            List<object> list2 = new List<object>();
            list.Add(1);
            list.Add('C');
            list2.Add("Hello");
            list.Add(list2); // list2를 list에 추가

            Console.WriteLine("Hello World!");

            foreach (var item in list)
            {
                int index = list.IndexOf(item);
                Console.WriteLine($"Item: {item}" +
                    $", Type: {item.GetType()}, Index: {index}");
            }
            CleanRobot CRobot = new CleanRobot();
            CRobot.move();
            CRobot.clean();
        }
    }
}

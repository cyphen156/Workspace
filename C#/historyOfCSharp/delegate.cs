using System;

// 대리자 이벤트 핸들러
delegate void myEventHandler();

class Publisher
{
    // 공유가능한 메서드 이벤트 등록
    public static event myEventHandler myEvent;
    public void RunEvent()
    {
        myEvent();
    }
}

class Subscriber
{
    //구독자 클래스의 생성자 호출시 Publisher 클래스의 공유 메서드에 TestMethod 등록
    public Subscriber()
    {
        Publisher.myEvent += TestMethod;
    }

    public void TestMethod()
    {
        Console.WriteLine("이벤트 메서드 호출!!");
    }
}

class MainClass
{
    public static void Main(string[] args)
    {
        Publisher pub = new Publisher();
        Subscriber sub = new Subscriber();
        pub.RunEvent();
        return;
    }
}
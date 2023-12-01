using System;
using System.Runtime.CompilerServices;

class Logger
{
    public static void Log(string message,
    [CallerMemberName] string memberName = "",
    [CallerFilePath] string filePath = "",
    [CallerLineNumber] int lineNumber = 0)
    {
        Console.WriteLine($"Message: {message}");
        Console.WriteLine($"Member Name: {memberName}");
        Console.WriteLine($"File Path: {filePath}");
        Console.WriteLine($"Line Number: {lineNumber}");
    }
}

internal class Program
{
    static void Main(string[] args)
    {
        MyMethod();
    }

    private static void MyMethod()
    {
        Logger.Log("Something happened");
    }
}

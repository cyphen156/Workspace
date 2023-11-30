using System;

// 제네릭 클래스
class GenericClass <T>
{
    private T[] values;
    private int index;

    public GenericClass(int length)
    {
        values = new T[length];
        index = length;
    }

    public void setValue(T item, int index)
    {
        this.values[index] = item;
    }

    public void printClassValue()
    {
        foreach(T item in values)
        {
            Console.WriteLine(item);
        }
    }
}

class MainClass
{
    // 제네릭 메서드
    static void PrintValue<T>(T[] values)
    {
        foreach (var i in values)
        {
            Console.WriteLine(i);
        }
    }

    public static void Main(string[] args)
    {
        // 제네릭 메서드 구현
        int[] intValues = { 1, 2, 3 };
        double[] doubleValues = { 1.1, 2.2, 3.3 };

        PrintValue<int>(intValues);
        PrintValue<double>(doubleValues);

        // 제네릭 클래스 구현

        GenericClass<int> intArr = new GenericClass<int>(3);
        GenericClass<double> doubleArr = new GenericClass<double>(3);

        intArr.setValue(1, 0);
        intArr.setValue(2, 1);
        intArr.setValue(3, 2);

        doubleArr.setValue(3.33, 2);
        doubleArr.setValue(2.22, 1);
        doubleArr.setValue(1.11, 0);

        intArr.printClassValue();
        doubleArr.printClassValue();
        return;
    }
}
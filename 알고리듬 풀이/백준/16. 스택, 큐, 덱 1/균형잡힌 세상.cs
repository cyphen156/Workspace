// 4949 융택
// 균형잡힌 세상<
// 괄호 짝맞추기 문제

// 각 문자열은 마지막 글자(.)를 제외하고 영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")로 이루어져 있으며
// , 온점(".")으로 끝나고, 길이는 100글자보다 작거나 같다.
// --> 0 < Length <= 100호가 있다.
// ----> 열리는 괄호는 닫히는 괄호가 있다는 

// 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
// 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
// --> if ([) --> Error

// 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
// --> 닫히는 괄호가 있다면 반드시 열리는 괄것을 반드시 보장하지는 못한다.

// 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
// 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
// --> 괄호 안에 괄호가 또 나올 수 있다. 

// 스택 가져오기

class Stack
{
    private int size;
    private int[] datas;

    public Stack(int initSize)
    {
        size = -1;
        datas = new int[initSize];
    }

    ~Stack() { }

    public void Push(int inData)
    {
        if (size == datas.Length)
        {
            int newLength = datas.Length * 2;
            int[] newDatas = new int[newLength];
            for (int i = 0; i < datas.Length; i++)
            {
                newDatas[i] = datas[i];
            }
            datas = newDatas;
        }
        size++;
        datas[size] = inData;
    }

    public int Pop()
    {
        if (IsEmpty())
        {
            return -1;
        }
        return datas[size--];
    }

    private bool IsEmpty()
    {
        if (size == -1)
        {
            return true;
        }
        return false;
    }
    public int Empty()
    {
        if (size == -1)
        {
            return 1;
        }
        return 0;
    }
    public int Size()
    {

        return size + 1;
    }
    public int Top()
    {
        if (IsEmpty())
        {
            return -1;
        }
        return datas[size];
    }

    public void Clear()
    {
        size = -1;
    }
}

class Program
{
    public static void Main()
    {
        StreamReader sr = new StreamReader(Console.OpenStandardInput());
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());

        // ( --> 1
        // [ --> 2;

        // MaxSize = 100

        Stack stack = new Stack(100);
        while (true)
        {
            stack.Clear();
            string str = sr.ReadLine();
            if (str == ".")
            {
                break;
            }

            char[] datas = str.ToCharArray();
            bool isBalanced = true;
            foreach (char ch in datas)
            {
                if (ch == '(')
                {
                    stack.Push(1);
                }
                else if (ch == ')')
                {
                    if (stack.Top() != 1)
                    {
                        isBalanced = false;
                        break;
                    }
                    else
                    {
                        stack.Pop();
                    }
                }
                else if (ch == '[')
                {
                    stack.Push(2);
                }
                else if (ch == ']')
                {
                    if (stack.Top() != 2)
                    {
                        isBalanced = false;
                        break;
                    }
                    else
                    {
                        stack.Pop();
                    }
                }
            }

            // 스택이 비어있지 않음
            if (stack.Empty() != 1)
            {
                isBalanced = false;
            }

            if (isBalanced)
            {
                sw.WriteLine("yes");
            }
            else
            {
                sw.WriteLine("no");
            }
            sw.Flush();
        }
    }
}
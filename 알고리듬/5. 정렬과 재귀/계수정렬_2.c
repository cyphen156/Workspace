#define MAX_SIZE 0x7fffffff

int arr[MAX_SIZE] = { 0 };

void Insert(int data)
{
    arr[data]++;
}

int Search(int data)
{
    return arr[data];
}

int Order(int data)
{
    int result = 0;
    for (int i = 0; i <= data; ++i)
    {
        result += arr[i];
    }

    return result;
}
/**
 * 백준 균형잡힌 세상_4949
 * 문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고, 문자열이 균형을 이루는 조건은 아래와 같다.
 * 모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
 * 모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
 * 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
 * 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
 * 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
 * 앞서 푼 괄호의 응용문제
 * 이 문제는 C와 C#으로 풀어놓은 것이 있어 이것도 같이 공유하겠다.
 * 
 * 제한사항
 *****************************************
 * 온점이 들어오면 문자열은 끝난다.        *
 * 0 < strlen <= 100                     *
 * 첫번째 문자 입력이 '.'이라면 루프 종료  *
 *****************************************
 *
 *
 *
 * 주의
 * " ."이 친구도 종료 시퀀스가 아닌 균형잡힌 문자열이다. 
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <string>

using namespace std;

static char stack[101];
static int top = -1;

void Push(char data);
char Pop();
bool IsEmpty();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1)
    {
        string str;
        getline(cin, str);  

        top = -1;
        // 종료 시퀀스
        if (str.front() == '.')
        {
            break;
        }

        bool isVPS = true;

        for (int i = 0; i < str.length(); ++i)
        {
            switch (str[i])
            {
            case '(':
                Push('(');
                break;
            case '[':
                Push('[');
                break;
            case ')':
            {
                char temp = Pop();
                if (temp != '(')
                {
                    isVPS = false;
                    goto ESCAPE;
                }
                break;
            }
            case ']':
            {
                char temp = Pop();
                    if (temp != '[')
                    {
                        isVPS = false;
                        goto ESCAPE;
                    }
                    break;
            }
            default:
                break;
            }
        }
        
        ESCAPE:
        // 모두 비워지지 않았음
        if (top != -1)
        {
            isVPS = false;
        }

        if (isVPS)
        {
            cout << "yes" << '\n';
        }
        else 
        {
            cout << "no" << '\n';
        }
    }
    return 0;
}

void Push(char data)
{
    stack[++top] = data;
}

char Pop()
{
    if (IsEmpty())
    {
        // 빈 스택에서 Pop 시도시 널문자 반환 ==> 특수조건으로 활용
        return '\0';
    }
    return stack[top--];
}

bool IsEmpty()
{
    if (top < 0)
    {
        return true;
    }
    
    return false;
}
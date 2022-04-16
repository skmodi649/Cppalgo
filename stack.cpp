#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> stk;

    string s = "{[]}";
    int p = 0, sq = 0, cu = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            stk.push('[');
            sq++;
        }
        else if (s[i] == '(')
        {
            stk.push('(');
            p++;
        }
        else if (s[i] == '{')
        {
            stk.push('{');
            cu++;
        }
    }

        for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == ')' && stk.top() == '(')
        {
            stk.pop();
            p--;
        }
        else if (s[i] == ']' && stk.top() == '[')
        {
            stk.pop();
            sq--;
        }
        else if (s[i] == '}' && stk.top() == '{')
        {
            stk.pop();
            cu--;
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            break;
        }
    }
    if (p == 0 && cu == 0 && sq == 0)
    {
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}
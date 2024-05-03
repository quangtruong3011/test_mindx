#include <iostream>
#include <string>
#include <stack>

using namespace std;

void encodeString(string str)
{
    stack<pair<char, int>> charStack;

    for (char ch : str)
    {
        if (charStack.empty() || charStack.top().first != ch)
        {
            charStack.push(make_pair(ch, 1));
        }
        else
        {
            charStack.top().second++;
        }
    }

    stack<pair<char, int>> tempStack;
    while (!charStack.empty())
    {
        tempStack.push(charStack.top());
        charStack.pop();
    }

    while (!tempStack.empty())
    {
        cout << tempStack.top().first << tempStack.top().second;
        tempStack.pop();
    }
}

int main()
{
    string str;
    cin >> str;
    encodeString(str);
    return 0;
}

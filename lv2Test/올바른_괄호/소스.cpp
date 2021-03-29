//https://programmers.co.kr/learn/courses/30/lessons/12909
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0, close = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') open++;
        else close++;
        if (open < close) return false;
    }
    if (open == close) return true;
    else return false;

}

int main()
{
    cout << solution("()()") << endl;

    return 0;
}
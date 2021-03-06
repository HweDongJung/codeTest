//https://programmers.co.kr/learn/courses/30/lessons/12903
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

string solution(string s) 
{
    char str[100];
    
    string answer = "";
    strcpy_s(str, s.c_str());

    if (s.size() % 2 == 0)
    {
        answer += str[s.size() / 2 - 1];
        answer += str[s.size() / 2];
    }
    else
    {
        answer += str[s.size() / 2];
    }
    
    return answer;
}

int main()
{
    string ans = solution("abcde");
    cout << ans << endl;
    ans = solution("qwer");
    cout << ans << endl;

    return 0;
}
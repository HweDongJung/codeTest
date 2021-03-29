// 짝지어 제거하기 https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
int solution(string s);

int solution(string s) //vector의 push, pop이용 
{
    vector<char> str;

    for (int i = 0; i < s.size(); i++)
    {
        if (str.size() == 0) str.push_back(s[i]);
        else if (str[str.size() - 1] == s[i])str.pop_back();
        else str.push_back(s[i]);
    }
    if (str.size() == 0) return 1;
    else return 0;

}

int main()
{
    /*string s = "asdfasd";
    vector<bool> str = {true,true,false,true,true};
    int a = find(str.begin()+1, str.end(), true) - str.begin();
    s.erase(0, 2);*/
    cout << solution("baabaa") << " ";

    return 0;
}

int solution2(string s) //문자열 직접 erase.. 
{
    int answer = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            if (i == 0) i = -1;
            else i = i - 2;
        }
        if (s == "") return 1;
    }
    if (s == "") answer = 1;
    return answer;
}
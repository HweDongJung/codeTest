//https://programmers.co.kr/learn/courses/30/lessons/12916
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    char str[50];
    int pnum = 0, ynum = 0;
    strcpy_s(str,s.c_str());

    for (int i = 0; i < s.size(); i++)
    {
        if (str[i] == 'p' || str[i] == 'P') pnum++;
        else if (str[i] == 'y' || str[i] == 'Y') ynum++;
    }

    if (pnum != ynum) answer = false;

    return answer;
}

int main()
{
    string ans = "pyY";
    cout << solution(ans) << endl;


}
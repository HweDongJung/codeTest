//https://programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool solution(string s) 
{
    char str[7];
    if (s.size() != 4 && s.size() != 6) return false;
    strcpy_s(str, s.c_str());
    for (int i = 0; i < s.size(); i++)
    {
        //cout << (int)str[i] << endl;
        if ((int)str[i] < 48 || (int)str[i] > 57) return false;
    }

    return true;
}



int main()
{
    cout << solution("1234") << endl;

    return 0;
}
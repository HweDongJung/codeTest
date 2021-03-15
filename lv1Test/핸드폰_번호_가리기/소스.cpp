//https://programmers.co.kr/learn/courses/30/lessons/12948
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

string solution(string phone_number) 
{
    char num[20];
    strcpy_s(num, phone_number.c_str());
    string answer = "";

    for (int i = 0; i < phone_number.size(); i++)
    {
        if (i >= phone_number.size() - 4) answer += num[i];
        else answer += "*";
    }

    return answer;
}


int main()
{

    cout << solution("01033334444") << endl;


    return 0;
}
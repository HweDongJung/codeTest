//https://programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

string solution(string s) 
{
    char str[8000];
    int count = 0;
    strcpy_s(str, s.c_str());

    for (int i = 0; i < s.size(); i++)
    {
        if (str[i] == ' ') count = 0;
        else if (count % 2 == 0) //0을 포함한 짝수 인덱스에 있는 단어, 대문자로 변환
        {
            if ((int)str[i] > 96)//소문자일경우
            {
                str[i] -= 32;
                count++;
            }
            else count++; //대문자일 경우 그냥 패스
        }
        else //홀수 인덱스, 소문자로 변환
        {
            if ((int)str[i] < 96) //대문자일 경우 소문자로 변환
            {
                str[i] += 32;
                count++;
            }
            else count++; //이미 소문자일 경우 패스 
        }
    }
    string answer(str);

    return answer;
}

int main()
{
    string ans = "try hello world";
    cout << solution(ans) << endl;
    return 0;
}
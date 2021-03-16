//https://programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool isNotValid(char a);
string solution(string new_id);

int main()
{
    cout << solution("abcdefghijklmn.p") << endl;;

    return 0;
}

string solution(string new_id)
{
    string answer = "";
    char id[1000];
    vector<char> str;
    strcpy_s(id,new_id.c_str());
    for (int i = 0; i < new_id.size(); i++)
    {
        str.push_back(id[i]);
    }
    
    for (int i = 0; i < str.size(); i++)//1단계, 대문자 -> 소문자
    {
        if ((int)str[i] >= 65 && (int)str[i] <= 90) str[i] += 32;
    }
   
    for (int i = 0; i < str.size(); i++) //2 단계 유효하지 않은 문자 빼기
    {
        if (isNotValid(str[i]))
        {
            str.erase(str.begin()+i);
            i--;
        }
    }
    for (int i = 0; i < str.size()-1; i++) //3단계
    {
        if ((int)str[i] == 46 && (int)str[i+1] == 46)
        {
            str.erase(str.begin() + i);
            i--;
        }
    }
   
    if (str.size() != 0)
    {
        //4단계 처음의 마침표 검사
        if ((int)str[0] == 46) str.erase(str.begin() + 0);
    }
    if (str.size() != 0)
    {
        // 4단계 끝의 마침표 검사 
        if ((int)str[str.size() - 1] == 46) str.pop_back();
    }
    
    if (str.size() == 0) str.push_back('a'); //5단계
    if (str.size() >= 16) //6단계
    {
        str.erase(str.begin() + 15, str.end());
        if ((int)str[str.size()-1] == 46) str.pop_back();
    }

    if (str.size() <= 2) //7단계
    {
        char last = str[str.size() - 1];
        for (; str.size() <= 2;)
        {
            str.push_back(last);
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        answer += str[i];
    }

    return answer;
}

bool isNotValid(char a)
{
    if ((int)a >= 48 && (int)a <= 57) return false; //숫자인가
    else if ((int)a >= 97 && (int)a <= 122) return false; //소문자인가
    else if ((int)a == 45 || (int)a == 46 || (int)a == 95) return false; // '-', '_', '.'인가 
    else return true; //그 외의 문자는 유효하지 않음

}
//https://programmers.co.kr/learn/courses/30/lessons/12926
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

string solution(string s, int n)
{
    
    int size = s.size();
    char str[8000];
    strcpy_s(str, s.c_str());

    for (int i = 0; i < s.size(); i++)
    {
        if (str[i] == ' ') {}
        else if ((int)str[i] <= 90)
        {
            if (((int)str[i] + n) > 90) str[i] = str[i] + (n - 26);
            else str[i] = str[i] + n;
        }
        else
        {
            if (((int)str[i] + n) > 122) str[i] = str[i] + (n - 26);
            else str[i] = str[i] + n;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << str[i];
    }
    string answer(str);

    return answer;
}

int main()
{

    string ans = "A b c"; //테스트 케이스
    /*char as[50];
    char A = 'a';
    strcpy_s(as, ans.c_str());
    char B = ' ';
    A = A + 1;
    cout << as[0] << as[1] << as[2] << endl << ans.size();*/

    ans = solution(ans , 4);

        cout << ans << " ";


    return 0;
}
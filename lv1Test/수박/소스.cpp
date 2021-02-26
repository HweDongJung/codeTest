//https://programmers.co.kr/learn/courses/30/lessons/12922
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n)
{
    string answer = "";
    
    for (int i = 1; i <= n/2; i++)
    {
        answer = answer + "¼ö¹Ú";
    }
    if (n % 2 == 1) answer = answer + "¼ö";

    return answer;
}

int main()
{
    cout << solution(5);
    return 0;
}
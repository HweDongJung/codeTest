//https://programmers.co.kr/learn/courses/30/lessons/12924
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool reach(int start, int reac);

int solution(int n) 
{
    int answer = 1;

    for (int i = 1; i <= n / 2; i++)
    {
        if (reach(i, n)) answer++;
    }


    return answer;
}

bool reach(int start, int reac)
{
    int temp = 0;
    for(int i = start; temp < reac; i++)
    {
        temp += i;
    }
    if (temp == reac) return true;
    else return false;
}

int main()
{
    cout << solution(15) << endl;

    return 0;
}
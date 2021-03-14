//https://programmers.co.kr/learn/courses/30/lessons/12931
#include <iostream>
#include <cmath>

using namespace std;
int solution(int n)
{
    int answer = 0, temp=n;

    for (;;)
    {
        if (temp == 0) break;
        answer += temp % 10;
        temp /= 10;
    }

    return answer;
}

int main()
{
    cout << solution(123)<< endl;

    return 0;
}
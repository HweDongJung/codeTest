//https://programmers.co.kr/learn/courses/30/lessons/12932
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
    vector<int> answer;
    long long temp = n;
    for (;;)
    {
        answer.push_back(temp % 10);
        cout << temp%10 <<endl;
        temp /= 10;
        if (temp == 0) break;
    }

    return answer;
}

int main()
{
    long long n = 12345;
    solution(n);
    return 0;
}
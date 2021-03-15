//https://programmers.co.kr/learn/courses/30/lessons/12933
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0 , temp=1;
    vector<int> a;
    answer = n;
    for (;;)
    {
        if (answer == 0) break;
        a.push_back(answer % 10);
        answer /= 10;
    }
    sort(a.rbegin(),a.rend());
    answer = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        answer += a[i] * temp;
        temp *= 10;
    }

    return answer; 
}

int main()
{
    cout << solution(118372) << endl;

    return 0;
}
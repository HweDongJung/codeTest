//https://programmers.co.kr/learn/courses/30/lessons/12945
#include <string>
#include <vector>
#include <iostream>
//숫자 A, B, C가 있다고 하면 (A + B) % C의 값은 ( ( A % C ) + ( B % C) ) % C와 같다는 성질을 이용 

using namespace std;

vector<long long> fibo = {1,1};

int solution(int n) 
{
    
    for (int i = 2; i < n; i++)
    {
        fibo.push_back((fibo[i - 1] + fibo[i - 2])%1234567);
    }

    return fibo[n-1];
}

int main()
{
    cout << solution(5) << endl;

    return 0;
}
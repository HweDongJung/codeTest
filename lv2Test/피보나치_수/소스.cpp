//https://programmers.co.kr/learn/courses/30/lessons/12945
#include <string>
#include <vector>
#include <iostream>
//���� A, B, C�� �ִٰ� �ϸ� (A + B) % C�� ���� ( ( A % C ) + ( B % C) ) % C�� ���ٴ� ������ �̿� 

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
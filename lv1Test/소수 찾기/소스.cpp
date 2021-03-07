//https://programmers.co.kr/learn/courses/30/lessons/12921
/*
에라토스테네스의 체 
주어진 자연수 N이 소수이기 위한 필요충분 조건은 
N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다. 
*/
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) 
{
    if (n == 2) return 1;
    else if (n == 3) return 2; //n=2,3일때의 처리가 까다로워서 걍 첨에 if문 처리 
    vector<int> sosu = {2,3}; //소수목록 
    int temp;
    
    for (int i = 4; i <= n; i++) //4부터 검사시작 
    {
        //if (i % 2 == 0)continue; //짝수 넘기기
        temp = sqrt(i);

        for (int j = 0; j < sosu.size(); j++)
        {
            if (i % sosu[j] == 0) break;
            else if (sosu[j] >= temp)
            {
                sosu.push_back(i); //소수 추가
                break;
            }
        }
    }

    return sosu.size();
}

int solution2(int n)
{
    vector<bool> sosu(n + 1, true);
    int answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (sosu[i] == true)
        {
            for (int j = 2; i * j <= n; j++) sosu[j * i] = false;
            answer++;
        }
    }
    return answer;
}

int main()
{
    cout << solution2(10) << endl;

    return 0;
}
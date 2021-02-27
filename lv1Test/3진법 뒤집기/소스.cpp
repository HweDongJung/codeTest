//https://programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) 
{
    int temp=n, answer = 0;
    vector<int> ans;

    for (;;) // 3진법 수로 변환하는 반복문 
    {
        if (temp < 3)
        {
            ans.push_back(temp);
            break;
        }
        ans.push_back(temp % 3); //나눈 나머지 push
        temp = temp / 3; //3으로 나누기 
    }
    
    for (int i = ans.size(); i >= 1; i--) //뒤집힌 3진법 수를 다시 10진법으로 변환 
    {
        temp = pow(3, ans.size()-i);
        answer += (ans[i - 1] * temp);
    }

    return answer;
}

int main()
{
    cout << solution(45);
    return  0;
}
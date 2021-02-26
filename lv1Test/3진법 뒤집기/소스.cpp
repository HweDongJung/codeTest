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

    for (;;)
    {
        if (temp < 3)
        {
            ans.push_back(temp);
            break;
        }
        ans.push_back(temp % 3);
        temp = temp / 3;
    }
    
    for (int i = ans.size(); i >= 1; i--)
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
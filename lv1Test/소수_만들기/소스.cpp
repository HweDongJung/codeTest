//https://programmers.co.kr/learn/courses/30/lessons/12977
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) 
{
    int answer = 0;

    vector<bool> sosu(3001,true); 

    for (int i = 2; i < 3001; i++) //3000까지 소수 전부 판별 
    {
        if (sosu[i] == true)
        {
            for (int j = 2; i * j < 3001; j++) sosu[i * j] = false;
        }
    }

    for (int i = 0; i <= nums.size() - 3; i++)
    {
        for (int j = i + 1; j <= nums.size() - 2; j++)
        {
            for (int k = j + 1; k <= nums.size() - 1; k++)
            {
                if (sosu[nums[i] + nums[j] + nums[k]] == true) answer++; //소수면 answer++
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = { 1,2,3,4 };
    cout << solution(nums) << endl;

    return 0;
}
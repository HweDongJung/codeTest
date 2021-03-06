﻿//https://programmers.co.kr/learn/courses/30/lessons/42862
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int a, answer = 0;
    
    vector<int> have;
    vector<int>::iterator fnd, fnd1;

    for (int i = 1; i <= n; i++)
    {
        fnd = find(lost.begin(), lost.end(), i);
        fnd1 = find(reserve.begin(), reserve.end(), i);
        if (fnd != lost.end() && fnd1 != reserve.end())
        {
            a = fnd - lost.begin();
            lost.erase(lost.begin() + a);
            a = fnd1 - reserve.begin();
            reserve.erase(reserve.begin() + a);
        }
    }
    answer = n - lost.size();

    for (int i = 0; i < n; i++) //vector have : 1 = have, 0 = not have
    {
        fnd = find(lost.begin(), lost.end(), i + 1);
        if (fnd != lost.end()) have.push_back(0);
        else have.push_back(1);
    }
    have.push_back(1);

    for (int i = 0; i < reserve.size(); i++)
    {
        
        if (reserve[i] == 1)
        {
            if (have[reserve[i]] == 0) { have[1] = 1; answer++; }
        }
        else
        {
            if (have[reserve[i] - 2] == 0)
            {
                have[reserve[i] - 2] = 1; answer++;  
            }
            else if (have[reserve[i]] == 0)
            {
                have[reserve[i]] = 1; answer++;  
            }
        }
    }
    return answer;
}

int student[35];
int solution2(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    for (int i : reserve) student[i]++;
    for (int i : lost) student[i]--; 
    //student 배열의 원소 -1 : 도둑맞아서 빌려야 하는 경우, 0인경우 : 가지고 있는 경우, 1 : 본인것과 빌려줄 여분도 있는 경우

    for (int i = 1; i <= n; i++)
    {
        if (student[i] == -1)
        {
            if (student[i-1] == 1)
            {
                student[i - 1] = 0;
                student[i] = 0;
            }
            else if (student[i + 1] == 1)
            {
                student[i + 1] = 0;
                student[i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (student[i] >= 0) answer++;
    }
    return answer;
}

int main()
{
    vector<int> lost = { 3 }, reserve = { 1,3,5 };
    int n = 5;
    cout << solution2(n, lost, reserve) << endl;



}
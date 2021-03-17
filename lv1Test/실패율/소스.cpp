//https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int reach_cant[501] = { 0, }, reach[501] = { 0, }; //reach_cant 스테이지별 도달했지만 클리어 못한 플레이어, reach는 도달한 플레이어 수 
vector<double> fail;

bool cmp(int a, int b)
{
    
    if (fail[a - 1] == fail[b - 1]) return a < b;
    else fail[a] < fail[b];
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    int temp=0;
    //for (int i = 0; i < N; i++) answer.push_back(i + 1);
    
    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] == N + 1)
        {
            for (int j = 1; j <= N; j++) reach[j]++;
            continue;
        }
        reach_cant[stages[i]]++;
        for (int j = 1; j <= stages[i]; j++)
        {
            reach[j]++;
        }
    }

    
    for (int i = 1; i <= N; i++)
    {
        if (reach[i] == 0) fail.push_back(0);
        else fail.push_back((double)reach_cant[i] / (double)reach[i] );
    }
    //cout << fail[1] << endl;

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (fail[temp] < fail[i]) temp = i;
        }
        answer.push_back(temp+1);
        fail[temp] = -1;
    }

    return answer;
}

vector<int> solution2(int N, vector<int> stages) // pair, cmp를 이용한 풀이
{
    vector<int> answer;
    int temp = 0;
    for (int i = 0; i < N; i++) answer.push_back(i + 1);

    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] == N + 1)
        {
            for (int j = 1; j <= N; j++) reach[j]++;
            continue;
        }
        reach_cant[stages[i]]++;
        for (int j = 1; j <= stages[i]; j++)
        {
            reach[j]++;
        }
    }


    for (int i = 1; i <= N; i++)
    {
        if (reach[i] == 0) fail.push_back(0);
        else fail.push_back((double)reach_cant[i] / (double)reach[i]);
    }
    //cout << fail[1] << endl;

    sort(answer.begin(), answer.end(), cmp);
    

    return answer;
}

int main()
{
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    stages = solution2(5, stages);
    for (int i = 0; i < stages.size(); i++)
    {
        cout << stages[i] << endl;
    }
    return 0;
}
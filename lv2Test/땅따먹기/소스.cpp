//https://programmers.co.kr/learn/courses/30/lessons/12913
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; //다이나믹 프로그래밍 이용

vector<vector<int>> DP; //현재 단계까지의 최대값 저장 

int solution(vector<vector<int> > land)
{
    vector<int> temp;
    temp.push_back(land[0][0]);
    temp.push_back(land[0][1]);
    temp.push_back(land[0][2]);
    temp.push_back(land[0][3]); // 첫번째 영토의 값 저장 하고 
    DP.push_back(temp);
    temp.clear();
    for (int i = 1; i < land.size(); i++)
    {
        temp.push_back(land[i][0] + max({ DP[i - 1][1], DP[i - 1][2], DP[i - 1][3] }));
        temp.push_back(land[i][1] + max({ DP[i - 1][0], DP[i - 1][2], DP[i - 1][3] }));
        temp.push_back(land[i][2] + max({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][3] }));
        temp.push_back(land[i][3] + max({ DP[i - 1][0], DP[i - 1][1], DP[i - 1][2] }));
        DP.push_back(temp);
        temp.clear();
    } // 현재 영토를 고를 경우에서 더할 이전 영토까지의 최대값 중 제일 큰 값 고르기 

    int answer = *max_element(DP[land.size() - 1].begin(), DP[land.size() - 1].end());
    return answer;
}

int main()
{

    cout << solution({ {1,2,3,5}, {5,6,7,8}, {4,3,2,1} }) << endl;


    return 0;
}
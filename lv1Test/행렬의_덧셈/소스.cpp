﻿//https://programmers.co.kr/learn/courses/30/lessons/12950
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer = arr1;
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr1[i].size(); j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    
    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { {1,2}, {2,3} }, arr2 = { {3,4}, {5,6} };

    solution(arr1, arr2);

    return 0;
}
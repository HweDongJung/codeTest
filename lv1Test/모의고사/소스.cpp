//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> stu1 = { 1,2,3,4,5 }, stu2 = { 2, 1, 2, 3, 2, 4, 2, 5 }, stu3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int score1 = 0, score2 = 0, score3 = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == stu1[i % 5]) score1++;
    }

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == stu2[i % 8]) score2++;
    }

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == stu3[i % 10]) score3++;
    }
    
    if (score1 > score2 && score1 > score3) answer.push_back(1);
    else if (score1 < score2 && score3 < score2) answer.push_back(2);
    else if (score1 < score3 && score2 < score3) answer.push_back(3);
    else if (score1 == score2 && score1 > score3)
    {
        answer.push_back(1); answer.push_back(2);
    }
    else if (score1 == score3 && score1 > score2)
    {
        answer.push_back(1); answer.push_back(3);
    }
    else if (score2 == score3 && score2 > score1)
    {
        answer.push_back(2); answer.push_back(3);
    }
    else
    {
        answer.push_back(1); answer.push_back(2); answer.push_back(3);
    }


    return answer;
}


int main()
{

    vector<int> ans = { 1, 3, 2, 4, 2 }; //테스트 케이스

    ans = solution(ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
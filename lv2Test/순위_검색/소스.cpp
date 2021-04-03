//https://programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <sstream>
#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

bool checkInfo(tuple<string, string, string, string, int> tup, string lang, string job, string career, string food, int score);

vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer(query.size(),0);
    vector<tuple<string, string, string, string, int>> query_tup; //query의 언어 직군 경력 소울푸드 점수 
    for (int i=0; i< query.size(); i++)
    {
        stringstream ss(query[i]);
        string lang, job, career, food;
        int score;
        ss >> lang;
        ss >> job; 
        ss >> job;
        ss >> career;
        ss >> career;
        ss >> food;
        ss >> food;
        ss >> score;
        query_tup.push_back(make_tuple(lang, job, career, food, score));
    }

    for (int i = 0; i < info.size(); i++)
    {
        string lang, job, career, food;
        int score;
        stringstream ss(info[i]);
        ss >> lang;
        ss >> job;
        ss >> career;
        ss >> food;
        ss >> score;
        for (int j = 0; j < query.size(); j++) if (checkInfo(query_tup[j], lang, job, career, food, score)) answer[j]++;
    }

    return answer;
}

int main()
{
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210",
        "python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250",
        "- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<int> nums = solution(info, query);

    for (int i = 0; i < nums.size(); i++) cout << nums[i] << endl;

    return 0;
}

bool checkInfo(tuple<string, string, string, string, int> tup, string lang, string job, string career, string food, int score)
{
    
    bool a, b, c, d, e;
    if (get<0>(tup) == "-") a = true;
    else a = (lang == get<0>(tup));

    if (get<1>(tup) == "-") b = true;
    else b = (job == get<1>(tup));

    if (get<2>(tup) == "-") c = true;
    else c = (career == get<2>(tup));

    if (get<3>(tup) == "-") d = true;
    else d = (food == get<3>(tup));

    e = (score >= get<4>(tup));

    return (a && b && c && d && e);
}
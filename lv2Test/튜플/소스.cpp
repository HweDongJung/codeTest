//https://programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <iostream>
#include <algorithm> 
#include <sstream>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) 
{
    int num;
    char ch;
    vector<int> answer, temp;
    vector<vector<int>> s_vec;
    stringstream ss(s);
    
    while (true)
    {
        ch = ss.get();
        if ((int)ch == -1) break; //탈출문 
        else if ((int)ch > 47 && (int)ch < 58)
        {
            ss.unget();
            ss >> num;
            temp.push_back(num);
        }
        else if (ch == '}')
        {
            s_vec.push_back(temp);
            temp.clear();
        }
    }

    sort(s_vec.begin(), s_vec.end(), cmp); //size 오름차순 정렬

    for (int i = 0; i < s_vec.size(); i++)
    {
        for (int j = 0; j < s_vec[i].size(); j++)
        {
            if (find(answer.begin(), answer.end(), s_vec[i][j]) == answer.end()) answer.push_back(s_vec[i][j]); //answer에 없는 값이라면 push
        }

    }

    return answer;
}

int main()
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
   

    vector<int> answer = solution(s);

    for (int i = 0; i < answer.size(); i++) cout << answer[i] << endl;

    return 0;
}
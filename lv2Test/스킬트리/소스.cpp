//https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    string skill_pick ="";

    for (int i = 0; i < skill_trees.size(); i++)
    {
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            if (skill.find(skill_trees[i][j]) < 27) skill_pick += skill_trees[i][j]; // skill에 있는 스킬일 경우 문자열 변수에 추가
     
        }
        if (skill.find(skill_pick) == 0 || skill_pick == "") answer++; // skill_pick이 find() == 0,즉 처음부터 일치하거나 아예 자유스킬만 찍은 경우에만 answer++
        skill_pick = "";
    }


    return answer;

}


int main()
{
    cout << solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });

    return 0;
}
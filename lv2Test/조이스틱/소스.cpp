//https://programmers.co.kr/learn/courses/30/lessons/42860
#include <string>
#include <vector>
#include <algorithm>
//BBAAAAAAAAAABB
//한 커서에서 원하는 알파벳을 만들기 위한 무빙 개수 + 조이스틱 커서를 옮기는 개수 

using namespace std;

pair<bool,int> leastMove(vector<int> name, int point) 
{
    int pick, move1=0;

    for (int i = point+1; i < name.size(); i++)
    {
        move1++;
        if (name[i] == 0) pick = i;
    }
    
    if (move1 > name.size() - move1) return make_pair(false, name.size() - move1); //역방향으로 
    else return make_pair(true, move1); //정방향
}

int leastAlphabet(char a)
{
    int b = (int)a - 64;
    if (b - 1 < 27 - b) return b - 1;
    else 27 - b;
}

int solution(string name) 
{
    int answer = 0, point = 0;
    vector<int> name1(name.size(), 0); //지나갈 필요 없는곳 or 이미 지나간 곳은 0아님
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A') name1[i]++; //'A'인 곳은 지나갈 필요 없으므로 ++
        answer += leastAlphabet(name[i]);
    }
    name1[1] = 1;
    pair<bool, int> a;
    for (;;)
    {
        a = leastMove(name1, point);
        if (a.first) //정방향 
        {
            for (int i = 1; i <= a.second; i++) name1[point + i]++;

            point = 
        }
        else
    }

    return answer;
}
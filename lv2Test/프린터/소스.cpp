//https://programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

bool comp(pair<int,int> pair1, pair<int,int> pair2) 
{ 
    return pair1.first < pair2.first; 
}

int solution(vector<int> priorities, int location) 
{
    int answer = 0, max; //max에 현재 문서중 최대 우선도를 저장
    vector<pair<int, int>> priorities_pair; //첫번째는 우선도, 두번째는 location

    for (int i = 0; i < priorities.size(); i++)
    {
        priorities_pair.push_back(make_pair(priorities[i], i)); //각 문서의 우선도와 위치 저장
    }
    max = *max_element(priorities.begin(), priorities.end());
    for (;;)
    {
        if(priorities_pair[0].first == max)
        {
            answer++;
            if (priorities_pair[0].second == location) break; //원하던location 문서를 출력했을 시 for문 탈출 
            priorities_pair.erase(priorities_pair.begin()+0);
            const auto max_pair = *max_element(priorities_pair.begin(), priorities_pair.end(),comp); //pair의 second값중 우선순위 최대값을 가지는 pair 가져오기
            max = max_pair.first; // 그 pair의 우선순위 값 max로 옮기기
        }
        else
        {
            priorities_pair.push_back(make_pair(priorities_pair[0].first, priorities_pair[0].second));
            priorities_pair.erase(priorities_pair.begin() + 0);
        }
    }


    return answer;
}


int main()
{
    cout << solution({ 1,1,9,1,1,1 }, 0) << endl;

    return 0;
}
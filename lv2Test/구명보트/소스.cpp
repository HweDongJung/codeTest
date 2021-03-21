//https://programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    vector<int> peoples = people;
    sort(peoples.rbegin(), peoples.rend());//내림차순 정렬

    cout << peoples[0] << endl;

    for (int i = 0; i < peoples.size();)
    {
        if (peoples[i] <= limit / 2)
        {
            if ((peoples.size() - i) % 2 == 0) answer += ((peoples.size() - i) / 2); //남은사람
            else answer = ++answer + ((peoples.size() - i) / 2) ;

            break;
        }
        if (peoples[i] + peoples[peoples.size() - 1] <= limit)
        {
            peoples.pop_back();
            answer++;
            i++;
        }
        else
        {
            i++;
            answer++;
        }
        if (i == peoples.size()-1)
        {
            answer++;
            break;
        }
    }


    return answer;
}

int main()
{
    cout << solution({160,150,140,60,50,40}, 200) << endl;

    return 0;
}
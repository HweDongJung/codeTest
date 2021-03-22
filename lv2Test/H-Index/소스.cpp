//https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//3 0 6 1 5 정렬 -> 6 5 3 1 0
using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0, count =0;
    vector<int> cit = citations;
    sort(cit.rbegin(), cit.rend());
    if (*max_element(cit.begin(), cit.end()) == 0) return 0;
    for (int i = cit[0]; i >= 0; i--)
    {
        for (int j = 0; j < cit.size(); j++)
        {
            if (cit[j] >= i) count++;
            else if (count >= i && count >= cit.size()-j) return i;
            else
            {
                count = 0;
                break;
            }
        }
    }
    answer = citations.size();
    return answer;
}

int main()
{
    cout << solution({ 2,2 }) << endl;
    
    return 0;
}
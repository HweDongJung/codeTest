#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) 
{
    int answer = 0,money=0;
    vector<int> req = d;
    sort(req.begin(), req.end());
    for (int i = 0; i < req.size(); i++)
    {
        money += req[i];
        answer++;
        if (budget == money) break;
        else if (budget < money)
        {
            answer--;
            break;
        }
    }
    return answer;
}

int main()
{
    vector<int> d = { 2,2,3,3 };

    cout << solution(d, 11) << endl;

    return 0;
}
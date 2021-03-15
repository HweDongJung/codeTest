//https://programmers.co.kr/learn/courses/30/lessons/12943
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) 
{
    int answer = 0;
    for (long long i = num; i != 1;)
    {
        
        if (i % 2 == 0)
        {
            i /= 2;
            answer++;
        }
        else
        {
            i = (i * 3) + 1;
            answer++;
        }
        if (answer == 500)
        {
            answer = -1; 
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution(626331)<< endl;


    return 0; 
}
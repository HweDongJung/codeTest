//https://programmers.co.kr/learn/courses/30/lessons/12940
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    int big, small;
    if (n <= m)
    {
        big = m;
        small = n;
    }
    else
    {
        big = n;
        small = m;
    }

    for (int i = small; i > 0; i--)
    {
        if (n % i == 0 && m % i == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    for (int i=1;;i++)
    {
        if ((big * i) % small == 0)
        {
            answer.push_back(big*i);
            break;
        }
    }
    
    return answer;
}

int main()
{
    solution(3, 12);
    solution(2, 5);

    return 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/12947
#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    bool answer = true;
    int a = 0, b = x;
    for (;b !=0;)
    {
        a += b % 10;
        b = b / 10;
    }
    if (x % a != 0) answer = false;
    return answer;
}

int main()
{
    solution(10);

    return 0;
}
#include <string>
#include <vector>
#include <iostream> 

using namespace std;
// a,b모두 양수 모두 음수 a음수 b 양수 3가지 
long long solution(int a, int b)
{
    long long temp;
    int num1, num2;
    if (a > b) 
    { 
        num1 = b;
        num2 = a;
    }
    else
    {
        num1 = a;
        num2 = b;
    }
    temp = 0;
    for (long long i = num1; i <= num2; i++)
    {
        temp = temp + i;
    }
    return temp;
}

int main()
{
    solution(5, 3);



    return 0;
}
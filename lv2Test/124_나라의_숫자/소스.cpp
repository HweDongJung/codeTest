//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <iostream>
#include <vector>
/*
10진법 숫자를 3으로 나누고 나머지 0=4 2=2 1=1 몫이 n이면 n-1번 돈거와 같은 숫자 나옴
*/

using namespace std;


string solution(int n) 
{
    string answer = "";
    int num = n;
    for (;;)
    {
        
        if (num % 3 == 0) //나눠 떨어진다면 
        {
            answer = "4" + answer;
            num = (num / 3) - 1;
        }
        else // 안나눠 떨어진다면
        {
            answer = to_string(num%3) + answer;
            num = num / 3;
        }
        if (num == 0) break;
    }


    return answer;
}

int main()
{

    cout << solution(10) << endl;
    return 0;

}
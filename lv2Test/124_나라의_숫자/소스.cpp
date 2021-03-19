//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <iostream>
#include <vector>
/*
10���� ���ڸ� 3���� ������ ������ 0=4 2=2 1=1 ���� n�̸� n-1�� ���ſ� ���� ���� ����
*/

using namespace std;


string solution(int n) 
{
    string answer = "";
    int num = n;
    for (;;)
    {
        
        if (num % 3 == 0) //���� �������ٸ� 
        {
            answer = "4" + answer;
            num = (num / 3) - 1;
        }
        else // �ȳ��� �������ٸ�
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
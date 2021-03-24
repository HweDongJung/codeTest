//https://programmers.co.kr/learn/courses/30/lessons/17687
#include <string>
#include <vector>
#include <iostream>
//0 1 10 11 100 101 110

using namespace std;

string convert(int n, int num);
string solution(int n, int t, int m, int p);

int main()
{
    cout << solution(16, 16, 2, 1) << endl;

    return 0;
}

string solution(int n, int t, int m, int p)  //t*m이 구할 숫자 개수 
{
    string answer = "", str = "";

    for (int i = 0;; i++)
    {
        str += convert(n, i);
        
        if (str.size() >= t * m) break;
    }
    
    for (int i = 0; i < t; i++)
    {
        answer += str[i * m + p - 1];
    }


    return answer;
}

string convert(int n, int num)
{
    string str = "";
    if (num == 0) return "0";
    int i = num;
    while (i != 0)
    {
        if (i % n >= 10)
        {
            str = (char)(55 + i % n) + str;
        }
        else str = to_string(i % n) + str;
        
        i /= n;
    }


    return str;
}
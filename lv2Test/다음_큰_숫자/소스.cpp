// https://programmers.co.kr/learn/courses/30/lessons/12911
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int count1(int n)
{
    int num = n;
    string numstr = "";
    while (num != 0)
    {
        numstr = to_string(num % 2) + numstr;
        num /= 2;
    }

    return count(numstr.begin(), numstr.end(), '1');
}

int solution(int n)
{
    int answer = count1(n);

    for (int i = n + 1;; i++)
    {
        if (count1(i) == answer) return i;
    }
}

int main()
{
    cout << solution(15) << endl;

    return 0;
}
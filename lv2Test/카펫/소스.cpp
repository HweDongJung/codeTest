//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
            if ((i + yellow / i) * 2 + 4 == brown)
            {
                answer.push_back((yellow / i) + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    return answer;
}


int main()
{
    vector<int> a = solution(24, 24);
    cout << a[0] << " " << a[1] << endl;
    return 0;
}
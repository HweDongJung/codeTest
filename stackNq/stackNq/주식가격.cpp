/*
https://programmers.co.kr/learn/courses/30/lessons/42584
�ֽİ���
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) //prices �̸��� ������ vector �����̳� �Է�, price���� 
{
    int size, time = 0; // prices�� ������, �Էµ� �迭�� ���� ����
    size = prices.size(); // ���� ���� ���ֱ� 
    vector<int> answer;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            time++;
            if (prices[i] > prices[j])  break;
        }
        answer.push_back(time);
        time = 0;
    }
    answer.push_back(0);

    return answer;
}

int main()
{

    vector<int> answer, asdf = { 1,2,3,2,3 };
    answer = solution(asdf);
    for (int i = 0; i < 5; i++)
    {
        cout << answer[i] << endl;
    }

}
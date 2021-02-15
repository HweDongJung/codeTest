/*
https://programmers.co.kr/learn/courses/30/lessons/42584
주식가격
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) //prices 이름의 정수형 vector 컨테이너 입력, price에는 
{
    int size, time = 0; // prices의 사이즈, 입력된 배열의 원소 갯수
    size = prices.size(); // 갯수 저장 해주기 
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
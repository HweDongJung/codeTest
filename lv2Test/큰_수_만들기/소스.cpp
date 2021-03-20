//https://programmers.co.kr/learn/courses/30/lessons/42883
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
    solution과 다른 접근 
    K개를 빼는 작업이라면 다르게 생각해서 number.size - k개를 고르는 작업 
    예시 1924에서 2개 빼는 작업이라면 역으로 1924에서 4-2개를 고르는 작업이 됨 
    그렇다면 1924에서 맨 첫번째 앞숫자를 고를 때 안전빵 맨뒷자리 4를 빼고 1,9,2중에서 제일 큰 숫자를 고르고 -> 9
    9를 골랐으면 그 뒷숫자들 2,4 중에서 큰 숫자를 고름 그러면 94가 됨 
    이러한 알고리즘으로 구현 
*/


using namespace std;

bool cmp(pair<int, int> numbers1, pair<int, int> numbers2)
{
    return numbers1.first < numbers2.first;
}


string solution(string number, int k)
{
    string answer = "";
    vector<pair<int, int>> numbers; //첫번째 int는 number의 숫자, 두번째 int는 index 
    int select = number.size() - k, point = -1,max1=0; // 골라야 하는 숫자 개수, point= 이전에 고른 숫자 index
    for (int i = 0; i < number.size(); i++) numbers.push_back(make_pair(number[i] - '0', i)); //numbers 벡터에 number 숫자 저장 

    for (; select > 0;) // 다 고를때까지
    {
        if (select == number.size() - (point + 1))
        {
            for (int i = point + 1; i < number.size(); i++) answer += number[i];
            break;
        }
        for (int i = point + 1; i < number.size() - (select - 1); i++)
        {
            if (numbers[max1].first < numbers[i].first) max1 = numbers[i].second;
        }
        answer += to_string(numbers[max1].first);
        point = max1;
        max1++;
        select--;
    }


    return answer;
}

int main()
{
    cout << solution("4177252841",4) << endl;

    return 0;
}
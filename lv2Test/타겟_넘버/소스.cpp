//https://programmers.co.kr/learn/courses/30/lessons/43165
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void calculate(vector<int> numbers, int target, int index, int result) //result는 지금까지 계산한 값
{
    if (index == numbers.size()) // 다 계산했으면 끝내기 
    {
        if(result == target) answer++; // 경우의 수 중  결과값이 target과 같다면 answer++
    }
    else
    {
        calculate(numbers, target, index + 1, result - numbers[index]);
        calculate(numbers, target, index + 1, result + numbers[index]);

    }
}

int solution(vector<int> numbers, int target) 
{
    calculate(numbers, target, 0, 0);

    return answer;
}

int main()
{
    cout << solution({ 1,1,1,1,1 }, 3) << endl;

    return 0;
}
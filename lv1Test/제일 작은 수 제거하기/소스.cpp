//https://programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{

    vector<int> answer;
    int index=0, num=arr[0];
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
    answer = arr;
    for (int i = 1; i < arr.size(); i++)
    {
        if (num > arr[i])
        {
            index = i;
            num = arr[i];
        }
    }
    answer.erase(answer.begin() + index);

    return answer;
}

int main()
{
    vector<int> arr = { 4,3,2,1 };
    arr = solution(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
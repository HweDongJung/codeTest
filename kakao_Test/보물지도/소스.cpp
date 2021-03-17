//https://programmers.co.kr/learn/courses/30/lessons/17681
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2);

int main()
{
    vector<string> answer;
    vector<int> arr1 = { 9, 20, 28, 18, 11 }, arr2 = { 30, 1, 21, 17, 28 };
    int n=5;

    answer = solution(n,arr1,arr2);

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    string temp = "";
    int arr1num, arr2num;
    for (int i = 0; i < n; i++)
    {
        arr1num = arr1[i];
        arr2num = arr2[i];

        for (int j = 0; j < n; j++)
        {
            int pow1 = pow(2, (n - 1) - j);
            if (arr1num / pow1 == 1 || arr2num / pow1 == 1)
            {
                temp += "#";
                if (arr1num / pow1 == 1) arr1num -= pow1;
                if (arr2num / pow1 == 1) arr2num -= pow1;
            }
            else temp += " ";
        }
        answer.push_back(temp);
        temp = "";
    }

    return answer;
}
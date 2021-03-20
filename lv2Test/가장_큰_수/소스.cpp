//https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool cmp1(int a, int b)
{
    return stoi(to_string(a) + to_string(b)) > stoi(to_string(b) + to_string(a));
}

string solution(vector<int> numbers)
{
    if (*max_element(numbers.begin(),numbers.end()) == 0 ) return "0";
    string answer = "";
    vector<int> a = numbers;
    sort(a.begin(), a.end(), cmp1);
    for (int i = 0; i < a.size(); i++) answer += to_string(a[i]);

    return answer;
}

int main()
{
    vector<int> a = { 30,303 };
    sort(a.begin(), a.end(), cmp1);
    for (int i=0; i < a.size(); i++)cout << a[i];
    //cout << solution({303,30}) << endl;

    return 0;
}
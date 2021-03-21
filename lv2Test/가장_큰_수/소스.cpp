//https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool cmp1(int a, int b)
{
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
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
   
    cout << solution({ 3, 30, 34, 5, 9 }) << endl;

    return 0;
}
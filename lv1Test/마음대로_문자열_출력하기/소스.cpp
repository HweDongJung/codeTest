//https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int k;
bool cmp(string a, string b)
{
    if (a[k] != b[k]) return a[k] < b[k];
    else return a < b;

}

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer = strings;
    k = n;
    sort(answer.begin(), answer.end(), cmp);
    

    return answer;
}

int main()
{
    vector<string> a = { "sun", "bed", "car" };
    a = solution(a, 1);
    
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
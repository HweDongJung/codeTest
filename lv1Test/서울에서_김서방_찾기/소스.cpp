//https://programmers.co.kr/learn/courses/30/lessons/12919
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "김서방은 ";
    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            
            answer += to_string(i);
            answer += "에 있다";
        }
    }
    
    return answer;
}

int main()
{
    vector<string> seoul = { "Jane", "Kim" };
    cout << solution(seoul) << endl;
    return 0;
}
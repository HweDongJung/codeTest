//https://programmers.co.kr/learn/courses/30/lessons/70129
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string make_binary(int num)
{
    int num1 = num;
    string str = "";
    for(;num1 > 0;)
    {
        str = to_string(num1 % 2) + str;
        num1 = num1 / 2;
    }
    return str;
}

vector<int> solution(string s) 
{
    vector<int> answer;
    string s1 = s;
    int count = 0, remov = 0;
    for (;s1 != "1";)
    {
        int temp = 0;
        for (int i = 0; i < s1.size(); i++) if (s1[i] == '0') temp++;

        remov += temp;
        s1 = make_binary(s1.size()-temp);
        count++;
    }

    answer.push_back(count);
    answer.push_back(remov);

    return answer;
}

int main()
{
    vector<int> ans = solution("110010101001");
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
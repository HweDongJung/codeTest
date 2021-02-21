//https://programmers.co.kr/learn/courses/30/lessons/42576
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    sort(participant.begin(), participant.end()); 
    sort(completion.begin(), completion.end()); //participant, completion 모두 정렬

    for (int i=0; i < completion.size(); i++)
    {
        /*if (i == participant.size() - 1)
        {
            answer = participant[i];
            break;
        }*/
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    } //문자열 대조하면서 어긋나는 부분 찾기 

    if (answer == "") answer = participant[participant.size() - 1]; //끝까지 answer 대입되지 않은 경우 participant의 마지막 원소가 정답
   /* 이중 for문 사용으로 복잡도 n^2
   for (int i = 0; i < completion.size(); i++)
    {
        for (int j = 0; j < participant.size(); j++)
        {
            if (participant[j] == completion[i])
            {
                participant.erase(participant.begin()+j);
                break;
            }
        }
    }*/

    return answer;
}

int main()
{
    vector<string> asdf = { "leo", "kiki", "eden" }, zxcv = {"eden", "kiki"};
    //sort(asdf.begin(), asdf.end());
    //asdf.erase(asdf.begin() + 1);
    //cout << asdf.size() << endl;
    string ans = solution(asdf, zxcv);;
    
    cout << ans << endl;
    
    return 0;
}
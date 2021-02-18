#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

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
    }

    if (answer == "") answer = participant[participant.size() - 1];
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
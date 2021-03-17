//https://programmers.co.kr/learn/courses/30/lessons/17682
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>


using namespace std;

int getBonus(char bon)
{
    if (bon == 'S') return 1;
    else if (bon == 'D') return 2;
    else return 3;
}



int solution(string dartResult) 
{
    dartResult[4];
    int answer = 0;
    vector<int> score = {0,0,0,0};
    char str[10];
    strcpy_s(str,dartResult.c_str());
    for (int i = 0; i < dartResult.size(); i++)
    {
        if ((int)str[i] >= 48 && (int)str[i] <= 57) //숫자일 경우
        {
            score[answer] += (int)str[i] - 48; //스코어에 숫자 더하기
            if (i == 0) { answer++; continue; }
            else if (str[i - 1] == '1') { score[answer - 1] += 9; continue; } //앞에 '1' 즉 10점일 경우 앞의 스코어 벡터에 9 더하기
            answer++;
        }
        else if (str[i] == 'S' || str[i] == 'D' || str[i] == 'T') //보너스 SDT
        {
            score[answer - 1] = pow(score[answer - 1], getBonus(str[i]));
        }
        else //옵션
        {
            if (str[i] == '*')//스타상
            {
                if (answer == 1) score[answer - 1] *= 2;
                else
                {
                    score[answer - 1] *= 2;
                    score[answer - 2] *= 2;
                }
            }
            else //# 아차상
            {
                score[answer - 1] *= -1;
            }
        }
        
    }

    answer = 0;
    for (int i = 0; i < 3; i++)
    {
        answer += score[i];
    }

    return answer;
}

int solution2(string dartResult) //stringstream을 이용한 방법
{
    int point[3] = { 0, }, score;
    char bonus, option;
    int answer = 0;
    stringstream ss(dartResult);


    for (int i = 0; i < 3; i++)
    {
        ss >> score;
        bonus = ss.get();
        option = ss.get();
        if (option != '*' && option != '#') ss.unget(); //option문자가 아닐경우 읽음 취소

        score = pow(score, getBonus(bonus));
        point[i] = score;
        switch (option)
        {
        case '*':
            if (i == 0)
            {
                point[i] *= 2;
                break;
            }
            point[i] *= 2;
            point[i - 1] *= 2;
            break;
        case '#':
            point[i] *= -1;
            break;
        default:
            break;
        }

    }

    for (int i = 0; i < 3; i++)
    {     
        answer += point[i];
    }

    return answer;
}

int main()
{

    cout << solution2("1D2S#10S") << endl;

    return 0;
}
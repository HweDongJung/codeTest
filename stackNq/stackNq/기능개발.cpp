//프로그래머스 기능개발 https://programmers.co.kr/learn/courses/30/lessons/42586 

#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::endl;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int count=0, size = progresses.size();
    for (int i=0;i<size;)
    {
        for (int j=0; j<size;j++) //1일 경과 구현
        {
            progresses[j] += speeds[j];
        }

        if (progresses[i] >= 100) //첫번째 요소가 100을 넘겼을때 
        { 
            while(1)
            {
                count++;
                i++;
                if (i == size) { answer.push_back(count); break; } //다음 요소가 없을경우 루프 끝내기
                else if (progresses[i] < 100) { answer.push_back(count); break; } // 다음 요소가 100 미만일경우 루프 끝내기
            }
        }
        
        count = 0;
    }
    return answer;
}

vector<int> solution2(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer, time;
    int size = progresses.size(),count =0;
    for (int i = 0 ; i < size; i++)
    {
        if ((100 - progresses[i]) % speeds[i] > 0) time.push_back((100 - progresses[i]) / speeds[i] + 1);
        else time.push_back((100 - progresses[i]) / speeds[i]);
    }
    int i=0, temp;
    while (1)
    {
        temp = time[i];
        if (i == size - 1) {answer.push_back(1); break;
    }
        for (int j=i+1; j < size; j++)
        {
            count++;
            if (temp < time[j]) { i = j; answer.push_back(count); break; }
            
        }
        if (answer.size()==size) break;
    }


    return answer;
}

int main()
{
    
    vector<int> ans, asdf = { 93,30,55 }, zxcv = {1,30,5}; //테스트 케이스
    
    ans = solution2(asdf, zxcv);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
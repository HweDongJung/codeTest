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

int main()
{
    
    vector<int> ans, asdf = { 93,30,55 }, zxcv = {1,30,5}; //테스트 케이스
    
    ans = solution(asdf, zxcv);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
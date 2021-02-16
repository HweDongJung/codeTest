//���α׷��ӽ� ��ɰ��� https://programmers.co.kr/learn/courses/30/lessons/42586 

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
        for (int j=0; j<size;j++) //1�� ��� ����
        {
            progresses[j] += speeds[j];
        }

        if (progresses[i] >= 100) //ù��° ��Ұ� 100�� �Ѱ����� 
        { 
            while(1)
            {
                count++;
                i++;
                if (i == size) { answer.push_back(count); break; } //���� ��Ұ� ������� ���� ������
                else if (progresses[i] < 100) { answer.push_back(count); break; } // ���� ��Ұ� 100 �̸��ϰ�� ���� ������
            }
        }
        
        count = 0;
    }
    return answer;
}

int main()
{
    
    vector<int> ans, asdf = { 93,30,55 }, zxcv = {1,30,5}; //�׽�Ʈ ���̽�
    
    ans = solution(asdf, zxcv);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
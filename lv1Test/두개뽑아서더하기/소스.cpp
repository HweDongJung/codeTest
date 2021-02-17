#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    int size = numbers.size();
    vector<int>::iterator fnd;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            fnd = find(answer.begin(),answer.end(),numbers[i]+numbers[j]);
            if (fnd == answer.end()) answer.push_back(numbers[i] + numbers[j]); //answer�迭�� ���� ���ڰ� ���� ��� push, �ƴҰ��(�̹� �ߺ����� ���� ���) �Ѿ 
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{

    vector<int> ans, asdf = { 2,1,3,4,1 }; //�׽�Ʈ ���̽�

    ans = solution(asdf);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
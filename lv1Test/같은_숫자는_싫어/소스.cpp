#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int compare=11;
    for (int i = 0; i < arr.size(); i++)
    {
        if (compare != arr[i])
        {
            answer.push_back(arr[i]);
            compare = arr[i];
        }
    }

    return answer;
}

int main()
{
    vector<int> ans, arr = { 1, 1, 3, 3, 0, 1, 1 };
    ans = solution(arr);
    for (int i=0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
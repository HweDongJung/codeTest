#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer, temp;
    for (int i = 0; i < commands.size(); i++)
    {
        for (int j=commands[i][0]; j<= commands[i][1];j++)
        {
            temp.push_back(array[j-1]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
        temp.clear();
    }
    commands.size();
    return answer;
}

int main()
{
    vector<int> array1 = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };
    array1 = solution(array1, commands);

    for (int i = 0; i < array1.size(); i++)
    {
        cout << array1[i] << " ";
    }

    return 0;
}
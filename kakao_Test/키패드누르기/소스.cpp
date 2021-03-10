//https://programmers.co.kr/learn/courses/30/lessons/67256

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string findDist(int left, int right, int push, string hand) //내 손가락이 있는 위치로부터 누르고자 하는 번호의 위치까지의 거리 찾는 함수. 2,5,8,0을 누르고자 할때만 사용됨 
{
    vector <vector<int>> dist = { {0,0,3,0,0,2,0,0,1}, {4,0,1,0,0,2,0,0,3},{3,0,0,0,0,1,0,0,2} //0,1,2
                                  ,{4,0,1,0,0,2,0,0,3} ,{3,0,2,0,0,1,0,0,2} ,{2,0,1,0,0,0,0,0,1} //3,4,5
                                  ,{3,0,2,0,0,1,0,0,2} ,{2,0,3,0,0,2,0,0,1} ,{1,0,2,0,0,1,0,0,0} //6,7,8
                                  ,{2,0,3,0,0,2,0,0,1} ,{1,0,4,0,0,3,0,0,2} ,{1,0,4,0,0,3,0,0,2} }; //9,*,#
    if (dist[left][push] > dist[right][push]) return "R";
    else if ((dist[left][push] < dist[right][push])) return "L";
    else
    {
        if (hand == "right") return "R";
        else return "L";
    }

}

string solution(vector<int> numbers, string hand) //누를 번호와 오른손/왼손잡이 입력
{
    string answer = "";
    int left=10, right=11; //왼,오른손의 시작위치, 각 *, #에서 시작
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) //1,4,7일때 왼쪽손가락 사용
        {
            answer += "L"; 
            left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) //3,6,9일때 오른쪽 손가락 사용
        {
            answer += "R";
            right = numbers[i];
        }
        else //2,5,8,0 버튼을 눌러야 할 때 
        {
            if (findDist(left, right, numbers[i], hand) == "R")
            {
                answer += "R";
                right = numbers[i];
            }
            else
            {
                answer += "L";
                left = numbers[i];
            }
        }
    }



    return answer;
}

int main()
{
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };

    cout << solution(numbers, "right") << endl;

    return 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <iostream>
#include <algorithm>
/*
폰켓몬을 고른다고 할 때 한번에 고를 수 있는 최대의 폰켓몬 종류 구하기
case 1 : nums에 있는 폰켓몬 종류 < 고를 수 있는 포켓몬 수 -> nums에 있는 폰켓몬 종류 출력
case 2 : nums에 있는 폰켓몬 종류 > 고를 수 있는 포켓몬 수 -> 고를 수 있는 포켓몬 수
case 3 : 같을 때 -> 둘 중에 아무거나 출력
*/

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pick = nums.size() / 2;
    vector<int> pocketmon = nums;
    sort(pocketmon.begin(), pocketmon.end());
    for (int i = 0; i < pocketmon.size(); i++)
    {
        if (i == 0) answer++;
        else if (pocketmon[i - 1] != pocketmon[i]) answer++; //answer에 포켓몬 종류 개수 저장
    }

    if (answer > pick) answer = pick;

    return answer;
}

int main()
{
    vector<int> nums = { 3,1,2,3 };

    cout << solution(nums) << endl;

    return 0;
}
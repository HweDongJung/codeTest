#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

bool canCross(vector<pair<int, int>> truck_pair, int weight, int truck_weight);
int solution(int bridge_length, int weight, vector<int> truck_weights);

int main()
{
    vector<int> trucks = { 7,4,5,6 };
    cout << solution(2, 10, trucks) << endl;

    return 0;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0; // 시간 경과를 표시하는 변수
    vector<pair<int, int>> truck_pair; // 첫번째 int는 특정 트럭의 무게, 두번째 int는 지나간 길이
    vector<int> reach_truck, trucks = truck_weights; //reach_truck = 도착한 트럭목록

    for (;;)
    {
        answer++;//시간 경과 
        
        if (truck_pair.size() != 0 && truck_pair[0].second == bridge_length) //먼저 다리에 있는 트럭이 길이만큼 갔다면 pop 하고 다리를 지난 트럭 vector로 push
        {
            reach_truck.push_back(truck_pair[0].first); 
            truck_pair.erase(truck_pair.begin()+0);
        }
        if (reach_truck.size() == truck_weights.size()) break;//트럭 다 도착했으면 for문 탈출
        else
        {
            for (int i = 0; i < truck_pair.size(); i++) truck_pair[i].second ++;
        }

        if (trucks.size() != 0 && canCross(truck_pair, weight, trucks[0]))//다리의 무게와 들어가려는 트럭 무게 비교
        {
            truck_pair.push_back(make_pair(trucks[0], 1));
            trucks.erase(trucks.begin() + 0);
        }
    }

    return answer;
}

bool canCross(vector<pair<int, int>> truck_pair, int weight, int truck_weight) //weight = 다리가 견딜 수 있는 최대무게 
{
    int weights=0;
    for (int i = 0; i < truck_pair.size(); i++) weights += truck_pair[i].first;
    if (weight - weights >= truck_weight) return true; //다리의 한도무게 - 현재 다리위 트럭들의 무게 >= 다리 들어오려는 트럭의 무게라면 가능
    else return false;

}
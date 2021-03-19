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
    int answer = 0; // �ð� ����� ǥ���ϴ� ����
    vector<pair<int, int>> truck_pair; // ù��° int�� Ư�� Ʈ���� ����, �ι�° int�� ������ ����
    vector<int> reach_truck, trucks = truck_weights; //reach_truck = ������ Ʈ�����

    for (;;)
    {
        answer++;//�ð� ��� 
        
        if (truck_pair.size() != 0 && truck_pair[0].second == bridge_length) //���� �ٸ��� �ִ� Ʈ���� ���̸�ŭ ���ٸ� pop �ϰ� �ٸ��� ���� Ʈ�� vector�� push
        {
            reach_truck.push_back(truck_pair[0].first); 
            truck_pair.erase(truck_pair.begin()+0);
        }
        if (reach_truck.size() == truck_weights.size()) break;//Ʈ�� �� ���������� for�� Ż��
        else
        {
            for (int i = 0; i < truck_pair.size(); i++) truck_pair[i].second ++;
        }

        if (trucks.size() != 0 && canCross(truck_pair, weight, trucks[0]))//�ٸ��� ���Կ� ������ Ʈ�� ���� ��
        {
            truck_pair.push_back(make_pair(trucks[0], 1));
            trucks.erase(trucks.begin() + 0);
        }
    }

    return answer;
}

bool canCross(vector<pair<int, int>> truck_pair, int weight, int truck_weight) //weight = �ٸ��� �ߵ� �� �ִ� �ִ빫�� 
{
    int weights=0;
    for (int i = 0; i < truck_pair.size(); i++) weights += truck_pair[i].first;
    if (weight - weights >= truck_weight) return true; //�ٸ��� �ѵ����� - ���� �ٸ��� Ʈ������ ���� >= �ٸ� �������� Ʈ���� ���Զ�� ����
    else return false;

}
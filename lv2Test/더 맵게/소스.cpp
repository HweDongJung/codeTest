//https://programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0, scov=0;
    priority_queue<int, vector<int>, greater<int>> q; //우선순위 큐 선언, min heap(top이 최소값) 

    for (int i = 0; i < scoville.size(); i++) q.push(scoville[i]); 

    for (;;)
    {
        if (q.size() == 1 && q.top() < K) return -1;
        if (q.top() >= K) break;
        scov += q.top(); 
        q.pop();
        scov += (q.top() * 2); 
        q.pop();
        q.push(scov); 
        scov = 0;
        answer++; 
    }

    return answer;
}

int solution2(vector<int> scoville, int K)//내가 처음 만든 코드, 시간초과  
{
    int answer = 0;
    vector<int> scovil = scoville;
    for (;;)
    {
        if (*min_element(scovil.begin(), scovil.end()) >= K) break;
        if (scovil.size() == 1 && scovil[0] < K) return -1;
        sort(scovil.begin(), scovil.end());
        scovil[1] = scovil[0] + (scovil[1] * 2);
        scovil.erase(scovil.begin() + 0);
       
        answer++;
    }

    return answer;
}


int main()
{
    cout << solution({ 1,2,3,9,10,12 }, 7) << endl;

    return 0;
}
//https://programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int findDoll(vector<vector<int>> board, int pick); //pick = moves에 있던 칸 맨 위에 있는 인형 위치 출력하는 함수 
bool is_Pang(vector<int> bowl); //바구니 안에 팡 터질 인형이 있는가를 반환
int solution(vector<vector<int>> board, vector<int> moves);

int main()
{
    vector<vector<int>> board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };
    cout << solution(board, moves) << endl;

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0, point;
    vector<int> bowl; // 꺼내서 담는 바구니
    vector<vector<int>> now_board = board; //인형뽑기 안의 현 상황 

    for (int i = 0; i < moves.size(); i++)
    {
        point = findDoll(now_board, moves[i]-1);
        if (point == -1) continue; //인형 없으면 그냥 넘어가기
        bowl.push_back(now_board[point][moves[i]-1]);
        now_board[point][moves[i]-1] = 0;
        if (is_Pang(bowl))
        {
            bowl.pop_back();
            bowl.pop_back();
            answer += 2;
        }
    }

    return answer;
}

int findDoll(vector<vector<int>> board, int pick)
{
    int point = -1;
    for (int i = 0; i<board.size();i++)
    {
        if (board[i][pick] != 0)
        {
            point = i;
            break;
        }
    }

    return point; //-1이라면 그 줄에 인형 없음 
}

bool is_Pang(vector<int> bowl)
{
    if (bowl.size() == 1) return false;
    if (bowl[bowl.size() - 1] == bowl[bowl.size() - 2]) return true;
    else return false;
}
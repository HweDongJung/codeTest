//https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool is_Right(char a, char b, char type, int gap, vector<char> ch);

int solution(int n, vector<string> data) 
{
    vector<char> a = { 'A','C','F','J','M','N','R','T' };
    vector<vector<char>> temp1, temp2;

    char ch1, ch2, type;
    int gap;
    bool tem1= true;
    do 
    {
        temp1.push_back(a);
    } while (next_permutation(a.begin(), a.end())); //모든 경우의 섞은 벡터를 temp1에 저장 

    for (int i = 0; i < n; i++)
    {
        stringstream ss(data[i]);
        ch1 = ss.get(); 
        ss.get();
        ch2 = ss.get();
        type = ss.get();
        ss >> gap;

        if (i%2==0)
        {
            for (int j = 0; j < temp1.size(); j++) if (is_Right(ch1, ch2, type, gap, temp1[j])) temp2.push_back(temp1[j]); //조건에 맞는경우 push 
            if (temp2.size() == 0) return 0;
            temp1.clear();
        }
        else
        {
            for (int j = 0; j < temp2.size(); j++) if (is_Right(ch1, ch2, type, gap, temp2[j])) temp1.push_back(temp2[j]);
            if (temp1.size() == 0) return 0;
            temp2.clear();
        }
    }
    if (n % 2 == 0) return temp1.size();
    else return temp2.size();
    
}

int main()
{
    cout << solution(2, { "N~F=0", "R~T>2" }) << endl;

    return 0;
}

bool is_Right(char a, char b, char type, int gap, vector<char> ch)
{
    int ap = find(ch.begin(), ch.end(), a) - ch.begin();
    int bp = find(ch.begin(), ch.end(), b) - ch.begin();

    switch (type)
    {
    case '>':
        if (abs(ap - bp) > (gap + 1)) return true;
        else break;
    case '<':
        if (abs(ap - bp) < (gap + 1)) return true;
        else break;
    case '=':
        if (abs(ap - bp) == (gap + 1)) return true;
        else break;
    default:
        break;
    }

    return false;
}
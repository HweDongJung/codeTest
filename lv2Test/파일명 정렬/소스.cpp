//https://programmers.co.kr/learn/courses/30/lessons
#include <string>
#include <cstring>
#include <iostream>
#include <tuple>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(tuple<string, int, int> a, tuple<string, int, int> b)
{
    if (get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
    else return get<0>(a) < get<0>(b);
}

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    vector<tuple<string, int, int>> file_Tup;
    string headstr = "", number = "";
    bool head = true;
    
    for (int i = 0; i < files.size(); i++)
    {
        for (int j = 0; j < files[i][j]; j++)
        {
            if (head == false && ((int)files[i][j] < 48 || (int)files[i][j] > 57)) break;
            if ((int)files[i][j] >=48 && (int)files[i][j] <= 57) 
            {
                head = false;
                number += files[i][j];
                if (number.size() == 5) break;
            }
            if (head) headstr += files[i][j];

        }
        for (int j = 0; j < headstr.size(); j++) headstr[j] = toupper(headstr[j]);
        file_Tup.push_back(make_tuple(headstr,stoi(number),i));
        head = true;
        headstr = ""; 
        number = "";
    }
    stable_sort(file_Tup.begin(), file_Tup.end(), cmp);
    for (int i = 0; i < file_Tup.size(); i++) answer.push_back(files[get<2>(file_Tup[i])]);

    return answer;
}


int main()
{
    vector<string> a = { "img000012345", "img1.png","img2","IMG02" };
    
    a = solution(a);

    for (int i = 0; i < a.size(); i++) cout << a[i] << endl;

    return 0;
}
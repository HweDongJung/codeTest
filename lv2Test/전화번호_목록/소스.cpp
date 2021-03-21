//https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_found(string a, string b)
{
    if (a.size() > b.size())
    {
        if (a.find(b) == 0) return true; 
        else return false;
    }
    else if (a.size() == b.size()) return false;
    else
    {
        if (b.find(a) == 0) return true;
        else return false;
    }

}

bool cmp(string a, string b)
{
    return a[0] < b[0];
}

bool solution2(vector<string> phone_book)
{
    bool answer = true;

    vector<string> phone = phone_book;
    sort(phone.begin(), phone.end());

    //for (int i = 0; i < phone.size(); i++) cout << phone[i] << endl;

    for (int i = 0; i < phone.size() - 1; i++)
    {
        if (is_found(phone[i], phone[i + 1])) return false;
    }
    return answer;
}


bool solution(vector<string> phone_book) 
{
    bool answer = true;
    int firstNum;
    vector<vector<string>> phone = { {}, {}, {}, {}, {}, {}, {}, {}, {}, {} };
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        firstNum = (int)phone_book[i][0] - '0';
        phone[firstNum].push_back(phone_book[i]);
    }

    for (int i =0; i<phone.size(); i++)
    {
        if (phone[i].size() < 2) continue;

        for (int j = 0; j < phone[i].size()-1; j++)
        {
            for (int k = j + 1; k < phone[i].size(); k++)
            {
                if (is_found(phone[i][j], phone[i][k]))
                {
                    return false;
                }
            }

        }
    }
   
    return answer;
}

int main()
{
    string sex = "sex";
    string sex2 = "sex king is coming";

    solution2({ "119", "97674223", "1195524421" });

    cout << sex.find(sex2) << endl;

    return 0;
}
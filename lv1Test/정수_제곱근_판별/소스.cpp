//https://programmers.co.kr/learn/courses/30/lessons/12934
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    answer = sqrt(n);
    if (pow(answer, 2) != n) return -1;
    else return pow(++answer, 2);

}
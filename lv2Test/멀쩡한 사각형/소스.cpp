#include <iostream>
#include <cmath>


using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long square(int w, int h, long long num)
{
    long long sq1, sq2;

    sq1 = floor((double)h / (double)w * num);
    sq2 = ceil((double)h / (double)w * (num + 1));

    return sq2 - sq1;
}

long long solution(int w, int h)
{
    int gcd1 = gcd(w, h);
    long long broken = w + h - gcd1;
    return (long long)w * (long long)h - broken;

}

long long solution2(int w, int h) // 소수점 문제로 안풀리는듯; 
{
    long long answer = 1, wrong_square = 0;
    

    for (long long i = 0; i < w; i++)
    {
        wrong_square += square(w,h, i);
    }
    
    answer = (long long)w * (long long)h - wrong_square;
    return answer;
}



int main()
{
    cout << solution(8, 12) << endl;
    /*double a = 4.0 / 3.0;
    int b = 3;
    cout << a*b << endl;
    cout << ceil(a * b) << endl;*/
    return 0;
}
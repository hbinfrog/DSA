#include <iostream>
#include <sstream> //引用stringstream的头文件
#include <string>
#include <math.h>
#include <vector>
using namespace std;

void Multi(string s1, string s2)
{
    // string res = "";
    if (s1 == "0" || s2 == "0")
    {
        printf("0");
    }
    int n1 = s1.size();
    int n2 = s2.size();
    long long a[600] = {0};
    long long b[600] = {0};
    long long ret[600] = {0};
    long long index = 1;
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        if (i != 0 && i % 9 == 0)
        {
            index = 1;
            k++;
        }
        a[k] += index * (s1[n1 - 1 - i] - '0');
        index = index * 10;
    }
    index = 1;
    k = 0;
    for (int i = 0; i < n2; i++)
    {
        if (i != 0 && i % 9 == 0)
        {
            index = 1;
            k++;
        }
        b[k] += index * (s2[n2 - 1 - i] - '0');
        index = index * 10;
    }
    int bit1 = (n1 + 8) / 9;
    int bit2 = (n2 + 8) / 9;
    int bit3 = bit1 + bit2;
    for (int i = 1; i <= bit1; i++)
    {
        for (int j = 1; j <= bit2; j++)
        {
            ret[i + j - 1] += a[i - 1] * b[j - 1];
            ret[i + j] += ret[i + j - 1] / 1000000000;
            ret[i + j - 1] = ret[i + j - 1] % 1000000000;
        }
    }
    if (ret[bit3])
    {
        printf("%lld", ret[bit3]);
    }
    for (int i = bit3 - 1; i > 0; i--)
    {
        printf("%.9lld", ret[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Multi(s1, s2);
        printf("\n");
    }
}
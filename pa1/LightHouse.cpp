#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 4000020
class Points{
public:
    long long x;
    long long y;
    bool operator<=(Points &p){
        if(this->x <= p.x){
            return true;
        }
        return false;
    }

};
Points points[MAX];

long long y_value[MAX];
long long num = 0;
template <typename T>
void merge(T *a, int lo, int mi, int hi)
{
    //num = 0;
    int lb = mi - lo;
    int lc = hi - mi;
    T *B = new T[lb];
    T *A = a + lo;
    T *C = a + mi;
    for (int i = 0; i < lb; i++)
    {
        B[i] = A[i];
    }
    int j = 0;
    int k = 0;
    int i = 0;
    while ((j < lb) && (k < lc))
    {
        if (B[j] <= C[k])
        {
            A[i] = B[j];
            j++;
            num += lc - k;
        }
        else
        {
            A[i] = C[k];
            k++;
        }
        i++;
    }
    while (j < lb)
    {
        A[i] = B[j];
        i++;
        j++;
    }
    delete[] B;
}
template <typename T>
void Sort(T *a, int lo, int hi)
{
    if (hi - lo < 2)
    {
        return;
    }
    int mi = (lo + hi) >> 1;
    Sort(a, lo, mi);
    Sort(a, mi, hi);
    merge(a, lo, mi, hi);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &points[i].x, &points[i].y);
    }
    Sort(points, 0, n);
    for(int i = 0; i < n; i++){
        y_value[i] = points[i].y;
    }
    num = 0;
    Sort(y_value, 0, n);
    printf("%lld\n", num);
}

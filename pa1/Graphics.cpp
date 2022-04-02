#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std;
#define N 200010

long long x[N];
long long y[N];

void merge(long long a[], int lo, int mi, int hi){
    int lb = mi - lo;
    int lc = hi - mi;
    long long* B = new long long[lb];
    long long* A = a + lo;
    long long* C = a + mi;
    for(int i = 0; i < lb; i++){
        B[i] = A[i];
    }
    int j = 0;
    int k = 0;
    int i = 0;
    while((j < lb) && (k < lc)){
        if(B[j] <= C[k]){
            A[i] = B[j];
            j++;
        }
        else{
            A[i] = C[k];
            k++;
        }
        i++;
    }
    while(j < lb){
        A[i] = B[j];
        i++;
        j++;
    }
    delete [] B;
}

void mergesort(long long a[], int lo, int hi){
    if(hi - lo < 2){
        return;
    }
    int mi = (hi + lo) >> 1;
    mergesort(a,lo,mi);
    mergesort(a,mi,hi);
    merge(a,lo,mi,hi);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", x+i);
    }
    for(int i = 0; i < n; i++){
        scanf("%lld", y+i);
    }
    mergesort(x,0,n);
    mergesort(y,0,n);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        long long px, py;
        scanf("%lld%lld", &px, &py);
        int left = 0;
        int right = n;
        if(y[left]*px + x[left]*py - x[left]*y[left] < 0){
            printf("%d\n", 0);
            continue;
        }
        if(y[right-1]*px + x[right-1]*py - x[right-1]*y[right-1] >= 0){
            printf("%d\n", n);
            continue;
        }
        while(left < right){
            int mid = (left+right) / 2;
            long long dis = y[mid]*px + x[mid]*py - x[mid]*y[mid];
            long long dis_lo = y[mid-1]*px + x[mid-1]*py - x[mid-1]*y[mid-1];
            long long dis_hi = y[mid+1]*px + x[mid+1]*py - x[mid+1]*y[mid+1];
            if(dis == 0){
                printf("%d\n", mid + 1);
                break;
            }
            if(dis >= 0 && dis_hi < 0){
                printf("%d\n", mid + 1);
                break;
            }
            if(dis < 0 && dis_lo >= 0){
                printf("%d\n", mid);
                break;
            }
            if(dis < 0){
                right = mid;
            }
            if(0 < dis){
                left = mid + 1;
            }
            

        }
    }
    return 0;
}
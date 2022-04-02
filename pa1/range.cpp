#include <iostream>
#include <stdio.h>
using namespace std;

void merge(int a[], int lo, int mi, int hi){
    int lb = mi - lo;
    int lc = hi - mi;
    int* B = new int[lb];
    int* A = a + lo;
    int* C = a + mi;
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

void Sort(int a[], int lo, int hi){
    if(hi - lo < 2){
        return ;
    }
    int mi = (lo + hi) >> 1;
    Sort(a,lo,mi);
    Sort(a,mi,hi);
    merge(a,lo,mi,hi);
}
int find(int a[], int lo, int hi, int target){
    //int pos = -1;
    while (lo < hi)
    {
        /* code */
        int mi = (lo + hi) >> 1;
        target < a[mi] ? hi = mi : lo = mi + 1;
    }
    return lo - 1;
}

int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    //cin >> n >> m;
    int points[n];
    for(int i = 0; i < n; i++){
        int point;
        scanf("%d", &point);
        points[i] = point;
    }
    Sort(points,0,n);
    for(int i = 0; i < m; i++){
        int res = 0;
        int left, right;
        scanf("%d%d",&left,&right);
        //cin >> left >> right;
        int leftpos = find(points,0, n, left);
        int rightpos = find(points,0, n, right);
        // cout << leftpos << endl;
        // cout << rightpos << endl;
        res = rightpos - leftpos;
        if(points[leftpos] == left){
            res++;
        }
        printf("%d\n",res);
        //cout << res << endl;
    }
    //cout << endl;
    return 0;

}
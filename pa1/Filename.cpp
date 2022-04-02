#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define N 501020
int com[N];



int abs(int x){
    if(x < 0){
        return -x;
    }
    return x;
}

int max(int x, int y){
    if(x < y){
        return y;
    }
    return x;
}
int min(int x, int y){
    if(x < y){
        return x;
    }
    return y;
}
int main(){
    int len1, len2, k;
    cin >> len1 >> len2 >> k;
    string s1, s2;
    cin >> s1 >> s2;
    if(abs(len1 - len2) > k){
        cout << "-1" << endl;
    }
    else{
        for(int i = 0; i <= len2; i++){
            com[i] = 0;
        }
        for(int i = 1; i <= len1; i++){
            int pre = com[0];
            for(int j = max(i-k,1); j <= min(len2, i + k); j++){
                int temp = com[j];
                if(s1[i-1] == s2[j-1]){
                    com[j] = pre + 1;
                }
                else{
                    com[j] = max(com[j-1], com[j]);
                }
                pre = temp;

            }
        }
        if(len1 + len2 - 2*com[len2] > k){
            cout << "-1" << endl;
        }
        else{
            cout << len1 + len2 - 2*com[len2] << endl;
        }


    }
    return 0;
}
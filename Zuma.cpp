#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;

#define L 20020
char a[L];

int length_cal(int pos, char c, int len){
    for(int i = len; i > pos; i--){
        a[i] = a[i-1];
    }
    a[pos] = c;
    len++;
    for(int i = 0; i < len - 2; i++){
        if(a[i] == a[i+1] && a[i+1] == a[i+2]){
            int left = i + 2;
            for(left = i + 2; left < len && a[left] == a[i]; left++);
            int diff = left - i;
            for(int j = i; j < len; j++){
                a[j] = a[j+diff];
            }
            len = len - diff;
            i = -1;
        }
    }
    return len;
}

int main(){

    cin.getline(a, L);
    int length = strlen(a);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int pos;
        char c;
        scanf("%d %c", &pos, &c);
        length = length_cal(pos,c,length);
        if(length > 0){
            printf("%s\n",a);
        }
        else{
            printf("-\n");
        }
    }
    return 0;

}
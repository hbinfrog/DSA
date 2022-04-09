#include<iostream>
#include<string>
#include<cstring>

struct MultiTreeNode
{
    int parent;
    int son;
    int left;
    int right;
    int height;
    int size;
    MultiTreeNode(){
        parent = -1;
        son = -1;
        left = -1;
        right = -1;
        height = 0;
        size = 1;
    }
    /* data */
}node[1000010];



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int child_num;
        scanf("%d", &child_num);
        for(int j = 0 ; j < child_num; j++){
            int first;
            if(j == 0){
                scanf("%d", &first);
                node[i].son = first;
                node[first].parent = i;

            }
            else{
                int bro;
                scanf("%d", &bro);
                node[first].right = bro;
                node[bro].left = first;
                first = bro;
            }
            int child;
            scanf("%d", &child);

        }

    }
    for(int i = 0; i < m; i++){
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            /* code */
            break;
        case 1:
            break;
        case 2:
            break;
        
        default:
            break;
        }

    }
    return 0;
}
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct listnode{  
    char data;
    listnode* pre;
    listnode* suc;
    listnode(){}
    listnode(char a,listnode* p=NULL,listnode* q=NULL):data(a),pre(p),suc(q){}
    void insert(listnode* const tem){//left
        tem->pre=pre;
        if(pre!=NULL)
            pre->suc=tem;
        tem->suc=this;
        pre=tem;
    }
    void insert1(listnode* const tem){//right
        tem->suc=suc;
        if(suc!=NULL)
            suc->pre=tem;
        tem->pre=this;
        suc=tem;
    }
    void del(){//right
        suc=suc->suc;
        delete suc->pre;
        suc->pre=this;
    }
    void del1(){//left
        pre=pre->pre;
        delete pre->suc;
        pre->suc=this;
    }
};

int main()
{
    int length=1;
    char a;
    a=getchar();
    listnode* first=new listnode(a);
    listnode* last=first;
    listnode* first1=new listnode(a);
    listnode* last1=first1;
    while(true){
        a=getchar();
        if(a==' '||a=='\n')
            break;
        listnode* tem=new listnode(a);
        listnode* temp=new listnode(a);
        last->insert1(tem);
        last=tem;
        last1->insert(temp);
        last1=temp;
        length++;
    }
    listnode* t1=new listnode('F');
    listnode* t2=new listnode('L');
    listnode* t3=new listnode('F');
    listnode* t4=new listnode('L');
    t1->suc=first;
    first->pre=t1;
    t2->pre=last;
    last->suc=t2;
    t3->pre=first1;
    first1->suc=t3;
    t4->suc=last1;
    last1->pre=t4;
    listnode* l=t1;
    listnode* l1=t3;
    int l_num=0;
    listnode* r=t2;
    listnode* r1=t4;
    int r_num=length;
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        char s=getchar();
        if(s=='>'){
            getchar();
            char s1=getchar();
            if(s1=='L'){
                if(l->suc->suc!=NULL){
                    printf("T\n");
                    l=l->suc;
                    l1=l1->pre;
                    l_num++;
                }
                else
                    printf("F\n");  
            }
            if(s1=='R'){
                if(r->suc!=NULL){
                    printf("T\n");
                    r=r->suc;
                    r1=r1->pre;
                    r_num++;
                }
                else
                    printf("F\n");
            }
        }
        if(s=='<'){
            getchar();
            char s1=getchar();
            if(s1=='L'){
                if(l->pre!=NULL){
                    printf("T\n");
                    l=l->pre;
                    l1=l1->suc;
                    l_num--;
                }
                else
                    printf("F\n");  
            }
            if(s1=='R'){
                if(r->pre->pre!=NULL){
                    printf("T\n");
                    r=r->pre;
                    r1=r1->suc;
                    r_num--;
                }
                else
                    printf("F\n");
            }
        }
        if(s=='I'){
            getchar();
            char s1=getchar();
            getchar();
            char s2=getchar();
            listnode* temp=new listnode(s2);
            listnode* temp1=new listnode(s2);
            printf("T\n");
            if(s1=='L'){
                l->insert1(temp);
                l=l->suc;
                l1->insert(temp1);
                l1=l1->pre;
                if(l_num<=r_num)    
                    r_num++;
                l_num++;
            }
            if(s1=='R'){
                if(l->suc==r){
                    r->insert(temp);
                    r1->insert1(temp1);
                    l=l->suc;
                    l1=l1->pre;
                }
                else
                {
                    r->insert(temp);
                    r1->insert1(temp1);
                }
                if(r_num<=l_num)
                    l_num++;
                r_num++;
            }    
            
        }
        if(s=='D'){
            getchar();
            char s1=getchar();
            if(s1=='L'){
                if(l->suc->suc!=NULL){
                    printf("T\n");
                    if(l->suc==r){
                        r=r->suc;
                        r1=r1->pre;
                    }
                    l->del();
                    l1->del1();
                    if(l_num<r_num)
                        r_num--;
                }
                else
                    printf("F\n");  
            }
            if(s1=='R'){
                if(r->suc!=NULL){
                    printf("T\n");
                    if(r==l){
                        l=l->pre;
                        l1=l1->suc;
                    }
                    r=r->suc;
                    r->del1();
                    r1=r1->pre;
                    r1->del();
                    if(r_num<l_num)
                    l_num--;
                }
                else
                    printf("F\n");  
            }
        }
        if(s=='R'){
            if(l_num>=r_num)
                printf("F\n");
            else{
                printf("T\n");
                listnode* k1=l->suc;
                listnode* k2=r->pre;
                l->suc=r1->suc;
                r1->suc->pre=l;
                l1->pre->suc=r;
                r->pre=l1->pre;
                r1->suc=k1;
                k1->pre=r1;
                l1->pre=k2;
                k2->suc=l1;
            }
        }
        if(s=='S'){
            listnode* asd=t1->suc;
            while(asd->suc!=NULL){
                putchar(asd->data);
                //printf("%c",asd->data);
                asd=asd->suc;
            }
            printf("\n");
        }
        getchar();
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;

struct ListNode
{
    char data;
    ListNode *succ;
    ListNode *pred;
    ListNode() {}
    ListNode(char a, ListNode *s = nullptr, ListNode *p = nullptr) : data(a), succ(s), pred(p) {}
    ListNode *insertAsSucc(char const &e)
    {
        ListNode *x = new ListNode(e, succ, this);
        if (succ != nullptr)
            this->succ->pred = x;
        this->succ = x;
        return x;
    }
    ListNode *insertAsPred(char const &e)
    {
        ListNode *x = new ListNode(e, this, pred);
        if (pred != nullptr)
            this->pred->succ = x;
        this->pred = x;
        return x;
    }
    char remove()
    {
        char e = this->data;
        if(this->pred != nullptr)
            this->pred->succ = this->succ;
        if(this->succ != nullptr)
            this->succ->pred = this->pred;
        delete this;
        return e;
    }
};

void swap(char &x, char &y)
{
    char temp = x;
    x = y;
    y = temp;
}
const char l = 0x20;
const char r = 0x7f;

// const int init_len = 3200050;
// const int N = 4000050;
// char c[init_len];
// char L[init_len + N];

int main()
{
    char a;
    ListNode *header = new ListNode(l);
    ListNode *trailer = new ListNode(r);
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    // L[0] = header->data;
    ListNode *first_temp = header;
    int size = 0;
    while (1)
    {
        size++;

        a = getchar();
        if (a == '\n')
        {
            break;
        }
        ListNode *x = first_temp->insertAsSucc(a);
        first_temp = x;
        // size++;
    }
    ListNode *last = first_temp;

    ListNode *list_l = header;  //左光标的位置
    ListNode *list_r = trailer; //右光标的位置
    // L[size] = trailer->data;
    int posl = 0;
    int posr = size - 1;

    int n;
    cin >> n;
    // cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        char op;
        char dir;
        char ch;
        cin >> op;
        if (op == '>')
        {
            cin >> dir;
            if (dir == 'L')
            {
                if (list_l->succ->succ != nullptr)
                {
                    list_l = list_l->succ;
                    cout << "T" << endl;
                    posl++;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
            else
            {
                if (list_r->succ != nullptr)
                {
                    list_r = list_r->succ;
                    cout << "T" << endl;
                    posr++;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
        }
        if (op == '<')
        {
            cin >> dir;
            if (dir == 'L')
            {
                if (list_l->pred->pred != nullptr)
                {
                    list_l = list_l->pred;
                    cout << "T" << endl;
                    posl--;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
            else
            {
                if (list_r->pred != nullptr)
                {
                    list_r = list_r->pred;
                    cout << "T" << endl;
                    posr--;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
        }
        if (op == 'I')
        {
            cin >> dir >> ch;
            size++;
            cout << "T" << endl;
            if (dir == 'L')
            {
                ListNode *x = list_l->succ->insertAsPred(ch);
                list_l = list_l->succ;
                if (posl <= posr)
                    posr++;
                posl++;
            }
            else
            {

                if (list_l->succ->pred == list_r->pred)
                {
                    ListNode *x = list_r->pred->insertAsSucc(ch);
                    list_r->pred = x;
                    list_l = list_l->succ;
                }
                else
                {
                    ListNode *x = list_r->pred->insertAsSucc(ch);
                    list_r->pred = x;
                }
                if (posr <= posl)
                    posl++;
                posr++;
            }
        }
        if (op == 'D')
        {
            size--;
            cin >> dir;
            if (dir == 'L')
            {
                if (list_l->succ->succ != nullptr)
                {
                    list_l->succ->remove();
                    if (list_l->pred)
                        list_l->succ = list_l->pred->succ->succ;
                    if (list_l->pred == list_r->pred)
                    {
                        list_r->succ = list_l->succ;
                    }
                    if (list_l->succ == list_r->succ)
                    {
                        list_r->succ = list_l->succ->succ;
                    }
                    if (list_l->succ->succ == list_r->succ)
                    {
                        list_r->pred = list_l->succ->pred;
                    }
                    if (posl < posr)
                    {
                        posr--;
                    }
                    cout << "T" << endl;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
            if (dir == 'R')
            {
                if (list_r->succ != nullptr)
                {
                    if (list_l == list_r)
                    {
                        list_r->pred->succ->remove();
                        list_r->succ = list_r->succ->succ;
                        list_l->pred = list_r->pred->pred;
                        list_l->succ = list_r->pred->succ;
                    }
                    else
                    {
                        list_r->pred->succ->remove();
                        list_r->succ = list_r->succ->succ;
                    }
                    if (posr < posl)
                        posl--;
                    cout << "T" << endl;
                }
                else
                {
                    cout << "F" << endl;
                }
            }
        }
        if (op == 'R')
        {
            if (posr <= posl)
            {
                cout << "F" << endl;
            }
            else
            {
                ListNode * x = list_l->succ;
                ListNode * y = list_r->pred;
                while(x != y && x->succ != y){
                    swap(x->data, y->data);
                    x = x->succ;
                    y = y->pred;
                }
                cout << "T" << endl;
            }
        }
        if (op == 'S')
        {
            ListNode *temp = header->succ;
            while (temp->succ != nullptr)
            {
                cout << temp->data;
                temp = temp->succ;
            }
            cout << endl;
        }
    }
}

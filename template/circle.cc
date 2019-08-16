#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v)
        : val(v)
        , next(nullptr)
    {
    }
};

int cir(int n, int k)
{
    int p = 0;
    for (int i = 2; i <= n; i++) {
        p = (p + k) % i;
    }
    return p + 1;
}
int main(int argc, char* argv[])
{

    int n=100;
    int k=3;
    cout<<cir(n,k)<<endl;
    
    ListNode* head=new ListNode(1);
    auto p=head;
    for(int i=2;i<=n;i++)
    {
        auto t=new ListNode(i);
        p->next=t;
        p=p->next;
    }
    p->next=head;
    int step=1;
    p=head; 
    while(n>1)    
    {
        if(step==k)
        {
            cout<<p->val<<endl;
            p->val=p->next->val;
            auto t=p->next;
            p->next=t->next;
            delete t;
            n=n-1;
            step=1;
        }else{
            step+=1;
            p=p->next;
        }
    }
    cout<<p->val<<endl;
    return 0;
}
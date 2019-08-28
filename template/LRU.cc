class LRUCache {
    
struct ListNode{
   int key,val;
   ListNode*next;
   ListNode*pre; 
   ListNode(int k,int v):key(k),val(v),pre(nullptr),next(nullptr) 
   {}
};
    
public:
    LRUCache(int capacity):n(0),cap(capacity) {
       head=new ListNode(-1,-1);
       tail=new ListNode(-1,-1);
       head->next=tail;
       tail->pre=head;
    }
    
    int get(int key) {
       if(m.find(key)==m.end()) 
           return -1;
       delink(m[key]);
       link(head,m[key]);
       return m[key]->val; 
    }
    
    void put(int key, int val) {
        if(cap==0)return;
        if(m.find(key)!=m.end()) 
        {
            m[key]->val=val;
            delink(m[key]);
            link(head,m[key]);
        }else{
          m[key]=new ListNode(key,val);
          if(n<cap)  
              n++;
          else
          {
              auto p=tail->pre;
              delink(p);
              m.erase(p->key);
              delete p;
          }
          link(head,m[key]);
        }
    }
private:
    void delink(ListNode* p)
    {
        auto pre=p->pre;
        auto next=p->next;
        pre->next=next;
        next->pre=pre;
    }
    void link(ListNode* left,ListNode*p)
    {
       auto right=left->next;
       left->next=p;
       p->pre=left;
       right->pre=p;
       p->next=right;
    }
    unordered_map<int,ListNode*> m;
    ListNode* head;
    ListNode* tail;
    int n;
    int cap; 
};

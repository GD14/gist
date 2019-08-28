struct node{
    int key;   
    int val;
    int freq;
    node* next;
    node* pre;
   node(int k,int v)
       :key(k),val(v),freq(0)
       ,next(nullptr),pre(nullptr){}
};
class LFUCache {
public:
    LFUCache(int capacity):cap(capacity),n(1) {
      head=new node(-1,-1);
      tail=new node(-1,-1);  
      head->next=tail;
      tail->pre=head;
      kHead[0]=tail;
    }
    
    int get(int key) {
        if(pos.find(key)==pos.end())    
            return -1;
        auto ptr=pos[key]; 
        detach(ptr); 
        advance(ptr);
        return ptr->val;
    }
    
    void put(int key, int val) {
        if(cap==0) return ;
        if(pos.find(key)!=pos.end()){
           pos[key]->val=val; 
           detach(pos[key]);
           advance(pos[key]);
        }else{
            
           if(n==cap){
              auto last=tail->pre; 
              detach(last);         
              pos.erase(last->key); 
              delete last;
           }else{
               n++;
           }  
            pos[key]=new node(key,val);
            advance(pos[key]); 
        }
    }
private:
    inline void link(node* pre,node* ptr)
    {
        auto next=pre->next;
        pre->next=ptr;
        ptr->pre=pre;
        ptr->next=next;
        next->pre=ptr;
    }
    inline void delink(node* ptr){
        auto pre=ptr->pre;
        auto next=ptr->next;
        pre->next=next;
        next->pre=pre;
    }
    void detach(node* ptr)
    {
         //如果ptr是k头节点，更换k头节点
        if(kHead[ptr->freq]==ptr) 
        {
          if(ptr->next==tail)
               kHead.erase(ptr->freq);    
          else {
              if(ptr->next->freq==ptr->freq)
                kHead[ptr->freq]=ptr->next;
              else kHead.erase(ptr->freq);
          }
        }
        delink(ptr); 
    }
    
    void advance(node* ptr)
    {
       int k=++ptr->freq;
       for(int i=k;i>=0;i--) 
           if(kHead.find(i)!=kHead.end())
           {
              link(kHead[i]->pre,ptr); 
              kHead[k]=ptr;
               break;
           }
    }
private:
    node* head;
    node* tail;
    int cap;
    int n;
    unordered_map<int,node*> pos;
    unordered_map<int,node*> kHead; 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
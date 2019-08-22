#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

struct ListNode {
    int val_;
    ListNode* next_;
};

class LockFreeQueue {
public:
    LockFreeQueue()
    {
        head_ = new ListNode();
        head_->next_ = nullptr;
        tail_ = head_;
    }
    ~LockFreeQueue()
    {
        auto p = head_;
        while (p != tail_) {
            auto q = p;
            p = p->next_;
            delete q;
        }
        delete tail_;
    }
    void push(int val)
    {
        auto newPtr = new ListNode;
        newPtr->val_ = val;
        newPtr->next_ = nullptr;

        auto p = tail_;
        auto oldPtr = tail_;

        do {
            while (p->next_ != nullptr)
                p = p->next_;
        } while (CAS(p->next_, nullptr, newPtr) != true);

        CAS(tail_, oldPtr, newPtr);
    }

    int pop()
    {
        ListNode* p;
        do {
            p = head_->next_;
            if (p == nullptr)
                return;
        } while (CAS(head_->next_, p, p->next_) != true);
        auto val = p->val_;
        delete p;
        return val;
    }

private:
    bool CAS(ListNode*& ptr, ListNode* oldVal, ListNode* newVal)
    {
        return __sync_bool_compare_and_swap(&ptr, oldVal, newVal);
    }
    ListNode* head_;
    ListNode* tail_;

    int size_;
};
int main(int argc, char* argv[])
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* x = sortList(head);
        ListNode* y = sortList(mid);

        return combineSort(x, y);
    }

    ListNode* combineSort(ListNode* l1, ListNode* l2)
    {
        ListNode res(0);
        ListNode* p = &res;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return res.next;
    }
};
int main(int argc, char* argv[])
{

    return 0;
}
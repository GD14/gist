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
    ListNode* detectCycle(ListNode* head)
    {
        if (!head || !head->next)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            } else
                return nullptr;
            slow = slow->next;
        } while (slow != fast);

        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main(int argc, char* argv[])
{
}
//找循环链表的循环开始节点
//find the begining of the loop link
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
       do{ 
            if(fast->next&&fast->next->next)
                fast=fast->next->next;
            else
                return nullptr;
            slow=slow->next;
        }while(slow!=fast);
       
        slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
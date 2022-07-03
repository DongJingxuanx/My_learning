
#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



 
class Solution{
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode *slow_ptr = head;
        ListNode *quick_ptr = head;
        do {
            if(quick_ptr->next == NULL || (quick_ptr->next)->next == NULL)
                return NULL;
            slow_ptr = slow_ptr->next;
            quick_ptr = (quick_ptr->next)->next;
        } while (slow_ptr != quick_ptr);
        slow_ptr = head;
        while(slow_ptr != quick_ptr) {
            slow_ptr = slow_ptr->next;
            quick_ptr = quick_ptr->next;
        }
        return slow_ptr;
    }
};

int main(int argc, char* argv[]) {
    ListNode* node0 = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    Solution c;
    ListNode* res = c.detectCycle(node0);
    if (res == NULL) {
       std::cout << "result node val:" << "null" <<std::endl; 
    }else
        std::cout << "result node val:" << res->val <<std::endl;
    return 0;
}

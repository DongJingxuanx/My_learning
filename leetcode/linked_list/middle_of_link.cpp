#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode* List) {
    while(List != NULL)
    {    
        std::cout << List->val <<' ';
        List = List->next;
        
    }
    std::cout<<std::endl;
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow_ptr = head;
        ListNode* quick_ptr = head;
        while(quick_ptr != NULL && quick_ptr->next != NULL) {
            slow_ptr = slow_ptr->next;
            quick_ptr = (quick_ptr->next)->next;
        }
        return slow_ptr;
    }
};

int main(int argc, char* argv[]) {
    ListNode a(1), b(2), c(3), d(4);
    ListNode* head = &a;
    head->next = &b;
    (head->next)->next = &c;
    ((head->next)->next)->next = &d;
    print_list(head);
    Solution s;
    ListNode* res = s.middleNode(head);
}
#include <iostream>
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* max_head = new ListNode(-1);
        ListNode* max_ptr = max_head;

        ListNode* min_head = new ListNode(-1);
        ListNode* min_ptr = min_head;
        if (head == NULL) return NULL;
        while(head != NULL) {
            if(head->val < x) {
                min_ptr->next = head;
                min_ptr = min_ptr->next;
            } else {
                max_ptr->next = head;
                max_ptr = max_ptr->next;
            }
            head = head->next;
        }
        // print_list(min_head->next);
        // print_list(max_head->next);
        max_ptr->next = NULL;
        min_ptr->next = max_head->next;
        return min_head->next;
    }
};


int main(int argc, char* argv[]) {
    ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
    ListNode* p1 = &n1;
    // p1->next = &n2;
    (p1->next) = &n3;
    (p1->next)->next = &n4;
    ((p1->next)->next)->next = &n5;
    (((p1->next)->next)->next)->next = &n6;
    print_list(p1);
    
    Solution s;
    ListNode* res = s.partition(p1, 3);
    print_list(res);

}
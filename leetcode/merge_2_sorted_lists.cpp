#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        ListNode* ori_head = new ListNode(-1);
        ListNode* head = ori_head;

        ListNode* cur_ptr = NULL;

        while(ptr1 != NULL &&  ptr2 != NULL ) {
            if(ptr1->val < ptr2->val) {
                cur_ptr = ptr1;
                head->next = cur_ptr;
                head = cur_ptr;
                ptr1 = ptr1->next;
                // cur_ptr->next = NULL;
  
                
            } else {
                cur_ptr = ptr2;
                head->next = cur_ptr;
                head = cur_ptr;
                ptr2 = ptr2->next;
                // cur_ptr->next = NULL;
       
                
            }
        }
        cur_ptr = ptr1 == NULL? ptr2: ptr1;
        head->next = cur_ptr;
        return ori_head->next;
        
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        if (ptr1 == NULL) return ptr2;
        if (ptr2 == NULL) return ptr1;
        ListNode* head = new ListNode(-1);
        ListNode* cur_ptr = head;
        while(ptr1 != NULL &&  ptr2 != NULL ) {
            if(ptr1->val < ptr2->val) {
                cur_ptr->next = ptr1;
                ptr1 = ptr1->next;
                cur_ptr = cur_ptr->next;
            } else {
                cur_ptr->next = ptr2;
                ptr2 = ptr2->next;
                cur_ptr = cur_ptr->next;

            }
        }
        cur_ptr->next = ptr1 == NULL? ptr2: ptr1;
        return head->next;
        
    }
};

void print_list(ListNode* List) {
    while(List != NULL)
    {    
        std::cout << List->val <<' ';
        List = List->next;
        
    }
    std::cout<<std::endl;
}

int main(int argc, char* argv[]) {
    ListNode ptr1_1(1), ptr1_2(2), ptr1_3(4);
    ListNode ptr2_1(1), ptr2_2(3), ptr2_3(4);

    // ListNode ptr1_1(5);
    // ListNode ptr2_1(1), ptr2_2(3), ptr2_3(4);
    
    ListNode* List1 = &ptr1_1;
    List1->next = &ptr1_2;
    List1->next->next = &ptr1_3;
    
    ListNode* List2 = &ptr2_1;
    List2->next = &ptr2_2;
    List2->next->next = &ptr2_3;
    
    std::cout <<"List1:";
    print_list(List1);

    std::cout <<"List2:";
    print_list(List2);
    std::cout<<std::endl;

    Solution s;
    ListNode* res = s.mergeTwoLists(List1, List2);
    std::cout <<"result:";
    print_list(res);
    std::cout<<std::endl;
    
}
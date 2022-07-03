#include<iostream>
#define REVERSE_LINK
#ifdef REVERSE_LINK
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int k = right - left + 1;
        ListNode* start = new ListNode(-1);
        start->next = head;
        for(int i = 1; i < left; i++) start = start->next;
        ListNode* new_res = reverseK(start->next, right - left + 1);
        start->next->next = end;
        start->next = new_res;
        return left == 1 ? start->next : head;


    }

    ListNode* reverseK(ListNode* head, int k) {
        if(k == 1) {
            end = head->next;
            return head;
        }
        ListNode* last = reverseK(head->next, k-1);
        head->next->next = head;
        return last;
    }
    ListNode* end = NULL;
};


int main(int argv, char* argc[]) {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(5);
    n1->next = n2;
    Solution a;
    ListNode* result = a.reverseBetween(n1, 1, 2);
    print_list(result);
}
#endif
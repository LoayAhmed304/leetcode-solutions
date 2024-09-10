/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode* prev = head;
        ListNode* ptr = head->next;

        while(ptr){
            int res = gcd(prev->val, ptr->val);
            ListNode* temp = new ListNode(res, ptr);
            prev->next = temp;
            prev = ptr;
            ptr = ptr->next;
        }

        return head;
    }
};

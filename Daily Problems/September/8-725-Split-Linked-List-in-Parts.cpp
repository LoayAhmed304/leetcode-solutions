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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size =0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            ++size;
        }
        int n = size / k;
        int extraNodes = size % k;

        vector<ListNode*>res;
        temp = head;

        for(int i = 0; i < k; i++){
            ListNode* sol = new ListNode();
            ListNode* final = sol;

            int numberNodes = n;
            if(extraNodes){
                numberNodes++;
                extraNodes--;
            }

            for(int j = 0; j < numberNodes; j++){
                if(temp){
                    ListNode* rest = new ListNode(temp->val);
                    sol->next = rest;
                    temp = temp->next;
                    sol=sol->next;
                }
            }
            res.push_back(final->next);
        }
        return res;
    }
};

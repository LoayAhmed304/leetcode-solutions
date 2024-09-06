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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>all;
        int n = nums.size();
        
        // Inserting in a hash set to make the find operation better
        for(int i =0; i< n; i++){
            all.insert(nums[i]);
        }

        // Skipping leading invalid numbers
        while(head && all.find(head->val) != all.end()){
            head = head->next;
        }

        ListNode* ptr = head->next;
        ListNode* slow = head;
        while(ptr){
            while(ptr && all.find(ptr->val) != all.end())
                ptr = ptr->next;
            slow->next = ptr;
            
            if(!ptr)break;

            slow = ptr;
            ptr = ptr->next;
        }

        return head;
    }
};

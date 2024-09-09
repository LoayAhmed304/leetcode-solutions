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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));

        int top = 0, bot = m - 1, left = 0, right = n - 1;

        while(head){

            // Iterate right
            for(int col = left; col <= right && head; ++col){
                res[top][col] = head->val;
                head = head->next;
            }
            ++top;

            // Iterate down
            for (int row = top; row <= bot && head; ++row){
                res[row][right] = head->val;
                head = head->next;
            }
            --right;

            // Iterate left
            for(int col = right; col >= left && head; --col){
                res[bot][col] = head->val;
                head = head->next;
            }
            --bot;

            // Iterate up
            for(int row = bot; row >= top && head; --row){
                res[row][left] = head->val;
                head = head->next;
            }
            ++left;
        }
        return res;
    }
};

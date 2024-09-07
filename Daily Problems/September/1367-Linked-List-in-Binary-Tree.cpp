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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool subPathRec(ListNode* head, TreeNode* root){
        if(!head) return true; // Reached the end of the list
        if(!root) return false; // Reached a end of the tree but not the list

        // If current node = current head value, continue the path
        if(root->val == head->val){
            if(subPathRec(head->next, root->left) || subPathRec(head->next, root->right))
                return true;
        }
        
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;

        if(subPathRec(head, root))
            return true;

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

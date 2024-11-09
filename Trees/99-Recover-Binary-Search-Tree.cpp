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
    void sol_19(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& middle, TreeNode*& last) {
        if (!root) return;

        sol_19(root->left, prev, first, middle, last);

        if (prev && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            }else
                last = root;
        }
        prev = root;
        sol_19(root->right, prev, first, middle, last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        sol_19(root, prev, first, middle, last);
        if(first && last){
            swap(first->val, last->val);
        }else if(first && middle){
            swap(first->val, middle->val);

        }
        
    }
};

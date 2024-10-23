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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*>q;
        q.push(root);
        vector<int>levelTotal;

        while(!q.empty()){
            int curSum = 0;
            int n = q.size();
            for(int i =0; i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                curSum += cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            levelTotal.push_back(curSum);
        }
        q.push(root);
        root->val = 0;
        int curLevel = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                int sum = 0;
                if(cur->left) sum += cur->left->val;
                if(cur->right) sum += cur->right->val;

                if(cur->left){
                    cur->left->val = levelTotal[curLevel] - sum;
                    q.push(cur->left);
                }
                if(cur->right){
                    cur->right->val = levelTotal[curLevel] - sum;
                    q.push(cur->right);
                }
            }
            ++curLevel;
        }
        return root;
    }
};

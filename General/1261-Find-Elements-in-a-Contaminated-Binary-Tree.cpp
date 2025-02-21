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
class FindElements {
public:
    unordered_map<int, bool>mp;
    void solRec(TreeNode* root,  int curNum){
        if(!root) return;
        root->val = curNum;
        mp[curNum] = true;
        if(root->left) solRec(root->left, curNum * 2 + 1);
        if(root->right) solRec(root->right, curNum * 2 + 2);
    }
    FindElements(TreeNode* root) {
        if(root)mp[0] = true;
        solRec(root->left, 1);
        solRec(root->right, 2);
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

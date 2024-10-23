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
    int deepestLeavesSum(TreeNode* root) {
        priority_queue<pair<int, int>>pq;
        queue<TreeNode*>q;

        q.push(root);
        int index = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n; i++){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur->left && !cur->right)
                pq.push({index, cur->val});
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            }
            index++;
        }
        int max = pq.top().first;
        int res = 0;
        while(!pq.empty() && pq.top().first == max){
            res += pq.top().second;
            pq.pop();
        }
        return res;


    }
};

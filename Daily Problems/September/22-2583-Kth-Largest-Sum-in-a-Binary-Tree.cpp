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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        int level = 0;
        priority_queue<long long, vector<long long>, greater<long long>>minHeap;
        queue<TreeNode*>q;

        q.push(root);
        long long curSum = 0;
        while(!q.empty()){
            curSum = 0;
            long long n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                curSum += cur->val;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            level++;
            if(minHeap.size() == k){
                if(curSum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(curSum);
                }
            }else{
                minHeap.push(curSum);
            }
        }
        if(level < k) return -1;
        return minHeap.top();
    }
};

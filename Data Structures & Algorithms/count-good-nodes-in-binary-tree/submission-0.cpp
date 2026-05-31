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
    int dfs(TreeNode* root , int maxsofar){
        if(!root) return 0 ;
        int cnt = 0 ;
        if(root->val >= maxsofar){
            cnt = 1;
            maxsofar = root->val;
        }
        cnt += dfs(root->left,maxsofar);
        cnt+= dfs(root->right, maxsofar);

        return cnt;
    }
    int goodNodes(TreeNode* root) {
     return dfs(root,root->val);   
    }
};

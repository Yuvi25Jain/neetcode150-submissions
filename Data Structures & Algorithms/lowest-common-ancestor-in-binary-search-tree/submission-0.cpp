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
    bool isValidBst(TreeNode* root , long minval , long maxval){
        if(!root) return true;
        if(root->val <= minval || root->val >= maxval) return false;
        return isValidBst(root->left,minval, root->val) && isValidBst(root->right, root->val , maxval);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};

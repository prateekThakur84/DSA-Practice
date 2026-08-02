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
    void solve(TreeNode* root, int tar, vector<vector<int>> &ans,vector<int> tmp){
        if(root == NULL) return;
        if(root->val == tar && root->left== NULL && root->right == NULL){
            tmp.push_back(root->val);
            ans.push_back(tmp);
            return;
        }else if(root->left == NULL && root->right == NULL){
                return;
        }
        

        tmp.push_back(root->val);



        solve(root->left,tar-(root->val),ans,tmp);

        solve(root->right,tar-(root->val),ans,tmp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        if(root->val == tar && root->left== NULL && root->right==NULL){
            vector<int> t;
            t.push_back(root->val);
            ans.push_back(t);
            return ans;
        }else if(root->val != tar && root->left== NULL && root->right==NULL){
            return ans;
        }
        vector<int> tmp;

        solve(root,tar,ans,tmp);
        return ans;
    }
};
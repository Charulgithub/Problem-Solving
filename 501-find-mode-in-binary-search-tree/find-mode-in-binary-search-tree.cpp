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
    vector<int>inorder( TreeNode* root, vector<int>& ans){
        if( root == NULL) return ans;
       else{
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
       }
       return ans;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        int maxcnt = 0;
        vector<int>mode;
        
        unordered_map<int, int> mp;
        for( auto it : ans){
            mp[it]++;
            maxcnt = max(maxcnt, mp[it]);
        }
        for(auto &pair : mp){
            if(pair.second == maxcnt){
                mode.push_back(pair.first);
            }
        }
        return mode;
    }
};
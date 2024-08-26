/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    
    void traversePostorder(Node* root){
        if(root == NULL) return;

        for(Node* child : root->children){
            traversePostorder(child);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        ans.clear();
        traversePostorder(root);
        return ans;
    }
};
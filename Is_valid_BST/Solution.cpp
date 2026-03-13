#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        vector<int> res;
        inorder(root, res);
        for(int i = 1; i < res.size(); i++){
            if(res[i] <= res[i-1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

TreeNode* createTree(){
    int val{0};
    cout<<"please enter val:\n";
    cin>>val;
    if(val==0){
        return nullptr;
    }
    TreeNode* node=new TreeNode(val);
    node->left=createTree();
    node->right=createTree();
    return node;
}

int main(){
    TreeNode* root=createTree();
    Solution s;
    if(s.isValidBST(root)){
        cout<<"true\n"; 
    }else{
        cout<<"false\n";
    }
}
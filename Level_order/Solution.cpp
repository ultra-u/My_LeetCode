#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        vector<TreeNode*> current{root};
        while(!current.empty()){
            vector<int> level;
            vector<TreeNode*> next;
            for(auto node : current){
                level.push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            res.push_back(level);
            current = next;
        }
        return res;
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
    Solution sol;
    vector<vector<int>> res=sol.levelOrder(root);
    for(const auto& level : res){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
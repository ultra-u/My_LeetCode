#include <iostream>
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
    int maxDepth(TreeNode* root) {
            if(root==nullptr)   return 0;
            return max(maxDepth(root->left),maxDepth(root->right))+1;           //分别递归左右子树并返回其子树高度
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
    Solution s1;
    int depth=s1.maxDepth(root);
    cout<<"the maxdepth of binary tree is "<<depth;
}
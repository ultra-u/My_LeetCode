#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {                                                    //递归交换左右节点
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left=invertTree(root->left);                      //递归左子树
        TreeNode* right=invertTree(root->right);                    //递归右子树
        root->left=right;
        root->right=left;
        return root;
    }
    friend ostream& operator<<(ostream& out, TreeNode* root);       //友元函数
};

ostream& operator<<(ostream& out, TreeNode* root) {                 //重载运算符来输出二叉树
    if (!root) {
        out << "Empty tree";
        return out;
    }

    queue<TreeNode*> q;
    q.push(root);
    out << "[";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            out << node->val;
            q.push(node->left);
            q.push(node->right);
        } else {
            out << "null";
        }

        if (!q.empty()) {
            out << ", ";
        }
    }
    out << "]";

    return out;
}

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
    cout<<"the invert tree is "<<s1.invertTree(root);
}
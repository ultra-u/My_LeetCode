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

class Solution {
public:
    bool check(TreeNode* p,TreeNode *q){                            //同步移动两个指针，分别对称遍历左右子树
        if(!p&&!q)  return true;                                    //p,q都为空，则当前一定对称
        if(!p||!q)  return false;                                   //p,q中有一个未空，则当前一定不对称
        return p->val==q->val&&check(p->left,q->right)&&check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
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
    cout<<"is symmetric: "<<s1.isSymmetric(root);
}
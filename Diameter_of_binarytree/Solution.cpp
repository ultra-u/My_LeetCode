#include<iostream>
#include<vector>
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
    int ans{0};
    int depth(TreeNode* node){
            if(node == nullptr) return 0;
            int left_depth = depth(node->left);
            int right_depth = depth(node->right);
            ans = max(ans, left_depth + right_depth + 1);
            return max(left_depth, right_depth) + 1;
        }
    int diameterOfBinaryTree(TreeNode* root){
        ans=1;
        depth(root);
        return ans - 1;
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
    TreeNode* root = createTree();
    Solution s;
    int result = s.diameterOfBinaryTree(root);
    cout << "The diameter of the binary tree is: " << result << endl;
}
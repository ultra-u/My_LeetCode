#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int leftSize = it - inorder.begin();
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSize);
        vector<int> rightPreorder(preorder.begin() + 1 + leftSize, preorder.end());
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it + 1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

int main(){
    int pre_number{0},in_number{0};
    cout<<"please input the number of preorder : "<<endl;
    cin>>pre_number;
    cout<<"please input the number of inorder : "<<endl;
    cin>>in_number;
    if (pre_number != in_number) {
        cout << "Error: preorder and inorder must have the same size!" << endl;
        return 1;
    }
    vector<int> preorder(pre_number), inorder(in_number);
    cout<<"please input the preorder : "<<endl;
    for(int i = 0; i < pre_number; ++i){
        cout<<"preorder["<<i<<"] : ";
        cin>>preorder[i];
    }
    cout<<"please input the inorder : "<<endl;
    for(int i = 0; i < in_number; ++i){
        cout<<"inorder["<<i<<"] : ";
        cin>>inorder[i];
    }
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    cout << "Constructed tree: [";
    
    if (root == nullptr) {
        cout << "]" << endl;
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<string> result;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();      
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
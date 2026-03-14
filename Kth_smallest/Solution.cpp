#include<iostream>
#include<vector>
#include<algorithm>
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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == nullptr) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    int kthSmallest(TreeNode* root,int k){
        vector<int> res;
        inorder(root,res);
        return res[k-1];
    }
};

TreeNode* createTree(vector<int> &nums, int index){
    if(index >= nums.size() || nums[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(nums[index]);
    root->left = createTree(nums, 2*index+1);
    root->right = createTree(nums, 2*index+2);
    return root;
}

int main(){
    int size{0},index{0};
    cout<<"Enter the size of the tree: ";
    cin>>size;
    vector<int> nums(size);
    cout<<"Enter the elements of the tree (use -1 for null nodes): ";
    for(int i=0; i<size; i++){
        cout<<"Node "<<i<<": \n";
        cin>>nums[i];
    }
    TreeNode* root = createTree(nums, 0);
    cout<<"Enter the value of index: ";
    cin>>index;
    Solution solution;
    cout<<"The "<<index<<"th smallest element is: "<<solution.kthSmallest(root, index)<<endl;
}
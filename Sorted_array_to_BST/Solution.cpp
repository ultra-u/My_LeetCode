#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
    friend ostream& operator<<(ostream& out, TreeNode* root);
};

ostream& operator<<(ostream& out, TreeNode* root) {                 
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

int main(){
    int val{0},size{0};
    vector<int> nums;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i{0};i<size;++i){
        cout<<"please enter val:\n";
        cin>>val;
        nums.push_back(val);
    }
    Solution s;
    TreeNode* root=s.sortedArrayToBST(nums);
    cout<<root;
}
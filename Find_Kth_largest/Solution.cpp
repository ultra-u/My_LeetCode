#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {                                                //采用堆排序解决，建立一个大根堆，输出第K次
public:
    void maxHeap(vector<int>&a,int i ,int heapsize){
        int l=i*2+1,r=i*2+2,largest=i;                          //堆的一些基本属性，本质上就是一个完全二叉树
        if(l<heapsize&&a[l]>a[largest]){                        //若左子节点大于当前节点，进行调整
            largest=l;
        }
        if(r<heapsize&&a[r]>a[largest]){                        //若有子节点大于当前节点，进行调整
            largest=r;
        }
        if(largest!=i){                                         //若子节点中有比父节点大的元素
            swap(a[i],a[largest]);                              //交换当前节点与largest节点
            maxHeap(a,largest,heapsize);                        //递归调用，调整节点位置以维持大根堆的特性
        }
    }
    void buildMaxHeap(vector<int>&a,int heapsize){
        for(int i=heapsize/2-1;i>=0;i--){                       //从最后一个非叶子节点开始遍历并调整节点以满足大根堆的性质
            maxHeap(a,i,heapsize);        
        }

    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapsize=nums.size();
        buildMaxHeap(nums,heapsize);                            //构建大根堆
        for(int i=nums.size()-1;i>=nums.size()-k+1;i--){              //从最后一个元素向前遍历到第K个元素
            swap(nums[0],nums[i]);                               //堆顶与堆底元素进行交换
            --heapsize;
            maxHeap(nums,0,heapsize);                           //重新调整堆以满足大根堆的性质
        }
        return nums[0];                                         //此时的堆顶元素为第K大元素
    }
};

int main(){
    int num{0},size{0},k{0};
    vector<int> nums{};
    cout<<"please enter k:\n";
    cin>>k;
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter num:\n";
        cin>>num;
        nums.push_back(num);
    }
    Solution s1;
    cout<<"find "<<k<<" th largest: "<<s1.findKthLargest(nums,k);
}
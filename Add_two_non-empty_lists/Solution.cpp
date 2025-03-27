#include <iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();                     //辅助节点，用于简化链表操作
        ListNode* curr=dummy;                               //curr指针用于追踪当前正在处理的节点
        int carry=0;                                        //carry用于存储进位值
        while(l1||l2||carry){
            int a=l1?l1->val:0;                             //如果 l1 非空，则 a 是 l1 当前节点的值，否则 a 为 0
            int b=l2?l2->val:0;                             //如果 l2 非空，则 b 是 l2 当前节点的值，否则 b 为 0
            int sum=a+b+carry;
            carry=sum>=10?1:0;                              //如果 sum 大于或等于 10，则进位为 1，否则为 0
            curr->next=new ListNode(sum%10);
            curr=curr->next;                                //创建一个新的 ListNode，其值为 sum 对 10 取模的结果，即个位数
            if(l1)  l1=l1->next;                            //l1非空，移动到下一个节点
            if(l2)  l2=l2->next;                            //l2非空，移动到下一个节点
        }
        return dummy->next;                                 //返回 dummy->next，即结果链表的第一个节点
    }
};
int main(){
    ListNode* l1=new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode* l2=new ListNode(5,new ListNode(6,new ListNode(4)));
    Solution s1;
    ListNode* result=s1.addTwoNumbers(l1,l2);
    while(result){
        std::cout<<result->val<<" ";
        result=result->next;
    }
    //释放内存
    delete l1->next->next;
    delete l1->next;
    delete l1;
    delete l2->next->next;
    delete l2->next;
    delete l2;
    delete result->next->next->next;
    delete result->next->next;
    delete result->next;
    delete result;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre=prices[0];                                  //记录前一天的股票价格
        int result{0};
        for(int price:prices){
            result=max(result,price-pre);                   //寻求最大利润
            pre=min(pre,price);                             //买入价格尽可能低
        }
        return result;
    }
};

int main(){
    int price{0},size{0};
    vector<int> prices{};
    cout<<"please enter size:\n";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"please enter price:\n";
        cin>>price;
        prices.push_back(price);
    }
    Solution s1;
    cout<<"the max profit is "<<s1.maxProfit(prices);
}
#include <bits/stdc++.h> 

int maxProfit(std::vector<int>& prices) {
        
     int pos_lprice = 0,pos_hprice=-1;
        
    for(int i = 1; i<prices.size(); i++)
        {
            if(prices[i] < prices[pos_lprice] )
                pos_lprice = i;
            else if(pos_hprice == -1)
                pos_hprice = i;
            else if(prices[pos_hprice] < prices[i])
                pos_hprice = i;
        }
        
    if(pos_hprice > pos_lprice && pos_hprice != prices.size())
        return prices[pos_hprice] - prices[pos_lprice];
    else
        return 0;
}

int main()
{
    std::vector<int> prices = {2,4,1};

    std::cout<<maxProfit(prices);
    return 0;
}

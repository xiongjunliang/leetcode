
//  Best Time to but and sell stock III 
//  Author: Xiongjun Liang

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> maxf(prices.size());
        vector<int> maxb(prices.size());
        
        int mf = prices[0];
        maxf[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            mf = min(mf, prices[i]);
            maxf[i] = max(maxf[i-1], prices[i] - mf);
        }
        int mb = prices[prices.size()-1];
        maxb[prices.size()-1] = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            mb = max(mb, prices[i]);
            maxb[i] = max(maxb[i+1], mb - prices[i]);
        }
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            maxprofit = max(maxprofit, maxf[i] + maxb[i]);
        }
        return maxprofit; 
    }
};


int main() {
    int x;
    int y;
    cin >> x;
    vector<int> p;
    while (x--) {
        cin >> y;
        p.push_back(y);
    }

    Solution s;
    cout << s.maxProfit(p) << endl;

    return 0;
}












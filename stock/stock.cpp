
//  Best Time to but and sell stock 
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
        int current_sell = prices[0];
        int current_buy = prices[0];
        int next_buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > current_sell) {
                current_sell = prices[i];
            }
            if (prices[i] < next_buy) {
                next_buy = prices[i];
            }
            if ((current_sell - current_buy) < (prices[i] - next_buy)) {
                current_sell = prices[i] ;
                current_buy = next_buy;
            }
        }

        return (current_sell - current_buy); 
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












class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (gas.size() == 0) {
            return -1;
        }
        int sum = 0;
        int min_sum = INT_MAX;
        vector<int> gc(gas.size());
        for (int i = 0; i < gas.size(); ++i) {
            gc[i] = gas[i] - cost[i];
            sum += gc[i];
            min_sum = min(min_sum, sum);

        }
        if (sum < 0) {
            return -1;
        }
        int i;
        for (i = 0; i < gc.size(); ++i) {
            if (min_sum >= 0) {
                break;
            } else {
                min_sum -= gc[i];
            }
        }
        if (i < gc.size()) {
            return i;
        } else {
            return -1;
        }
    }
};

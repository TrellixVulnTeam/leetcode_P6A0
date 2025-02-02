#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <bitset>
#include <sstream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {//https://discuss.leetcode.com/topic/19750/my-c-solution-o-n-time-o-1-space-8ms
public:
	int maxProfit(vector<int>& prices) {
		int states[2][4] = { INT_MIN, 0, INT_MIN, 0 }; // 0: 1 buy, 1: one buy/sell, 2: 2 buys/1 sell, 3, 2 buys/sells
		int len = prices.size(), i, cur = 0, next = 1;
		for (i = 0; i<len; ++i)
		{
			states[next][0] = max(states[cur][0], -prices[i]);
			states[next][1] = max(states[cur][1], states[cur][0] + prices[i]);
			states[next][2] = max(states[cur][2], states[cur][1] - prices[i]);
			states[next][3] = max(states[cur][3], states[cur][2] + prices[i]);
			swap(next, cur);
		}
		return max(states[cur][1], states[cur][3]);
	}
};
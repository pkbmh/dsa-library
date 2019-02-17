#include "../../../common/headers.hpp"


int stock_profit(vector<int> &prices, int k) {
	int d = prices.size();
	vector<vector<int> >dp(k+1, vector<int>(d+1, 0));

	for(int i = 1; i <= k; ++i) {
		for(int j = 1; j <= d; ++j) {
			// no transaction on j'th day, done j transaction before j'th day
			dp[i][j] = dp[i][j-1];

			// let's sell on j'th day meaning that we have to buy before j'th day
			for(int m = 0; m < j; ++m) {
				dp[i][j] = max(dp[i][j], dp[i-1][m]+prices[j]-prices[m]);
			}
		}
	}

	return dp[k][d];
}

int main()
{
	vector<int> prices = {2, 5, 7, 1, 4, 3, 1, 3};
	int k = 3;

	int profit = stock_profit(prices, k);
	cout << "Max profit = " << profit << endl;
	return 0;
}
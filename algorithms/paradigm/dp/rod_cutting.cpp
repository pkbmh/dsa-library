#include "../../../common/headers.hpp"


int rod_cut_max_profit(int price[], int len, int rod_len) {
	int dp[rod_len+1];
	
	for(int i = 0; i < len; ++i)
		dp[i+1] = price[i];

	for(int l = 1; l <= rod_len; ++l) {
		for(int i = 1; i <= len; ++i) {
			if(l >= i) 
				dp[l] = max(dp[l], dp[l-i]+price[i-1]);
		}
	}
	return dp[rod_len];
}
	
int main()
{	
	int price[] = {3,5,8,9,10,20,22,25};
	int rod_len = 10;
	int len = sizeof(price) / sizeof(price[0]);

	int profit = rod_cut_max_profit(price, len, rod_len);
	cout << "Max profit by cutting road = " << profit << endl;
return 0;
}
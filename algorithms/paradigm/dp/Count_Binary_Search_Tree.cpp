#include "../../../common/headers.hpp"


LLI count_bst(int k) {

	if(k <= 1) return 1;

	int cnt = 0;
	for(int i = 1; i <= k; ++i) {
		cnt += count_bst(i-1) * count_bst(k-i);
	}
	return cnt; 
}

LLI count_bst_dp(int keys) {
	LLI dp[keys+1];
	dp[0] = 1;

	for(int k = 1; k <= keys; ++k) {
		dp[k] = 0;
		for(int i = 1; i <= k; ++i) {
			dp[k] += dp[i-1] * dp[k-i];
		}

	}

	return dp[keys];
}
int main()
{

	for(int i = 1; i <= 100; ++i)
	cout << count_bst_dp(i) << endl;
}
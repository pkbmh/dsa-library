#include "../../../common/headers.hpp"


int max_profit(vector<int>&arr, int i, int j) {
	if(i > j) return 0;
	if(i == j) return arr[i];
	int ci = arr[i] + min(max_profit(arr, i+2, j), max_profit(arr, i+1, j-1));
	int cj = arr[j] + min(max_profit(arr, i+1, j-1), max_profit(arr, i, j-2));
	return max(ci, cj);
}

int max_profit_dp(vector<int>&arr) {
	int len = arr.size();
	int dp[len][len];

	for(int i = 0; i < len; ++i) {
		memset(dp[i], 0, sizeof(dp[i]));
		dp[i][i] = arr[i];
	}

	for(int l = 2; l <= len; ++l) {
		for(int i = 0; i <= len-l; ++i) {
			int j = i+l-1;

			if(l == 2) {
				dp[i][j] = max(arr[i], arr[j]);
			}else {
				int ci = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
				int cj = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);

				dp[i][j] = max(ci, cj);
			}
		}
	}

	return dp[0][len-1];
}

int main()
{
	// vector<int> arr = {3,9,1,2};
	// cout << max_profit(arr, 0, arr.size()-1) << " " << max_profit_dp(arr) <<  endl;
	srand(time(NULL));
	int t = 100;
	while(t--){
		int n = abs(rand() % 17) + 5;
		vector<int>arr(n);
		for(int i = 0; i < n; ++i) {
			arr[i] = abs(rand() % 1000);
		}
		int ans_rec =  max_profit(arr, 0, arr.size()-1);
		int ans_dp = max_profit_dp(arr);

		assert(ans_dp == ans_rec);	
	}
	return 0;
}
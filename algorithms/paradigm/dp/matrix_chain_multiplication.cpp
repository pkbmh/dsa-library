#include "../../../common/headers.hpp"


int mcm_cost_copy(int arr[], int len) {
	
	int dp[len][len];
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			dp[i][j] = 0;

	for(int i = 0; i < len; ++i) dp[i][i] = 0;

	for(int l = 2; l < len; ++l) {
		for(int i = 0; i < len-l; ++i) {
			int j = i + l;
			dp[i][j] = 5000000;
			cout << i << " ii " << j << endl;
			for(int k = i+1; k < j; ++k) {
				int tmp = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
				cout << k << "k " << tmp << endl;
				dp[i][j] = min(dp[i][j], tmp);
			}
		}
		for(int x = 0; x < len; ++x) {
			for(int y = 0; y < len; ++y)
				cout << dp[x][y] << " ";
			cout << endl;
		}
		cout << "------" << endl;
	}

	return dp[0][len-1];
}
int mcm_cost(int arr[], int len) {
	
	int dp[len][len];
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			dp[i][j] = INT_MAX-10000;

	for(int i = 0; i < len; ++i) dp[i][i] = 0;

	for(int l = 2; l < len; ++l) {
		for(int i = 0; i < len-l; ++i) {
			int j = i + l - 1;
			
			for(int k = i; k < j; ++k) {
				int tmp = dp[i][k] + dp[k+1][j] + arr[i] * arr[k+1] * arr[j+1];
				dp[i][j] = min(dp[i][j], tmp);
			}
		}
	}

	return dp[0][len-2];
}
int main()
{
	int mats[] = {4,2,3,5,3};
	int len = sizeof(mats) / sizeof(int);

	int cost = mcm_cost(mats, len);
	
	cout << "multiplication cost is = " << cost << endl;
	return 0;
}

#include "../../../common/headers.hpp"


int coin_change_min_coin(int arr[], int len, int sum) {
	int dp[sum+1];
	int path[sum+1];

	dp[0] = 0;
	
	for(int i = 1; i <= sum; ++i) dp[i] = INT_MAX-1;
	for(int i = 1; i <= sum; ++i) {
		for(int j  = 0; j < len; ++j) {
			if(arr[j] <= i && dp[i] > dp[i-arr[j]]) {
				dp[i] = dp[i-arr[j]] + 1;
				path[i] = j;
			}
		}
	}
	if(dp[sum] >= INT_MAX-1) return INT_MAX;

	cout << "******* Coin used *******" << endl;
	int i = sum;
	while(i > 0) {
		cout << arr[path[i]] << " ";
		i -= arr[path[i]];
	}
	cout << endl << "*************************" << endl;

	return dp[sum];
}
int main()
{
	int total = 13;
    int coins[] = {7, 3, 2, 6};
    int len = sizeof(coins) / sizeof(coins[0]);
    int min_coin = coin_change_min_coin(coins, len, total);
    cout << "minimum coin required is = " << min_coin << endl;
return 0;
}
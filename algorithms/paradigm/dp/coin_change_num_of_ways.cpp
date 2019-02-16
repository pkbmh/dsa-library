#include "../../../common/headers.hpp"



int coin_change_ways(int arr[], int len, int sum) {
	int dp[len+1][sum+1];

	for(int i = 0; i <= len; ++i) {
		memset(dp[i], 0, sizeof(dp[i]));
		dp[i][0] = 1;
	}


	for(int w = 1; w <= sum; ++w) {
		for(int i = 1; i <= len; ++i) {
			dp[i][w] = dp[i-1][w];
			if(arr[i-1] <= w) {
				dp[i][w] += dp[i][w-arr[i-1]];
			}
		}
	}

	return dp[len][sum];
}

void print_coins(int arr[], int total, int ind, int len, vector<int>&tmp) {
	if(total == 0){
		for(int i : tmp) cout << i << " ";
		cout << endl;
		return;
	}

	if(ind == len) return;

	if(arr[ind] <= total) {
		tmp.push_back(arr[ind]);
		print_coins(arr, total-arr[ind], ind, len, tmp);
		tmp.pop_back();
	}
	print_coins(arr, total, ind+1, len, tmp);
}
int main()
{

	int total = 15;
    int coins[] = {3,4,6,7,9};
    int len = sizeof(coins) / sizeof(coins[0]);

    int ways = coin_change_ways(coins, len, total);
	

	cout << "No of way to change = " << ways << endl;
	cout << "printing solutions" << endl;
	vector<int>tmp;
	print_coins(coins, total, 0, len, tmp);
	cout << "-------------------" << endl;

	total = 25;
	int coins1[] = {4,3,1,4,6,5,7,8,9};
	len = sizeof(coins1) / sizeof(coins1[0]);

	ways = coin_change_ways(coins1, len, total);
	cout << "No of way to change = " << ways << endl;

	return 0;
}


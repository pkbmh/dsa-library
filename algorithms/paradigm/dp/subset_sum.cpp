#include "../../../common/headers.hpp"


bool subset_sum(int arr[], int len, int sum) {
	bool dp[len+1][sum+1];
	dp[0][0] = true;
	for(int i = 1; i <= sum; ++i) dp[0][i] = false;

	for(int i = 1; i <= len; ++i) {
		for(int j  = 1; j <= sum; ++j) {
			dp[i][j] = dp[i-1][j];
			if(j >= arr[i-1])
				dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
		}
	}

	return dp[len][sum];
}
int main()
{
	int arr[] = {6, 3, 5, 5, 2, 3, 2, 6};
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << subset_sum(arr, len, 11) << endl;
	cout << subset_sum(arr, len, 17) << endl;
	cout << subset_sum(arr, len, 7) << endl;
	cout << subset_sum(arr, len, 15) << endl;
	cout << subset_sum(arr, len, 1) << endl;


	return 0;
}
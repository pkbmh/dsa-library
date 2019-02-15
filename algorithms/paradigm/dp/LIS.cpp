#include "../../../common/headers.hpp"


int lis(int arr[], int len) {
	int dp[len];
	int path[len];
	for(int i = 0; i < len; ++i) {
		dp[i] = 1;
		path[i] = i;
	}

	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < i; ++j) {
			if(arr[i] > arr[j] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
				path[i] = j;
			}
		}
	}

	// TODO: Correct path
	int i = len-1;
	stack<int>st;
	while(path[i] != i) {
		st.push(arr[path[i]]);
		i = path[i];
	}
	st.push(arr[i]);

	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}cout << endl;

	return dp[len-1];
}
int main()
{
	int arr[] = {23,10,22,5,33,8,9,21,50,41,60,80,99, 22,23,24,25,26,27};
	int len = sizeof(arr) / sizeof(arr[0]);

	cout << "LIS length = " << lis(arr, len) << endl;
return 0;
}
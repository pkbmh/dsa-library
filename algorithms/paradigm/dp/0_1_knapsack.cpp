#include "../../../common/headers.hpp"

int main() {
	int val[] = {22, 20, 15, 30, 24, 54, 21, 32, 18, 25};
    int wt[] = {4, 2, 3, 5, 5, 6, 9, 7, 8, 10};

    int sz = sizeof(val) / sizeof(int);

    int capacity = 30;

    int dp[capacity+1][sz+1];
    for(int i = 0; i <= capacity; ++i) memset(dp[i], 0, sizeof(dp[i]));

    for(int i = 1; i <= sz; ++i) {
    	for(int j = 1; j <= capacity; ++j) {
    		if(j >= wt[i-1]) {
    			dp[j][i] = max(dp[j-wt[i-1]][i-1]+val[i-1], dp[j][i-1]);
    		}
    	}
    }

    cout << "max profit is " << dp[capacity][sz] << endl;
return 0;
}
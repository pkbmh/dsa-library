#include "../../../common/headers.hpp"


int optimial_bst(int input[], int freq[], int len) {
	int dp[len][len];

	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			dp[i][j] = INT_MAX/2;

	for(int i = 0; i < len; ++i) dp[i][i] = freq[i];

	for(int l = 2; l <= len; ++l) {
		for(int i = 0; i <= len-l; ++i) {
			int j = i+l-1;
			
			int sum = 0;
			
			// TODO: can be changed with prefix sum
			for(int k = i; k <= j; ++k) sum += freq[k];

			for(int k = i; k <= j; ++k){
				// when k is i meaning that i'th node is root and i+1 to j nodes are in right.
				// when k is j meaning that j'th node is root and i to j-1 nodes are in left.
                int val = sum + (k == i ? 0 : dp[i][k-1]) + (k == j ? 0 : dp[k+1][j]) ;
                dp[i][j] = min(dp[i][j], val);
            }
		}
	}

	
	return dp[0][len-1];
}
int main()
{
	int input[] = {10,12,20,35,46};
    int freq[] = {34,8,50,21,16};
    int len = sizeof(input) / sizeof(input[0]);

    int cost = optimial_bst(input, freq, len);
    cout << "optimal cost is = " << cost << endl;
	return 0;
}
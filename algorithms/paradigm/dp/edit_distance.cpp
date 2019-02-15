#include "../../../common/headers.hpp"

int edit_dist(string a, string b) {
	int len1 = a.length();
	int len2 = b.length();

	int dp[len1+1][len2+1];

	for(int i = 0; i <= len1; ++i) dp[i][0] = i;
	for(int i = 0; i <= len2; ++i) dp[0][i] = i;

	for(int i = 1; i <= len1; ++i) {
		for(int j = 1; j <= len2; ++j) {
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
		}
	}
	cout << "Operations" << endl;

	int i = len1;
	int j = len2;
	while(i > 0 && j > 0) {
		if(a[i-1] == b[j-1]) {
			--i;
			--j;
		}else {
			if(dp[i][i] == dp[i-1][j]+1) {
				cout << "Deleted from string 1, char : " << a[i-1] << endl; 
				--i;
			}else if(dp[i][j] == dp[i][j-1]+1) {
				cout << "Deleted from string 2, char : " << b[j-1] << endl; 
				--j;
			}else {
				cout << "Edit string1 char: " << a[i-1] << " :: string 2 char : " << b[j-1] << endl;
				--i;
				--j; 
			}
		}
	}
	return dp[len1][len2];
}

int main()
{
	string a = "azced";
    string b = "abcdef";

    int dist = edit_dist(a, b);
    cout << "edit distance is = " << dist << endl;

return 0;
}

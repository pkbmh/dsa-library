#include "../../../common/headers.hpp"


int longest_pali_subseq(string str) {
	int len = str.length();

	int dp[len][len];
	for(int i = 0; i < len; ++i) memset(dp[i], 0, sizeof(dp[i]));
	for(int i = 0; i < len; ++i) dp[i][i] = 1;

	for(int l = 2; l <= len; ++l) {
		for(int i = 0; i <= len-l; ++i) {
			int j = i+l-1;
			if(l == 2 && str[i] == str[j])
                dp[i][j] = 2;
			else if(str[i] == str[j]) {
				dp[i][j] = dp[i+1][j-1]+2;
			}else {
				dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return dp[0][len-1];
}
int main()
{
	string str = "agbdba"; // 5
	cout <<"Longest Palindromic Subsequence length = "<< longest_pali_subseq(str) << endl;

	str = "agbdbaasafdasfadedasdeasfds"; // 15
	cout <<"Longest Palindromic Subsequence length = "<< longest_pali_subseq(str) << endl;

	str = "agbdeasedsassasaaaasaaaasa"; // 14
	cout <<"Longest Palindromic Subsequence length = "<< longest_pali_subseq(str) << endl;
}

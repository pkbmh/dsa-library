// https://leetcode.com/problems/regular-expression-matching/


#include "../../../common/headers.hpp"


bool match(string str, string pattern) {
	int len = str.length();
	int pl = pattern.length();

	bool dp[len+1][pl+1];
	for(int i = 0; i <= len; ++i) memset(dp[i], 0, sizeof(dp[i]));

	dp[0][0] = true;
	
	for (int i = 1; i <= pl; i++) {
        if (pattern[i-1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }

	for(int i = 1; i <= len; ++i) {
		for(int j = 1; j <= pl; ++j) {
			if(str[i] == pattern[j-1] || pattern[i-1] == '.') {
				dp[i][j] = dp[i-1][j-1];
			}else if(pattern[j-1] == '*'){
				if(j-1 > 0) {
					dp[i][j] = dp[i][j-2];
					if(pattern[j-2] == str[i-1] || pattern[j-2] == '.')
						dp[i][j] = dp[i][j] || dp[i-1][j];
				}
			}else dp[i][j] = false;
		}
	}



	return dp[len][pl];
}
int main() {
	string str = "acaabbaccbbacaabbbb";
	string patt = "a*.*b*.*a*aa*a*";

	cout << "Does string matches pattern = " << match(str, patt) << endl;
return 0;
}
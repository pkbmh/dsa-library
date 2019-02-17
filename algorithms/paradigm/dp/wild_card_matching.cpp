#include "../../../common/headers.hpp"

bool isMatch(string text, string pattern) {
	// replace multiple * by one

	int i = 0;
	int j = 0;
	int cnt = 0;
	while(j < pattern.length()) {
		if(pattern[j] == '*') {
			if(cnt == 0) {
				swap(pattern[i], pattern[j]);
				++i;
			}
			++j;
			++cnt;
		}else {
			cnt = 0;
			swap(pattern[i], pattern[j]);
			++i;
			++j;
		}
	}
	int len = text.length();
	int pl = i;

	bool dp[len+1][pl+1];
	for(int i = 0; i <= len; ++i) memset(dp[i], 0, sizeof(dp));
	if (pl > 0 && pattern[0] == '*') {
        dp[0][1] = true;
    }

    dp[0][0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= pl; j++) {
            if (pattern[j-1] == '?' || text[i-1] == pattern[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else if (pattern[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[len][pl];
}

bool isMatchRec(string text, string pattern, int i = 0, int j = 0) {
	if(j == pattern.length()) return i == text.length();
	if(pattern[j] == '*') {
		while(j+1 < pattern.length() && pattern[j+1] == '*') ++j;
		return isMatchRec(text, pattern, i+1, j+1) || isMatchRec(text, pattern, i+1, j);
	}else {
		if(i < text.length() && (text[i] == pattern[j] || pattern[j] == '?'))
			return isMatchRec(text, pattern, i+1, j+1);
		return false;
	}
}
int main()
{
	string text = "xbylmz";
	string pattern = "x?y*z";

	cout << "Text isMatch pattern = " << isMatchRec(text, pattern) << endl;
	cout << "Text isMatch pattern = " << isMatch(text, pattern) << endl;
return 0;
}
#include "../../../common/headers.hpp"


string lcs(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();

	int dp[len1+1][len2+1];

	for(int i = 0; i <= len1; ++i) dp[i][0] = i;
	for(int i = 0; i <= len2; ++i) dp[0][i] = i;

	for(int i = 1; i <= len1; ++i)
		for(int j = 1; j <= len2; ++j)
			if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;

	string tmp = "";

	int i = len1;
	int j = len2;

	while(i > 0 && j > 0) {
		if(str1[i-1] == str2[j-1]) {
			tmp = str1[i-1] + tmp;
			i--;
			j--;
		}
		else if(dp[i][j] == dp[i-1][j]+1) i--;
		else j--;
	}

	return tmp;
}
int main() {

	string str1 = "ABCDGHLQR";
    string str2 = "AEDPHR";
    string lcs_str = lcs(str1, str2);
    cout << lcs_str << " len = " << lcs_str.length() << endl;

   	assert(lcs_str.length() == 4);

    str1 = "asdadwefweafwaefwaklwelfwewefweffjadwvcuasdc";
    str2 = "asdasweweaffweafwaehjdfvwejbdfasguayewfawkefuwae";
    lcs_str = lcs(str1, str2);

    cout << lcs_str << " len = " << lcs_str.length() << endl;

   	assert(lcs_str.length() == 26);
	return 0;
}
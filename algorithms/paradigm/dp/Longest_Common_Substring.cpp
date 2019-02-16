#include "../../../common/headers.hpp"

string lcs(string str1, string str2) {
	int len1 = str1.length();
	int len2 = str2.length();

	int dp[len1+1][len2+1];

	for(int i = 0; i <= len1; ++i) memset(dp[i], 0, sizeof(dp[i]));
	//for(int i = 0; i <= len2; ++i) dp[0][i] = 0;

	int rr;
	int rc;
	int ans = 0;
	for(int i = 1; i <= len1; ++i)
		for(int j = 1; j <= len2; ++j){
			if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = 0;

			if(dp[i][j] > ans) {
				ans = dp[i][j];
				rr = i;
				rc = j;
			}
		}

	string tmp = "";

	while(dp[rr][rc] > 0) {
		tmp = str1[rr-1] + tmp;
		--rr;
		--rc;
	}

	return tmp;
}
int main() {

	string str1 = "ABCDGHLQR";
    string str2 = "AEDPHR";
    string lcs_str = lcs(str1, str2);
    cout << lcs_str << " len = " << lcs_str.length() << endl;

    str1 = "asdadwefweafwaefwaklwelfwewefweffjadwvcuasdc";
    str2 = "asdasweweaffweafwaehjdfvwejbdfasguayewfawkefuwae";
    lcs_str = lcs(str1, str2);
    cout << lcs_str << " len = " << lcs_str.length() << endl;

   	str1 = "abcdaf";
    str2 = "xbcdf";
    lcs_str = lcs(str1, str2);

    cout << lcs_str << " len = " << lcs_str.length() << endl;

	return 0;
}
#include "../../../common/headers.hpp"


bool isIntterLeavingRec(string str1, int ind1, string str2, int ind2, string str3, int ind3) {
	if(ind3 == str3.length()) return true;

	if(ind1 == str1.length() && ind2 == str2.length()) return false;

	bool res = false;
	if(str1[ind1] == str3[ind3]) res = res || isIntterLeavingRec(str1, ind1+1, str2, ind2, str3, ind3+1);
	if(!res && str2[ind2] == str3[ind3]) return isIntterLeavingRec(str1, ind1, str2, ind2+1, str3, ind3+1);
}


bool isIntterLeavingDp(string str1, string str2, string str3) {
	int len1 = str1.length();
	int len2 = str2.length();
	int len3 = str3.length();

	bool dp[len1+1][len2+1];
	for(int i = 0; i <= len1; ++i) memset(dp[i], 0, sizeof(dp[i]));
	
	for(int i = 0; i <= len1; ++i) {
		for(int j = 0; j <= len2 && i+j <= str3.length(); ++j) {
			if(i == 0 && j == 0) {
				dp[i][j] = true;
			}else if(i == 0 || j == 0) {
				if(i == 0) dp[i][j] = dp[i][j-1] && (str2[j-1] == str3[i+j-1]); 
				else dp[i][j] = dp[i-1][j] && (str1[i-1] == str3[i+j-1]); 
			}else {
				dp[i][j] = (dp[i][j-1] && (str2[j-1] == str3[i+j-1])) || (dp[i-1][j] && (str1[i-1] == str3[i+j-1]));
			}


			if(i+j == str3.length() && dp[i][j]) return true;
			
		}
	}
	return false;
}


int main()
{
	string str1 = "XXYM";
    string str2 = "XXZT";
    string str3 = "XXXZXYTM";
	return 0;
}
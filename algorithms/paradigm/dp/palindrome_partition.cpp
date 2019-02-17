#include "../../../common/headers.hpp"


int min_palindrome_partition(string str) {
	int len = str.length();
	bool isPalindrome[len][len];
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < len; ++j) 
			isPalindrome[i][j] = false;
		isPalindrome[i][i] = true;
	}

	for(int l = 2; l <= len; ++l) {
		for(int i = 0; i <= len-l; ++i) {
			int j = i+l-1;
			if(l == 2 && str[i] == str[j])
				isPalindrome[i][j] = true;
			else {
				if(str[i] == str[j])
					isPalindrome[i][j] = isPalindrome[i+1][j-1];
				else isPalindrome[i][j] = false;
			}
		}
	}
	int cnt[len];
	for(int i = 0; i < len; ++i) {
		if(isPalindrome[0][i]) cnt[i] = 0;
		else {
			cnt[i] = INT_MAX;

			for(int j = 1; j <= i; ++j) {
				if(isPalindrome[j][i] && cnt[j-1] != INT_MAX && cnt[j-1]+1 < cnt[i])
					cnt[i] = cnt[j-1] + 1;
			}
		}
	}
	return cnt[len-1];
}
int main() {

}
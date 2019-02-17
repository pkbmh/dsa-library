#include "../../../common/headers.hpp"


int max_val(vector<int>& arr) {
if(arr.size() == 0) return 0;
int len = arr.size();
int dp[len][len];


for(int i = 0; i < len; ++i){
    for(int j = 0; j < len; ++j)
        dp[i][j] = 0;
    int left = 1, right = 1;
    
    if(i != 0) left = arr[i-1];
    if(i != len-1) right = arr[i+1];
    
    dp[i][i] = (left * arr[i] * right);
}

for(int l = 2; l <= len; ++l) {
    for(int i = 0; i <= len-l; ++i) {
        int j = l+i-1;
        // i last burst in i..j or j last burst in i..j
        for(int k = i; k <= j; ++k) {
            int left = (i == 0 ? 1 : arr[i-1]);
            int right = (j == len-1 ? 1 : arr[j+1]);
            
            int leftV = (k == i ? 0 : dp[i][k-1]);
            int rightV = (k == j ? 0 : dp[k+1][j]);
            dp[i][j] = max(dp[i][j], leftV + rightV + left * arr[k]* right);
        }
    }
}

return dp[0][len-1];
}

int main()
{
    vector<int> arr = {3,1,5,8};
    cout << "Maximum burst profit is = " << max_val(arr) << endl;
return 0;
}
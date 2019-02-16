// https://leetcode.com/problems/word-break/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        int len = s.length();
        bool dp[len][len];
        for(int i = 0; i < len; ++i) memset(dp[i], 0, sizeof(dp[i]));
        // lenght 1;
        for(int i = 0; i < len; ++i) {
            string tmp = string(1,s[i]);
            if(dict.find(tmp) != dict.end())
                dp[i][i] = true;
        }
        for(int l = 2; l <= len; ++l) {
            for(int i = 0; i <= len-l; ++i) {
                int j = i+l-1;
                string tmp = "";
                for(int k = j; k >= i; --k) {
                    tmp = s[k] + tmp;
                    if(dict.find(tmp) != dict.end()) {
                        dp[k][j] = true;
                        if(k != i && dp[i][j] == false) {
                            dp[i][j] = dp[i][k-1] && dp[k][j];
                            
                        }
                    }
                }
            }
        }
        
        return dp[0][len-1];
    }
    bool wordBreak1(string s, vector<string>& wordDict) {
        
        set<string>dict;
        for(string str : wordDict) {
            dict.insert(str);
        }
        map<string,bool> dp;
        return wordBreak(s, dict, dp);
        
    }
    
    bool wordBreak(string s, set<string>&dict, map<string,bool>&dp) {
        if(s.length() == 0) return true;
        if(dp.find(s) != dp.end()) {
            return false;
        }
        string str = "";
        for(int i = 0; i < s.length(); ++i) {
            str = str + s[i];
            
            if(dict.find(str) != dict.end() && wordBreak(s.substr(i+1), dict, dp)) {
                 return true;
            }
        }
        
        return dp[s] = false;
    }
};
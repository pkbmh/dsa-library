#include "../../../common/headers.hpp"

void  clearTmp(vector<string>&tmp, int diff, vector<string>&result) {
        if(diff > 0) {
             if(tmp.size() == 1) {
                 tmp.push_back(string(diff, ' '));
             }else {
                int sz = tmp.size();
                int sp = sz/2;
                if(diff > sp){
                    tmp[1] = tmp[1] + string(diff/sp+diff%sp, ' ');
                    for(int i = 3; i < tmp.size(); i += 2) {
                        tmp[i] = tmp[i] + string(diff/sp, ' ');
                    }
                }else {
                    for(int i = 1; diff && i < tmp.size(); i += 2) {
                        tmp[i] = tmp[i] + " ";
                        --diff;
                    }
                }
             }
         }
        string tmps = "";
        for(int i = 0; i < tmp.size(); ++i) {
            tmps += tmp[i];
        }
        tmp.clear();
        result.push_back(tmps);
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> tmp;
        tmp.push_back(words[0]);
        int tmp_len = words[0].length();
        
        for(int i = 1; i < words.size(); ++i) {
            string str = words[i];
            
            if(tmp_len + str.length() + 1 <= maxWidth) {
                tmp.push_back(" ");
                tmp.push_back(str);
                tmp_len += 1 + str.length();
            }else {
                int diff = maxWidth - tmp_len;
                clearTmp(tmp, diff, result);
                tmp.push_back(str);
                tmp_len = str.length();
            }
        }
        int diff = maxWidth - tmp_len;
        if(diff > 0) {
            tmp.push_back(string(diff, ' '));
        }
        string tmps = "";
        for(int i = 0; i < tmp.size(); ++i) {
            tmps += tmp[i];
        }
        tmp.clear();
        result.push_back(tmps);
        
          
        return result;
    }
    

// minimum cost 
pair<int, vector<string> > justify(vector<string>&words, int maxWidth) {
    int len = words.size();
    int cost[len][len];

    for(int i = 0; i < len; ++i) {
        
        cost[i][i] = maxWidth - words[i].length();
        cost[i][i] = cost[i][i] * cost[i][i];
        int ll = words[i].length();

        for(int j = i+1; j < len; ++j) {
            ll += words[j].length() + 1;
            if(ll <= maxWidth) {
                cost[i][j] = maxWidth - ll;
                cost[i][j] = cost[i][j] * cost[i][j];
            }else {
                cost[i][j] = INT_MAX;
            }  
        }
    }
    // for(int i = 0; i < len; ++i){
    //     for(int j = 0; j < len; ++j)
    //         printf("%d ", cost[i][j]);
    //     cout << endl;
    // }


    int result[len+1];
    int path[len+1];
    
    result[len] = 0;
    path[len] = -1;

    for(int i = len-1; i >= 0; --i) {

        result[i] = INT_MAX;
        for(int j = i; j < len; ++j) {

            // If i to j can fit into one line
            if(cost[i][j] != INT_MAX && cost[i][j] + result[j+1] < result[i]){
                result[i] = cost[i][j] + result[j+1];
                path[i] = j;
            }
        }
    }

    // for(int i = 0; i < len; ++i) cout << result[i] << " "; cout << endl;
    // for(int i = 0; i < len; ++i) cout << path[i] << " "; cout << endl;
    
    
    int i = 0;
    vector<string> ans;
    while(i < len) {
        int j = path[i];
        string tmp = words[i];
        for(int k = i+1; k <= j; ++k) {
            tmp = tmp + " " + words[k];
        }
        ans.push_back(tmp);
        i = j+1;
    }
    return {result[0], ans};
}
int main() {

    // vector<string> words = {"pkbmhh","boy","likes","to","code"};
    vector<string> words = {"pkbmhh","likes","to","write","code","at", "free", "time"};
    int maxWidth = 12;
    pair<int, vector<string> > result = justify(words, maxWidth);
    cout << "Minimum cost = " << result.first << endl;
    for(string str : result.second) cout << str << endl;
    return 0;
}
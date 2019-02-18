#include "../../../common/headers.hpp"

typedef vector<vector<char> >VVC;
typedef std::vector<std::vector<PII> > VVPII;
#define hori F 
#define ver S

int find_square(VVC mat) {
	int mx = 0;
	int len = mat.size();
	VVPII T(len);
	for(int i = 0; i < len; ++i)T[i].resize(mat[i].size(), {0,0});

	for(int i=0; i < len; i++){
            for(int j=0; j < mat[i].size(); j++){
                if(mat[i][j] == 'X'){
                    if(i == 0 && j == 0){
                        T[i][j].hori = 1;
                        T[i][j].ver = 1;
                    }
                    else if(i == 0){
                        T[i][j].hori = T[i][j-1].hori + 1;
                        T[i][j].ver = 1;
                    }else if(j == 0){
                        T[i][j].ver = T[i-1][j].ver +1;
                        T[i][j].hori = 1;
                    }else{
                        T[i][j].hori = T[i][j-1].hori +1;
                        T[i][j].ver = T[i-1][j].ver + 1;
                    }
                }
            }
        }
        
        for(int i = 0; i < len; ++i) {
        	for(int j = 0; j < T[i].size(); ++j)
        		cout << "("<<T[i][j].ver << ","<< T[i][j].hori << ")	  ";
        	cout << endl;
        }
        //start iterating from bottom right corner and find min of hori or ver at every cell.
        //If this is greater than 1 then see if you can find a number between this min and 1
        //such that on left's ver and top's hori is greater greater than or equal to k.
         mx = 1;
        for(int i=T.size() -1; i >=0 ; i--){
            for(int j= T[0].size()-1 ; j >=0; j--){
                if(T[i][j].ver == 0 || T[i][j].ver == 1 || T[i][j].hori ==1 ){
                    continue;
                }
                int mn = min(T[i][j].ver, T[i][j].hori);
                int k = 0;
                for(k=mn; k > 1; k--){
                    if(T[i][j-k+1].ver >= k && T[i-k+1][j].hori >= k){
                        break;
                    }
                }
                if(mx < k){
                    mx = k;
                }
            }
        }
        
        return mx;

}

int main()
{
	VVC input = {{'X','O','O','O','O','O'},
                          {'O','O','O','O','O','O'},
                          {'X','X','X','X','O','O'},
                          {'X','X','X','X','X','O'},
                          {'X','O','O','X','X','O'},
                          {'X','O','X','X','X','O'}};
        
    VVC input1 = {{'O', 'O', 'O', 'O', 'O', 'X'},
                            {'O', 'X', 'O', 'X', 'X', 'X'},
                            {'O', 'X', 'O', 'X', 'O', 'X'},
                            {'O', 'X', 'X', 'X', 'X', 'X'},
                            {'O', 'O', 'O', 'O', 'O', 'O'},
        		};
        
    VVC input2 = {{'O', 'O', 'X', 'O', 'X'},
                            {'O', 'X', 'X', 'O', 'X'},
                            {'O', 'X', 'O', 'X', 'X'},
                            {'X', 'X', 'X', 'X', 'X'},
                            {'O', 'X', 'X', 'X', 'O'},
                           };

    int res = find_square(input);
    cout << "Size of Maximum Subsquare With Sides as X = " << res <<  endl;
   
    res = find_square(input1);
    cout << "Size of Maximum Subsquare With Sides as X = " <<  res <<  endl;

    res = find_square(input2);
    cout << "Size of Maximum Subsquare With Sides as X = " << res <<  endl;

return 0;
}
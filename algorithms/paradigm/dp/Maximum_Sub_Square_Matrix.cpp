#include "../../../common/headers.hpp"

 int maxSize(vector<vector<int> >&arr){
        int r = arr.size();
        int c = arr.size();

        int result[r][c]; 
        int max = 0;
        for(int i=0; i < r; i++){
            result[i][0] = arr[i][0];
            if (result[i][0] == 1)
            {
                max = 1;
            }
        }
        
        for(int i=0; i < c; i++){
            result[0][i] = arr[0][i];
            if (result[0][i] == 1)
            {
                max = 1;
            }
            
        }
        
        
        for(int i=1; i < r; i++){
            for(int j=1; j < c; j++){
                if(arr[i][j] == 0){
                    continue;
                }
                int t = min(result[i-1][j],min(result[i-1][j-1],result[i][j-1]));
                result[i][j] =  t +1;
                if(result[i][j] > max){
                    max = result[i][j];
                }
            }
        }
        return max;
    }
    


int main()
{
	vector<vector<int> >arr = {{0,1,1,0,1},{1,1,1,0,0},{1,1,1,1,0},{1,1,1,0,1}};
    int result = maxSize(arr);
    cout << "Max square size = " << result << endl;
	return 0;
}
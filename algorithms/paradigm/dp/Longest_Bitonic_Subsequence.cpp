#include "../../../common/headers.hpp"


int longestSequence(VI &arr){
		int len = arr.size();
        int lis[len] ;
        int lds[len] ;
        for(int i=0; i < len; i++){
            lis[i] = 1;
            lds[i] = 1;
        }
        for(int i=1 ; i < len; i++){
            for(int j=0; j < i ; j++){
                if(arr[i] > arr[j]){
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        for(int i = len-2; i >=0 ; i--){
            for(int j = len-1; j > i; j--){
                if(arr[i] > arr[j]){
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        int max = 0;
        for(int i=0; i < len; i++){
            if(max < lis[i] + lds[i]-1){
                max = lis[i] + lds[i] -1;
            }
        }
        return max;
    }
    
    int main(){
        VI arr = {1,4,3,7,2,1,8,11,13,0};
        int r = longestSequence(arr);
       	cout << r << endl;
    	return 0;
    }
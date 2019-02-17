#include "../../../common/headers.hpp"

int maxSum(vector<int>&arr){
        int len = arr.size();
        int T[len];

        for (int i = 0; i < len; i++) {
            T[i] = arr[i];
        }

        for(int i=1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    T[i] = max(T[i], T[j] + arr[i]);
                }
            }
        }

        int max = T[0];
        for (int i=1; i < len; i++){
            if(T[i] > max){
                max = T[i];
            }
        }
        return max;
}

int main()
{
	vector<int> arr = {1, 101, 10, 2, 3, 100,4};
    int r = maxSum(arr);
	cout << "Maximum Sum  = " << r << endl;
	return 0;
}
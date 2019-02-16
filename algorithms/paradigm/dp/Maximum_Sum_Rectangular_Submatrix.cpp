// #include "../../../common/headers.hpp"

#include <iostream>
using namespace std;
struct Result
{
	int max_sum;
	int st_row;
    int st_col;
    int ed_row;
    int ed_col;
    Result():max_sum(INT_MIN), st_row(0), st_col(0), ed_row(0), ed_col(0){}
};

Result kadane_result(int arr[], int len) {
	Result res;
	int tmp = 0;
	int st = 0;
	for(int i = 0; i < len; ++i) {
		tmp += arr[i];
		if(tmp > res.max_sum) {
			res.max_sum = tmp;
			res.ed_row = i;
			res.st_row = st;
		}
		if(tmp < 0) {
			tmp = 0;
			st = i+1;
		}
	}
	return res;
}
int main()
{

	// int mat[][5] = {{ 2,  1, -3, -4,  5},
 //                  { 0,  6,  3,  4,  1},
 //                  { 2, -2, -1,  4, -5},
 //                  {-3,  3,  1,  0,  3}};	

	// int mat[][5] = {{ 2,  1, -3, -4,  5},
 //                  { 0,  6,  3,  4,  1},
 //                  { 2, -2, -1,  -4, -5},
 //                  {-3,  3,  1,  0,  3}};	

	// int mat[][5] = {{ -2,  11, -3, -4,  -5},
 //                  { 0,  6,  3,  4,  -1},
 //                  { -2, 3, 1,  -4, -5},
 //                  {-3,  3,  1,  0,  -3}};	

  	// int mat[][5] = {{ -2,  11, -3, -4,  -5},
  	// 				{ 0,  6,  3,  4,  -1},
 		// 			{ -2, 3, 1,  1, -5},
 		// 			{-3,  3,  1,  0,  -3}};	
	int mat[][5] = {{ -3,  -11, -3, -4,  -5},
                  { -11,  -6,  -3, -4,  -11},
                  { -22, -3, -2,  -11, -5},
                  {-3,  -3,  -11,  -11,  -3}};	
	int rows = 4;
    int cols = 5;

    Result res;
    int arr[rows];

	int sc = 0;
    int ec = 0;
    
    while(sc < cols) {
    	for(int i = 0; i < rows; ++i) arr[i] = 0;
    	ec = sc;

    	while(ec < cols) {
    		for(int i = 0; i < rows; ++i) {
    			arr[i] += mat[i][ec];
    		}
    		Result tmp = kadane_result(arr, rows);
    		if(res.max_sum < tmp.max_sum) {
    			res = tmp;
    			res.st_col = sc;
    			res.ed_col = ec;
    		}
    		++ec;
    	}
    	++sc;
    }
    cout << "Max SubRectange sum = " << res.max_sum << endl;

    for(int i = res.st_row; i <= res.ed_row; ++i) {
    	for(int j = res.st_col; j <= res.ed_col; ++j) {
    		cout << mat[i][j] << " ";
    	}
    	cout << endl;
    }

	return 0;
}
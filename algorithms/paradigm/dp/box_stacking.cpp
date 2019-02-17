#include "../../../common/headers.hpp"

struct BLOCK {
	int h,w,d;
	BLOCK(int a , int b , int c) {
		h = a;
		w = b;
		d = c; 
	}
};
bool comp(const BLOCK& a , const BLOCK& b) {
	return ((b.d*b.w) < (a.d*a.w));
}
int main()
{
	int n;
	while(true) {
		scanf("%d", &n);
		if(n == 0)
			break;
		vector<BLOCK>block;
		int ind = 0;
		int arr[3];
		for(int i = 0; i < n; i++){ 
			scanf("%d%d%d", &arr[0],&arr[1],&arr[2]);
			sort(arr , arr+3);
			do{
				block.push_back(BLOCK(arr[0],arr[1],arr[2]));
			}while(next_permutation(arr , arr+3));
		}
		sort(block.begin() , block.end(), comp);
		ind = block.size();
		int msp[ind];
		for(int i = 0; i < ind; i++)
			msp[i] = block[i].h;

		for(int i = 1; i < ind; i++) {
			for(int j = 0; j < i; j++) {
				if(block[i].w < block[j].w && block[i].d < block[j].d && msp[i] < msp[j]+block[i].h)
					msp[i] = msp[j] + block[i].h;
			}
		}
		int maxh  =0;
		for(int i = 0; i < ind; i++)
			maxh = max(msp[i] , maxh);

		printf("%d\n", maxh);
	}
		
return 0;
}
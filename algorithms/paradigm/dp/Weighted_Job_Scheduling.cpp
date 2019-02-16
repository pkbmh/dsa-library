#include "../../../common/headers.hpp"


struct Job{
	int start;
	int end;
	int price;
};


int schedule_job(Job jobs[], int len) {
	sort(jobs, jobs+len, [](Job a, Job b) {return a.end <= b.end; });
	//for(int i = 0; i < len; ++i) cout << jobs[i].start << " " << jobs[i].end << endl;
	
	int dp[len];
	dp[0] = jobs[0].price;

	for(int i = 1; i < len; ++i) {
		dp[i] = max(jobs[i].price, dp[i-1]);
		int mx = 0;
		for(int j = i-1; j >= 0; --j) {
			if(jobs[j].end <= jobs[i].start){
				dp[i] = max(dp[i], dp[j]+jobs[i].price);
				break;
			}
		}

	}
	// for(int i : dp) cout << i << " ";
	// 	cout << endl;
	return *max_element(dp, dp+len);
}

int main()
{
	Job jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
	int len = sizeof(jobs) / sizeof(jobs[0]);

	int max_profit = schedule_job(jobs, len);
	assert(max_profit == 250);
	cout << "Max profit = " << max_profit << endl;


	Job jobs1[] = { {2,5,6}, {4,6,5}, {6,7,4},{1,3,5}, {5,8,11}, {7,9,2}};
	len = sizeof(jobs1) / sizeof(jobs1[0]);
	max_profit = schedule_job(jobs1, len);
	assert(max_profit == 17);
	cout << "Max profit = " << max_profit << endl;

	return 0;
}
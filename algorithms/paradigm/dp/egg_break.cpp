#include "../../../common/headers.hpp"


int egg_break(int egg, int floor,  vector<vector<int> >&dp) {
	if(egg == 1 || floor <= 1) return floor;
	if(dp[egg][floor] != -1) return dp[egg][floor];
	int ans = INT_MAX;
	for(int i = 1; i <= floor; ++i) {
		int eg_break = egg_break(egg-1, i-1, dp) + 1;
		int eg_notbreak = egg_break(egg, floor-i, dp) + 1;
		ans = min(ans, max(eg_break, eg_notbreak));
	}
	return dp[egg][floor] = ans;
}
int egg_break_dp(int egg, int floor) {
	int dp[egg+1][floor+1];
	for(int i = 0; i <= floor; ++i) dp[1][i] = i;

	for(int e = 2; e <= egg; e++){
        for(int f = 1; f <=floor; f++){
            dp[e][f] = INT_MAX;
             for(int k = 1; k <=f ; k++){
                int c =  max(dp[e-1][k-1], dp[e][f-k]) + 1;
                if(c < dp[e][f]){
                	dp[e][f] = c;
                }
             }
        }
    }
    return dp[egg][floor];
}
int main()
{
	int egg = 2;
	int floor = 10;
	vector<vector<int> >dp(egg+1, vector<int>(floor+1, -1));
	int trials = egg_break(egg, floor, dp);
	assert(trials == 4);
	//assert(trials == egg_break_dp(egg, floor));
	cout << "Trial need for (egg, floor)"<< "("<< egg << "," << floor << ") = "  <<  trials << endl;
	cout << "egg_break_dp(egg, floor)" << egg_break_dp(egg, floor) << endl;

	egg = 2;
	floor = 36;
	dp.clear();
	dp.resize(egg+1, vector<int>(floor+1, -1));
	trials = egg_break(egg, floor, dp);
	assert(trials == 8);
	//assert(trials == egg_break_dp(egg, floor));
	cout << "Trial need for (egg, floor)"<< "("<< egg << "," << floor << ") = "  <<  trials << endl;
	cout << "egg_break_dp(egg, floor)" << egg_break_dp(egg, floor) << endl;

	egg = 3;
	floor = 36;
	dp.clear();
	dp.resize(egg+1, vector<int>(floor+1, -1));
	trials = egg_break(egg, floor, dp);
	assert(trials == 6);
	assert(trials == egg_break_dp(egg, floor));
	cout << "Trial need for (egg, floor)"<< "("<< egg << "," << floor << ") = "  <<  trials << endl;
	cout << "egg_break_dp(egg, floor)" << egg_break_dp(egg, floor) << endl;


	egg = 4;
	floor = 65;
	dp.clear();
	dp.resize(egg+1, vector<int>(floor+1, -1));
	trials = egg_break(egg, floor, dp);
	assert(trials == 7);
	//assert(trials == egg_break_dp(egg, floor));
	cout << "Trial need for (egg, floor)"<< "("<< egg << "," << floor << ") = "  <<  trials << endl;
	cout << "egg_break_dp(egg, floor)" << egg_break_dp(egg, floor) << endl;

	return 0;
}
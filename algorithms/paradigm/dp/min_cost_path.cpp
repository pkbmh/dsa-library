#include "../../../common/headers.hpp"


int min_path_cost(vector<vector<int> >&mat) {
	int r = mat.size();
	int c = mat[0].size();
	int tmp[r][c];
	tmp[0][0] = mat[0][0];
	for(int i = 1; i < c; ++i) tmp[0][i] = tmp[0][i-1] + mat[0][i];
	for(int i = 1; i < r; ++i) tmp[i][0] = tmp[i-1][0] + mat[i][0];

	for(int i = 1; i < r; ++i)
		for(int j = 1; j < c; ++j)
			tmp[i][j] = min(tmp[i][j-1], tmp[i-1][j]) + mat[i][j];

	return tmp[r-1][c-1];
}
int main()
{

	vector<vector<int> > cell_cost = {{1,3,5,8},{4,2,1,7},{4,3,2,3}};
	//vector<vector<int> > cell_cost = {{1,2,3},{4,8,2},{1,5,3},{6,2,9}};

	int path_cost  = min_path_cost(cell_cost);
	cout << "Min path cost is = "<< path_cost << endl;

return 0;
}
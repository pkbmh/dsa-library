#include "../../../common/headers.hpp"

class MatrixSumQuery {
private: 
	VVI sum_mat;
	int rows;
	void build(VVI &mat) {
		this->rows = mat.size();
		sum_mat.resize(rows+1, vector<int>(rows+1, 0));

		for(int i = 1; i <= rows; ++i)
			for(int j = 1; j < sum_mat[i].size(); ++j)
				sum_mat[i][j] = mat[i-1][j-1] + sum_mat[i][j-1] + sum_mat[i-1][j] - sum_mat[i-1][j-1];
	}

public:
	MatrixSumQuery(VVI &mat) {
		build(mat);
	}
	
	int sumQuery(pair<int,int> top, pair<int,int>bottom) {
		++top.F; ++top.S; ++bottom.F; ++bottom.S;
		return sum_mat[bottom.F][bottom.S] - sum_mat[top.F - 1][bottom.S] - sum_mat[bottom.F][top.F - 1] + sum_mat[top.F- 1][top.S - 1];
	}
};

int main(){

	VVI mat = {{3, 0, 1, 4, 2},
              	{5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}};
     VVI mat1 = {{2,0,-3,4}, 
     			{6, 3, 2, -1}, 
     			{5, 4, 7, 3}, 
     			{2, -6, 8, 1}};

    MatrixSumQuery matrixSumQuery(mat);
    MatrixSumQuery matrixSumQuery1(mat1);
    

    cout << matrixSumQuery.sumQuery({1, 1}, {2, 2}) << endl;
    cout << matrixSumQuery1.sumQuery({1, 1}, {2, 2}) << endl;

return 0;
}
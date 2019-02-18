#include "../../../common/headers.hpp"


int main()
{

	VI arr = {4,1,1,4,2,1};
	int in = arr[0];
	int ex = 0;
	int res = max(in ,ex);
	for(int i = 1; i < arr.size(); ++i) {
		int tmp = in;
		in = max(ex + arr[i], in);
		ex = tmp;
	}

	cout << in << endl;

return 0;
}
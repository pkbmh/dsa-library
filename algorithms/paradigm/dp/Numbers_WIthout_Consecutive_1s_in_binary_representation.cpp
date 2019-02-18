#include "../../../common/headers.hpp"


int count_numbers(int len) {
	int a = 1;
	int b = 1;

	for(int i = 1; i < len; ++i) {
		int tmp = b;
		b = a+b;
		a = tmp;
	}

	return a+b;
}
int main()
{
	int len = 3;

	cout << "Totol numbers = " << count_numbers(len) << endl;
return 0;
}
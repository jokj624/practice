#include <iostream>
#include <string>
using namespace std;

int ans, n;

bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return false;
	return true;
}

void find(int num) {
	if (!is_prime(num))
		return;
	if (to_string(num).length() == n) {
		printf("%d\n", num);
	}
	num *= 10;
	find(num + 1);
	find(num + 3);
	find(num + 5);
	find(num + 7);
	find(num + 9);
}

int main() {
	scanf("%d", &n);
	find(2); find(3); find(5); find(7);
	return 0;
}

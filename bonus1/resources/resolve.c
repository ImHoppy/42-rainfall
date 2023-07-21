#include <limits.h>
int main() {
	printf("value = %d\n", INT_MIN+(44/4));
	printf("unsigned = %u\n", (INT_MIN+(44/4))*4);
	return 0;
}

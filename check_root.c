#include <stdio.h>
#include <unistd.h>


int main() {
	int rv = seteuid(0);
	if (rv == -1) {
		printf("Try running as root!\n");
	} else {
		printf("You have root permissions.\n");
	}
	printf("Effective UID: %d\n", geteuid());
}

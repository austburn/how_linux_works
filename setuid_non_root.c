#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int run_as_uid = 0;

	if (argc == 2) {
		run_as_uid = atoi(argv[1]);
	}

	uid_t uid = getuid();
	uid_t euid = geteuid();
	seteuid(run_as_uid);
	if (uid == 0) {
		printf("You have root permissions.\n");
	} else {
		printf("You do not have root permissions. Exiting.\n");
		return -1;
	}
	printf("UID: %d, EUID: %d\n", uid, euid);

	int fd = open("root_read_only", O_RDONLY);
	printf("The file descriptor is: %d\n", fd);
	if (fd < 0) {
		printf("There was a problem opening the file. Exiting.\n");
		return -1;
	}
	char buf[16];
	size_t nbytes = sizeof(buf);
	ssize_t bytes_read = read(fd, buf, nbytes);

	printf("I read %d bytes and got: %s\n", (int)bytes_read, buf);
}


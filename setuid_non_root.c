#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	uid_t uid = getuid();
	uid_t euid = geteuid();
	if (uid == 0) {
		printf("You have root permissions.\n");
	} else {
		printf("You do not have root permissions\n");
	}
	printf("UID: %d, EUID: %d\n", uid, euid);
	int fd = open("root_read_only", O_RDONLY);
	printf("The file descriptor is: %d\n", fd);
	char buf[16];
	size_t nbytes = sizeof(buf);
	ssize_t bytes_read = read(fd, buf, nbytes);
	printf("I read %d bytes and got: %s\n", bytes_read, buf);
}


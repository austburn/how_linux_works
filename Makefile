init:
	echo "test" > root_read_only
	chown root:root root_read_only
	chmod 0400 root_read_only
	       	

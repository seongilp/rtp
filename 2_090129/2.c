// Polling method
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int term_desc, result;
	int count = 0;
	char c;
	term_desc = open("/dev/tty",O_RDONLY | O_NONBLOCK);
	while(1) {
		write(1,"1",1);
		result = read(term_desc, &c, 1);
		if(c == 'q')
			break;
		if(result == 1)
			count++;
		else {
			continue;
		}
	}
	printf("\n You pressed key %d times..!\n",count);
	return 0;
}

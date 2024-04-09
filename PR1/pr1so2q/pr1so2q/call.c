#include <stdlib.h>

#define WAIT (1<<15)

void proc()
{
	int loop=WAIT;

	while (loop--);

	proc();
}

int main(int argc, char *argv[])
{
	proc();
	
	exit(0);
}

#include <stdio.h>
#include <stdlib.h>

struct pkt{
	char ch1;
	char ch2[2];
	char ch3;
};

int main(int argc, char *argv[])
 {

	int number = atoi(argv[1]), generated_number;
	struct pkt pkt;
	pkt.ch1 = number&0xff;
	pkt.ch2[0] = (number>>8)&0xff;
	pkt.ch2[1] = (number>>16)&0xff;
	pkt.ch3 = (number>>24)&0xff;	
	printf("1st Member of the structure : %d\n" "2nd Member of the structure : %d, %d\n" "3rd Member of the structure : %d\n",
	pkt.ch1, pkt.ch2[0], pkt.ch2[1], pkt.ch3); 

	generated_number = (pkt.ch3<<24) | (pkt.ch2[1]<<16) | (pkt.ch2[0]<<8) | (pkt.ch1);
	printf("The regenerated number : %d\n", generated_number);
	return 0;
}

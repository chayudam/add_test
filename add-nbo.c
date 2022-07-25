# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <arpa/inet.h>
int main(int argc, char **argv )
{
	FILE *five;
	FILE *thou;
	uint32_t thou1, five1;
	thou=fopen(argv[1],"rb");
	five=fopen(argv[2],"rb");
	fread(&thou1, sizeof(int)*4, 1, thou);
	fread(&five1, sizeof(int)*4, 1, five);
	thou1=htonl(thou1);
	five1=htonl(five1);
	uint32_t value=0;
	value=thou1+five1;
	int thou2;

	printf("%u(%#x) + %u(%#x) = %u(%#x) \n",thou1, thou1, five1, five1, value, value);

	fclose(five);
	fclose(thou);

	return 0;	
}


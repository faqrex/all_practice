#ifdef DEBUG
#pragma message "Debug Opened"
#endif

#define _STR(var) #var

#ifdef DEBUG

#define PRINT_STR(var) printf("string "#var" =%s\n",var);
#define PRINT_INT(var) printf("int "#var" =%d\n",var);

#else 

#define PRINT_STR(var) 
#define PRINT_INT(var) 

#endif


#if DEBUG
static void dump_addr(char* addr, int sz,char* banner)
{
#define MAX_COLUMN 4
	printf(">>>>----%s----\n",banner);
	int column;
	int line; 
	int i;
	int bol;
	line  = 0;
	column = 0;
	bol = 1;

	for (i =0 ; i< sz ; i++) {
		if (0 == column) {
			printf("line %04d:",line);
			bol = 0;
		}

		if (column < MAX_COLUMN -1) {
			/* printf("%02x  ",addr[i]); */
			printf("%2d ",addr[i]);
			column++;
		} else { /*MAX_COLUMN-1*/
			printf("%2d\n",addr[i]);
			column = 0;
			bol = 1;
		}
	}
	if (!bol) putchar('\n');
	printf("<<<<<<<<<<<<\n");
}
#else
#define dump_addr(...)
#endif

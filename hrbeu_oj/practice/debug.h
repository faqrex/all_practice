#include <stdio.h>
#pragma message "Debug Opened"

#define _STR(var) #var

#define PRINT_STR(var) printf("<%s:%d>string "#var" =%s\n",__FUNCTION__,__LINE__,var);
#define PRINT_INT(var) printf("<%s:%d>int "#var" =%d\n",__FUNCTION__,__LINE__,var);

static void dump_addr(char* addr, int sz,char* banner)
{
#define MAX_COLUMN 8
	printf(">>>>>>>>--%s--\n",banner);
	int column;
	int line; 
	int i;
	int bol;
	line  = 0;
	column = 0;
	bol = 1;//Begin Of Line

	for (i =0 ; i< sz ; i++) {
		if (0 == column) {
			printf("<base+%04d>:",line);
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
			line++;
		}
	}
	if (!bol) putchar('\n');
	printf("<<<<<<<<<<<<\n");
}

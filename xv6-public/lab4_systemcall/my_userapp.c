#include "types.h"
#include "stat.h"
#include "user.h"

int
main (int argc, char* argv[]){
	if(argc<=1)
	{
		exit();
	}

	if(strcmp(argv[1],"2019074120_12299_ParkSeonWook")!=0)
	{
		exit();
	}

	char *buf="2019074120_12299_ParkSeonWook";
	int ret_val;
	ret_val=myfunction(buf);
	printf(1,"Return value : 0x%x\n", ret_val);
	exit();
};

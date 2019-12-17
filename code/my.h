#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <pthread.h>
#include <limits.h>
#include <assert.h>
#define check_error(return_val,msg){\
			if(return_val!=0){\
				fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
			}\
		}

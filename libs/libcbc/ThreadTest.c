//Ref https://computing.llnl.gov/tutorials/pthreads/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

//Function prototypes


void* PrintHello(void* threadid);


int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void*)t);
		if (rc)	 
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

   /* Last thing that main() should do */
   pthread_exit(NULL);
}


void* PrintHello(void* threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
	
	unsigned long counter = 0;
	unsigned long outerCounter = 0;
	while(outerCounter < 10000)
	{
		
		if(counter < 100000)
		{
			counter++;
		}
		else
		{
			counter = 0;
			outerCounter++;
		}
	}
	
	printf("thread #%ld signing off-Goodbye\n", tid);
	
    pthread_exit(NULL);
}

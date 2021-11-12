#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>


static void catcher (int sig) {
	//sigint is ctrl+c (stop current process)
	// sigusr1 is a user defined signal
	
	
    if (sig == SIGINT) {
		// to make a .txt file 
        int note = open("message.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
        if (note==-1) {
            printf("error found! %s\n", strerror(errno));
            return;
        }
		
		
        char message[1000] = "The program exited due to SIGINT\n";
		// to write the message into the .txt file
        int error = write(note, message, sizeof(message));
        if (error ==-1) {
            printf("error found!  %s\n", strerror(errno));
            return;
        }
        exit(0);
    }

    //  print out the ppid 
    if (sig == SIGUSR1) {
        printf(" PPID is %d\n", getppid());
    }
}

int main () {
	// appends message to file 
    signal(SIGINT, catcher);
	// prints out the PID of parent process
    signal(SIGUSR1, catcher);
    // any numebr other than -1 is true
	while(17) {
        printf(" PID is %d\n", getpid());
		// to wait 1 second between printing
        sleep(1);
    }
    return 0;
}
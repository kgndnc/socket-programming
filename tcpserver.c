#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "3490" // the port client will be connecting to


int main(int argc, char* argv[]) {


	// get address info
	
	struct addrinfo hints = {0};
	struct addrinfo *res, *temp_addrinfo;
	int ecode;

	// hints.ai_family = AF_INET; // ipV4
	hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
	hints.ai_flags = AI_PASSIVE; // fill in my IP for me

	 if((ecode = getaddrinfo(NULL, "3490", &hints, &res)) != 0 ) {
	 	fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ecode));
	 	return EXIT_FAILURE;
	 }

	printf("If you're here, everything's fine\n");


	int i;

	for (temp_addrinfo = res, i =0; temp_addrinfo->ai_next != NULL; temp_addrinfo = temp_addrinfo->ai_next, i++) {
		printf("Info 1: %d\n", temp_addrinfo->ai_family);
		printf("Loop number: %d\n", i);
	}

	// create socket
	// bind it to some port
	// listen for incoming connections
	// accept and create a new socket for that incoming connection


	return 0;
}

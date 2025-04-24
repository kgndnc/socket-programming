#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

// AF = Address family
// PF = Protocol family

int main(int argc, char *argv[]) {

	struct addrinfo hints, *res, *p;
	int sockfd;
	
	// first, load up address structs with getaddrinfo():


	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me
	
	/*
	By using the AI_PASSIVE flag, I’m telling the program to bind to the IP of the host it’s running on. If you want to bind to a specific local IP address, drop the AI_PASSIVE and put an IP address in for the first argument to getaddrinfo().
	*/

	// do the lookup
	getaddrinfo("www.google.com", "80", &hints, &res);
	
	// make a socket	
	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	
	// bind it to the port we passed in to getaddrinfo()
	
//	int b = bind(sockfd, res->ai_addr, res->ai_addrlen);
/*
Also, notice that we didn’t call bind(). Basically, we don’t care about our local port number; we only care where we’re going (the remote port). The kernel will choose a local port for us, and the site we connect to will automatically get this information from us. No worries.
*/
	
	printf("socket descriptor: %d\n", sockfd);

	int c = connect(sockfd, res->ai_addr, res->ai_addrlen);
	printf("connect returned %d\n", c);
	

	freeaddrinfo(res); // free the linked list

	return 0;
}


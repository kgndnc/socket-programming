#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int status;
    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr,"usage: showip hostname\n");
        return 1;
    }

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
    // hints.ai_flags = AI_PASSIVE; // fill in my IP for me

    if ( (status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0 ) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);


    // ... do everything until you don't need servinfo anymore ....
    p = res;
    do {
        void *addr;
        char *ipver;

        // get the pointer to the address itself
        // different fields in IPv4 and IPv6
        if (p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }


        // convert the IP to a string and print it:
        // network-to-presentation
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s: %s\n", ipver, ipstr);


        p = p->ai_next;
    } while ( p != NULL && p->ai_next != NULL);

    freeaddrinfo(res); // free the linked-list

    return 0;
}


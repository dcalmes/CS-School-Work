

///////////////////////////////////////////////////////
//To Compile: gcc -o client client.c -lnsl -lsocket
//To Run: ./client ServerName PortNumber
//         eg., ./client bgunix 45656
//Programmer: Douglas G Calmes
///////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

////////////////////////////////////////
// This is the same function as in
// the server.
////////////////////////////////////////
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr; // serv_addr - Address of the server we want to connect to
    struct hostent *server;	  // pointer to the hostent structure	

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr, "usage %s hostname port\n", argv[0]);
       exit(0);
    }

	// This is the same lines of code from the server!
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket\n");
	// End of the same code!

	// Set the server to the host on the Internet.
	// If it returns NULL: Tell user they cannon find the host
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

	// Set the fields in serv_addr
	//	The majority of the fields will be the same as the server.
	// Use bcopy() because server->h_addr is a character string.
	//	This will copy the length bytes from s1 to s2.
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    serv_addr.sin_port = htons(portno);

	// connect() is called by the client in order to connect to the server.
	// 	Arguements in connect():	socket file descriptor
	//					address of the host (connection)
	//					size of the address
	// If the connect() succeedes it will return 0.  If not it will
	// return -1 and print out that it had an error connecting.
    if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting\n");

	// Have the user enter a message.
    printf("Please enter the message: ");
    bzero(buffer, 256);

	// Read the message from stdin.
    fgets(buffer, 255, stdin);
	
	// Read the reply from the socket and display it on the screen.
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket\n");
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) 
         error("ERROR reading from socket\n");
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}

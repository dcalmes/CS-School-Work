///////////////////////////////////////////////////////////////////
// To Comiple: gcc -o server server.c -lsocket
// To Run: ./server PortNumber
//         (Portnumber can be any number between 2000 and 65535)
//         e.g., ./server 45656
//
// Programmer: Douglas G Calmes
///////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

/////////////////////////////////////////////
// This function will be called if the 
// system ends up failing.  It will display
// display an error message then abort
// the program.
/////////////////////////////////////////////

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
	////////////////////////////////////////////////////
    	// Variables:
	//	stockfd & newsockfd - file descriptors
	//	portno - stores the port number
	//	clilen - size of the address of the client
	//	n - return value for read() & write()
	////////////////////////////////////////////////////
	
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];	// Buffer that contains characters from the socket connection
     struct sockaddr_in serv_addr, cli_addr;
     int n;

	// Print an error if there are less than two arguments
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

	// set sockfd and print an error if it is less than 0
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");

	// Use two arguments, pointer to the buffer and size of the buffer
	// to set all of the values in the buffer to 0. aka. initialize
     bzero((char *) &serv_addr, sizeof(serv_addr));

	// Convert the string of digits into an integer
     portno = atoi(argv[1]);

	// Set sin_family to AF_INET
     serv_addr.sin_family = AF_INET;
	
	// Contains the IP address of the host.
	// This will always be the IP address, so we set it to INADDR_ANY to get
	// this address.
     serv_addr.sin_addr.s_addr = INADDR_ANY;

	// sin_port contains the port number.
	// Uses htons() to convert a port number from host byte order to network byter order.
     serv_addr.sin_port = htons(portno);

	// Report an error if these are less than 0.
	//	The most common failure is when the socket
	//	is already being used on this machine.
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
         error("ERROR on binding");

	// This call will allow the process to listen on the socket for connections.
	//	It contains two arguments: socket file descriptor & size of backlog queue.
	//		The size of the backlog should be set to the maximum size.
	//		If the first argument is valid, it wont fail or check for errors.
     listen(sockfd,5);

	// We first set clilen to the size of cli_addr.
	// accept() system call is what causes the process to block.  This will block until
	// a client is connected to the server.
	//	Once connected, the process will be woken up.
	// This call will return a new file descriptor.
	//	All communication on this connection will now use this new file descriptor.
	// The other two arguments are a reference pointer to the address of the client on
	// the other end of the connection & the size of the structure.
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                        (struct sockaddr *) &cli_addr, 
                        &clilen);
     if (newsockfd < 0) 
          error("ERROR: on accept");

	// This next step will happen once the client has connected to our server.
	// The buffer will then be initialized using the bzero() function.
	// It will then read from the socket.
	// The updated file descriptor will be used here.
	// read() will block until something for it to read shows up.
	// 	It will continue to read until 255, or until it reads the total
	//	number of characters in the socket.
	//	It will then return the number of characters that were read.
     bzero(buffer,256);
     n = read(newsockfd, buffer, 255);
     if (n < 0) 
        error("ERROR: reading from socket");
     printf("Here is the message: %s\n", buffer);

	// Write a message to the client of everything written by the server
     n = write(newsockfd,"Message received!", 18);
     if (n < 0) 
        error("ERROR: writing to socket");
     close(newsockfd);
     close(sockfd);

     return 0; 
}

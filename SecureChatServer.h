#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <openssl/evp.h>
#include <vector>
#include "User.h"

class SecureChatServer{
    private:
        //Server private key
        static EVP_PKEY* server_prvkey;

        //Server certificate
        static X509* server_certificate;

        //Port and listening IP address, in dotted notation (e.g. 192.168.1.1)
        char address[MAX_ADDRESS_SIZE];
        unsigned short int port;
        int listening_socket;
        struct sockaddr_in server_addr;

        //Get the server private key
        static EVP_PKEY* getPrvKey();

        //Get the specified user private key
        static EVP_PKEY* getUserKey(string username);

        //Get the server certificate
        static X509* getCertificate();

        //List of users
        static map<string, User> *users;

        //Setup the socket
        void setupSocket();

        //Let the main process listen to client requests
        void listenRequests();

        //Send the certificate to a client
        void sendCertificate(int process_socket);

        //Receive authentication from user
        string receiveAuthentication(int process_socket, unsigned int &status);

        void handleConnection(int data_socket, sockaddr_in client_address);

        //Change user status
        void changeUserStatus(string username, unsigned int status, int socket);

        void printUserList();

        //Send the list of available users
        void sendAvailableUsers(int data_socket, string username);

        vector<User> getOnlineUsers();

        //Receive Request To Talk
        string receiveRTT(int data_socket, string username);

        //Forward a RTT to the final receiver
        void forwardRTT(string receiver_username, string sender_username);

        //Receive response to RTT
        unsigned int receiveResponse(string receiver_username);

        //Forward response to RTT
        void forwardResponse(int data_socket, unsigned int response);

        //Send user public key to the users that want to communicate
        void sendUserPubKey(string receiver_username, string sender_username);

        //Receive a logout message
        void checkLogout(int data_socket, char* msg, unsigned int buffer_len, unsigned int auth_required, string username);

    public:
        //Constructor that gets as inputs the address, the port and the user filename.
        SecureChatServer(const char* addr, unsigned short int port, const char *user_filename);
};
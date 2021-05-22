#include <string>
#include "Utility.h"

const unsigned int USERNAME_MAX_SIZE = 16;
const unsigned int MAX_ADDRESS_SIZE = 16;
const unsigned int MAX_USERS_TO_SEND = 64;

const unsigned int BUFFER_SIZE = 1024;
const unsigned int CERTIFICATE_MAX_SIZE = 2048;
const unsigned int DIGEST_SIZE = EVP_MD_size(EVP_sha256());
const unsigned int SIGNATURE_SIZE = 256;
const unsigned int AUTHENTICATION_MAX_SIZE = USERNAME_MAX_SIZE + 3 + SIGNATURE_SIZE;
const unsigned int MAX_AVAILABLE_USER_MESSAGE = 10;
const unsigned int AVAILABLE_USER_MAX_SIZE = 2 + MAX_AVAILABLE_USER_MESSAGE*(USERNAME_MAX_SIZE+2) + SIGNATURE_SIZE;
const unsigned int RTT_MAX_SIZE = 3 + USERNAME_MAX_SIZE + SIGNATURE_SIZE;

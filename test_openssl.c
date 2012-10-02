#include <stdio.h>
#include <openssl/evp.h>
int main()
{
     OpenSSL_add_all_algorithms();
     printf( "Successful!\n" );
     return 0;
}

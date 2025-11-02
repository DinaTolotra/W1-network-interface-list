## Name
inet_ntop - convert IPv4 and IPv6 addresses from binary to text form
## Synopsis
```C
#include <arpa/inet.h>

const char *inet_ntop(int af, const void *restrict src,
                        char dst[restrict .size], socklen_t size);
```
## Description
 - The function `inet_ntop` convert a network address stored at `src` of family `af` to a valie pointer `dst` with `size` bytes avalaible.  
 - `src` type are generally `in_addr` or `in6_addr`.  
 - `af` value are generally `AF_INET` or `AF_INET6`.  
 - `size` value are generally `INET_ADDRSTRLEN` or `INET6_ADDRSTRLEN`.  

## Return value
On success, `inet_ntop()` returns a non-null pointer to `dst`. `NULL` is returned if there was an error.

## Example
```C
...
#include <arpa/inet.h>

int main(void) {
    char p_addr[INET6_ADDRSTRLEN];      // INET6_ADDRSTRLEN is greater than INET_ADDRSTRLEN
    struct ifaddrs *interface;
    ...
    struct sockaddr *s_addr;
    int family;

    getifaddrs(...);
    ...
    while (interface) {
        s_addr = interface->ifa_addr;
        family = s_addr->sa_family;
        // Convert the socket addres to IPv4 or IPv6 socket addres
        // get the address of the socket and pass to the function it's memory address
        if (family == AF_INET) {
            inet_ntop(
                family,
                &(((struct sockaddr_in*)s_addr)->sin_addr),
                p_addr,
                INET_ADDRSTRLEN
            );
        } else if (family == AF_INET6) {
            inet_ntop(
                family,
                &(((struct sockaddr_in6*)s_addr)->sin6_addr),
                p_addr,
                INET6_ADDRSTRLEN
            );
        }
        /* do something with p_addr */
        interface = interface->ifa_next;
    }
    return 0;
}
```
## Reference
 - man inet_pton(3)
 - man inet_ntop(3)
 - getifaddrs.md

## Acronym
 - `inet_ntop`: internet, number to printable
 - `af`: address family  
 - ...

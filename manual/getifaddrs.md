## Name
getifaddrs, freeifaddrs, ifaddrs - get interface addresses

## Synopsis
```C
#include <sys/types.h>
#include <ifaddrs.h>

int getifaddrs(struct ifaddrs **ifap);
void freeifaddrs(struct ifaddrs *ifa);

struct ifaddrs {
    struct ifaddrs  *ifa_next;      /* Next item in list */
    char            *ifa_name;      /* Name of interface */
    unsigned int    ifa_flags;      /* Flags from SIOCGIFFLAGS */
    struct sockaddr *ifa_addr;      /* Address of interface */
    struct sockaddr *ifa_netmask;   /* Netmask of interface */
    union {
        struct sockaddr *ifu_broadaddr; /* Broadcast address of interface */
        struct sockaddr *ifu_dstaddr;   /* Point-to-point destination address */
    } ifa_ifu;
#define ifa_broadaddr   ifa_ifu.ifu_broadaddr
#define ifa_dstaddr     ifa_ifu.ifu_dstaddr
    void            *ifa_data;      /* Address-specific data */
};
```

## Description
 - The function `getifaddrs()` create a linked list of type `struct ifaddrs` and override the value of `ifap` by it's value(first node).  
 - For the function `freeifaddrs()` get a valid linked list of type `struct ifaddrs` and free each element of this linked list strating at `ifa`.  
 - The `struct ifaddrs` structure are meant to be a linked list due to the element `struct *ifa_next` who point to an another `struct ifaddrs`.  

## Return value
On success, `getifaddrs()` returns `0`; on error, `-1` is returned.

## Example
```C
#include <sys/types.h>
#include <ifaddrs.h>

int main(void) {
    struct ifaddrs *interface_list;
    struct ifaddrs *interface;
    int ret;

    interface = 0;                          // 0 as default value
    ret = getifaddrs(&interface_list);

    if (ret == 0) {
        interface = interface_list;         // Conserve the inital element to interface_list
    }
    while (interface) {                     // Check if interface is not null
        /* Do action with interface */
        interface = interface->ifa_next;    // Go to next element
    }
    if (ret == 0) {
        freeifaddrs(interface_list);        // Free the linked list if it existe
    }
    return 0;
}
```

## Reference
 - man getifaddrs(3)

## Acronym
 - `getifaddrs`: get interface address
 - `freeifaddrs`: free interface address
 - `ifa`: interface address
 - `ifap`: interface address pointer

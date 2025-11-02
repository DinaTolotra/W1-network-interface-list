# UNIX BASED SYSTEM INTERFACE ADDRESS
## Description
Program to list network interfaces and their ip address on a unix based system.
## Dependencies
### Program
 - ifaddrs.h: for getifaddrs() and freeifaddrs(); (man getifaddrs(3))
 - arpa/inet.h: for inet_ntop(); (man inet_ntop(3), man inet_pton(3))
 - unistd.h: for write(); (man write(2))
All of this dependencies are part of C standard lib.
### Build
 - make
 - gcc: for compilation
 - ar: from binutils for static lib creation
## Usage
```bash
make build/ip  
./build/ip  
```
### Reference
 - (book)   Hands-on network programming with C - by Lewis Van Winkle
 - (manual) man getifaddrs(3)
 - (manual) man freeifaddrs(3)
 - (manual) man inet_ntop(3)
 - (manual) man write(2)
 - (doc) [getifaddrs.md](./manual/getifaddrs.md)
 - (doc) [freeifaddrs.md](./manual/getifaddrs.md)
 - (doc) [inet_ntop.md](./manual/inet_ntop.md)
 - (doc) [write.md](./manual/write.md)

## Name
write - write to a file descriptor
## Synopsis
```C
#include <unistd.h>

ssize_t write(int fd, const void buf[.count], size_t count);
```
## Description
`write()` write up to `count` bytes from buffer starting at `buf` to the file referred by the file descriptor `fd`.  
`size_t` is used for a count of bytes. It's value range are [0, SIZE_MAX] (man size_t(3type)).  
`ssize_t` is used for a count of bytes or an error indication. It's value range are [-1, SSIZE_MAX]. -1 is for error indication (man ssize_t(3type)).  
`size_t` and `ssize_t` are defined in several headers, likely `aio.h` or `unistd.h`.  

## Return value
On success, the count of bytes written is returned. On error, -1 is returned.

## Example
```C
#include <unistd.h>

int main(void) {
    write(STDOUT_FILENO, "Hello world", 11);
    return 0;
}
```
`STDOUT_FILENO` is a system-defined file descriptor alongside with `STDIN_FILENO` and `STDERR_FILENO`.  
`"Hello world"` create a string in memory and return the pointer pointing to the first character of the string.  
`11` is the number of character to print.

## Reference
 - man write(2)
 - man size_t(3type)
 - man ssize_t(3type)

## Acronym
 - `fd`: file descriptor
 - `aio`: asynchronous input/output
 - `unistd`: unix standard (?)

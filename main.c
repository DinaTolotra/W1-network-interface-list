#include <ifaddrs.h>
#include <arpa/inet.h>

#include "io.h"

int is_ipv4(struct ifaddrs *interface);
int is_ipv6(struct ifaddrs *interface);
void print_if_name(struct ifaddrs *interface);
void print_addr(const struct sockaddr *addr);

int main() {
	struct ifaddrs *if_list;
	struct ifaddrs *interface;
	int ret;

	ret = getifaddrs(&if_list);
	if (ret == -1) {
		io_put_str("[ERROR] failed to get interface information\n");
	} else {
		interface = if_list;
		while (interface) {
			io_put_str("INTERFACE: ");
			print_if_name(interface);
			if (is_ipv4(interface) || is_ipv6(interface)) {
				io_put_str("\n\t");
				print_addr(interface->ifa_addr);
			}
			io_put_char('\n');
			interface = interface->ifa_next;
		}
		freeifaddrs(if_list);
	}
	return 0;
}

int is_ipv4(struct ifaddrs *interface) {
	return interface->ifa_addr->sa_family == AF_INET;
}

int is_ipv6(struct ifaddrs *interface) {
	return interface->ifa_addr->sa_family == AF_INET6;
}

void print_if_name(struct ifaddrs *interface) {
	io_put_str(interface->ifa_name);
}

void print_addr(const struct sockaddr *addr) {
	char str_addr[64];

	if (addr->sa_family == AF_INET) {
		inet_ntop(addr->sa_family, &((struct sockaddr_in*)addr)->sin_addr, str_addr, INET_ADDRSTRLEN);
	} else if (addr->sa_family == AF_INET6) {
		inet_ntop(addr->sa_family, &((struct sockaddr_in6*)addr)->sin6_addr, str_addr, INET6_ADDRSTRLEN);
	}
	io_put_str(str_addr);
}

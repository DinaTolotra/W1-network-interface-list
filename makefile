build/ip: build/libio.a main.c
	@gcc -Wextra -Wall -Werror -o $@ -g main.c -Iinclude -Lbuild -lio

build/libio.a: build/object/libio.o
	@ar -rcs $@ $^

build/object/libio.o: build/object source/io.c
	@gcc -Wextra -Wall -Werror -o $@ -c source/io.c -Iinclude

build/object: build
	@mkdir -p build/object

build:
	@mkdir -p build

clean:
	@rm -r build

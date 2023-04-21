# "systemd-ioofd"
###### _System-Daemon---Indexed-outside-of-Filesystem-Daemon_

- _A system-daemon for the Linux system._
- _Being developed as an idea for a dynamic file-directory._

Between a server and its nodes, the daemon checks to see if the compressed files received are valid, verifying its integrity.

The general idea is to enable the user to have a portable daemon which can be dropped in and dropped out like a node.

This was an idea I had for a virtual filesystem in Kernel Virtual Machine (KVM).
In this way we can have a programmatic-process which can monitor and defend files within a dynamic directory.

I also will try in the future to have this idea work with interopting with any C-binding package.
    I would have also used Google's 'protobuf' or Apache's 'Arrow', but these cross-language development platforms have undesirable licensings.

I want this project to stick between the lines of 'zlib' and 'MIT' licensing.

###### _You mainly want to make the binary with:_
_i.e_ `make systemd_ioofd`

Make commands are compiled...
_...with these Makefile commands:_
```Makefile
systemd_ioofd: src/main.c $(EXT_FILES)
	gcc src/main.c -o out/systemd_ioofd.o

dynamic_library: systemd_ioofd.o
	gcc systemd_ioofd.o -o systemd_ioofd

dc_toolchain_conan: 
	cd build
	cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	cmake --build .
```
`source main` or `source systemd_ioofd`
`. main` or `. systemd_ioofd`
...would be the general commands to execute the binary.
# "systemd-oofsd"
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

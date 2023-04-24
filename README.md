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
<<<<<<< Updated upstream
=======

###### _Emulate the host "x86" guest OS from the buildroot:_

_First download QEMU from the mirror repository:_

```Bash
git clone https://github.com/qemu/qemu.git
cd qemu
```

###### _Configure the local target: "i386 Soft MMU"_ for QEMU:

```Bash
./configure --target-list=i386-softmmu
make
```

###### _Further configure the local target: i440fx PC (pc-i440fx, pc):_

_Make sure to confiure your Window Sound System product with the CS4231A chip_
`The PC speaker audio device can be configured using the pcspk-audiodev machine property, i.e.`
`Further note that, by default, GUS shares IRQ(7) with parallel ports and so QEMU must be told to not have parallel ports to have working GUS.`

```bash
qemu-system-x86_64 some.img -audiodev <backend>,id=<name> -machine pcspk-audiodev=<name>
```

_Remember, qemu64 is used for x86_64 guests and qemu32 is used for i686 guests, when no -cpu argument is given to QEMU, or no <cpu> is provided in libvirt XML. So configure with:_

```bash
qemu-system-x86_64 -cpu host
```

_"Libvirt" guest XML will then be:_

```xml
<cpu mode='host-passthrough'/>
```

_...with no additional features._

_Although, if you need a "Hyper-V" enlightenments for Windows guest, individual enlightenments can be enabled through CPU flags, e.g::_

```bash
qemu-system-x86_64 --enable-kvm --cpu host,hv_relaxed,hv_time, hv_vapic, hv_synic, hv_runtime, hv_stimer, hv_syndbg
```

_Further information about this in here:_
[https://www.qemu.org/docs/master/system/i386/hyperv.html]

_And here:_

###### Useful links

_Hyper-V Top Level Functional specification and other information:_

[https://github.com/MicrosoftDocs/Virtualization-Documentation]

[https://docs.microsoft.com/en-us/virtualization/hyper-v-on-windows/tlfs/tlfs]

###### Launching a guest

_Utilizing SGX in the guest requires a kernel/OS with SGX support. The support can be determined in guest by:_

```bash
grep sgx /proc/cpuinfo
```

_To launch a SGX guest:_

```bash
qemu-system-x86_64 \
 -cpu host,+sgx-provisionkey \
 -object memory-backend-epc,id=mem1,size=64M,prealloc=on \
 -M sgx-epc.0.memdev=mem1,sgx-epc.0.node=0
```

#### You mainly want to make the binary with:

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
>>>>>>> Stashed changes

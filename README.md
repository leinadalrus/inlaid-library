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

###### _Install the necessary packages first:_

- meson
- ninja-build
- libglib2.0
- iasl
- cgcc
- appleframeworks
- pixman-1

_Necessary installation to have cgcc and pixman-1:
_

```bash
sudo apt-get install build-essential libcairo2-dev libpango1.0-dev libjpeg-dev libgif-dev librsvg2-dev
```

###### _Configure the local target: "i386 Soft MMU"_ for QEMU:

```bash
./configure --target-list=i386-softmmu
make
```

When done right, the following output should be:
```bash
Using './build' as the directory for build output
The Meson build system
Version: 0.61.5
Source dir: /home/leinadalrus/.config/qemu
Build dir: /home/leinadalrus/.config/qemu/build
Build type: native build
Project name: qemu
Project version: 7.2.91
C compiler for the host machine: cc -m64 -mcx16 (gcc 11.3.0 "cc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0")
C linker for the host machine: cc -m64 -mcx16 ld.bfd 2.38
Host machine cpu family: x86_64
Host machine cpu: x86_64
Program scripts/symlink-install-tree.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/symlink-install-tree.py)
Program sh found: YES (/usr/bin/sh)
C++ compiler for the host machine: c++ -m64 -mcx16 (gcc 11.3.0 "c++ (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0")
C++ linker for the host machine: c++ -m64 -mcx16 ld.bfd 2.38
Program python3 found: YES (/usr/bin/python3)
Program bzip2 found: YES (/usr/bin/bzip2)
Program iasl found: YES (/usr/bin/iasl)
Compiler for C supports link arguments -Wl,-z,relro: YES
Compiler for C supports link arguments -Wl,-z,now: YES
Compiler for C++ supports link arguments -Wl,--warn-common: YES
Program cgcc found: NO
Library m found: YES
Run-time dependency threads found: YES
Library util found: YES
Run-time dependency appleframeworks found: NO (tried framework)
Found pkg-config: /usr/bin/pkg-config (0.29.2)
Run-time dependency gio-2.0 found: YES 2.72.4
Program /usr/bin/gdbus-codegen found: YES (/usr/bin/gdbus-codegen)
Run-time dependency gio-unix-2.0 found: YES 2.72.4
Run-time dependency pixman-1 found: YES 0.40.0
Run-time dependency zlib found: YES 1.2.11
Has header "libaio.h" : NO
Run-time dependency liburing found: NO (tried pkgconfig)
Run-time dependency libnfs found: NO (tried pkgconfig)
Run-time dependency appleframeworks found: NO (tried framework)
Run-time dependency appleframeworks found: NO (tried framework)
Run-time dependency libseccomp found: NO (tried pkgconfig)
Has header "cap-ng.h" : NO
Run-time dependency xkbcommon found: NO (tried pkgconfig)
Run-time dependency slirp found: NO (tried pkgconfig)
Has header "libvdeplug.h" : NO
Run-time dependency libpulse found: NO (tried pkgconfig)
Run-time dependency alsa found: NO (tried pkgconfig)
Run-time dependency jack found: NO (tried pkgconfig)
Run-time dependency sndio found: NO (tried pkgconfig)
Run-time dependency spice-protocol found: NO (tried pkgconfig)
Run-time dependency spice-server found: NO (tried pkgconfig)
Library rt found: YES
Run-time dependency libiscsi found: NO (tried pkgconfig)
Run-time dependency libzstd found: NO (tried pkgconfig)
Run-time dependency virglrenderer found: NO (tried pkgconfig)
Run-time dependency blkio found: NO (tried pkgconfig)
Run-time dependency libcurl found: NO (tried pkgconfig)
Run-time dependency libudev found: NO (tried pkgconfig)
Library mpathpersist found: NO
Run-time dependency ncursesw found: NO (tried pkgconfig)
Has header "curses.h" : NO
Message: Trying with /usr/include/ncursesw
Has header "curses.h" : NO
Has header "brlapi.h" : NO
sdl2-config found: NO
Run-time dependency sdl2 found: NO (tried pkgconfig and config-tool)
Library rados found: NO
Has header "rbd/librbd.h" : NO
Run-time dependency glusterfs-api found: NO (tried pkgconfig)
Run-time dependency libssh found: NO (tried pkgconfig)
Has header "bzlib.h" : NO
Has header "lzfse.h" : NO
Has header "sys/soundcard.h" : YES
Run-time dependency epoxy found: NO (tried pkgconfig)
Has header "epoxy/egl.h" with dependency epoxy: NO
Run-time dependency gnutls found: NO (tried pkgconfig)
Run-time dependency gnutls found: NO (tried pkgconfig)
libgcrypt-config found: NO need ['>=1.8']
Run-time dependency libgcrypt found: NO (tried config-tool)
Run-time dependency nettle found: NO (tried pkgconfig)
Run-time dependency gmp found: NO (tried pkgconfig)
Run-time dependency gtk+-3.0 found: NO (tried pkgconfig)
Run-time dependency libpng found: YES 1.6.37
Run-time dependency libjpeg found: YES 2.1.2
Has header "sasl/sasl.h" : NO
Has header "security/pam_appl.h" : NO
Has header "snappy-c.h" : NO
Has header "lzo/lzo1x.h" : NO
Has header "numa.h" : NO
Library ibumad found: NO
Has header "rdma/rdma_cma.h" : NO
Library ibverbs found: NO
Run-time dependency xencontrol found: NO (tried pkgconfig)
Library xenstore found: NO
Library xenctrl found: NO
Library xendevicemodel found: NO
Library xenforeignmemory found: NO
Library xengnttab found: NO
Library xenevtchn found: NO
Library xentoolcore found: NO
Run-time dependency libcacard found: NO (tried pkgconfig)
Run-time dependency u2f-emu found: NO (tried pkgconfig)
Run-time dependency canokey-qemu found: NO (tried pkgconfig)
Run-time dependency libusbredirparser-0.5 found: NO (tried pkgconfig)
Run-time dependency libusb-1.0 found: NO (tried pkgconfig)
Run-time dependency libpmem found: NO (tried pkgconfig)
Run-time dependency libdaxctl found: NO (tried pkgconfig)
Run-time dependency libkeyutils found: NO (tried pkgconfig)
Checking for function "gettid" : YES
Run-time dependency libselinux found: YES 3.3
Run-time dependency fuse3 found: NO (tried pkgconfig)
Run-time dependency libbpf found: NO (tried pkgconfig)
Run-time dependency libdw found: NO (tried pkgconfig)
Has header "sys/epoll.h" : YES
Has header "linux/magic.h" : YES
Has header "valgrind/valgrind.h" : NO
Has header "linux/btrfs.h" : YES
Has header "libdrm/drm.h" : NO
Has header "pty.h" : YES
Has header "sys/disk.h" : NO
Has header "sys/ioccom.h" : NO
Has header "sys/kcov.h" : NO
Checking for function "close_range" : YES
Checking for function "accept4" : YES
Checking for function "clock_adjtime" : YES
Checking for function "dup3" : YES
Checking for function "fallocate" : YES
Checking for function "posix_fallocate" : YES
Checking for function "posix_memalign" : YES
Checking for function "_aligned_malloc" : NO
Checking for function "valloc" : YES
Checking for function "memalign" : YES
Checking for function "ppoll" : YES
Checking for function "preadv" : YES
Checking for function "pthread_fchdir_np" : NO
Checking for function "sendfile" : YES
Checking for function "setns" : YES
Checking for function "unshare" : YES
Checking for function "syncfs" : YES
Checking for function "sync_file_range" : YES
Checking for function "timerfd_create" : YES
Checking for function "copy_file_range" : YES
Checking for function "getifaddrs" : YES
Checking for function "openpty" with dependency -lutil: YES
Checking for function "strchrnul" : YES
Checking for function "system" : YES
Header <sys/epoll.h> has symbol "epoll_create1" : YES
Header <linux/falloc.h> has symbol "FALLOC_FL_PUNCH_HOLE" : YES
Header <linux/falloc.h> has symbol "FALLOC_FL_KEEP_SIZE" : YES
Header <linux/falloc.h> has symbol "FALLOC_FL_ZERO_RANGE" : YES
Has header "linux/fiemap.h" : YES
Header <linux/fs.h> has symbol "FS_IOC_FIEMAP" : YES
Checking for function "getrandom" : YES
Header <sys/random.h> has symbol "GRND_NONBLOCK" : YES
Header <sys/inotify.h> has symbol "inotify_init" : YES
Header <sys/inotify.h> has symbol "inotify_init1" : YES
Header <sys/prctl.h> has symbol "PR_SET_TIMERSLACK" : YES
Header <linux/rtnetlink.h> has symbol "IFLA_PROTO_DOWN" : YES
Header <sys/sysmacros.h> has symbol "makedev" : YES
Header <getopt.h> has symbol "optreset" : NO
Header <netinet/in.h> has symbol "IPPROTO_MPTCP" : YES
Checking whether type "struct sigevent" has member "sigev_notify_thread_id" : NO
Checking whether type "struct stat" has member "st_atim" : YES
Checking for type "struct iovec" : YES
Checking for type "struct utmpx" : YES
Checking for type "struct mmsghdr" : YES
Header <linux/vm_sockets.h> has symbol "AF_VSOCK" : YES
Program scripts/minikconf.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/minikconf.py)
Configuring i386-softmmu-config-target.h using configuration
Configuring i386-softmmu-config-devices.mak with command
Reading depfile: /home/leinadalrus/.config/qemu/build/meson-private/i386-softmmu-config-devices.mak.d
Configuring i386-softmmu-config-devices.h using configuration
Program scripts/make-config-poison.sh found: YES (/home/leinadalrus/.config/qemu/scripts/make-config-poison.sh)
Run-time dependency capstone found: NO (tried pkgconfig)
Library fdt found: NO
Configuring config-host.h using configuration
Program scripts/hxtool found: YES (/home/leinadalrus/.config/qemu/scripts/hxtool)
Program scripts/shaderinclude.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/shaderinclude.py)
Program scripts/qapi-gen.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/qapi-gen.py)
Program scripts/qemu-version.sh found: YES (/home/leinadalrus/.config/qemu/scripts/qemu-version.sh)

Executing subproject libvhost-user

libvhost-user| Project name: libvhost-user
libvhost-user| Project version: undefined
libvhost-user| C compiler for the host machine: cc -m64 -mcx16 (gcc 11.3.0 "cc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0")
libvhost-user| C linker for the host machine: cc -m64 -mcx16 ld.bfd 2.38
libvhost-user| Compiler for C supports arguments -Wsign-compare: YES
libvhost-user| Compiler for C supports arguments -Wdeclaration-after-statement: YES
libvhost-user| Compiler for C supports arguments -Wstrict-aliasing: YES
libvhost-user| Dependency threads found: YES unknown (cached)
libvhost-user| Dependency glib-2.0 found: YES 2.72.4 (overridden)
libvhost-user| Build targets in project: 10
libvhost-user| Subproject libvhost-user finished.


Executing subproject libvduse

libvduse| Project name: libvduse
libvduse| Project version: undefined
libvduse| C compiler for the host machine: cc -m64 -mcx16 (gcc 11.3.0 "cc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0")
libvduse| C linker for the host machine: cc -m64 -mcx16 ld.bfd 2.38
libvduse| Compiler for C supports arguments -Wsign-compare: YES (cached)
libvduse| Compiler for C supports arguments -Wdeclaration-after-statement: YES (cached)
libvduse| Compiler for C supports arguments -Wstrict-aliasing: YES (cached)
libvduse| Build targets in project: 11
libvduse| Subproject libvduse finished.

Program scripts/decodetree.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/decodetree.py)
Program ../scripts/modules/module_block.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/block/../scripts/modules/module_block.py)
Program ../scripts/block-coroutine-wrapper.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/block/../scripts/block-coroutine-wrapper.py)
Program scripts/modinfo-collect.py found: YES (/home/leinadalrus/.config/qemu/scripts/modinfo-collect.py)
Program scripts/modinfo-generate.py found: YES (/home/leinadalrus/.config/qemu/scripts/modinfo-generate.py)
Program nm found: YES
Program scripts/undefsym.py found: YES (/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/undefsym.py)
Program scripts/feature_to_c.sh found: YES (/bin/sh /home/leinadalrus/.config/qemu/scripts/feature_to_c.sh)
Configuring 50-edk2-i386-secure.json using configuration
Configuring 50-edk2-x86_64-secure.json using configuration
Configuring 60-edk2-aarch64.json using configuration
Configuring 60-edk2-arm.json using configuration
Configuring 60-edk2-i386.json using configuration
Configuring 60-edk2-x86_64.json using configuration
Program qemu-keymap found: NO
Program sphinx-build found: NO
Program bash found: YES 5.1.16 (/usr/bin/bash)
Program diff found: YES (/usr/bin/diff)
Program dbus-daemon found: YES (/usr/bin/dbus-daemon)
Did not find CMake 'cmake'
Found CMake: NO
Run-time dependency gvnc-1.0 found: NO (tried pkgconfig and cmake)
Run-time dependency sysprof-capture-4 found: NO (tried pkgconfig and cmake)
Program initrd-stress.sh found: YES (/home/leinadalrus/.config/qemu/tests/migration/initrd-stress.sh)
Build targets in project: 531

qemu 7.2.91

  Directories
    Install prefix               : /usr/local
    BIOS directory               : share/qemu
    firmware path                : share/qemu-firmware
    binary directory             : /usr/local/bin
    library directory            : /usr/local/lib/x86_64-linux-gnu
    module directory             : lib/x86_64-linux-gnu/qemu
    libexec directory            : /usr/local/libexec
    include directory            : /usr/local/include
    config directory             : /usr/local/etc
    local state directory        : /var/local
    Manual directory             : /usr/local/share/man
    Doc directory                : /usr/local/share/doc
    Build directory              : /home/leinadalrus/.config/qemu/build
    Source path                  : /home/leinadalrus/.config/qemu
    GIT submodules               : ui/keycodemapdb meson tests/fp/berkeley-testfloat-3 tests/fp/berkeley-softfloat-3 dtc

  Host binaries
    git                          : git
    make                         : make
    python                       : /usr/bin/python3 (version: 3.10)
    sphinx-build                 : NO
    iasl                         : /usr/bin/iasl
    genisoimage                  :

  Configurable features
    Documentation                : NO
    system-mode emulation        : YES
    user-mode emulation          : NO
    block layer                  : YES
    Install blobs                : YES
    module support               : NO
    fuzzing support              : NO
    Audio drivers                : oss
    Trace backends               : log
    D-Bus display                : YES
    QOM debugging                : NO
    vhost-kernel support         : YES
    vhost-net support            : YES
    vhost-user support           : YES
    vhost-user-crypto support    : YES
    vhost-user-blk server support: YES
    vhost-vdpa support           : YES
    build guest agent            : YES

  Compilation
    host CPU                     : x86_64
    host endianness              : little
    C compiler                   : cc -m64 -mcx16
    Host C compiler              : cc -m64 -mcx16
    C++ compiler                 : c++ -m64 -mcx16
    CFLAGS                       : -g -O2
    CXXFLAGS                     : -g -O2
    QEMU_CFLAGS                  : -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -fno-strict-aliasing -fno-common -fwrapv -Wundef -Wwrite-strings -Wmissing-prototypes -Wstrict-prototypes -Wredundant-decls -Wold-style-declaration -Wold-style-definition -Wtype-limits -Wformat-security -Wformat-y2k -Winit-self -Wignored-qualifiers -Wempty-body -Wnested-externs -Wendif-labels -Wexpansion-to-defined -Wimplicit-fallthrough=2 -Wmissing-format-attribute -Wno-missing-include-dirs -Wno-shift-negative-value -Wno-psabi -fstack-protector-strong
    QEMU_CXXFLAGS                : -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2 -D_GNU_SOURCE -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -fno-strict-aliasing -fno-common -fwrapv -Wundef -Wwrite-strings -Wtype-limits -Wformat-security -Wformat-y2k -Winit-self -Wignored-qualifiers -Wempty-body -Wendif-labels -Wexpansion-to-defined -Wimplicit-fallthrough=2 -Wmissing-format-attribute -Wno-missing-include-dirs -Wno-shift-negative-value -Wno-psabi -fstack-protector-strong
    QEMU_LDFLAGS                 : -fstack-protector-strong -Wl,-z,relro -Wl,-z,now -Wl,--warn-common
    profiler                     : NO
    link-time optimization (LTO) : NO
    PIE                          : YES
    static build                 : NO
    malloc trim support          : YES
    membarrier                   : NO
    debug stack usage            : NO
    mutex debugging              : NO
    memory allocator             : system
    avx2 optimization            : YES
    avx512bw optimization        : YES
    avx512f optimization         : NO
    gprof                        : NO
    gcov                         : NO
    thread sanitizer             : NO
    CFI support                  : NO
    strip binaries               : NO
    sparse                       : NO
    mingw32 support              : NO

  Targets and accelerators
    KVM support                  : YES
    HAX support                  : NO
    HVF support                  : NO
    WHPX support                 : NO
    NVMM support                 : NO
    Xen support                  : NO
    Xen emulation                : YES
    TCG support                  : YES
    TCG backend                  : native (x86_64)
    TCG plugins                  : YES
    TCG debug enabled            : NO
    target list                  : i386-softmmu
    default devices              : YES
    out of process emulation     : YES
    vfio-user server             : NO

  Block layer support
    coroutine backend            : ucontext
    coroutine pool               : YES
    Block whitelist (rw)         :
    Block whitelist (ro)         :
    Use block whitelist in tools : NO
    VirtFS support               : NO
    Live block migration         : YES
    replication support          : YES
    bochs support                : YES
    cloop support                : YES
    dmg support                  : YES
    qcow v1 support              : YES
    vdi support                  : YES
    vvfat support                : YES
    qed support                  : YES
    parallels support            : YES
    FUSE exports                 : NO
    VDUSE block exports          : YES

  Crypto
    TLS priority                 : NORMAL
    GNUTLS support               : NO
    libgcrypt                    : NO
    nettle                       : NO
    AF_ALG support               : NO
    rng-none                     : NO
    Linux keyring                : YES

  Dependencies
    SDL support                  : NO
    SDL image support            : NO
    GTK support                  : NO
    pixman                       : YES 0.40.0
    VTE support                  : NO
    slirp support                : NO
    libtasn1                     : NO
    PAM                          : NO
    iconv support                : YES
    curses support               : NO
    virgl support                : NO
    blkio support                : NO
    curl support                 : NO
    Multipath support            : NO
    PNG support                  : YES 1.6.37
    VNC support                  : YES
    VNC SASL support             : NO
    VNC JPEG support             : YES 2.1.2
    OSS support                  : YES
    sndio support                : NO
    ALSA support                 : NO
    PulseAudio support           : NO
    JACK support                 : NO
    brlapi support               : NO
    vde support                  : NO
    netmap support               : NO
    l2tpv3 support               : YES
    Linux AIO support            : NO
    Linux io_uring support       : NO
    ATTR/XATTR support           : YES
    RDMA support                 : NO
    PVRDMA support               : NO
    fdt support                  : internal
    libcap-ng support            : NO
    bpf support                  : NO
    spice protocol support       : NO
    rbd support                  : NO
    smartcard support            : NO
    U2F support                  : NO
    libusb                       : NO
    usb net redir                : NO
    OpenGL support (epoxy)       : NO
    GBM                          : NO
    libiscsi support             : NO
    libnfs support               : NO
    seccomp support              : NO
    GlusterFS support            : NO
    TPM support                  : YES
    libssh support               : NO
    lzo support                  : NO
    snappy support               : NO
    bzip2 support                : NO
    lzfse support                : NO
    zstd support                 : NO
    NUMA host support            : NO
    capstone                     : NO
    libpmem support              : NO
    libdaxctl support            : NO
    libudev                      : NO
    FUSE lseek                   : NO
    selinux                      : YES 3.3
    libdw                        : NO

  Subprojects
    libvduse                     : YES
    libvhost-user                : YES

  User defined options
    Native files                 : config-meson.cross
    prefix                       : /usr/local
    werror                       : true
    vfio_user_server             : disabled

Found ninja-1.10.1 at /usr/bin/ninja
Running postconf script '/usr/bin/python3 /home/leinadalrus/.config/qemu/scripts/symlink-install-tree.py'
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

> > > > > > > Stashed changes

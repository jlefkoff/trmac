
# TR Log for Mac

This is the source repository for the mac port of N6TR's
DOS contest logging program TRlog. Originally ported for linux by Larry
Tyree N6TR as [trlinux](https://github.com/trlinux/trlinux)

## Tar balls and a compiled version
If you prefer, the latest source release along with a compiled
version is available under the
[Releases](https://github.com/trlinux/trlinux/releases) tag on
[Github](https://github.com/trlinux/trlinux). The binary file
is automatically compiled by github runners using 64 bit ubuntu-latest
on Intel hardware. This
is currently Ubuntu 20.04. Check
[Runners](https://docs.github.com/en/actions/using-github-hosted-runners/about-github-hosted-runners)
for the current version
if this readme is out of date. Mint and other linux versions
based on Ubuntu should also work with that binary.
If you are running a different distribution or a 32 bit operating
system please build from source.

## Building TR mac
You need the following homebrew packages installed

* gcc
* fpc
* libusb
* xquartz

Then simply clone the repository:
```
    git clone https://github.com/jlefkoff/trmac.git
```

# Documentation
The documentation is written in latex. To compile the documentation,
you need a latex installation such as
[MacTeX](https://tug.org/mactex/).

# Typical build

Once you have cloned the archive, you can build the latest version by
```
   cd trmac
   git pull
   make
```

If you don't have latex installed, you can build just the programs trlog
and post. After cloning the repository:

```
   cd trlinux
   cd src
   make
   make install
   make -f Makefile.post
```

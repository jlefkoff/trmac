#!/bin/sh
DoExitAsm ()
{ echo "An error occurred while assembling $1"; exit 1; }
DoExitLink ()
{ echo "An error occurred while linking $1"; exit 1; }
OFS=$IFS
IFS="
"
/Library/Developer/CommandLineTools/usr/bin/ld     -lX11 :/opt/homebrew/opt/gcc/lib/gcc/15/libgcc_s.1.1.dylib :/opt/homebrew/Cellar/libusb/1.0.29/lib :/opt/homebrew/Cellar/hidapi/0.14.0/lib/libhidapi.dylib      -order_file symbol_order.fpc -multiply_defined suppress -L. -o trlog `cat link63961.res` -filelist linkfiles63961.res
if [ $? != 0 ]; then DoExitLink ; fi
IFS=$OFS

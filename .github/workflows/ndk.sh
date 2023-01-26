#!/bin/bash
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-11.1.0/clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-20.10.tar.xz -o /dev/null
tar xpvf clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-20.10.tar.xz
wget https://dl.google.com/android/repository/android-ndk-r10e-linux-x86_64.zip -o /dev/null
unzip android-ndk-r10e-linux-x86_64.zip
export ANDROID_NDK_HOME=$PWD/android-ndk-r10e/
export NDK_HOME=$PWD/android-ndk-r10e/
export PATH=$PWD/clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-20.10/bin:$PATH
./waf configure -T release --64bits --togles --android=aarch64,host,21 --prefix=/csgo-android
./waf install -j4 --strip


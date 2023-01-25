#!/bin/bash
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-11.1.0/clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz && tar xpvf clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-16.04.tar.xz
wget https://dl.google.com/android/repository/android-ndk-r10e-linux-x86_64.zip && unzip android-ndk-r10e-linux-x86_64.zip
export ANDROID_NDK=/home/runner/work/csgo-sdk-2017/csgo-sdk-2017/android-ndk-r10e && export PATH=/home/runner/work/csgo-sdk-2017/csgo-sdk-2017/clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-16.04/bin:$PATH
./waf configure -T release --64bits --android=aarch64,host,21 --prefix=/home/runner/work/csgo-sdk-2017/csgo-sdk-2017/csgo-android
./waf install -j4

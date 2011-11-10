#!/bin/bash

javac JSpgLib.java
javah JSpgLib
gcc -fPIC -g -c  -I/System/Library/Frameworks/JavaVM.framework/Headers interfaceJSpgLib.c
gcc -shared -o libinterfaceJSpgLib.jnilib interfaceJSpgLib.o
java JSpgLib

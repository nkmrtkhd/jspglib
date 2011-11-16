#!/bin/bash

javac jspglib/JSpgLib.java && \
javah -classpath . jspglib.JSpgLib && \
gcc -fPIC -g -c -I/usr/lib/jvm/java-1.6.0-openjdk-1.6.0.0.x86_64/include/linux/ -I/usr/lib/jvm/java-1.6.0-openjdk-1.6.0.0.x86_64/include/ -I/home/nakamura/myLocal/spglib-1.0.9/include/spglib interfaceJSpgLib.c && \
gcc -shared  -L/home/nakamura/myLocal/spglib-1.0.9/lib/ -lsymspg -lm -o libinterfaceJSpgLib.so interfaceJSpgLib.o && \
java -classpath . jspglib.JSpgLib

#!/bin/bash

tar xzvf spglib-1.0.9.tar.gz &&\
cd spglib-1.0.9 &&\
./configure --prefix=$HOME/myLocal/spglib-1.0.9 &&\
make install &&\
cd ../ &&\
javac jspglib/JSpgLib.java && \
javah -classpath . jspglib.JSpgLib && \
gcc -fPIC -g -c -I/usr/lib/jvm/java-1.6.0-openjdk-1.6.0.0.x86_64/include/linux/ -I/usr/lib/jvm/java-1.6.0-openjdk-1.6.0.0.x86_64/include/ -I/home/nakamura/myLocal/spglib-1.0.9/include/spglib interfaceJSpgLib.c && \
gcc -shared  -L$HOME/myLocal/spglib-1.0.9/lib/ -lsymspg -lm -o libinterfaceJSpgLib.so interfaceJSpgLib.o && \
java -classpath . jspglib.JSpgLib &&\
ant jar
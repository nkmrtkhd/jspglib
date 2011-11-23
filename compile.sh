#!/bin/bash

tar xzvf spglib-1.0.9.tar.gz &&\
cd spglib-1.0.9 &&\
./configure --prefix=$HOME/myLocal/spglib-1.0.9 &&\
make install &&\
cd ../ &&\
javac jspglib/JSpgLib.java && \
javah -classpath . jspglib.JSpgLib && \
gcc -fPIC -g -c -I/System/Library/Frameworks/JavaVM.framework/Headers -I/Users/nakamura/myLocal/spglib-1.0.9/include/spglib interfaceJSpgLib.c && \
gcc -shared  -L/Users/nakamura/myLocal/spglib-1.0.9/lib/ -lsymspg -lm \
-o libinterfaceJSpgLib.jnilib interfaceJSpgLib.o && \
java -classpath . jspglib.JSpgLib &&\
ant jar
Java front end of [spglib ](http://spglib.sourceforge.net/)

**コンパイル方法**

for OSX
```
javac jspglib/JSpgLib.java
javah -classpath . jspglib.JSpgLib
gcc -fPIC -g -c -I/System/Library/Frameworks/JavaVM.framework/Headers -I/Users/nakamura/myLocal/spglib-1.0.9/include/spglib interfaceJSpgLib.c
gcc -shared  -L/Users/nakamura/myLocal/spglib-1.0.9/lib/ -lsymspg -lm -o libinterfaceJSpgLib.jnilib interfaceJSpgLib.o 
java -classpath . jspglib.JSpgLib
```

実行は
```
java jspglib.JSpgLib
```

**使い方**

jarで固めたJSpgLib.jarとlibinterfaceJspgLib.jnilibをPATHの通った場所に置く．
```
import jspglib.JSpgLib;

JSpgLib jspg=new JSpgLib();
jspg.
```
などとする．
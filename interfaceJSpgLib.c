#include <jni.h>
#include "JSpgLib.h"
#include <stdio.h>

JNIEXPORT void JNICALL Java_JSpgLib_printHello
(JNIEnv *env, jobject obj)
{
  printf("Hello JNI World\n");
  return;
}

JNIEXPORT void JNICALL Java_JSpgLib_getPrimitive
(JNIEnv *env, jobject obj, jobjectArray a)
{
  printf("catch %f\n",a[0][0]);
  return;
}
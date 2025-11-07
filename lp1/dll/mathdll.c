#include <jni.h>
#include "MathLibrary.h"

JNIEXPORT jint JNICALL Java_MathLibrary_add
  (JNIEnv *env, jobject obj, jint a, jint b) {
    return a + b;
}

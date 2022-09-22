/*
* Copyright (c) 2022 XXIV
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "URLEncoding.h"

extern char* url_encoding_encode(const char* data);

extern char* url_encoding_encode_binary(const unsigned char* data, size_t length);

extern char* url_encoding_decode(const char* data);

extern char* url_encoding_decode_binary(const unsigned char* data, size_t length);

extern void url_encoding_free(char* ptr);

JNIEXPORT jstring JNICALL Java_URLEncoding_encode
  (JNIEnv* env, jclass cls, jstring str)
{
    const char* data = (*env)->GetStringUTFChars(env,str, NULL);
    char* res = url_encoding_encode(data);
    if (res == NULL)
    {
        return NULL;
    }
    jstring jstr = (*env)->NewStringUTF(env,res);
    url_encoding_free(res);
    return jstr;
}


JNIEXPORT jstring JNICALL Java_URLEncoding_encodeBinary
  (JNIEnv* env, jclass cls, jstring str)
{
    const char* data = (*env)->GetStringUTFChars(env,str, NULL);
    char* res = url_encoding_encode_binary(data, (*env)->GetStringUTFLength(env,str));
    if (res == NULL)
    {
        return NULL;
    }
    jstring jstr = (*env)->NewStringUTF(env,res);
    url_encoding_free(res);
    return jstr;
}


JNIEXPORT jstring JNICALL Java_URLEncoding_decode
  (JNIEnv* env, jclass cls, jstring str)
{
    const char* data = (*env)->GetStringUTFChars(env,str, NULL);
    char* res = url_encoding_decode(data);
    if (res == NULL)
    {
        return NULL;
    }
    jstring jstr = (*env)->NewStringUTF(env,res);
    url_encoding_free(res);
    return jstr;
}


JNIEXPORT jstring JNICALL Java_URLEncoding_decodeBinary
  (JNIEnv* env, jclass cls, jstring str)
{
    const char* data = (*env)->GetStringUTFChars(env,str, NULL);
    char* res = url_encoding_decode_binary(data, (*env)->GetStringUTFLength(env,str));
    if (res == NULL)
    {
        return NULL;
    }
    jstring jstr = (*env)->NewStringUTF(env,res);
    url_encoding_free(res);
    return jstr;
}
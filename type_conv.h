#ifndef _TYPE_CONV_H_
#define _TYPE_CONV_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char u8;

long Byte4ToLong(char bytes[4]);
void StrToHex(u8 *pbDest, u8 *pbSrc, int nLen);
#ifdef __cplusplus
}
#endif

#endif


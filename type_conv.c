#include "type_conv.h"
#include <ctype.h>

long Byte4ToLong(char bytes[4])
{
    long result = 0;

    result = ((bytes[0] & 0xFF) + (bytes[1] & 0xFF) * 256 + (bytes[2] & 0xFF) * 256 * 256 + (long) (bytes[3] & 0xFF) * 256 * 256 * 256);

    return result;
}

/**
 * C prototype : void StrToHex(BYTE *pbDest, BYTE *pbSrc, int nLen)
 * parameter(s): [OUT] pbDest - 输出缓冲区
 * [IN] pbSrc - 字符串
 * [IN] nLen - 16进制数的字节数(字符串的长度/2)
 * return value:
 * remarks : 将字符串转化为16进制数
*/
void StrToHex(u8 *pbDest, u8 *pbSrc, int nLen)
{
    char h1,h2;
    u8 s1,s2;
    int i;

    for (i=0; i<(nLen/2); i++)
    {
        h1 = pbSrc[2*i];
        h2 = pbSrc[2*i+1];

        s1 = toupper(h1) - 0x30;
        if (s1 > 9)
            s1 -= 7;

        s2 = toupper(h2) - 0x30;
        if (s2 > 9)
            s2 -= 7;

        pbDest[i] = s1*16 + s2;
    }
}

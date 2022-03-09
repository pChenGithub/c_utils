#ifndef _IFNET_OPT_H_
#define _IFNET_OPT_H_

#define IP_TYPE_4BYTE   0
#define IP_TYPE_STR     1

int get_ip(const char* ifname, unsigned char *ip, int len, char type);
int get_gateway(const char* ifname, unsigned char *ip, int len);
int get_mask(const char* ifname, unsigned char *ip, int len, char type);

#endif



#include "ifnet_opt.h"
#include "global.h"

#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#define LOGTAG "ifnet_opt"
#define IFACE_NUM 3

int get_ip(const char *ifname, unsigned char* ip, int len, char type)
{
    int ret = 0;
    int socketfd = 0;
    // struct ifreq，保存了网络接口的信息，包括名字、ip、掩码、广播。链路状态、mac地址
    // struct ifconf 理解为ifreq的集合，但是ifreq的内存需要用户指定
    struct ifreq ifcu_req;
    // 检查参数
    assert(NULL!=ifname && NULL!=ip);
    // 获取socket，
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd<0)
    {
        LOG_E("socket create failed");
        return -1;
    }

    memcpy(ifcu_req.ifr_ifrn.ifrn_name, ifname, strlen(ifname)+1);
    if (ioctl(socketfd, SIOCGIFADDR, &ifcu_req)<0)
    {
        LOG_E("ioctl system call failed");
        ret = -1;
        goto socket_close_exit;
    }

    // 打印ip地址
    struct sockaddr* ip_addr = &ifcu_req.ifr_ifru.ifru_addr;
#if 0
    LOG_D("ip addr xx %d.%d.%d.%d",
          ip_addr->sa_data[2],
            ip_addr->sa_data[3],
            ip_addr->sa_data[4],
            ip_addr->sa_data[5]);
#endif
    switch (type) {
    case IP_TYPE_4BYTE:
        ip[0] = ip_addr->sa_data[2];
        ip[1] = ip_addr->sa_data[3];
        ip[2] = ip_addr->sa_data[4];
        ip[3] = ip_addr->sa_data[5];
        break;
    case IP_TYPE_STR:
    default:
        snprintf((char*)ip, len, "%d.%d.%d.%d",
                ip_addr->sa_data[2],
                ip_addr->sa_data[3],
                ip_addr->sa_data[4],
                ip_addr->sa_data[5]);
        break;
    }
socket_close_exit:
    close(socketfd);
    return ret;
}

int get_gateway(const char *ifname, unsigned char *ip, int len)
{
    (void)len;
    (void)ip;
    (void)ifname;
    int ret = 0;
    return ret;
}

int get_mask(const char *ifname, unsigned char *ip, int len, char type)
{
    int ret = 0;
    int socketfd = 0;
    // struct ifreq，保存了网络接口的信息，包括名字、ip、掩码、广播。链路状态、mac地址
    // struct ifconf 理解为ifreq的集合，但是ifreq的内存需要用户指定
    struct ifreq ifcu_req;
    // 检查参数
    assert(NULL!=ifname && NULL!=ip);
    // 获取socket，
    socketfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socketfd<0)
    {
        LOG_E("socket create failed");
        return -1;
    }

    memcpy(ifcu_req.ifr_ifrn.ifrn_name, ifname, strlen(ifname)+1);
    if (ioctl(socketfd, SIOCGIFNETMASK, &ifcu_req)<0)
    {
        LOG_E("ioctl system call failed");
        ret = -1;
        goto socket_close_exit;
    }

    // 打印ip地址
    struct sockaddr* ip_addr = &ifcu_req.ifr_ifru.ifru_netmask;
#if 0
    LOG_D("ip addr xx %d.%d.%d.%d",
          ip_addr->sa_data[2],
            ip_addr->sa_data[3],
            ip_addr->sa_data[4],
            ip_addr->sa_data[5]);
#endif
    switch (type) {
    case IP_TYPE_4BYTE:
        ip[0] = ip_addr->sa_data[2];
        ip[1] = ip_addr->sa_data[3];
        ip[2] = ip_addr->sa_data[4];
        ip[3] = ip_addr->sa_data[5];
        break;
    case IP_TYPE_STR:
    default:
        snprintf((char*)ip, len, "%d.%d.%d.%d",
                ip_addr->sa_data[2],
                ip_addr->sa_data[3],
                ip_addr->sa_data[4],
                ip_addr->sa_data[5]);
        break;
    }

socket_close_exit:
    close(socketfd);
    return ret;
}

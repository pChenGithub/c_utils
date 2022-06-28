// 正则表达式C接口
#ifndef __REGULAR_EXP_H__
#define __REGULAR_EXP_H__
#ifdef __cplusplus
extern "C" {
#endif
// 经典的正则表达式
#define REGULAR_STR_IP      "^[0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}$"  // IP地址
#define REGULAR_STR_HOST    "^[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(\\.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+\\.\?$"  // 域名

#define REGULAR_MATCH           0   // 正则表示式匹配
#define REGULAR_ERR_PARAMCHECK  1   // 参数检查失败
#define REGULAR_ERR_COMPILED    2   // 正则字符串编译失败
#define REGULAR_ERR_NOTMATCH    3  // 正则表示式匹配

// 验证指定字符串是否符合指定正则表达式
int regular_match(const char* in, const char* regular);
#ifdef __cplusplus
}
#endif

#endif


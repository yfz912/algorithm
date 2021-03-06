#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

bool wordBreak(char *s, char **wd, int n)
{
    if (s == NULL || wd == NULL || n == 0) {
        return false; // 参数错误
    }
    const int len = strlen(s);
    // dp[i] = dynamic plan, 后i个字符串，是否OK
    // bool dp[len + 1]; // gcc支持变长数组，vs不支持
    int size = sizeof(bool) * (len + 1);
    bool *dp = (bool *)malloc(size);
    memset(dp, 0, size);
    dp[len] = true; // 后0个字符串，认为OK
    for (int i = len - 1; i >= 0; i--) {

        for (int j = 0; j < n; j++) {
            int wdlen = strlen(wd[j]);
            int k = i + wdlen; // 后段
            if (k > len) { // 后段不够长
                continue;
            }
            dp[i] = (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) || dp[i];
            /* if (dp[k] && strncmp(s + i, wd[j], wdlen) == 0) {
                printf("i=%d, k=%d,  s=%s, wd[%d]=%s, wdlen=%d,  dp[%d]=%d, dp[%d]=%d\n",
                    i, k, s + k, j, wd[j], wdlen, k, dp[k], i, dp[i]);
            } */
        }
    }
    /* for (int i = 0; i <= len; i++) {
        printf("%d:%d ", i, dp[i]);
    }
    printf("\n");
    */
    return dp[0];
}

int main()
{
    // const char s[] = "leetcode", *wd[] = {"leet", "code"}; // true
    // const char s[] = "applepenapple", *wd[] = {"apple", "pen"}; // true
    // const char s[] = "catsandog", *wd[] = {"cats", "dog", "sand", "and", "cat"}; // false
    /* const char s[] = "bccdbacdbdacddabbaaaadababadad",
        *wd[] = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa",
            "bd","abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b",
            "bcc","bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a",
            "bbcc","cdcbd","cada","dbca","ac","abacd","cba","cdb",
            "dbac","aada","cdcda","cdc","dbc","dbcb","bdb","ddbdd",
            "cadaa","ddbc","babb"};*/// true
    const char s[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
        *wd[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}; // false
    int n = sizeof(wd) / sizeof(wd[0]);
    
    /*int r = strcmp(wd[0], wd[1]);
        printf("r=%d\n", r);    
    for (int i = 0; i < n; i++) {
        printf("%s\n", wd[i]);
    }*/
    if (wordBreak((char*)s, (char**)wd, n)) {
        printf("true");
    } else {
        printf("false");        
    }     
    return 0;
}

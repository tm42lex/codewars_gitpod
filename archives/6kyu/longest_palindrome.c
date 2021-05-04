#include <string.h>
#include <stdio.h>

int longest_palindrome(const char *s)
{
    int slen   = strlen(s);
    int o_slen = slen;
    int ret    = 0;
    while(slen--) {
        int i =  0 - 1;
        while(++i <= slen) {
            int plen = 0;
            while (s[i + plen] == s[slen - plen] && ++plen && plen <= o_slen){
                if (plen > ret) 
                    ret++;
                if (&(s[i + plen]) >= &(s[slen - plen])){
                    ret *= 2;
                    if (&(s[i + plen]) == (&s[slen - plen]))
                        ret++;
                    break;
                }
            }
        }
    }
    return ret;
}
int main() {
    const char *s1 = "hello";
    const char *s2 = "zzbaabcd";
    const char *s3 = "I like racecars that go fast";

    printf("%d\n", longest_palindrome(s1));
    printf("%d\n", longest_palindrome(s2));
    printf("%d\n", longest_palindrome(s3));
    return (0);
}
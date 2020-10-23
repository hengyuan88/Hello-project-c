/*******
 * Topic: Is “inline” without “static” or “extern” ever useful in C99?
 * Refer: https://stackoverflow.com/questions/6312597/is-inline-without-static-or-extern-ever-useful-in-c99
 */
#include <stdio.h>

/* 'gcc -std=c99 -o a inline.c' will fail if no "extern" */
/* #if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 199901L */
#if __GNUC__ < 5
char v[16]="no-extern";
inline void f() {}
#else
char v[16]="with-extern";
extern inline void f() {}
#endif

int main()
{
	f();
	printf("===[ %s ]===\n", v);
	printf("[GCC Version : %s]\n", __VERSION__);
#if defined(__STDC_VERSION__)
	printf("[STDC Version: %ldL]\n", __STDC_VERSION__);
#endif
	return 0;
}

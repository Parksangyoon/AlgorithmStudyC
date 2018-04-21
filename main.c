#include <stdio.h>

int main()
{
    int test_case;
    int T, answer=0;
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}

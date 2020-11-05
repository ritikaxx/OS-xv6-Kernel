#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char *argv[])
{
int x = atoi(argv[1]);
int n = atoi(argv[2]);
int res = 1;
for(int i = 0; i < n; i++) {
    res *= x;
}
printf(1,"\n %d to the power of %d is %d \n", x, n, pow(res));
exit();
}

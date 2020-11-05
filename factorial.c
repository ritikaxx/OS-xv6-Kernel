#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    int fact = 1;
    int i;
    //argint(0, &x);
    for(i = 1; i <= x; i++) {
        fact = fact * i;
    }
    printf(1,"\n The factorial of %d is %d\n", x, factorial(fact));
    exit();
}

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
int x=atoi(argv[1]);
printf(0,"\n The cube of %d is %d",x,cube(x));
exit();
}

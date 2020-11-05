#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
int size=argc-1;
int data[size];
int i;
int m=0;
for (i=0;i<size;i++)
{
data[i]=atoi(argv[i+1]);
m+=data[i];
printf(1,"\n m value: %d",m);
}
m/= size; 
printf(1,"\n mean value %d",mean(m));
exit();
}

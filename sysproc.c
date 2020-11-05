#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stdio.h"
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}


int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
int
sys_cps(void)
{
return cps();
}


int 
sys_shutdown(void)
{
cprintf("shutdown signal sent \n");
outw( 0xB004,0x0 | 0x2000);
return 0;
}

int 
sys_hello(void)
{
  int n;
  if(argint(0,&n)<0)
  return -1;
  cprintf("heloo world %d\n",n);
  return 0;
}
int
sys_birthyear(void)
{
return 2002;
}


int sys_square(void)  {
  int x;
  argint(0, &x);
  return x*x;
}

int sys_cube(void)  {
  int x;
  argint(0, &x);
  return x*x*x;
}

int sys_pow(void)  {
  int x;
  argint(0, &x);
  return x;
}

int sys_median(void)  {
  int x;
  argint(0, &x);
  return x;
}

int sys_factorial(void)  {
  int x;
  argint(0, &x);
  return x;
}

int sys_mean(void)  {
  int x;
  argint(0, &x);
  return x;
}


int
sys_date(struct rtcdate *r)
{
    if (argptr(0, (void *)&r, sizeof(*r)) < 0)
    {
       return -1;
    }
       cmostime(r);  // get the time from the cmos
       return 0;
 }




int
sys_alarm(void)
{
	int ticks;
	void (*handler)();

	if(argint(0,&ticks) < 0)
		return -1;
	if(argptr(1,(char **)&handler,1) < 0)
		return -1;

	myproc()->alarmticks = ticks;
	myproc()->alarmhandler = handler;
	return 0;
}


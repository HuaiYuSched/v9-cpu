
#include <u.h>

int current;

out(port, val) {asm(LL,8); asm(LBL, 16); asm(BOUT);}
ivec(void *isr) { asm(LL,8); asm(IVEC); }
stmr(int val)   { asm(LL,8); asm(TIME); }
halt(val)       { asm(LL,8); asm(HALT); }

write(fd,char *p, n){ while (n--) out(fd,*p++);}

trap()
{

}
  

alltraps()
{
  asm(PSHA);
  asm(PSHB);
  asm(PSHC);

  current++;
  trap();

  asm(POPC);
  asm(POPB);
  asm(POPA);
  asm(RTI);
}

main()
{
  current = 0;
  stmr(1000);
  ivec(alltraps);
  asm(STI);
  while(current < 10){
    if(current &1) out(1,'1'); else out(1,'0');
  }
  halt(0);
}

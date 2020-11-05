#include "cpu/exec/template-start.h"

#define instr jbe


static void do_execute() {
	DATA_TYPE_S displacement = op_src->val;
	print_asm("jbe %x  %x %d,%d %x",cpu.eip + 1 + DATA_BYTE + displacement,  cpu.eip  ,cpu.ZF ,  cpu.CF,cpu.eip   );
    
	if (cpu.CF == 1 || cpu.ZF == 1)cpu.eip +=displacement;
}
make_instr_helper(i)


#include "cpu/exec/template-end.h"

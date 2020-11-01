#include "cpu/exec/template-start.h"

#define instr ret

make_helper(concat(ret_n_, SUFFIX))
{
	current_sreg = R_SS;
	cpu.eip = swaddr_read(reg_l(R_ESP),DATA_BYTE);
	//if (DATA_BYTE == 2)cpu.eip &= 0xffff;
	reg_l (R_ESP) += DATA_BYTE;
	print_asm("ret");
	return 1;
}


#include "cpu/exec/template-end.h"

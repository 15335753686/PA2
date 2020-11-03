#include "cpu/exec/template-start.h"


#define  instr pop

static void do_execute()
{
    if (DATA_BYTE==1)
    {
        current_sreg =  R_SS;
        swaddr_write(op_src->addr,4,swaddr_read(reg_l(R_ESP), DATA_BYTE));
        swaddr_write(reg_l(R_ESP), DATA_BYTE, 0);
        reg_l(R_ESP) += 4;

    }
    else
    {   
        current_sreg  =  R_SS;
       concat(write_operand_, SUFFIX) (op_src, swaddr_read(REG(R_ESP), DATA_BYTE));
        swaddr_write(reg_l(R_ESP), DATA_BYTE, 0);
        reg_l(R_ESP) += DATA_BYTE;
    }
    print_asm_template1();
}

#if DATA_BYTE == 2 || DATA_BYTE ==4
make_instr_helper(r)
make_instr_helper(rm)
#endif





#include "cpu/exec/template-end.h"
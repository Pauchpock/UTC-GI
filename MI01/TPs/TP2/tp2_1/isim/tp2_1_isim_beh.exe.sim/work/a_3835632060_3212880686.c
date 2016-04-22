/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//nassme.utc/~mi01a002/tp2_1/tp2_1.vhd";



static void work_a_3835632060_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    int t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)1);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 660U);
    t4 = xsi_signal_has_event(t1);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 948U);
    t2 = *((char **)t1);
    t9 = *((int *)t2);
    t1 = (t0 + 1744);
    t5 = (t1 + 32U);
    t8 = *((char **)t5);
    t11 = (t8 + 40U);
    t12 = *((char **)t11);
    *((int *)t12) = t9;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 1700);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 948U);
    t5 = *((char **)t1);
    t1 = (t5 + 0);
    *((int *)t1) = 0;
    goto LAB3;

LAB5:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 948U);
    t8 = *((char **)t2);
    t9 = *((int *)t8);
    t10 = (t9 + 1);
    t2 = (t0 + 948U);
    t11 = *((char **)t2);
    t2 = (t11 + 0);
    *((int *)t2) = t10;
    goto LAB3;

LAB7:    t2 = (t0 + 684U);
    t5 = *((char **)t2);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)1);
    t3 = t7;
    goto LAB9;

}


extern void work_a_3835632060_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3835632060_3212880686_p_0};
	xsi_register_didat("work_a_3835632060_3212880686", "isim/tp2_1_isim_beh.exe.sim/work/a_3835632060_3212880686.didat");
	xsi_register_executes(pe);
}


#include "types.h"
#include "utils.h"
#include "string.h"
#include "debug.h"
#include "ff.h"

#define MAX_STRLEN 64


void __write_mem_reg(int reg, u16 val) { *(u16*)(0x0d8b4000 + reg * 2) = val; }
u16 __read_mem_reg(int reg) { return *(u16*)(0x0d8b4000 + reg * 2); }

void __ddr_write(u16 reg, u16 val)
{
	__write_mem_reg(0x3a, reg);
	__read_mem_reg(0x3a);
	__write_mem_reg(0x3b, val);
}

u16 __ddr_read(u16 reg)
{
	u16 res;

	__write_mem_reg(0x3a, reg);
	__read_mem_reg(0x3a);
	res = __read_mem_reg(0x3b);
	return res;
}


void memreg_dump()
{
	char string[MAX_STRLEN];
	u32 len;

	FIL fp; 
	f_open(&fp, "memlog.txt", FA_CREATE_ALWAYS | FA_WRITE);

	//for (u32 regaddr = 0x0d8b4000; regaddr < 0x0d8b4078; regaddr += 0x2)
	//{
	//	sprintf(string, "%08x: %04x\n", regaddr, *(u16*)regaddr);
	//	len = strlen(string);
	//	f_write(&fp, &string, len, NULL);
	//	memset(&string, 0, MAX_STRLEN);
	//}

	//for (u32 regaddr = 0x0d8b4204; regaddr < 0x0d8b4210; regaddr += 0x2)
	//for (u32 regaddr = 0x0d8b4000; regaddr < 0x0d8b4200; regaddr += 0x2)
	//{
	//	sprintf(string, "%08x: %04x\n", regaddr, *(u16*)regaddr);
	//	len = strlen(string);
	//	f_write(&fp, &string, len, NULL);
	//	memset(&string, 0, MAX_STRLEN);
	//}

	for (u32 regaddr = 0x0d8b0000; regaddr < 0x0d8b0200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}
	for (u32 regaddr = 0x0d8b1000; regaddr < 0x0d8b1200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}
	for (u32 regaddr = 0x0d8b2000; regaddr < 0x0d8b2200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}
	for (u32 regaddr = 0x0d8b3000; regaddr < 0x0d8b3200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}
	for (u32 regaddr = 0x0d8b5000; regaddr < 0x0d8b5200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}
	for (u32 regaddr = 0x0d8b6000; regaddr < 0x0d8b6200; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}


	f_close(&fp);
}




// MEMIRR bits are typically 0x27 when we run MINI.
void acrreg_dump()
{
	char string[MAX_STRLEN];
	u32 len;

	FIL fp; 
	f_open(&fp, "acrlog.txt", FA_CREATE_ALWAYS | FA_WRITE);

	//sprintf(string, "%08x: %08x\n", 0x0d800058, *(u32*)0x0d800058);
	//len = strlen(string);
	//f_write(&fp, &string, len, NULL);
	//memset(&string, 0, MAX_STRLEN);

	//// Why does setting 0x40 not work lol
	//udelay(100);
	//write32(0x0d800060, 0xffffffff);
	//udelay(100);
	//sprintf(string, "SRNPROT is %08x\n", *(u32*)0x0d800060);
	//len = strlen(string);
	//f_write(&fp, &string, len, NULL);
	//memset(&string, 0, MAX_STRLEN);

	//sprintf(string, "%08x: %08x\n", 0x0d800058, *(u32*)0x0d800058);
	//len = strlen(string);
	//f_write(&fp, &string, len, NULL);
	//memset(&string, 0, MAX_STRLEN);


	for (u32 regaddr = 0x0d800000; regaddr < 0x0d800400; regaddr += 0x4)
	{
		sprintf(string, "%08x: %08x\n", regaddr, *(u32*)regaddr);
		len = strlen(string);
		f_write(&fp, &string, len, NULL);
		memset(&string, 0, MAX_STRLEN);
	}

	f_close(&fp);
}

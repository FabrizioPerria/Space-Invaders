#ifndef __SHARED_REGISTERS_H
#	define __SHARED_REGISTERS_H

/* 
	Here all the I/O register addresses used by more than one module
   are defined
*/

#	define SYSCTL_RCGC0	(*((volatile unsigned long *)0x400FE100))
#	define SYSCTL_RCGC1	(*((volatile unsigned long *)0x400FE104))	
#	define SYSCTL_RCGC2	(*((volatile unsigned long *)0x400FE108))

#	define MAGIC_NUM 		0x4C4F434B;		// used to unlock the GPIO ports

#endif

// SPDX-License-Identifier: GPL-2.0
/*
 * TODO
 */

#include <asm/armv8/mmu.h>

int board_init(void)
{
	return 0;
}

static struct mm_region tetris_mem_map[] = {
	{
		/* DDR */
		.virt = 0x40000000UL,
		.phys = 0x40000000UL,
		.size = 0x40000000UL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_NORMAL) | PTE_BLOCK_OUTER_SHARE,
	}, {
		/* Peripheral block */
		.virt = 0x00000000UL,
		.phys = 0x00000000UL,
		.size = 0x23fffffffUL,
		.attrs = PTE_BLOCK_MEMTYPE(MT_DEVICE_NGNRNE) |
			 PTE_BLOCK_NON_SHARE |
			 PTE_BLOCK_PXN | PTE_BLOCK_UXN
	}, {
	}
};

struct mm_region *mem_map = tetris_mem_map;

/*
 * Copyright (c) 2010-2012 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * EXYNOS - GPIO lib support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H __FILE__

#include <linux/types.h>
#include <linux/err.h>
#include <mach/irqs.h>
#include <plat/irqs.h>
#include <plat/cpu.h>

/* Macro for EXYNOS GPIO numbering */

#define EXYNOS_GPIO_NEXT(__gpio) \
	((__gpio##_START) + (__gpio##_NR) + CONFIG_S3C_GPIO_SPACE + 1)

/* EXYNOS4 GPIO bank sizes */

#define EXYNOS4_GPIO_A0_NR	(8)
#define EXYNOS4_GPIO_A1_NR	(6)
#define EXYNOS4_GPIO_B_NR	(8)
#define EXYNOS4_GPIO_C0_NR	(5)
#define EXYNOS4_GPIO_C1_NR	(5)
#define EXYNOS4_GPIO_D0_NR	(4)
#define EXYNOS4_GPIO_D1_NR	(4)

/* GPIO_E serise is only for EXYNOS4210 */
#define EXYNOS4_GPIO_E0_NR	(5)
#define EXYNOS4_GPIO_E1_NR	(8)
#define EXYNOS4_GPIO_E2_NR	(6)
#define EXYNOS4_GPIO_E3_NR	(8)
#define EXYNOS4_GPIO_E4_NR	(8)

#define EXYNOS4_GPIO_F0_NR	(8)
#define EXYNOS4_GPIO_F1_NR	(8)
#define EXYNOS4_GPIO_F2_NR	(8)
#define EXYNOS4_GPIO_F3_NR	(6)
#define EXYNOS4_GPIO_J0_NR	(8)
#define EXYNOS4_GPIO_J1_NR	(5)
#define EXYNOS4_GPIO_K0_NR	(7)
#define EXYNOS4_GPIO_K1_NR	(7)
#define EXYNOS4_GPIO_K2_NR	(7)
#define EXYNOS4_GPIO_K3_NR	(7)
#define EXYNOS4_GPIO_L0_NR	(8)	/* EXYNOS4X12 has 7 pins */
#define EXYNOS4_GPIO_L1_NR	(3)	/* EXYNOS4X12 has 2 pins */
#define EXYNOS4_GPIO_L2_NR	(8)
#define EXYNOS4_GPIO_Y0_NR	(6)
#define EXYNOS4_GPIO_Y1_NR	(4)
#define EXYNOS4_GPIO_Y2_NR	(6)
#define EXYNOS4_GPIO_Y3_NR	(8)
#define EXYNOS4_GPIO_Y4_NR	(8)
#define EXYNOS4_GPIO_Y5_NR	(8)
#define EXYNOS4_GPIO_Y6_NR	(8)

/* GPIO_M serise is only for EXYNOS4X12*/
#define EXYNOS4_GPIO_M0_NR	(8)
#define EXYNOS4_GPIO_M1_NR	(7)
#define EXYNOS4_GPIO_M2_NR	(5)
#define EXYNOS4_GPIO_M3_NR	(8)
#define EXYNOS4_GPIO_M4_NR	(8)

#define EXYNOS4_GPIO_X0_NR	(8)
#define EXYNOS4_GPIO_X1_NR	(8)
#define EXYNOS4_GPIO_X2_NR	(8)
#define EXYNOS4_GPIO_X3_NR	(8)
#define EXYNOS4_GPIO_Z_NR	(7)

/* GPIO_V serise is only for EXYNOS4X12*/
#define EXYNOS4_GPIO_V0_NR	(8)
#define EXYNOS4_GPIO_V1_NR	(8)
#define EXYNOS4_GPIO_V2_NR	(8)
#define EXYNOS4_GPIO_V3_NR	(8)
#define EXYNOS4_GPIO_V4_NR	(2)

/* EXYNOS4 GPIO bank numbers */

enum exynos4_gpio_number {
	EXYNOS4_GPIO_A0_START	= 0,
	EXYNOS4_GPIO_A1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_A0),
	EXYNOS4_GPIO_B_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_A1),
	EXYNOS4_GPIO_C0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_B),
	EXYNOS4_GPIO_C1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_C0),
	EXYNOS4_GPIO_D0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_C1),
	EXYNOS4_GPIO_D1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_D0),
	EXYNOS4_GPIO_E0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_D1),
	EXYNOS4_GPIO_E1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_E0),
	EXYNOS4_GPIO_E2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_E1),
	EXYNOS4_GPIO_E3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_E2),
	EXYNOS4_GPIO_E4_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_E3),
	EXYNOS4_GPIO_F0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_E4),
	EXYNOS4_GPIO_F1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_F0),
	EXYNOS4_GPIO_F2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_F1),
	EXYNOS4_GPIO_F3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_F2),
	EXYNOS4_GPIO_J0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_F3),
	EXYNOS4_GPIO_J1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_J0),
	EXYNOS4_GPIO_K0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_J1),
	EXYNOS4_GPIO_K1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_K0),
	EXYNOS4_GPIO_K2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_K1),
	EXYNOS4_GPIO_K3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_K2),
	EXYNOS4_GPIO_L0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_K3),
	EXYNOS4_GPIO_L1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_L0),
	EXYNOS4_GPIO_L2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_L1),
	EXYNOS4_GPIO_Y0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_L2),
	EXYNOS4_GPIO_Y1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y0),
	EXYNOS4_GPIO_Y2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y1),
	EXYNOS4_GPIO_Y3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y2),
	EXYNOS4_GPIO_Y4_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y3),
	EXYNOS4_GPIO_Y5_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y4),
	EXYNOS4_GPIO_Y6_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y5),
	EXYNOS4_GPIO_M0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Y6),
	EXYNOS4_GPIO_M1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_M0),
	EXYNOS4_GPIO_M2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_M1),
	EXYNOS4_GPIO_M3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_M2),
	EXYNOS4_GPIO_M4_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_M3),
	EXYNOS4_GPIO_X0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_M4),
	EXYNOS4_GPIO_X1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_X0),
	EXYNOS4_GPIO_X2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_X1),
	EXYNOS4_GPIO_X3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_X2),
	EXYNOS4_GPIO_Z_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_X3),
	EXYNOS4_GPIO_V0_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_Z),
	EXYNOS4_GPIO_V1_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_V0),
	EXYNOS4_GPIO_V2_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_V1),
	EXYNOS4_GPIO_V3_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_V2),
	EXYNOS4_GPIO_V4_START	= EXYNOS_GPIO_NEXT(EXYNOS4_GPIO_V3),
};

/* EXYNOS4 GPIO number definitions */

#define EXYNOS4_GPA0(_nr)	(EXYNOS4_GPIO_A0_START + (_nr))
#define EXYNOS4_GPA1(_nr)	(EXYNOS4_GPIO_A1_START + (_nr))
#define EXYNOS4_GPB(_nr)	(EXYNOS4_GPIO_B_START + (_nr))
#define EXYNOS4_GPC0(_nr)	(EXYNOS4_GPIO_C0_START + (_nr))
#define EXYNOS4_GPC1(_nr)	(EXYNOS4_GPIO_C1_START + (_nr))
#define EXYNOS4_GPD0(_nr)	(EXYNOS4_GPIO_D0_START + (_nr))
#define EXYNOS4_GPD1(_nr)	(EXYNOS4_GPIO_D1_START + (_nr))
#define EXYNOS4_GPE0(_nr)	(EXYNOS4_GPIO_E0_START + (_nr))
#define EXYNOS4_GPE1(_nr)	(EXYNOS4_GPIO_E1_START + (_nr))
#define EXYNOS4_GPE2(_nr)	(EXYNOS4_GPIO_E2_START + (_nr))
#define EXYNOS4_GPE3(_nr)	(EXYNOS4_GPIO_E3_START + (_nr))
#define EXYNOS4_GPE4(_nr)	(EXYNOS4_GPIO_E4_START + (_nr))
#define EXYNOS4_GPF0(_nr)	(EXYNOS4_GPIO_F0_START + (_nr))
#define EXYNOS4_GPF1(_nr)	(EXYNOS4_GPIO_F1_START + (_nr))
#define EXYNOS4_GPF2(_nr)	(EXYNOS4_GPIO_F2_START + (_nr))
#define EXYNOS4_GPF3(_nr)	(EXYNOS4_GPIO_F3_START + (_nr))
#define EXYNOS4_GPJ0(_nr)	(EXYNOS4_GPIO_J0_START + (_nr))
#define EXYNOS4_GPJ1(_nr)	(EXYNOS4_GPIO_J1_START + (_nr))
#define EXYNOS4_GPK0(_nr)	(EXYNOS4_GPIO_K0_START + (_nr))
#define EXYNOS4_GPK1(_nr)	(EXYNOS4_GPIO_K1_START + (_nr))
#define EXYNOS4_GPK2(_nr)	(EXYNOS4_GPIO_K2_START + (_nr))
#define EXYNOS4_GPK3(_nr)	(EXYNOS4_GPIO_K3_START + (_nr))
#define EXYNOS4_GPL0(_nr)	(EXYNOS4_GPIO_L0_START + (_nr))
#define EXYNOS4_GPL1(_nr)	(EXYNOS4_GPIO_L1_START + (_nr))
#define EXYNOS4_GPL2(_nr)	(EXYNOS4_GPIO_L2_START + (_nr))
#define EXYNOS4_GPY0(_nr)	(EXYNOS4_GPIO_Y0_START + (_nr))
#define EXYNOS4_GPY1(_nr)	(EXYNOS4_GPIO_Y1_START + (_nr))
#define EXYNOS4_GPY2(_nr)	(EXYNOS4_GPIO_Y2_START + (_nr))
#define EXYNOS4_GPY3(_nr)	(EXYNOS4_GPIO_Y3_START + (_nr))
#define EXYNOS4_GPY4(_nr)	(EXYNOS4_GPIO_Y4_START + (_nr))
#define EXYNOS4_GPY5(_nr)	(EXYNOS4_GPIO_Y5_START + (_nr))
#define EXYNOS4_GPY6(_nr)	(EXYNOS4_GPIO_Y6_START + (_nr))
#define EXYNOS4_GPM0(_nr)	(EXYNOS4_GPIO_M0_START + (_nr))
#define EXYNOS4_GPM1(_nr)	(EXYNOS4_GPIO_M1_START + (_nr))
#define EXYNOS4_GPM2(_nr)	(EXYNOS4_GPIO_M2_START + (_nr))
#define EXYNOS4_GPM3(_nr)	(EXYNOS4_GPIO_M3_START + (_nr))
#define EXYNOS4_GPM4(_nr)	(EXYNOS4_GPIO_M4_START + (_nr))
#define EXYNOS4_GPX0(_nr)	(EXYNOS4_GPIO_X0_START + (_nr))
#define EXYNOS4_GPX1(_nr)	(EXYNOS4_GPIO_X1_START + (_nr))
#define EXYNOS4_GPX2(_nr)	(EXYNOS4_GPIO_X2_START + (_nr))
#define EXYNOS4_GPX3(_nr)	(EXYNOS4_GPIO_X3_START + (_nr))
#define EXYNOS4_GPZ(_nr)	(EXYNOS4_GPIO_Z_START + (_nr))
#define EXYNOS4_GPV0(_nr)	(EXYNOS4_GPIO_V0_START + (_nr))
#define EXYNOS4_GPV1(_nr)	(EXYNOS4_GPIO_V1_START + (_nr))
#define EXYNOS4_GPV2(_nr)	(EXYNOS4_GPIO_V2_START + (_nr))
#define EXYNOS4_GPV3(_nr)	(EXYNOS4_GPIO_V3_START + (_nr))
#define EXYNOS4_GPV4(_nr)	(EXYNOS4_GPIO_V4_START + (_nr))

/* the end of the EXYNOS4 specific gpios */

#define EXYNOS4_GPIO_END	(EXYNOS4_GPV4(EXYNOS4_GPIO_V4_NR) + 1)

/* EXYNOS5 GPIO bank sizes */

#define EXYNOS5_GPIO_A0_NR	(8)
#define EXYNOS5_GPIO_A1_NR	(6)
#define EXYNOS5_GPIO_A2_NR	(8)
#define EXYNOS5_GPIO_B0_NR	(5)
#define EXYNOS5_GPIO_B1_NR	(5)
#define EXYNOS5_GPIO_B2_NR	(4)
#define EXYNOS5_GPIO_B3_NR	(4)
#define EXYNOS5_GPIO_C0_NR	(7)
#define EXYNOS5_GPIO_C1_NR	(4)
#define EXYNOS5_GPIO_C2_NR	(7)
#define EXYNOS5_GPIO_C3_NR	(7)
#define EXYNOS5_GPIO_D0_NR	(4)
#define EXYNOS5_GPIO_D1_NR	(8)
#define EXYNOS5_GPIO_Y0_NR	(6)
#define EXYNOS5_GPIO_Y1_NR	(4)
#define EXYNOS5_GPIO_Y2_NR	(6)
#define EXYNOS5_GPIO_Y3_NR	(8)
#define EXYNOS5_GPIO_Y4_NR	(8)
#define EXYNOS5_GPIO_Y5_NR	(8)
#define EXYNOS5_GPIO_Y6_NR	(8)
#define EXYNOS5_GPIO_C4_NR	(7)
#define EXYNOS5_GPIO_X0_NR	(8)
#define EXYNOS5_GPIO_X1_NR	(8)
#define EXYNOS5_GPIO_X2_NR	(8)
#define EXYNOS5_GPIO_X3_NR	(8)
#define EXYNOS5_GPIO_E0_NR	(8)
#define EXYNOS5_GPIO_E1_NR	(2)
#define EXYNOS5_GPIO_F0_NR	(4)
#define EXYNOS5_GPIO_F1_NR	(4)
#define EXYNOS5_GPIO_G0_NR	(8)
#define EXYNOS5_GPIO_G1_NR	(8)
#define EXYNOS5_GPIO_G2_NR	(2)
#define EXYNOS5_GPIO_H0_NR	(4)
#define EXYNOS5_GPIO_H1_NR	(8)
#define EXYNOS5_GPIO_V0_NR	(8)
#define EXYNOS5_GPIO_V1_NR	(8)
#define EXYNOS5_GPIO_V2_NR	(8)
#define EXYNOS5_GPIO_V3_NR	(8)
#define EXYNOS5_GPIO_V4_NR	(2)
#define EXYNOS5_GPIO_Z_NR	(7)

/* EXYNOS5 GPIO bank numbers */

enum exynos5_gpio_number {
	EXYNOS5_GPIO_A0_START		= 0,
	EXYNOS5_GPIO_A1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_A0),
	EXYNOS5_GPIO_A2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_A1),
	EXYNOS5_GPIO_B0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_A2),
	EXYNOS5_GPIO_B1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_B0),
	EXYNOS5_GPIO_B2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_B1),
	EXYNOS5_GPIO_B3_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_B2),
	EXYNOS5_GPIO_C0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_B3),
	EXYNOS5_GPIO_C1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_C0),
	EXYNOS5_GPIO_C2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_C1),
	EXYNOS5_GPIO_C3_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_C2),
	EXYNOS5_GPIO_D0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_C3),
	EXYNOS5_GPIO_D1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_D0),
	EXYNOS5_GPIO_Y0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_D1),
	EXYNOS5_GPIO_Y1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y0),
	EXYNOS5_GPIO_Y2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y1),
	EXYNOS5_GPIO_Y3_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y2),
	EXYNOS5_GPIO_Y4_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y3),
	EXYNOS5_GPIO_Y5_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y4),
	EXYNOS5_GPIO_Y6_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y5),
	EXYNOS5_GPIO_C4_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_Y6),
	EXYNOS5_GPIO_X0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_C4),
	EXYNOS5_GPIO_X1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_X0),
	EXYNOS5_GPIO_X2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_X1),
	EXYNOS5_GPIO_X3_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_X2),
	EXYNOS5_GPIO_E0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_X3),
	EXYNOS5_GPIO_E1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_E0),
	EXYNOS5_GPIO_F0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_E1),
	EXYNOS5_GPIO_F1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_F0),
	EXYNOS5_GPIO_G0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_F1),
	EXYNOS5_GPIO_G1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_G0),
	EXYNOS5_GPIO_G2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_G1),
	EXYNOS5_GPIO_H0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_G2),
	EXYNOS5_GPIO_H1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_H0),
	EXYNOS5_GPIO_V0_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_H1),
	EXYNOS5_GPIO_V1_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_V0),
	EXYNOS5_GPIO_V2_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_V1),
	EXYNOS5_GPIO_V3_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_V2),
	EXYNOS5_GPIO_V4_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_V3),
	EXYNOS5_GPIO_Z_START		= EXYNOS_GPIO_NEXT(EXYNOS5_GPIO_V4),
};

/* EXYNOS5 GPIO number definitions */

#define EXYNOS5_GPA0(_nr)	(EXYNOS5_GPIO_A0_START + (_nr))
#define EXYNOS5_GPA1(_nr)	(EXYNOS5_GPIO_A1_START + (_nr))
#define EXYNOS5_GPA2(_nr)	(EXYNOS5_GPIO_A2_START + (_nr))
#define EXYNOS5_GPB0(_nr)	(EXYNOS5_GPIO_B0_START + (_nr))
#define EXYNOS5_GPB1(_nr)	(EXYNOS5_GPIO_B1_START + (_nr))
#define EXYNOS5_GPB2(_nr)	(EXYNOS5_GPIO_B2_START + (_nr))
#define EXYNOS5_GPB3(_nr)	(EXYNOS5_GPIO_B3_START + (_nr))
#define EXYNOS5_GPC0(_nr)	(EXYNOS5_GPIO_C0_START + (_nr))
#define EXYNOS5_GPC1(_nr)	(EXYNOS5_GPIO_C1_START + (_nr))
#define EXYNOS5_GPC2(_nr)	(EXYNOS5_GPIO_C2_START + (_nr))
#define EXYNOS5_GPC3(_nr)	(EXYNOS5_GPIO_C3_START + (_nr))
#define EXYNOS5_GPD0(_nr)	(EXYNOS5_GPIO_D0_START + (_nr))
#define EXYNOS5_GPD1(_nr)	(EXYNOS5_GPIO_D1_START + (_nr))
#define EXYNOS5_GPY0(_nr)	(EXYNOS5_GPIO_Y0_START + (_nr))
#define EXYNOS5_GPY1(_nr)	(EXYNOS5_GPIO_Y1_START + (_nr))
#define EXYNOS5_GPY2(_nr)	(EXYNOS5_GPIO_Y2_START + (_nr))
#define EXYNOS5_GPY3(_nr)	(EXYNOS5_GPIO_Y3_START + (_nr))
#define EXYNOS5_GPY4(_nr)	(EXYNOS5_GPIO_Y4_START + (_nr))
#define EXYNOS5_GPY5(_nr)	(EXYNOS5_GPIO_Y5_START + (_nr))
#define EXYNOS5_GPY6(_nr)	(EXYNOS5_GPIO_Y6_START + (_nr))
#define EXYNOS5_GPC4(_nr)	(EXYNOS5_GPIO_C4_START + (_nr))
#define EXYNOS5_GPX0(_nr)	(EXYNOS5_GPIO_X0_START + (_nr))
#define EXYNOS5_GPX1(_nr)	(EXYNOS5_GPIO_X1_START + (_nr))
#define EXYNOS5_GPX2(_nr)	(EXYNOS5_GPIO_X2_START + (_nr))
#define EXYNOS5_GPX3(_nr)	(EXYNOS5_GPIO_X3_START + (_nr))
#define EXYNOS5_GPE0(_nr)	(EXYNOS5_GPIO_E0_START + (_nr))
#define EXYNOS5_GPE1(_nr)	(EXYNOS5_GPIO_E1_START + (_nr))
#define EXYNOS5_GPF0(_nr)	(EXYNOS5_GPIO_F0_START + (_nr))
#define EXYNOS5_GPF1(_nr)	(EXYNOS5_GPIO_F1_START + (_nr))
#define EXYNOS5_GPG0(_nr)	(EXYNOS5_GPIO_G0_START + (_nr))
#define EXYNOS5_GPG1(_nr)	(EXYNOS5_GPIO_G1_START + (_nr))
#define EXYNOS5_GPG2(_nr)	(EXYNOS5_GPIO_G2_START + (_nr))
#define EXYNOS5_GPH0(_nr)	(EXYNOS5_GPIO_H0_START + (_nr))
#define EXYNOS5_GPH1(_nr)	(EXYNOS5_GPIO_H1_START + (_nr))
#define EXYNOS5_GPV0(_nr)	(EXYNOS5_GPIO_V0_START + (_nr))
#define EXYNOS5_GPV1(_nr)	(EXYNOS5_GPIO_V1_START + (_nr))
#define EXYNOS5_GPV2(_nr)	(EXYNOS5_GPIO_V2_START + (_nr))
#define EXYNOS5_GPV3(_nr)	(EXYNOS5_GPIO_V3_START + (_nr))
#define EXYNOS5_GPV4(_nr)	(EXYNOS5_GPIO_V4_START + (_nr))
#define EXYNOS5_GPZ(_nr)	(EXYNOS5_GPIO_Z_START + (_nr))

/* the end of the EXYNOS5 specific gpios */

#define EXYNOS5_GPIO_END	(EXYNOS5_GPZ(EXYNOS5_GPIO_Z_NR) + 1)

/* EXYNOS5410 GPIO bank sizes */

#define EXYNOS5410_GPIO_J0_NR	(5)
#define EXYNOS5410_GPIO_J1_NR	(8)
#define EXYNOS5410_GPIO_J2_NR	(8)
#define EXYNOS5410_GPIO_J3_NR	(8)
#define EXYNOS5410_GPIO_J4_NR	(2)
#define EXYNOS5410_GPIO_K0_NR	(8)
#define EXYNOS5410_GPIO_K1_NR	(8)
#define EXYNOS5410_GPIO_K2_NR	(8)
#define EXYNOS5410_GPIO_K3_NR	(7)
#define EXYNOS5410_GPIO_A0_NR	(8)
#define EXYNOS5410_GPIO_A1_NR	(6)
#define EXYNOS5410_GPIO_A2_NR	(8)
#define EXYNOS5410_GPIO_B0_NR	(5)
#define EXYNOS5410_GPIO_B1_NR	(5)
#define EXYNOS5410_GPIO_B2_NR	(4)
#define EXYNOS5410_GPIO_B3_NR	(4)
#define EXYNOS5410_GPIO_C0_NR	(7)
#define EXYNOS5410_GPIO_C3_NR	(4)
#define EXYNOS5410_GPIO_C1_NR	(7)
#define EXYNOS5410_GPIO_C2_NR	(7)
#define EXYNOS5410_GPIO_M5_NR	(2)
#define EXYNOS5410_GPIO_D1_NR	(8)
#define EXYNOS5410_GPIO_E0_NR	(8)
#define EXYNOS5410_GPIO_E1_NR	(2)
#define EXYNOS5410_GPIO_F0_NR	(6)
#define EXYNOS5410_GPIO_F1_NR	(8)
#define EXYNOS5410_GPIO_G0_NR	(8)
#define EXYNOS5410_GPIO_G1_NR	(8)
#define EXYNOS5410_GPIO_G2_NR	(2)
#define EXYNOS5410_GPIO_H0_NR	(4)
#define EXYNOS5410_GPIO_H1_NR	(8)
#define EXYNOS5410_GPIO_M7_NR	(8)
#define EXYNOS5410_GPIO_Y0_NR	(6)
#define EXYNOS5410_GPIO_Y1_NR	(4)
#define EXYNOS5410_GPIO_Y2_NR	(6)
#define EXYNOS5410_GPIO_Y3_NR	(8)
#define EXYNOS5410_GPIO_Y4_NR	(8)
#define EXYNOS5410_GPIO_Y5_NR	(8)
#define EXYNOS5410_GPIO_Y6_NR	(8)
#define EXYNOS5410_GPIO_Y7_NR	(8)
#define EXYNOS5410_GPIO_X0_NR	(8)
#define EXYNOS5410_GPIO_X1_NR	(8)
#define EXYNOS5410_GPIO_X2_NR	(8)
#define EXYNOS5410_GPIO_X3_NR	(8)
#define EXYNOS5410_GPIO_V0_NR	(8)
#define EXYNOS5410_GPIO_V1_NR	(8)
#define EXYNOS5410_GPIO_V2_NR	(8)
#define EXYNOS5410_GPIO_V3_NR	(8)
#define EXYNOS5410_GPIO_V4_NR	(2)
#define EXYNOS5410_GPIO_Z_NR	(7)

/* EXYNOS5410 GPIO bank numbers */

enum exynos5410_gpio_number {
	EXYNOS5410_GPIO_J0_START	= 0,
	EXYNOS5410_GPIO_J1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_J0),
	EXYNOS5410_GPIO_J2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_J1),
	EXYNOS5410_GPIO_J3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_J2),
	EXYNOS5410_GPIO_J4_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_J3),
	EXYNOS5410_GPIO_K0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_J4),
	EXYNOS5410_GPIO_K1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_K0),
	EXYNOS5410_GPIO_K2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_K1),
	EXYNOS5410_GPIO_K3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_K2),
	EXYNOS5410_GPIO_A0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_K3),
	EXYNOS5410_GPIO_A1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_A0),
	EXYNOS5410_GPIO_A2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_A1),
	EXYNOS5410_GPIO_B0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_A2),
	EXYNOS5410_GPIO_B1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_B0),
	EXYNOS5410_GPIO_B2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_B1),
	EXYNOS5410_GPIO_B3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_B2),
	EXYNOS5410_GPIO_C0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_B3),
	EXYNOS5410_GPIO_C3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_C0),
	EXYNOS5410_GPIO_C1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_C3),
	EXYNOS5410_GPIO_C2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_C1),
	EXYNOS5410_GPIO_M5_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_C2),
	EXYNOS5410_GPIO_D1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_M5),
	EXYNOS5410_GPIO_E0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_D1),
	EXYNOS5410_GPIO_E1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_E0),
	EXYNOS5410_GPIO_F0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_E1),
	EXYNOS5410_GPIO_F1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_F0),
	EXYNOS5410_GPIO_G0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_F1),
	EXYNOS5410_GPIO_G1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_G0),
	EXYNOS5410_GPIO_G2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_G1),
	EXYNOS5410_GPIO_H0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_G2),
	EXYNOS5410_GPIO_H1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_H0),
	EXYNOS5410_GPIO_M7_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_H1),
	EXYNOS5410_GPIO_Y0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_M7),
	EXYNOS5410_GPIO_Y1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y0),
	EXYNOS5410_GPIO_Y2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y1),
	EXYNOS5410_GPIO_Y3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y2),
	EXYNOS5410_GPIO_Y4_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y3),
	EXYNOS5410_GPIO_Y5_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y4),
	EXYNOS5410_GPIO_Y6_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y5),
	EXYNOS5410_GPIO_Y7_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y6),
	EXYNOS5410_GPIO_X0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_Y7),
	EXYNOS5410_GPIO_X1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_X0),
	EXYNOS5410_GPIO_X2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_X1),
	EXYNOS5410_GPIO_X3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_X2),
	EXYNOS5410_GPIO_V0_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_X3),
	EXYNOS5410_GPIO_V1_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_V0),
	EXYNOS5410_GPIO_V2_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_V1),
	EXYNOS5410_GPIO_V3_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_V2),
	EXYNOS5410_GPIO_V4_START	= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_V3),
	EXYNOS5410_GPIO_Z_START		= EXYNOS_GPIO_NEXT(EXYNOS5410_GPIO_V4),
};

/* EXYNOS5410 GPIO number definitions */

#define EXYNOS5410_GPJ0(_nr)	(EXYNOS5410_GPIO_J0_START + (_nr))
#define EXYNOS5410_GPJ1(_nr)	(EXYNOS5410_GPIO_J1_START + (_nr))
#define EXYNOS5410_GPJ2(_nr)	(EXYNOS5410_GPIO_J2_START + (_nr))
#define EXYNOS5410_GPJ3(_nr)	(EXYNOS5410_GPIO_J3_START + (_nr))
#define EXYNOS5410_GPJ4(_nr)	(EXYNOS5410_GPIO_J4_START + (_nr))
#define EXYNOS5410_GPK0(_nr)	(EXYNOS5410_GPIO_K0_START + (_nr))
#define EXYNOS5410_GPK1(_nr)	(EXYNOS5410_GPIO_K1_START + (_nr))
#define EXYNOS5410_GPK2(_nr)	(EXYNOS5410_GPIO_K2_START + (_nr))
#define EXYNOS5410_GPK3(_nr)	(EXYNOS5410_GPIO_K3_START + (_nr))
#define EXYNOS5410_GPA0(_nr)	(EXYNOS5410_GPIO_A0_START + (_nr))
#define EXYNOS5410_GPA1(_nr)	(EXYNOS5410_GPIO_A1_START + (_nr))
#define EXYNOS5410_GPA2(_nr)	(EXYNOS5410_GPIO_A2_START + (_nr))
#define EXYNOS5410_GPB0(_nr)	(EXYNOS5410_GPIO_B0_START + (_nr))
#define EXYNOS5410_GPB1(_nr)	(EXYNOS5410_GPIO_B1_START + (_nr))
#define EXYNOS5410_GPB2(_nr)	(EXYNOS5410_GPIO_B2_START + (_nr))
#define EXYNOS5410_GPB3(_nr)	(EXYNOS5410_GPIO_B3_START + (_nr))
#define EXYNOS5410_GPC0(_nr)	(EXYNOS5410_GPIO_C0_START + (_nr))
#define EXYNOS5410_GPC3(_nr)	(EXYNOS5410_GPIO_C3_START + (_nr))
#define EXYNOS5410_GPC1(_nr)	(EXYNOS5410_GPIO_C1_START + (_nr))
#define EXYNOS5410_GPC2(_nr)	(EXYNOS5410_GPIO_C2_START + (_nr))
#define EXYNOS5410_GPM5(_nr)	(EXYNOS5410_GPIO_M5_START + (_nr))
#define EXYNOS5410_GPD1(_nr)	(EXYNOS5410_GPIO_D1_START + (_nr))
#define EXYNOS5410_GPE0(_nr)	(EXYNOS5410_GPIO_E0_START + (_nr))
#define EXYNOS5410_GPE1(_nr)	(EXYNOS5410_GPIO_E1_START + (_nr))
#define EXYNOS5410_GPF0(_nr)	(EXYNOS5410_GPIO_F0_START + (_nr))
#define EXYNOS5410_GPF1(_nr)	(EXYNOS5410_GPIO_F1_START + (_nr))
#define EXYNOS5410_GPG0(_nr)	(EXYNOS5410_GPIO_G0_START + (_nr))
#define EXYNOS5410_GPG1(_nr)	(EXYNOS5410_GPIO_G1_START + (_nr))
#define EXYNOS5410_GPG2(_nr)	(EXYNOS5410_GPIO_G2_START + (_nr))
#define EXYNOS5410_GPH0(_nr)	(EXYNOS5410_GPIO_H0_START + (_nr))
#define EXYNOS5410_GPH1(_nr)	(EXYNOS5410_GPIO_H1_START + (_nr))
#define EXYNOS5410_GPM7(_nr)	(EXYNOS5410_GPIO_M7_START + (_nr))
#define EXYNOS5410_GPY0(_nr)	(EXYNOS5410_GPIO_Y0_START + (_nr))
#define EXYNOS5410_GPY1(_nr)	(EXYNOS5410_GPIO_Y1_START + (_nr))
#define EXYNOS5410_GPY2(_nr)	(EXYNOS5410_GPIO_Y2_START + (_nr))
#define EXYNOS5410_GPY3(_nr)	(EXYNOS5410_GPIO_Y3_START + (_nr))
#define EXYNOS5410_GPY4(_nr)	(EXYNOS5410_GPIO_Y4_START + (_nr))
#define EXYNOS5410_GPY5(_nr)	(EXYNOS5410_GPIO_Y5_START + (_nr))
#define EXYNOS5410_GPY6(_nr)	(EXYNOS5410_GPIO_Y6_START + (_nr))
#define EXYNOS5410_GPY7(_nr)	(EXYNOS5410_GPIO_Y7_START + (_nr))
#define EXYNOS5410_GPX0(_nr)	(EXYNOS5410_GPIO_X0_START + (_nr))
#define EXYNOS5410_GPX1(_nr)	(EXYNOS5410_GPIO_X1_START + (_nr))
#define EXYNOS5410_GPX2(_nr)	(EXYNOS5410_GPIO_X2_START + (_nr))
#define EXYNOS5410_GPX3(_nr)	(EXYNOS5410_GPIO_X3_START + (_nr))
#define EXYNOS5410_GPV0(_nr)	(EXYNOS5410_GPIO_V0_START + (_nr))
#define EXYNOS5410_GPV1(_nr)	(EXYNOS5410_GPIO_V1_START + (_nr))
#define EXYNOS5410_GPV2(_nr)	(EXYNOS5410_GPIO_V2_START + (_nr))
#define EXYNOS5410_GPV3(_nr)	(EXYNOS5410_GPIO_V3_START + (_nr))
#define EXYNOS5410_GPV4(_nr)	(EXYNOS5410_GPIO_V4_START + (_nr))
#define EXYNOS5410_GPZ(_nr)	(EXYNOS5410_GPIO_Z_START + (_nr))

/* the end of the EXYNOS5410 specific gpios */

#define EXYNOS5410_GPIO_END	(EXYNOS5410_GPZ(EXYNOS5410_GPIO_Z_NR) + 1)

/* EXYNOS5420 GPIO bank sizes */

#define EXYNOS5420_GPIO_A0_NR	(8)
#define EXYNOS5420_GPIO_A1_NR	(6)
#define EXYNOS5420_GPIO_A2_NR	(8)
#define EXYNOS5420_GPIO_B0_NR	(5)
#define EXYNOS5420_GPIO_B1_NR	(5)
#define EXYNOS5420_GPIO_B2_NR	(4)
#define EXYNOS5420_GPIO_B3_NR	(8)
#define EXYNOS5420_GPIO_B4_NR	(2)
#define EXYNOS5420_GPIO_C0_NR	(8)
#define EXYNOS5420_GPIO_C1_NR	(8)
#define EXYNOS5420_GPIO_C2_NR	(7)
#define EXYNOS5420_GPIO_C3_NR	(4)
#define EXYNOS5420_GPIO_C4_NR	(2)
#define EXYNOS5420_GPIO_D1_NR	(8)
#define EXYNOS5420_GPIO_H0_NR	(8)
#define EXYNOS5420_GPIO_J4_NR	(4)
#define EXYNOS5420_GPIO_Y0_NR	(6)
#define EXYNOS5420_GPIO_Y1_NR	(4)
#define EXYNOS5420_GPIO_Y2_NR	(6)
#define EXYNOS5420_GPIO_Y3_NR	(8)
#define EXYNOS5420_GPIO_Y4_NR	(8)
#define EXYNOS5420_GPIO_Y5_NR	(8)
#define EXYNOS5420_GPIO_Y6_NR	(8)
#define EXYNOS5420_GPIO_Y7_NR	(8)
#define EXYNOS5420_GPIO_X0_NR	(8)
#define EXYNOS5420_GPIO_X1_NR	(8)
#define EXYNOS5420_GPIO_X2_NR	(8)
#define EXYNOS5420_GPIO_X3_NR	(8)
#define EXYNOS5420_GPIO_E0_NR	(8)
#define EXYNOS5420_GPIO_E1_NR	(2)
#define EXYNOS5420_GPIO_F0_NR	(6)
#define EXYNOS5420_GPIO_F1_NR	(8)
#define EXYNOS5420_GPIO_G0_NR	(8)
#define EXYNOS5420_GPIO_G1_NR	(8)
#define EXYNOS5420_GPIO_G2_NR	(2)
#define EXYNOS5420_GPIO_Z_NR	(7)

/* EXYNOS5420 GPIO bank numbers */

enum exynos5420_gpio_number {
	EXYNOS5420_GPIO_A0_START	= 0,
	EXYNOS5420_GPIO_A1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_A0),
	EXYNOS5420_GPIO_A2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_A1),
	EXYNOS5420_GPIO_B0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_A2),
	EXYNOS5420_GPIO_B1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_B0),
	EXYNOS5420_GPIO_B2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_B1),
	EXYNOS5420_GPIO_B3_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_B2),
	EXYNOS5420_GPIO_B4_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_B3),
	EXYNOS5420_GPIO_C0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_B4),
	EXYNOS5420_GPIO_C1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_C0),
	EXYNOS5420_GPIO_C2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_C1),
	EXYNOS5420_GPIO_C3_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_C2),
	EXYNOS5420_GPIO_C4_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_C3),
	EXYNOS5420_GPIO_D1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_C4),
	EXYNOS5420_GPIO_H0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_D1),
	EXYNOS5420_GPIO_J4_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_H0),
	EXYNOS5420_GPIO_Y0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_J4),
	EXYNOS5420_GPIO_Y1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y0),
	EXYNOS5420_GPIO_Y2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y1),
	EXYNOS5420_GPIO_Y3_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y2),
	EXYNOS5420_GPIO_Y4_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y3),
	EXYNOS5420_GPIO_Y5_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y4),
	EXYNOS5420_GPIO_Y6_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y5),
	EXYNOS5420_GPIO_Y7_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y6),
	EXYNOS5420_GPIO_X0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_Y7),
	EXYNOS5420_GPIO_X1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_X0),
	EXYNOS5420_GPIO_X2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_X1),
	EXYNOS5420_GPIO_X3_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_X2),
	EXYNOS5420_GPIO_E0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_X3),
	EXYNOS5420_GPIO_E1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_E0),
	EXYNOS5420_GPIO_F0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_E1),
	EXYNOS5420_GPIO_F1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_F0),
	EXYNOS5420_GPIO_G0_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_F1),
	EXYNOS5420_GPIO_G1_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_G0),
	EXYNOS5420_GPIO_G2_START	= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_G1),
	EXYNOS5420_GPIO_Z_START		= EXYNOS_GPIO_NEXT(EXYNOS5420_GPIO_G2),
};

/* EXYNOS5420 GPIO number definitions */

#define EXYNOS5420_GPA0(_nr)	(EXYNOS5420_GPIO_A0_START + (_nr))
#define EXYNOS5420_GPA1(_nr)	(EXYNOS5420_GPIO_A1_START + (_nr))
#define EXYNOS5420_GPA2(_nr)	(EXYNOS5420_GPIO_A2_START + (_nr))
#define EXYNOS5420_GPB0(_nr)	(EXYNOS5420_GPIO_B0_START + (_nr))
#define EXYNOS5420_GPB1(_nr)	(EXYNOS5420_GPIO_B1_START + (_nr))
#define EXYNOS5420_GPB2(_nr)	(EXYNOS5420_GPIO_B2_START + (_nr))
#define EXYNOS5420_GPB3(_nr)	(EXYNOS5420_GPIO_B3_START + (_nr))
#define EXYNOS5420_GPB4(_nr)	(EXYNOS5420_GPIO_B4_START + (_nr))
#define EXYNOS5420_GPC0(_nr)	(EXYNOS5420_GPIO_C0_START + (_nr))
#define EXYNOS5420_GPC1(_nr)	(EXYNOS5420_GPIO_C1_START + (_nr))
#define EXYNOS5420_GPC2(_nr)	(EXYNOS5420_GPIO_C2_START + (_nr))
#define EXYNOS5420_GPC3(_nr)	(EXYNOS5420_GPIO_C3_START + (_nr))
#define EXYNOS5420_GPC4(_nr)	(EXYNOS5420_GPIO_C4_START + (_nr))
#define EXYNOS5420_GPD1(_nr)	(EXYNOS5420_GPIO_D1_START + (_nr))
#define EXYNOS5420_GPH0(_nr)	(EXYNOS5420_GPIO_H0_START + (_nr))
#define EXYNOS5420_GPJ4(_nr)	(EXYNOS5420_GPIO_J4_START + (_nr))
#define EXYNOS5420_GPY0(_nr)	(EXYNOS5420_GPIO_Y0_START + (_nr))
#define EXYNOS5420_GPY1(_nr)	(EXYNOS5420_GPIO_Y1_START + (_nr))
#define EXYNOS5420_GPY2(_nr)	(EXYNOS5420_GPIO_Y2_START + (_nr))
#define EXYNOS5420_GPY3(_nr)	(EXYNOS5420_GPIO_Y3_START + (_nr))
#define EXYNOS5420_GPY4(_nr)	(EXYNOS5420_GPIO_Y4_START + (_nr))
#define EXYNOS5420_GPY5(_nr)	(EXYNOS5420_GPIO_Y5_START + (_nr))
#define EXYNOS5420_GPY6(_nr)	(EXYNOS5420_GPIO_Y6_START + (_nr))
#define EXYNOS5420_GPY7(_nr)	(EXYNOS5420_GPIO_Y7_START + (_nr))
#define EXYNOS5420_GPX0(_nr)	(EXYNOS5420_GPIO_X0_START + (_nr))
#define EXYNOS5420_GPX1(_nr)	(EXYNOS5420_GPIO_X1_START + (_nr))
#define EXYNOS5420_GPX2(_nr)	(EXYNOS5420_GPIO_X2_START + (_nr))
#define EXYNOS5420_GPX3(_nr)	(EXYNOS5420_GPIO_X3_START + (_nr))
#define EXYNOS5420_GPE0(_nr)	(EXYNOS5420_GPIO_E0_START + (_nr))
#define EXYNOS5420_GPE1(_nr)	(EXYNOS5420_GPIO_E1_START + (_nr))
#define EXYNOS5420_GPF0(_nr)	(EXYNOS5420_GPIO_F0_START + (_nr))
#define EXYNOS5420_GPF1(_nr)	(EXYNOS5420_GPIO_F1_START + (_nr))
#define EXYNOS5420_GPG0(_nr)	(EXYNOS5420_GPIO_G0_START + (_nr))
#define EXYNOS5420_GPG1(_nr)	(EXYNOS5420_GPIO_G1_START + (_nr))
#define EXYNOS5420_GPG2(_nr)	(EXYNOS5420_GPIO_G2_START + (_nr))
#define EXYNOS5420_GPZ(_nr)	(EXYNOS5420_GPIO_Z_START + (_nr))

/* the end of the EXYNOS5410 specific gpios */

#define EXYNOS5420_GPIO_END	(EXYNOS5420_GPZ(EXYNOS5420_GPIO_Z_NR) + 1)

/* actually, EXYNOS5410_GPIO_END is the biggest one */

#if defined(CONFIG_SOC_EXYNOS5410)
#define S3C_GPIO_END		(EXYNOS5410_GPIO_END)
#elif defined(CONFIG_SOC_EXYNOS5420)
#define S3C_GPIO_END		(EXYNOS5420_GPIO_END)
#else
#define S3C_GPIO_END		(EXYNOS5_GPIO_END > EXYNOS4_GPIO_END ? \
				 EXYNOS5_GPIO_END : EXYNOS4_GPIO_END)
#endif

/* define the number of gpios */

#define ARCH_NR_GPIOS		(CONFIG_SAMSUNG_GPIO_EXTRA + S3C_GPIO_END)

static inline int irq_to_gpio(unsigned int irq)
{
	if (soc_is_exynos5250()) {
		switch (irq) {
		case IRQ_EINT(0) ... IRQ_EINT(7):
			return EXYNOS5_GPX0(0) + irq - IRQ_EINT(0);
		case IRQ_EINT(8) ... IRQ_EINT(15):
			return EXYNOS5_GPX1(0) + irq - IRQ_EINT(8);
		case IRQ_EINT(16) ... IRQ_EINT(23):
			return EXYNOS5_GPX2(0) + irq - IRQ_EINT(16);
		case IRQ_EINT(24) ... IRQ_EINT(31):
			return EXYNOS5_GPX3(0) + irq - IRQ_EINT(24);
		}
	} else if (soc_is_exynos5410()) {
		switch (irq) {
		case IRQ_EINT(0) ... IRQ_EINT(7):
			return EXYNOS5410_GPX0(0) + irq - IRQ_EINT(0);
		case IRQ_EINT(8) ... IRQ_EINT(15):
			return EXYNOS5410_GPX1(0) + irq - IRQ_EINT(8);
		case IRQ_EINT(16) ... IRQ_EINT(23):
			return EXYNOS5410_GPX2(0) + irq - IRQ_EINT(16);
		case IRQ_EINT(24) ... IRQ_EINT(31):
			return EXYNOS5410_GPX3(0) + irq - IRQ_EINT(24);
		}
	} else if (soc_is_exynos5420()) {
		switch (irq) {
		case IRQ_EINT(0) ... IRQ_EINT(7):
			return EXYNOS5420_GPX0(0) + irq - IRQ_EINT(0);
		case IRQ_EINT(8) ... IRQ_EINT(15):
			return EXYNOS5420_GPX1(0) + irq - IRQ_EINT(8);
		case IRQ_EINT(16) ... IRQ_EINT(23):
			return EXYNOS5420_GPX2(0) + irq - IRQ_EINT(16);
		case IRQ_EINT(24) ... IRQ_EINT(31):
			return EXYNOS5420_GPX3(0) + irq - IRQ_EINT(24);
	        }
        } else {
		switch (irq) {
		case IRQ_EINT(0) ... IRQ_EINT(7):
			return EXYNOS4_GPX0(0) + irq - IRQ_EINT(0);
		case IRQ_EINT(8) ... IRQ_EINT(15):
			return EXYNOS4_GPX1(0) + irq - IRQ_EINT(8);
		case IRQ_EINT(16) ... IRQ_EINT(23):
			return EXYNOS4_GPX2(0) + irq - IRQ_EINT(16);
		case IRQ_EINT(24) ... IRQ_EINT(31):
			return EXYNOS4_GPX3(0) + irq - IRQ_EINT(24);
		}
	}
	return -EINVAL;
}

#endif /* __ASM_ARCH_GPIO_H */

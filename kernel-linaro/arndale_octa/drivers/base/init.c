/*
 * Copyright (c) 2002-3 Patrick Mochel
 * Copyright (c) 2002-3 Open Source Development Labs
 *
 * This file is released under the GPLv2
 */

#include <linux/device.h>
#include <linux/init.h>
#include <linux/memory.h>

#include "base.h"

/**
 * driver_init - initialize driver model.
 *
 * Call the driver model init functions to initialize their
 * subsystems. Called early from init/main.c.
 */
void __init driver_init(void)
{
	/* These are the core pieces */
	/*
		��ʼ��devptmpfs�ļ�ϵͳ�����������豸������ļ�ϵͳ��������ǵ��豸�ڵ�
		����ļ�ϵͳ�������ں��ڹ����ļ�ϵͳ֮���Զ����ص�/dev�£�Ҳ�������ļ�ϵͳ�������ű����ֶ�����
	*/
	devtmpfs_init();
	/*
		��ʼ������ģ���еĲ�����ϵͳ��kobject
		devices
		dev
		dev/block
		dev/char
	*/
	devices_init();
	buses_init();//��ʼ������ģ���е�bus��ϵͳ
	classes_init();//��ʼ������ģ���е�class��ϵͳ
	firmware_init();//��ʼ������ģ���е�firmware��ϵͳ
	hypervisor_init();//��ʼ������ģ���е�hypervisor��ϵͳ

	/* These are also core pieces, but must come after the
	 * core core pieces.
	 */
	platform_bus_init();//��ʼ��bus/platform��ϵͳ
	cpu_dev_init();//��ʼ��devices/system/cpu��ϵͳ
	memory_dev_init();///��ʼ��devices/system/memory��ϵͳ
	container_dev_init();//��ʼ��container
}

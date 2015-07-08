/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2009 coresystems GmbH
 * Copyright (C) 2013 Google, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc.
 */

#ifndef _CBMEM_ID_H_
#define _CBMEM_ID_H_

#define CBMEM_ID_ACPI		0x41435049
#define CBMEM_ID_ACPI_GNVS	0x474e5653
#define CBMEM_ID_ACPI_GNVS_PTR	0x474e5650
#define CBMEM_ID_AGESA_RUNTIME	0x41474553
#define CBMEM_ID_AMDMCT_MEMINFO 0x494D454E
#define CBMEM_ID_CAR_GLOBALS	0xcac4e6a3
#define CBMEM_ID_CBTABLE	0x43425442
#define CBMEM_ID_CONSOLE	0x434f4e53
#define CBMEM_ID_COVERAGE	0x47434f56
#define CBMEM_ID_EHCI_DEBUG	0xe4c1deb9
#define CBMEM_ID_ELOG		0x454c4f47
#define CBMEM_ID_FREESPACE	0x46524545
#define CBMEM_ID_FSP_RESERVED_MEMORY 0x46535052
#define CBMEM_ID_FSP_RUNTIME	0x52505346
#define CBMEM_ID_GDT		0x4c474454
#define CBMEM_ID_HOB_POINTER	0x484f4221
#define CBMEM_ID_IGD_OPREGION	0x4f444749
#define CBMEM_ID_IMD_ROOT	0xff4017ff
#define CBMEM_ID_IMD_SMALL	0x53a11439
#define CBMEM_ID_MEMINFO	0x494D454D
#define CBMEM_ID_MPTABLE	0x534d5054
#define CBMEM_ID_MRCDATA	0x4d524344
#define CBMEM_ID_MTC		0xcb31d31c
#define CBMEM_ID_NONE		0x00000000
#define CBMEM_ID_PIRQ		0x49525154
#define CBMEM_ID_POWER_STATE	0x50535454
#define CBMEM_ID_RAM_OOPS	0x05430095
#define CBMEM_ID_RAMSTAGE	0x9a357a9e
#define CBMEM_ID_RAMSTAGE_CACHE	0x9a3ca54e
#define CBMEM_ID_REFCODE	0x04efc0de
#define CBMEM_ID_REFCODE_CACHE	0x4efc0de5
#define CBMEM_ID_RESUME		0x5245534d
#define CBMEM_ID_RESUME_SCRATCH	0x52455343
#define CBMEM_ID_ROMSTAGE_INFO	0x47545352
#define CBMEM_ID_ROMSTAGE_RAM_STACK 0x90357ac4
#define CBMEM_ID_ROOT		0xff4007ff
#define CBMEM_ID_SMBIOS         0x534d4254
#define CBMEM_ID_SMM_SAVE_SPACE	0x07e9acee
#define CBMEM_ID_SPINTABLE	0x59175917
#define CBMEM_ID_STAGEx_META	0x57a9e000
#define CBMEM_ID_STAGEx_CACHE	0x57a9e100
#define CBMEM_ID_TCPA_LOG	0x54435041
#define CBMEM_ID_TIMESTAMP	0x54494d45
#define CBMEM_ID_VBOOT_HANDOFF	0x780074f0
#define CBMEM_ID_VBOOT_WORKBUF	0x78007343
#define CBMEM_ID_WIFI_CALIBRATION 0x57494649

#define CBMEM_ID_TO_NAME_TABLE				 \
	{ CBMEM_ID_ACPI,		"ACPI       " }, \
	{ CBMEM_ID_ACPI_GNVS,		"ACPI GNVS  " }, \
	{ CBMEM_ID_ACPI_GNVS_PTR,	"GNVS PTR   " }, \
	{ CBMEM_ID_AGESA_RUNTIME,	"AGESA RSVD " }, \
	{ CBMEM_ID_AMDMCT_MEMINFO,	"AMDMEM INFO" }, \
	{ CBMEM_ID_CAR_GLOBALS,		"CAR GLOBALS" }, \
	{ CBMEM_ID_CBTABLE,		"COREBOOT   " }, \
	{ CBMEM_ID_CONSOLE,		"CONSOLE    " }, \
	{ CBMEM_ID_COVERAGE,		"COVERAGE   " }, \
	{ CBMEM_ID_EHCI_DEBUG,		"USBDEBUG   " }, \
	{ CBMEM_ID_ELOG,		"ELOG       " }, \
	{ CBMEM_ID_FREESPACE,		"FREE SPACE " }, \
	{ CBMEM_ID_FSP_RESERVED_MEMORY, "FSP MEMORY " }, \
	{ CBMEM_ID_FSP_RUNTIME,		"FSP RUNTIME" }, \
	{ CBMEM_ID_GDT,			"GDT        " }, \
	{ CBMEM_ID_IMD_ROOT,		"IMD ROOT   " }, \
	{ CBMEM_ID_IMD_SMALL,		"IMD SMALL  " }, \
	{ CBMEM_ID_MEMINFO,		"MEM INFO   " }, \
	{ CBMEM_ID_MPTABLE,		"SMP TABLE  " }, \
	{ CBMEM_ID_MRCDATA,		"MRC DATA   " }, \
	{ CBMEM_ID_MTC,			"MTC        " }, \
	{ CBMEM_ID_PIRQ,		"IRQ TABLE  " }, \
	{ CBMEM_ID_POWER_STATE,		"POWER STATE" }, \
	{ CBMEM_ID_RAM_OOPS,		"RAMOOPS    " }, \
	{ CBMEM_ID_RAMSTAGE_CACHE,	"RAMSTAGE $ " }, \
	{ CBMEM_ID_RAMSTAGE,		"RAMSTAGE   " }, \
	{ CBMEM_ID_REFCODE_CACHE,	"REFCODE $  " }, \
	{ CBMEM_ID_REFCODE,		"REFCODE    " }, \
	{ CBMEM_ID_RESUME,		"ACPI RESUME" }, \
	{ CBMEM_ID_RESUME_SCRATCH,	"ACPISCRATCH" }, \
	{ CBMEM_ID_ROMSTAGE_INFO,	"ROMSTAGE   " }, \
	{ CBMEM_ID_ROMSTAGE_RAM_STACK,	"ROMSTG STCK" }, \
	{ CBMEM_ID_ROOT,		"CBMEM ROOT " }, \
	{ CBMEM_ID_SMBIOS,		"SMBIOS     " }, \
	{ CBMEM_ID_SMM_SAVE_SPACE,	"SMM BACKUP " }, \
	{ CBMEM_ID_SPINTABLE,		"SPIN TABLE " }, \
	{ CBMEM_ID_TIMESTAMP,		"TIME STAMP " }, \
	{ CBMEM_ID_VBOOT_HANDOFF,	"VBOOT      " }, \
	{ CBMEM_ID_VBOOT_WORKBUF,	"VBOOT WORK " }, \
	{ CBMEM_ID_WIFI_CALIBRATION,	"WIFI CLBR  " },
#endif /* _CBMEM_ID_H_ */

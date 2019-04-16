/*
 * (C) Copyright 2018-2019
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef _P3450_PORG_H
#define _P3450_PORG_H

#include <linux/sizes.h>

#include "tegra210-common.h"

/* High-level configuration options */
#define CONFIG_TEGRA_BOARD_STRING	"NVIDIA P3450-PORG"

/* Board-specific serial config */
#define CONFIG_TEGRA_ENABLE_UARTA

/* I2C */
#define CONFIG_SYS_I2C_TEGRA
#define CONFIG_SYS_VI_I2C_TEGRA

/* SD/MMC */
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_TEGRA_MMC

/* Only MMC1 for now, add USB/NET in later when supported */
#define BOOT_TARGET_DEVICES(func) \
	func(MMC, mmc, 1)

/* Environment s/b at end of SPI, fix it later */
#define CONFIG_ENV_IS_NOWHERE

/* SPI */
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#define CONFIG_SF_DEFAULT_SPEED		24000000
#define CONFIG_SPI_FLASH_SIZE		(4 << 20)

/* USB2.0 Host support */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_TEGRA

/* PCI host support */
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_CMD_PCI

/* Android fastboot support */
#define CONFIG_CMD_FASTBOOT
#define CONFIG_USB_FASTBOOT_BUF_SIZE	  0x40000000
#define CONFIG_USB_FASTBOOT_BUF_ADDR	  (NV_PA_SDRAM_BASE + 0x10000000)

/* Android bootimg support */
#define CONFIG_CMD_BOOTA
#define CONFIG_ANDROID_BOOT_IMAGE
#define CONFIG_CMD_BOOTA_BOOT_PART	      "LNX"
#define CONFIG_CMD_BOOTA_RECOVERY_PART	  "SOS"
#define CONFIG_CMD_BOOTA_DT_PART	      "DTB"
#define CONFIG_ANDROID_DT_HDR_BUFF	      (NV_PA_SDRAM_BASE + 0x03000000)
#define CONFIG_ANDROID_BOOT_HDR_BUFF	  (NV_PA_SDRAM_BASE + 0x04000000)
#define BOARD_EXTRA_ENV_SETTINGS \
	"bootargs_append=" \
	"init=init androidboot.secureos=tlk earlycon=uart8250,mmio32,0x70006000 " \
	"androidboot.modem=none androidboot.serialno=0323317065547 " \
	"androidboot.security=none tegraid=21.1.2.0.0 ddr_die=3072M@2048M " \
	"section=512M memtype=0 vpr_resize usb_port_owner_info=1 lane_owner_info=0 " \
	"emc_max_dvfs=1 touch_id=0@63 video=tegrafb no_console_suspend=1 console=ttyS0,115200n8 " \
	"debug_uartport=lsport,2 earlyprintk=uart8250-32bit,0x70006000 maxcpus=4 "\
	'lp0_vec=0x1000@0xff780000 nvdumper_reserved=0xff180000 core_edp_mv=1075 " \
	"core_edp_ma=4000 tegra_fbmem=0x800000@0x92cb7000 androidboot.touch_panel_id=63  " \
	"androidboot.touch_feature=0 androidboot.orientation=0 usbcore.old_scheme_first=1 " \
	"is_hdmi_initialised=1 android.kerneltype=normal androidboot.touch_vendor_id=0 " \
	"androidboot.bootloader=00.00.2018.01-t210-430913d9 androidboot.verifiedbootstate=orange"

/* General networking support */

#include "tegra-common-usb-gadget.h"
#include "tegra-common-post.h"

/* Crystal is 38.4MHz. clk_m runs at half that rate */
#define COUNTER_FREQUENCY	19200000

#endif /* _P3450_PORG_H */

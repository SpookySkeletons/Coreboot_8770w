ifeq ($(CONFIG_SOC_INTEL_FSP_BROADWELL_DE),y)

subdirs-y += romstage
subdirs-y += ../../../cpu/intel/microcode
subdirs-y += ../../../cpu/intel/turbo
subdirs-y += ../../../cpu/x86/lapic
subdirs-y += ../../../cpu/x86/mtrr
subdirs-y += ../../../cpu/x86/smm
subdirs-y += ../../../cpu/x86/tsc
subdirs-y += ../../../cpu/x86/cache
subdirs-y += ../../../lib/fsp
subdirs-y += fsp

romstage-y += gpio.c
ramstage-y += cpu.c
ramstage-y += chip.c
ramstage-y += northcluster.c
ramstage-y += ramstage.c
ramstage-y += tsc_freq.c
romstage-y += memmap.c
ramstage-y += memmap.c
ramstage-y += southcluster.c
ramstage-y += acpi.c
ramstage-y += smbus_common.c
ramstage-y += smbus.c
romstage-y += tsc_freq.c
postcar-y += tsc_freq.c
ramstage-y += smi.c
ramstage-y += gpio.c
ramstage-y += iou_complto.c
ramstage-$(CONFIG_HAVE_SMI_HANDLER) += smmrelocate.c
ramstage-$(CONFIG_HAVE_SMI_HANDLER) += pmutil.c
ramstage-y += vtd.c
smm-y += pmutil.c
smm-y += smihandler.c
smm-y += tsc_freq.c

CPPFLAGS_common += -I$(src)/soc/intel/fsp_broadwell_de/include
CPPFLAGS_common += -I$(src)/soc/intel/fsp_broadwell_de/fsp
CPPFLAGS_common += -I$(src)/soc/intel/fsp_broadwell_de/

cpu_microcode_bins += $(wildcard 3rdparty/intel-microcode/intel-ucode/06-56-*)

endif # ifeq ($(CONFIG_SOC_INTEL_FSP_BROADWELL_DE),y)

##
## This file is part of the coreboot project.
##
## Copyright (C) 2013 Google Inc.
## Copyright (C) 2015 Intel Corp.
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

romstage-y += romstage.c
romstage-y += spd_util.c

ramstage-y += gpio.c
ramstage-y += ramstage.c

SPD_BIN = $(obj)/spd.bin

SPD_SOURCES = hynix_2GiB_dimm_H9CCNNN8GTMLAR-NUD
SPD_SOURCES += hynix_2GiB_dimm_H9CCNNN8GTMLAR-NUD
SPD_SOURCES += micron_dimm_MT52L256M32D1PF-107
SPD_SOURCES += micron_dimm_MT52L256M32D1PF-107
SPD_SOURCES += samsung_2GiB_dimm_K4E8E324EB-EGCF
SPD_SOURCES += samsung_2GiB_dimm_K4E8E324EB-EGCF

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/spd/$(f).spd.hex)

# Include spd ROM data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do for c in $$(cat $$f | grep -v ^#); \
	    do printf $$(printf '\%o' 0x$$c); \
	  done; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := spd

Bones' Coreboot src/
===============

I recommend you build from source! My working config is located in configs/ for you to customize. Bootsplash, Serial, Version can be manually set.
I also recommend drilling a hole over your SOIC-16 in the metal frame, makes subsequent flashes almost effortless.

Why the 8770w?
===============
In terms of graphical performance, the 8770w is second to nothing, under a libre BIOS. This laptop will run any MXM 3.0B card you care to put in it, tested with an Nvidia Quadro Maxwell M3000M, AMD Tonga W7170M, and a AMD Polaris10 WX7100 GPU.

I can describe the laptop thusly: HOT, LOUD, THICK, FAST

Two variants of the mainboard exist, one with 2 ram slots and the other with 4, the maximum RAM is 16 and 32GB respectively. Two variants of CPU AND GPU heatsink, a single pipe or a double pipe on the CPU that greatly enhances cooling, with a MXM A type GPU sink and a B type. Be mindful of what heatsink you have if you plan to upgrade to a full depth MXM B or a quad core CPU. The heatsinks don't necessarily conform to newer GPUs, you may have to get creative with your thermal pads!

Also availble is the HP dreamcolor 10 bit 2.2 gamma display, really looks like a dream but I belive it burns somewhere near 15 watts to produce those beautiful colors. The EDID of the display also conflicts with AMD's free and open kernel driver. Kernels newer than mainline ~4.18 were somehow changed to break EDID handling so the monitor boots into X/tty with a 640x480 resolution, the display being driven by a proprietary eDP -> Dual LVDS board and connectors is unable to handle this and the monitor displays garbage.

If you have the normal 8 bit LVDS display, or run Nvidia, this will be of little concern to you.

If however you want a fully free (barring the AMDGPU firmware blobs) and open graphics stack I recommend you put this in your xorg...

    Modeline "1920x1080_60.02"  138.70  1920 1968 2000 2080  1080 1083 1088 1111 -hsync -vsync
    Option "PreferredMode" "1920x1080_60.02"
    
...To force the display modeline without the kernel's assistance! Fixes the display on Xorg but not in your tty!

This laptop has relatively little power saving, especially using AMD as the GPU! The proximity of the GPU with the battery results in a ready degredation of the cells and high current draw while actually using the cells exacerbates this issue. Have spares or better yet: Compensate with a slice battery for nearly 200Wh of power in the laptop. Have/ build some muscle.

!!45-50 watts idle on my own setup!!

I recommend implementing software power restrictions on the GPU when you remove the DC jack as the laptop is known to shut off from over-drawing the cells. Nvidia doesn't have as big of an issue as AMD in this department, but if for any reason your laptop shuts off suddenly I can almost assure your that the issue is maximum power usage of either the battery or charger.

When purchasing a GPU keep in mind that you may have to tweak your vBIOS to achieve a proper stutter-free experience, if you plan to use a 67+ watt card in the MXM. You will NEED TO ENSURE that the GPU does not thermal throttle below 95-99C! This is very very hot, but keep in mind we're dealing with a laptop with a maximum of one fan, and 2+2 heat pipes, it's a miracle it does so well to begin with!

Throttling at and below 90C can result in very unpleasant stutter in heavy applications & games with a very important tipping point of 67 watts exactly to stick to a 89C barrier!

If you want something cooler by all means, limit your TDP to around 67 watts max, but if you want PERFORMANCE and don't mind some higher temps, you'll need to mod the vBIOS.

Second issue, the largest adapter, and presumably unfrankensteined, you can get for this absolute unit is 230 watts. You can very readily over-draw your 230W adapter just by overclocking your MXM! Test that your HP does not powercut under extreme CPU and GPU load.

The onboard EC does not control the fans in accordance with newer AMD GPUs, only the CPU temp, the single fan for both CPU and GPU makes this a nonissue. I have never experienced a scenario in which my GPU was too hot and the CPU was cool in my years of usage.

Please ensure your GPU is EFI compatible, I believe Tianocore payload reads your GPU's GOP to load the framebuffer at startup. If your card is not EFI compatible consider compiling it on your own with SEABIOS and slipping your vBIOS into the coreboot rom in the build options.

And there you have it, most anything I care to say about the extreme performance HP laptop, despite a few rough-patches it's quite an enjoyable portable 60fps tank!

coreboot README
===============

coreboot is a Free Software project aimed at replacing the proprietary BIOS
(firmware) found in most computers.  coreboot performs a little bit of
hardware initialization and then executes additional boot logic, called a
payload.

With the separation of hardware initialization and later boot logic,
coreboot can scale from specialized applications that run directly
firmware, run operating systems in flash, load custom
bootloaders, or implement firmware standards, like PC BIOS services or
UEFI. This allows for systems to only include the features necessary
in the target application, reducing the amount of code and flash space
required.

coreboot was formerly known as LinuxBIOS.


Payloads
--------

After the basic initialization of the hardware has been performed, any
desired "payload" can be started by coreboot.

See <https://www.coreboot.org/Payloads> for a list of supported payloads.


Supported Hardware
------------------

coreboot supports a wide range of chipsets, devices, and mainboards.

For details please consult:

 * <https://www.coreboot.org/Supported_Motherboards>
 * <https://www.coreboot.org/Supported_Chipsets_and_Devices>


Build Requirements
------------------

 * make
 * gcc / g++
   Because Linux distribution compilers tend to use lots of patches. coreboot
   does lots of "unusual" things in its build system, some of which break due
   to those patches, sometimes by gcc aborting, sometimes - and that's worse -
   by generating broken object code.
   Two options: use our toolchain (eg. make crosstools-i386) or enable the
   `ANY_TOOLCHAIN` Kconfig option if you're feeling lucky (no support in this
   case).
 * iasl (for targets with ACPI support)
 * pkg-config
 * libssl-dev (openssl)

Optional:

 * doxygen (for generating/viewing documentation)
 * gdb (for better debugging facilities on some targets)
 * ncurses (for `make menuconfig` and `make nconfig`)
 * flex and bison (for regenerating parsers)


Building coreboot
-----------------

Please consult <https://www.coreboot.org/Build_HOWTO> for details.


Testing coreboot Without Modifying Your Hardware
------------------------------------------------

If you want to test coreboot without any risks before you really decide
to use it on your hardware, you can use the QEMU system emulator to run
coreboot virtually in QEMU.

Please see <https://www.coreboot.org/QEMU> for details.


Website and Mailing List
------------------------

Further details on the project, a FAQ, many HOWTOs, news, development
guidelines and more can be found on the coreboot website:

  <https://www.coreboot.org>

You can contact us directly on the coreboot mailing list:

  <https://www.coreboot.org/Mailinglist>


Copyright and License
---------------------

The copyright on coreboot is owned by quite a large number of individual
developers and companies. Please check the individual source files for details.

coreboot is licensed under the terms of the GNU General Public License (GPL).
Some files are licensed under the "GPL (version 2, or any later version)",
and some files are licensed under the "GPL, version 2". For some parts, which
were derived from other projects, other (GPL-compatible) licenses may apply.
Please check the individual source files for details.

This makes the resulting coreboot images licensed under the GPL, version 2.

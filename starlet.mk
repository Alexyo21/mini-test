ifeq ($(strip $(DEVKITARM)),)
$(error "Set DEVKITARM in your environment.")
endif

PREFIX = $(DEVKITARM)/bin/arm-none-eabi-

CFLAGS = -mbig-endian -mcpu=arm926ej-s
CFLAGS += -fomit-frame-pointer -ffunction-sections
CFLAGS += -Wall -Wextra -Os -flto -pipe
ASFLAGS =
LDFLAGS = -Os -flto -mbig-endian -n -nostartfiles -nodefaultlibs -Wl,-gc-sections


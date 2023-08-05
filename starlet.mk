ifeq ($(strip $(DEVKITARM)),)
$(error "Set DEVKITARM in your environment.")
endif

PREFIX = $(DEVKITARM)/bin/arm-none-eabi-

CFLAGS = -mbig-endian -mcpu=arm926ej-s
CFLAGS += -g -ffunction-sections
CFLAGS += -Wall -Wextra -Og -pipe
ASFLAGS = -g
LDFLAGS = -mbig-endian -n -nostartfiles -nodefaultlibs -g -Wl,-gc-sections


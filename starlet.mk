ifeq ($(strip $(DEVKITARM)),)
$(error "Set DEVKITARM in your environment.")
endif

PREFIX = $(DEVKITARM)/bin/arm-none-eabi-

CFLAGS = -mbig-endian -mcpu=arm926ej-s -mfloat-abi=soft -mtp=soft -marm -mthumb-interwork
CFLAGS += -g -ffunction-sections -fno-fast-math
CFLAGS += -Wall -Wextra -Os -pipe
ASFLAGS = -g
LDFLAGS = -mbig-endian -n -nostartfiles -nodefaultlibs -g -Wl,-gc-sections


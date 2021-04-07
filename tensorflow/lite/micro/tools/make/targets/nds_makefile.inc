ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/ds_rules

TARGET_ARCH := armv5te
TARGET_TOOLCHAIN_PREFIX := arm-none-eabi-
TARGET_TOOLCHAIN_ROOT := $(DEVKITARM)/bin/

ARCH := -mthumb -mthumb-interwork

CFLAGS += -g -Wall -O2\
                  -march=armv5te -mtune=arm946e-s -fomit-frame-pointer\
                  -ffast-math \
                  $(ARCH)
CFLAGS += $(INCLUDE) -DARM9
CXXFLAGS += $(CFLAGS)

INCLUDES += \
  -I$(DEVKITPRO)/libnds/include

ifeq ($(OS),Windows_NT)
TARGETS += cpcmngdisk.exe
else
TARGETS	+= cpcmngdisk
endif

cpcmngdisk_SRCS	= main.c
ifeq ($(OS),Windows_NT)
cpcmngdisk_OBJS	= $(addprefix mngdisk\, $(cpcmngdisk_SRCS:.c=.obj))
else
cpcmngdisk_OBJS	= $(addprefix mngdisk/, $(cpcmngdisk_SRCS:.c=.obj))
endif

GARBADGES += $(cpcmngdisk_OBJS)

cpcmngdisk cpcmngdisk.exe: $(cpcmngdisk_OBJS)
ifdef ld_msvc
	$(LD) /OUT:$@ $^ $(LDFLAGS)
else
	$(LD) -o $@ $^ $(LDFLAGS)
endif


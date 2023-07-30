ifeq ($(OS),Windows_NT)
TARGETS += cpcmkdisk.exe
else
TARGETS	+= cpcmkdisk
endif

cpcmkdisk_SRCS	= main.c
ifeq ($(OS),Windows_NT)
cpcmkdisk_OBJS	= $(addprefix mkdisk\, $(cpcmkdisk_SRCS:.c=.obj))
else
cpcmkdisk_OBJS	= $(addprefix mkdisk/, $(cpcmkdisk_SRCS:.c=.obj))
endif

GARBADGES += $(cpcmkdisk_OBJS)

cpcmkdisk cpcmkdisk.exe: $(cpcmkdisk_OBJS)
ifdef ld_msvc
	$(LD) /OUT:$@ $^ $(LDFLAGS)
else
	$(LD) -o $@ $^ $(LDFLAGS)
endif


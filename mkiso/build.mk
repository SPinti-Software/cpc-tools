ifeq ($(OS),Windows_NT)
TARGETS += cpcmkiso.exe
else
TARGETS	+= cpcmkiso
endif

cpcmkiso_SRCS	= main.c
ifeq ($(OS),Windows_NT)
cpcmkiso_OBJS	= $(addprefix mkiso\, $(cpcmkiso_SRCS:.c=.obj))
else
cpcmkiso_OBJS	= $(addprefix mkiso/, $(cpcmkiso_SRCS:.c=.obj))
endif

GARBADGES += $(cpcmkiso_OBJS)

cpcmkiso cpcmkiso.exe: $(cpcmkiso_OBJS)
ifdef ld_msvc
	$(LD) /OUT:$@ $^ $(LDFLAGS)
else
	$(LD) -o $@ $^ $(LDFLAGS)
endif


ifeq ($(OS),Windows_NT)
TARGETS += cpccheck.exe
else
TARGETS	+= cpccheck
endif

cpccheck_SRCS	= main.cpp
ifeq ($(OS),Windows_NT)
cpccheck_OBJS	= $(addprefix check\, $(cpccheck_SRCS:.cpp=.obj))
else
cpccheck_OBJS	= $(addprefix check/, $(cpccheck_SRCS:.cpp=.obj))
endif

GARBADGES += $(cpccheck_OBJS)

cpccheck cpccheck.exe: $(cpccheck_OBJS)
ifdef ld_msvc
	$(LD) /OUT:$@ $^ $(LDFLAGS)
else
	$(CXX) -o $@ $^ $(LDFLAGS)
endif

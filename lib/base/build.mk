ifdef cc_msvc
LIBS += libbase.lib
else
LIBS += libbase.a
endif

libbase_SRCS = cli.c program.c
ifeq ($(OS),Windows_NT)
libbase_OBJS =  $(addprefix lib\base\, $(libbase_SRCS:.c=.obj))
else
libbase_OBJS =  $(addprefix lib/base/, $(libbase_SRCS:.c=.obj))
endif

GARBADGES += $(libbase_OBJS)

libbase.lib: $(libbase_OBJS)
	$(MSVCLNK) /OUT:$@ $^

libbase.a: $(libbase_OBJS)
	$(AR) rcs $@ $^

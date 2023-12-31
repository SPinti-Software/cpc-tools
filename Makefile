.DEFAULT_GOAL := all

ifeq ($(OS),Windows_NT)
CC	:= cl
CXX	:= cl
LD	:= link
MSVCLNK	:= lib
RM	:= cmd /c del /s
ISCC	:= iscc
else
CC	?= gcc
CXX	?= g++
LD	:= $(CC)
RM	:= rm -f
endif
TAR	:= tar

include build-aux/toolchain.mk

TARGETS =
LIBS    =
GARBADGES =

ifdef cc_msvc
CFLAGS	+= /TC /Wall /WX /wd5045 /wd4820 /D_CRT_SECURE_NO_WARNINGS /Za /Ilib
CXXFLAGS += /Ilib
else
CFLAGS	+= -Wall -Werror -Wextra -Ilib
CXXFLAGS += -Ilib
ifdef cc_clang_gcc
CFLAGS	+= -ansi -pedantic
endif
endif

ifdef ld_msvc
LDFLAGS	+= /SUBSYSTEM:CONSOLE
endif

include lib/build.mk
include mkiso/build.mk
include mkdisk/build.mk
include mngdisk/build.mk
include check/build.mk

.PHONY: all
all: $(TARGETS)


$(TARGETS): $(LIBS)

%.obj: %.c
ifdef cc_msvc
	$(CC) /Fo:$@ /c $< $(CFLAGS)
else
	$(CC) -o $@ -c $< $(CFLAGS)
endif

%.obj: %.cpp
ifdef cc_msvc
	$(CXX) /Fo:$@ /c $< $(CXXFLAGS)
else
	$(CXX) -o $@ -c $< $(CXXFLAGS)
endif

.PHONY: dist
dist:

.PHONY: clean
clean:
	$(RM) $(GARBADGES) $(TARGETS) $(LIBS)


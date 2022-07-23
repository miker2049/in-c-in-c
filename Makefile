##
# in c in c
#
# @file
# @version 0.1


all: smfsh in_c

VPATH = src

CC= gcc

COREOBJS = \
geelib.o \
smf.o \
smf_decode.o \
smf_load.o \
smf_save.o \
smf_tempo.o \

SMFSHOBJ = smfsh.o
INCOBJ = inc.o

CFLAGS = -DPACKAGE_VERSION=\"0.0.1\" -std=c99 -g -I./src/ \
-D_POSIX_C_SOURCE=200809L

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

smfsh: $(COREOBJS) $(SMFSHOBJ)
	$(CC) -lm -o $@ $^

in_c: $(COREOBJS) $(INCOBJ)
	$(CC) -lm -o $@ $^


clean:
	rm -rf $(COREOBJS) $(SMFSHOBJ) $(INCOBJ) smfsh in_c
# end

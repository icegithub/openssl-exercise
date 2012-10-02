CC=gcc
CFLAG=-Wall -O2
VPATH=-I /usr/local/include /usr/local/lib/libcrypto.a -ldl

src := $(wildcard *.c)
## make .c in $(src) replace by .o
obj := $(src:.c=.o)
bin := demo

all: $(bin)
	@echo "Make Successfully!"

$(bin):$(obj)
	@echo "Begin to Output demo......"
	$(CC) $(CFLAG) $< -o $@ $(VPATH)

$(obj):$(src)
	@echo "Begin to Compiler......(But do not link)"
	$(CC) -c $(CFLAG) $< -o $@ $(VPATH)

.PHONY: clean
clean:
	@echo "Begin to clean .o and binary file"
	rm -f *.o $(bin) Encryption Decryption
	@echo "Clean Done!"
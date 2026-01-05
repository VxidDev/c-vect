CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -Iinclude
AR = ar
ARFLAGS = rcs
RM = rm -f

LIB = libvectors.a

SRCS = src/InitVec.c \
       src/AppendVec.c \
       src/FreeVec.c \
       src/GetLastVec.c \
       src/GetItemFromVec.c \
       src/PopVec.c \
       src/RemoveFromVec.c \
	   src/ClearVec.c \
	   src/ResetVec.c \
	   src/ShrinkToFitVec.c \
	   src/ShrinkVec.c \
	   src/ExtendVec.c \
	   src/GetSizeVec.c \
	   src/GetCapacityVec.c \
	   src/InsertVec.c \
	   src/SetItemVec.c \
	   src/ContainsVec.c \
	   src/SortVec.c \
	   src/ForEachVec.c \
	   src/IndexOfVec.c \
	   src/FrontVec.c \
	   src/BackVec.c \
	   src/FilterVec.c \
	   src/MapVec.c \
	   src/ReduceVec.c

OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "Built $(LIB)"

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(LIB) $(OBJS)
	@echo "Cleaned all"

.PHONY: install
install: $(LIB)
	mkdir -p /usr/local/lib /usr/local/include
	cp $(LIB) /usr/local/lib/
	cp include/*.h /usr/local/include/
	@echo "Installed to /usr/local/"

.PHONY: format
format:
	clang-format -i include/*.h src/*.c

.PHONY: check
check:
	cppcheck --enable=all --inconclusive --language=c include/ src/

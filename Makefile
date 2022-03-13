TARGET   = prog

CC       = gcc
# compiling flags here
CFLAGS   = -Wall 

LINKER   = gcc
# linking flags here
LFLAGS   = 

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /F /Q .\obj\*.o
	@echo All binary files removed.
	
remove: clean
	del /F /Q .\bin\prog.exe
	@echo Executable and all binary files removed.
	
run: 
	bin/prog.exe

gdb:
	gdb bin/prog.exe
##### MAKEFILE #####

TARGET 			:= Curo

PKGS			:= gtk+-3.0
PKGS_CFLAGS		:= `pkg-config --cflags $(PKGS)`
PKGS_LDFLAGS	:= `pkg-config --libs $(PKGS)`

ADD_CFLAGS		:= -Wall -g

CFLAGS 			:= $(PKGS_CFLAGS) $(ADD_CFLAGS)
LDFLAGS 		:= $(PKGS_LDFLAGS)

CC			:= gcc

SRCDIR		:= src
BUILDDIR	:= build
BINDIR		:= bin

SOURCES		:= $(wildcard $(SRCDIR)/*.c)
OBJECTS		:= $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

rm			:= rm -f			

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CC) $^ -o $@ $(LDFLAGS)
	@echo "Linking complete!"

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
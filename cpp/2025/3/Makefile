# Compiler & Standard
CXX      = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Iinclude
LDFLAGS  =

# Directories
SRCDIR   = src
OBJDIR   = build
BINDIR   = bin

# Output binary (change name if preferred)
TARGET   = $(BINDIR)/main

# Auto-discover sources & map to object files
SRCS     = $(wildcard $(SRCDIR)/*.cpp)
OBJS     = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS     = $(OBJS:.o=.d)

# create compile_commands.json
COMP_DB  = bear
MAKE	 = make

# mark as commands, not files
.PHONY: all release debug compile_commands clean

# Default target
all: release

# Release build (optimized)
release: CXXFLAGS += -O2
release: $(TARGET)

# Debug build (debug symbols, no optimization)
debug: CXXFLAGS += -g -O0 -DDEBUG
debug: $(TARGET)

compile_commands:
	$(COMP_DB) -- $(MAKE) clean all

# Linking rule
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Compilation & auto-dependency generation
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include auto-generated header dependencies
-include $(DEPS)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

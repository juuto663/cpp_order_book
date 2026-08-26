# Build any single exercise:  make build/chapter_4/floating_point
# Build everything:           make all
# Start over:                 make clean
#
# clang++ comes from flake.nix, not /usr/bin. Run inside `nix develop` (direnv
# does this automatically when you cd into the repo).

CXX      := clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -g -Isrc
DEPFLAGS := -MMD -MP

# .cpp files that are not programs on their own.
# HELPERS have no main(); they get linked into the targets listed below.
HELPERS := \
	src/chapter_2/fake_helper.cpp \
	src/chapter_2/io.cpp

# SKIP does not compile. Remove a line here once the file builds.
SKIP := \
	src/chapter_2/thread_race_condition.cpp \
	src/chapter_2/initializations.cpp
# thread_race_condition.cpp  `import iostream` — modules experiment, unfinished
# initializations.cpp        int w1{4.5} on line 33 is a deliberate narrowing error

SRCS := $(filter-out $(HELPERS) $(SKIP),$(shell find src -name '*.cpp'))
BINS := $(patsubst src/%.cpp,build/%,$(SRCS))

.PHONY: all clean
all: $(BINS)

# Targets that need a helper linked in. These are extra prerequisites, so
# editing a helper rebuilds its dependents. The recipe's $(filter %.cpp,$^)
# passes both files to the compiler.
build/chapter_2/how_to_use_headers:        src/chapter_2/fake_helper.cpp
build/chapter_2/forward_declaration:       src/chapter_2/fake_helper.cpp
build/chapter_2/chatper_2_quiz_question_2: src/chapter_2/io.cpp

build/%: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(filter %.cpp,$^) -o $@

clean:
	rm -rf build

# Header dependencies recorded by -MMD, so touching io.h rebuilds what uses it.
-include $(shell find build -name '*.d' 2>/dev/null)

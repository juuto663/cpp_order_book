# gdb crash course

## Build for it

```bash
g++ -g -O0 -std=c++23 prog.cpp -o prog   # -g = debug symbols, -O0 = don't reorder lines
gdb ./prog                                # or: gdb --args ./prog arg1 arg2
```

## Core loop

| Command | Short | Does |
|---|---|---|
| `break main.cpp:42` | `b` | Breakpoint at line |
| `break myFunc` | `b` | Breakpoint at function entry |
| `run` | `r` | Start the program |
| `next` | `n` | Step over one line |
| `step` | `s` | Step into a call |
| `finish` | `fin` | Run until current function returns |
| `continue` | `c` | Run to next breakpoint |
| `until 60` | `u` | Run to line 60 (skips loops) |

## Look around

| Command | Does |
|---|---|
| `print x` / `p x` | Value of `x` |
| `p arr[3]` , `p *ptr` , `p obj.field` | Expressions work |
| `p vec` | Prints `std::vector` readably (pretty-printers are on by default) |
| `info locals` | All locals in scope |
| `info args` | Function arguments |
| `backtrace` / `bt` | Call stack |
| `frame 2` / `f 2` | Switch to stack frame 2, then `info locals` there |
| `list` / `l` | Source around the current line |
| `display x` | Auto-print `x` after every stop |

## Change things

```
set var x = 10        # assign to a variable
watch counter         # break when counter's value changes
info breakpoints      # list them
delete 2              # remove breakpoint 2
```

## Two habits that pay off immediately

**TUI mode** — a source window instead of blind stepping:

```
layout src        # or start gdb with: gdb -tui ./prog
Ctrl-x a          # toggle it off/on
Ctrl-l            # redraw when it garbles
```

**Post-mortem on a crash** — no breakpoints needed:

```
gdb ./prog
run
# segfault happens
bt              # where it died
f 1             # go up to your code
info locals     # what was wrong
```

`quit` / `q` to exit. `Enter` alone repeats the last command — that's how you
step 20 lines with 20 keystrokes.

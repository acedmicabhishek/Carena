# Auto 
- Default for local variables (inside functions).

- Stored in stack memory.

- Lifetime: Exists only during the function execution.

- Scope: Local to the block where declared.

- Default value: Garbage (undefined).


# Static
- Stored in data segment (not stack).

- Lifetime: Persists throughout the program’s execution.

- Scope: Depends on where it’s declared:

- Inside a function : visible only inside that function, but value persists across calls.

- Outside functions : visible only in that file.

- Default value: 0.

# extern

- Declares a global variable defined in another file or later in the same file.

- Tells the compiler: “this variable exists somewhere else, don’t allocate new storage.”

# register

- Suggests storing the variable in a CPU register instead of RAM (for speed).

- Modern compilers usually ignore this suggestion.

- Lifetime: Same as auto (only while function runs).

- Scope: Local.

- Note: Can’t take the address of a register variable (&var not allowed).

# global variables (default storage: static, but scope is global)

- Declared outside functions.

- Accessible by any function in the file.

- Lifetime: Entire program.

- Default value: 0.
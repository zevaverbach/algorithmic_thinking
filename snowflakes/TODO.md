- demonstrate segfault when you iterate beyond the end of an array
- make sure `num_snowflakes` is on the stack, and that it goes out of scope after you return from get_num_snowflakes_from_stdin
  - print the memory address, for example
- is snowflakes really empty after declaration?
- why do we have to create `snowflake` using malloc? its size is predictable at compile time, so why can't we use the stack?

# Later
- how does `bool` work in C? The definitions are simple enough but what about the type?
- does clang put "0"s in a declared array?

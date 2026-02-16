# mtee
## Version 1.0.0
*Made by Michał Waluś*

Simple version of `tee`. Reads from standard input and write to standard output and given files. 

Usage:
```
./mtee [FILE]...
```

Current version doesn't accept any flags.

*Note: The current version has been made as an exercise and uses `pipe()` and `fork()`, which makes it less efficient.
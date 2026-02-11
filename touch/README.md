# mtouch
## Version 1.1.0
*Made by Michał Waluś*

Simple version of `touch`. Updates the access and modification times of a given file to current time. Creates a file if it doesn't exists. Accepts multiple files as input.

Usage:
```
./mmkdir [OPTIONS]... [FILE]...
```

Current version accepts the following flags:
- `-m` - Update only the modification time.
- `-a` - Update only the access time. 
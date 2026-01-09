# mecho
## Version 1.1.0
*Made by Michał Waluś*

My version of `echo`. Outputs given given text to stdout.

Usage:
```
./mls [OPTIONS]... [MESSAGE]
```

Current version accepts the following flags:
- `-c [NUMBER]` - Prints the message the given number of times.
- `-e` - Formats escape characters, e.g. a new line will be written, instead of `\n`. This option also supports ANSI escape codes.
- `-n` - Does not print the new line at the end.
- `-r` - Repeats the message in a loop until forcefully stopped.
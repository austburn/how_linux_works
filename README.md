How Linux Works
===============

Just some tests around certain things I learned in the book.

setuid.c

```bash
~ ./a.out
I got -1 when attempting to setuid(0).
1000
```

```bash
~ sudo ./a.out
I got 0 when attempting to setuid(0).
0
```

# Simple Interpreter
## Credits
The base version of this simple interpreter was provided through a [tutorial by Dr. Laurie Tratt](https://youtu.be/Q2UDHY5as90?si=wbjvZ6I1SvFIPA_c).
I then decided to translate the program to C++ for practice.
This version supports some basic integer arithmetic and while loop control flow.

## Syntax
### Declaring variables
```
x = 1
y = 2 3 +
z = x y *
```

### While loops
```
while <condition>
    <code>
end
```
Example:
```
while x 1 >=
    x = x 1 -
end
```

### Supported operators
- `=` assignment
- `+` addition
- `-` subtraction
- `*` multiplication
- `>=` greater-than-or-equal-to

### Sample Program
Calculate factorial
```
n = 5
r = 1
while n 1 >=
    r = r n *
    n = n 1 -
end
```
# Simple Interpreter
## Credits
The base version of this simple interpreter was provided through a [tutorial by Dr. Laurie Tratt](https://youtu.be/Q2UDHY5as90?si=wbjvZ6I1SvFIPA_c).
I then decided to translate the program to C++ for practice.
This version supports some basic integer arithmetic and while loop control flow. The output is the values of all variables.

## Continuation
Building on the ground work laid down in Dr. Tratt's tutorial, I have added:
- empty line handling
- `if` statements
- `==`, `<=`, `>`, and `<` operators

## Known Issues
- Nested `while` loops are not functional
- Extra `endif`s will map to future `if`s

## Syntax
### Declaring variables
```
x = 1
y = 2 3 +
z = x y *
```

### If statements
```
if <condition>
    <code>
endif
```

Example:
```
x = 10
y = 0

if x 5 >
    y = 1
endif
```

### While loops
```
while <condition>
    <code>
endwhile
```

Example:
```
while x 1 >=
    x = x 1 -
endwhile
```

### Supported operators
- `=` assignment
- `+` addition
- `-` subtraction
- `*` multiplication
- `==` equal to
- `>=` greater than or equal to
- `<=` less than or equal to
- `>` greater than
- `<` less than

### Sample programs
Calculate factorial
```
n = 5
r = 1
while n 1 >=
    r = r n *
    n = n 1 -
endwhile
```

Nested if statements
```
x = 2
counter = 0

if x 0 >
    counter = counter 1 +

    if x 1 >
        counter = counter 1 +

        if x 2 > 
            counter = counter 1 +
        endif
    endif
endif
```
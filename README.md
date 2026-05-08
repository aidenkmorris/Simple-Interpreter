# Simple Interpreter
## Credits
The base version of this simple interpreter was provided through a [tutorial by Dr. Laurie Tratt](https://youtu.be/Q2UDHY5as90?si=wbjvZ6I1SvFIPA_c).
I then decided to translate the program to C++ for practice.
This version supported some basic integer arithmetic and while loop control flow. The output was the values of all variables.

## Continuation
Building on the ground work laid down in Dr. Tratt's tutorial, I have added:
- `==`, `!=`, `<=`, `>`, and `<` operators
- empty line handling
- `if` statements
- `if-else` statements
- Basic `for` loops

Output is simply the values of all variables at the time of successful termination.

## Known Issues
- Nested `while` loops are not functional
- Nested `for` loops are not functional
- Extra `endif`s will map to future `if`s

## Syntax
### Declaring variables
```
x = 1
y = 2 3 +
z = x y *
w = 1 2 + 3 4 + *
```
Note: the expression assigned to `w` is equivalent to (1 + 2) * (3 + 4)

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

### If-else statements
```
if <condition>
    <code>
else
    <code>
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

### For loops
```
for <initializer>
until <condition>
    <code>
endfor
```
Note that the loop will run `until` the condition is met.

As of now, the increment is always by 1.

### Supported operators
- `=` assignment
- `+` addition
- `-` subtraction
- `*` multiplication
- `==` equal to
- `!=` not equal to
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

If/else statement
```
i = 0
x = 0
count = 0

while i 10 <
    if x 0 ==
        count = count 1 +
        x = x 1 +
    else
        x = x 1 -
    endif

    i = i 1 +
endwhile
```

For loops using until
```
x = 1
y = 1

for i = 0
until i 5 ==
    x = x 2 *
endfor

for i = 0
until y 30 >
    y = y 2 *
endfor
```
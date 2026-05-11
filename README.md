# Simple Interpreter
## Credits
The base version of this simple interpreter was provided through a [tutorial by Dr. Laurie Tratt](https://youtu.be/Q2UDHY5as90?si=wbjvZ6I1SvFIPA_c).
I then decided to translate the program to C++ for practice.
This version supported some basic integer arithmetic and while loop control flow. The output was the values of all variables.

## Continuation
Building on the ground work laid down in Dr. Tratt's tutorial, I have added:
- `/`, `%`, `==`, `!=`, `<=`, `>`, and `<` operators
- functional nesting of `while` loops
- empty line handling
- comments
- `if` statements
- `if-else` statements
- Basic `for` loops
- `print` statements
- `printline` statements
- `input` statements

## Known Issues
- Extra `endif`s will map to future `if`s
- No proper error handling/messaging is currently present
- Code in between `for` and `until` will execute (n + 1) times, where n is the number of times the loop runs

## Syntax
### Supported operators
- `=` assignment
- `+` addition
- `-` subtraction
- `*` multiplication
- `/` division
- `%` modulo
- `==` equal to
- `!=` not equal to
- `>=` greater than or equal to
- `<=` less than or equal to
- `>` greater than
- `<` less than

### Declaring variables
```
x = 1
y = 2 3 +
z = x y *
w = 1 2 + 3 4 + *
```
Note: the expression assigned to `w` is equivalent to (1 + 2) * (3 + 4)

### Print and printline statements
```
print <text>
printline <text>
```

Example:
```
printline Hello, world!
print This will be on a newline...
print but this will be on the same line
```

To reference variables in `print`/`printline` statements, use the prefix `~` like so:
```
x = 42

// x
printline x

// 42
printline ~x

// ~x
printline ~~x

// ~42
printline ~~~x
```

Note that `~~` can be used to print a literal `~`.

### Input statements
```
input <variable>
```

`input` statements can be used to create new variables or modify existing variables.

Example:
```
input x
printline x equals ~x

y = 1
input y
printline y now equals ~y
```

### Comments
```
// This is a comment

//This is another comment

x = 10 // This is a third comment
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

Example: 
```
counter = 0

for x = 0
until x 5 ==
    counter = counter 1 +
endfor
```

Note that the loop will run `until` the condition is met.

As of now, the increment is always by 1.

## Sample programs
### Calculate factorial
```
n = 5
r = 1

while n 1 >=
    r = r n *
    n = n 1 -
endwhile

printline ~r
```
This was the original program demonstrated by Dr. Tratt and 
full extent of his interpreter's capabilites. The original
version looked like the following (now incorrect) code:
```
n = 5
r = 1
while n 1 >=
    r = r n *
    n = n 1 -
end
```

### Nested if statements
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

printline counter: ~counter
```

### If/else statement
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

printline count: ~count
```

### Nested while loops
```
counter = 0

while counter 10 <
    i = 0

    while i 3 <
        counter = counter 1 +
        i = i 1 +
    endwhile
endwhile

printline ~counter
```

### For loops using until
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

printline x: ~x
printline y: ~y
```

### Nested for loops
```
counter = 0

for x = 0
until x 5 ==
    for y = 0
    until y 3 ==
        counter = counter 1 +
    endfor
endfor

printline ~counter
```

### Collatz Conjecture Implementation
```
// Change this value
print Please input a positive integer: 
input value

printline Starting value: ~value

steps = 0

while value 1 !=
    // (value % 2) == 0
    if value 2 % 0 ==
        value = value 2 /
    else
        value = value 3 * 1 +
    endif

    steps = steps 1 +
    printline Step ~steps -> ~value
endwhile
```
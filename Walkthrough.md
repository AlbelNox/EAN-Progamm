# Methods
## List of Methods in Program
 - eanCheckProgram
 - checkValidEAN
 - eanValidation
 - isPlaceholder
 - waitForUser
 - runTests
 - runTestsAssert

# Infotext for Methods
### Here is written what each Method is doing

## eanCheckProgram
``` md
This is the method for the eanprogramm, here is the menue placed. 
We wait for an input from the user. 
If the input is send, we check if the input is `exit`. 
If it is, we go back to the main menue. 
If the input is something else, we use the `checkValidEAN` method. 
After that, we use `eanValidation`. 
In the end we have a `Valid` or `Invalid` output. 
```

## checkValidEAN
``` md
We work twith the input from the user.
The input is checked via Regex if it is a digit [0-9].
Next we check the lengthof the input String, is it 8 or 13 digits long. 
If that is correct we use `isPlaceholder`.
If there are more or less digits or other symbols in the string, we give the User an response with an `invalid` text.
```

## eanValidation
``` md
Here we check if the EAN is valid or invalid:

 - Multiply the digits (excluding the check digit) alternately by 1 and 3.
 - Add up the results.
 - Calculate the remainder of the sum when divided by 10.
 - The check digit is the number needed to reach the next multiple of 10.
```

## isPlaceholder
``` md
We check with a regex if the input is a string with 8 or 13 zeros.
```

## waitForUser
``` md
This method is for clearing the screen after the end of an iteration of the process.
```

## runTests
``` md
This method is provided with some data for testing.
there are strings of type `valid`, `invalid` and `placeholder`.
They run through the functions.
```

## runTestsAssert
``` md
Here we run through the the tests again and assert the result.
```

# Walkthrough
### What will the program do?
``` md
First we start the application. We are now in the mainMenue, 
where we have 3 options: `1: runTests`, `2: EanCheck Program` and `0: End Program`.

1. If we choose 1, we will run through the tests and check the program does what it should. 
To verify the integrety of the functions. 
The results will be displayed. We get a message, that we shoult press any key. 
If we do that, we get back to the mainmenue.

2. If we choose 2, we get in the menue of the eanChecker programm. Here are 2 options: 
`exit` and `every other string`.
If we type `exit`, we will be lead back to the last screen, the mainMenue. 
If we input a string, the program will check the strings validation. 
First, it checks it the string is just providing digits and has a length of 8 or 13. 
There is also a check for placeholders like `00000000` or `0000000000000`. 
If the string is now invalid, we get a response which provide us with this data. 
The program will also restart after an input. 
If the check is still valid, now we check the ean of it`s validation. 
If it is valid, we get a response in the console `valid EAN`. 
Else we get a respone `invalid string`. 
After we pressed a key, we get back to the eanmenue and can input the next ean for the check.
```

# Control flow graphs

### runTestsAssert()
```mermaid
graph TD
subgraph "runTestsAssert"
A(start) --> B(for)
B --> C(end for)
C --> D(for)
D --> E(end for)
E --> F(for)
F --> G(end for)
G --> H(for)
H --> I(end for)
I --> J(for)
J --> K(end for)
K --> L(for)
L --> M(end for)
M -->|input| N(end)
end
```

### runTests()
```mermaid
graph TD
subgraph "runTests()"
A(start) --> B(for)
B --> C(if)
C --> D(endif)
D --> E(end for)
E --> F(for)
F --> G(if)
G --> H(endif)
H --> I(end for)
I --> J(for)
J --> K(if)
K --> L(end if)
L --> M(end for)
M --> N(for)
N --> O(if)
O --> P(endif)
P --> Q(end for)
Q --> R(for)
R --> S(if)
S --> T(end if)
T --> U(endfor)
U --> V(for)
V --> W(if)
W --> X(endif)
X --> Y(end for)
Y --> Z(end)
end
```

### waitForUser()
```mermaid
graph TD
subgraph "waitForUser()"
A(start) -->|input| B(end) 
end
```

### isPlatceholder()
```mermaid
graph TD
subgraph "isPlaceholder()"
A(start) --> B(if)
B --> C(end if)
C --> D(end)
end
```

### Main()
```mermaid
graph TD
subgraph "Main()"
A(start) --> B(While)
B -->|input| C(switch)
C --> D(case 1:)
C --> E(case 2:)
C --> F(case 0:)
C --> G(default)
D --> H(end switch)
E --> H
F --> H
G --> H
H --> I(end while)
B --> I
H --> B
I --> J(end)
end
```

### eanValidation()
```mermaid
graph TD
subgraph "eanValidation()"
A(start) --> B(for)
B --> C(endfor)
C --> D(if)
D --> E(end)
end
```

### checkValidEAN()
```mermaid
graph TD
subgraph "checkValidEAN()"
A(start) --> B(if)
B --> C(then)
B --> D(else)
C --> E(if)
E --> F(then)
E --> G(else)
G --> H(end)
D --> H
F --> H
end
```

### eanCheckProgram()
```mermaid
graph TD
subgraph "eanCheckProgram()"
A(start) --> B(while)
B-->|input| C(if)
C --> D(then)
D -->|input| L
C --> E(end if)
E --> F(if)
F --> G(then)
G -->|input| L
F --> H(end if)
H --> I(if)
I --> J(then)
J -->|input| L
I --> K(end if)
K -->|input| L(end while)
L --> M(end) 
end
```


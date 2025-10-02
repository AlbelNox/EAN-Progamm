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
This is the method for the eanprogramm, here is the menue placed. We wait for an input from the user. If the input is send, we check if the input is 'exit'. If it is, we go back to the main menue. If the input is something else, we use the 'checkValidEAN' method. And after that, we use 'eanValidation'. In the end we have a 'Valid' or 'Invalid' output. 
```

## checkValidEAN
``` md
We work twith the input from the user.
The input is checked via Regex if it is a digit [0-9].
Next we check the lengthof the input String, is it 8 or 13 digits long. If that is correct we use 'isPlaceholder'.
If there are more or less digits or other symbols in the string, we give the User an output with an 'invalid' text
```

## eanValidation
``` md
Here we check if the EAN is valid or invalid.
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
there are strings of type 'valid', 'invalid' and 'placeholder'.
They run through the functions.
```

## runTestsAssert
``` md
Here we run through the the tests again and assert the result.
```

# Walkthrough
### What will the program do?
``` md
First we start the application. We are now in the mainMenue, where we have 3 options: '1: runTests', '2: EanCheck Program' and '0: End Program'.

1. If we choose 1, we will run through the tests and check the program does what it should. To verify the integrety of the functions. The results will be displayed. We get a message, that we shoult press any key. If we do that, we get back to the mainmenue.

2. If we choose 2, we get in the menue of the eanChecker programm. Here are 2 options: 'exit' and 'every other string'.
If we type 'exit', we will be lead back to the last screen, the mainMenue. If we input a string, the program will check the strings validation. First, it checks it the string is just providing digits and has a length of 8 or 13. There is also a check for placeholders like '00000000' or '0000000000000'. If the string is now invalid, we get a response which provide us with this data. The program will also restart after an input. If the check is still valid, now we check the ean of it's validation. If it is valid, we get a response in the console 'valid EAN'. Else we get a respone 'invalid string'. After we pressed a key, we get back to the eanmenue and can input the next ean for the check.
```
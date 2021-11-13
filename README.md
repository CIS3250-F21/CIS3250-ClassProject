# CIS3250

This is the massive repository for all code for the class CIS3250 Fall Semester.

[Link To Document](https://docs.google.com/document/d/1p10rx8R_3oGFU1SiKOWELDZhxhAfR2k61Vg8fF_Rl34/edit?usp=sharing)

## Branches

**_NOTE: Only push/pull and work within your own branch_**<br>
When making a pull request please try and make it the final version of your code to help reduce the frequency of code review. Obviously if changes need to be made, feel free to do so. Once you submit a pull request one or multiple admins will look through it, and we may ask to setup a time to meet if we have any questions or would like to talk about your code.<br>

### Before you make a pull request

Please compile using "make" to make sure all of your functions and tests compile properly. Please also run a Valgrind check and make sure there are no memory leaks/uninitialized jumps. The command is below.

> valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

## Group File

1. Put all of your group specific functions in your spesific files. Change them from Group# to what you see fit.
2. We already have you getters and setters defined, please put your code inside of the functions, and **_do not_** change anything else inside of main.c or main.h.

## Tests

1. Your test functions can go in your testing files, inside your folder. Rename them form Group# to what you see fit.
2. Please name the function that runs all of your tests runGroup#Tests()
3. If you have a test handler, rename it to group#TestHandler()

## Naming Conventions

| Type         | Style          |
| ------------ | -------------- |
| Variables    | camelCase      |
| Functions    | UpperCamelCase |
| Globals      | CAPTITAL_CASE  |
| Curly Braces | New Line       |
| File Name    | UpperCamelCase |

## Changes:

1. Changed any mention of Vectors to Points
2. change transformation matrix to a static array
3. 

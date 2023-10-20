# _printf

## Custom version of printf() in C Language

### Description
   Our (Ahmed II Shahd omer) custom function called _printf(). It is a mini-version of C Language function printf(), and our function _printf() attempts to replicate the exact same process as the C function printf().



### Usage
The directory contents should be compiled with the following command:

$ gcc -Wall -Werror -Wextra -pedantic *.c
_printf() function may be used, in any C language program. This is the prototype:

_printf(const char *FORMAT, ...)
FORMAT refers to a string with any number of specifiers followed by a ‘%’ symbol. i.e. "My name is %s and I am %d years old". … refers to a list of variadic (variable arguments in C Language), which can be any number of variables of any type. With the above example string, appropriate arguments could be "Ahmed Ibrahim", 22. These examples together should be called like so:

_printf("My name is %s and I am %d years old", "Ahmed Ibrahim", 22)

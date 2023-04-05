# Libft

In this repository I made some implementation of functions from the following libraries: `<stdlib.h>` , `<string.h>`, `<ctype.h>`.

## More fun things.

The second part of this project was the implementation of Linked Lists, creation of split function and I/O to file descriptors.

I also created a Makefile to help in the compilation process. With the Makefile you can make a statically linked library (libft.a).

## How to ...

There are many ways to Rome.
If you already know about make files, c compilers and C language, you don't need to read this.
But if you don't have any idea. I hope this is helpful.

### Requirements

- [x] I have GCC compiler installed. (If not check below 'How to install gcc')
- [x] I have installed make. 
- [x] I've cloned this repository:

```bash
git clone https://github.com/nucata/libft.git
```
### Run it

1. In your terminal you need to go to the folder you just have download

```bash
cd libft
```

2. You need to create the statically linked library (Somthing like putting all the functions together in a file)
```bash
make
```
Now you can check that you have the library by doing
```bash
ls libft.a
```
3. The previous command makes you to have some "residuos" that are not needed for what we want to do.
 ```bash
make clean
```
4. Create a main file.
```bash
touch main.c
```

5. Copy this code inside`main.c`.
```c
 #include "libft.h"   // Here are the prototypes of my functions.
 
 int main(void)
 {
    char  *text = "This will be a list of words";
    char  **words = ft_split(text, ' '); // This will take the text and split it into a list of words, each word delimitated by the other by a space.
    
    for (int i = 0; i < 7; i++)
    {
      ft_putstr_fd(words[i], 1);
      ft_putchar_fd('\t', 1);
    }
    return (0);
 }
 ```
 5. Compile the main file with the library.
 ```bash
 cc main.c libft.a -o executable
 ```
 
 6. Execute the program
 ```bash
 ./executable
 ```
 7. **Play around, make changes to the code and have fun**

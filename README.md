# quadratic_solver

## How does it work 

This project helps user to sovle _quadratic equatation_.

## How to use it

1) write in command line:

```g++ main.cpp test.cpp -o main -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include- dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored- qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype- limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE```

or rus as administrator release.bat

2) enter 3 numbers - the coefficients _a, b, c_ of the equation ax^2 + bx + c = 0 respectively. The program will notify you of the successful entry of each variable.

3) the program will display the solutions and their number.

## How to enable testmode, input debug, colored cmd

you must enter the appropriate commands after the commands above

test solver: `-DTEST`

more information about scanned values:  `-DINPUT_DEBUG` 

make some text colored in cmd `-DCOLOR_COMANDLINE`

## How is testing done

1) input.txt file is opened

2) read the number of tests

3) each test consists of: coefficients a, b, c of equation ax^2 + bx + c = 0 correct number of solutions correct answers if there are 1 or 2 4) the equation is solved and the solutions and their number are checked

## Colors that are supported 

1) red: `#ff0000` 

2) light green `#9cee90`
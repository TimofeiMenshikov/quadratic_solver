/*! \mainpage Quadratic solver
 *
 * This project helps user to sovle quadratic equatation.

 * - \subpage how_to_use "How to use it"
 * - \subpage how_to_enable_testmode "How to enable testmode, input debug, colored cmd"
 * - \subpage how_is_testing_done "How is testing done"
 */

/*! \page how_to_use How to use it?
 *
 * 1) write in command line: \code g++ main.cpp test.cpp -o main -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include- dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored- qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype- limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE \endcode
 *
 * or run as administrator release.bat
 * 
 * 2) enter 3 numbers - the coefficients a, b, c of the equation ax^2 + bx + c = 0 respectively. The program will notify you of the successful entry of each variable.
 *
 * 3) the program will display the solutions and their number.
 */


/*! \page how_to_enable_testmode How to enable testmode, input debug, colored cmd?
 * 
 * 1) write in command line:
 *
 * \code g++ main.cpp test.cpp -o main -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE\endcode
 * 
 * 2) you must enter the appropriate commands after the commands above
 *
 * test solver
 * 
 * \code -DTEST \endcode
 * 
 * more information about scanned values
 * 
 * \code -DINPUT_DEBUG \endcode
 * 
 * make some text colored in cmd
 * 
 * \code -DCOLOR_COMANDLINE \endcode
 */

/*! \page how_is_testing_done How is testing done?
 * 
 * 1) input.txt file is opened
 * 
 * 2) read the number of tests
 * 
 * 3) each test consists of:
 *		coefficients a, b, c of equation ax^2 + bx + c = 0
 *		correct number of solutions
 *		correct answers if there are 1 or 2
 * 4) the equation is solved and the solutions and their number are checked
 * 
 * 
 */


/*!
\file
main page documentation
*/

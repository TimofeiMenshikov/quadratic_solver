#ifndef PRINT_H
#define PRINT_H

void print_solutions(const struct Solutions* const solutions_pointer);
void print_test_info(const struct Solutions* const solutions_pointer, const struct Solutions* const right_solutions_pointer);
void print_test(const bool is_passed, const int test_number, const struct Solutions* const solutions_pointer, const struct Solutions* right_solutions_pointer, const struct Coefficients* coef_pointer);
int print_error(const int ERROR_CODE);

#endif /* PRINT_H */
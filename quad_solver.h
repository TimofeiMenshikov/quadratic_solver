#define MAXSTR 1000
#define TEST

void test();
struct Coefficients coef_input_from_file(struct Coefficients coefficients, FILE* inputfile);
struct Coefficients coef_input(struct Coefficients coefficients);
void print_solutions(double* solutions, int num_of_solutions);
int solve_quadratic(struct Coefficients coefficients, double* solutions);
int solve_linear(struct Coefficients coefficients, double* solutions);
int solve_equation(struct Coefficients coefficients, double* solutions);
void print_test(bool is_passed, int test_number, int num_of_solutions, double* solutions, int right_num_of_solutions, double* right_answers, struct Coefficients coefficients);
bool check_answers(int num_of_solutions, int right_num_of_solutions, double* solutions, double* right_answers);
bool check_num_of_solutions(int num_of_solutions, int right_num_of_solutions);
bool check_solver(double *solutions, double *right_answers, int num_of_solutions, int right_num_of_solutions);

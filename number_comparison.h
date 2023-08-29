/// constant for comparison of two numbers
const double EPS = 0.0000001;

enum number_comparison    /// constants for comparison_of_two_numbers function
{
    FIRST_IS_LESS = -1,
    EQUAL = 0,
    FIRST_IS_BIGGER = 1
};

bool is_equal(const double first_number, const double second_number);
int comparison_of_two_numbers(const double first_number_pointer, const double second_number_pointer);

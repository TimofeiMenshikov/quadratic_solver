#ifndef INPUT_H
#define INPUT_H

#ifdef INPUT_DEBUG
    #define DEBUG_EXEC(function)    \
        do                          \
        {                           \
            function;               \
        }                           \
        while(0);                   
#else                           
    #define DEBUG_EXEC(function)
#endif /* INPUT_DEBUG */ 


void coef_input(struct Coefficients* coef_pointer);
void one_coef_input(double* one_coef_pointer);
bool is_not_inputed(double* one_coef_pointer);

int input_from_file(struct Coefficients* coef_pointer, struct Solutions* right_solutions_pointer, FILE* inputfile);

void clean_buffer();

#endif /* INPUT_H */
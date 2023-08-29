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

int input_from_file(struct Coefficients* const coef_pointer, struct Solutions* const right_solutions_pointer, FILE* const inputfile);

void coef_input(struct Coefficients* const coef_pointer);
void one_coef_input(double* const one_coef_pointer);
bool is_not_inputed(double* const one_coef_pointer);


void clean_buffer();

#endif /* INPUT_H */
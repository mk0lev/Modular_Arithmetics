#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

// ex.1
int fill_in_array(unsigned int n, int* array);
// ex.2
int sum_of_elements(int* array, unsigned int e1, unsigned int e2, unsigned int n);
// ex.3
int sub_of_elements(int* array, unsigned int e1, unsigned int e2);
// ex.4
int mul_of_elements(int* array, unsigned int e1, unsigned int e2);
// ex.5
void multiply_elements_equal_one(int* array, int n);
// ex.6
void find_reciprocal_of_all_elements(int* array, int n);
// ex.7
int reciprocal_element_position(int* array, int n, unsigned int element);
// ex.8
int mod(int x, int divisor);
int multiply_array_elements(const int* array, int indexA, int indexB, int m);
int find_reciprocal_element_position(const int* array, int size, int el);
int division_elements_of_array(const int* array, int n, int indexA, int indexB);
// ex.9
int quick_recursive_pow_0(int sizeOfZ, int a, int m);
// ex.10
int quick_recursive_pow(int m, int sizeOfZ_1, int l, int p=1, int res=1);
// ex.11
bool is_finite_field(int num);
// ex.12
bool find_primitive_root(int* F_n, unsigned int n_n, unsigned int element);
// ex.13
int find_all_primitive_roots(int* F_n, unsigned int n_n);
// ex.14
int discrete_log(int* F_n, unsigned int n, unsigned int element, unsigned int number);

#endif //FUNCTIONS_H

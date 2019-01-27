#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

// ex. 1
int fill_in_array(unsigned int n, int* array){

    for(int i=0; i<n; i++){
        array[i] = i;
    }

    return 0;
}

// ex. 2
int sum_of_elements(int* array, unsigned int e1, unsigned int e2, unsigned int n){

    return (array[e1] + array[e2])%n;
}

// ex. 3
int sub_of_elements(int* array, unsigned int e1, unsigned int e2){

    return array[e1] - array[e2];
}

// ex. 4
int mul_of_elements(int* array, unsigned int e1, unsigned int e2){

    return array[e1]*array[e2];
}

// ex. 5
int multiply_elements_of_array(int* array, unsigned int A, unsigned int B, int n){
    return array[A]*array[B]%n;
}

bool elements_exist_in_matrix(const int arr[][2], int n, int a, int b){
    for (int i = 0; i < n; i++) {
        if ((arr[i][0] == a && arr[i][1] == b) || (arr[i][0] == b && arr[i][1] == a)) {
            return true;
        }
    }

    return false;
}

void multiply_elements_equal_one(int* array, int n){
    int row = 0;
    int res[n * n - 1][2];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) {
                continue;
            }

            int multiply = multiply_elements_of_array(array, i, j, n);

            if (multiply == 1 && !elements_exist_in_matrix(res, row, array[i], array[j])) {
                res[row][0] = array[i];
                res[row++][1] = array[j];
            }
        }
    }
    cout << "1" << '\t';
    for (int i = 0; i < row; i++) {
        cout << res[i][0] << '\t';
    }

    cout << endl;
    cout << "1" << '\t';
    for (int i = 0; i < row; i++){
        cout << res[i][1] << '\t';
    }

    cout << endl;
}

//ex. 6
void find_reciprocal_of_all_elements(int* array, int n){
    int row = 0;
    int res[n * n - 1][2];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) {
                continue;
            }

            int multiply = multiply_elements_of_array(array, i, j, n);

            if (multiply == 1 && !elements_exist_in_matrix(res, row, array[i], array[j])){
                res[row][0] = array[i];
                res[row++][1] = array[j];
            }
        }
    }
    cout << "1" << '\t';
    for (int i = 0; i < row; i++){
        cout << res[i][0] << '\t';
    }
    for (int i = 0; i < row; i++) {
        cout << res[i][1] << '\t';
    }

    cout << endl;
    cout << "1" << '\t';

    for (int i = 0; i < row; i++) {
        cout << "1/" << res[i][1] << '\t';
    }
    for (int i = 0; i < row; i++) {
        cout << "1/" << res[i][0] << '\t';
    }

}

//ex. 7
int reciprocal_element_position(int* array, int n, unsigned int element){
    element--;

    for (unsigned int i = 0; i < n; i++) {
        if (element == i) {
            continue;
        }

        int multiply = multiply_elements_of_array(array, i, element, n);

        if (multiply == 1) {
            return i+1;
        }
    }

    return 0;
}

//ex.8


int mod(int x, int divisor){
    int m = x % divisor;
    return m + (m < 0 ? divisor : 0);
}

int multiply_array_elements(const int* array, int indexA, int indexB, int m){
    return mod(array[indexA] * array[indexB], m);
}


int find_reciprocal_element_position(const int* array, int n, int el) {
    for (int i = 0; i < n; i++) {
        if (i == el) {
            continue;
        }

        int multiply = multiply_array_elements(array, el, i, n);

        if (multiply == 1) {
            return i;
        }
    }

    return -1;
}

int division_elements_of_array(const int*array, int n, int indexA, int indexB){
    int pos = find_reciprocal_element_position(array, n, indexB);
    if (pos == -1) {
        return pos;
    }

    return multiply_array_elements(array, indexA, pos, n);
}

//ex.9
int quick_recursive_pow_0(int sizeOfZ, int a, int m){
    int k;
    for (k = 2; k < sizeOfZ; k++) {
        if (int(pow(a, k)) % sizeOfZ == 1) {
            break;
        }
    }

    return int(pow(a, m % k)) % sizeOfZ;
}

//ex. 10
int quick_recursive_pow(int m_1, int sizeOfZ_1, int l, int p, int res){
    if (m_1 == 0) {
        return res % sizeOfZ_1;
    }

    l = int(pow(l, p)) % sizeOfZ_1;
    if (m_1 & 0x1) {
        res *= l;
    }

    return quick_recursive_pow(m_1 >> 1, sizeOfZ_1, l, 2, res);
}

//ex.11
bool is_finite_field(int num){

    bool isTrue = true;
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            isTrue = false;
            break;
        }
    }
    return isTrue;

}

//ex.12
bool find_primitive_root(int* F_n, unsigned int n_n, unsigned int element) {
    int* arr= nullptr;
    arr = new int[n_n];

    int num_1;

    for (int i = 0; i < n_n; i++)
    {
        if (F_n[i] == element)
        {
            num_1 = F_n[i];
            break;
        }
    }

    int u = 0;
    arr[u] = 0;
    for (int i = 1; i < n_n; i++)
    {
        arr[u] = ((int)pow(num_1, i) % n_n);
        u++;
    }

    int T = 1;
    for (int i = 0; i < u; i++)
    {
        for (int k = i + 1; k < u; k++)
        {
            if (arr[i] == arr[k])
            {
                T = 0;
                break;
            }
        }
    }

    if (T == 0)
    {
        delete[]arr;
        arr = nullptr;

        return 0;
    }
    else if(T == 1)
    {

        delete[]arr;
        arr = nullptr;

        return 1;
    }

}

//ex.13
int find_all_primitive_roots(int* F_n, unsigned int n_n){

	int** primitive = nullptr;
    primitive = new int*[n_n];

	for (int i = 0; i<n_n; i++)
	{
        primitive[i] = new int[n_n];
	}

	int col = 0;
	for (int i = 1; i<n_n; i++)
	{
        primitive[0][col] = i;
		col++;
	}

	for (int i = 1, p = 1; i < n_n; i++,p++)
	{
		for (int j = 0; j<col; j++)
		{
            primitive[i][j] = ((int)pow(F_n[p], primitive[0][j])) % n_n;
		}
	}

	int i = 1;
	int j = 0;
	int prime = 0;
	while(i < n_n)
	{
		int T = 1;

		for (int k = j+1; k<col; k++)
		{
			if (primitive[i][j] == primitive[i][k])
			{
				T=0;
				i++;
				break;
			}
		}

		j++;
		if (T == 0)
		{
			j = 0;
		}

		if (T == 1 && j== col - 1)
		{
			prime = i;
			cout << prime << std::endl;
			i++;
			j = 0;
		}

	}

	for (int i = 0; i < n_n; i++)
	{
		delete[]primitive[i];
	}

	delete[]primitive;
    primitive = nullptr;

	return 0;
}

//ex.14
int discrete_log(int* F_n, unsigned int n, unsigned int element, unsigned int number){

    int* arr = nullptr;
    arr = new int[n];

    int numb;

    for (int i = 0; i < n; i++)
    {
        if (F_n[i] == element)
        {
            numb = F_n[i];
            break;
        }
    }

    int j = 0;
    arr[j] = 0;
    for (int i = 1; i < n; i++)
    {
        arr[j] = ((int)pow(numb, i) % n);
        j++;
    }

    int T = 1;

    for (int i = 0; i < j; i++)
    {
        for (int k=i+1; k < j; k++)
        {
            if (arr[i] == arr[k])
            {
                T = 0;
                break;
            }
        }
    }

    if (T == 0)
    {

        delete[]arr;
        arr = nullptr;
        return -1;
    }else if (T == 1){
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = (int)pow(numb, i);

            if (res % n == number){
                delete[]arr;
                arr = nullptr;

                return i;
            }
        }
    }
}

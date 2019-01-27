#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

const int k = 100;

int main() {

    int n, elem1, elem2;
    int array[k];

    // ex. 1
    cout << "Enter a number initializing the size of the residue class ring: ";

    cin >> n;

    fill_in_array(n, array);

    cout << "Output of Ex. 1: ";

    for (int i = 0; i < n; i++) {  // printing the array
        cout << array[i] << " ";
    }

    // ex.2
    cout << endl << "Enter two elements to sum: " << endl << "1. ";
    cin >> elem1;
    cout << endl << "2. ";
    cin >> elem2;

    while (elem1 <= 0 || elem1 >= n || elem2 <= 0 || elem2 >= n) {
        cout << "The elements must be in the interval [1, " << n << "]!";
        cout << endl << "Enter two elements to sum: " << endl << "1. ";
        cin >> elem1;
        cout << endl << "2. ";
        cin >> elem2;
    }
    cout << "The sum of the elements is: " << sum_of_elements(array, elem1 - 1, elem2 - 1, n) << endl;

    // ex. 3
    cout << endl << "Enter two elements to subtract: " << endl << "1. ";
    cin >> elem1;
    cout << endl << "2. ";
    cin >> elem2;

    while (elem1 <= 0 || elem1 >= n || elem2 <= 0 || elem2 >= n) {
        cout << "The elements must be in the interval [1, " << n << "]!";
        cout << endl << "Enter two elements to subtract: " << endl << "1. ";
        cin >> elem1;
        cout << endl << "2. ";
        cin >> elem2;
    }
    cout << "The subtraction of the elements is: " << abs(sub_of_elements(array, elem1 - 1, elem2 - 1)) << endl;

    // ex. 4
    cout << endl << "Enter two elements to multiply: " << endl << "1. ";
    cin >> elem1;
    cout << endl << "2. ";
    cin >> elem2;

    while (elem1 <= 0 || elem1 >= n || elem2 <= 0 || elem2 >= n) {
        cout << "The elements must be in the interval [1, " << n << "]!";
        cout << endl << "Enter two elements to multiply: " << endl << "1. ";
        cin >> elem1;
        cout << endl << "2. ";
        cin >> elem2;
    }
    cout << "The multiplication of the elements is: " << mul_of_elements(array, elem1 - 1, elem2 - 1) % n << endl;

    // ex. 5
    cout << "Problem 5: " << endl << "Swapped elements means their multiplication would return 1 in the chosen RCR" << endl;

    multiply_elements_equal_one(array, n);

    //ex. 6
    cout << "Problem 6: " << endl << "Under every element is their reciprocal value in the chosen RCR" << endl;
    find_reciprocal_of_all_elements(array, n);

    //ex. 7
    int element;
    cout << endl << "Problem 7: ";
    cout << "Which element to find reciprocal element of: ";
    cin >> element;
    int pos = reciprocal_element_position(array, n, element);
    if (pos == 0) {
        cout << "This one doesn't have a reciprocal element in this residue class ring!" << endl;
    } else {
        cout << "Position of reciprocal element " << element << " is the " << pos << "th element in the chosen RCR" << endl;
    }
    //ex.8
    int x, y;
    cout << "Enter two elements from the chosen RCR:" << endl << "x: "; cin >> x;
    cout << endl << "y: "; cin >> y;

    int division = division_elements_of_array(array, n, x, y);
    cout << "The division " << x << "/" << y << " in the chosen RCR equals " << division << endl;

    //ex.9
    int sizeOfZ, m, a;

    cout << "Problem 9: " << endl << "Enter residue class ring size, base and exponent respectively:" << endl;
    cout << "Residue class ring size: "; cin >> sizeOfZ;
    cout << endl << "Base: "; cin >> a;
    cout << endl << "Exponent: "; cin >> m;

    int recursivePowResult_0 = quick_recursive_pow_0(sizeOfZ, a, m);
    cout << endl << a << "^" << m << " in Z_" << sizeOfZ << " = " << recursivePowResult_0 << endl;

    //ex.10
    int sizeOfZ_1, m_1, a_1;

    cout << "Problem 10: " << endl << "Enter residue class ring size, base and exponent respectively:" << endl;
    cout << "Residue class ring size: "; cin >> sizeOfZ_1;
    cout << endl << "Base: "; cin >> a_1;
    cout << endl << "Exponent: "; cin >> m_1;

    int recursivePowResult_1 = quick_recursive_pow(m_1, sizeOfZ_1, a_1);

    cout << endl << a_1 << "^" << m_1 << " in Z_" << sizeOfZ_1 << " = " << recursivePowResult_1 << endl;

    //ex. 11
    int num;
    bool isTrue;

    cout << "Either reenter the previous size of the RCR or enter a new one to check if it's a finite field: "; cin >> num;

    isTrue = is_finite_field(num);

    if(isTrue == true){
        cout << endl << "F_" << num << " is a finite field" << endl;
    } else{
        cout << "F_" << num << " is not a finite field, but a residue class ring => Z_" << num << endl;
    }

    //ex.12
    int n_12;

    cout << endl;
	cout << "Problem 12: " << endl;
	cout << "Enter a size for the finite field in the last 3 problems: "; cin >> n_12;

	cout << "Enter a number to check if it's a primitive root: " << endl;
	do
	{
		cin >> element;
		if (element < 0 || element > n_12-1)
		{
			cout << "Number must be between 1 and " << n_12 << endl;
		}
	} while (element < 0 || element > n_12-1);

	cout << endl;
	cout << "Is " << element << " a primitive root of the chosen finite field?" << endl;
	cout << "Answer: " << boolalpha << find_primitive_root(array, n_12, element) << endl;

	//ex.13
    cout << "Problem 13: " << endl;
    cout << endl;
    cout << "All primes roots in this field are:" << endl;
    find_all_primitive_roots(array, n_12);
    cout << endl;

    //ex.14
    int number;
    cout << "Problem 14:" << endl;
    cout << endl;
    cout << "Enter a base for dlog: ";
    do
    {
        cin >> element;

    } while (element<0 || element>n_12 - 1);

    cout << endl;
    cout << "Enter an element for dlog: " << endl;
    do
    {
        cin >> number;
        cout << "Enter another element for dlog: " << endl;
    } while (number<0 || number>n_12);

    cout << "The discrete logarithm of " << number << " to the base " << element << "mod" << n_12 << " is: ";
    cout<< discrete_log(array, n_12, element, number)%n_12;
    cout << endl;

    return 0;
}

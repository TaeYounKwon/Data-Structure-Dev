#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size, size_t position=0, size_t minPosition=0);
void SelectionSort(int array[], size_t size);


int main() {
    const size_t ELEMENTS = 7;
    const size_t TESTS = 3;
    int data[][ELEMENTS] = {
            {7, 5, 4, 1, 3, 0, 9},
            {1, 5, 9, 11, 13, 20, 29},
            {8, 5, 4, 1, 3, 4, 0}};

    int minimumSolutions[] = {5, 0, 6};
    int sortedArrays[][7] = {
            {0, 1, 3, 4, 5, 7, 9},
            {1, 5, 9, 11, 13, 20, 29},
            {0, 1, 3, 4, 4, 5, 8}};

    unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

    string strings[] = {"hello", "aardvark", "reviver"};
    string reverses[] = {"olleh", "kravdraa", "reviver"};
    size_t passed = 0;
    int minimumResponses[TESTS];
    for (int i = 0; i < TESTS; ++i) {
        minimumResponses[i] = -1;
    }

    cout << "Testing Fibonacci" << endl;
    for (int i = 0; i < 10; ++i) {
        unsigned long long int fibonacci = Fibonacci(i);
        if (fibonacci == fibonacciSequence[i])
            cout << "\tPassed " << ++passed << " tests" << endl;
    }


    cout << "Testing Minimum Position Finding" << endl;
    for (int i = 0; i < TESTS; ++i) {
        minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
        if (minimumResponses[i] == minimumSolutions[i]){
            cout << "\tPassed " << ++passed << " tests" << endl;
        }
    }
    cout << "Testing Sorting" << endl;
    bool equal;
    for (int i = 0; i < TESTS; ++i) {
        SelectionSort(data[i], ELEMENTS);
        equal = true;
        for (int j = 0; j < ELEMENTS; ++j) {
            if (data[i][j] != sortedArrays[i][j]){
                equal = false;
                cerr << "Test " << i << " position " << j << " values: ";
                cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
                break;
            }
        }
        if (equal){
            cout << "\tPassed " << ++passed << " tests" << endl;
        }
    }

    cout << "Testing Reverse Strings" << endl;
    stringstream out;
    for (int i = 0; i < TESTS; ++i) {
        out.clear();
        out.str("") ;
        PrintReverseString(strings[i], out);
        if (out.str() == reverses[i])
            cout << "\tPassed " << ++passed << " tests" << endl;
    }

    return 0;
}

unsigned long long int Fibonacci(unsigned int n){
    if((n==0)||(n==1)) {
        return n;
    }
    else {
        return(Fibonacci(n-1)+Fibonacci(n-2));
    }


}

void PrintReverseString(const string& str, ostream& output){
    string _tmp;
    string _stringSaved=str;
    if(str.size()==0)
        return;
    else
    {
        _tmp += _stringSaved.back();
        _stringSaved.pop_back();
        PrintReverseString(_stringSaved, output << _tmp);
    }
}

// You may change the parameters of these functions
size_t MinimumPosition(const int array[],  size_t size, size_t position, size_t minPosition){
    if(position>size)
        exit(1);
    if(position==size)
        return minPosition;
    else {
        if (array[position] < array[minPosition])
            return MinimumPosition(array, size, position + 1, position);
        else
            return MinimumPosition(array, size, position + 1, minPosition);
    }
}
void SelectionSort(int array[], size_t size){
    size_t _indexSmall=0;

    if(size==0)
        return;

    for (size_t i = 0; i < size - 1; ++i)
    {
        _indexSmall = i;
        size_t j = i + 1;
        if (array[j] < array[_indexSmall])
        {
            _indexSmall = j;
            auto temp = array[i];
            array[i] = array[_indexSmall];
            array[_indexSmall] = temp;
            ++j;
        }
    }
    size--;
    SelectionSort(array, size);
}
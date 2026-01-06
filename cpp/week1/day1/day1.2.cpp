// Time complexity test
// Write a Cpp program that calculates the sum of numbers from 1 to N.

#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;

// Find sum (Iterative - linear approach)
long long sumLinear(long long num)
{
    long long sum = 0;
    for (long long i = 0; i <= num; i++)
    {
        sum += i;
    }
    return sum;
}

// Find sum (Mathematical - constant approach) (Gauss method)
long long sumConstant(long long num)
{
    return (num * (num + 1)) / 2;
}


int main()
{
    long long N;
    cout << "Enter a big number: ";
    cin >> N;
    cout << endl;

    // Measure time for the linear approach O(N) 
    auto start = high_resolution_clock::now();
    long long linearResult = sumLinear(N);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);

    cout << "The sum of the N numbers are: " << linearResult << " (linear approach)" << endl;
    cout << "The time it took to calculate (in microseconds): " << duration1.count() << endl;
    cout << endl;

    
    // Measure time for the constant approach O(1) 
    start = high_resolution_clock::now();
    long long constResult = sumConstant(N);
    stop = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop - start);

    cout << "The sum of the N numbers are: " << constResult << " (constant approach)" << endl;
    cout << "The time it took to calculate (in microseconds): " << duration2.count() << endl;
    cout << endl;

    return 0;
}

/*
    Test result:
        
    Enter a big number: 1000000

    The sum of the N numbers are: 500000500000 (linear approach)
    The time it took to calculate (in microseconds): 2005

    The sum of the N numbers are: 500000500000 (constant approach)
    The time it took to calculate (in microseconds): 0
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 1, m;
    double a, x, S = 0, mnog, eps = 0.0001;

    // Input x with the constraint |x| < 1
    cout << "Enter |x| < 1: \n";
    cin >> x;
    while (fabs(x) >= 1)
    {
        cout << "Invalid x! Enter |x| < 1: \n";
        cin >> x;
    };

    // Input the number of terms in the series
    cout << "Enter the number of terms \n";
    cin >> m;
    cout << endl;

    // Initialize the first term of the series
    a = 3 * x * x / 24;
    S = a; // Set the sum to the first term

    // Compute the sum of the series, either based on the required precision or the number of terms
    while (fabs(a) > eps && i <= m)
    {
        // Calculate the next term using the recurrence relation
        mnog = -pow(x, 2) / ((2.0 * i + 4.0) * (2.0 * i + 1.0));
        a = a * mnog; // Update the next term
        S += a; // Add the term to the sum
        i++; // Increment the counter
    };

    // Set precision for output and display the results
    cout.precision(8);
    cout << "S = " << S << endl; // Display the sum
    cout << "i = " << i << endl; // Display the number of terms used

    // Check the result by calculating a reference value using the formula
    cout << "Reference formula = " << ((1.0 - cos(x) - (x * sin(x))) / (x * x)) + (1.0 / 2.0) << endl;
    // Display the difference between the calculated sum and the reference value
    cout << "Difference = " << fabs(((1.0 - cos(x) - (x * sin(x))) / (x * x)) + (1.0 / 2.0) - S) << endl;

    return 0;
}

#include <iostream>
#include <limits> // To use numeric limits for clearing input stream
using namespace std;

// Class Sum to perform arithmetic operations
class Sum
{
private:
    double x;

public:
    // Constructor to initialize the value of x with input validation
    Sum()
    {
        x = getInput("Enter value for x: ");
    }

    // Function to get numeric input from the user
    double getInput(const string& prompt)
    {
        double value;
        while (true) // Loop until valid input is provided
        {
            cout << prompt;
            cin >> value;

            // Check if the input is valid
            if (cin.fail()) // If the input is not a valid doubleeger
            {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
                cout << "Invalid input! Please enter a numeric value." << endl;
            }
            else
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any leftover input
                return value; // Return the valid input
            }
        }
    }

    // Overloading the + operator
    void operator+(Sum ob)
    {
        cout << x << " + " << ob.x << " = " << x + ob.x << endl;
    }

    // Overloading the - operator
    void operator-(Sum ob)
    {
        cout << x << " - " << ob.x << " = " << x - ob.x << endl;
    }

    // Overloading the * operator
    void operator*(Sum ob)
    {
        cout << x << " * " << ob.x << " = " << x * ob.x << endl;
    }

    // Overloading the / operator
    void operator/(Sum ob)
    {
        if (ob.x != 0) // Check for division by zero
        {
            cout << x << " / " << ob.x << " = " << x / ob.x << endl;
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    }
};

int main()
{
    Sum ob1;
    Sum ob2;

    ob1 + ob2;  // Perform addition
    ob1 - ob2;  // Perform subtraction
    ob1 * ob2;  // Perform multiplication
    ob1 / ob2;  // Perform division

    return 0;
}

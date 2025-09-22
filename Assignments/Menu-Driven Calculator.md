### Preassignment Rambling
The first thing I thought of when creating this program is that it is much more readable and user-friendly than Java, in my opinion.
I personally like how much more readable it is to get user input in C++ than in Java.

Java:
```java
Import java.util.Scanner;

public class Calculator {
	public static void main(String[] args) {
		Scanner scnr = new Scanner (System.in); 
		int input = scnr.nextInt();

		System.out.println("Number: " + input);
	}
}
```

C++:
```cpp
#include <iostream>
using namespace std;

int main() {
	int input = 0;

	cin >> input;
	cout << "Number: " << input;
}
```
I wonder what context would lead programmers to prefer Java over C++, because there is definitely a reason Java is still used.

# Challenges faced

The first challenge I faced with this project was a large but avoidable syntax error that made the program act strangely. Instead of using `'\n'` for new lines, I typed `'\ln'`, which probably came from my natural tendency to type Java's `println` command. The code ran fine and ended smoothly, but it would generate something like this:

```
1 - Addition26682 - Subtraction26683 - Multiplication26684 - Division2668Please make your choice: 3
Test: num1 = 12668num2 = 22668choice = 32668
```
That last output is something I like to do to ensure the inputs give the correct choice. I implemented it something like this:
```cpp
cout << "Test:" << '\n'
<< "num1 = " << num1
<< "num2 = " << num2
<< "choice = " << choice;
```
Is there a quicker way to implement value testing in C++? Please let me know!

The last challenge I faced was forgetting to properly `return 1;` whenever I use `cerr`. I noticed this after testing my program and realizing that even when I put a negative number, the code would keep running, which is very unintended. I will learn to do this out of habit, just like putting semicolons where they need to be. 

This assignment also made me understand switch-case implementation more! I heavily struggled to do this assignment during Java Programming, but this assignment cleared it up for me. Thank you!

By the way, I use Visual Studio Code because I like how it looks, and it treats me well.

# The Code
```cpp
#include <iostream>
using namespace std;

int main() {
    double num1 = 0;
    double num2 = 0; 
    enum class Calculator { Add=1, Subtract=2, Multiply=3, Divide=4 };
    int choice{};

    cout << "Please Enter Your First Number: ";
    if (!(cin >> num1)) {  // Reads next input, checking if it's a valid number.
        cerr << "Invalid input." << '\n'; // Return an error if it is not a number
        return 1;
    }
    if (num1 < 0) {
        cerr << "Input cannot be negative." << '\n'; // Return an error if it is a negative number.
        return 1;
    }

    cout << "Please Enter Your Second Number: ";
    if (!(cin >> num2)) {  // Reads next input, checking if it's a valid number.
        cerr << "Invalid input."; // Return an error if it is not a number
        return 1;
    }
    if (num2 < 0) {
        cerr << "Input cannot be negative." << '\n'; // Return an error if it is a negative number.
        return 1;
    }

    // Show the user the valid options
    cout << '\n' 
    << "1 - Addition" << '\n'
    << "2 - Subtraction" << '\n'
    << "3 - Multiplication" << '\n'
    << "4 - Division" << '\n'
    << "Please make your choice: ";
    cin >> choice; // reads the user's input, valid values: 1, 2, 3, 4
    

    /* converts choice into each valid value: 1, 2, 3, 4. 
    *This acts as a check for a valid input. 
    */
    switch (static_cast<Calculator>(choice)) { 
        case Calculator::Add:
        cout << num1 << " + " << num2 << " = " << num1 + num2; // Perform Addition, display result
            break;
        case Calculator::Subtract:
        cout << num1 << " - " << num2 << " = " << num1 - num2; // Perform Subtraction, display result
            break;
        case Calculator::Multiply:
        cout << num1 << " * " << num2 << " = " << num1 * num2; // Perform Multiplication, display result
            break;
        case Calculator::Divide:
        if (num2 == 0) {
            cerr << "Undefined: Divisor cannot be zero."; /*Edge case: num2 is zero*/
            return 1;                                              /* return an error INSIDE the if-statement so it doesn't divide by zero*/
        }
        cout << num1 << " / " << num2 << " = " << num1 / num2; // Perform Division, display result
            break;
        default:
            cerr << "Invalid input. "; // Invalid case: return an error
            return 1;
        }

    return 0;
}
```
# The video
```
url
```

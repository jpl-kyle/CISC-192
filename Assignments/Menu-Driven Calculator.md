### Preassignment Rambling
The first thing I thought of when creating this program is that it is much more readable and user friendly than Java, in my opinion.
I personally like how much readable it is to get user input in C++ than Java.

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
I wonder what context would have programmers prefer Java over C++, because there definitely is a reason Java is still used.

# Challenges faced

The first challenge I faced with this project was a large but avoidable syntax usage that made the program act strangely. Instead of using `'\n'` for new lines, I typed `'\nl'`, which probably came from my natural tendency to type java's `println` command. The code ran fine and ended smoothly, but it would generate something like this this:

`1 - Addition26682 - Subtraction26683 - Multiplication26684 - Division2668Please make your choice: 3
Test: num1 = 12668num2 = 22668choice = 32668`

The last challenge I faced was forgetting to properly return 1; whenever I use cerr. I noticed this after testing my program and realizing that even when I put a negative number, the code would keep running, which is very unintended. I will learn to do this out of habit, just like putting semicolons where they need to be. 

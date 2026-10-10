# Loan Amortization & Cash Flow Engine

A robust command-line financial calculation tool written in **C++** designed to process complex loan structures, compute exact monthly payments, and generate detailed month-by-month amortization schedules.

## Features
* **Flexible Loan Modeling:** Supports both standard fully-amortizing loans and balloon payment structures.
* **Input Validation:** Built-in error handling via `std::cin` stream clearing to prevent crashes from invalid user inputs.
* **Precise Financial Formatting:** Uses `<iomanip>` to output clean, currency-formatted amortization schedules tracking monthly principal, interest, and remaining balance over time.

## Tech Stack
* Language: C++

## How to Run

### Option 1: Using Visual Studio (Windows)
1. Double-click the **`Loan Calculator.sln`** file to open the solution in Visual Studio.
2. Set the build configuration to **Release** or **Debug**.
3. Press **Ctrl + F5** (or click the **Local Windows Debugger** button) to build and run the program.

### Option 2: Using the Command Line (g++)
1. Clone the repository:
   ```bash
   git clone https://github.com/norealityyy/Loan-Amortization_and_Cash-Flow-Engine
2. Navigate to the project directory:
   ```bash
   cd Loan-Amortization_and_Cash-Flow-Engine
3. Compile the source files:
   ```bash
   g++ main.cpp functions.cpp -o loan_calculator
4. Run the executable:
   * **Windows:** `loan_calculator.exe`
   * **Mac/Linux:** `./loan_calculator`
### Sample Output

```
Enter principal amount: 250000
Enter interest rate without decimal points (e.g., enter 75 for 7.5%): 65
Enter the term of the loan in years: 30
Enter loan type - amortizing (a) or balloon (b): a

Monthly payment for an amortizing loan is $1580.17

Month     Payment        Principal      Interest       Balance        
----------------------------------------------------------------------
1         $1580.17       $226.00        $1354.17       $249774.00    
2         $1580.17       $227.23        $1352.94       $249546.77    
...

#include <string> 
#include <vector> 
#include <iostream> 

using namespace std; 

// first make sure all chars in string are digits 
bool digits_only(string num) {
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < num.length(); i++) {
        int digit = (int) num[i];
        if (digit < 0 || digit > 9) {
            return false; 
        }
    }
    return true;
}

// now double each digit from right to left 
int[] double_right_left(string num) {
    int digits[num.length()]; 
    for (int i = num.length() - 1; i > -1; i--) {
        digit = (int) num[i];
        digits.push_back(digit);
    }
    // now double every second digit in digits[]
    for (int i = 0; i < digits.length; i++) {
        if (i % 2 == 1) {
            digits[i] = digits[i] * 2;
            if (digits[i] > 9) {                  // take sum of digits if greater than 10 
                digits[i] = digits[i] % 10 + 1
            }
        }
    }
    return digits; 
}

// take the sum of all the digits
int sum_all(int[] digits) {
    sum = 0; 
    for (int i = 0; i < digits.length; i++) {
        sum += digits[i];
    }
    return sum; 
}

// identify the bank that issued the card based on the number 
string identify_bank(string num) {
    int first = (int) num[0]; 
    string bank = ""
    if (first == 3) {
        bank = "American Express"
    } else if (first == 4) {
        bank = "Visa"
    } else if (first == 5) {
        bank = "MasterCard"
    } else if (first == 6) {
        bank = "Discover"
    } else {
        bank = "Unknown bank" 
    }
    return bank; 
}

// identify industry that issued card based on card number 
string identify_industry(string num) {
    int first = (int) num[0]; 
    string industry = ""
    if (first == 1 || first == 2) {
        industry = "Airline"
    } else if (first == 3) {
        industry = "Travel"
    } else if (first == 4 || first == 5 || first == 6) {
        industry = "Bank"
    } else if (first == 7) {
        industry = "Gas"
    }
    return industry
}

// main method to test inputted credit card numbers
int main() {
    cout << "Enter a credit card number to validate. Enter 'exit' to quit anytime."
    string ccnum; 

    while (true) {
        cin >> ccnum; 
        if (ccnum == "exit" || ccnum == ccnum == "EXIT") {
            break; 
        }

        if (!digits_only(ccnum)) {
            cout << "Invalid input. Please enter a new number." 
            return; 
        }

        // double and sum the digits of the inputted number
        int doubled[ccnum.length()] = double_right_left(ccnum); 
        int num_sum = sum_all(doubled); 

        // now check if digit is a multiple of 10 
        bool isValid = false; 
        if (num_sum % 10 == 0) {
            cout << "This is a valid number"
            isValid = true; 
        } else {
            cout << "This is an invalid number"
            isValid = false; 
        }

        // only check the bank and industry if the card number is valid 
        if (isValid) {
            bank = identify_bank(ccnum); 
            industry = identify_industry(ccnum); 
            cout << "The bank is: " + bank;
            cout << "The industry is " + industry; 
        }
    }
}

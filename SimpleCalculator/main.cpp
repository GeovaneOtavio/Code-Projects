#include <iostream>
#include <string>

// Function to additions;
double addition(double n1, double n2){
    return n1 + n2;
}

// Function to subtractions;
double subtraction(double n1, double n2){
    return n1 - n2;
}

// Function to multiplications;
double multiplication(double n1, double n2){
    return n1 * n2;
}

// Functions to divisions;
double division(double n1, double n2){
    // 'Try' to check if it has division by 0;
    try{
        if(n2 > 0)
            return n1 / n2;

        throw std::string("Error due to a division by 0 or minor!");
    }
    catch (std::string error){
        throw error;
    }
}

// Function to check operators, if it has another character unless the desired operator, it returns an arror;
double operators(char oper, double n1, double n2){
    try{
        switch (oper) {
            case '+':
                return addition(n1, n2);

            case '-':
                return subtraction(n1, n2);

            case '*':
                return multiplication(n1, n2);

            case '/':
                return division(n1, n2);

            default:
                throw std::string("Error due to wrong operator!");
        }
    } catch (std::string error) {
        throw error;
    }
}

// Main thread;
int main() {

    // Variables;
    char contn = 'Y', oper =' ';
    double n1, n2;

    // Loop;
    do{
        std::cout << "Welcome to Simple Calculator!\n";
        std::cout << "Please enter the operator (+, -, *, /):";
        std::cin >> oper;
        std::cout << "Enter the first number:";
        std::cin >> n1;
        std::cout << "Enter the second number:";
        std::cin >> n2;

        // All the functions are called here;
        try {
            double result = operators(oper, n1, n2);
            std::cout << "Result: " << n1 << oper << n2 << " = " << result << std::endl;
        } catch (std::string error){
            std::cout << error << "\nPlease try again!\n";
        }

        // Check with the user if them want to use the calculator again;
        std::cout << "Do you wat to perform another calculation? (Y to Yes):";
        std::cin >> contn;

        contn = toupper(contn);

    } while (contn == 'Y');

    std::cout << "Thank you for using Simple Calculator\n";
    return 0;
}
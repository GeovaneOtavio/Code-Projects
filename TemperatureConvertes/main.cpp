#include <iostream>

int main() {
    char contn = 'Y';
    int option = 0;
    float temperature = 0.0;

    do{

        std::cout << "Welcome to Temperature Converter!\n"
                     "Select the temperature scale you want to convert from:\n"
                     "1. Celsius\n"
                     "2. Fahrenheit\n"
                     "3. Kelvin\n"
                     "Enter your choice:";
        std::cin >> option;

        try {
            if(option == 1){
                std::cout << "Enter the temperature in Celsius:";
                std::cin >> temperature;
                if(temperature < -273.15)
                    throw std::string("The minimum possible temperature is -273.15 °C");
                std::cout << "Converted temperatures:\n"
                             "Fahrenheit: " << (temperature * 1.8 + 32) << " °F\n"
                             "Kelvin: " << (temperature + 273.15) << " K\n";

            } else if(option == 2){
                std::cout << "Enter the temperature in Fahrenheit:";
                std::cin >> temperature;
                if(temperature < -459.67)
                    throw std::string("The minimum possible temperature is -459,67 °F");
                std::cout << "Converted temperatures:\n"
                             "Celsius: " << ((temperature - 32) * (0.555556)) << " °C\n"
                             "Kelvin: " << ((temperature - 32) * (0.555556) + 273.15) << " K\n";

            } else if(option == 3){
                std::cout << "Enter the temperature in Kelvin:";
                std::cin >> temperature;
                if(temperature < 0)
                    throw std::string("The minimum possible temperature is 0 K");
                std::cout << "Converted temperatures:\n"
                             "Celsius: " << (temperature - 273.15) << " °C\n"
                             "Fahrenheit: " << ((temperature - 273.15) * 1.8 + 32) << " °F\n";

            } else
                throw std::string("Please select a possible option!");

        } catch (std::string error){
            std::cout << error << std::endl;
        }
        std::cout << "Do you want to convert another temperature? (Y to Yes):";
        std::cin >> contn;
        contn = toupper(contn);

    } while (contn == 'Y');

    std::cout << "Thank you for using Temperature Converter!\n";

    return 0;
}

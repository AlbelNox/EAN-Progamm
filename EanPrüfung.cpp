#include <iostream>
#include <string>
#include <regex>
#include <assert.h>

using namespace std;

//constructors
bool checkValidEAN(string input);
bool eanValidation(string input);
void waitForUser();
bool isPlaceholder(string input);
void eanCheckProgram();
void runTests();
void runTestsAssert();

int main()
{
    int input = 123;
    while(input != 0)
    {
        cout << "\033[34mMainmenue:\033[0m \n1= runTests, 2= EanCheckProgram. 0= endProgram\n";
        cin >> input;
        switch (input)
        {
        case 1:
            runTests();
            runTestsAssert();
            break;
        case 2:
            eanCheckProgram();
            break;
        case 0:
            break;
        default:
            break;
        }
    }
    return 0;
}

void eanCheckProgram()
{
    string input = "";
    system("cls");
    
    while(input != "exit")
    {
        cout << "\033[34mEAN Check Menue\033[0m: \nTo exit the Programm type 'exit'\nGib die zu ueberpruefende EAN Nummer ein:\n";
        cin >> input;
        if(input == "exit")
        {
            waitForUser();
            break;
        }
        if(!checkValidEAN(input))
        {
            waitForUser();
            continue;
        }
        if(!eanValidation(input))
        {
            cout << "EAN is \033[31minvalid\033[0m\n";
            waitForUser();
            continue;
        }
        cout << "EAN is \033[32mValid!\033[0m\n";
        waitForUser();
    }
}

//verify input is valid
bool checkValidEAN(string input)
{
    regex regexNumber("^[0-9]*$");  // just digits are allowed

    if(regex_match(input, regexNumber)) //verify digits
    {
        if(input.length() == 8 || input.length() == 13) //verify valid length
        {
            if(isPlaceholder(input))
            {
                cout << "Identified placeholder ean: " << input << "\n";
                return false;
            }
            return true;
        }
        else
        {
            cout << "Invalid input the EAN should have 8 or 13 digits!\n";
            return false;
        }
    }
    else
    {
        cout << "Invalid input, the EAN should be 8 or 13 'digits'!\n";
        return false;
    }
}

//check input is valid ean or not
bool eanValidation(string input)
{
    int sum = 0;
    bool usethree = true;

    //calculate checkdigit from 7 or 12 digits without checkdigit
    for(int i = input.length() -2; i >= 0; i--)
    {
        int digit = input[i] - '0'; //string into int
        sum += digit * (usethree ? 3 : 1);
        usethree = !usethree;
    }
    
    int checkDigit = (10 - (sum % 10)) % 10;    //build checkdigit to compare from calculation
    int givenCheckDigit = input.back() - '0';   //get checkdigit -> string into int

    if(checkDigit != givenCheckDigit)
    {
        return false;
    }
    return true;
}

bool isPlaceholder(string input)
{
    regex shortEan("^[0]{8}$"); //regex 8 zeros
    regex longEan("^[0]{13}$"); //regex 13 zeros

    if(regex_match(input, shortEan) || regex_match(input, longEan))
    {
        return true;
    }
    return false;
}

void waitForUser()
{
    cout << "\nPress Enter to continue ...";
    cin.ignore();
    cin.get();
    system("cls");
}

void runTests()
{
    string validEans[] = 
    {
        "12345670", "12457861", "1234567891231", "9876543217882"
    };
    string invalidEans[] =
    {
        "12345678", "12457898", "1234567891234", "9876543217884"
    };
    string placeholderEans[] =
    {
        "00000000", "0000000000000"
    };
    
    cout << "\n--- Test \033[32mvalid\033[0m EANs ---\n";
    for (const string& ean : validEans) {
        if(checkValidEAN(ean))
        {
            bool result = eanValidation(ean);
            cout << "EAN: " << ean << " -> " << (result ? " \033[32mvalid\033[0m" : " \033[31minvalid\033[0m") << endl;
        }
    }

    cout << "\n--- Test \033[31minvalid\033[0m EANs ---\n";
    for (const string& ean : invalidEans) {
        if(checkValidEAN(ean))
        {
            bool result = eanValidation(ean);
            cout << "EAN: " << ean << " -> " << (result ? " \033[32mvalid\033[0m" : " \033[31minvalid\033[0m") << endl;
        }
    }

    cout << "\n--- Test \033[33mplaceholder\033[0m EANs ---\n";
    for (const string& ean : placeholderEans) {
        if(checkValidEAN(ean))
        {
            bool result = eanValidation(ean);
            cout << "EAN: " << ean << " -> " << (result ? " \033[32mvalid\033[0m" : " \033[31minvalid\033[0m") << endl;
        }
    }
}

void runTestsAssert()
{
    string validEans[] = 
    {
        "12345670", "12457861", "1234567891231", "9876543217882"
    };
    string invalidEans[] =
    {
        "12345678", "12457898", "1234567891234", "9876543217884"
    };
    string placeholderEans[] =
    {
        "00000000", "0000000000000"
    };
    cout << "\n--- \033[35mAssert Tests\033[0m ---\n";
    // Test valid EANs
    for (const string& ean : validEans) {
        assert(checkValidEAN(ean));      
        assert(eanValidation(ean));      
    }

    // Test invalid EANs
    for (const string& ean : invalidEans) {
        assert(checkValidEAN(ean));      
        assert(!eanValidation(ean));     
    }

    // Test placeholder
    for (const string& ean : placeholderEans) {
        assert(!checkValidEAN(ean));     
    }

    cout << "\033[32mAll Assert Tests Succeed!\033[0m\n";
    waitForUser();
}
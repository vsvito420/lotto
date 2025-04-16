#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <limits>

// Base class for lottery systems
class LotterySystem {
protected:
    std::vector<int> selectedNumbers;
    std::vector<int> manualNumbers;
    std::map<int, int> frequencyMap;
    int numberOfTickets;
    bool useManualNumbers;
    std::string systemName;
    
    // Random number generator
    std::random_device rd;
    std::mt19937 gen;

public:
    // Constructor
    LotterySystem(const std::string& name) : systemName(name), numberOfTickets(1), useManualNumbers(false), gen(rd()) {
        manualNumbers.reserve(30); // Reserve space for up to 30 manual numbers
    }
    
    // Destructor
    virtual ~LotterySystem() {
        clearData();
    }
    
    // Clear all data
    void clearData() {
        selectedNumbers.clear();
        frequencyMap.clear();
    }
    
    // Set number of tickets
    void setNumberOfTickets(int tickets) {
        numberOfTickets = tickets;
    }
    
    // Set whether to use manual numbers
    void setUseManualNumbers(bool use) {
        useManualNumbers = use;
    }
    
    // Get the system name
    std::string getSystemName() const {
        return systemName;
    }
    
    // Add a manual number
    bool addManualNumber(int number) {
        // Check if the number is already in the list
        if (std::find(manualNumbers.begin(), manualNumbers.end(), number) != manualNumbers.end()) {
            return false; // Number already exists
        }
        
        manualNumbers.push_back(number);
        return true;
    }
    
    // Clear manual numbers
    void clearManualNumbers() {
        manualNumbers.clear();
    }
    
    // Get manual numbers
    const std::vector<int>& getManualNumbers() const {
        return manualNumbers;
    }
    
    // Save manual numbers to file
    bool saveManualNumbers(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        file << systemName << std::endl;
        for (int number : manualNumbers) {
            file << number << std::endl;
        }
        
        file.close();
        return true;
    }
    
    // Load manual numbers from file
    bool loadManualNumbers(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }
        
        std::string line;
        std::getline(file, line); // Read system name
        
        if (line != systemName) {
            file.close();
            return false; // Wrong system
        }
        
        clearManualNumbers();
        
        int number;
        while (file >> number) {
            addManualNumber(number);
        }
        
        file.close();
        return true;
    }
    
    // Generate lottery numbers - to be implemented by derived classes
    virtual void generateNumbers() = 0;
    
    // Print lottery ticket - to be implemented by derived classes
    virtual void printTicket() const = 0;
    
    // Print frequency distribution
    void printFrequencyDistribution() const {
        std::cout << "\nFrequency Distribution for " << systemName << ":" << std::endl;
        for (const auto& pair : frequencyMap) {
            std::cout << "Number " << pair.first << ": " << pair.second << " times" << std::endl;
        }
    }
    
    // Update frequency map
    void updateFrequencyMap(const std::vector<int>& numbers) {
        for (int number : numbers) {
            frequencyMap[number]++;
        }
    }
};

// Derived class for Lotto 6 aus 49
class Lotto6aus49 : public LotterySystem {
private:
    static const int MAX_NUMBER = 49;
    static const int NUMBERS_PER_TICKET = 6;

public:
    // Constructor
    Lotto6aus49() : LotterySystem("Lotto 6 aus 49") {}
    
    // Generate lottery numbers
    void generateNumbers() override {
        clearData();
        
        for (int ticket = 0; ticket < numberOfTickets; ticket++) {
            std::vector<int> ticketNumbers;
            
            if (useManualNumbers && !manualNumbers.empty()) {
                // Use manual numbers if available
                std::vector<int> validManualNumbers;
                for (int num : manualNumbers) {
                    if (num >= 1 && num <= MAX_NUMBER) {
                        validManualNumbers.push_back(num);
                    }
                }
                
                // If we have enough valid manual numbers
                if (validManualNumbers.size() >= NUMBERS_PER_TICKET) {
                    // Shuffle the manual numbers
                    std::shuffle(validManualNumbers.begin(), validManualNumbers.end(), gen);
                    
                    // Take the first NUMBERS_PER_TICKET numbers
                    ticketNumbers.assign(validManualNumbers.begin(), 
                                        validManualNumbers.begin() + NUMBERS_PER_TICKET);
                } else {
                    // Not enough manual numbers, generate random ones
                    generateRandomNumbers(ticketNumbers);
                }
            } else {
                // Generate random numbers
                generateRandomNumbers(ticketNumbers);
            }
            
            // Sort the numbers
            std::sort(ticketNumbers.begin(), ticketNumbers.end());
            
            // Add to selected numbers
            selectedNumbers.insert(selectedNumbers.end(), ticketNumbers.begin(), ticketNumbers.end());
            
            // Update frequency map
            updateFrequencyMap(ticketNumbers);
        }
    }
    
    // Print lottery ticket
    void printTicket() const override {
        std::cout << "\n--- " << systemName << " Ticket ---" << std::endl;
        
        int ticketCount = 0;
        for (size_t i = 0; i < selectedNumbers.size(); i += NUMBERS_PER_TICKET) {
            std::cout << "Ticket " << ++ticketCount << ": ";
            
            for (size_t j = i; j < i + NUMBERS_PER_TICKET && j < selectedNumbers.size(); j++) {
                std::cout << selectedNumbers[j] << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
private:
    // Generate random numbers for a ticket
    void generateRandomNumbers(std::vector<int>& ticketNumbers) {
        std::vector<int> allNumbers(MAX_NUMBER);
        for (int i = 0; i < MAX_NUMBER; i++) {
            allNumbers[i] = i + 1;
        }
        
        std::shuffle(allNumbers.begin(), allNumbers.end(), gen);
        
        ticketNumbers.assign(allNumbers.begin(), allNumbers.begin() + NUMBERS_PER_TICKET);
    }
};

// Derived class for Eurolotto
class Eurolotto : public LotterySystem {
private:
    static const int MAX_MAIN_NUMBER = 50;
    static const int MAX_EURO_NUMBER = 12;
    static const int MAIN_NUMBERS_PER_TICKET = 5;
    static const int EURO_NUMBERS_PER_TICKET = 2;
    
    std::vector<int> selectedEuroNumbers;
    std::map<int, int> euroFrequencyMap;

public:
    // Constructor
    Eurolotto() : LotterySystem("Eurolotto") {}
    
    // Clear all data
    void clearData() {
        LotterySystem::clearData();
        selectedEuroNumbers.clear();
        euroFrequencyMap.clear();
    }
    
    // Generate lottery numbers
    void generateNumbers() override {
        clearData();
        
        for (int ticket = 0; ticket < numberOfTickets; ticket++) {
            std::vector<int> ticketMainNumbers;
            std::vector<int> ticketEuroNumbers;
            
            if (useManualNumbers && !manualNumbers.empty()) {
                // Use manual numbers if available
                std::vector<int> validMainNumbers;
                std::vector<int> validEuroNumbers;
                
                for (int num : manualNumbers) {
                    if (num >= 1 && num <= MAX_MAIN_NUMBER) {
                        validMainNumbers.push_back(num);
                    } else if (num >= 1 && num <= MAX_EURO_NUMBER) {
                        validEuroNumbers.push_back(num);
                    }
                }
                
                // If we have enough valid manual numbers
                if (validMainNumbers.size() >= MAIN_NUMBERS_PER_TICKET && 
                    validEuroNumbers.size() >= EURO_NUMBERS_PER_TICKET) {
                    // Shuffle the manual numbers
                    std::shuffle(validMainNumbers.begin(), validMainNumbers.end(), gen);
                    std::shuffle(validEuroNumbers.begin(), validEuroNumbers.end(), gen);
                    
                    // Take the first numbers
                    ticketMainNumbers.assign(validMainNumbers.begin(), 
                                           validMainNumbers.begin() + MAIN_NUMBERS_PER_TICKET);
                    ticketEuroNumbers.assign(validEuroNumbers.begin(), 
                                           validEuroNumbers.begin() + EURO_NUMBERS_PER_TICKET);
                } else {
                    // Not enough manual numbers, generate random ones
                    generateRandomNumbers(ticketMainNumbers, ticketEuroNumbers);
                }
            } else {
                // Generate random numbers
                generateRandomNumbers(ticketMainNumbers, ticketEuroNumbers);
            }
            
            // Sort the numbers
            std::sort(ticketMainNumbers.begin(), ticketMainNumbers.end());
            std::sort(ticketEuroNumbers.begin(), ticketEuroNumbers.end());
            
            // Add to selected numbers
            selectedNumbers.insert(selectedNumbers.end(), ticketMainNumbers.begin(), ticketMainNumbers.end());
            selectedEuroNumbers.insert(selectedEuroNumbers.end(), ticketEuroNumbers.begin(), ticketEuroNumbers.end());
            
            // Update frequency maps
            updateFrequencyMap(ticketMainNumbers);
            updateEuroFrequencyMap(ticketEuroNumbers);
        }
    }
    
    // Print lottery ticket
    void printTicket() const override {
        std::cout << "\n--- " << systemName << " Ticket ---" << std::endl;
        
        int ticketCount = 0;
        for (size_t i = 0, j = 0; i < selectedNumbers.size(); 
             i += MAIN_NUMBERS_PER_TICKET, j += EURO_NUMBERS_PER_TICKET) {
            std::cout << "Ticket " << ++ticketCount << ": ";
            
            // Print main numbers
            std::cout << "Main numbers: ";
            for (size_t k = i; k < i + MAIN_NUMBERS_PER_TICKET && k < selectedNumbers.size(); k++) {
                std::cout << selectedNumbers[k] << " ";
            }
            
            // Print Euro numbers
            std::cout << "| Euro numbers: ";
            for (size_t k = j; k < j + EURO_NUMBERS_PER_TICKET && k < selectedEuroNumbers.size(); k++) {
                std::cout << selectedEuroNumbers[k] << " ";
            }
            
            std::cout << std::endl;
        }
    }
    
    // Print frequency distribution
    void printFrequencyDistribution() const {
        LotterySystem::printFrequencyDistribution();
        
        std::cout << "\nFrequency Distribution for Euro Numbers:" << std::endl;
        for (const auto& pair : euroFrequencyMap) {
            std::cout << "Euro Number " << pair.first << ": " << pair.second << " times" << std::endl;
        }
    }
    
private:
    // Generate random numbers for a ticket
    void generateRandomNumbers(std::vector<int>& mainNumbers, std::vector<int>& euroNumbers) {
        // Generate main numbers
        std::vector<int> allMainNumbers(MAX_MAIN_NUMBER);
        for (int i = 0; i < MAX_MAIN_NUMBER; i++) {
            allMainNumbers[i] = i + 1;
        }
        
        std::shuffle(allMainNumbers.begin(), allMainNumbers.end(), gen);
        
        mainNumbers.assign(allMainNumbers.begin(), allMainNumbers.begin() + MAIN_NUMBERS_PER_TICKET);
        
        // Generate Euro numbers
        std::vector<int> allEuroNumbers(MAX_EURO_NUMBER);
        for (int i = 0; i < MAX_EURO_NUMBER; i++) {
            allEuroNumbers[i] = i + 1;
        }
        
        std::shuffle(allEuroNumbers.begin(), allEuroNumbers.end(), gen);
        
        euroNumbers.assign(allEuroNumbers.begin(), allEuroNumbers.begin() + EURO_NUMBERS_PER_TICKET);
    }
    
    // Update Euro frequency map
    void updateEuroFrequencyMap(const std::vector<int>& numbers) {
        for (int number : numbers) {
            euroFrequencyMap[number]++;
        }
    }
};

// Class to manage the lottery program
class LotteryManager {
private:
    Lotto6aus49 lotto6aus49;
    Eurolotto eurolotto;
    LotterySystem* currentSystem;
    
public:
    // Constructor
    LotteryManager() : currentSystem(&lotto6aus49) {}
    
    // Run the lottery program
    void run() {
        bool running = true;
        
        while (running) {
            displayMenu();
            int choice = getMenuChoice();
            
            switch (choice) {
                case 1: // Lotto 6 aus 49
                    currentSystem = &lotto6aus49;
                    runLotterySystem();
                    break;
                    
                case 2: // Eurolotto
                    currentSystem = &eurolotto;
                    runLotterySystem();
                    break;
                    
                case 3: // Enter own numbers
                    enterOwnNumbers();
                    break;
                    
                case 4: // Save manual numbers
                    saveManualNumbers();
                    break;
                    
                case 5: // Load manual numbers
                    loadManualNumbers();
                    break;
                    
                case 6: // End program
                    running = false;
                    std::cout << "Ending program. Goodbye!" << std::endl;
                    break;
                    
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        }
    }
    
private:
    // Display the main menu
    void displayMenu() const {
        std::cout << "\n=== Lottery Program Menu ===" << std::endl;
        std::cout << "1 - Lotto 6 aus 49" << std::endl;
        std::cout << "2 - Eurolotto" << std::endl;
        std::cout << "3 - Enter own numbers" << std::endl;
        std::cout << "4 - Save manual numbers" << std::endl;
        std::cout << "5 - Load manual numbers" << std::endl;
        std::cout << "6 - End program" << std::endl;
        std::cout << "Enter your choice: ";
    }
    
    // Get menu choice from user
    int getMenuChoice() const {
        int choice;
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        return choice;
    }
    
    // Run the selected lottery system
    void runLotterySystem() {
        std::cout << "\nSelected system: " << currentSystem->getSystemName() << std::endl;
        
        // Ask for number of tickets
        int tickets;
        std::cout << "Enter number of tickets to generate: ";
        std::cin >> tickets;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        currentSystem->setNumberOfTickets(tickets);
        
        // Ask whether to use manual numbers
        char useManual;
        std::cout << "Use manually entered numbers? (y/n): ";
        std::cin >> useManual;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        currentSystem->setUseManualNumbers(useManual == 'y' || useManual == 'Y');
        
        // Generate and print lottery numbers
        currentSystem->generateNumbers();
        currentSystem->printTicket();
        currentSystem->printFrequencyDistribution();
    }
    
    // Enter own numbers
    void enterOwnNumbers() {
        std::cout << "\n=== Enter Own Numbers ===" << std::endl;
        std::cout << "Select lottery system:" << std::endl;
        std::cout << "1 - Lotto 6 aus 49" << std::endl;
        std::cout << "2 - Eurolotto" << std::endl;
        std::cout << "Enter your choice: ";
        
        int choice;
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (choice == 1) {
            currentSystem = &lotto6aus49;
        } else if (choice == 2) {
            currentSystem = &eurolotto;
        } else {
            std::cout << "Invalid choice. Returning to main menu." << std::endl;
            return;
        }
        
        // Clear existing manual numbers
        currentSystem->clearManualNumbers();
        
        std::cout << "\nEnter up to 30 numbers for " << currentSystem->getSystemName() << std::endl;
        std::cout << "Enter -1 to finish" << std::endl;
        
        int number;
        int count = 0;
        
        while (count < 30) {
            std::cout << "Enter number " << (count + 1) << ": ";
            std::cin >> number;
            
            // Clear input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (number == -1) {
                break;
            }
            
            if (currentSystem->addManualNumber(number)) {
                count++;
            } else {
                std::cout << "Number already entered. Please enter a different number." << std::endl;
            }
        }
        
        std::cout << "\nEntered " << count << " numbers for " << currentSystem->getSystemName() << std::endl;
        
        // Display entered numbers
        const std::vector<int>& manualNumbers = currentSystem->getManualNumbers();
        std::cout << "Entered numbers: ";
        for (int num : manualNumbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    // Save manual numbers
    void saveManualNumbers() {
        if (currentSystem->getManualNumbers().empty()) {
            std::cout << "No manual numbers to save." << std::endl;
            return;
        }
        
        std::string filename = "manual_numbers.txt";
        if (currentSystem->saveManualNumbers(filename)) {
            std::cout << "Manual numbers saved to " << filename << std::endl;
        } else {
            std::cout << "Failed to save manual numbers." << std::endl;
        }
    }
    
    // Load manual numbers
    void loadManualNumbers() {
        std::string filename = "manual_numbers.txt";
        if (currentSystem->loadManualNumbers(filename)) {
            std::cout << "Manual numbers loaded from " << filename << std::endl;
            
            // Display loaded numbers
            const std::vector<int>& manualNumbers = currentSystem->getManualNumbers();
            std::cout << "Loaded numbers: ";
            for (int num : manualNumbers) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Failed to load manual numbers or wrong system." << std::endl;
        }
    }
};

// Main function
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Create and run the lottery manager
    LotteryManager manager;
    manager.run();
    
    return 0;
}
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm;

    // Elemente hinzufügen
    mm.insert({1, "apple"});
    mm.insert({2, "banana"});
    mm.insert({1, "mango"});
    mm.insert({2, "peach"});

    // Durch alle Elemente in der multimap iterieren
    for (const auto& pair : mm) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
// Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460, Luis Armando Salazar A01114901
// November 01 2020


#include <iostream>
#include <fstream>
#include "DoubleLinkedList.h"
#include "MyBST.h"

int main() {
    // Unsorted list of registries
    std::string archivo = "bitacora.txt";
    DoubleLinkedList listRegistries;

    // Open text file and create a list of IPs without ports
    try {
        std::ifstream is;
        is.open(archivo);
        if (!is) throw std::ios::failure("Cannot find file");
        std::string str;
        // Get each line of the file and create a double liked list
        while (std::getline(is, str)) {
            // The string of each registry is passed as an argument to the linked list, this string is then passed to a
            // constructor inside DoubleLinkedList to initialize the RegisterEntry objects
            listRegistries.insertLast(str);
        }
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }

    // Sort list of IPs
    listRegistries.mergeSort();

    // Save sorted list of IPs
    listRegistries.bitacoraOrdenada(listRegistries);

    // Creat BST from the list of sorted IPs
    MyBST ipTree;
    // Sorted list of IPs
    std::string archivoOrdenado = "bitacoraOrdenada.txt";

    // Open text file and store the number of repetitions of each IP with its corresponding ip as a string in the BST
    try {
        ifstream is;
        is.open(archivoOrdenado);
        if (!is) throw ios::failure("Cannot find file");
        string ipString;
        string pastIpString;
        // Counter for repetitions
        int counter = 0;

        // Cycle to create the BST of IPs
        while (std::getline(is, ipString)) {
            if (ipString == pastIpString || pastIpString.empty()) {
                counter++;
            } else {
                // Add IP with the number of repetitions as key
                ipTree.insert(counter, ipString);
                counter = 0;
            }
            pastIpString = ipString;
        }
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }

    // Display the number of repetitions in descending order
    ipTree.reverseInorder();

    // Display the top five IPs
    cout << endl << "Top five: " << endl;
    ipTree.topFive();
    return 0;
}
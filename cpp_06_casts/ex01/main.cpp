#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

void printData(const Data* data, const std::string& label) {
	std::cout << "\n" << label << std::endl;
	std::cout << "Address: " << RED << data << RES << std::endl;
	std::cout << "ID: " << data->id << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << std::endl;
}

int main() {
	//create a data obj
	Data originalData;
	originalData.id = 42;
	originalData.name = "Ori";
	printData(&originalData, "Original Data:");
	
	//serialize the pointer
	//std::cout << "\nSerialize " << std::endl;
	uintptr_t serialized = Serializer::serialize(&originalData);
	//std::cout << "Serialized value: 0x" << std::hex << serialized << std::dec << std::endl;
	
	//seserialize back to pointer
	//std::cout << "\nDeserialize " << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	printData(deserialized, "Deserialized Data:");
	
	//verify the address
	std::cout << "\nVerification " << std::endl;
	std::cout << "Original pointer:     " << RED << &originalData << RES << std::endl;
	std::cout << "Deserialized pointer: " << RED << deserialized << RES << std::endl;
	// std::cout << "Pointers match: " << ((&originalData == deserialized) ? "YES ✓" : "NO ✗") << std::endl;
	// std::cout << "Data integrity: " << ((originalData.id == deserialized->id &&
	// 										originalData.name == deserialized->name) ? "YES ✓" : "NO ✗") << std::endl;
	
	// // Additional tests
	// std::cout << "\n=== ADDITIONAL TESTS ===" << std::endl;
	
	// //dynamically allocated data
	// Data* heapData = new Data;
	// heapData->id = 100;
	// heapData->name = "Heap Data";
	// printData(heapData, "Heap Data (Original):");

	// uintptr_t heapSerialized = Serializer::serialize(heapData);
	// Data* heapDeserialized = Serializer::deserialize(heapSerialized);
	
	// printData(heapDeserialized, "Heap Data (Deserialized):");

	// delete heapData;
	
	// // Test with NULL pointer
	// std::cout << "\n--- NULL Pointer Test ---" << std::endl;
	// Data* nullPtr = NULL;
	// uintptr_t nullSerialized = Serializer::serialize(nullPtr);
	// Data* nullDeserialized = Serializer::deserialize(nullSerialized);
	// std::cout << "NULL pointer test: " << ((nullPtr == nullDeserialized) ? "PASS ✓" : "FAIL ✗") << std::endl;
	
	return 0;
}
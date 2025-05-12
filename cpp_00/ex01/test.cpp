#include "test.hpp"

class NullBuffer : public std::streambuf 
{
	public:
		int overflow(int c) { return c; }
};

void fill_pb(PhoneBook &pb)
{
	//Save original buffers
	std::streambuf* orig_cout = std::cout.rdbuf();
	std::streambuf* orig_cerr = std::cerr.rdbuf();
	std::streambuf* orig_cin = std::cin.rdbuf();
	
	std::cout << "=== Filling PhoneBook with test data ===" << std::endl;
	
	// Create null buffer for output suppression
	NullBuffer null_buffer;
	// Redirect stdout and stderr to null buffer
	std::cout.rdbuf(&null_buffer);
	std::cerr.rdbuf(&null_buffer);
	
	const std::string first_names[] = {"John", "Emma", "Michael", "Sophia", "William", "Olivia", "James", "How"};
	const std::string last_names[] = {"Smith", "Johnson", "Brown", "Davis", "Wilson", "Miller", "Taylor", "Set"};
	const std::string nick_names[] = {"Johnny", "Emmy", "Mike", "Sophie", "Will", "Liv", "Jimmy", "Avie"};
	const std::string phone_numbers[] = {"1234567", "2345678", "3456789", "4567890", "5678901", "6789012", "7890123", "123456789"};
	const std::string secrets[] = {"Pizza", "Cats", "Singing", "Dancing", "Comics", "Gaming", "Writing", "Sleeping"};
	
	for (int i = 0; i < 8; i++) {
		std::stringstream inputs;
		inputs << first_names[i] << std::endl;
		inputs << last_names[i] << std::endl;
		inputs << nick_names[i] << std::endl;
		inputs << phone_numbers[i] << std::endl;
		inputs << secrets[i] << std::endl;

		// Redirect cin to our prepared input
		std::cin.rdbuf(inputs.rdbuf());
		// Add contact (output suppressed)
		pb.add_contact();
	}

	// Restore original buffers
	std::cout.rdbuf(orig_cout);
	std::cerr.rdbuf(orig_cerr);
	std::cin.rdbuf(orig_cin);

	std::cout << "=== PhoneBook filled with 8 test contacts ===" << std::endl;
}
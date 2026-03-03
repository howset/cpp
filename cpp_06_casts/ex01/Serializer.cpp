#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &copy) {
	(void)copy;
}

Serializer &Serializer::operator=(const Serializer &copy) {
	(void)copy;
	return *this;
}

//store (convert) ptr val as unsigned int
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

//convert unsigned int to ptr vals
Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
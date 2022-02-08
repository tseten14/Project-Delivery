// Owl.cpp
#include "Owl.h"

Owl::Owl() :Standard()
{
	this->id = "o";
}
Owl::Owl(std:: string sender_name, std:: string date_scheduled, std:: string id, double weight) : Standard(sender_name, date_scheduled, weight)
{
	this->id = id;
}

std::string Owl::get_id()
{
	return this->id;
}
void Owl::display()
{
	std::cout << " Standard-Owl: "<<std::endl;
	Standard::display();
	std::cout << "ID: "<<this->id << " Weight: " << Standard::get_weight() << std::endl;
}
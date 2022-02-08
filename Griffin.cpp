// Griffin.cpp
#include "Griffin.h"


Griffin::Griffin() :Standard()
{
	this->id = "g";
}
Griffin::Griffin(std:: string sender_name, std:: string date_scheduled, std:: string id, double weight) : Standard(sender_name, date_scheduled, weight)
{
	this->id = id;
}

std:: string Griffin::get_id()
{

	return this->id;
}
void Griffin::display()
{
	std::cout << " Standard-Griffin: "<<std::endl;;
	Standard::display();
	std::cout << "ID: "<<this->id << " Weight: " << Standard::get_weight() << std::endl;
}
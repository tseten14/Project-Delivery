// Standard.cpp
#include "Standard.h"

Standard::Standard() :Delivery()
{

}

Standard::Standard(std:: string sender_name, std:: string date_scheduled, double weight) : Delivery::Delivery(sender_name, date_scheduled)
{
	this->weight = weight;
}

double Standard::get_weight()
{
	return this->weight;
}
std::string Standard::get_sender_name(){
	return Delivery::get_sender_name();
}
std::string Standard::get_date_scheduled(){
	return Delivery::get_date_scheduled();
}
void Standard::display() {
	Delivery::display();
}
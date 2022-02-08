// VanishingCabinet.cpp
#include "VanishingCabinet.h"

VanishingCabinet::VanishingCabinet() :Delivery()
{
	this->id = "-";
}

VanishingCabinet::VanishingCabinet(std:: string sender_name, std::string date_scheduled, std:: string id) : Delivery(sender_name, date_scheduled)
{
	this->id = id;
}


std:: string VanishingCabinet::get_id()
{
	return this->id;
}

std:: string VanishingCabinet:: get_sender_name() {
	return Delivery::get_sender_name();
}

std::string VanishingCabinet:: get_date_scheduled() {
	return Delivery::get_date_scheduled();
}

void VanishingCabinet::display()
{
	std::cout << " Vanishing Cabinet: "<<std::endl;
	Delivery::display();
	std::cout << "ID: "<<this->id << std::endl;
}
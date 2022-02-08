// Delivery.cpp
#include "Delivery.h"

Delivery::Delivery()
{

}

Delivery::Delivery(std:: string sender_name, std:: string date_scheduled)
{
	this->sender_name = sender_name;
	this->date_scheduled = date_scheduled;

}

std:: string Delivery::get_date_scheduled()
{
	return this->date_scheduled;

}

std:: string Delivery::get_sender_name()
{
	return this->sender_name;
}

void Delivery::set_sender_name(std:: string name)
{
	this->sender_name = name;
}

void Delivery::set_date_scheduled(std:: string date)
{
	this->date_scheduled = date;
}

void Delivery::display() {
	std::cout << "Name: "<<this->sender_name << " Date Scheduled: " << this->date_scheduled<<" ";
}





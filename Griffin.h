#pragma once
#include "Standard.h"
class Griffin : public Standard {
	std::string id; //stores string

public:
	Griffin();   //constructor

	Griffin(std::string sender_name, std::string date_scheduled, std::string id, double weight);   //overloaded constructor

	std::string get_id();    //id getter

	void display();   //print deliveries
};

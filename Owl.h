#pragma once
#include "Standard.h"

class Owl : public Standard {
	std::string  id;  //stores id

public:
	Owl();  //constructor

	Owl(std::string sender_name, std::string date_scheduled, std::string id, double weight);   //overloaded constructor

	std::string get_id();   //gets id

	void display();      //prints deliveries
};

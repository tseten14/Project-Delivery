#pragma once
#include "Delivery.h"
class VanishingCabinet : public Delivery {
	std::string id;             //stores id

public:
	VanishingCabinet();   //Default constructor

	VanishingCabinet(std::string sender_name, std::string date_scheduled, std::string id); //Overloaded constructor

	std::string get_id(); //id getter

	std::string get_date_scheduled(); //date getter

	std::string get_sender_name();   //name getter
	void display();
};

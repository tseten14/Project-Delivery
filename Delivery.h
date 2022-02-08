#pragma once
#include<iostream>
#include<string>
class Delivery {

	std::string sender_name;   //stores sender's name
	std::string date_scheduled; //stores the date scheduled 


protected:
	Delivery();     //default constructor

	Delivery(std::string sender_name, std::string date_scheduled);    //overloaded constructor

	std::string get_sender_name();       //name getter

	std::string get_date_scheduled();     //date_scheduled getter

	void set_sender_name(std::string sender_name);   //name setter

	void set_date_scheduled(std::string date_scheduled);   //date setter

public:
	virtual void display() ; //prints delivery info

};

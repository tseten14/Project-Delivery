#pragma once
#include "Delivery.h"
class Standard:public Delivery
{

  double weight;		//stores weight

protected:

    Standard ();		//default constructor

    Standard (std::string sender_name, std::string date_scheduled, double weight);	//overloaded constructor
public:
  double get_weight ();		//weight getter

    std::string get_date_scheduled ();	//date getter

    std::string get_sender_name ();	//name getter
  void display ();		// prints delivery info
};

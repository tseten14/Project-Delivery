//Sherpa Travels
#include "Owl.h"
#include "VanishingCabinet.h"
#include "Griffin.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
void print_menu ();		//displays the menu
size_t get_selection ();	//gets the menu selection from the user
void schedule_new_delivery (std::vector < Delivery * >&ptr_list, std::vector < std::string > &id_list);	//adds a new delivery
std::string generate_id (int type);	//generates a random number from 0 to 99999
void display_all (std::vector < Delivery * >ptr_list);	//displays all deliveries
void display_type (std::vector < Delivery * >ptr_list);	//displays deliveries of chossen type
void remove_delivery (std::vector < Delivery * >&ptr_list);	// removes a delivery
void load_delivery (std::vector < Delivery * >&ptr_list);	//loads deliveries from files
void save_delivery (std::vector < Delivery * >ptr_list);	//saves deliveries to files
std::string datescheduled ();	//returns the datescheduled
bool check_duplicate_id (std::vector < std::string > &id_list,
			 std::string id);


int
main ()
{
  std::srand (time (NULL));	//seeding the random number genrator
  std::vector < Delivery * >ptr_list;	//vector that stores the address of an object   
  std::vector < std::string > id_list;	//vector that stores the id string 
  size_t user_choice;

  do
    {
      print_menu ();		//calling the function that displays menu
      user_choice = get_selection ();	//storing user selection returned by the function

      if (user_choice == 1)
	{
	  schedule_new_delivery (ptr_list, id_list);	//calling the function to schedule a new delivery
	}
      else if (user_choice == 2)
	{
	  remove_delivery (ptr_list);	//calling the function to remove a delivery
	}
      else if (user_choice == 3)
	{
	  load_delivery (ptr_list);	//calling load_delivery function
	}
      else if (user_choice == 4)
	{
	  save_delivery (ptr_list);	//calling save_delivery function
	}
      else if (user_choice == 5)
	{
	  display_all (ptr_list);	//calling the function that displays all scheduled deliveries
	}
      else if (user_choice == 6)
	{
	  display_type (ptr_list);	// calling the function that displays deliveries by type
	}
      else if (user_choice == 7)
	{
	  for (int i = 0; i < ptr_list.size (); i++)
	    {
	      ptr_list.pop_back ();	//pops back all the elements from the vector
	      delete ptr_list[i];	//deletes dynamically created memory when user quits the program
	    }
	  std::cout << std::endl << "Thank you for using Sherpa Travels." << std::endl << std::endl;	// displaying exit message
	  return 0;
	}
      else
	{
	  continue;		//keep continuing 
	}
    }
  while (user_choice != 7);

  return 0;
}

void
print_menu ()
{
  //displays the menu to the user
  std::cout << std::endl;
  std::cout << "Please select from the following choices:" << std::endl;
  std::cout << "\t " << "(1) Schedule a new delivery." << std::endl;
  std::cout << "\t " << "(2) Remove a delivery." << std::endl;
  std::cout << "\t " << "(3) Load deliveries from a file." << std::endl;
  std::cout << "\t " << "(4) Save deliveries to file." << std::endl;
  std::cout << "\t " << "(5) Display all scheduled deliveries." << std::endl;
  std::cout << "\t " << "(6) Display deliveries by transportation type." <<
    std::endl;
  std::cout << "\t " << "(7) Quit." << std::endl;
}

size_t
get_selection ()
{
  //gets the user selection and returns the selection to main
  size_t selection;
  std::cout << "Selection: ";
  std::cin >> selection;

  if (selection > 7 || selection < 1)
    {
      std::cout << std::endl;
      std::cout << "Invalid Selection.Please select a number between 1 and 7 "
	<< std::endl << std::endl;
    }

  return selection;
}

void
schedule_new_delivery (std::vector < Delivery * >&ptr_list,
		       std::vector < std::string > &id_list)
{
  char choice;			//variable that stores user choice
  double weight;		//variable that stores the weight
  std::cout << std::endl;
  std::cout << "Schedule a new delivery" << std::endl;
  std::cout << "-----------------------" << std::endl;
  std::string input;
  // input user's name

  std::cout << "\t " << "Please enter the sender's name: ";
  std::cin.ignore ();
  getline (std::cin, input);

  do
    {
      std::cout << "\t " << "Enter Weight (kgs): ";
      std::cin >> weight;

      if (weight <= 0)
	{
	  std::cout << std::endl << "\t" << " " <<
	    "Invalid Selection.Please enter a valid weight." << std::endl <<
	    std::endl;
	}

    }
  while (weight <= 0);

  //asks and validates the shipping type 
  do
    {
      std::cout << "\t " << "Standard Shipping (Y/N)? ";
      std::cin >> choice;

      choice = tolower (choice);	// converting uppercase to lowercase

      if (choice != 'y' && choice != 'n')
	{
	  std::cout << std::endl << "\t" << " " <<
	    "Invalid Selection.Please select Y for Yes and N for No." <<
	    std::endl << std::endl;
	}

    }
  while (choice != 'y' && choice != 'n');

  //asks and validates the weight

  if (choice == 'y' && weight <= 1.58)
    {
      int type = 2;		//setting a type for Owl        
      std::string id;
      std::string date_scheduled = datescheduled ();	//stores the datescheduled

      do
	{
	  id = generate_id (type);	//stores the unique id

	}
      while (check_duplicate_id (id_list, id) == true);
      Owl *object = new Owl (input, date_scheduled, id, weight);	//storing the information of the object
      ptr_list.push_back (object);	// storing the address in the array
    }

  else if (choice == 'y' && weight > 1.58)
    {
      int type = 3;		//setting a type for Griffin
      std::string id;
      std::string date_scheduled = datescheduled ();	//stores the datescheduled

      do
	{
	  id = generate_id (type);	//stores the unique id
	}
      while (check_duplicate_id (id_list, id) == true);

      Griffin *object = new Griffin (input, date_scheduled, id, weight);	// storing the information of the object
      ptr_list.push_back (object);	// storing the address in the array
    }

  else
    {
      int type = 1;		//setting a type for Vanishing Cabinet
      std::string date_scheduled = datescheduled ();	//stores the date Scheduled
      std::string id;

      do
	{
	  id = generate_id (type);	//stores the unique id
	}
      while (check_duplicate_id (id_list, id) == true);

      VanishingCabinet *object = new VanishingCabinet (input, date_scheduled, id);	//storing the information of the object
      ptr_list.push_back (object);	// storing the address in the array

    }


  std::
    cout << std::endl << "\t " << "New Delivery Scheduled Successfully" <<
    std::endl;
}

std::string generate_id (int type)
{
  // receives the type and returns id accordingly based on the type

  if (type == 2)
    {
      std::string ret = "o";
      for (int i = 0; i < 3; i++)
	{

	  int rand1 = rand () % 10;
	  std::stringstream rand_id;
	  rand_id << rand1;
	  std::string final_id = rand_id.str ();
	  ret.append (final_id);
	}

      return ret;
    }

  else if (type == 3)
    {
      std::string ret = "g";
      for (int i = 0; i < 7; i++)
	{
	  int rand1 = rand () % 10;
	  std::stringstream rand_id;
	  rand_id << rand1;
	  std::string final_id = rand_id.str ();
	  ret.append (final_id);
	}
      return ret;
    }

  else
    {
      std::string ret = "-";
      std::string final_id;
      for (int i = 0; i < 8; i++)
	{
	  int rand1 = rand () % 10;
	  std::stringstream rand_id;
	  rand_id << rand1;
	  std::string first_part = rand_id.str ();
	  final_id.append (first_part);
	}

      final_id.append (ret);

      for (int i = 0; i < 8; i++)
	{
	  int rand1 = rand () % 10;
	  std::stringstream rand_id;
	  rand_id << rand1;
	  std::string second_part = rand_id.str ();
	  final_id.append (second_part);
	}
      return final_id;
    }
}

bool
check_duplicate_id (std::vector < std::string > &id_list, std::string id)
{
  //checks for duplicate ID
  for (int i = 0; i < id_list.size (); i++)
    {
      if (id == id_list.at (i))
	return true;
    }
  return false;
}


void
display_all (std::vector < Delivery * >ptr_list)
{
  //displays all the deliveries

  std::cout << std::endl;
  std::cout << "All Deliveries " << std::endl;
  std::cout << "----------------" << std::endl;

  if (ptr_list.size () == 0)
    {
      std::cout << "\t" << "Nothing Scheduled" << std::endl;
      return;
    }

  // displays all the deliveries
  for (int i = 0; i < ptr_list.size (); i++)
    {
      std::cout << "[" << i << "]";
      (*ptr_list[i]).display ();
    }
}

void
display_type (std::vector < Delivery * >ptr_list)
{

  //displays deliveries by type

  int type;			// gets user input
  std::cout << std::endl;
  std::cout << "All Deliveries " << std::endl;
  std::cout << "----------------" << std::endl;
  ;
  if (ptr_list.size () == 0)	//if nothing is scheduled
    {
      std::cout << "\t" << "Nothing Scheduled" << std::endl;
      return;;
    }

  std::cout << std::endl;

  // user input and input validation
  do
    {
      std::cout << "Which type (1) Griffin, (2) Owl, (3) Vanishing Cabinet? ";
      std::cin >> type;

      if (type != 1 && type != 2 && type != 3)
	{
	  std::
	    cout << "\t" << "Invalid selection. Please select 1, 2 or 3." <<
	    std::endl << std::endl;
	}

    }
  while (type != 1 && type != 2 && type != 3);

  //displaying output based on user input

  if (type == 1)
    {

      for (int i = 0; i < ptr_list.size (); i++)
	{
	  Griffin *delivery = dynamic_cast < Griffin * >(ptr_list[i]);
	  std::string initialid = delivery->get_id ();
	  if (initialid.front () == 'g')
	    {
	      std::cout << "[" << i << "]";
	      delivery->display ();
	    }
	}
    }

  else if (type == 2)
    {
      for (int i = 0; i < ptr_list.size (); i++)
	{
	  Owl *delivery = dynamic_cast < Owl * >(ptr_list[i]);
	  std::string initialid = delivery->get_id ();
	  if (initialid.front () == 'o')
	    {
	      std::cout << "[" << i << "]";
	      delivery->display ();
	    }
	}
    }

  else
    {
      for (int i = 0; i < ptr_list.size (); i++)
	{
	  VanishingCabinet *delivery =
	    dynamic_cast < VanishingCabinet * >(ptr_list[i]);
	  std::string initialid = delivery->get_id ();
	  if (initialid.front () != 'g' || initialid.front () != 'o')
	    {
	      std::cout << "[" << i << "]";
	      delivery->display ();
	    }
	}
    }
  std::cout << std::endl;
}

void
remove_delivery (std::vector < Delivery * >&ptr_list)
{
  std::cout << std::endl << "Remove a Delivery" << std::endl;
  std::cout << "------------------" << std::endl;

  if (ptr_list.size () == 0)
    {
      std::cout << "\t" << "Error: Nothing to remove" << std::endl;
      return;
    }

  display_all (ptr_list);

  int index;			// gets the index that has to be removed from the user

  //asks and validates the user
  do
    {
      std::cout << "\t" <<
	"Which would you like to remove(enter the index) : ";
      std::cin >> index;

      if (index < 0 || index > (ptr_list.size ()) - 1)	//printing error message
	{
	  std::cout << std::endl << "\t" <<
	    "Invalid selection. Please enter a valid index from 0 to " <<
	    (ptr_list.size ()) - 1 << std::endl << std::endl;
	}


    }
  while (index < 0 || index > (ptr_list.size ()) - 1);

  //removing deliveries

  for (int i = index; i < (ptr_list.size () - 1); i++)
    {
      ptr_list[i] = ptr_list[i + 1];
    }

  ptr_list.erase (ptr_list.begin () + ptr_list.size () - 1);

  std::cout << std::
    endl << "\t " << "Delivery Removed Successfully" << std::endl;
}

void
load_delivery (std::vector < Delivery * >&ptr_list)
{
  std::cout << "\nLoad Deliveries From File" << std::endl;
  std::cout << "---------------------------" << std::endl << std::endl;

  std::ifstream my_file;	// declaring my_file (an object of type ifstream)
  std::string file_name;	// gets the file_name from the user

  std::cout <<
    "\tName the .txt file from which you'd like to load the delivery information: ";
  if ('\n' == std::cin.peek ())
    {
      std::cin.ignore ();
    }
  getline (std::cin, file_name);

  my_file.open (file_name.c_str ());	// opening the file entered by user

  if (my_file.fail ())		//display error message if file does not exist
    {
      std::cout << "\n\tThe file does not exist." << std::endl;
      return;
    }

  std::string everything;	//string that stores information from the file
  std::string delimeter = ",";	//declaring a delimiter 
  size_t pos = 0;		//initializing position of the delimiter
  std::string name;		//string that stores name of sender 
  std::string date;		//string that stores date scheduled
  std::string id;		// string that stores the ID
  std::string weight;		// double that stores the weight

  while (!my_file.eof ())	// loop that runs until the end the file
    {
      getline (my_file, everything);	//stores each line of infortmation from the file in the string everytime

      //declaring position of delimiter and running a loop that goes through the entire content of file
      while ((pos = everything.find (delimeter)) != std::string::npos)
	{

	  name = everything.substr (0, pos);	// storing first part of the information,i.e.name                               
	  everything.erase (0, pos + delimeter.length ());	// erasing the information that was stored
	  pos = everything.find (delimeter);	// finding the next delimiter and storing its position


	  date = everything.substr (0, pos);	// storing next part of the information,i.e.date
	  everything.erase (0, pos + delimeter.length ());	// erasing the information that was stored
	  pos = everything.find (delimeter);	// finding the next delimiter and storing its position

	  id = everything.substr (0, pos);	// storing next part of the information,i.e.id
	  everything.erase (0, pos + delimeter.length ());	// erasing the information that was stored
	  pos = everything.find (delimeter);	// finding the next delimiter and storing its position

	  weight = everything.substr (0, pos);	// storing next part of the information,i.e. weight
	  double result;	// declaring a double that stores the weight

	  //converting the string to double and storing it to result

	  std::stringstream ss;	// copies information from weight(string) and stores it in result(double)
	  ss << weight;		// taking information from weight
	  ss >> result;		// copying information to result

	  if (id[0] == 'o')
	    {
	      Owl *object = new Owl (name, date, id, result);
	      ptr_list.push_back (object);
	    }

	  else if (id[0] == 'g')
	    {
	      Griffin *object = new Griffin (name, date, id, result);
	      ptr_list.push_back (object);
	    }

	  else
	    {
	      VanishingCabinet *object =
		new VanishingCabinet (name, date, id);
	      ptr_list.push_back (object);
	    }
	}			// increasing the number of deliveries
    }

  my_file.close ();		// closes the file

  std::cout << "\nAll deleveries loaded successfully." << std::endl;
}

void
save_delivery (std::vector < Delivery * >ptr_list)
{
  std::cout << std::endl << "Save Deliveries To File" << std::endl;
  std::cout << "-------------------------" << std::endl << std::endl;
  std::ofstream myfile;		// declaring myfile(an object of type ofstream)
  std::string filename;		// gets the filename from the user
  std::cout << std::
    endl << "\t " <<
    "Name of the .txt file where you'd like to save delivery information: ";
  std::cin.ignore ();
  getline (std::cin, filename);

  myfile.open (filename.c_str ());	// opening the file entered by user


  // storing all the information to the file entered by the user



  for (int i = 0; i < ptr_list.size (); i++)
    {
      Griffin *delivery = dynamic_cast < Griffin * >(ptr_list[i]);
      Owl *delivery1 = dynamic_cast < Owl * >(ptr_list[i]);
      VanishingCabinet *delivery2 =
	dynamic_cast < VanishingCabinet * >(ptr_list[i]);
      std::string G;
      std::string O;
      std::string V;
      G = delivery->get_id ();
      O = delivery1->get_id ();
      V = delivery2->get_id ();

      if (G.front () == 'g' || O.front () == 'g' || V.front () == 'g')
	{

	  myfile << "Standard-Griffin " << ",";
	  myfile << "," << delivery->get_sender_name () << ",";
	  myfile << delivery->get_date_scheduled () << ",";
	  myfile << delivery->get_id () << ",";
	  myfile << delivery->get_weight () << std::endl;
	}

      else if (G.front () == 'o' || O.front () == 'o' || V.front () == 'o')
	{

	  myfile << "Standard-Owl " << ",";
	  myfile << "," << delivery->get_sender_name () << ",";
	  myfile << delivery1->get_date_scheduled () << ",";
	  myfile << delivery1->get_id () << ",";
	  myfile << delivery1->get_weight () << std::endl;

	}

      else
	{

	  myfile << "Vanishing Cabinet " << ",";
	  myfile << "," << delivery2->get_sender_name () << ",";
	  myfile << delivery2->get_date_scheduled () << ",";
	  myfile << delivery2->get_id () << std::endl;
	}
    }
  myfile.close ();		// closing the file
  std::cout << "\t " << "Deliveries Successfully Saved" << std::endl;	// displaying confirmation msg

}


std::string datescheduled ()
{

  size_t day, month, year;	//Initializing day, month and year
  std::string date;

  std::cout << "Please enter the date of delivery\n";
  do
    {
      std::cout << "\nEnter Month(1-12): ";

      std::cin >> month;
    }
  while (month < 1 || month > 12);

  do
    {
      std::cout << "Day: ";
      std::cin >> day;
    }
  while (day < 1 || day > 31);

  do
    {
      std::cout << "Year: ";
      std::cin >> year;
    }
  while (year < 1950);
  std::cout << "\n";

  date = std::to_string (month) + "-" + std::to_string (day) + "-" + std::to_string (year);	//combining sub strings to a single string
  std::cout << std::endl;
  return date;
}

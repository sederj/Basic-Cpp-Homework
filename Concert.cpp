/**
 * This class provides the code for 
 * the Concert.h class, including the implementation of 
 * the Concert object, overloading the < operator to sort 
 * Concert objects, and overloading the << operator to 
 * easily print information about a concert object.
 *
 * @author Joseph Seder and Dan Gritters
 */

#include "Concert.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

// default constructor
Concert::Concert() {
	this->concertName = "";
	this->friends = {};
	this->desire = 0;	
}

// constructor with all parameters
Concert::Concert(std::string concertName, std::vector<std::string> friends, 
		int desire, std::tm date) {
	this->concertName = concertName;
	this->friends = friends;
	this->desire = desire;
	this->date = date;
}

//overload the < operator so the Concert obj can be sorted, comparing by date first, then desire
bool Concert::operator<(const Concert& other) const {
	// first compare the year of each concert
	if (this->date.tm_year < other.date.tm_year){
		 return true;
	} else if (this->date.tm_year > other.date.tm_year){
		 return false;
	}

	// then compare the month
	if (this->date.tm_mon < other.date.tm_mon){
		 return true;
	} else if (this->date.tm_mon > other.date.tm_mon){
		 return false;
	}
	
	// then compare the day
	if (this->date.tm_mday < other.date.tm_mday){
		return true;
	} else if (this->date.tm_mday > other.date.tm_mday){
		return false;
	}

	// then compare the desire
	if (this->desire > other.desire){
		 return false;
	} else{
		 return true; 
	}
}

//getter method for the concert name
std::string Concert::getConcertName() const{
	return this->concertName;
}

//getter method for the date struct
std::tm Concert::getDate() const{
	return this->date;
}

// getter method for desire
int Concert::getDesire() const{
	return this->desire;
}

// << overload to allow the std cout to print information about concerts
std::ostream& operator<<(std::ostream& stream, const Concert& other){
	stream <<  other.getConcertName()<< "    " << other.getDate().tm_mon << "/" 
		<< other.getDate().tm_mday << "/" << (1900+ other.getDate().tm_year) 
		<< "    Desire: " << other.getDesire() << "\n";
	return stream;
}

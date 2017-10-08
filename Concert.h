/**
 * Header file for concert definitions and definition for overloading
 * the << operator to print concert information
 *
 * @author Joseph Seder and Dan Gritters
 */

#include <string>
#include <vector>
#include <ctime>

class Concert {

	public:
		// default concert constructor
		Concert();

		// constructor with parameters
		Concert(std::string concertName, std::vector<std::string> friends, 
			int desire, std::tm date);
		
		// function to overload the < operator to compare Concerts
		bool operator<(const Concert& other) const;
		
		//returns the date
		std::tm getDate() const;
		
		//returns the name of the concert
		std::string getConcertName() const;
		
		//returns the desire
		int getDesire() const;
	private:
		// Who will be performing?
		std::string concertName;
		
		// A list of the people you want
		// to take with you.  May be empty
		// or arbitrarily full.
		std::vector<std::string> friends;
		
		// A value from 1-10 concerning how
		// badly you want to see this show.
		int desire;
		
		// The date of the show
		// See http://en.cppreference.com/w/cpp/chrono/c/tm
		std::tm date;
};

// function to overload the << operator to print Concert info
std::ostream& operator<<(std::ostream& stream, const Concert& other);

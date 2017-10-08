/**
 * Main file which will create 10 concert objects, 
 * place them in a vector, sort them, and print them 
 * to the console.
 *
 * @author Joseph Seder and Dan Gritters
 */

#include "Concert.h"
#include <iostream>
#include <vector>
#include <algorithm>

// creates a date struct initialized with the give month day and year after 1900
std::tm getDate(int month, int day, int yearsSince1900) {
	struct std::tm tmStruct;

	tmStruct.tm_year = yearsSince1900;
	tmStruct.tm_mday = day;
	tmStruct.tm_mon = month;

	return tmStruct;
}

// Main that creates 10 concerts, puts them into a vector, sorts them,and then prints them.
int main(int argc, char** argv){
	//vector to hold the concerts
	std::vector<Concert> concertList;
	
	//creating concerts and appending them to the vector
	Concert c1("Tom Petty", {"Bill", "Fred"}, 10, getDate(1,30,118));
	concertList.push_back(c1);
	Concert c2("Journey", {"James"}, 10, getDate(1,30,117));
	concertList.push_back(c2);
	Concert c3("REO Speedwagon", {"Jake", "Fred"}, 10, getDate(6,1,119));
	concertList.push_back(c3);
	Concert c4("Billy Joel", {"Bill", "Fred", "Jake"}, 9, getDate(6,1,119));
	concertList.push_back(c4);
	Concert c5("Bon Jovi", {}, 10, getDate(12,30,120));
	concertList.push_back(c5);
	Concert c6("Foreigner", {"Joel", "Jim"}, 7, getDate(1,30,117));
	concertList.push_back(c6);
	Concert c7("Eagles", {"Jason"}, 9, getDate(8,23,117));
	concertList.push_back(c7);
	Concert c8("Kansas", {"Jill", "Jasmine"}, 6, getDate(6,1,119));
	concertList.push_back(c8);
	Concert c9("Rick Astley", {"Jacky", "Jack", "Justin"}, 1, getDate(4,12,120));
	concertList.push_back(c9);
	Concert c10("Bee Gees", {}, 8, getDate(1,3,121));
	concertList.push_back(c10);
	
	//sort the vector using the begin and end iterators
	std::sort(concertList.begin(), concertList.end());
	
	//use an iterator in a for loop to print each concert object using overloaded cout operator
	for(std::vector<Concert>::iterator it = concertList.begin(); it != concertList.end(); ++it){
		std::cout << *it;
	}
} 


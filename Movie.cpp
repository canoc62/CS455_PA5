//Christopher Cano CS455 PA5

#include "Movie.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Studio.h"
using namespace std;

Movie::Movie(){
    
    title = "";
    year = 0;//"";
    studioName = "";
    income = 0;//"";
    starsList;
}

Movie::Movie(string movieTitle, int movieYear, long movieIncome, string movieStudio){
    
    title = movieTitle;
    year = movieYear;
    income = movieIncome;
    studioName = movieStudio;
    starsList;
}

void Movie::setTitle(string movieTitle){
    
    title = movieTitle;
}

void Movie::setYear(int movieYear){
    
    year = movieYear;
}

void Movie::setIncome(long movieIncome){
    
    income = movieIncome;
}

void Movie::setStudio(string movieStudio){
    
    studioName = movieStudio;
}

void Movie::setStars(vector<string> list){
    
    starsList = list; 
}

string Movie::getTitle(){
    
    return title;
}

int Movie::getYear(){
    
    return year;
}

long Movie::getIncome(){
    
    return income;
}

string Movie::getStudio(){
    
    return studioName;
}

bool Movie::findStar(string star){
    
    for(int i = 0; i<starsList.size();i++){
        
        if(starsList.at(i).compare(star) == 0){
            
            return true;
        }
    }
    
    return false;
}

void Movie::addStar(string newStar){
    
    starsList.push_back(newStar);
}

void Movie::printMovie(){
    
    stringstream incomeStream;
    incomeStream << getIncome();
    string income = "$" + incomeStream.str() + ".00";
    cout << left;
    cout << setw(15) << getTitle() << setw(15) << income << setw(15) << getYear() << setw(15) << getStudio() << endl;
}

string Movie::starListPrint(){
    
    string listOfStars = "";
    if(starsList.size() ==0){
        cout << "No stars in this movie!" << endl;
        return listOfStars;
    }
    
    listOfStars = "1)" +starsList.at(0) + "\n";
    for(int i = 1; i < starsList.size();i++){
        
        int j = i +1;
        stringstream js;
        js << j;
        string jString = js.str();
        listOfStars += "                    " + jString + ")" + starsList.at(i) + "\n";
    }
    
    return listOfStars;
}
void Movie::printDetail(){
    
    cout << left;
    cout << setw(20) << "Movie Title:" << setw(20) << getTitle() << endl;
    cout << setw(20) << "Year Made:" << setw(20) << getYear() << endl;
    cout << setw(20) << "Studio:" << setw(20) << getStudio() << endl;
    cout << setw(20) << "Stars:" << setw(20) << starListPrint() << endl;
    cout << setw(20) << "Gross Income:" << "$" << getIncome() << ".00" << endl;
    cout << "\n" << "****************************************************" << endl;
}

void Movie::readMovie(string title ,int year ,long income ,string studio,vector<string> list){
    
    setTitle(title);
    setYear(year);
    setIncome(income);
    setStudio(studio);
    setStars(list);
}

bool Movie::equals(Movie otherMovie){
    
    if(getTitle().compare(otherMovie.getTitle()) == 0){
        
        return true;
    }
    else{
        
        return false;
    }
}






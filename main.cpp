//Christopher Cano CS455 PA5

/* 
 * File:   main.cpp
 * Author: chrstphrcn
 *
 * Created on July 11, 2014, 11:13 PM
 */
// main file portrays the data base of movies. LinkedList is used to contain list of movies. vector is used to collect studio objects
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "node.h"
#include "LinkedList.h"
#include "Movie.h"
#include "Studio.h"
#include <stdlib.h>

using namespace std;

int getChoice();
bool checkRead(ifstream&,string&);
void readFile(ifstream&, LinkedList &,vector<Studio>&);
void processChoice(int, LinkedList&, vector<Studio>&,ifstream&,ofstream&,string&,string&);
void processAnswer(int, LinkedList&);
bool searchMovie(LinkedList &, string);
void addMovie(LinkedList &,vector<Studio>&);
void deleteMovie(LinkedList &, vector<Studio>&,string);
void displayMenu();
void printMovieReport(LinkedList &);
void printMovieReportToFile(LinkedList &, ofstream&, string&);
void printDetailReport(LinkedList &);
void printDetailReportToFile(LinkedList &,ofstream&, string&);
void printStudioSales(vector<Studio>&);
void printStudioSalesToFile(vector<Studio>&, ofstream &, string&);
void searchPrintMovie(LinkedList&,string);
void searchPrintStudio(LinkedList&, vector<Studio>&, string);
void searchPrintActor(LinkedList&,string);
void addStudioInfo(string,vector<Studio>&);
bool searchStudio(string,vector<Studio> &);
void addIncomeToStudio(int, string, vector<Studio> &);
void subtractIncomeFromStudio(int, string, vector<Studio> &);
void addMovieToStudio(vector<Studio>&,string);
void subtractMovieFromStudio(vector<Studio>&,string);
string formatIncome(long);

int main(int argc, char** argv){
    
    vector<Studio> studioList;
    LinkedList movieList;
    string inFileName;
    string outFileName;
    ifstream fin;
    ofstream fout;
    
    int quit = 13;
    int answer;     
    do{
        displayMenu();
        answer = getChoice();
        if(answer != quit){
        processChoice(answer,movieList,studioList,fin,fout,inFileName,outFileName);
        }
    }while(answer != quit);
   
    return 0;
}

int getChoice(){
	
    int choice;
    cin.clear();
    cin >> choice;
    cin.clear();
    cin.ignore( 200, '\n' );
    
    return choice;
}

bool checkRead(ifstream &fin,string &inFile){
    
    cin.clear();
    cout << "\nEnter input file name: " << endl;
    cin >> inFile;
    cin.ignore(10,'\n');
    
    fin.open(inFile.c_str());

    if(fin.fail()){
        
        cout << "\nBad input file name. File not opened." /*Please enter existing file with correct file name.*/ << endl;
        return false;
    }
    else if(!fin.fail()){
        cout << "File opened!" << endl;
    }
    return true;
}

void readFile(ifstream &fin, LinkedList &list,vector<Studio>&studioList){
   
    cout << "reading file" << endl;

    int x = 0;
    while(!fin.eof()){
    cin.clear();
    string title;
    getline(fin,title);  
    int yearMade;
    fin >> yearMade;
    fin.ignore();
    long income;
    fin >> income;
    fin.ignore();
    string studio;
    fin >> studio;
    fin.ignore(10,'\n');
    addStudioInfo(studio,studioList);
    
    if(searchStudio(studio,studioList) == true){
            
        //long inc = strtol(income.c_str(),NULL,0);
        addIncomeToStudio(income,studio,studioList);
    }
    
    string actorLine;
    getline(fin,actorLine);
    stringstream linestream(actorLine);
    string starName;
    vector<string> starList;
    while(getline(linestream,starName,',') && linestream.peek() != '\n'){
        
        string starFirstName;
        string starLastName;
        
        istringstream iss;//takes out white space
        iss.str(starName);
        iss>>starFirstName;
        iss>>starLastName;
        
        string starFullName = starFirstName + " " + starLastName;
        starList.push_back(starFullName);
    }
    Movie newMovie;
    newMovie.readMovie(title,yearMade,income,studio,starList);
    list.addNode(newMovie);
   
    }
    fin.close();
}

void processChoice(int answer, LinkedList &list, vector<Studio>&stuList, ifstream &fin, ofstream &fout,string &inFile, string &outFile){
    
    string studioTitle;
    string movieTitle;
    string name;
    string go;
    string choice;
    
    switch(answer){
            
            case 1:
             
                bool read;
                read = checkRead(fin,inFile);
                while(true){
                    
                    if(read == true){
                    
                        cout << "true" << endl;
                        readFile(fin, list, stuList); 
                        break;
                    }
                    else{
                        
                        cout << "Do you want to enter another file? Enter \"y\", lower case \"y\", to continue, otherwise enter any key to cancel." << endl;
                        cin >> go;
                        if(go.compare("y") == 0){
                            
                            read = checkRead(fin,inFile);
                        }
                        else{
                            
                            break;
                        }             
                    }
                }
                break;
            case 2:
            
                addMovie(list,stuList);
                break;
            case 3:
            
                cout << "What is the title of the movie you want to delete?" << endl;
                getline(cin,movieTitle);
                deleteMovie(list,stuList,movieTitle);
                break;
            case 4:
            
                printMovieReport(list);
                break;
            
            case 5:
            
                printMovieReportToFile(list,fout,outFile);
                break;
            case 6:
            
                printStudioSales(stuList);
                break;
            case 7:
            
                printStudioSalesToFile(stuList,fout,outFile);
                break;
            
            case 8:
            
                printDetailReport(list);
                break;
            case 9:
            
                printDetailReportToFile(list,fout,outFile);
                break;
            case 10:
            
                cout << "What is the title of the movie you want to search and print?" << endl;
                cin.clear();
                getline(cin,movieTitle);
                searchPrintMovie(list,movieTitle);
                break;
            case 11:
            
                cout << "What is the name of the studio whose info you want to print?" << endl;
                cin.clear();
                getline(cin,studioTitle);
                searchPrintStudio(list,stuList,studioTitle);
                break;
            case 12:
            
                cout << "What is the name of the actor or actress whose movies he or she has been in?" << endl;
                cin.clear();
                getline(cin,name);
                searchPrintActor(list,name);
                break;
            case 13:
            
            return;
            break;
            
            default:
            
            cout << "Invalid command. Enter one of the below: " << endl;
            cin.clear();
            
    }
}

void addMovie(LinkedList &list,vector<Studio> &studioList ){
    
    list.addMovie(studioList);
}

void deleteMovie(LinkedList &list, vector<Studio> &stuList, string title){
    
    list.deleteMovie(stuList,title);
}

bool searchMovie(LinkedList &list,string title){
   
    if(list.searchMovie(title) == true){
        
        return true;
    }
    else{
        
        return false;
    }
}

void displayMenu(){
    
    cout << left;
    cout << "\n";
    cout << "MOVIE DATABASE MENU" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "\"1\" - Read in a file of movie content and add them to list." << endl;
    cout << "\"2\" - Add a movie to the list." << endl;
    cout << "\"3\" - Delete a move from the list." << endl;
    cout << "\"4\" - Print movie report to monitor." << endl;
    cout << "\"5\" - Print movie report to file." << endl;
    cout << "\"6\" - Print studio sales info to monitor." << endl;
    cout << "\"7\" - Print studio sales info to file." << endl;
    cout << "\"8\" - Print detailed report to monitor." << endl;
    cout << "\"9\" - Print detailed report to file." << endl;
    cout << "\"10\" - Search for a particular movie and print details in page format to monitor." << endl;
    cout << "\"11\" - Search for a studio and print studio name and gross income of all movies produced to monitor." << endl;
    cout << "\"12\" - Search for an actor or actress and print all movies he or she has been in in page format to the monitor." << endl;
    cout << "\"13\" - Quit the program." << endl;
}

void printMovieReport(LinkedList &list){
    
    list.displayAllMovieReports();
}

void printMovieReportToFile(LinkedList &list, ofstream &fout, string &outFile){
    
    list.displayAllMovieReportsToFile(fout,outFile);
}

void printDetailReport(LinkedList &list){
    
    list.displayAllDetailReports();
}

void printDetailReportToFile(LinkedList &list, ofstream &fout, string &outFile){
    
    list.displayAllDetailReportsToFile(fout,outFile);
}

void printStudioSales(vector<Studio>&stuList){
    
    cout << left;
    cout << setw(15) << "Studio Name" << setw(15) << "#ofMovies" << setw(15) << "Total Gross Income"  << endl;
    for(int i = 0; i<stuList.size();i++){
        
      cout << setw(15) << stuList.at(i).getName() << setw(15) << stuList.at(i).getNumMovies() << setw(15) << formatIncome(stuList.at(i).getTotalIncome()) << endl;
    }
}

void printStudioSalesToFile(vector<Studio> &stuList, ofstream &fout, string &outFile){
    
    cout << "Enter output file name: " << endl;
    cin >> outFile;
   
    fout.open(outFile.c_str());
    fout << left;
    fout << setw(15) << "Studio Name" << setw(15) << "#ofMovies" << setw(15) << "Total Gross Income"  << endl;
    
    for(int i = 0; i<stuList.size();i++){
        
      fout << setw(15) << stuList.at(i).getName() << setw(15) << stuList.at(i).getNumMovies() << setw(15) << formatIncome(stuList.at(i).getTotalIncome()) << endl;
    }
    
    cout << "Printed studio info to file!" << endl;
    fout.close();    
}
    
 void searchPrintMovie(LinkedList &list, string title){
    
     list.searchPrintMovie(title);
 }   

void searchPrintStudio(LinkedList &list, vector<Studio>&stuList, string studio){
    
    list.searchPrintStudio(stuList,studio);
}   

void searchPrintActor(LinkedList &list, string actorName){
    
    list.searchPrintActor(actorName);
}

void addStudioInfo(string studioName, vector<Studio>&stuList){
    
    if(searchStudio(studioName, stuList) == false){
        
        Studio studio;
        studio.setName(studioName);
        stuList.push_back(studio);
   }
    else{
        
        addMovieToStudio(stuList,studioName);
    }  
}

bool searchStudio(string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            return true;
        }
    }
    
    return false;
}

void addIncomeToStudio(int moreIncome, string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            list.at(i).addIncome(moreIncome);
        }
    }
}

void subtractIncomeFromStudio(int income, string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            list.at(i).subtractIncome(income);
        }
    }
}

void addMovieToStudio(vector<Studio> &stuList,string stuName){
    
  for(int i = 0; i<stuList.size();i++){
        
        if(stuList.at(i).getName() == stuName){
            
            stuList.at(i).addNumMovie();
        }
    }  
}

void subtractMovieFromStudio(vector<Studio> &stuList,string stuName){
    
    for(int i = 0; i<stuList.size();i++){
        
        if(stuList.at(i).getName() == stuName){
            
            
            stuList.at(i).subtractNumMovie();
        }
    }
}
//formats output to show income with dollar sign and 0 cents
string formatIncome(long stuIncome){
    
    stringstream incomeStream;
    incomeStream << stuIncome;
    string income = "$" + incomeStream.str() + ".00";
    
    return income;
}
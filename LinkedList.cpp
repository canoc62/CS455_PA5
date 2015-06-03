//Christopher Cano CS455 PA5
#include<iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#ifndef H_LinkedList
#define H_LinkedList
#include"LinkedList.h"
#include "Studio.h"
using namespace std;

LinkedList::LinkedList()
{
	head.count = 0;
	head.headPtr = NULL;
	return;
}

LinkedList::~LinkedList()
{
	deleteAllNodes();
	return;
}

void LinkedList::addToHead(Movie newData)
{
	Node *pNew = new Node;
	pNew -> data = newData;
	pNew -> next = head.headPtr;
	head.headPtr = pNew;
	head.count++;
}

bool LinkedList::removeFromHead()
{
	bool exit;
	Node *temp;

	if ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
		exit = true; // returns true if successful
	}
	else
		exit = false; // returns false if unsuccessful

	return exit;
}

/*
bool LinkedList::addToTail( int )
{

}
bool LinkedList::removeFromTail()
{

}
*/

void LinkedList::addNode(Movie newData )
{
	Node *pNew = new Node,
	     *pPre = NULL,
	     *pCur = head.headPtr;
	pNew -> data = newData;

	while ( pCur && dataCmp( pNew -> data, pCur -> data ) >= 0 )
	{
		pPre = pCur;
		pCur = pCur -> next;
	}

	if ( pPre )
	{
		pNew -> next = pPre -> next;
		pPre -> next = pNew;
		head.count++;
	}
	else
	{
		pNew -> next = head.headPtr;
		head.headPtr = pNew;
		head.count++;
	}
	
}

bool LinkedList::deleteNode(Movie data)
{
	bool exit;
	Node *pPre = NULL,
	     *pCur = head.headPtr;

	while ( pCur && dataCmp( pCur -> data, data ) != 0 )
	{
		pPre = pCur;
		pCur = pCur -> next;
	}

	if ( pCur && dataCmp( pCur -> data, data ) == 0 )
	{
		if ( pPre )
		{
			pPre -> next = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
		else
		{
			head.headPtr = pCur -> next;
			delete pCur;
			head.count--;
			exit = true; // return true if successful
		}
	}
	else
		exit = false; // return false if unsuccessful

	return exit;
}

void LinkedList::deleteAllNodes()
{
	Node *temp;

	while ( head.headPtr )
	{
		temp = head.headPtr;
		head.headPtr = head.headPtr -> next;
		delete temp;
		head.count--;
	}

	return;
}

bool LinkedList::isEmpty()
{
	return head.count == 0;
}


int LinkedList::getNoOfNodes()
{
	return head.count;
}

void LinkedList::displayAllNodes()
{
	Node *pCur = head.headPtr;
	int nodeCount = 1;

	while ( pCur )
	{
		cout << "Node " << nodeCount << ": ";
		displayNode( pCur );
		cout << endl;

		nodeCount++;
		pCur = pCur -> next;
	}

	return;
}

bool LinkedList::hasDigit(string n)
{
    return std::any_of(n.begin(), n.end(), ::isdigit);
}

void LinkedList::addMovie(vector<Studio> &studioList ){
    
    cout << "What is the title of the movie?" << endl;
    cin.clear();
    string movieTitle;
    getline(cin,movieTitle);
    
    if(searchMovie(movieTitle) == true){
        
        cout << "Cannot add this move because it is already in the list." << endl;
    }
    else{
        
        int year;
        
        cout << "What year was this movie made?" << endl;
        while (true)
        {
            cin >> year;

            if(cin){
                break;
            }
            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Invalid input. Please enter an integer number for year: "<< flush;
            
        }
        cin.ignore();//
        cout << "What was the gross income of the movie?" << endl;
        long income;
        while (true)
        {
            cin >> income;

            if(cin){
                break;
            }
            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Invalid input. Please enter an long number for income: "<< flush;
            
        }
        cin.ignore();//
        cout <<"What is the name of the studio that made this movie?" << endl;
        string studio;
        getline(cin,studio);
        
        addStudioInfo(studio,studioList);
        if(searchStudio(studio,studioList) == true){
            
            //long inc = strtol(income.c_str(),NULL,0);
            addIncomeToStudio(income,studio,studioList);
        }
        
        vector<string> stars;
        cout << "Enter up to 5 star actors and/or actresses of this movie, enter \"done\" to stop before 5: " << endl;
        int counter = 0;
        string name;
        while(counter<5){
            
            while (true){
                
                getline(cin, name);

                if(hasDigit(name)==false){
                    break;
                }
      
                cin.clear();
                cout << "Cannot enter a name containing numbers. Enter again or enter done: " << flush;
            
            }
            
            if(name.compare("done") != 0){
         
                stars.push_back(name);
            }
            else{
               
                break;
            }
            counter++;
        }
        
        Movie newMovie;
        newMovie.readMovie(movieTitle,year, income, studio,stars);
        addNode(newMovie);
        cout<<"New movie " << movieTitle << " added!" << endl;
    }
}

void LinkedList::deleteMovie(vector<Studio> &stuList, string title){
    
    if(searchMovie(title) == true){
        
        cout << "Movie found in list. It will be removed." << endl;
        Node *remove;
        remove = head.headPtr;
        while(remove != NULL){
            
            if(remove->data.getTitle().compare(title) == 0){
                
                //long inc = strtol(remove->data.getIncome().c_str(),NULL,0);
                subtractIncomeFromStudio(remove->data.getIncome(),remove->data.getStudio(),stuList);
                subtractMovieFromStudio(stuList,remove->data.getStudio());
                
                deleteNode(remove->data);
                cout << "Movie removed!" << endl;
                break;
            }
            
            remove = remove->next;
        }
    }
    else{
        
        cout << "Movie cannot be removed because it is not in the list." << endl;
    } 
}

bool LinkedList::searchMovie(string title){
   
        Node *itr;
       
        itr = head.headPtr;
        while(itr != NULL){
            
            if(itr->data.getTitle().compare(title) == 0){
                
                return true;
            }
            
            itr = itr->next;
        }

        return false;
}

void LinkedList::displayMovieReport(Node *node)
{
    stringstream incomeStream;
    incomeStream << node ->data.getIncome();
    string income = "$" + incomeStream.str() + ".00";
   
    cout << setw(25) << node ->data.getTitle() << setw(25) << income << setw(25) << node->data.getYear() << setw(25) << node->data.getStudio() << endl;
}

void LinkedList::displayAllMovieReports(){
    
    Node *pCur = head.headPtr;
	int nodeCount = 1;

        cout << left;
        cout << setw(25) << "Title" << setw(25) << "Gross Income" << setw(25) << "Year" << setw(25) << "Studio" << endl;
	while ( pCur )
	{
		displayMovieReport( pCur );
		nodeCount++;
		pCur = pCur -> next;
	}

	return;
    
}

void LinkedList::displayAllMovieReportsToFile(ofstream&fout,string &outFile){
    
    cout << "Enter output file name: " << endl;
    cin >> outFile;
   
    fout.open(outFile.c_str());
    
    Node *pCur = head.headPtr;

        fout << left;
        fout << setw(25) << "Title" << setw(25) << "Gross Income" << setw(25) << "Year" << setw(25) << "Studio" << endl;
	while ( pCur )
	{
                stringstream incomeStream;
                incomeStream << pCur->data.getIncome();
                string income = "$" + incomeStream.str() + ".00";
                fout << setw(25) << pCur->data.getTitle() << setw(25) << income << setw(25) << pCur->data.getYear() << setw(25) << pCur->data.getStudio() << endl;
		pCur = pCur -> next;
	}
        cout <<"Printed movie report to file!" << endl;
        fout.close(); 

	return;
}

void LinkedList::displayDetailReport(Node *node){
    
    cout << left;
    cout << setw(20) << "Movie Title:" << setw(20) << node->data.getTitle() << endl;
    cout << setw(20) << "Year Made:" << setw(20) << node->data.getYear() << endl;
    cout << setw(20) << "Studio:" << setw(20) << node->data.getStudio() << endl;
    cout << setw(20) << "Stars:" << setw(20) << node->data.starListPrint() << endl;
    cout << setw(20) << "Gross Income:" << "$" << node->data.getIncome() << ".00" << endl;
    cout << "\n" << "****************************************************" << endl;
}

void LinkedList::displayAllDetailReports(){
    
    Node *pCur = head.headPtr;
	int nodeCount = 1;

	while ( pCur )
	{
		displayDetailReport( pCur );
		nodeCount++;
		pCur = pCur -> next;
	}

	return;
    
}

void LinkedList::displayAllDetailReportsToFile(ofstream&fout,string &outFile){
        
    cout << "Enter output file name: " << endl;
    cin >> outFile;
   
    fout.open(outFile.c_str());
    
    Node *pCur = head.headPtr;
    
    while(pCur != NULL){
        
    fout << left;  
    fout << setw(20) << "Movie Title:" << setw(20) << pCur->data.getTitle() << endl;
    fout << setw(20) << "Year Made:" << setw(20) << pCur->data.getYear() << endl;
    fout << setw(20) << "Studio:" << setw(20) << pCur->data.getStudio() << endl;
    fout << setw(20) << "Stars:" << setw(20) << pCur->data.starListPrint() << endl;
    fout << setw(20) << "Gross Income:" << setw(20) << pCur->data.getIncome() << endl;
    fout << "\n" << "****************************************************" << endl;
        
        pCur = pCur->next;
    }
    cout << "Printed detailed report to file!" << endl;
    fout.close();
}

void LinkedList::searchPrintMovie(string title){
    
    bool found  = false; 
    Node *sptr;
    sptr = head.headPtr;
    cout << left;
    while(sptr != NULL){
        
        if(sptr->data.getTitle().compare(title) == 0){
            
            sptr->data.printDetail();
            found = true;
            break;
        }
        
        sptr = sptr->next;
    }
    if(found == false){
        
        cout << "This movie is not on the list." << endl;
    }
 }  

void LinkedList::searchPrintStudio(vector<Studio>&stuList, string studio){
    
    bool found  = false;
    Node *sptr;
    sptr = head.headPtr;
    
    cout << left;
    cout << setw(15) << "Studio Name" << setw(15) << "#ofMovies" << setw(15) << "Total Gross Income"  << endl;
    while(sptr != NULL){
        
        if(sptr->data.getStudio().compare(studio) == 0){
            for(int i =0; i<stuList.size();i++){
        
                if(stuList.at(i).getName().compare(sptr->data.getStudio())==0){
            
                    cout << setw(15) << stuList.at(i).getName() << setw(15) << stuList.at(i).getNumMovies() << setw(15) << formatIncome(stuList.at(i).getTotalIncome()) << endl;
                    break;
                }
            }
        found = true;
        break;
    }
        sptr = sptr->next;
        }
  
    if(found == false){
        
        cout << "This studio entered does not have a movie in the list." << endl;
    }
   
}   

void LinkedList::searchPrintActor(string actorName){
    
    bool found = false;
    Node *sptr;
    sptr = head.headPtr;
    
    while(sptr != NULL){
        
        if(sptr->data.findStar(actorName) == true){
            
            cout << left;
            sptr->data.printDetail();
            found = true;
            break;
        }
        
        sptr = sptr->next;
    }
    
    if(found == false){
        
        cout << "This actor is not in any of the movies in the list." << endl;
    }
}

int LinkedList::dataCmp( Movie value0, Movie value1)
{
	int exit = 0;

	if ( value0.getTitle().compare(value1.getTitle()) < 0 )
		exit = -1;
	else if ( value0.getTitle().compare(value1.getTitle()) > 0)
		exit = 1;

	return exit;
}

void LinkedList::displayNode( Node *node )
{
	cout << node -> data.getTitle();
	return;
}
/*
 
 
 
 */
void LinkedList::addStudioInfo(string studioName, vector<Studio>&stuList){
    
    if(searchStudio(studioName, stuList) == false){
        
        Studio studio;
        studio.setName(studioName);
        stuList.push_back(studio);
   }
    else{
        
        addMovieToStudio(stuList,studioName);
    }  
}

bool LinkedList::searchStudio(string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            return true;
        }
    }
    
    return false;
}

void LinkedList::addIncomeToStudio(int moreIncome, string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            list.at(i).addIncome(moreIncome);
        }
    }
}

void LinkedList::subtractIncomeFromStudio(int income, string studioName, vector<Studio> &list){
    
    for(int i = 0; i<list.size();i++){
        
        if(list.at(i).getName().compare(studioName) == 0){
            
            list.at(i).subtractIncome(income);
        }
    }
}

void LinkedList::addMovieToStudio(vector<Studio> &stuList,string stuName){
    
  for(int i = 0; i<stuList.size();i++){
        
        if(stuList.at(i).getName() == stuName){
            
            stuList.at(i).addNumMovie();
        }
    }  
}

void LinkedList::subtractMovieFromStudio(vector<Studio> &stuList,string stuName){
    
    for(int i = 0; i<stuList.size();i++){
        
        if(stuList.at(i).getName() == stuName){
            
            
            stuList.at(i).subtractNumMovie();
        }
    }
}

string LinkedList::formatIncome(long stuIncome){
    
    stringstream incomeStream;
    incomeStream << stuIncome;
    string income = "$" + incomeStream.str() + ".00";
    
    return income;
}

#endif
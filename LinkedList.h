//Christopher Cano CS455 PA5

/*
--------------------LinkedList------------------------
- head: HeadNode
------------------------------------------------------
+ LinkedList()
+ ~LinkedList()
+ addToHead(Movie): void
+ removeFromHead(): bool
+ addNode(movie): void
+ deleteNode(movie): bool
+ deleteAllNodes(): void
+ isEmpty(): bool
+ getNoOfNodes(): int
+ addMovie(vector<Studio>&): void
+ hasDigit(string): bool
+ deleteMovie(vector<Studio>&,string): void
+ searchMovie(string): bool
+ searchPrintMovie(string): void
+ searchPrintStudio(vector<Studio>&,string):void
+ searchPrintActor(string): void
+ displayAllNodes(): void
+ displayMovieReport(Node*): void
+ displayAllMovieReports(): void
+ displayAllMovieReportsToFile(ofstream&,string&): void
+ displayDetailReport(Node*): void
+ displayAllDetailReports(): void
+ displayAllDetailReportsToFile(ofstream&,string&): void
+ formatIncome(long): string
+ addStudioInfo(string,vector<Studio>&): void
+ searchStudio(string,vector<Studio>&): bool
+ addIncomeToStudio(int, string, vector<Studio> &): void
+ subtractIncomeFromStudio(int, string, vector<Studio> &): void
+ addMovieToStudio(vector<Studio> &,string): void
+ subtractMovieFromStudio(vector<Studio> &,string): void
- dataCmp( Movie, Movie ): int
- displayNode( Node* ): void
------------------------------------------------------------------
 */
#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include "Node.h"
#include "Movie.h"
#include "Studio.h"
#include <fstream>
using namespace std ;
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();

		void addToHead( Movie );
		bool removeFromHead();

//		bool addToTail( int );
//		bool removeFromTail();

		void addNode( Movie );
		bool deleteNode( Movie);
		void deleteAllNodes();

		bool isEmpty();
		int getNoOfNodes();
                bool hasDigit(string);
                void addMovie(vector<Studio>&);
                void deleteMovie(vector<Studio>&,string);
                bool searchMovie(string);
                void searchPrintMovie(string);
                void searchPrintStudio(vector<Studio>&,string);
                void searchPrintActor(string);
		void displayAllNodes();
                void displayMovieReport(Node*);
                void displayAllMovieReports();
                
                void displayAllMovieReportsToFile(ofstream&,string&);
                void displayDetailReport(Node*);
                void displayAllDetailReports();
                void displayAllDetailReportsToFile(ofstream&,string&);
                string formatIncome(long);
                void addStudioInfo(string,vector<Studio>&);
                bool searchStudio(string,vector<Studio>&);
                void addIncomeToStudio(int, string, vector<Studio> &);
                void subtractIncomeFromStudio(int, string, vector<Studio> &);
                void addMovieToStudio(vector<Studio> &,string);
                void subtractMovieFromStudio(vector<Studio> &,string);
               
	private:
		int dataCmp( Movie, Movie );
		void displayNode( Node* );

		HeadNode head;

};

#endif	/* LINKEDLIST_H */


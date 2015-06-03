//Christopher Cano CS455 PA5
/* 
 * File:   Movie.h
 * Author: chrstphrcn
 *
 * Created on July 10, 2014, 11:10 PM
 */

/*
----------------Movie--------------------------------------
- title: string
- year: int
- income: long
- studioName: string
- starsList: vector<string>
------------------------------------------------------------
+ Movie()
+ Movie(string, int, long, string)
+ setTitle(string): void
+ setYear(int): void
+ setIncome(long): void
+ setStudio(string): void
+ setStars(vector<string>): void
+ getTitle(): string
+ getYear(): int
+ getIncome(): long
+ getStudio(): string
+ findStar(string): bool
+ addStar(string): void
+ starListPrint(): string
+ printMovie(): void
+ printDetail(): void
+ readMovie(string,int,long,string,vector<string>): void 
+ equals(Movie otherMovie): bool
--------------------------------------------------------------
 
 */
#ifndef MOVIE_H
#define	MOVIE_H

#include <vector>
#include <string>
#include "Studio.h"

using namespace std;
class Movie{
    
private:
    string title;
    int year;
    long income;
    string studioName;
    vector<string> starsList;
    
public:
    
    Movie();
    Movie(string, int, long, string);
    void setTitle(string);
    void setYear(int);
    void setIncome(long);
    void setStudio(string);
    void setStars(vector<string>);
    string getTitle();
    int getYear();
    long getIncome();
    string getStudio();
    bool findStar(string);
    void addStar(string);
    string starListPrint();
    void printMovie();
    void printDetail();
    void readMovie(string,int,long,string,vector<string>); 
    bool equals(Movie otherMovie);
};


#endif	/* MOVIE_H */


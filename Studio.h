//Christopher Cano CS455 PA5

/* 
 * File:   Studio.h
 * Author: chrstphrcn
 *
 * Created on July 12, 2014, 10:28 PM
 */
//Studio class represents the studio of a move. It keeps track of how many movies a studio has well as its total income from those movies.
/*
-------------Studio-------------
- name: string
- numMovies: int
- totalIncome: long
--------------------------------
+ Studio():
+ ~Studio():
+ setName(string): void
+ getName(): string
+ getTotalIncome(): long
+ getNumMovies(): int
+ addNumMovie(): void
+ addIncome(int): void
+ subtractNumMovie(): void
+ subtractIncome(int): void
---------------------------------
 */

#ifndef STUDIO_H
#define	STUDIO_H
#include <string>
using namespace std;

class Studio{
     
private:
    
    string name;
    int numMovies;
    long totalIncome;
    
public:
    
    Studio();
    ~Studio();
    void setName(string);
    string getName();
    long getTotalIncome();
    int getNumMovies();
    void addNumMovie();
    void addIncome(int);
    void subtractNumMovie();
    void subtractIncome(int);
    
};

#endif	/* STUDIO_H */


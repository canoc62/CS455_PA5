
#include <string>
#include "Studio.h"
using namespace std;

    Studio::Studio(){
        
         name = "";
         numMovies = 1;
         totalIncome = 0;
    }
    
    Studio::~Studio(){
        
       // delete name;
       // delete numMovies;
       // delete totalIncome;
    }
    
   void  Studio::setName(string stuName){
        
        name = stuName;
    }
    
   string Studio::getName(){
        
        return name;
    }
    
   long Studio::getTotalIncome(){
        
        return totalIncome;
    }
    
   int Studio::getNumMovies(){//int
        
        return numMovies;
    }
    
   void Studio::addNumMovie(){
        
        numMovies++;
    }
    
   void Studio::addIncome(int addedToIncome){
        
        totalIncome += addedToIncome;
    }
   
   void Studio::subtractNumMovie(){
       
       numMovies--;
   }
   
   void Studio::subtractIncome(int subtractFromIncome){
       
       totalIncome-=subtractFromIncome;
   }
    

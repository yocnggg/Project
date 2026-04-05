/**
 * focaccia.cpp
  * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 *
 * Zihao.Yang
 * yocnggg
 *
 * EECS 183: Project 1
 * Winter 2026
 * 
 * <#description#>
 *
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;

        
    //fix "magic number"
    
    
    const double PEOPLE_PER_LOAF = 4.0;

    //single cup/spoon each loaf use
        const double FLOUR_CUPS_PER_LOAF = 5.0;
        
        const double YEAST_TSP_PER_LOAF = 1.75;
        
        const double SALT_TSP_PER_LOAF = 1.875;
        
        const double OIL_TBSP_PER_LOAF = 2.0;
  
    
    //cup or spoon ----> bag or can or bottle
        const double FLOUR_CUPS_PER_BAG = 20.0;
        
        const double YEAST_TSP_PER_PKG = 2.25;
        
        const double SALT_GRAMS_PER_TSP = 5.0;
        const double SALT_GRAMS_PER_CAN = 30.0;
        
        const double OIL_ML_PER_TBSP = 14.8;
        const double OIL_ML_PER_BOTTLE = 500.0;
   
  
    // single cost
        const double COST_FLOUR_BAG = 2.69;
        const double COST_YEAST_PKG = 0.40;
        const double COST_SALT_CAN = 0.49;
        const double COST_OIL_BOTTLE = 6.39;

      

    //develpment cycle
        int loaves = ceil(people / PEOPLE_PER_LOAF);

    //total amount of use
        double totFlour = FLOUR_CUPS_PER_LOAF * loaves;
        double totYeast = YEAST_TSP_PER_LOAF * loaves;
        double totSalt = SALT_TSP_PER_LOAF * loaves;
        double totOil = OIL_TBSP_PER_LOAF * loaves;

    //total bag or can or bottle of use
        int flourBags = ceil(totFlour / FLOUR_CUPS_PER_BAG);
        int yeastPkgs = ceil(totYeast / YEAST_TSP_PER_PKG);
        int saltCans = ceil((totSalt * SALT_GRAMS_PER_TSP) / SALT_GRAMS_PER_CAN);
        int oilBottles = ceil((totOil * OIL_ML_PER_TBSP) / OIL_ML_PER_BOTTLE);
    
    
    //totalcost
    
    double totalCost = flourBags * COST_FLOUR_BAG + yeastPkgs * COST_YEAST_PKG + saltCans * COST_SALT_CAN + oilBottles * COST_OIL_BOTTLE;

    
    //same output as the Project1 introduction
    
    
    cout << "You need to make: " << loaves << " " << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl;

    cout << endl;

    cout << "Shopping List for Focaccia Bread" << endl;
    
    cout << "--------------------------------" << endl;

    cout << flourBags << " " << pluralize("bag", "bags", flourBags) << " of flour" << endl;

    cout << yeastPkgs << " " << pluralize("package", "packages", yeastPkgs) << " of yeast" << endl;

    cout << saltCans << " " << pluralize("canister", "canisters", saltCans) << " of salt" << endl;

    cout << oilBottles << " " << pluralize("bottle", "bottles", oilBottles) << " of olive oil" << endl;

    cout << endl;

    cout << "Total expected cost of ingredients: $" << totalCost << endl;
    
    cout << endl;

    cout << "Have a great party!" << endl;

    


        return 0;
    }

    
// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}


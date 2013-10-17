*** README ***

file(s):  buildDeck.cpp, Card.h CityCard.h, EpidemicCard.h, EventCard.h

This is just a basic Card class and driver to test the creation of a deck of cards.
All of the 48 cities and 5 event cards are "stringed" together in an array.  An 
unordered_set is used to store a set of 53 random numbers.  These will be the 
unique id's for the Cards.

An array of six random numbers will be used for the somewhat evenluy placed EPIDEMIC
cards to be inserted into the deck upon creation.

The main loop will create individual Card object.  If the current index is one found
in the epidemic array, then an EPIDEMIC card is inserted.  Otherwise, and Card object,
with city name or event name, will be inserted.

COMPILING FROM THE COMMAND LINE:
Because this uses an "unordered_set" for the random deck id's, you will need to include
the "-std=gnu++11" argument to your command line.

Example:  g++ -std=gnu++11 buildDeck.cpp

The purpose of this submission is to provide one example of how the deck creation
can be done.

-- Derrick(3dfxScorpion)

FIXED ISSUE of missing city (forgot a comma...)

20131015 - 
    converted to handle Chris' CityCard and EventCard classes, as well as a newly created EdipemicCard



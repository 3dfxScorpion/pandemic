*** README ***

file(s):  buildDeck.cpp, Card.h

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


KNOWN ISSUE:

- for some reason, one card is blank...

deck created:
ID: 0 - Baghdad
ID: 1 - EPIDEMIC
ID: 2 - Jakarta
ID: 3 - Miami
ID: 4 - Delhi
ID: 5 - Paris
ID: 6 - Sao Paulo
ID: 7 - Airlift
ID: 8 - Essen
ID: 9 - Bangkok
ID: 10 - Mexico City
ID: 11 - Riyadh
ID: 12 - Milan
ID: 13 - St. Petersburg
ID: 14 - EPIDEMIC
ID: 15 - Montreal
ID: 16 - Government Grant
ID: 17 - OsakaOne Quiet Night
ID: 18 - San Francisco
ID: 19 - 
ID: 20 - Washington
ID: 21 - Tokyo
ID: 22 - Chennai
ID: 23 - EPIDEMIC
ID: 24 - EPIDEMIC
ID: 25 - Seoul
ID: 26 - Manila
ID: 27 - New York
ID: 28 - Resilient Population
ID: 29 - Hong Kong
ID: 30 - Santiago
ID: 31 - Tehran
ID: 32 - Beijing
ID: 33 - Bogota
ID: 34 - Atlanta
ID: 35 - Forecast
ID: 36 - EPIDEMIC
ID: 37 - Cairo
ID: 38 - Sydney
ID: 39 - Istanbul
ID: 40 - Khartoum
ID: 41 - Kinshasa
ID: 42 - Shanghai
ID: 43 - EPIDEMIC
ID: 44 - Kolkata
ID: 45 - Ho Chi Minh City
ID: 46 - Mumbai
ID: 47 - Lagos
ID: 48 - London
ID: 49 - Los Angeles
ID: 50 - Buenos Aires
ID: 51 - Lima
ID: 52 - Moscow
ID: 53 - Taipei
ID: 54 - Karachi
ID: 55 - Johannesburg
ID: 56 - Algiers
ID: 57 - Madrid
ID: 58 - Chicago



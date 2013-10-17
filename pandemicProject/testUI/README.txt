*** README ***

file(s):  ALL OF THEM (though hacked and possibly renamed by me)

This is a consolidation of files that will allow a few, simple actions to execute.

The main loop will create a deck, two players, and deal each player four cards.

COMPILING FROM THE COMMAND LINE:
Because this uses an "unordered_set" for the random deck id's, you will need to include
the "-std=gnu++11" argument to your command line.

Example:  g++ -std=gnu++11 buildDeck.cpp


-- Derrick(3dfxScorpion)

TO DO:
  Finish Deck class to create deck of n size.  Add shuffle method.


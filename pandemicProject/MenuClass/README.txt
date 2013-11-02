*** README ***

file(s):  adding MenuClass folder

This will currnently take a Map and vector<Player*> and display them nicely
in a menu format.

Methods:

    Map& getMenuMap() { return menuMap; }
    vector<Player*> getMenuPlayers() { return menuPlayers; }
    void setMenuMap(Map& m) { menuMap = m; }
    void setMenuPlayers(vector<Player*> p) { menuPlayers = p; }
    string menuCities(Map&);
    string menuHands(vector<Player*>);


Thanks,

-- Derrick(3dfxScorpion)

to do:
  Implement command menu for starters...

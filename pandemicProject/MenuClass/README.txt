*** README ***

file(s):  adding MenuClass folder

This will currnently take a Map and vector<Player*> and display them nicely
in a menu format.  I need to add the means to associate primary or submenu(s)
to appropriate switch/case decision tree.

Welcome to Pandemic
==========================================================================================
City:            Blk:   Blu:   Red:   Yel:    City:            Blk:   Blu:   Red:   Yel:
==========================================================================================
San Francisco     1      0      1      0      Algiers           1      0      1      0
Chicago           1      1      0      0      Cairo             0      0      1      1
Atlanta           0      1      1      0      Istanbul          0      1      1      0
Montreal          1      1      0      1      Moscow            0      1      0      1
New York          0      1      1      1      Tehran            1      0      1      1
Washington        1      0      1      1      Baghdad           1      1      1      0
London            0      1      0      1      Riyadh            1      0      1      0
Madrid            0      1      1      0      Karachi           1      1      0      0
Paris             0      1      1      1      Mumbai            0      0      1      1
Essen             1      0      1      0      Delhi             1      0      0      1
Milan             0      1      1      1      Kolkata           0      1      1      0
St. Petersburg    1      0      0      0      Chennai           1      1      1      0
Los Angeles       0      1      0      1      Bangkok           0      1      1      0
Mexico City       1      1      0      0      Jakarta           1      0      1      0
Miami             0      1      1      0      Beijing           0      1      1      1
Bogota            1      0      0      1      Shanghai          1      0      0      1
Lima              1      1      0      0      Hong Kong         0      1      1      0
Santiago          1      1      0      0      Ho Chi Minh City  1      1      1      0
Sao Paulo         1      1      0      0      Seoul             0      1      1      0
Buenos Aires      0      1      1      1      Taipei            0      1      0      1
Lagos             1      1      0      0      Manila            1      0      0      0
Kinshasa          1      0      1      0      Sydney            0      0      1      0
Khartoum          1      0      1      0      Tokyo             1      1      1      1
==========================================================================================
   Player 1                 Player 2                 Player 3                 Player 4
==========================================================================================
(0)Manila                (1)Tehran                (2)Lagos                 (3)Washington
(4)Government Grant      (5)Bogota                (6)Khartoum              (7)Essen
(8)Mumbai                (9)Baghdad               !!-Epidemic-!!           (11)Santiago
(12)St. Petersburg       (13)New York             !!-Epidemic-!!           (15)Moscow
(16)Paris                (17)Resilient Population (18)Tokyo                (19)Montreal
(20)Ho Chi Minh City     (21)Bangkok              (22)Chicago              (23)Miami
(24)Jakarta              (25)Mexico City          (26)Hong Kong            !!-Epidemic-!!
(28)Sao Paulo            (29)Istanbul             (30)Kinshasa             (31)London
!!-Epidemic-!!           (33)Kolkata              (34)Milan                (35)Beijing
(36)Chennai              (37)Forecast             (38)Taipei               (39)Cairo
==========================================================================================
Select from the following:
(0)Move To City             (5)Treat Disease
(1)Charter Flight           (6)Cure Disease
(2)Direct Flight            (7)Share Knowledge
(3)Shuttle Flight           (8)Done with Actions
(4)Build Station            (9)Exit
9

Goodbye...

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
  Associate switch/case decision tree to appropriate command menu


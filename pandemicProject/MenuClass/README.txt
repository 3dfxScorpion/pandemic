*** README ***

file(s):  adding MenuClass folder

This will currnently take a Map and vector<Player*> and display them nicely
in a menu format.

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
(0)Montreal              (1)Istanbul              (2)New York              (3)Resilient Population
(4)Mumbai                (5)Riyadh                !!-Epidemic-!!           (7)Baghdad
(8)Jakarta               (9)Airlift               (10)Seoul                (11)Paris
(12)Hong Kong            (13)Khartoum             (14)San Francisco        (15)Mexico City
(16)Miami                (17)Manila               (18)Forecast             (19)Government Grant
!!-Epidemic-!!           (21)Los Angeles          (22)Shanghai             (23)Tokyo
(24)One Quiet Night      (25)Bangkok              !!-Epidemic-!!           (27)Johannesburg
(28)Chennai              (29)Kinshasa             (30)Milan                (31)Cairo
(32)Lagos                (33)Tehran               (34)Chicago              !!-Epidemic-!!
(36)Buenos Aires         (37)Essen                (38)Karachi              (39)St. Petersburg
==========================================================================================


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

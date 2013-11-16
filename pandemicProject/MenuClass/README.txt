*** README ***

MenuClass

Slightly new look and new functionality:

====================================================================================================
City:               Black:  Blue:  Red:  Yellow:  City:               Black:  Blue:  Red:  Yellow:
====================================================================================================
San Francisco-(R)     1      0      1      0      Algiers               1      0      1      0
Chicago               1      1      0      0      Cairo                 0      0      1      1
Atlanta               0      1      1      0      Istanbul              0      1      1      0
Montreal              1      1      0      1      Moscow                0      1      0      1
New York-(R)          0      1      1      1      Tehran                1      0      1      1
Washington-(R)        1      0      1      1      Baghdad               1      1      1      0
London                0      1      0      1      Riyadh                1      0      1      0
Madrid                0      1      1      0      Karachi               1      1      0      0
Paris-(R)             0      1      1      1      Mumbai                0      0      1      1
Essen                 1      0      1      0      Delhi                 1      0      0      1
Milan                 0      1      1      1      Kolkata               0      1      1      0
St. Petersburg        1      0      0      0      Chennai               1      1      1      0
Los Angeles-(R)       0      1      0      1      Bangkok               0      1      1      0
Mexico City           1      1      0      0      Jakarta               1      0      1      0
Miami                 0      1      1      0      Beijing               0      1      1      1
Bogota                1      0      0      1      Shanghai              1      0      0      1
Lima                  1      1      0      0      Hong Kong-(R)         0      1      1      0
Santiago-(R)          1      1      0      0      Ho Chi Minh City      1      1      1      0
Sao Paulo             1      1      0      0      Seoul                 0      1      1      0
Buenos Aires-(R)      0      1      1      1      Taipei                0      1      0      1
Lagos                 1      1      0      0      Manila-(R)            1      0      0      0
Kinshasa              1      0      1      0      Sydney-(R)            0      0      1      0
Khartoum              1      0      1      0      Tokyo                 1      1      1      1
====================================================================================================
     Player 1                 Player 2                 Player 3                 Player 4
  in Istanbul              in San Francisco         in Hong Kong             in Atlanta
----------------------------------------------------------------------------------------------------
(0)Beijing               (1)Kolkata               (2)Manila                (3)New York
(4)Resilient Population  (5)Johannesburg          (6)Karachi               (7)Paris
!!-Epidemic-!!           (9)Essen                 (10)Milan                (11)Baghdad
(12)Lima                 (13)Istanbul             (14)Kinshasa             (15)Ho Chi Minh City
(16)Forecast             (17)Seoul                (18)Mexico City          (19)Government Grant
!!-Epidemic-!!           (21)Airlift              (22)Miami                !!-Epidemic-!!
(24)Chicago              (25)Madrid               (26)Sydney               (27)Jakarta



====================================================================================================
Select from the following:                        Cubes Remaining:
(0)Move To City             (5)Treat Disease            Black                    0
(1)Charter Flight           (6)Cure Disease             Blue                     1
(2)Direct Flight            (7)Share Knowledge          Red                      2
(3)Shuttle Flight           (8)Done with Actions        Yellow                   3
(4)Build Station            (9)Exit
1
charter flight to city...
Adjacent Cities
----------------
(1)Algiers
(2)Baghdad
(3)Cairo
(4)Milan
(5)Moscow
(6)St. Petersburg

You entered: Charter Flight
Press any key to continue . . .

Added:
    map<int,string> mappedCmds;
    map<int, void(*)(PlayerMove*)> mappedFuncs;

    These are for mapping "choices" to strings and the actual functions to
    perform the desired action.

Methods:
    Changed menuAdjCities method to be a static method, rather than
    a class method in order to test external accessibility of the
    function pointers

Other:
    Menu shows:
        cubes (placeholder for now)
        current player location
        adjacent city list when choose to travel

Enjoy,

-- Derrick(3dfxScorpion)



*** README ***

NEW mainProject folder (old can be found under mainProject_old)

Slightly new look and new functionality:

====================================================================================================
City:               Black:  Blue:  Red:  Yellow:  City:               Black:  Blue:  Red:  Yellow:
====================================================================================================
San Francisco         0      0      0      0      Algiers               0      0      0      0
Chicago               0      0      0      0      Cairo                 0      0      0      0
Atlanta-(R)           0      0      0      0      Istanbul              0      0      0      0
Montreal              0      3      0      0      Moscow                1      0      0      0
New York              0      0      0      0      Tehran                0      0      0      0
Washington            0      0      0      0      Baghdad               0      0      0      0
London                0      0      0      0      Riyadh                0      0      0      0
Madrid                0      0      0      0      Karachi               0      0      0      0
Paris                 0      2      0      0      Mumbai                3      0      0      0
Essen                 0      0      0      0      Delhi                 1      0      0      0
Milan                 0      0      0      0      Kolkata               0      0      0      0
St. Petersburg        0      0      0      0      Chennai               0      0      0      0
Los Angeles           0      0      0      0      Bangkok               0      0      0      0
Mexico City           0      0      0      0      Jakarta               0      0      2      0
Miami                 0      0      0      0      Beijing               0      0      1      0
Bogota                0      0      0      0      Shanghai              0      0      0      0
Lima                  0      0      0      0      Hong Kong             0      0      0      0
Santiago              0      0      0      3      Ho Chi Minh City      0      0      0      0
Sao Paulo             0      0      0      0      Seoul                 0      0      0      0
Buenos Aires          0      0      0      0      Taipei                0      0      0      0
Lagos                 0      0      0      0      Manila                0      0      0      0
Kinshasa              0      0      0      0      Sydney                0      0      0      0
Khartoum              0      0      0      0      Tokyo                 0      0      0      0
====================================================================================================
        Perl                     Ruby                   Python             The Other Code
 in Atlanta               in Atlanta               in Atlanta               in Atlanta
 ----------------------------------------------------------------------------------------------------
 (0)London                (2)Lima                  (4)Mexico City           (6)Bogota
 (1)Tokyo                 (3)Jakarta               (5)Istanbul              (7)Bangkok








 ====================================================================================================
         Perl select from the following (10 to Exit):     Cubes Remaining:
 (0)Move To City               (5)Treat Disease              black   19
 (1)Charter Flight             (6)Cure Disease               blue    19
 (2)Direct Flight              (7)Share Knowledge            red     21
 (3)Shuttle Flight                                           yellow  19
 (4)Build Station



 Finally integrated MenuClass into MVC.  There are a few things to note as we move forward with
 added menu functionality:

  - Controller.cpp includes a string array to which menu options are to be placed:

        // primary commands
        string cmds01[] = {
            "Move To City",
            "Charter Flight",
            "Direct Flight",
            "Shuttle Flight",
            "Build Station",
            "Treat Disease",
            "Cure Disease",
            "Share Knowledge",
        };

 - There is an array of function references that point to the associative menu option:

         // array of function pointers
         void(*fns[])(Player*) = {
             &do_move_to_city,
             &do_charter_flight,
             &do_direct_flight,
             &do_shuttle_flight,
             &do_build_station,
             &do_treat_disease,
             &do_cure_disease,
             &do_share_knowledge
         };

  -  As we implement the actual menu option/function combination, just change the two
    two listings shown about, plus the function declarations found in Controller.cpp
    and the rest of the code will do the rest.

    **NOTE** - the functions currently take a Player* as an argument, so menu functions
               references are based on that function signature.  Again, this can be
                changed as needed in the future

 - The main menu now reflects:
    - current location(s) of research station(s)
   - current outbreak levels of infected cities
    - current infection cube count
         - current player's name and location
    - background music (just kidding...)

With the ability to Load games, or implement scenarios, we can test how well the menu
does in fact show such changes.  So, please feel free to test away!

Enjoy,

-- Derrick(3dfxScorpion)


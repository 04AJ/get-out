#include <iostream>
#include "Floor.h"
using namespace std;

int main()
{

    // creating all floors
    char **maze3 = Floor::create2DArray("mazes/maze3.txt");
    char **maze2 = Floor::create2DArray("mazes/maze2.txt");
    char **maze1 = Floor::create2DArray("mazes/maze1.txt");

    // opening menu
    cout << R"(
                ('-.    .-') _                                     .-') _    
              _(  OO)  (  OO) )                                   (  OO) )   
  ,----.     (,------. /     '._         .-'),-----.  ,--. ,--.   /     '._  
 '  .-./-')   |  .---' |'--...__)       ( OO'  .-.  ' |  | |  |   |'--...__) 
 |  |_( O- )  |  |     '--.  .--'       /   |  | |  | |  | | .-') '--.  .--' 
 |  | .--, \ (|  '--.     |  |          \_) |  |\|  | |  |_|( OO )   |  |    
(|  | '. (_/  |  .--'     |  |            \ |  | |  | |  | | `-' /   |  |    
 |  '--'  |   |  `---.    |  |             `'  '-'  '('  '-'(_.-'    |  |    
  `------'    `------'    `--'               `-----'   `-----'       `--'    
)" << endl;
    cout << "1: Create new character    2: Load character from file" << endl;
    int load = 0;
    cin >> load;

    if (load == 1)
    {

        cout << "Option 1: Ghostbuster" << endl;
        cout << R"(                       ---                                     
                    -        --                             
                --( /     \ )XXXXXXXXXXXXX                   
            --XXX(   O   O  )XXXXXXXXXXXXXXX-              
           /XXX(       U     )        XXXXXXX\               
         /XXXXX(              )--   XXXXXXXXXXX\             
        /XXXXX/ (      O     )   XXXXXX   \XXXXX\
        XXXXX/   /            XXXXXX   \   \XXXXX----        
        XXXXXX  /          XXXXXX         \  ----  -         
---     XXX  /          XXXXXX      \           ---        
  --  --  /      /\  XXXXXX            /     ---=         
    -        /    XXXXXX              '--- XXXXXX         
      --\/XXX\ XXXXXX                      /XXXXX         
        \XXXXXXXXX                        /XXXXX/
         \XXXXXX                         /XXXXX/         
           \XXXXX--  /                -- XXXX/       
            --XXXXXXX---------------  XXXXX--         
               \XXXXXXXXXXXXXXXXXXXXXXXX-            
                 --XXXXXXXXXXXXXXXXXX-)"
             << endl;
        cout << "Option 2: Detective" << endl;
        cout << R"(
                             /^\/^\
                             \----|
                         _---'---~~~~-_
                          ~~~|~~L~|~~~~
                             (/_  /~~--
                           \~ \  /  /~
                         __~\  ~ /   ~~----,
                         \    | |       /  \
                         /|   |/       |    |
                         | | | o  o     /~   |
                       _-~_  |        ||  \  /
                      (// )) | o  o    \\---'
                      //_- |  |          \
                     //   |____|\______\__\
                     ~      |   / |    |
                             |_ /   \ _|
                           /~___|  /____\           )"
             << endl;
        cout << "Option 3: Vampire Slayer" << endl;
        cout << R"( 
                         /\
                         || 
                         ||
                         ||
                         ||           {}
                         ||          .--.
                         ||         /.--.\
                         ||         |====|
                         ||         |`::`|
                        _||_    .-;`\..../`;_.-^-._
                         /\\   /  |...::..|`   :   `|
                         |:'\ |   /'''::''|   .:.   |
                          \ /\;-,/\   ::  |..:::::..|
                           \ <` >  >._::_.| ':::::' |
                            `""`  /   ^^  |   ':'   |
                                  |       \    :    /
                                  |        \   :   /
                                  |___/\___|`-.:.-`
                                   \_ || _/    `
                                   <_ >< _>
                                   |  ||  |
                                   |  ||  |
                                  _\.:||:./_
                                 /____/\____\
         )"
             << endl;
        cout << "Enter 1,2, or 3 to select your character type:" << endl;
        int charType = 0;
        cin >> charType;

        cout << "Name your character: " << endl;
        string charName;
        getline(cin, charName);

        char myChar = 'A';
        int cX = 0;
        int cY = 2;
        maze3[cX][cY] = myChar;
        Floor::printMap(maze3);
        cout << "Type w a s d and click enter to move your character, type q and click enter to quit" << endl;
        char input;
        cin >> input;

        while (input != 'q' || input != 'Q')
        {
            Floor::userInput(input, maze3, myChar, cX, cY);
            Floor::printMap(maze3);
            cin >> input;
        }
    }

    delete[] maze3;
    return 0;
}

/*
Sources:
https://www.google.com/url?q=https://www.dcode.fr/maze-generator&sa=D&source=docs&ust=1669275854077728&usg=AOvVaw31qhAtfq_0OdMb2YnPPFJB
https://www.asciiart.eu/movies/ghostbusters
https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Ghost&t=Get%20Out
https://www.asciiart.eu/people/occupations/knights
https://ascii.co.uk/art/detective


*/
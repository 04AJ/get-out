#include <iostream>
#include "Floor.h"
using namespace std;

// char floor3[11][31] = {
// {' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
// {' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
// {'#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#',' ',' ','#','#','#','#','#','#','#',' ', ' ', '#',' ',' ','#',' ',' ','#'},
// {#     #     #  #           #  #},
// {#######  #  ####  ##########  #},
// {#     #  #  #           #     #},
// {####  #  #############  #######},
// {#        #        #  #        #},
// {####  ####  #######  #  #######},
// {#                    #         },
// {############################   },

// }

int main()
{

    ifstream finput;
    finput.open("mazes/maze3.txt");
    char *maze3 = create2DArray(finput);

    for (int i = 0; i < 11; i++)
    {

        for (int j = 0; j < 31; j++)
        {
            cout << maze3[i][j];
        }
        cout << endl;
    };

    // cout << endl;
    // finput.open("mazes/maze2.txt");
    // create2DArray(finput);
    return 0;
}
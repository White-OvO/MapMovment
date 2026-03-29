#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int row = 10;
    const int col = 15;
    string input = "";
    char arr[row][col];
    int moveInputRow;
    int currentPosition;
    int moveInputCol;

    for (int i = 0; i < row; i++)

        for (int j = 0; j < col; j++)

            arr[i][j] = '\0';

    // Open and read from trees.csv
    ifstream iFile("trees.csv");
    if (!iFile)
    {
        cout << "Error: Could not open trees.csv\n";
        return 1;
    }

    string line;
    getline(iFile, line); // Skip header line
                          //  cout << line << endl;
    while (!iFile.eof())
    {
        getline(iFile, line);
        //  cout << line << endl;
        int p = line.find(',');

        int x = stoi(line.substr(0, p));
        int y = stoi(line.substr(p + 1, line.length()));

        arr[y][x] = 't';
        arr[9][0] = 'p';
    }

    // verify that the x is a valid x . ( along the colum or going tothe negative colum or bigger colum
    //  neither a negative row or a postive row .
    // make sure its not on top of a tree
    //  replace p sith a - or emprt charatcer when moving p
    //  move the p where the new move coordinates

    iFile.close();

    // Display initial map

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == '\0')
                cout << "_ ";
            else
                cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    bool invalidInput = false;
    while (true)
    {
        // Prompt for move or quit
        do
        {
            cout << "(m)ove -or- (q)uit? ";
            cin >> input;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(128, '\n');
                input = "";
            }

            if (input != "m" && input != "M" && input != "q" && input != "Q")
            {
                cout << "Error: Invalid option\n";
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        cout << (arr[i][j] == '\0' ? "_ " : string(1, arr[i][j]) + " ");
                    }
                    cout << endl;
                }
            }
        } while (input != "m" && input != "M" && input != "q" && input != "Q");

        if (input == "q" || input == "Q")
        {
            cout << "\nQuitting...\n";
            break;
        }

        // Move logic

        // Validate row input
        while (true)
        {
            cout << "\nMove Row: ";
            cin >> moveInputRow;

            if (!cin.fail() && moveInputRow >= 0 && moveInputRow <= 9)
            {
                invalidInput = false;
                break; // valid row input
            }

            // Invalid input
            invalidInput = true;
            cout << "\nError: Move must be between 0 and 9\n";
            cin.clear();
            cin.ignore(128, '\n');

            // Reprint map
            cout << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (arr[i][j] == '\0')
                        cout << "_ ";
                    else
                        cout << arr[i][j] << " ";
                }
                cout << endl;
            }

            if (input != "M" || input != "m" || input != "q'" || input != " Q")
                cout << "(m)ove -or- (q)uit? ";
            cin >> input;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(128, '\n');
                input = "";
            }

            if (input != "m" && input != "M" && input != "q" && input != "Q")
            {
                cout << "Error: Invalid option\n";
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        cout << (arr[i][j] == '\0' ? "_ " : string(1, arr[i][j]) + " ");
                    }
                    cout << endl;
                }
            }
            continue;

            // No need for continue here — the loop will repeat naturally
        }

        // Validate column input
        while (true)
        {
            cout << "Move Column: ";
            cin >> moveInputCol;

            if (!cin.fail() && moveInputCol >= 0 && moveInputCol <= 14)
            {
                invalidInput = false;
                break; // valid column
            }
            else {
                invalidInput = true;

            cout << "\nError: Move must be between 0 and 14\n";
            cin.clear();
            cin.ignore(128, '\n');


           //  cout << "Error: Invalid option\n";
           cout << endl; 
                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        cout << (arr[i][j] == '\0' ? "_ " : string(1, arr[i][j]) + " ");
                    }
                    cout << endl;
                }
            }
            // Reprint map
            // for (int i = 0; i < row; i++)
            // {
            //     for (int j = 0; j < col; j++)
            //     {
            //         if (arr[i][j] == '\0')
            //             cout << "_ ";
            //         else
            //             cout << arr[i][j] << " ";
            //     }
            //     cout << endl;
            // }

           break ; 
        }

        if (invalidInput == false && arr[moveInputRow][moveInputCol] == 't')
        {
            cout << "\nThere's a tree in your way\n\n";


             for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        cout << (arr[i][j] == '\0' ? "_ " : string(1, arr[i][j]) + " ");
                    }
                    cout << endl;
                }
            continue;
        }
        //   else
        //    {
        // arr[moveInputRow][moveInputCol] = 'p';
        //      } // Reprint map
if ( invalidInput == true ) { 
    continue;
    }else { 
        cout << "\n\nMoved to row " << moveInputRow << " column " << moveInputCol << endl << "\n" ;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == moveInputRow && j == moveInputCol)
                {
                    arr[i][j] = 'p';
                    cout << arr[i][j] << ' ';
                }
                else if (arr[i][j] == '\0' || arr[i][j] == 'p')
                {
                    cout << "_ ";
                }
                else
                {
                    cout << arr[i][j] << " ";
                }
            }
        
        cout << endl; 
        }
                  }
    }
    return 0;
}




// read 10 numbers from user in a array and then print the array in a reverse order we do not have to chagne the position 

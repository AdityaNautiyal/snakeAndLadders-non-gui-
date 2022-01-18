#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


void board();//initialize function to draw the board

int check_progress();//initialize function to check game progress

int roll_dice();//initialize function to roll dice

//then we declare some variables

int roll1; //holds the rolled value for the player
int roll2; //holds the rolled value for computer

int input1; //variable to hold the users input, any number to roll dice and 0 to quit game, although entering a not a number value ends  the game as well...
int input2;
int progress; //holds the value for the progress

int player1 = 0;

int  player2= 0;

//both player and computer's initial starting point is 0

int squares[99]; // for the 100 squares, computers right counts from 0


int main() //this is where it all goes down in c++, it's like the canvas for da vinci...
{
    srand( time(NULL) ); //we need random numbers remeber?

    string alert1 = ""; //to alert you for your triumphs and misfortunes
    string alert2 = ""; // to alert you for computer's triumphs and misfortunes

    cout << "Welcome to snakes and ladders, enter any number to roll dice, press 0 to quit\n\n";
    cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n";

    for ( int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
        {
            squares[i] = i;
        }

    do // every game is in some sort of loop
    {
        cout << "input any number and enter: ";
        cin >> input1;

        roll1 = roll_dice();//player rolls dice

        if( (roll1 + player1) > 100)
        {
            player1 = player1; //player has rolled a number that exceeds the end point player remains where they are
        }
        else
        {
            squares[player1] = player1;//overwrite the current position
            player1 = player1 + roll1;//move player to a new position
        }

        cout << "input any number and enter:";
        cin >> input2;
        roll2 = roll_dice();//computer rolls dice

        if( (roll2 + player2) > 100)
        {
            player2 = player2; //computer has rolled a number that exceeds the end point, computer remains where it is
        }
        else
        {
            squares[player2] = player2;//overwrite the current position
            player2 = player2 + roll2;//move computer to a new position
        }

        switch(player1) // it is snakes and ladders, numbers represent the snakes and ladders
        {
            case 99:
            player1 = 5;
            alert1 = "OOPS... Player1 ran into a SNAKE!";
            break;

            case 93:
            player1 = 25;
            alert1 = "OOPS... Player1 ran into a SNAKE!";
            break;

            case 77:
            player1 = 9;
            alert1 = "OOPS... Player1 ran into a SNAKE!";
            break;

            case 52:
            player1 = 6;
            alert1 = "OOPS... Player1 ran into a SNAKE!";
            break;

            case 30:
            player1 = 2;
            alert1 = "OOPS... Player1 ran into a SNAKE!";
            break;

            case 45:
            player1 = 66;
            alert1 = "YAY! Player1 climbed a ladder!!!";
            break;

            case 35:
            player1 = 67;
            alert1 = "YAY! Player1 climbed a ladder!!!";
            break;

            case 20:
            player1 = 41;
            alert1 = "YAY! Player1 climbed a ladder!!!";
            break;

            case 8:
            player1 = 28;
            alert1 = "YAY! Player1 climbed a ladder!!!";
            break;

            case 4:
            player1 = 36;
            alert1 = "YAY! you climbed a ladder!!!";
            break;

            default:
            alert1 = "";

       }

        switch(player2)
        {
            case 99:
            player2 = 5;
            alert2 = "OOPS... Player2 ran into a SNAKE!";
            break;

            case 93:
            player2 = 25;
            alert2 = "OOPS... PLayer2 ran into a SNAKE!";
            break;

            case 77:
            player2 = 9;
            alert2 = "OOPS... PLayer2 ran into a SNAKE!";
            break;

            case 52:
            player2 = 6;
            alert2 = "OOPS... PLayer2 ran into a SNAKE!";
            break;

            case 30:
            player2 = 2;
            alert2 = "OOPS... Player2 ran into a SNAKE!";
            break;

            case 45:
            player2 = 66;
            alert2 = "YAY Player2 climbed a ladder!!!";
            break;

            case 35:
            player2 = 67;
            alert2 = "YAY Player2 climbed a ladder!!!";
            break;

            case 20:
            player2 = 41;
            alert2 = "YAY Player2 climbed a ladder!!!";
            break;

            case 8:
            player2 = 28;
            alert2 = "YAY Player2 climbed a ladder!!!";
            break;

            case 4:
            player2 = 36;
            alert2 = "YAY Player2 climbed a ladder!!!";
            break;

            default:
            alert2 = "";
        }

        squares[player1] = 200; //player1's position shall be represented by the integer 200
        squares[player2] = 300; //player2's position shall be represented by the inteer 300

        if ( input1 != 0)
        {
            cout<<"Player1 rolled "<<roll1<<" Player2 rolled "<<roll2<<endl;
            cout<<"Player1 Position: "<<player1<<" Player2 Position: "<<player2<<endl;
            cout <<alert1<<endl;
            cout <<alert2<<endl;

            board();
            cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n"; //so the player knows which is a snake and that which is ladder
        }

        progress = check_progress();

    }
    while ( progress == 0 && input1 != 0 );

    if ( squares[100] == 200)
    {
        cout << "||Player1 Win!||"<<endl;
    }
    else if ( squares[100] == 300)
    {
        cout << "||Player2 Wins!"<<endl;
    }
    else
    {
        cout << "Quit!";
    }

    cin.get();
    cin.ignore();
}

void board()//define the board drawing mechanism!
{
    cout << "----------------------------------------------------------------------------"<<endl<<endl;
         cout << squares[100]<<"\t"<<squares[99]<<"\t"<<squares[98]<<"\t"<<squares[97]<<"\t"<<squares[96]<<"\t"
         <<squares[95]<<"\t"<<squares[94]<<"\t"<<squares[93]<<"\t"<<squares[92]<<"\t"<<squares[91]<<endl<<endl;

         cout << squares[81]<<"\t"<<squares[82]<<"\t"<<squares[83]<<"\t"<<squares[84]<<"\t"<<squares[85]<<"\t"
         <<squares[86]<<"\t"<<squares[87]<<"\t"<<squares[88]<<"\t"<<squares[89]<<"\t"<<squares[90]<<endl<<endl;

         cout << squares[80]<<"\t"<<squares[79]<<"\t"<<squares[78]<<"\t"<<squares[77]<<"\t"<<squares[76]<<"\t"
         <<squares[75]<<"\t"<<squares[74]<<"\t"<<squares[73]<<"\t"<<squares[72]<<"\t"<<squares[71]<<endl<<endl;

         cout << squares[61]<<"\t"<<squares[62]<<"\t"<<squares[63]<<"\t"<<squares[64]<<"\t"<<squares[65]<<"\t"
         <<squares[66]<<"\t"<<squares[67]<<"\t"<<squares[68]<<"\t"<<squares[69]<<"\t"<<squares[70]<<endl<<endl;

         cout << squares[60]<<"\t"<<squares[59]<<"\t"<<squares[58]<<"\t"<<squares[57]<<"\t"<<squares[56]<<"\t"
         <<squares[55]<<"\t"<<squares[54]<<"\t"<<squares[53]<<"\t"<<squares[52]<<"\t"<<squares[51]<<endl<<endl;

         cout << squares[41]<<"\t"<<squares[42]<<"\t"<<squares[43]<<"\t"<<squares[44]<<"\t"<<squares[45]<<"\t"
         <<squares[46]<<"\t"<<squares[47]<<"\t"<<squares[48]<<"\t"<<squares[49]<<"\t"<<squares[50]<<endl<<endl;

         cout << squares[40]<<"\t"<<squares[39]<<"\t"<<squares[38]<<"\t"<<squares[37]<<"\t"<<squares[36]<<"\t"
         <<squares[35]<<"\t"<<squares[34]<<"\t"<<squares[33]<<"\t"<<squares[32]<<"\t"<<squares[31]<<endl<<endl;

         cout << squares[21]<<"\t"<<squares[22]<<"\t"<<squares[23]<<"\t"<<squares[24]<<"\t"<<squares[25]<<"\t"
         <<squares[26]<<"\t"<<squares[27]<<"\t"<<squares[28]<<"\t"<<squares[29]<<"\t"<<squares[30]<<endl<<endl;

         cout << squares[20]<<"\t"<<squares[19]<<"\t"<<squares[18]<<"\t"<<squares[17]<<"\t"<<squares[16]<<"\t"
         <<squares[15]<<"\t"<<squares[14]<<"\t"<<squares[13]<<"\t"<<squares[12]<<"\t"<<squares[11]<<endl<<endl;

         cout << squares[1]<<"\t"<<squares[2]<<"\t"<<squares[3]<<"\t"<<squares[4]<<"\t"<<squares[5]<<"\t"
         <<squares[6]<<"\t"<<squares[7]<<"\t"<<squares[8]<<"\t"<<squares[9]<<"\t"<<squares[10]<<endl<<endl;
    cout << "----------------------------------------------------------------------------"<<endl;
}

int roll_dice()//define the dice rolling mechanism
{
    return rand() % (7-1) + 1;//can only roll 1 - 6
}

int check_progress()//define the progress checking mechanism
{
    if ( squares[100] == 200 || squares[100] == 300)
    {
        return 1;//game has ended... win! someone has
    }
    else
    {
        return 0;//game is still on, win no one has...
    }
}

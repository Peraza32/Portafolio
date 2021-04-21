/*Programa que simula la carrea de la Libere y la tortuga*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int MoveTurtle(int * const, int );
int MoveHare(int * const, int );
int Tick();


int main()
{

    int turtle = 1, hare = 1;
    int cont = 0, tp;

    srand(time(0));

    cout << "BANG!" <<endl;
    cout << "And they are off!" <<endl;
    cout << "T: " <<turtle << " H: " <<hare <<endl;

    do
   {

      
        tp =( 1 + rand() % 10);

        MoveTurtle(&turtle, tp);
        MoveHare(&hare, tp);

        if( turtle == hare)
            cout << "Ouch! " << "T: " <<turtle << " H: " <<hare <<endl;
        else
            cout << "T: " <<turtle << " H: " <<hare <<endl;
            
        cont++;
   }while(turtle < 70 && hare < 70);

   if(turtle >= 70 && hare < 70)
        cout << "Turtle WINS";
    else if( hare >= 70 && turtle < 70)
        cout << "Hare wins";
    else if( hare >= 70 && turtle >= 70)
        cout << "It's a tie";

    return 0;
}

int MoveTurtle(int * const t, int probability)
{
    if( probability >= 1 && probability <= 5 )
         *t += 3;  //Fast Plod, 3 spaces Forward
    else if(probability >= 6 && probability <= 7)
    {
        *t -= 6;  //Slip, 6 spaces backwards
            if(*t < 1)
                *t = 1;
    }
    else if( probability  >= 8 && probability <= 10)
         *t +=  1; //Slow Plod, 1 space forward

    return *t;
}

int MoveHare(int * const h, int probability)
{
    if( probability >= 1 && probability <= 2)
         *h; //Sleep, Nothing happens
    else if( probability >= 3 && probability <= 4)
         *h += 9; //Big Hop, 9 spaces forward
    else if( probability == 5)
        {
            *h -= 12; //Big Slip, 12 spaces backwards
            if(*h < 1)
                *h = 1;
        }
    else if( probability >= 6 && probability <= 8)
        *h += 1; //Small Hop, 1 space forward
    else if ( probability >= 9  && probability <= 10)
       {
            *h -= 2; //Small slip, 2 spaces backwards
            if(*h < 1)
                *h = 1;
        } 

    return *h; 
}

int Tick() //Funcion que nos da el porcentaje a usar
{
    int t;
    srand(time(0));
    t =( 1 + rand() % 10); //Devolvemos el "porcentaje"
    return t;
}
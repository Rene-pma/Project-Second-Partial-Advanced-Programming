#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <conio.h>
#include <map> 
#include <set>
#include <pthread.h>
#include "Quiz.h"

using namespace std; 

int main()
{
    Quiz quiz;
    int sel; 
   
   SetConsoleOutputCP(CP_UTF8); 

   cout<<endl; 
   printf("╔═╗╔═╗    ╔═══╗\n║║╚╝║║    ║╔═╗║\n║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n║║║║║║║ ║║║║ ║║║║╠╬══║║\n║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n     ╔═╝║    ╚╝\n     ╚══╝"); 

    cout<<endl; 
    cout<<"----- Menu -----"<<endl; 
    cout<<"Select a game option"<<endl; 
    cout<<endl; 
    cout<<"1 - Single player"<<endl; 
    cout<<"2 - play in pairs"<<endl; 
    cout<<"3 - Multiplayer"<<endl; 

        cin>>sel; 

        switch(sel)
        {
            case 1:
            quiz.juegoIndividual();
            return main();
            break; 

            case 2:  
            quiz.juegoEnParejas();
            return main();  
            break;

            case 3:
            {
                cout<<"Enter the number of players :"<<endl; 
                int n;
                cin>>n; 
                quiz.juegoMultijugador(n);
                return main();  
            }
            break; 

            default: 
            cout<<"Invalid number - Enter a number between 1 and 3"<<endl; 
            break; 
        }
    }
    
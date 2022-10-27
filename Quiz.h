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

using namespace std; 

string gquest; 
bool ciclo = true; 

class Quiz
{
    private:
        string nombre, user, tema, date, quest, a, b, c, d; 
        string nombre1, nombre2, user1, user2, ganador;  

        char respuesta, correcta, respuesta1, respuesta2; 

        vector <string> preguntas, ra,rb, rc, rd; 
        vector <char> r_correctas;

        int num, pts, pts1, pts2, contP, n, mayor;  
        map <string,int> score, score1; 

        string *nombre3, *user3; 
        char *respuesta3; 
        int *pts3, *arr1, *arr2, *arr3, *arr4;

        int seg;
        bool ciclo = true; 
        pthread_t hilo;

    
    public: 
    
    Quiz(){} // Constructor 

    void Temporizador()
    {
        int seg = 5; 

        while(ciclo)
        {
            system("cls"); 
            cout<<"The game will start in...";
            cout<<seg<<endl; 
            Sleep(1000); 
            cout<<endl; 
            seg--; 
            if(seg == 0)
            {
                ciclo = false; 
            }
        }
        
        pthread_exit(NULL); 
    }

    static void* _Temporizador(void *This)
    {
        Quiz*cptr = (Quiz*)This;
        cptr -> Temporizador(); 
    }

    void juegoIndividual()
    {
        int num=1, pts=0, contP=0;  

        cout<<"Enter your name: "<<endl;
        cin.ignore(); 
        getline(cin,nombre); 
        cout<<"Enter a game user: "<<endl; 
        getline(cin,user);  
        cout<<"Enter the subject of the questions: "<<endl; 
        getline(cin,tema); 
        cout<<"Enter the date: "<<endl; 
        cin.ignore();
        getline(cin,date); 
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 

        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 

        cout<<endl; 
        cout<<"                  ----- Welcome to My Quiz -----"<<endl; 
        cout<<"Enter the questions and enter -1 when you no longer want to continue entering"<<endl; 
        cout<<endl; 

        while(true)
        {
            cout<<"Enter question no."<<num<<endl; 
            getline(cin,quest); 
            if(quest == "-1"){system("cls");break;}
            cout<<"Enter option a"<<endl; 
            getline(cin,a); 
            cout<<"Enter option b"<<endl; 
            getline(cin,b); 
            cout<<"Enter option c"<<endl; 
            getline(cin,c); 
            cout<<"Enter option d"<<endl; 
            getline(cin,d);  
            cout<<"What is the correct answer option? (a/b/c/d)"<<endl; 
            contP++; 
            cin>>correcta; 
            num++; 
            cin.ignore(); 
            system("cls");
            preguntas.push_back(quest); 
            ra.push_back(a); 
            rb.push_back(b); 
            rc.push_back(c); 
            rd.push_back(d); 
            r_correctas.push_back(correcta); 

        }

        arr1 = new int[contP]; 
        arr2 = new int[contP]; 
        arr3 = new int[contP]; 
        arr4 = new int[contP]; 

        pthread_create(&hilo, NULL, _Temporizador, this); 
        pthread_join(hilo, (NULL));  
        system("cls"); 

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {   
            //pthread_create(&hilo, NULL, _Temporizador, this); 
            //pthread_join(hilo, (void**)&i); 
            //gquest = to_string(i+1) + ".- " + preguntas[i] + "\n" + "a) " + ra[i] + "\n" + "b) " + rb[i] + "\n" + "c) " + rc[i] + "\n" + "d) " + rd[i] + "\n";  

            cout<<i+1<<".- "<<preguntas[i]<<endl; 
            
            cout<<"a) "<<ra[i]<<endl; 
            cout<<"b) "<<rb[i]<<endl; 
            cout<<"c) "<<rc[i]<<endl; 
            cout<<"d) "<<rd[i]<<endl; 
            cout<<endl; 
            
            try
            {
                cout<<"Answer: "; 
                cin>>respuesta; 
                    if(respuesta != 'a' && respuesta != 'b' && respuesta != 'c' && respuesta != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
            }
            catch(char const* e)
            {
                cout<<e<<endl; 
            }


            if(respuesta == r_correctas[i]){
                arr1[i] = 1;  
                pts = pts + 300; 
                cout<<"Correct answer"<<endl; 
            }
            else{
                arr1[i] = 0; 
                cout<<"Incorrect amswer X"<<endl; 
            }
            cout<<endl;
        } 
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0)
            {
                cout<<"----- Second round of questions -----"<<endl;
                cout<<endl; 
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try
                {
                    cout<<"Answer: "; 
                    cin>>respuesta; 
                    if(respuesta != 'a' && respuesta != 'b' && respuesta != 'c' && respuesta != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e)
                {
                    cout<<e<<endl; 
                }

                if(respuesta == r_correctas[i]){
                arr2[i] = 1; 
                pts = pts + 150; 
                cout<<"Respuesta Correcta "<<endl; 
                }
                else{
                arr2[i] = 0; 
                cout<<"Respuesta Incorrecta X"<<endl; 
                }
            cout<<endl;
            }  
        }
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0 && arr2[i] == 0)
            { 
                cout<<"----- Tercera ronda de preguntas -----"<<endl;
                cout<<endl;
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try
                {
                    cout<<"Answer: "; 
                    cin>>respuesta; 
                    if(respuesta != 'a' && respuesta != 'b' && respuesta != 'c' && respuesta != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e)
                {
                    cout<<e<<endl; 
                }

                if(respuesta == r_correctas[i]){
                arr3[i] = 1;  
                pts = pts + 30; 
                cout<<"Respuesta Correcta"<<endl; 
                }
                else{
                arr3[i] = 0; 
                cout<<"Respuesta Incorrecta X"<<endl; 
                }
            cout<<endl;
            }  
        }
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0)
            {
                cout<<"----- Cuarta ronda de preguntas -----"<<endl;  
                cout<<endl; 
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try
                {
                    cout<<"Answer: "; 
                    cin>>respuesta; 
                    if(respuesta != 'a' && respuesta != 'b' && respuesta != 'c' && respuesta != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e)
                {
                    cout<<e<<endl; 
                }

                if(respuesta == r_correctas[i]){
                arr4[i] = 1; 
                pts = pts - 20; 
                cout<<"Respuesta Correcta"<<endl; 
                }
                else{
                arr4[i] = 0; 
                pts = pts - 20; 
                cout<<"Respuesta Incorrecta X"<<endl; 
                }
            cout<<endl;
            }  
        }
                for(int i=0; i<preguntas.size(); i++)
                {
                    while (arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0 && arr4[i] == 0)
                    {
                        cout<<i+1<<".- "<<preguntas[i]<<endl; 

                            cout<<"a) "<<ra[i]<<endl; 
                            cout<<"b) "<<rb[i]<<endl; 
                            cout<<"c) "<<rc[i]<<endl; 
                            cout<<"d) "<<rd[i]<<endl; 
                            cout<<endl; 
                            
                            try
                            {
                                cout<<"Respuesta: "; 
                                cin>>respuesta; 
                                    if(respuesta != 'a' && respuesta != 'b' && respuesta != 'c' && respuesta != 'd')
                                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                            }
                            catch(char const* e)
                            {
                                cout<<e<<endl; 
                            }

                            if(respuesta == r_correctas[i]){
                            arr4[i] = 1;  
                            pts = pts - 20; 
                            cout<<"Respuesta Correcta"<<endl; 
                            }
                            else{
                            arr4[i] = 0; 
                            pts = pts - 20; 
                            cout<<"Respuesta Incorrecta X"<<endl; 
                            }    
                    }  
                }   

        SetConsoleOutputCP(CP_UTF8); 
        printf("          ╔╗╔╗╔╗            ╔╦╗\n          ║║║║║║            ║║║\n          ║║║║║╠╦═╗╔═╗╔══╦═╗║║║\n          ║╚╝╚╝╠╣╔╗╣╔╗╣║═╣╔╝╚╩╝\n          ╚╗╔╗╔╣║║║║║║║║═╣║ ╔╦╗\n           ╚╝╚╝╚╩╝╚╩╝╚╩══╩╝ ╚╩╝");
        cout<<endl; 

        score.insert(make_pair(nombre,pts)); 
        for(map<string,int>::iterator it = score.begin(); it != score.end(); it++){
            pair<string,int> score = *it;
            cout<<"      Total de puntos de "<<score.first <<" : "<< score.second <<endl;
            cout<<endl; 
        } 
        

        ofstream archivo; 
        
        archivo.open("My Quiz.txt",ios::app);
        
        if(archivo.fail()){
            cout<<"El archivo no se puede abrir."; 
        }

        archivo<<"                            ╔═╗╔═╗    ╔═══╗\n                            ║║╚╝║║    ║╔═╗║\n                            ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                            ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                            ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                            ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                                 ╔═╝║    ╚╝\n                                 ╚══╝"<<endl; 
        archivo<<endl; 
        archivo<<"Nombre: "<<nombre; 
        archivo<<"                              "<<date<<endl; 
        archivo<<endl; 
        archivo<<"Tema: "<<tema<<endl; 
        archivo<<endl; 
        for(int i=0; i<preguntas.size(); i++)
        {
            archivo<<i+1<<".- "<<preguntas[i]<<endl; 

            archivo<<"a) "<<ra[i]<<endl; 
            archivo<<"b) "<<rb[i]<<endl; 
            archivo<<"c) "<<rc[i]<<endl; 
            archivo<<"d) "<<rd[i]<<endl; 
            archivo<<endl; 
            archivo<<"Respuesta correcta: "<<endl; 
            archivo<<r_correctas[i]<<endl; 
            archivo<<endl; 
        }
    }


    void juegoEnParejas()
    {
        int num=1, contP=0;
        int pts1=0, pts2=0;  

        cout<<"Enter the name of player 1: "<<endl;
        cin.ignore(); 
        getline(cin,nombre1); 
        cout<<"Enter player 1 username: " <<endl; 
        getline(cin,user1); 
        cout<<"Enter the name of player 2: "<<endl; 
        getline(cin,nombre2); 
        cout<<"Enter player 2 username: "<<endl; 
        getline(cin,user2); 
        cout<<"Enter the subject of the questions: "<<endl; 
        getline(cin,tema); 
        cout<<"Enter the date: "<<endl; 
        getline(cin,date); 
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 

        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 


        cout<<endl; 
        cout<<"                  ----- Welcome to My Quiz -----"<<endl; 
        cout<<"Enter the questions and enter -1 when you no longer want to continue entering"<<endl; 
        cout<<endl; 

        while(true)
        {
            cout<<"Enter question no."<<num<<endl; 
            getline(cin,quest); 
            if(quest == "-1"){system("cls");break;}
            cout<<"Enter option a"<<endl; 
            getline(cin,a); 
            cout<<"Enter option b"<<endl; 
            getline(cin,b); 
            cout<<"Enter option c"<<endl; 
            getline(cin,c); 
            cout<<"Enter option d"<<endl; 
            getline(cin,d);  
            cout<<"What is the correct answer option? (a/b/c/d)"<<endl; 
            contP++; 
            cin>>correcta; 
            num++; 
            cin.ignore(); 
            system("cls");
            preguntas.push_back(quest); 
            ra.push_back(a); 
            rb.push_back(b); 
            rc.push_back(c); 
            rd.push_back(d); 
            r_correctas.push_back(correcta); 
        }

        arr1 = new int[contP]; 
        arr2 = new int[contP]; 
        arr3 = new int[contP]; 
        arr4 = new int[contP]; 

        pthread_create(&hilo, NULL, _Temporizador, this); 
        pthread_join(hilo, (NULL));  

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {
            cout<<i+1<<".- "<<preguntas[i]<<endl; 

            cout<<"a) "<<ra[i]<<endl; 
            cout<<"b) "<<rb[i]<<endl; 
            cout<<"c) "<<rc[i]<<endl; 
            cout<<"d) "<<rd[i]<<endl; 
            cout<<endl; 

            try{
                cout<<"Answer 1: "; 
                cin>>respuesta1;
                if(respuesta1 != 'a' && respuesta1 != 'b' && respuesta1 != 'c' && respuesta1 != 'd')
                    throw "Error - Please enter one of the possible answers - a,b,c,d";
            }
            catch (char const* e){
                cout<<e<<endl; 
                cout<<endl; 
            }

            try{
                cout<<"Answer 2:"; 
                cin>>respuesta2;
                if(respuesta2 != 'a' && respuesta2 != 'b' && respuesta2 != 'c' && respuesta2 != 'd')
                    throw "Error - Please enter one of the possible answers - a,b,c,d";
            }
            catch (char const* e){
                cout<<e<<endl; 
                cout<<endl; 
            }

            if(respuesta1 == r_correctas[i]){
                arr1[i] = 1;  
                pts1 = pts1 + 300; 
                cout<<"Answer 1 correct"<<endl; 
            }
            else{
                arr1[i] = 0; 
                cout<<"Answer 1 incorrect X"<<endl; 
            }

            if(respuesta2 == r_correctas[i]){
                arr1[i] = 1;  
                pts2 = pts2 + 300; 
                cout<<"Answer 2 correct"<<endl; 
            }
            else{
                arr1[i] = 0; 
                cout<<"Answer 2 incorrect X"<<endl; 
            }
            cout<<endl;
        }
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 
        
        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0)
            { 
                cout<<"----- Second round of questions -----"<<endl;
                cout<<endl;
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try{
                    cout<<"Answer 1: "; 
                    cin>>respuesta1;
                    if(respuesta1 != 'a' && respuesta1 != 'b' && respuesta1 != 'c' && respuesta1 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                try{
                    cout<<"Answer 2: "; 
                    cin>>respuesta2;
                    if(respuesta2 != 'a' && respuesta2 != 'b' && respuesta2 != 'c' && respuesta2 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                if(respuesta1 == r_correctas[i]){
                arr2[i] = 1; 
                pts1 = pts1 + 150; 
                cout<<"Answer 1 correct"<<endl; 
                }
                else{
                arr2[i] = 0; 
                cout<<"Answer 1 incorrect X"<<endl; 
                }

                if(respuesta2 == r_correctas[i]){
                arr2[i] = 1; 
                pts2 = pts2 + 150; 
                cout<<"Answer 2 correct"<<endl; 
                }
                else{
                arr2[i] = 0; 
                cout<<"Answer 2 incorrect X"<<endl; 
                }
            cout<<endl;
            }  
        }
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 
    
        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0 && arr2[i] == 0)
            { 
                cout<<"----- Third round of questions -----"<<endl;
                cout<<endl;
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try{
                    cout<<"Amswer 1: "; 
                    cin>>respuesta1;
                    if(respuesta1 != 'a' && respuesta1 != 'b' && respuesta1 != 'c' && respuesta1 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                try{
                    cout<<"Answer 2: "; 
                    cin>>respuesta2;
                    if(respuesta2 != 'a' && respuesta2 != 'b' && respuesta2 != 'c' && respuesta2 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                if(respuesta1 == r_correctas[i]){
                arr3[i] = 1;  
                pts1 = pts1 + 30; 
                cout<<"Answer 1 correct"<<endl; 
                }
                else{
                arr3[i] = 0; 
                cout<<"Answer 1 incorrect X"<<endl; 
                }

                if(respuesta2 == r_correctas[i]){
                arr2[i] = 1; 
                pts2 = pts2 + 150; 
                cout<<"Answer 2 correct"<<endl; 
                }
                else{
                arr2[i] = 0; 
                cout<<"Answer 2 incorrect X"<<endl; 
                }
            cout<<endl;
            }  
        }
        system("cls");

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {    
            if(arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0)
            {
                cout<<"----- Fourth round of questions -----"<<endl;  
                cout<<endl; 
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
                
                try{
                    cout<<"Answer 1: "; 
                    cin>>respuesta1;
                    if(respuesta1 != 'a' && respuesta1 != 'b' && respuesta1 != 'c' && respuesta1 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                try{
                    cout<<"Answwer 2: "; 
                    cin>>respuesta2;
                    if(respuesta2 != 'a' && respuesta2 != 'b' && respuesta2 != 'c' && respuesta2 != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d";
                }
                catch (char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }

                if(respuesta1 == r_correctas[i]){
                arr4[i] = 1; 
                pts1 = pts1 - 20; 
                cout<<"Answer 1 correct"<<endl; 
                }
                else{
                arr4[i] = 0; 
                pts1 = pts1 - 20; 
                cout<<"Answer 1 incorrect X"<<endl; 
                }

                if(respuesta2 == r_correctas[i]){
                arr2[i] = 1; 
                pts2 = pts2 + 150; 
                cout<<"Answer 2 correct"<<endl; 
                }
                else{
                arr2[i] = 0; 
                cout<<"Answer 2 incorrect X"<<endl; 
                }
                cout<<endl;
            }  
        }
                for(int i=0; i<preguntas.size(); i++)
                {
                    while (arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0 && arr4[i] == 0)
                    {
                        cout<<i+1<<".- "<<preguntas[i]<<endl; 

                            cout<<"a) "<<ra[i]<<endl; 
                            cout<<"b) "<<rb[i]<<endl; 
                            cout<<"c) "<<rc[i]<<endl; 
                            cout<<"d) "<<rd[i]<<endl; 
                            cout<<endl; 
                            
                            try{
                                cout<<"Answer 1: "; 
                                cin>>respuesta1;
                                if(respuesta1 != 'a' && respuesta1 != 'b' && respuesta1 != 'c' && respuesta1 != 'd')
                                    throw "Error - Please enter one of the possible answers - a,b,c,d";
                            }
                            catch (char const* e){
                                cout<<e<<endl; 
                                cout<<endl; 
                            }

                            try{
                                cout<<"Answer 2: "; 
                                cin>>respuesta2;
                                if(respuesta2 != 'a' && respuesta2 != 'b' && respuesta2 != 'c' && respuesta2 != 'd')
                                    throw "Error - Please enter one of the possible answers - a,b,c,d";
                            }
                            catch (char const* e){
                                cout<<e<<endl; 
                                cout<<endl; 
                            }

                            if(respuesta1 == r_correctas[i]){
                            arr4[i] = 1;  
                            pts1 = pts1 - 20; 
                            cout<<"Answer 1 correct"<<endl; 
                            }
                            else{
                            arr4[i] = 0; 
                            pts1 = pts1 - 20; 
                            cout<<"Answer 1 incorrect X"<<endl; 
                            } 

                            if(respuesta2 == r_correctas[i]){
                                arr4[i] = 1; 
                                pts2 = pts2 - 20; 
                                cout<<"Answer 2 correct"<<endl; 
                            }
                            else{
                                arr4[i] = 0; 
                                pts2 = pts2 - 20; 
                                cout<<"Amswer 2 incorrect"<<endl; 
                            }
                            
                            
                    }  
                }   

        cout<<endl; 
        cout<<"    ----- Total points: -----"<<endl; 
        cout<<endl; 

        score.insert(make_pair(user1,pts1)); 
        for(map<string,int>::iterator it = score.begin(); it != score.end(); it++){
            pair<string,int> score = *it;
            cout<<"Total points of"<<score.first <<" : "<< score.second <<endl;
        } 

        score1.insert(make_pair(user2,pts2)); 
        for(map<string,int>::iterator it = score1.begin(); it != score1.end(); it++){
            pair<string,int> score1 = *it;
            cout<<"Total points of"<<score1.first <<" : "<< score1.second <<endl;
            cout<<endl; 
        } 
    

        SetConsoleOutputCP(CP_UTF8); 
        printf("          ╔╗╔╗╔╗            ╔╦╗\n          ║║║║║║            ║║║\n          ║║║║║╠╦═╗╔═╗╔══╦═╗║║║\n          ║╚╝╚╝╠╣╔╗╣╔╗╣║═╣╔╝╚╩╝\n          ╚╗╔╗╔╣║║║║║║║║═╣║ ╔╦╗\n           ╚╝╚╝╚╩╝╚╩╝╚╩══╩╝ ╚╩╝");
        cout<<endl; 

        if (pts1 > pts2)
        {
            cout<<endl; 
            cout<<"Game winner: "<<endl; 
            cout<<nombre1<<" "<<"@"<<user1<<endl; 
            cout<<endl; 
        }else{
            cout<<endl; 
            cout<<"Game winner :"<<endl; 
            cout<<nombre2<<" "<<"@"<<user2<<endl;
            cout<<endl; 
        }


        ofstream archivo; 
        
        archivo.open("My Quiz.txt",ios::app);
        
        if(archivo.fail()){
            cout<<"The file cannot be opened."; 
        }

        archivo<<"                            ╔═╗╔═╗    ╔═══╗\n                            ║║╚╝║║    ║╔═╗║\n                            ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                            ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                            ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                            ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                                 ╔═╝║    ╚╝\n                                 ╚══╝"<<endl; 
        archivo<<endl; 
        archivo<<"Name: "<<nombre1<<endl; 
        archivo<<"Name: "<<nombre2<<endl; 
        archivo<<"                              "<<date<<endl; 
        archivo<<endl; 
        archivo<<"Topic: "<<tema<<endl; 
        archivo<<endl; 
        for(int i=0; i<preguntas.size(); i++)
        {
            archivo<<i+1<<".- "<<preguntas[i]<<endl; 

            archivo<<"a) "<<ra[i]<<endl; 
            archivo<<"b) "<<rb[i]<<endl; 
            archivo<<"c) "<<rc[i]<<endl; 
            archivo<<"d) "<<rd[i]<<endl; 
            archivo<<endl; 
            archivo<<"Correct Answer: "<<endl; 
            archivo<<r_correctas[i]<<endl; 
            archivo<<endl; 
        }
    }  

    void juegoMultijugador(int p)
    {
        nombre3 = new string[p]; 
        user3 = new string[p];
        respuesta3 = new char[p]; 
        pts3 = new int[p]; 

        int num=1, mayor=0; 
    
        for(int i=0; i<p; i++){
            cout<<"Enter the player's name "<<i+1<<": "<<endl;
            cin.ignore();  
            getline(cin,nombre3[i]); 
            cout<<"Enter the player's username "<<i+1<<": "<<endl; 
            cin.ignore(); 
            getline(cin,user3[i]); 
        }
        cout<<"Enter the topic of the questions:"<<endl; 
        cin.ignore(); 
        getline(cin,tema); 
        cout<<"Enter the date: "<<endl; 
        getline(cin,date); 

        system("cls");

        SetConsoleOutputCP(CP_UTF8); 

        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 

        cout<<endl; 
        cout<<"                  ----- Welcome to My Quiz -----"<<endl; 
        cout<<"Enter the questions and enter -1 when you no longer want to continue entering"<<endl; 
        cout<<endl; 

        while(true)
        {
            cout<<"Enter question no."<<num<<endl; 
            getline(cin,quest); 
            if(quest == "-1"){system("cls");break;}
            cout<<"Enter option a"<<endl; 
            getline(cin,a); 
            cout<<"Emter option b"<<endl; 
            getline(cin,b); 
            cout<<"Enter option c"<<endl; 
            getline(cin,c); 
            cout<<"Enetr option d"<<endl; 
            getline(cin,d);  
            cout<<"What is the correct answer option? (a/b/c/d)"<<endl; 
            contP++; 
            cin>>correcta; 
            num++; 
            cin.ignore(); 
            system("cls");
            preguntas.push_back(quest); 
            ra.push_back(a); 
            rb.push_back(b); 
            rc.push_back(c); 
            rd.push_back(d); 
            r_correctas.push_back(correcta); 
        }

        arr1 = new int[contP]; 
        arr2 = new int[contP]; 
        arr3 = new int[contP]; 
        arr4 = new int[contP]; 

        pthread_create(&hilo, NULL, _Temporizador, this); 
        pthread_join(hilo, (NULL));  

        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 


        for(int i=0; i<preguntas.size(); i++)
        {
            cout<<i+1<<".- "<<preguntas[i]<<endl; 

            cout<<"a) "<<ra[i]<<endl; 
            cout<<"b) "<<rb[i]<<endl; 
            cout<<"c) "<<rc[i]<<endl; 
            cout<<"d) "<<rd[i]<<endl; 
            cout<<endl; 
            
            try{
                for(int i=0; i<p; i++){
                    cout<<"Answer "<<i+1<<":"; 
                    cin>>respuesta3[i]; 
                    pts3[i] = 0; 
                }
                if(respuesta3[i] != 'a' && respuesta3[i] != 'b' && respuesta3[i] != 'c' && respuesta3[i] != 'd')
                    throw "Error - Please enter one of the possible answers - a,b,c,d"; 
            }
            catch(char const* e){
                cout<<e<<endl; 
                cout<<endl; 
            }
        
            for(int i=0; i<preguntas.size(); i++)
            {
                for(int j=0; j<p; j++)
                {
                    if(respuesta3[j] == r_correctas[i]){
                        arr1[i] = 1; 
                        pts3[j] = pts3[j] + 300; 
                        cout<<"Answer "<<j+1<<" Correct"<<endl;
                    } 
                    else{
                        arr1[i] = 0; 
                        cout<<"Incorrect Answer X"<<endl; 
                    }
                }
            }
        }
                
        cout<<endl;
        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {
            if(arr1[i] == 0)
            { 
                cout<<"----- Second round of questions -----"<<endl;
                cout<<endl;
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
    
                try{
                    for(int i=0; i<p; i++){
                        cout<<"Answer "<<i+1<<":"; 
                        cin>>respuesta3[i]; 
                    }
                    if(respuesta3[i] != 'a' && respuesta3[i] != 'b' && respuesta3[i] != 'c' && respuesta3[i] != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }
               
                for(int i=0; i<preguntas.size(); i++)
                {
                    for(int j=0; j<p; j++)
                    {
                        if(respuesta3[j] == r_correctas[i]){
                            arr2[i] = 1; 
                            pts3[j] = pts3[j] + 300; 
                            cout<<"Answer "<<j+1<<" Correct"<<endl;
                        } 
                        else{
                            arr2[i] = 0; 
                            cout<<"Incorrect Answer X"<<endl; 
                        }
                    }
                }
            }
        }
               
        cout<<endl; 
        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {
            if(arr1[i] == 0 && arr2[i] == 0)
            {
                cout<<"----- Third round of questions -----"<<endl;
                cout<<endl; 
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
    
                try{
                    for(int i=0; i<p; i++){
                        cout<<"Answer "<<i+1<<":"; 
                        cin>>respuesta3[i]; 
                    }
                    if(respuesta3[i] != 'a' && respuesta3[i] != 'b' && respuesta3[i] != 'c' && respuesta3[i] != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }
               
                for(int i=0; i<preguntas.size(); i++)
                {
                    for(int j=0; j<p; j++)
                    {
                        if(respuesta3[j] == r_correctas[i]){
                            arr3[i] = 1; 
                            pts3[j] = pts3[j] + 300; 
                            cout<<"Answer "<<j+1<<" Correct"<<endl;
                        } 
                        else{
                            arr3[i] = 0; 
                            cout<<"Incorrect Answer X"<<endl; 
                        }
                    }
                }
            }
        }

        cout<<endl; 
        SetConsoleOutputCP(CP_UTF8); 
        printf("                       ╔═╗╔═╗    ╔═══╗\n                       ║║╚╝║║    ║╔═╗║\n                       ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                       ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                       ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                       ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                            ╔═╝║    ╚╝\n                            ╚══╝"); 
        cout<<endl; 

        for(int i=0; i<preguntas.size(); i++)
        {
            if(arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0)
            {
                cout<<"----- Fourth round of questions -----"<<endl;
                cout<<endl; 
                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                cout<<"a) "<<ra[i]<<endl; 
                cout<<"b) "<<rb[i]<<endl; 
                cout<<"c) "<<rc[i]<<endl; 
                cout<<"d) "<<rd[i]<<endl; 
                cout<<endl; 
    
                try{
                    for(int i=0; i<p; i++){
                        cout<<"Answwer "<<i+1<<":"; 
                        cin>>respuesta3[i]; 
                    }
                    if(respuesta3[i] != 'a' && respuesta3[i] != 'b' && respuesta3[i] != 'c' && respuesta3[i] != 'd')
                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                }
                catch(char const* e){
                    cout<<e<<endl; 
                    cout<<endl; 
                }
               
                for(int i=0; i<preguntas.size(); i++)
                {
                    for(int j=0; j<p; j++)
                    {
                        if(respuesta3[j] == r_correctas[i]){
                            arr4[i] = 1; 
                            pts3[j] = pts3[j] + 300; 
                            cout<<"Answer "<<j+1<<" Correct"<<endl;
                        } 
                        else{
                            arr4[i] = 0; 
                            cout<<"Incorrect Answer X"<<endl; 
                        }
                    }
                }
            }
        }

                        for(int i=0; i<preguntas.size(); i++)
                        {
                            while(arr1[i] == 0 && arr2[i] == 0 && arr3[i] == 0 && arr4[i] == 0)
                            {
                                cout<<endl; 
                                cout<<i+1<<".- "<<preguntas[i]<<endl; 

                                cout<<"a) "<<ra[i]<<endl; 
                                cout<<"b) "<<rb[i]<<endl; 
                                cout<<"c) "<<rc[i]<<endl; 
                                cout<<"d) "<<rd[i]<<endl; 
                                cout<<endl; 
                    
                                try{
                                    for(int i=0; i<p; i++){
                                        cout<<"Answer "<<i+1<<":"; 
                                        cin>>respuesta3[i]; 
                                    }
                                    if(respuesta3[i] != 'a' && respuesta3[i] != 'b' && respuesta3[i] != 'c' && respuesta3[i] != 'd')
                                        throw "Error - Please enter one of the possible answers - a,b,c,d"; 
                                }
                                catch(char const* e){
                                    cout<<e<<endl; 
                                    cout<<endl; 
                                }
                            
                                for(int i=0; i<preguntas.size(); i++)
                                {
                                    for(int j=0; j<p; j++)
                                    {
                                        if(respuesta3[j] == r_correctas[i]){
                                            arr4[i] = 1; 
                                            pts3[j] = pts3[j] - 20; 
                                            cout<<"Answer "<<j+1<<" Correct"<<endl;
                                        } 
                                        else{
                                            arr4[i] = 0; 
                                            pts3[j] = pts3[j] - 20;
                                            cout<<"Incorrect Answer"<<endl; 
                                        }
                                    }
                                }
                            }
                        }

        /*for(int j=0; j<pts3[j]; j++)
        {
            if (pts3[j] > mayor) 
                mayor = pts3[j];
        }
        cout<<"El mayor es: "<<mayor;*/

        for(int i=0; i<p; i++){
            score.insert(make_pair(nombre3[i],pts3[i])); 
            for(map<string,int>::iterator it = score.begin(); it != score.end(); it++){
                pair<string,int> score = *it;
                cout<<"Total points of "<<score.first <<" : "<< score.second <<endl;
            }
        }
    
        ofstream archivo; 
        
        archivo.open("My Quiz.txt",ios::app);
        
        if(archivo.fail()){
            cout<<"The file cannot be opened."; 
        }

        archivo<<"                            ╔═╗╔═╗    ╔═══╗\n                            ║║╚╝║║    ║╔═╗║\n                            ║╔╗╔╗╠╗ ╔╗║║ ║╠╗╔╦╦═══╗\n                            ║║║║║║║ ║║║║ ║║║║╠╬══║║\n                            ║║║║║║╚═╝║║╚═╝║╚╝║║║══╣\n                            ╚╝╚╝╚╩═╗╔╝╚══╗╠══╩╩═══╝\n                                 ╔═╝║    ╚╝\n                                 ╚══╝"<<endl; 
        archivo<<endl; 
        for(int i=0; i<n; i++){
            archivo<<"Name "<<i+1<<": "<<nombre3[i]<<endl; 
        }
        archivo<<"                                                   Fecha: "<<date<<endl; 
        archivo<<endl; 
        archivo<<"Topic: "<<tema<<endl; 
        archivo<<endl; 
        for(int i=0; i<preguntas.size(); i++)
        {
            archivo<<i+1<<".- "<<preguntas[i]<<endl; 

            archivo<<"a) "<<ra[i]<<endl; 
            archivo<<"b) "<<rb[i]<<endl; 
            archivo<<"c) "<<rc[i]<<endl; 
            archivo<<"d) "<<rd[i]<<endl; 
            archivo<<endl; 
            archivo<<"Correct Answer: "<<endl; 
            archivo<<r_correctas[i]<<endl; 
            archivo<<endl; 
        }
    }  

};


#include<iostream>
#include<cstdlib> // ini buat nge random
#include<cmath> //ini library buat function fbs untuk pembatasan skor pemenangnya


using namespace std;

int rps()
{

    string words [] =
    {
        "batu",
        "gunting",
        "kertas",
    };
    
    
    string input = "ya";

    cout << "\t   ---Game batu, gunting, kertas udah dimulai nih, siapkan mentalmu!--- " << endl;
    cout << "\t ----pemain yang terlebih dahulu mendapat score 5, dialah pemenangnya----" << endl;
    
    int botScore = 0;
    int playerScore = 0;

    while(input == "ya")
    {
        srand((unsigned) time(0));
        int randomNumber = (rand() % 3);
        cout << "bot telah memilih, giliran anda memilih" << endl; 
        string com = words[randomNumber];
        string player = "" ;

        while (true)
        {
            cout << "> ";cin >> player ;
            if (player == "batu" || player == "gunting" || player == "kertas")
            {
                
                break;
            }
            cout << "-----------pilihan yang anda masukkan tidak tersedia------------" << endl;
            cout << "-----------silakan memilih batu, gunting atau kertas------------" << endl;
        }

    if (com == player)
        {
            cout << "------draw-------" << endl;
            cout << "karena pilihan anda sama dengan bot" << endl;
        }
        else
        {
            if (com == "batu" && player == "gunting")
            {
                cout << "anda kalah karena bot memilih batu" << endl;
                botScore = botScore + 1;
            }
            else
            {
                if (com == "gunting" && player == "kertas")
                {
                    cout << "anda kalah karena bot memilih gunting" << endl;
                    botScore = botScore + 1;
                }
                else
                {
                    if (com == "kertas" && player == "batu")
                    {
                        cout << "anda kalah karena bot memilih kertas" << endl;
                        botScore = botScore + 1;
                    }
                    else
                    {
                        if (player == "batu" || player == "gunting" || player == "kertas")
                        {
                            cout << "anda menang karena bot memilih " << com << endl;
                            playerScore = playerScore + 1;
                        }
                        
                    }
                }
            }
        }
    cout << "Skor Bot : " << botScore << " Skor Player : " << playerScore << endl;

    if (botScore >= 5 || playerScore >= 5 && fabs(botScore - playerScore) >= 2)
    {

        if (playerScore > botScore)
        {
            cout << "\t selamat anda memenangkan permainan!!" << endl;
            cout << "\t -------------------------------------"<< endl;
            
        }
        else
        {
            cout << "\t semnagat dan jangan putus asa, anda kalah" << endl;
            cout << "\t -------------------------------------"<< endl;
        }
       cout << "apakah anda ingin bermain lagi?" << endl;
       cin >> input; 
    }
      
    }


    return 0;
}
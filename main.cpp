#include <iostream>
#include "tictactoe.cpp"
#include "hangman.cpp"
#include "rps.cpp"
using namespace std;

int main()
{

    bool jalan = true;
    int aksi = 0;

    while (jalan)
    {
        cout << "===== Selamat datang di Game Hub! ======\n";
        cout << "1. Tic-Tac-Toe\n"
            << "2. Hangman\n"
            << "3. Batu Gunting Kertas\n";
        cout << "Select a game (-1 untuk keluar): ";
        cin >> aksi;
        while (aksi < 1 || aksi > 3)
        {
            if (aksi == -1) break;
            cout << "Input invalid. Mohon ulangi: ";
            cin.clear();
            cin.ignore();
            cin >> aksi;
        }
        cin.clear();
        cin.ignore();
        switch (aksi)
        {
            case 1:
                ticTacToe();
                break;
            case 2:
                hangman();
                break;
            case 3:
                rps();
                break;
            case -1:
                jalan = false;
                cout << "Program Selesai. Terimakasih telah menggunakan program ini!";
                break;
            default:
                cout << "Input invalid.";
                break;
        }
        cout << "\n";
    }

    return 0;
}
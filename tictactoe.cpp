#include <iostream>
#include <cstring>

using namespace std;

struct grid
{

    char arrGrid[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char displayGrid[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int giliran = 0;

    void updateGrid(char simbol, int index)
    {
        arrGrid[index] = simbol;
        displayGrid[index] = simbol;
        giliran++;
    }

    bool cekIsiKotak(int index)
    {
        if (arrGrid[index] == 'X' || arrGrid[index] == 'O')
            return true;
        return false;
    }

    bool cekKondisiSelesai()
    {
        // cek garis horizontal
        if (arrGrid[0] == arrGrid[1] && arrGrid[0] == arrGrid[2] && arrGrid[1] == arrGrid[2])
            return true;
        else if (arrGrid[3] == arrGrid[4] && arrGrid[3] == arrGrid[5] && arrGrid[4] == arrGrid[5])
            return true;
        else if (arrGrid[6] == arrGrid[7] && arrGrid[6] == arrGrid[8] && arrGrid[7] == arrGrid[8])
            return true;

        // cek garis vertikal
        else if (arrGrid[0] == arrGrid[3] && arrGrid[0] == arrGrid[6] && arrGrid[3] == arrGrid[6])
            return true;
        else if (arrGrid[1] == arrGrid[4] && arrGrid[1] == arrGrid[7] && arrGrid[4] == arrGrid[7])
            return true;
        else if (arrGrid[2] == arrGrid[5] && arrGrid[2] == arrGrid[8] && arrGrid[5] == arrGrid[8])
            return true;
        
        // cek garis diagonal
        else if (arrGrid[0] == arrGrid[4] && arrGrid[0] == arrGrid[8] && arrGrid[4] == arrGrid[8])
            return true;
        else if (arrGrid[2] == arrGrid[4] && arrGrid[2] == arrGrid[6] && arrGrid[4] == arrGrid[6])
            return true;
        return false;
    }

    bool cekGameSelesai(int pemain)
    {
        if (cekKondisiSelesai())
        {
            cout << "Pemain " << pemain << " menang!\n";
            return true;
        }
        if (giliran == 9)
        {
            cout << "Papan penuh!\n";
            return true;
        }
        return false;
    }

    void resetGrid()
    {
        for (int i = 0; i < 9; i++)
        {
            arrGrid[i] = (char) i + 1;
            displayGrid[i] = ' ';
        }
    }

    void print()
    
    {  
        cout << "\n";
        cout << " " << displayGrid[0] << " | " << displayGrid[1] << " | " << displayGrid[2] << endl;
        cout << "---+---+---\n";
        cout << " " << displayGrid[3] << " | " << displayGrid[4] << " | " << displayGrid[5] << endl;
        cout << "---+---+---\n";
        cout << " " << displayGrid[6] << " | " << displayGrid[7] << " | " << displayGrid[8] << endl;
        cout << "\n";
    }

    void printNilai()
    {
        cout << "\n";
        cout << " " << arrGrid[0] << " | " << arrGrid[1] << " | " << arrGrid[2] << endl;
        cout << "---+---+---\n";
        cout << " " << arrGrid[3] << " | " << arrGrid[4] << " | " << arrGrid[5] << endl;
        cout << "---+---+---\n";
        cout << " " << arrGrid[6] << " | " << arrGrid[7] << " | " << arrGrid[8] << endl;
        cout << "\n";
    }

    bool promptResetGame()
    {
        char input;
        cout << "Main lagi? (y/n): ";
        cin >> input;
        if (tolower(input) == 'y') return true;
        return false;
    }

    void resetGame()
    {
        resetGrid();
        giliran = 0;
        cin.clear();
        cin.ignore();
    }
};

int ambilInput(int pemainKe)
{
    string s;
    char c[1];
    getInput:
        cout << "Pemain " << pemainKe << " > ";
        getline(cin, s);
        if (s == "-1")
        {
            return -1;
        }
        if (s.length() > 1)
        {
            cout << "Input terlalu panjang. Mohon ulangi.\n";
            goto getInput;    
        }
        strcpy(c, s.c_str());
        if (int(c[0]) < 49 || int(c[0]) > 57)
        {
            cout << "Input harus sebuah digit yang bukan nol. Mohon ulangi.\n";
            goto getInput;
        }
    int n;
    n = c[0] - '0';
    return n;
}

int ticTacToe()
{
    grid Grid;
    int pilihan;

    cout << "Selamat datang di Tic-Tac-Toe!\n";
    Grid.printNilai();
    cout << "Game ini melibatkan 2 player.\n"
        << "- Cara main: masukkan angka dari kotak yang ingin diisi.\n"
        << "- Untuk menang, player harus membentuk garis (bisa lurus, bisa miring).\n"
        << "- Untuk KELUAR game, ketik -1.\n";
    

    /* while (true)
    {
        Grid.print();
        if (Grid.cekGameSelesai(2))
        {
            if (Grid.promptResetGame())
            {
                Grid.resetGame();
                continue;
            }
            cout << "Game selesai.";
            break;
        }
        
        pilihan = ambilInput(1);
        if (pilihan < 0) break;
        while (Grid.cekIsiKotak(pilihan - 1))
        {
            cout << "Kotak ke " << pilihan << " sudah terisi. Mohon pilih kotak kosong.\n";
            pilihan = ambilInput(1);
        }
        Grid.updateGrid('X', pilihan - 1);
        Grid.print();
        if (Grid.cekGameSelesai(1))
        {
            if (Grid.promptResetGame())
            {
                Grid.resetGame();
                continue;
            }
            cout << "Game selesai.\n";
            break;
        }

        pilihan = ambilInput(2);
        if (pilihan < 0) break;
        while (Grid.cekIsiKotak(pilihan - 1))
        {
            cout << "Kotak ke " << pilihan << " sudah terisi. Mohon pilih kotak kosong.\n";
            pilihan = ambilInput(1);
        }
        Grid.updateGrid('O', pilihan - 1);
    } */

    Grid.print();
    do {
        pilihan = ambilInput(1);
        if (pilihan < 0) break;
        while (Grid.cekIsiKotak(pilihan - 1))
        {
            cout << "Kotak ke " << pilihan << " sudah terisi. Mohon pilih kotak kosong.\n";
            pilihan = ambilInput(1);
        }
        Grid.updateGrid('X', pilihan - 1);
        Grid.print();
        if (Grid.cekGameSelesai(1))
        {
            if (Grid.promptResetGame())
            {
                Grid.resetGame();
                Grid.print();
                continue;
            }
            cout << "Game selesai.\n";
            break;
        }

        pilihan = ambilInput(2);
        if (pilihan < 0) break;
        while (Grid.cekIsiKotak(pilihan - 1))
        {
            cout << "Kotak ke " << pilihan << " sudah terisi. Mohon pilih kotak kosong.\n";
            pilihan = ambilInput(1);
        }
        Grid.updateGrid('O', pilihan - 1);
        Grid.print();
        if (Grid.cekGameSelesai(2))
        {
            if (Grid.promptResetGame())
            {
                Grid.resetGame();
                Grid.print();
            }
            cout << "Game selesai.";
            break;
        }
    } while (true);

    return 0;
}
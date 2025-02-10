#include <iostream>
#include <mmsystem.h>
#include <string>
#include <windows.h>
using namespace std;

#pragma comment(lib, "Winmm.lib")

int main(){
	cout << "Olá, Treinador!" << endl;
    cout << "Iniciando música de fundo..." << endl;
    
    PlaySound(TEXT("Pokemon music.wav"), NULL, SND_ASYNC | SND_FILENAME); // Insira o caminho do arquivo de áudio
    
	return 0;
}
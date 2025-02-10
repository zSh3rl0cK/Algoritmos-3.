#include <iostream>

using namespace std;

int main() {

    int h_inicial, h_final; // hora inicial e final
	int m_inicial, m_final; // minuto inicial e final
    int duracao_h; // duracao em horas

	// inserindo as horas e minutos
    cin >> h_inicial >> m_inicial >> h_final >> m_final;

    int duracao_min; // duracao em minutos
    int duracaot; // duracao total

	// horas e minutos iguais
    if (h_inicial == h_final && m_inicial == m_final) {
        cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)" << endl;
        return 0;
    }
	
	// calculando a duracao total em minutos
    duracaot = (h_final * 60 + m_final) - (h_inicial * 60 + m_inicial);

	// inicio em 1 dia e termino no outro
    if (duracaot < 0) {
        duracaot += 24 * 60;
    }

	// calculando a duracao em horas e minutos
    duracao_h = duracaot / 60;
    duracao_min = duracaot % 60;

    cout << "O JOGO DUROU " << duracao_h << " HORA(S) E " << duracao_min << " MINUTO(S)" << endl;

    return 0;
}

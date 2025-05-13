#include <iostream>
#include <string> //garantir que todos os compiladores leiam a string. Boas praticas

using namespace std;

const string PALAVRA_SECRETA = "MARCIO"; //var levada a escopo global parra valer em tds os escopos. Const para boas praticas

bool letraExiste(char chute);

int main(){
    cout << PALAVRA_SECRETA << endl;

    bool naoAcertou = true;
    bool naoEnforcou = true;

    while(naoAcertou && naoEnforcou){
        char chute;
        cout << "Chute uma letra: "<< endl;
        cin >> chute;

        if(letraExiste(chute)){
            cout << "Voce acertou. Seu chute esta na palavra." << endl;
        }
        else {
            cout << "Voce errou. Seu chute nao esta na palavra." << endl;
        }
    }
}
//como varrer uma string posicao por posicao
bool letraExiste(char chute){
    for (int posicao = 0; posicao < PALAVRA_SECRETA.size(); posicao++){ //palavraSecret.size() me retorna o tamanho da string em questao
        if(chute == PALAVRA_SECRETA[posicao]){ //posicao na string
            return true;
        }
    }
    return false;
}
#include <iostream>
#include <string> //garantir que todos os compiladores leiam a string. Boas praticas
#include <map> //biblioteca para dicionario
#include <vector> //para vetor dinamico

using namespace std;

const string PALAVRA_SECRETA = "MARCIO"; //var levada a escopo global parra valer em tds os escopos. Const para boas praticas
map<char, bool> chutou; //inplementacao do dicionario/vetor chutou
vector<char> chuteErrado; //vetor dinamico para guardar chutes errados

bool letraExiste(char chute);

int main(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;

    bool naoAcertou = true;
    bool naoEnforcou = true;

    while(naoAcertou && naoEnforcou){
        //printar os chutes errados (valores dentro do vetor dinamico)
        cout << "Chutes errados: ";
        for(char i : chuteErrado){
            cout << i << " ";
        }
        cout << endl;
        
        //verificar se o chute foi realizado com sucesso ou nao
        for (char posicao : PALAVRA_SECRETA){
            if(chutou[posicao]) {
                cout << posicao << " "; //se chutou certo
            }
            else {
                cout << "_ "; //se chutou errado
            }
        } cout << endl;

        char chute;
        cout << "Chute uma letra: "<< endl;
        cin >> chute;
        chutou[chute] = true; //quando o chute for verdadeiro retorno isso ao map 

        if(letraExiste(chute)){
            cout << "Voce acertou. Seu chute esta na palavra." << endl;
        }
        else {
            cout << "Voce errou. Seu chute nao esta na palavra." << endl;
            chuteErrado.push_back(chute); //pega o valor da var chute que foi desviado para o else e guarda no fim do vetorr dinamico
        }
        cout << endl;
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
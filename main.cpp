#include <iostream>
#include <string> //garantir que todos os compiladores leiam a string. Boas praticas
#include <map> //biblioteca para dicionario
#include <vector> //para vetor dinamico
#include <fstream> //ler arquivo externo/txt
#include <ctime> //semente
#include <cstdlib> //funcao rand

using namespace std;

string palavraSecreta = "MARCIO"; //var levada a escopo global parra valer em tds os escopos. Const para boas praticas
map<char, bool> chutou; //inplementacao do dicionario/vetor chutou
vector<char> chuteErrado; //vetor dinamico para guardar chutes errados

bool letraExiste(char chute);
bool naoAcertou(); //verificando se o usuario nao chutou um char presente na strinh/vetor palavra secreta 
bool naoEnforcou(); //verificando se o numero de erros foi maior do que 5 usando o tamanho do vetor chuteErrado

void cabecalho();
void printChutesErrados();//printar os chutes errados (valores dentro do vetor dinamico)
void verificandoChute();//verificar se o chute foi realizado com sucesso ou nao
void tratandoChute();
vector<string> lerArquivo(){
    ifstream arquivo;//ler arquivo
    arquivo.open("palavras.txt");//abrir txt associando a arquivo
    int quantidadePalavras;
    arquivo >> quantidadePalavras; //cin usando arquivo.

    vector<string> palavrasDoArquivo; //guaradar as palavras no vector

    //escrevendo as linhas do arquivoS
    for(int i = 0; i < quantidadePalavras; i++){
        string palavraLida;
        arquivo >> palavraLida;

        palavrasDoArquivo.push_back(palavraLida); //guardando no vector
    }
    return palavrasDoArquivo;
}
void sorteioPalavras(){
    vector<string> palavras = lerArquivo(); //populando o vetor com as pakavrs do arquivo

    srand(time(NULL)); //inicializando semente
    int indiceSorteado = rand() % palavras.size(); //sorteando pelo tamanho do vector palavras

    palavraSecreta = palavras[indiceSorteado]; //passando para a palavra secreta os indices sorteados

}

int main(){
    cabecalho();
    lerArquivo();
    sorteioPalavras();

    while(naoAcertou() && naoEnforcou()){
        printChutesErrados();
        verificandoChute();
        tratandoChute();
    }
}
//como varrer uma string posicao por posicao
bool letraExiste(char chute){
    for (int posicao = 0; posicao < palavraSecreta.size(); posicao++){ //palavraSecret.size() me retorna o tamanho da string em questao
        if(chute == palavraSecreta[posicao]){ //posicao na string
            return true;
        }
    }
    return false;
}
bool naoAcertou(){
    for (char i : palavraSecreta){
        if(!chutou[i]){
            return true;
        }
    }
    return false;
}
bool naoEnforcou(){
    if(chuteErrado.size() < 5){
        return true;
    }
    else{
        return false;
    }
}
void cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}
//printar os chutes errados (valores dentro do vetor dinamico)
void printChutesErrados(){
     cout << "Chutes errados: ";
    for(char i : chuteErrado){
        cout << i << " ";    
    }
     cout << endl;
}
//verificar se o chute foi realizado com sucesso ou nao
void verificandoChute(){
    for (char posicao : palavraSecreta){
        if(chutou[posicao]) {
            cout << posicao << " "; //se chutou certo
        }
        else {
            cout << "_ "; //se chutou errado
        }
    } cout << endl;
}
void tratandoChute(){
    char chute;
    cout << "Chute uma letra: "<< endl;
    cin >> chute;
    chutou[chute] = true; //quando o chute for verdadeiro retorno isso ao map 

    if(letraExiste(chute)){
        cout << "Voce acertou. Seu chute esta na palavra." << endl;

        if(!naoAcertou()){
        cout << "Fim de jogo." << endl;
        cout << "Parabens! Voce encontrou a palavra secreta." << endl;
        cout << "A palavrea secreta era: " << palavraSecreta << endl;
    }
    }
    else {
        cout << "Voce errou. Seu chute nao esta na palavra." << endl;
        chuteErrado.push_back(chute); //pega o valor da var chute que foi desviado para o else e guarda no fim do vetorr dinamico
        
        if(!naoEnforcou()){
        cout << "Fim de jogo. Voce enforcou!" << endl;
        cout << "A palavrea secreta era: " << palavraSecreta << endl;
        }
    }
    cout << endl;
}
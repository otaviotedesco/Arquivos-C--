#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

struct Registro {
    int id;
    string nome;
    float salario;
};

void mostra_registro(string nome_arquivo);
void grava_registro(Registro dados, string nome_arquivo);
void ler_dados(Registro dados[], string nome_arquivo);

int main() {
    setlocale(LC_ALL, "C");
    Registro funcionarios[10];
    int opcao;
    string nome_arquivo;

    do {
        cout << "--------------------------------------------" << endl;
        cout << "Bem vindo ao menu de cadastro e leitura de dados\n" << endl;
        cout << "Escolha sua opção\n" << endl;
        cout << "0 - Sair\n" << endl;
        cout << "1 - Gravar em arquivo\n" << endl;
        cout << "2 - Ler arquivo\n " << endl;
 
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\nDigite o nome do arquivo que deseja criar ou modificar: ";
                cin >> nome_arquivo;
                nome_arquivo = nome_arquivo + ".txt";
                fflush(stdin);
                
                cout << "\n\tInforme os dados dos funcionários: \n\n";
                ler_dados(funcionarios, nome_arquivo);
                break;

            case 2:
                
                cout << "\nDigite o nome do arquivo que deseja ler: ";
                cin >> nome_arquivo;
                nome_arquivo = nome_arquivo + ".txt";
                cout << "\n\tDados dos funcionários: \n\n";
                mostra_registro(nome_arquivo);
                break;

            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}



void grava_registro(Registro dados, string nome_arquivo) {
    ofstream arquivo(nome_arquivo, ios::out | ios::app);
        
    if (arquivo.is_open()) {
        arquivo << "Nome: " << dados.nome << endl;
        arquivo << "Salario: " << dados.salario << endl;
        arquivo << "ID: " << dados.id << endl << endl;

        arquivo.close();
    } else {
        cout << "ERRO 404: arquivo não encontrado" << endl;
    }
}



void mostra_registro(string nome_arquivo) {
    string linha;
    ifstream arquivo(nome_arquivo, ios::in);

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            cout << linha << endl;
        }
        arquivo.close();
    } else {
        cout << "ERRO 404: arquivo não encontrado" << endl;
    }
}




void ler_dados(Registro dados[], string nome_arquivo) {
   
for (int i = 0; i < 2; i++)
{
    cout << "\nInsira o nome do funcionário: ";
    cin >> dados[0].nome; 
    fflush(stdin);
    cout << "\nInsira o ID do funcionário: ";
    cin >> dados[0].id;
    fflush(stdin);
    cout << "\nInsira o salário do funcionário: ";
    cin >> dados[0].salario; 
    fflush(stdin);
    grava_registro(dados[0], nome_arquivo); 
    }
}


#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int TAM = 5;
int topo = -1;

void imprime_nomes(string pilha_nomes[TAM], int *ptopo){

    if(*ptopo == -1){
        cout << "Empilhamento Vazio!" << endl;
    }else{
        cout << "Os nomes cadastrados sao:" << endl;
        for(int i = 0; i <= *ptopo; i++){
            cout << "--> " << pilha_nomes[i] << " alocado na posicao " << i << " da pilha de nomes." << endl;
        }
    }
    cout<<endl;
}

void nomes_push(string pilha_nomes[TAM], int *ptopo, string valor){
    if(*ptopo == TAM - 1){
        cout << "\nO empilhamento de nomes esta cheio!" << endl;
        cout << endl;
    }else{
        *ptopo = *ptopo + 1;
        pilha_nomes[*ptopo] = valor;
    }
}

void informa_nomes(string pilha_nomes[TAM], int *ptopo, string valor){
    char ch;
    
    cout << "Lembre-se que soh pode cadastrar 5 nomes no empilhamento." << endl;
    cout << endl;
    do{
        cout << "Digite um nome: ";
        cin >> valor;
        cout << endl;
        nomes_push(pilha_nomes, ptopo, valor);
        cout << "Deseja continuar? Digite (s) para continuar e (n) para parar." << endl;
        cout << "Opcao: ";
        cin >> ch;
        cout << endl;
    }while(ch == 's');
    
}

void nomes_pop(string pilha_nomes[TAM], int *ptopo){
    if(*ptopo == -1){
        cout << "Empilhamento Vazio!" << endl;
    }else{
        cout << "O nome removido foi: " << "'" << pilha_nomes[*ptopo] << "'" << " da posicao " << *ptopo 
        << " do empilhamento." << endl;
        *ptopo = *ptopo - 1;
    }
    cout << endl;
    cout << "Novo empilhamento ficou assim:" << endl;
    imprime_nomes(pilha_nomes, ptopo);
}

void nomes_clear(string pilha_nomes[TAM], int *ptopo, string valor){
    for(int i = *ptopo; i >= -1; i--){
        *ptopo = i;
        pilha_nomes[*ptopo] = valor;
    }
    cout << "Empilhamento de nomes foi esvaziado!" << endl;
}

void menu(string pilha_nomes[TAM], int *ptopo, string valor){    
    int opcao;
	
	do {
	    do{
	      	system("cls");
	      	cout << "\t+--------------------------------+\n";
	      	cout << "\t|         MENU PRINCIPAL         |\n";
	      	cout << "\t|       Empilhamento em C++      |\n";
	      	cout << "\t+--------------------------------+\n";
	     	cout << "1- Informar Nomes Para Empilhamento" << endl;
	      	cout << "2- Imprimir Dados Do Empilhamento" << endl;
	      	cout << "3- Remover Nome do Topo do Empilhamento" << endl;
	      	cout << "4- Esvaziar Empilhamento de Nomes" << endl;
	      	cout << "0- Sair" << endl;
	      
		   	cout << "\nInforme a opcao desejada: ";
		   	cin >> opcao;
		   	
		}while(opcao < 0 || opcao > 4);
		
		  	if(opcao == 1){
		  		system("cls");
		  		informa_nomes(pilha_nomes, ptopo, valor);
				system("pause");
			  	}
				else
				if(opcao == 2){
					system("cls");
					imprime_nomes(pilha_nomes, ptopo);
                    system("pause");
					}
                    else
                    if(opcao == 3){
                        system("cls");
                        nomes_pop(pilha_nomes, ptopo);
                        system("pause");
                        }
                        else
                        if(opcao == 4){
                            system("cls");
                            nomes_clear(pilha_nomes, ptopo, valor);
                            system("pause");
                        }
 	}while(opcao != 0);
}

int main(){
    string pilha_nomes[TAM];
    string valor;
    int *ptopo;
    ptopo = &topo;

    for(int i = 0; i < TAM; i++){
        pilha_nomes[i] = "";
    }

    menu(pilha_nomes, ptopo, valor);
}
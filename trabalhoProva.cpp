//programa que fará um empilhamento de nomes dentro de um vetor que se comportará como uma pilha
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int TAM = 5; // Declaração de uma constante global que informará o tamanho do indice usado na pilha

// Procedimento responsável pela impressão da pilha de nomes
void imprime_nomes(string pilha_nomes[TAM], int *ptopo){
    if(*ptopo == -1){
        cout << "Empilhamento Vazio!" << endl;
    }else{
        cout << "Os nomes cadastrados sao:" << endl;
        for(int i = 0; i <= *ptopo; i++){
            cout << "--> " << pilha_nomes[i] << " foi alocado na posicao " << i << " da pilha de nomes." << endl;
        }
    }
    cout<<endl;
}

// Procedimento responsável por fazer o empilhamento dos nomes dentro do vetor
void nomes_push(string pilha_nomes[TAM], int *ptopo, string valor){
    if(*ptopo == TAM - 1){ // Condição que verifica se o ponteiro 'ptopo' chegou ao limite do tamanho do empilhamento
        cout << "\nO empilhamento de nomes esta cheio!" << endl;
        cout << "Voces nao pode mais inserir nomes no empilhamento." << endl;
        cout << endl;
    }else{ // se a pilha de nomes não estiver no limite, continua inserindo nomes dentro da pilha
        *ptopo = *ptopo + 1;
        pilha_nomes[*ptopo] = valor;
    }
}

// Procedimento responsável por fazer o cadastro 
void informa_nomes(string pilha_nomes[TAM], int *ptopo, string valor){
    char ch; // Variável local para o controle da quantidade de nomes inseridos, sendo o máximo de 5 nomes
    
    cout << "Lembre-se que soh pode cadastrar 5 nomes no empilhamento." << endl;
    cout << endl;
    
    // Loop para inserção dos nomes na pilha
    do{
        cout << "Digite um nome: ";
        cin >> valor; // Armazenará o nome digitado dentro da string VALOR
        cout << endl;
        nomes_push(pilha_nomes, ptopo, valor); // Chamada do procedimento "nomes_push" para inserir o nome digitado dentro da pilha
        cout << endl;
        cout << "Deseja continuar? Digite (s) para continuar e (n) para parar." << endl;
        cout << "Opcao: ";
        cin >> ch; // verificará a condicação de continuar ou não informada pelo usuário, conforme a condição do loop
        cout << endl;
    }while(ch == 's'); // condição do loop para que o usuário continue inserindo nomes até chegar o máximo de inserções
    
}

// Procedimento responsável por fazer a exclusão do nome do topo da pilha, na condição de que o primeiro a ser inserido será o último a ser excluido
void nomes_pop(string pilha_nomes[TAM], int *ptopo){
    if(*ptopo == -1){ // Verifica se a pilha de nomes está vazia
        cout << "Empilhamento Vazio!" << endl;
    }else{ // Se não estiver vazia, removerá o nome do topo da pilha
        cout << "O nome removido foi: " << "'" << pilha_nomes[*ptopo] << "'" << " da posicao " << *ptopo 
        << " do empilhamento." << endl;
        *ptopo = *ptopo - 1; // Vai diminuir 1 indice por exclusão até chegar no topo inicial de -1
    }
    cout << endl;
    cout << "Novo empilhamento ficou assim:" << endl;
    cout << endl;
    imprime_nomes(pilha_nomes, ptopo); // Chamada do procedimento para mostrar como ficou nova pilha de nomes depois da exlusão do nome do topo
}

// Procedimento responsável por excluir todos os dados da pilha, deixando-a vazia
void nomes_clear(string pilha_nomes[TAM], int *ptopo, string valor){
    for(int i = *ptopo; i >= -1; i--){ // Loop responsável por percorrer todos os indices da pilha excluindo 1 a 1, até chegar em topo = -1, que é a condição de pilha vazia
        *ptopo = i;
        pilha_nomes[*ptopo] = valor;
    }
    cout << "Empilhamento de nomes foi esvaziado!" << endl;
}

// Procedimento responsável por montar um menu para controle das ações do usuário
void menu(string pilha_nomes[TAM], int *ptopo, string valor){    
    int opcao; // Variável local para controle das opções escolhidas pelo usuário
	
	do { // Loop responsável pelo controle das opções enquanto for != 0
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
		  		informa_nomes(pilha_nomes, ptopo, valor); // Chamada do procedimento caso o usuário escolha a opção 1 do menu
				system("pause");
			  	}
				else
				if(opcao == 2){
					system("cls");
					imprime_nomes(pilha_nomes, ptopo); // Chamada do procedimento caso o usuário escolha a opção 2 do menu
                    system("pause");
					}
                    else
                    if(opcao == 3){
                        system("cls");
                        nomes_pop(pilha_nomes, ptopo); // Chamada do procedimento caso o usuário escolha a opção 3 do menu
                        system("pause");
                        }
                        else
                        if(opcao == 4){
                            system("cls");
                            nomes_clear(pilha_nomes, ptopo, valor); // Chamada do procedimento caso o usuário escolha a opção 4 do menu
                            system("pause");
                        }
 	}while(opcao != 0); // Condição do loop para que seja exibido o menu
}

// Função principal do programa, é onde todo o processo de execução se inicia
int main(){
    string pilha_nomes[TAM], valor; // Declaração de Strings para a PILHA e para a variável VALOR
    int topo = -1; // Declaração da variável TOPO iniciando com valor -1
    int *ptopo; // Declaração do ponteiro *PTOPO
    ptopo = &topo; // Apontando PTOPO para o endereço de memória da variável TOPO

    for(int i = 0; i < TAM; i++){ // Loop responsável por deixar a PILHA sem sujeita de memória, deixando todos os indices vazios
        pilha_nomes[i] = "";
    }

    menu(pilha_nomes, ptopo, valor); // Chamada do procedimento MENU para iniciar o programa
}
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstring>
#include <unistd.h>

using namespace std;

FILE *teste;

struct cliente{
     
    char cpf[20], placa[20], cor[20], modelo[20];
    int auxe, existe;
    
};
cliente c1;


void limpar()
{
	for(int i=0; i<20; i++){
		c1.cpf[i]=' ';
		c1.placa[i]=' ';
		c1.modelo[i]=' ';
		c1.cor[i]=' ';
	}
}

void cadastro()
{
	char o;
	do{
		system("cls || clear");       //limpa a tela 
        cout<<"  ______________________________________________________________"<<endl;
        cout<<" |   \t                                                        |\n";
        cout<<" |   \tCPF do cliente: ";
		cin.getline(c1.cpf,20);
		cout<<" |______________________________________________________________|\n";
		cout<<"  ______________________________________________________________"<<endl;
        cout<<" |   \t                                                        |\n";
        cout<<" |   \tPlaca do carro: ";
		cin.getline(c1.placa,10);
		cout<<" |______________________________________________________________|\n";
		cout<<"  ______________________________________________________________"<<endl;
        cout<<" |   \t                                                        |\n";
        cout<<" |   \tModelo do carro: ";
		cin.getline(c1.modelo,20);
		cout<<" |______________________________________________________________|\n";
		cout<<"  ______________________________________________________________"<<endl;
        cout<<" |   \t                                                        |\n";
        cout<<" |   \tCor: ";
		cin.getline(c1.cor,20);
		cout<<" |______________________________________________________________|\n";
		c1.existe = 1;
        //GRAVAR NO ARQUIVO
        
        fseek(teste, sizeof(cliente), SEEK_END);
        fwrite(&c1, sizeof(cliente), 1, teste);
        limpar();			//limpeza do espaço que sobra na variavel
        cout<<endl;
        cout<<"##################################################################"<<endl;
        cout<<"#                                                                #"<<endl;
        cout<<"#   \t\tCadastro realizado com sucesso!                  #"<<endl;
		cout<<"#                                                                #"<<endl;
		cout<<"##################################################################"<<endl;
		cout<<endl;
		cout<<"    \t>> Deseja continuar cadastrando? (s ou n)";
		
		do{
            cout<<endl;
		    cout<<"    \t>> ";
			cin>>o;
			cin.ignore();
			if (o!= 's' && o!='S' && o!='n' && o!='N')
				cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
		}while(o!= 's' && o!='S' && o!='n' && o!='N');	
	}while (o== 's' || o=='S' );	
}

void editar()
{	
	char edicao[20], o;
	int i, k, x;
	do{
		do{
			system("cls || clear");
			i=0; x=0;
			o = ' ';
			for(int j=0; j<20; j++)
				edicao[i] = ' ';
			cout<<endl<<"    \t>> Placa do carro do cliente que deseja editar: ";
			cin.getline(edicao,20);
			fseek(teste, 0, SEEK_SET);
			fseek(teste, sizeof(cliente), SEEK_CUR);
			fread(&c1, sizeof(cliente), 1, teste);	
			while(!feof(teste)){
				if( strcmp(c1.placa, edicao) == 0 && c1.existe == 1){
				    cout<<endl;
	                cout<<"  ______________________________________________________________"<<endl;
	                cout<<"/|   \t                                                        |\n";
					cout<<" |   \tCPF: "<<c1.cpf<<endl;
				    cout<<" |   \tPlaca do carro: "<<c1.placa<<endl;
		       	    cout<<" |   \tModelo do carro: "<<c1.modelo<<endl;
		            cout<<" |   \tCor: "<<c1.cor<<endl;
		            cout<<" |______________________________________________________________|\n";
		            cout<<"/";
		            i++;
		            
		            if(i!=0){
						cout<<endl<<"    \t>> Esse é o cliente a ser editado? (s ou n)";
		    			do{
                            cout<<endl;
                            cout<<"    \t>> ";
							cin>>o;
							cin.ignore();
							if (o!= 's' && o!='S' && o!='n' && o!='N')
								cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
						}while(o!= 's' && o!='S' && o!='n' && o!='N');
					}
					if (o=='s' || o=='S'){
						do{
                            if(x > 0){  
                                system("cls || clear"); 
                                cout<<endl;
            	                cout<<"  ______________________________________________________________"<<endl;
            	                cout<<"/|   \t                                                        |\n";
            					cout<<" |   \tCPF: "<<c1.cpf<<endl;
            				    cout<<" |   \tPlaca do carro: "<<c1.placa<<endl;
            		       	    cout<<" |   \tModelo do carro: "<<c1.modelo<<endl;
            		            cout<<" |   \tCor: "<<c1.cor<<endl;
            		            cout<<" |______________________________________________________________|\n";
            		            cout<<"/";   
                            }
                            x++;
							cout<<endl;
							cout<<"    \t>> Qual campo deseja editar?"<<endl<<endl;
							cout<<"  ______________________________________________________________"<<endl;
    	                    cout<<"/|   \t                                                        |\n";
							cout<<" |   \t1 - CPF"<<endl;
							cout<<" |   \t2 - Placa"<<endl;
							cout<<" |   \t3 - Modelo"<<endl;
							cout<<" |   \t4 - Cor"<<endl;
							cout<<" |   \t0 - Cancelar"<<endl;
							cout<<" |______________________________________________________________|\n";
							cout<<"/";
							cout<<endl;
							
							do{
                                cout<<endl;
                                cout<<"    \t>> ";
								cin>>k;
								if(k<0 || k>4)
									cout<<"    \t>> não seja estúpido"<<endl;
							}while(k<0 || k>4);	
							cin.ignore();
							cout<<endl;
							switch (k){
								case 1:
									cout<<"    \t>> Entre com o novo CPF: ";
									cin.getline(c1.cpf,20);
									fseek(teste, -sizeof(cliente), SEEK_CUR);
									fwrite(&c1, sizeof(cliente), 1, teste);
								break;
								case 2:
									cout<<"    \t>> Entre com a nova placa: ";
									cin.getline(c1.placa,20); 
									fseek(teste, -sizeof(cliente), SEEK_CUR);
									fwrite(&c1, sizeof(cliente), 1, teste);
								break;
								case 3:
									cout<<"    \t>> Entre com o novo modelo: ";
									cin.getline(c1.modelo,20); 
									fseek(teste, -sizeof(cliente), SEEK_CUR);
									fwrite(&c1, sizeof(cliente), 1, teste);
								break;
								case 4:	
									cout<<"    \t>> Entre com a nova cor: ";
									cin.getline(c1.cor,20); 
									fseek(teste, -sizeof(cliente), SEEK_CUR);
									fwrite(&c1, sizeof(cliente), 1, teste);
								break; 
							}
							if( k == 0 )
							    break;
							cout<<endl;
							cout<<"##################################################################"<<endl;
                            cout<<"#                                                                #"<<endl;
                            cout<<"#   \t\tEdição realizada com sucesso!                    #"<<endl;
		                    cout<<"#                                                                #"<<endl;
		                    cout<<"##################################################################"<<endl;
							cout<<endl<<"    \t>> Deseja editar outro campo?(s ou n)";
							do{
                                cout<<endl;
		                        cout<<"    \t>> ";             
								cin>>o;
								cin.ignore();
								if (o!= 's' && o!='S' && o!='n' && o!='N')
									cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
							}while(o!= 's' && o!='S' && o!='n' && o!='N');        
			            }while(o== 's' || o=='S' );
		            }
		            cout<<endl;
					cout<<"    \t>> Deseja procurar outro cliente para edição? (s ou n)";
					
				    do{
                        cout<<endl;
		                cout<<"    \t>> ";          
						cin>>o;
						cin.ignore();
						if (o!= 's' && o!='S' && o!='n' && o!='N')
							cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
					}while(o!= 's' && o!='S' && o!='n' && o!='N');	    
				
		        break;
				}
		        
		    	fseek(teste, sizeof(cliente), SEEK_CUR);
				fread(&c1, sizeof(cliente), 1, teste);	
		    }
		    if (i==0){
		    	cout<<"    \t>> Carro não encontrado"<<endl<<endl;
				cout<<"    \t>> Deseja procurar outro cliente para edição? (s ou n)";
			    do{
                    cout<<endl;
		            cout<<"    \t>> ";          
					cin>>o;
					cin.ignore();
					if (o!= 's' && o!='S' && o!='n' && o!='N')
						cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
				}while(o!= 's' && o!='S' && o!='n' && o!='N');	
			}		
		}while(o== 's' || o=='S' );
	}while(o== 's' || o=='S' );	
	
}

void excluir()
{
	
	char exclusao[20], o, cpf[20], placa[20], cor[20], modelo[20];
	int i, k;
	do{
		do{
			system("cls || clear");
			i=0;
			o = ' ';
			for(int j=0; j<20; j++)
				exclusao[i] = ' ';
			cout<<endl<<"    \t>> Placa do carro do cliente que deseja excluir: ";
			cin.getline(exclusao,20);
			fseek(teste, 0, SEEK_SET);
			fseek(teste, sizeof(cliente), SEEK_CUR);
			fread(&c1, sizeof(cliente), 1, teste);	
			while(!feof(teste)){
				if( strcmp(c1.placa, exclusao) == 0 && c1.existe == 1){
				    cout<<endl;
				    cout<<"  ______________________________________________________________"<<endl;
                    cout<<"/|   \t                                                        |\n";
					cout<<" |   \tCPF:"<<c1.cpf<<endl;
				    cout<<" |   \tPlaca do carro: "<<c1.placa<<endl;
		       	    cout<<" |   \tModelo do carro: "<<c1.modelo<<endl;
		            cout<<" |   \tCor: "<<c1.cor<<endl;
		            cout<<" |______________________________________________________________|\n";
		            cout<<"/";
		            cout<<endl;
		            i++;
		            
		            if(i!=0){
						cout<<"    \t>> Esse é o cadastro a ser excluído? (s ou n)";
		    			do{
                            cout<<endl;
		                    cout<<"    \t>> ";        
							cin>>o;
							cin.ignore();
							if (o!= 's' && o!='S' && o!='n' && o!='N')
								cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
						}while(o!= 's' && o!='S' && o!='n' && o!='N');
					}
					if (o=='s' || o=='S'){
						c1.existe = 0;
						fseek(teste, -sizeof(cliente), SEEK_CUR);
						fwrite(&c1, sizeof(cliente), 1, teste);
					
    					cout<<endl;
    					cout<<"##################################################################"<<endl;
                        cout<<"#                                                                #"<<endl;
                        cout<<"#   \t\tCadastro excluído com sucesso!                   #"<<endl;
    		            cout<<"#                                                                #"<<endl;
    		            cout<<"##################################################################"<<endl;	
    					cout<<endl;
                    }
					cout<<endl<<"    \t>> Deseja procurar outro cadastro para excluir? (s ou n)";
				    do{
                        cout<<endl;
                        cout<<"    \t>> ";          
						cin>>o;
						cin.ignore();
						if (o!= 's' && o!='S' && o!='n' && o!='N')
							cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
					}while(o!= 's' && o!='S' && o!='n' && o!='N');	    
				
		        break;
				}
		        
		    	fseek(teste, sizeof(cliente), SEEK_CUR);
				fread(&c1, sizeof(cliente), 1, teste);	
		    }
		    if (i==0){
		    	cout<<"    \t>> Carro não encontrado"<<endl<<endl;
				cout<<"    \t>> Deseja procurar outro cadastro para excluir? (s ou n)";
			    do{
                    cout<<endl;
		            cout<<"    \t>> ";          
					cin>>o;
					cin.ignore();
					if (o!= 's' && o!='S' && o!='n' && o!='N')
						cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
				}while(o!= 's' && o!='S' && o!='n' && o!='N');	
			}		
		}while(o== 's' || o=='S' );
	}while(o== 's' || o=='S' );	
	
}

void pesquisar()
{
	char pesquisa[20],o;
	int i;
	do{
		system("cls || clear");
		i=0;
		cout<<endl<<"    \t>> Placa do carro: ";
		cin.getline(pesquisa,20);
		fseek(teste, 0, SEEK_SET);
		fseek(teste, sizeof(cliente), SEEK_CUR);
		fread(&c1, sizeof(cliente), 1, teste);	
		while(!feof(teste)){
			if( strcmp(c1.placa, pesquisa) == 0 && c1.existe == 1){
                cout<<"  ______________________________________________________________"<<endl;
                cout<<"/|   \t                                                        |\n";
			    cout<<" |   \tCPF:"<<c1.cpf<<endl;
			    cout<<" |   \tPlaca do carro: "<<c1.placa<<endl;
	       	    cout<<" |   \tModelo do carro: "<<c1.modelo<<endl;
	            cout<<" |   \tCor: "<<c1.cor<<endl;
	            cout<<" |______________________________________________________________|\n";
	            cout<<"/";
	            cout<<endl;
	            i++;
	        }
	    	fseek(teste, sizeof(cliente), SEEK_CUR);
			fread(&c1, sizeof(cliente), 1, teste);	
	    }
	    if (i==0)
	    	cout<<"    \t>> Carro não encontrado"<<endl<<endl; 	
		cout<<"    \t>> Deseja fazer outra busca? (s ou n)"<<endl;
	    do{
            cout<<endl;
		    cout<<"    \t>> ";          
			cin>>o;
			cin.ignore();
			if (o!= 's' && o!='S' && o!='n' && o!='N')
				cout<<"    \t>> não seja estúpido"<<endl;			//ARRUMAR!!!!!!!!!!
		}while(o!= 's' && o!='S' && o!='n' && o!='N');	    
	}while(o== 's' || o=='S' );	
}

void listar()
{
    system("cls || clear");
    int k=0;
	fseek(teste, 0, SEEK_SET);   //topo, p comecar
	fseek(teste, sizeof(cliente), SEEK_CUR);
	fread(&c1, sizeof(cliente), 1, teste);
    while(!feof(teste)){
    	if (c1.existe == 1){
        
            cout<<"  ______________________________________________________________"<<endl;
	        cout<<"/|   \t                                                        |\n";
			cout<<" |   \tCpf: "<<c1.cpf<<endl;
	        cout<<" |   \tPlaca do carro: "<<c1.placa<<endl;
	        cout<<" |   \tModelo do carro: "<<c1.modelo<<endl;
	        cout<<" |   \tCor: "<<c1.cor<<endl;
	        cout<<" |______________________________________________________________|\n";
	        cout<<"/"<<endl;
	        k++;
	    }
		    fseek(teste, sizeof(cliente), SEEK_CUR);
		    fread(&c1, sizeof(cliente), 1, teste);
   
    	
	}
    if(k != 0)
        cout<<endl<<"    \t>> Pressione enter para continuar...";
    else{
        cout<<endl<<"    \t>> Não há nenhum cliente cadastrado.";
        cout<<endl<<"    \t>> Pressione enter para continuar...";
    }
    cin.ignore();
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
    system("color 30");
    teste = fopen("teste.txt", "r+");
	if (teste == NULL){
		teste = fopen("teste.txt","w+");	
		if(teste == NULL){
			cout<<"Erro ao abrir arquivo"<<endl;
			exit(1);
		}
	}
	// carregamento
	
	for(int i=1;i<=3;i++){
        
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl;
        cout<<"\t\t\t  ________________         \n";
        cout<<"\t\t\t /|   | |   \\ \\   \\        \n";
        cout<<"\t\t\t| |___| |____\\ \\___\\__     \n";
        cout<<"\t\t\t|  _         _   |/  \\|    \n";
        cout<<"\t\t\t|_/ \\_______/ \\__|____|    \n";
        cout<<"\t\t\t  \\_/ \\_/   \\_/ \\_/        \n";
        cout<<endl<<"\t\t\t\tLOADING"<<endl;
        usleep(100000);
        system("cls || clear");   
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t    ________________       \n";
        cout<<"\t\t\t   /|   | |   \\ \\   \\      \n";
        cout<<"\t\t\t  | |___| |____\\ \\___\\__   \n";
        cout<<"\t\t\t  |  _         _   |/  \\|  \n";
        cout<<"\t\t\t  |_/ \\_______/ \\__|____|  \n";
        cout<<"\t\t\t    \\_/ \\_/   \\_/ \\_/      \n";
        cout<<endl<<"\t\t\t\tLOADING"<<endl;
        usleep(100000);
        system("cls || clear"); 
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t      ________________     \n";
        cout<<"\t\t\t     /|   | |   \\ \\   \\    \n";
        cout<<"\t\t\t    | |___| |____\\ \\___\\__ \n";
        cout<<"\t\t\t    |  _         _   |/  \\|\n";
        cout<<"\t\t\t    |_/ \\_______/ \\__|____|\n";
        cout<<"\t\t\t      \\_/ \\_/   \\_/ \\_/    \n";
        cout<<endl<<"\t\t\t\tLOADING"<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t        ________________   \n";
        cout<<"\t\t\t       /|   | |   \\ \\   \\  \n";
        cout<<"\t\t\t_     | |___| |____\\ \\___\\_\n";
        cout<<"\t\t\t\\|    |  _         _   |/  \n";
        cout<<"\t\t\t_|    |_/ \\_______/ \\__|___\n";
        cout<<"\t\t\t        \\_/ \\_/   \\_/ \\_/  \n";
        cout<<endl<<"\t\t\t\tLOADING."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t          ________________ \n";
        cout<<"\t\t\t         /|   | |   \\ \\   \\\n";
        cout<<"\t\t\t\\__     | |___| |____\\ \\___\n";
        cout<<"\t\t\t  \\|    |  _         _   |/\n";
        cout<<"\t\t\t___|    |_/ \\_______/ \\__|_\n";
        cout<<"\t\t\t          \\_/ \\_/   \\_/ \\_/\n";
        cout<<endl<<"\t\t\t\tLOADING."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_           _______________\n";
        cout<<"\t\t\t \\         /|   | |   \\ \\  \n";
        cout<<"\t\t\t__\\__     | |___| |____\\ \\_\n";
        cout<<"\t\t\t|/  \\|    |  _         _   \n";
        cout<<"\t\t\t|____|    |_/ \\_______/ \\__\n";
        cout<<"\t\t\t_/          \\_/ \\_/   \\_/ \\\n";
        cout<<endl<<"\t\t\t\tLOADING."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t___           _____________\n";
        cout<<"\t\t\t   \\         /|   | |   \\ \\\n";
        cout<<"\t\t\t\\___\\__     | |___| |____\\ \n";
        cout<<"\t\t\t  |/  \\|    |  _         _ \n";
        cout<<"\t\t\t__|____|    |_/ \\_______/ \\\n";
        cout<<"\t\t\t \\_/          \\_/ \\_/   \\_/\n";
        cout<<endl<<"\t\t\t\tLOADING.."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_____           ___________\n";
        cout<<"\t\t\t \\   \\         /|   | |   \\\n";
        cout<<"\t\t\t\\ \\___\\__     | |___| |____\n";
        cout<<"\t\t\t_   |/  \\|    |  _         \n";
        cout<<"\t\t\t \\__|____|    |_/ \\_______/\n";
        cout<<"\t\t\t_/ \\_/          \\_/ \\_/   \\\n";
        cout<<endl<<"\t\t\t\tLOADING.."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_______           _________\n";
        cout<<"\t\t\t \\ \\   \\         /|   | |  \n";
        cout<<"\t\t\t__\\ \\___\\__     | |___| |__\n";
        cout<<"\t\t\t  _   |/  \\|    |  _       \n";
        cout<<"\t\t\t_/ \\__|____|    |_/ \\______\n";
        cout<<"\t\t\t \\_/ \\_/          \\_/ \\_/  \n";
        cout<<endl<<"\t\t\t\tLOADING.."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_________           _______\n";
        cout<<"\t\t\t   \\ \\   \\         /|   | |\n";
        cout<<"\t\t\t____\\ \\___\\__     | |___| |\n";
        cout<<"\t\t\t    _   |/  \\|    |  _     \n";
        cout<<"\t\t\t___/ \\__|____|    |_/ \\____\n";
        cout<<"\t\t\t   \\_/ \\_/          \\_/ \\_/\n";
        cout<<endl<<"\t\t\t\tLOADING.."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t___________           _____\n";
        cout<<"\t\t\t |   \\ \\   \\         /|   |\n";
        cout<<"\t\t\t |____\\ \\___\\__     | |___|\n";
        cout<<"\t\t\t      _   |/  \\|    |  _   \n";
        cout<<"\t\t\t_____/ \\__|____|    |_/ \\__\n";
        cout<<"\t\t\t_/   \\_/ \\_/          \\_/ \\\n";
        cout<<endl<<"\t\t\t\tLOADING..."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_____________           ___\n";
        cout<<"\t\t\t | |   \\ \\   \\         /|  \n";
        cout<<"\t\t\t_| |____\\ \\___\\__     | |__\n";
        cout<<"\t\t\t        _   |/  \\|    |  _ \n";
        cout<<"\t\t\t_______/ \\__|____|    |_/ \\\n";
        cout<<"\t\t\t \\_/   \\_/ \\_/          \\_/\n";
        cout<<endl<<"\t\t\t\tLOADING..."<<endl;
        usleep(100000);
        system("cls || clear");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t"<<endl; 
        cout<<"\t\t\t_______________           _\n";
        cout<<"\t\t\t   | |   \\ \\   \\         /|\n";
        cout<<"\t\t\t___| |____\\ \\___\\__     | |\n";
        cout<<"\t\t\t_         _   |/  \\|    |  \n";
        cout<<"\t\t\t \\_______/ \\__|____|    |_/\n";
        cout<<"\t\t\t_/ \\_/   \\_/ \\_/          \\\n";
        cout<<endl<<"\t\t\t\tLOADING..."<<endl;
        usleep(100000);
        system("cls || clear");
        
    }
    
    int n;
    
    //menu
	do{
		system("cls || clear");
        cout<<"	___           ___           ___           ___                           ";   
		cout<<"       /  /\\         /  /\\         /  /\\         /  /\\               "<<endl;
		cout<<"      /  /::|       /  /::\\       /  /::|       /  /:/                  "<<endl;
		cout<<"     /  /:|:|      /  /:/\\:\\     /  /:|:|      /  /:/                  "<<endl;
		cout<<"    /  /:/|:|__   /  /::\\ \\:\\   /  /:/|:|__   /  /:/                  "<<endl;
		cout<<"   /__/:/_|::::\\ /__/:/\\:\\ \\:\\ /__/:/ |:| /\\ /__/:/     /\\        "<<endl;
		cout<<"   \\__\\/  /~~/:/ \\  \\:\\ \\:\\_\\/ \\__\\/  |:|/:/ \\  \\:\\    /:/  "<<endl;
		cout<<"         /  /:/   \\  \\:\\ \\:\\       |  |:/:/   \\  \\:\\  /:/        "<<endl;
		cout<<"        /  /:/     \\  \\:\\_\\/       |__|::/     \\  \\:\\/:/          "<<endl;
		cout<<"       /__/:/       \\  \\:\\         /__/:/       \\  \\::/             "<<endl;
		cout<<"       \\__\\/         \\__\\/         \\__\\/         \\__\\/           "<<endl;
	    cout<<"\n";
	    cout<<"  ______________________________________________________________"<<endl;
	    cout<<"/|   \t                                                        |\n";
	    cout<<" |   \t1 - Cadastrar Cliente                                   |\n";
	    cout<<" |   \t2 - Editar Cadastro                                     |\n";
	    cout<<" |   \t3 - Excluir Cadastro                                    |\n";
	    cout<<" |   \t4 - Pesquisar Cliente                                   |\n";
	    cout<<" |   \t5 - Clientes Cadastrados                                |\n";
	    cout<<" |   \t0 - Finalizar                                           |\n";
	    cout<<" |______________________________________________________________|\n";
	    cout<<"/"<<endl;
	    cout<<"  ______________________________________________________________"<<endl;
	    cout<<"/|   \t                                                        |\n";
	    cout<<" |   \tNúmero da Opção Desejada: ";
	    //entrada da opçao escolhida
	    
		do{
			cin>>n;
			cout<<" |______________________________________________________________|\n";
			cout<<"/"<<endl;
		    cin.ignore();
			switch(n){
		        case 1: cadastro(); break;
		        case 2: editar();   break;
		        case 3: excluir();  break;
		        case 4: pesquisar();break;
		        case 5: listar();   break;
		        case 0: break;
		        default: {
                        cout<<"  ______________________________________________________________"<<endl;
                        cout<<"/|   \t                                                        |\n";
                        cout<<" |   \tOpção inválida, tente novamente: "; 
                }
		    }
	    }while (n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=0); 
    }while (n != 0);
	
	fclose(teste);
    return 0;
}

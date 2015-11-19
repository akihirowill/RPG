#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "rpg.h"
#include "Monsters.h"

Class Classes[5]; // Structure das classes

void imprimechar (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot){
    // Imprime as características principais do personagem
    limpa();
    printf("Nome: %s\nClasse: %s\nNivel: %2d (%d/%d)\n",nome,Personagem.classname,nivel,expa,expt);
	printf("HP: %d/%d\nOuro: %3d\nPotions: %d\nSTR: %3d\nDEX: %3d\nCON: %3d\n",hpa,hpmax,gold,hppot,Personagem.str,Personagem.dex,Personagem.con);
}

void imprimemenu (Class Personagem, int nivel, char* nome, int expa, int expt,int hpc, int hpmax, int gold, int hppot) {
    imprimechar(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
    // Imprime o menu principal do jogo
    printf("1. Ir para o monasterio\n2. Ir para o campo de treinamento Pares\n3. Explorar\n");
    if (expa>=expt && nivel != 10){
        printf("4. Falar com o mestre\n");
    }
    if (nivel == 10 && expa >= expt){
        printf("5. Enfrentar Eenlucifer\n");
    }
    printf("9. Save Game\n");
    printf("Action:");
}

void imprimemestre (Class Personagem, int nivel, char* nome, int expa, int expt, int hpa, int hpmax, int gold, int hppot){
    imprimechar(Personagem,nivel,nome,expa,expt,hpa,hpmax,gold,hppot);
    // Imprime o menu do mestre
    printf("1. Lutar contra o mestre\n2. Sair\n");
    printf("Action:");
}

void boss (Class *Personagem,char* nome,Monsters Eenlucifer,int *hpa, int *hpmax, int *hppot,int n,int* win, int* death){
    char atoio[30];
    int tamatoio;
    int vidamob, vidamobmax;
    int cont = 0;
    int cura, def = 0, curou = 0, defa = 0, dexp, dexm, ataquep, ataquem;
    int doge = 0, crit = 0;
    vidamob = Eenlucifer.con;
    vidamobmax = Eenlucifer.con;
    int acao;
    while(vidamob > 0 && *hpa > 0){
		limpa();
		printf("%s%45s\n",nome,Eenlucifer.nome);
		printf("HP: %d/%d%40d/%d\n",*hpa,*hpmax,vidamob,vidamobmax);
		printf("1. Ataque fraco\n2. Ataque forte (chance de critico, maior taxa de desvio do oponente)\n3. Defesa + Potion (%d)\n",*hppot);
		if (cont != 0 && tamatoio == 1 && acao >= 1 && acao <= 4){
            if (defa != 0 && curou > 0){
				printf ("%s se curou por %d e sofreu %d dano de %s\n",nome,cura,ataquem-def,Eenlucifer.nome);
			}
			else if(defa != 0 && curou == 0){
				printf ("%s sofreu %d de dano de %s\n",nome,(ataquem-def),Eenlucifer.nome);
			}
			else{
				if (doge == 1){
					if (crit == 1){
						printf ("%s causou %d de dano e desviou do ataque de %s\n",Eenlucifer.nome,ataquem,nome);
					}
					else{
						if (dexp >= dexm){
							printf ("%s causou %d de dano e desviou do ataque de %s\n",nome,ataquep,Eenlucifer.nome);
						}
						else{
							printf("%s causou %d de dano e desviou do ataque de %s\n",Eenlucifer.nome,ataquem,nome);
						}
					}
				}
				else{
					if (crit == 1){
						printf("%s desferiu um ACERTO CRITICO e causou %d de dano\n%s causou %d de dano a %s\n",nome,2*ataquep,Eenlucifer.nome,ataquem,nome);
					}
					else{
						printf("%s causou %d de dano e recebeu %d de dano de %s\n",nome,ataquep,ataquem,Eenlucifer);
					}
				}
			}
		}
		ataquep = rand()%(Personagem->str)+1;
		ataquem = rand()%(Eenlucifer.str)+1;
		dexp = rand()%(Personagem->dex)+1;
		dexm = rand()%(Eenlucifer.dex)+1;
		cont++;
		doge = 0;
		crit = 0;
		def = 0;
		defa = 0;
		curou = 0;
		printf("Action:");
		scanf("%s",atoio);
		acao = atoi(&atoio[0]);
		tamatoio = strlen(atoio);
		if (tamatoio == 1)
            switch (acao) {
                case 1: {
                    if (dexp >= dexm){
                        if (dexp >= rand()%300){
                            vidamob = vidamob - ataquep;
                            doge++;
                        }
                        else{
                            vidamob = vidamob - ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                    }
                    else{
                        if (dexm >= rand ()%300){
                            *hpa = *hpa - ataquem;
                            doge++;
                        }
                        else{
                            *hpa = *hpa - ataquem;
                            vidamob = vidamob - ataquep;
                        }
                    }
                    break;
                }
                case 2: {
                    if (dexp >= rand()%200){
                        crit++;
                        if (dexp >= dexm){
                            vidamob = vidamob - 2*ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                        else{
                            if (dexm >= rand ()%300){
                                *hpa = *hpa - ataquem;
                                doge++;
                            }
                            else {
                                *hpa = *hpa - ataquem;
                                vidamob = vidamob - 2*ataquep;
                            }
                        }
                    }
                    else {
                        if (dexp >= dexm){
                            vidamob = vidamob - ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                        else{
                            if (dexm >= rand ()%300){
                                *hpa = *hpa - ataquem;
                                doge++;
                            }
                            else{
                                *hpa = *hpa - ataquem;
                                vidamob = vidamob - 2*ataquep;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    defa++;
                    if (*hppot >= 1){
                        curou++;
                        if (*hpa+cura >= *hpmax){
                            cura = *hpmax - *hpa;
                            *hpa = *hpmax;
                            *hppot = *hppot -1;
                            def = ataquem/2;
                            *hpa = *hpa - (ataquem-def);
                        }
                        else{
                            *hpa = *hpa + cura;
                            *hppot = *hppot-1;
                            def = ataquem/2;
                            *hpa = *hpa - (ataquem-def);
                        }
                    }
                    else{
                        def = ataquem/2;
                        *hpa = *hpa - (ataquem-def);
                    }
                    break;
                }
            }
        }
    if (*hpa <= 0){
        *death = 1;
    }
    else{
        *win = 1;
    }
}

void mestre (Class *Personagem, int* nivel, int* gold, int* expa, int* expt,char* nome,Monsters Instrutores[],int *hpa, int *hpmax, int *hppot,int n){
    int niv = *nivel-1;
    char atoio[30];
    int tamatoio;
    int vidamob, vidamobmax;
    int cont = 0;
    int cura, def = 0, curou = 0, defa = 0, dexp, dexm, ataquep, ataquem;
    int doge = 0, crit = 0;
    vidamob = Instrutores[niv].con;
    vidamobmax = Instrutores[niv].con;
    int acao;
    while(vidamob > 0 && *hpa > 0){
		limpa();
		printf("%s%45s\n",nome,Instrutores[niv].nome);
		printf("HP: %d/%d%40d/%d\n",*hpa,*hpmax,vidamob,vidamobmax);
		printf("1. Ataque fraco\n2. Ataque forte (chance de critico, maior taxa de desvio do oponente)\n3. Defesa + Potion (%d)\n",*hppot);
		if (cont != 0 && tamatoio == 1 && acao >= 1 && acao <= 4){
            if (defa != 0 && curou > 0){
				printf ("%s se curou por %d e sofreu %d dano de %s\n",nome,cura,ataquem-def,Instrutores[niv].nome);
			}
			else if(defa != 0 && curou == 0){
				printf ("%s sofreu %d de dano de %s\n",nome,(ataquem-def),Instrutores[niv].nome);
			}
			else{
				if (doge == 1){
					if (crit == 1){
						printf ("%s causou %d de dano e desviou do ataque de %s\n",Instrutores[niv].nome,ataquem,nome);
					}
					else{
						if (dexp >= dexm){
							printf ("%s causou %d de dano e desviou do ataque de %s\n",nome,ataquep,Instrutores[niv].nome);
						}
						else{
							printf("%s causou %d de dano e desviou do ataque de %s\n",Instrutores[niv].nome,ataquem,nome);
						}
					}
				}
				else{
					if (crit == 1){
						printf("%s desferiu um ACERTO CRITICO e causou %d de dano\n%s causou %d de dano a %s\n",nome,2*ataquep,Instrutores[niv].nome,ataquem,nome);
					}
					else{
						printf("%s causou %d de dano e recebeu %d de dano de %s\n",nome,ataquep,ataquem,Instrutores[niv]
             );
					}
				}
			}
		}
		ataquep = rand()%(Personagem->str)+1;
		ataquem = rand()%(Instrutores[niv].str)+1;
		dexp = rand()%(Personagem->dex)+1;
		dexm = rand()%(Instrutores[niv].dex)+1;
		cont++;
		doge = 0;
		crit = 0;
		def = 0;
		defa = 0;
		curou = 0;
		printf("Action:");
		scanf("%s",atoio);
		acao = atoi(&atoio[0]);
		tamatoio = strlen(atoio);
		if (tamatoio == 1)
            switch (acao) {
                case 1: {
                    if (dexp >= dexm){
                        if (dexp >= rand()%300){
                            vidamob = vidamob - ataquep;
                            doge++;
                        }
                        else{
                            vidamob = vidamob - ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                    }
                    else{
                        if (dexm >= rand ()%300){
                            *hpa = *hpa - ataquem;
                            doge++;
                        }
                        else{
                            *hpa = *hpa - ataquem;
                            vidamob = vidamob - ataquep;
                        }
                    }
                    break;
                }
                case 2: {
                    if (dexp >= rand()%200){
                        crit++;
                        if (dexp >= dexm){
                            vidamob = vidamob - 2*ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                        else{
                            if (dexm >= rand ()%300){
                                *hpa = *hpa - ataquem;
                                doge++;
                            }
                            else {
                                *hpa = *hpa - ataquem;
                                vidamob = vidamob - 2*ataquep;
                            }
                        }
                    }
                    else {
                        if (dexp >= dexm){
                            vidamob = vidamob - ataquep;
                            if (vidamob > 0){
                                *hpa = *hpa - ataquem;
                            }
                        }
                        else{
                            if (dexm >= rand ()%300){
                                *hpa = *hpa - ataquem;
                                doge++;
                            }
                            else{
                                *hpa = *hpa - ataquem;
                                vidamob = vidamob - 2*ataquep;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    defa++;
                    if (*hppot >= 1){
                        curou++;
                        if (*hpa+cura >= *hpmax){
                            cura = *hpmax - *hpa;
                            *hpa = *hpmax;
                            *hppot = *hppot -1;
                            def = ataquem/2;
                            *hpa = *hpa - (ataquem-def);
                        }
                        else{
                            *hpa = *hpa + cura;
                            *hppot = *hppot-1;
                            def = ataquem/2;
                            *hpa = *hpa - (ataquem-def);
                        }
                    }
                    else{
                        def = ataquem/2;
                        *hpa = *hpa - (ataquem-def);
                    }
                    break;
                }
            }
        }
    if (*hpa <= 0){
        *hpa = 1;
        *expa = 0;
    }
    else{
        *gold = *gold + Instrutores[niv].gold;
        *expa = 0;
        *expt = (*expt)+*nivel*60;
        *nivel = *nivel + 1;
        limpa();
        vermelho();
        printf("\n\n\n\n\n\n\n\ndP                                   dP                      \n88                                   88                      \n88        .d8888b. dP   .dP .d8888b. 88    dP    dP 88d888b. \n88        88ooood8 88   d8' 88ooood8 88    88    88 88'  `88 \n88        88.  ... 88 .88'  88.  ... 88    88.  .88 88.  .88 \n88888888P `88888P' 8888P'   `88888P' dP    `88888P' 88Y888P' \n                                                    88       \n                                                    dP  \n");
        espera(1500);
        verde();
        incrementa(Personagem,n);
        *hpa = Personagem->con;
        *hpmax = Personagem->con;
    }
}

void incrementa (Class *Personagem,int n){
    srand(time(NULL));
    int strinc, dexinc, coninc;
    if (n == 1){
        strinc = rand()%6+1;
        dexinc = rand()%6+1;
        coninc = rand()%10+1;
        Personagem->str = Personagem->str + strinc;
        Personagem->dex = Personagem->dex + dexinc;
        Personagem->con = Personagem->con + coninc;
        limpa();
        amarelo();
        printf("STR aumentou em: %d\nDEX aumentou em: %d\nCON aumentou em: %d\n",strinc,dexinc,coninc);
        espera(1500);
        verde();
    }
    else if (n == 2){
        strinc = rand()%8+1;
        dexinc = rand()%8+1;
        coninc = rand()%8+1;
        Personagem->str = Personagem->str + strinc;
        Personagem->dex = Personagem->dex + dexinc;
        Personagem->con = Personagem->con + coninc;
        limpa();
        amarelo();
        printf("STR aumentou em: %d\nDEX aumentou em: %d\nCON aumentou em: %d\n",strinc,dexinc,coninc);
        espera(1500);
        verde();
    }
    else if (n == 3){
        strinc = rand()%6+2;
        dexinc = rand()%6+2;
        coninc = rand()%6+2;
        Personagem->str = Personagem->str + strinc;
        Personagem->dex = Personagem->dex + dexinc;
        Personagem->con = Personagem->con + coninc;
        limpa();
        amarelo();
        printf("STR aumentou em: %d\nDEX aumentou em: %d\nCON aumentou em: %d\n",strinc,dexinc,coninc);
        espera(1500);
        verde();
    }
    else if (n == 4){
        strinc = rand()%8+1;
        dexinc = rand()%12+1;
        coninc = rand()%4+1;
        Personagem->str = Personagem->str + strinc;
        Personagem->dex = Personagem->dex + dexinc;
        Personagem->con = Personagem->con + coninc;
        limpa();
        amarelo();
        printf("STR aumentou em: %d\nDEX aumentou em: %d\nCON aumentou em: %d\n",strinc,dexinc,coninc);
        espera(1500);
        verde();
    }
    else if (n == 5){
        strinc = rand()%10+1;
        dexinc = rand()%6+1;
        coninc = rand()%4+1;
        Personagem->str = Personagem->str + strinc;
        Personagem->dex = Personagem->dex + dexinc;
        Personagem->con = Personagem->con + coninc;
        limpa();
        amarelo();
        printf("STR aumentou em: %d\nDEX aumentou em: %d\nCON aumentou em: %d\n",strinc,dexinc,coninc);
        espera(1500);
        verde();
    }
}

void imprimemonasterio (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot){
    imprimechar(Personagem,nivel,nome,expa,expt,hpa,hpmax,gold,hppot);
    // Imprime o menu do monastério
    int preco = hpmax-hpa;
    printf("1. Curar: %d pecas de ouro\n", preco);
    printf("2. Comprar potion de vida: 75 pecas de ouro\n");
    printf("3. Sair\n");
    printf("Action:");
}

void monasterio(int *gold, int *hpa, int hpmax, int *hppot, int action){
    // Realiza as ações do monastério
    int preco;
    preco = hpmax-*hpa;
    if (action == 1 && *gold >= preco){
        *hpa = hpmax;
        *gold = *gold - preco;
    }
    if (action == 2 && *gold >= 75){
        *hppot = *hppot +1;
        *gold = *gold - 75;
    }
}

void imprimetreino (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot){
    imprimechar(Personagem,nivel,nome,expa,expt,hpa,hpmax,gold,hppot);
    // Imprime o menu do campo de treinamento
    int precofor = (3*Personagem.str)+5*nivel;
    int precodex = (2*Personagem.dex)+2*nivel;
    int precocon = (3*Personagem.con)+5*nivel;
    printf("1. Treinar STR: %d pecas de ouro\n2. Treinar DEX: %d pecas de ouro\n3. Treinar CON: %d pecas de ouro\n4. Sair\nAction:",precofor,precodex,precocon);
}

void treino (Class *Personagem, int nivel, int *gold, int action,int *hpc, int *hpmax){
    int precofor = (3*Personagem->str)+5*nivel;
    int precodex = (2*Personagem->dex)+2*nivel;
    int precocon = (3*Personagem->con)+5*nivel;
    if (action == 1 && *gold >= precofor){
        *gold = *gold - precofor;
        Personagem->str++;
    }
    if (action == 2 && *gold >= precodex){
        *gold = *gold - precodex;
        Personagem->dex++;
    }
    if (action == 3 && *gold >= precocon){
        *gold = *gold - precocon;
        Personagem->con++;
        *hpmax = *hpmax + 1;
        *hpc = *hpc + 1;
    }
}

void imprimeexplora (Class Personagem, int nivel, char* nome, int expa, int expt,int hpa,int hpmax, int gold, int hppot){
    imprimechar(Personagem,nivel,nome,expa,expt,hpa,hpmax,gold,hppot);
    printf("1. Explorar a clareira (Monstros mais fracos que o heroi)\n2. Explorar a floresta (Monstros do nivel do heroi)\n3. Explorar a ravina (Monstros mais fortes que o heroi)\n4. Sair\nAction:");
}

int batalha( Class *Personagem, int*gold, int *expa, int expt, char* nome, Monsters Monstros[][3],int niv, int j,int *hpa,int hpmax, int *hppot){
	int winner = 2;
	int cont = 0;
	int fuga = 0, falha = 0;
	int cura, def = 0, curou = 0, defa = 0;
	int dexp, dexm;
	int doge = 0, crit = 0; // Dodge
	int vidamob,vidamobmax;
	int ataquep, ataquem;
	char atoio[30];
	int acao, tamatoio;
	vidamobmax = Monstros[niv][j].con;
	vidamob = Monstros[niv][j].con;
	while(vidamob > 0 && *hpa > 0){
		limpa();
		printf("%s%45s\n",nome,Monstros[niv][j].nome);
		printf("HP: %d/%d%40d/%d\n",*hpa,hpmax,vidamob,vidamobmax);
		printf("1. Ataque fraco\n2. Ataque forte (chance de critico, maior taxa de desvio do oponente)\n3. Defesa + Potion (%d)\n4. Fugir\n",*hppot);
		if (cont != 0 && tamatoio == 1 && acao >= 1 && acao <= 4){
			if (falha != 0){
				printf ("%s sofreu %d de dano de %s\n",nome,ataquem,Monstros[niv][j].nome);
			}
			else if (defa != 0 && curou > 0){
				printf ("%s se curou por %d e sofreu %d dano de %s\n",nome,cura,ataquem-def,Monstros[niv][j].nome);
			}
			else if(defa != 0 && curou == 0){
				printf ("%s sofreu %d de dano de %s\n",nome,(ataquem-def),Monstros[niv][j].nome);
			}
			else{
				if (doge == 1){
					if (crit == 1){
						printf ("%s causou %d de dano e desviou do ataque de %s\n",Monstros[niv][j].nome,ataquem,nome);
					}
					else{
						if (dexp >= dexm){
							printf ("%s causou %d de dano e desviou do ataque de %s\n",nome,ataquep,Monstros[niv][j].nome);
						}
						else{
							printf("%s causou %d de dano e desviou do ataque de %s\n",Monstros[niv][j].nome,ataquem,nome);
						}
					}
				}
				else{
					if (crit == 1){
						printf("%s desferiu um ACERTO CRITICO e causou %d de dano\n%s causou %d de dano a %s\n",nome,2*ataquep,Monstros[niv][j].nome,ataquem,nome);
					}
					else{
						printf("%s causou %d de dano e recebeu %d de dano de %s\n",nome,ataquep,ataquem,Monstros[niv][j].nome);
					}
				}
			}
		}
		ataquep = rand()%(Personagem->str)+1;
		ataquem = rand()%(Monstros[niv][j].str)+1;
		dexp = rand()%(Personagem->dex)+1;
		dexm = rand()%(Monstros[niv][j].dex)+1;
		cont++;
		doge = 0;
		crit = 0;
		def = 0;
		defa = 0;
		curou = 0;
		falha = 0;
		printf("Action:");
		scanf("%s",atoio);
		acao = atoi(&atoio[0]);
		tamatoio = strlen(atoio);
		if (tamatoio == 1)
		switch (acao) {
			case 1: {
				if (dexp >= dexm){
					if (dexp >= rand()%300){
						vidamob = vidamob - ataquep;
						doge++;
					}
					else{
						vidamob = vidamob - ataquep;
						if (vidamob > 0){
							*hpa = *hpa - ataquem;
						}
					}
				}
				else{
					if (dexm >= rand ()%300){
						*hpa = *hpa - ataquem;
						doge++;
					}
					else{
						*hpa = *hpa - ataquem;
						vidamob = vidamob - ataquep;
					}
				}
				break;
			}
			case 2: {
				if (dexp >= rand()%200){
					crit++;
					if (dexp >= dexm){
						vidamob = vidamob - 2*ataquep;
						if (vidamob > 0){
							*hpa = *hpa - ataquem;
						}
					}
					else{
						if (dexm >= rand ()%300){
							*hpa = *hpa - ataquem;
							doge++;
						}
						else {
							*hpa = *hpa - ataquem;
							vidamob = vidamob - 2*ataquep;
						}
					}
				}
				else {
					if (dexp >= dexm){Monsters Monstros[10][3];
						vidamob = vidamob - ataquep;
						if (vidamob > 0){
							*hpa = *hpa - ataquem;
						}
					}
					else{
						if (dexm >= rand ()%300){
							*hpa = *hpa - ataquem;
							doge++;
						}
						else{
							*hpa = *hpa - ataquem;
							vidamob = vidamob - 2*ataquep;
						}
					}
				}
				break;
			}
			case 3: {
				defa++;
				if (*hppot >= 1){
					curou++;
					if (*hpa+cura >= hpmax){
						cura = hpmax - *hpa;
						*hpa = hpmax;
						*hppot = *hppot -1;
						def = ataquem/2;
						*hpa = *hpa - (ataquem-def);
					}
					else{
						*hpa = *hpa + cura;
						*hppot = *hppot-1;
						def = ataquem/2;
						*hpa = *hpa - (ataquem-def);
					}
				}
				else{
					def = ataquem/2;
					*hpa = *hpa - (ataquem-def);
				}
				break;
			}
			case 4: {
				if (dexp > dexm){
					fuga++;
				}
				else{
					falha++;
					*hpa = *hpa - ataquem;
				}
				break;
			}
		}
		if (fuga == 1){
			break;
		}
	}
	if (fuga != 1){
		if (vidamob <= 0){
			winner = 0;
			int goldm, expm;
			goldm = Monstros[niv][j].gold-rand()%(niv+1);
			expm = Monstros[niv][j].exp-rand()%(niv+1);
			*gold = *gold+goldm;
			*expa = *expa+expm;
			if (*expa > expt)
            *expa = expt;
			limpa();
			printf("%s%45s\n",nome,Monstros[niv][j].nome);
			printf("HP: %d/%d                                       0/%d\n",*hpa,hpmax,vidamobmax);
			printf("Voce coletou %d pecas de ouro e recebeu %d de experiencia",goldm,expm);
			espera(3500);
		}
		else {
			winner = 1;
		}
	}
	return winner;
}

void explora (int action,int nivel, Class *Personagem, int *gold, int *expa, int expt,char* nome,int *hpa, int hpmax, int *hppot, int *death) {
	int j;
	int res;
	int niv;
	j = rand()%3; // Randomizando qual dos monstros será escolhido,
	if (action == 1){
		if (nivel == 1){
			niv = nivel-1;
		}
		else{
			niv = nivel-2;
		}
		res = batalha(Personagem,gold,expa,expt,nome,Monstros,niv,j,hpa,hpmax,hppot);
	}
	if (action == 2){
		niv = nivel-1;
		res = batalha(Personagem,gold,expa,expt,nome,Monstros,niv,j,hpa,hpmax,hppot);
	}
	if (action == 3){
		if (nivel == 10){
			niv = nivel-1;
		}
		else{
			niv = nivel;
		}
		res = batalha(Personagem,gold,expa,expt,nome,Monstros,niv,j,hpa,hpmax,hppot);
	}
	if (res == 1){
		*death = *death + 1;
	}
}

int main () {
    inicializa();
    FILE *charac;
    FILE *goldsave;
    FILE *expasave;
    FILE *exptsave;
    FILE *nivelsave;
    FILE *tamsave;
    FILE *nomesave;
    FILE *hpasave;
    FILE *hptsave;
    FILE *potsave;


    int win = 0, death = 0; // Contadores que se incrementam se o personagem vencer o jogo ou morrer para terminar a execução do programa
    int hpc, hpmax, hppot = 0; // hpc = HP atual, hpmax = HP máximo, hppot = Potions de HP
    int menu, action; // Receber ações do jogador
	int expa = 0, expt = 40; // Exp inicial e exp para upar do nível 1, incrementadas mais na frente no programa
	int i, j; // Contadores para impressão
	int n, saveg; // Recebe classe do personagem
	char o[30], atoio[30];
	int gold, tam, nivel = 1, tamatoio; // Gold e nível inicial
	char nome[30];
	srand (time(NULL));
    amarelo(); // Cor amarela
    // A seguir vem a impressão da logo do jogo
    printf("'||'  |'   ||  '||  '||     |''||''| '||              \n || .'    ...   ||   ||        ||     || ..     ....  \n ||'|.     ||   ||   ||        ||     ||' ||  .|...|| \n ||  ||    ||   ||   ||        ||     ||  ||  ||      \n.||.  ||. .||. .||. .||.      .||.   .||. ||.  '|...' \n                                                      \n                                                      \n'||''|.                                               \n ||   ||  ... ..   ....     ... .   ...   .. ...      \n ||    ||  ||' '' '' .||   || ||  .|  '|.  ||  ||     \n ||    ||  ||     .|' ||    |''   ||   ||  ||  ||     \n.||...|'  .||.    '|..'|'  '||||.  '|..|' .||. ||.    \n                          .|....'                     \n");
    printf("\n----------------------------------------------------------\n\n'||''|.   '||    ||'     .|'''.|                          \n ||   ||   |||  |||      ||..  '   ....     ... .  ....   \n ||    ||  |'|..'||       ''|||.  '' .||   || ||  '' .||  \n ||    ||  | '|' ||     .     '|| .|' ||    |''   .|' ||  \n.||...|'  .|. | .||.    |'....|'  '|..'|'  '||||. '|..'|' \n                                          .|....' \n");
	espera(1500);
	verde();
	Class Personagem; // Structure com valores do personagem
	do{
        limpa();
        printf("1. New Game\n2. Load save\nOption:");
        scanf("%s",atoio);
        saveg = atoi(&atoio[0]);
        tamatoio = strlen(atoio);
	}while (saveg != 1 && saveg != 2 || tamatoio != 1);
	limpa();
	verde();
	if (saveg == 1){
        gold = 75;
        printf("Digite o nome de seu personagem, sem espacos: ");
        scanf ("%s", nome);
        tam = strlen(nome);
        do{
            limpa();
            printf("1dX equivale a rolagem (aleatoria) de um dado de X faces\nSTR influencia diretamente no seu ataque, ao atacar o dano e 1dSTR\nDEX influencia sua chance de critico (Ataque forte)\nInfluencia sua chance de dodge (Ataque fraco) e fuga\n");
            printf("CON equivale a sua vida\n");
            printf("\nSelecione uma classe\n1: Warrior (1d6 STR, 1d6 DEX, 1d10 CON)\n2: Archer (1d8 STR, 1d8 DEX, 1d8 CON)\n3: Adventurer (1d6+1 STR, 1d6+1 DEX, 1d6+1 CON)\n4: Rogue (1d8 STR, 1d12 DEX, 1d4 CON)\n5: Beserker (1d10 STR, 1d6 DEX, 1d4 CON)\nEscolha:");
            scanf("%s", o);
            n = atoi(&o[0]);
            tamatoio = strlen(o);
        }while (n != 1 && n != 2 && n != 3 && n != 4 && n != 5 || tamatoio != 1);
        Personagem = Classes[n-1];
        hpc = Personagem.con; // Valor inicial do HP
        hpmax = Personagem.con; // Valor inicial do HP
	}
	else if (saveg == 2){
        charac = fopen("per.bin","r+b");
        fread(&Personagem,sizeof(Class),1,charac);
        fclose(charac);
        goldsave = fopen("gold.bin","r+b");
        fread(&gold,sizeof(int),1,goldsave);
        fclose(goldsave);
        expasave = fopen("expa.bin","r+b");
        fread(&expa,sizeof(int),1,expasave);
        fclose(expasave);
        exptsave = fopen("expt.bin","r+b");
        fread(&expt,sizeof(int),1,exptsave);
        fclose(exptsave);
        nivelsave = fopen("nivel.bin","r+b");
        fread(&nivel,sizeof(int),1,nivelsave);
        fclose(nivelsave);
        tamsave = fopen("tam.bin","r+b");
        fread(&tam,sizeof(int),1,tamsave);
        fclose(tamsave);
        nomesave = fopen("nome.bin","r+b");
        fread(&nome,sizeof(char)*tam+1,1,nomesave);
        fclose(nomesave);
        hpasave = fopen("hpa.bin","r+b");
        fread(&hpc,sizeof(int)*tam,1,hpasave);
        fclose(hpasave);
        hptsave = fopen("hpt.bin","r+b");
        fread(&hpmax,sizeof(int)*tam,1,hptsave);
        fclose(hptsave);
        potsave = fopen("pot.bin","r+b");
        fread(&hppot,sizeof(int)*tam,1,potsave);
        fclose(potsave);
	}
    while (win == 0 && death == 0){ // Começa o jogo
        imprimemenu(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
        char menuo[30];
        int tammenu;
        scanf("%s", menuo);
        menu = atoi(&menuo[0]);
        tammenu = strlen(menuo);
        if (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5 || menu == 9 &&tammenu == 1){
            switch (menu) {
                case 1: {
                    imprimemonasterio(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                    scanf("%s", atoio);
                    action = atoi(&atoio[0]);
                    tamatoio = strlen(atoio);
                    if (tamatoio == 1)
                    monasterio(&gold,&hpc,hpmax,&hppot,action);
                    while(tamatoio != 1 || action != 3){
                        imprimemonasterio(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                        scanf("%s", atoio);
                        action = atoi(&atoio[0]);
                        tamatoio = strlen(atoio);
                        if (tamatoio == 1)
                        monasterio(&gold,&hpc,hpmax,&hppot,action);
                    }
                    break;
                }
                case 2: {
                    imprimetreino(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                    scanf("%s", atoio);
                    action = atoi(&atoio[0]);
                    tamatoio = strlen(atoio);
                    if (tamatoio == 1)
                    treino(&Personagem,nivel,&gold,action,&hpc,&hpmax);
                    while(tamatoio != 1 || action != 4){
                        imprimetreino(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                        scanf("%s", atoio);
                        action = atoi(&atoio[0]);
                        tamatoio = strlen(atoio);
                        if (tamatoio == 1)
                        treino(&Personagem,nivel,&gold,action,&hpc,&hpmax);

                    }
                    break;
                }
                case 3: {
                    imprimeexplora(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                    scanf("%s", atoio);
                    action = atoi(&atoio[0]);
                    tamatoio = strlen(atoio);
                    if (tamatoio == 1)
                    explora(action,nivel,&Personagem,&gold,&expa,expt,nome,&hpc,hpmax,&hppot,&death);
                    while(tamatoio != 1 && death == 0 || action != 4){
                        imprimeexplora(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                        scanf("%s", atoio);
                        action = atoi(&atoio[0]);
                        tamatoio = strlen(atoio);
                        if (tamatoio == 1)
                        explora(action,nivel,&Personagem,&gold,&expa,expt,nome,&hpc,hpmax,&hppot,&death);
                        if (death > 0){
                        break;
                        }
                    }
                    break;
                }
                case 4: {
                    if (expa >= expt){
                        imprimemestre(Personagem,nivel,nome,expa,expt,hpc,hpmax,gold,hppot);
                        scanf("%d", &action);
                        mestre(&Personagem,&nivel,&gold,&expa,&expt,nome,Instrutores,&hpc,&hpmax,&hppot,n);
                    }
                    break;
                }
                case 5: {
                    if (expa >= expt){
                        boss(&Personagem,nome, Eenlucifer, &hpc, &hpmax, &hppot, n, &win, &death);
                    }
                }
                case 9: {
                    charac = fopen("per.bin","w+b");
                    fwrite(&Personagem,sizeof(Class),1,charac);
                    fclose(charac);
                    goldsave = fopen("gold.bin","w+b");
                    fwrite(&gold,sizeof(int),1,goldsave);
                    fclose(goldsave);
                    expasave = fopen("expa.bin","w+b");
                    fwrite(&expa,sizeof(int),1,expasave);
                    fclose(expasave);
                    exptsave = fopen("expt.bin","w+b");
                    fwrite(&expt,sizeof(int),1,exptsave);
                    fclose(exptsave);
                    nivelsave = fopen("nivel.bin","w+b");
                    fwrite(&nivel,sizeof(int),1,nivelsave);
                    fclose(nivelsave);
                    tamsave = fopen("tam.bin","w+b");
                    fwrite(&tam,sizeof(int),1,tamsave);
                    fclose(tamsave);
                    nomesave = fopen("nome.bin","w+b");
                    fwrite(&nome,sizeof(char)*tam+1,1,nomesave);
                    fclose(nomesave);
                    hpasave = fopen("hpa.bin","w+b");
                    fwrite(&hpc,sizeof(int)*tam,1,hpasave);
                    fclose(hpasave);
                    hptsave = fopen("hpt.bin","w+b");
                    fwrite(&hpmax,sizeof(int)*tam,1,hptsave);
                    fclose(hptsave);
                    potsave = fopen("pot.bin","w+b");
                    fwrite(&hppot,sizeof(int)*tam,1,potsave);
                    fclose(potsave);
                    printf("\nSaved Game");
                    espera(500);
                    break;
                }
            }
        }
    }
    if (death > 0){
    	limpa();
    	vermelho();
    	printf("                                                                   \n             _____ _____ _____ _____ _____ _____ _____ ____  _____ \n            | __  |   __|  _  | __  |     |  |  |  _  |    \\|     |\n            |    -|   __|   __|    -|  |  |  |  |     |  |  |  |  |\n            |__|__|_____|__|  |__|__|_____|\\___/|__|__|____/|_____|\n");
    }
    if (win > 0){
    	limpa();
    	vermelho();
    	printf("ooooo  oooo ooooooo  ooooo  oooo  oooo     oooo ooooo oooo   oooo \n  888  88 o888   888o 888    88    88   88  88   888   8888o  88  \n    888   888     888 888    88     88 888 88    888   88 888o88  \n    888   888o   o888 888    88      888 888     888   88   8888  \n   o888o    88ooo88    888oo88        8   8     o888o o88o    88  \n");
    }
	return 0;
}

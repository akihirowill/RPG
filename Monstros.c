#include "rpg.h"

 extern Monsters Monstros[10][3];
 extern Monsters Instrutores[9];
 extern Monsters Eenlucifer;
 extern Class Classes[5];

void inicializa(){
		Monstros[0][0].nome = "Rat";
		Monstros[0][0].str  = 3;
		Monstros[0][0].dex  = 5;
		Monstros[0][0].con  = 6;
		Monstros[0][0].gold = 6;
		Monstros[0][0].exp  = 9;
		// Bat
		Monstros[0][1].nome = "Bat";
		Monstros[0][1].str  = 2;
		Monstros[0][1].dex  = 5;
		Monstros[0][1].con  = 8;
		Monstros[0][1].gold = 5;
		Monstros[0][1].exp  = 8;
		// Slime
		Monstros[0][2].nome = "Slime";
		Monstros[0][2].str  = 2;
		Monstros[0][2].dex  = 7;
		Monstros[0][2].con  = 7;
		Monstros[0][2].gold = 6;
		Monstros[0][2].exp  = 10;
		// Spider
		Monstros[1][0].nome = "Spider";
		Monstros[1][0].str  = 5;
		Monstros[1][0].dex  = 9;
		Monstros[1][0].con  = 10;
		Monstros[1][0].gold = 11;
		Monstros[1][0].exp  = 12;
		// Racoon
		Monstros[1][1].nome = "Racoon";
		Monstros[1][1].str  = 6;
		Monstros[1][1].dex  = 5;
		Monstros[1][1].con  = 10;
		Monstros[1][1].gold = 13;
		Monstros[1][1].exp  = 14;
		// Hound
		Monstros[1][2].nome = "Hound";
		Monstros[1][2].str  = 7;
		Monstros[1][2].dex  = 8;
		Monstros[1][2].con  = 8;
		Monstros[1][2].gold = 12;
		Monstros[1][2].exp  = 15;
		// Wolf
		Monstros[2][0].nome = "Wolf";
		Monstros[2][0].str  = 10;
		Monstros[2][0].dex  = 12;
		Monstros[2][0].con  = 10;
		Monstros[2][0].gold = 15;
		Monstros[2][0].exp  = 18;
		// Bear
		Monstros[2][1].nome = "Bear";
		Monstros[2][1].str  = 6;
		Monstros[2][1].dex  = 5;
		Monstros[2][1].con  = 17;
		Monstros[2][1].gold = 18;
		Monstros[2][1].exp  = 20;
		// Rhino
		Monstros[2][2].nome = "Rhino";
		Monstros[2][2].str  = 7;
		Monstros[2][2].dex  = 10;
		Monstros[2][2].con  = 14;
		Monstros[2][2].gold = 16;
		Monstros[2][2].exp  = 20;
		// Giant Bee
		Monstros[3][0].nome = "Giant Bee";
		Monstros[3][0].str  = 8;
		Monstros[3][0].dex  = 10;
		Monstros[3][0].con  = 18;
		Monstros[3][0].gold = 18;
		Monstros[3][0].exp  = 25;
		// Burglar
		Monstros[3][1].nome = "Burglar";
		Monstros[3][1].str  = 10;
		Monstros[3][1].dex  = 14;
		Monstros[3][1].con  = 15;
		Monstros[3][1].gold = 21;
		Monstros[3][1].exp  = 27;
		// Ghoul
		Monstros[3][2].nome = "Ghoul";
		Monstros[3][2].str  = 9;
		Monstros[3][2].dex  = 8;
		Monstros[3][2].con  = 20;
		Monstros[3][2].gold = 20;
		Monstros[3][2].exp  = 27;
		// Mummy
		Monstros[4][0].nome = "Mummy";
		Monstros[4][0].str  = 11;
		Monstros[4][0].dex  = 12;
		Monstros[4][0].con  = 23;
		Monstros[4][0].gold = 25;
		Monstros[4][0].exp  = 33;
		// Imp
		Monstros[4][1].nome = "Imp";
		Monstros[4][1].str  = 10;
		Monstros[4][1].dex  = 16;
		Monstros[4][1].con  = 20;
		Monstros[4][1].gold = 22;
		Monstros[4][1].exp  = 35;
		// Succubus
		Monstros[4][2].nome = "Succubus";
		Monstros[4][2].str  = 11;
		Monstros[4][2].dex  = 14;
		Monstros[4][2].con  = 21;
		Monstros[4][2].gold = 24;
		Monstros[4][2].exp  = 35;
		// Ifrit
		Monstros[5][0].nome = "Ifrit";
		Monstros[5][0].str  = 13;
		Monstros[5][0].dex  = 20;
		Monstros[5][0].con  = 25;
		Monstros[5][0].gold = 30;
		Monstros[5][0].exp  = 45;
		// Mephit
		Monstros[5][1].nome = "Mephit";
		Monstros[5][1].str  = 12;
		Monstros[5][1].dex  = 20;
		Monstros[5][1].con  = 22;
		Monstros[5][1].gold = 29;
		Monstros[5][1].exp  = 45;
		// Troll
		Monstros[5][2].nome = "Troll";
		Monstros[5][2].str  = 12;
		Monstros[5][2].dex  = 23;
		Monstros[5][2].con  = 20;
		Monstros[5][2].gold = 37;
		Monstros[5][2].exp  = 48;
		// Orc
		Monstros[6][0].nome = "Orc";
		Monstros[6][0].str  = 16;
		Monstros[6][0].dex  = 30;
		Monstros[6][0].con  = 25;
		Monstros[6][0].gold = 43;
		Monstros[6][0].exp  = 60;
		// Drow Archer
		Monstros[6][1].nome = "Drow Archer";
		Monstros[6][1].str  = 13;
		Monstros[6][1].dex  = 40;
		Monstros[6][1].con  = 20;
		Monstros[6][1].gold = 50;
		Monstros[6][1].exp  = 55;
		// Minotaur
		Monstros[6][2].nome = "Minotaur";
		Monstros[6][2].str  = 14;
		Monstros[6][2].dex  = 25;
		Monstros[6][2].con  = 30;
		Monstros[6][2].gold = 60;
		Monstros[6][2].exp  = 55;
		// Beholder
		Monstros[7][0].nome = "Beholder";
		Monstros[7][0].str  = 22;
		Monstros[7][0].dex  = 35;
		Monstros[7][0].con  = 20;
		Monstros[7][0].gold = 70;
		Monstros[7][0].exp  = 70;
		// Worg
		Monstros[7][1].nome = "Worg";
		Monstros[7][1].str  = 18;
		Monstros[7][1].dex  = 45;
		Monstros[7][1].con  = 22;
		Monstros[7][1].gold = 65;
		Monstros[7][1].exp  = 85;
		// Vampire
		Monstros[7][2].nome = "Vampire";
		Monstros[7][2].str  = 16;
		Monstros[7][2].dex  = 35;
		Monstros[7][2].con  = 35;
		Monstros[7][2].gold = 80;
		Monstros[7][2].exp  = 60;
		// Lich
		Monstros[8][0].nome = "Lich";
		Monstros[8][0].str  = 22;
		Monstros[8][0].dex  = 45;
		Monstros[8][0].con  = 30;
		Monstros[8][0].gold = 80;
		Monstros[8][0].exp  = 80;
		// Frost Giant
		Monstros[8][1].nome = "Frost Giant";
		Monstros[8][1].str  = 25;
		Monstros[8][1].dex  = 20;
		Monstros[8][1].con  = 35;
		Monstros[8][1].gold = 95;
		Monstros[8][1].exp  = 95;
		// Fire Elemental
		Monstros[8][2].nome = "Fire Elemental";
		Monstros[8][2].str  = 20;
		Monstros[8][2].dex  = 38;
		Monstros[8][2].con  = 40;
		Monstros[8][2].gold = 65;
		Monstros[8][2].exp  = 120;
		// Green Dragon
		Monstros[9][0].nome = "Iron Giant";
		Monstros[9][0].str  = 28;
		Monstros[9][0].dex  = 50;
		Monstros[9][0].con  = 45;
		Monstros[9][0].gold = 120;
		Monstros[9][0].exp  = 130;
		// Archangel
		Monstros[9][1].nome = "Archangel";
		Monstros[9][1].str  = 26;
		Monstros[9][1].dex  = 55;
		Monstros[9][1].con  = 50;
		Monstros[9][1].gold = 130;
		Monstros[9][1].exp  = 125;
		// Hydra
		Monstros[9][2].nome = "Hydra";
		Monstros[9][2].str  = 26;
		Monstros[9][2].dex  = 45;
		Monstros[9][2].con  = 60;
		Monstros[9][2].gold = 120;
		Monstros[9][2].exp  = 140;
	//MONSTROS

	//CLASSES
	Classes[0] = (Class){1, "Warrior", (2+rand()%6+1), (5+rand()%6+1), (3+rand()%10+1)};
    Classes[1] = (Class){2, "Archer", (2+rand()%8+1), (5+rand()%8+1), (3+rand()%8+1)};
	Classes[2] = (Class){3, "Adventurer", (2+rand()%6+2), (5+rand()%6+2), (3+rand()%6+2)};
	Classes[3] = (Class){4, "Rogue", (2+rand()%8+1), (5+rand()%12+1), (3+rand()%4+1)};
	Classes[4] = (Class){5, "Beserker", (2+rand()%10+1), (5+rand()%6+1), (3+rand()%4+1)};
	//CLASSES

	//MESTRES
	// Bola
	    Instrutores[0].nome = "PiErre";
	    Instrutores[0].str  = 3;
	    Instrutores[0].dex  = 7;
	    Instrutores[0].con  = 8;
	    Instrutores[0].gold = 12;
	    Instrutores[0].exp  = 0;
	    // Sadao
	    Instrutores[1].nome = "Sadao";
	    Instrutores[1].str  = 7;
	    Instrutores[1].dex  = 9;
	    Instrutores[1].con  = 10;
	    Instrutores[1].gold = 26;
	    Instrutores[1].exp  = 0;
	    // Moura
	    Instrutores[2].nome = "Moura";
	    Instrutores[2].str  = 10;
	    Instrutores[2].dex  = 12;
	    Instrutores[2].con  = 14;
	    Instrutores[2].gold = 36;
	    Instrutores[2].exp  = 0;
	    // Maisa
	    Instrutores[3].nome = "Maisa";
	    Instrutores[3].str  = 10;
	    Instrutores[3].dex  = 14;
	    Instrutores[3].con  = 18;
	    Instrutores[3].gold = 50;
	    Instrutores[3].exp  = 0;
	    // Sandra
	    Instrutores[4].nome = "Sandra";
	    Instrutores[4].str  = 11;
	    Instrutores[4].dex  = 16;
	    Instrutores[4].con  = 23;
	    Instrutores[4].gold = 60;
	    Instrutores[4].exp  = 0;
	    // Marcela
	    Instrutores[5].nome = "Marcela";
	    Instrutores[5].str  = 13;
	    Instrutores[5].dex  = 23;
	    Instrutores[5].con  = 25;
	    Instrutores[5].gold = 74;
	    Instrutores[5].exp  = 0;
	    // Augusto
	    Instrutores[6].nome = "Augustus";
	    Instrutores[6].str  = 16;
	    Instrutores[6].dex  = 30;
	    Instrutores[6].con  = 30;
	    Instrutores[6].gold = 120;
	    Instrutores[6].exp  = 0;
	    // Estevam
	    Instrutores[7].nome = "Estevam";
	    Instrutores[7].str  = 20;
	    Instrutores[7].dex  = 45;
	    Instrutores[7].con  = 35;
	    Instrutores[7].gold = 160;
	    Instrutores[7].exp  = 0;
	    // Delano
	    Instrutores[8].nome = "Olaned";
	    Instrutores[8].str  = 25;
	    Instrutores[8].dex  = 45;
	    Instrutores[8].con  = 40;
	    Instrutores[8].gold = 190;
	    Instrutores[8].exp  = 0;
	    // MESTRES

	    //Eenlucifer
		Eenlucifer.nome = "Eenlucifer";
		Eenlucifer.str  = 35;
		Eenlucifer.dex  = 70;
		Eenlucifer.con  = 80;
		Eenlucifer.gold = 999;
		Eenlucifer.exp  = 999;
}


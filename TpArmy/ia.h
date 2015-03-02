#pragma once

/*
	L’intelligence artificielle est un facteur qui :  ­ 

		prend trois paramètres  : une unité, son armée, l’armée adverse.­ 
		retourne une action à effectuer  : ­ action de type shoot  : peut fournir l’id de la cible sur laquelle tirer  ­ 
		action de type move  : peut fournir la position vers laquelle se déplacer
    
	Il vous est demander de pouvoir créer l’IA suivante  : 
		● si on ne peut pas tirer, il faut se mettre hors de portée des ennemis  
		● si on peut tirer on choisit sa cible  
			○ si la cible est a portée, On tir dessus  
			○ sinon, on se rapproche de la cible 

	Ce qui va “customiser” votre IA est le choix de la cible  :

	pour toutes les capacités, ainsi que la  distance à l’unité courante on pourra choisir de prendre pour cible l’unité ennemie ayant la  plus grande ou la plus petite valeur.

	Chaque IA possible grâce à ces combinaisons se verra attribuer un code de deux caractères : 
		● la première correspondant à si on choisi la cible avec la plus grande valeur (“H”) ou la  plus petite (“L”)  
		● la seconde correspond a l’indice de la capacité choisie, ou à D dans le cas ou on  choisi la distance comme critère.

	Des exemples de ciblages possibles (avec leur code entre parenthèse) : 
		● l’ennemi le plus proche (LD)  
		● l’ennemi qui a le plus de tours a attendre avant son prochain tir (H6)  
		● l’ennemi qui a le moins de vie (L1)  
		● l’ennemi qui peut faire le plus de dommages (H4)
*/

class ia
{
public:
	ia();
	~ia();
};



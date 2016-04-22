; conversion.asm
;
; MI01 - TP Assembleur 1
;
; Affiche un nombre de 32 bits sous forme lisible

TITLE conversion.asm

.686
.MODEL FLAT, C

EXTERN      putchar:NEAR
EXTERN      getchar:NEAR

.DATA

nombre      dd      -821         ; Nombre à convertir
chaine      db      10 dup(?)       ; Remplacer xx par la longueur maximale n de la chaîne

.CODE

; Sous-programme main, automatiquement appelé par le code de
; démarrage 'C'
PUBLIC      main
main		PROC

			push eax					; sauvegarde des registres
			push ebx
			push ecx
			push edx
			
			mov eax,[nombre]		; nombre dans eax
			lea ebx,[chaine]		; adresse de chaine dans ebx
			mov ecx,10				; On effectuera des divisions par 10

			cmp eax, 0
			jns boucle				; si eax est positif on va à la boucle de conversion

			;Rendu à ce point, le nombre est considéré comme négatif

			mov eax,'-'			;On ajoute et on affiche le caractère "-"
			push eax
			call putchar
			add esp,4

			mov eax,[nombre]		; on remet nombre dans eax car putchar modifie eax
			neg eax					; On inverse le nombre
boucle:

			xor edx,edx				; mise à 0 du registre
			div ecx					; On effectue la divison : le reste sera dans edx et le quotient dans eax
			add edx,'0'
			mov [ebx],edx			;On déplace le caractère (reste de divison) dans la chaine
			
			inc ebx					; on incrémente la position courante de la chaine
			
			cmp eax,0				; test si eax = 0

			jne boucle				; alors la conversion est fini. sinon on reboucle

			lea esi,[chaine]		; on recupere l'adresse de début de chaine
			
			dec ebx					; on decremente ebx pour qu'il corresponde à l'adresse du dernier caractère de chaine

	
	; On réutilise le code de la question précédente
suivant:

			mov eax,[ebx]			; on parcours la chaine grace a l'adresse dans ebx	

			push eax				; Affichage			
			call putchar			
			add esp,4

			dec ebx 				; on décrémente notre compteur

			cmp esi,ebx				; on compare l'adresse de ebx et celle de chaine

			jbe suivant				; Tant que notre compteur est supérieur on continue
			
			call getchar
			
			pop edx					; on restaure les registres
			pop ecx
			pop ebx
			pop eax	

			ret
			
main        ENDP

END
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

nombre      dd      -821         ; Nombre � convertir
chaine      db      10 dup(?)       ; Remplacer xx par la longueur maximale n de la cha�ne

.CODE

; Sous-programme main, automatiquement appel� par le code de
; d�marrage 'C'
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
			jns boucle				; si eax est positif on va � la boucle de conversion

			;Rendu � ce point, le nombre est consid�r� comme n�gatif

			mov eax,'-'			;On ajoute et on affiche le caract�re "-"
			push eax
			call putchar
			add esp,4

			mov eax,[nombre]		; on remet nombre dans eax car putchar modifie eax
			neg eax					; On inverse le nombre
boucle:

			xor edx,edx				; mise � 0 du registre
			div ecx					; On effectue la divison : le reste sera dans edx et le quotient dans eax
			add edx,'0'
			mov [ebx],edx			;On d�place le caract�re (reste de divison) dans la chaine
			
			inc ebx					; on incr�mente la position courante de la chaine
			
			cmp eax,0				; test si eax = 0

			jne boucle				; alors la conversion est fini. sinon on reboucle

			lea esi,[chaine]		; on recupere l'adresse de d�but de chaine
			
			dec ebx					; on decremente ebx pour qu'il corresponde � l'adresse du dernier caract�re de chaine

	
	; On r�utilise le code de la question pr�c�dente
suivant:

			mov eax,[ebx]			; on parcours la chaine grace a l'adresse dans ebx	

			push eax				; Affichage			
			call putchar			
			add esp,4

			dec ebx 				; on d�cr�mente notre compteur

			cmp esi,ebx				; on compare l'adresse de ebx et celle de chaine

			jbe suivant				; Tant que notre compteur est sup�rieur on continue
			
			call getchar
			
			pop edx					; on restaure les registres
			pop ecx
			pop ebx
			pop eax	

			ret
			
main        ENDP

END
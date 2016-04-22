; hello1.asm
;
; MI01 - TP Assembleur 1
;
; Affiche une cha�ne de caract�res � l'�cran

TITLE hello1.asm

.686
.MODEL FLAT, C

EXTERN      putchar:NEAR
EXTERN      getchar:NEAR

.DATA

; Ajoutez les variables msg et longueur ici
msg			DB	"Hello World!"
longueur	DD	12

.CODE

; Sous-programme main, automatiquement appel� par le code de
; d�marrage 'C'
PUBLIC      main
main        PROC

            push    ebx             ; Sauvegarde pour le code 'C'
			; Met la valeur de ebx dans la pile
			
			mov ebx, [longueur]
			lea esi, [msg+ebx]
			; esi contient l'adresse du dernier caract�re
			
            neg ebx
            ; ebx contient -12
            
            ; On suppose que la longueur de la cha�ne est non nulle
            ; => pas de test de la condition d'arr�t au d�part
suivant:    movzx   eax, byte ptr[ebx + esi]
			; on met le premier caract�re de notre string dans eax

            ; Pr�paration de l'appel � la fonction de
            ; biblioth�que 'C' putchar(int c) pour afficher
            ; un caract�re. La taille du type C int est de
            ; 32 bits sur IA-32. Le caract�re doit �tre fourni
            ; sur la pile. Cf cours sur les sous-programmes.
            push    eax             ; Caract�re � afficher
            ; Met la valeur de eax dans la pile
            
            call    putchar         ; Appel de putchar
            ; Affiche sur la console la valeur du sommet de la pile
            
            add     esp, 4          ; Nettoyage de la pile apr�s appel
            ; On d�cale le pointeur de sommet de pile
            
            ; Fin de l'appel � putchar

            inc     ebx             ; Caract�re suivant
            ; Incr�mente ebx de 1
            
            jnz     suivant         ; si non, passer au suivant
            ; Si pas �gaux on saute � l'�tiquette 'suivant'

            call    getchar         ; Attente de l'appui sur "Entr�e"
            pop     ebx
            ; Depile la pile et mets l'�l�ment dans ebx

            ret                     ; Retour au code de d�marrage 'C'

main        ENDP

            END
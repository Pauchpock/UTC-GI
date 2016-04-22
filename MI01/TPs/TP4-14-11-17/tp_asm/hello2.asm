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
msg			DB	"bonjour tout le monde", 0
; 0 sera en fin de chaine msg

.CODE

; Sous-programme main, automatiquement appel� par le code de
; d�marrage 'C'
PUBLIC      main
main        PROC

            push    ebx             ; Sauvegarde pour le code 'C'
			; Met la valeur de ebx dans la pile
			
            mov     ebx, 0
            ; ebx <- 0 car ebx va servir de compteur

            ; On suppose que la longueur de la cha�ne est non nulle
            ; => pas de test de la condition d'arr�t au d�part
suivant:    movzx   eax, byte ptr[ebx + msg]
			; on met le premier caract�re de notre string dans eax

            ; Pr�paration de l'appel � la fonction de
            ; biblioth�que 'C' putchar(int c) pour afficher
            ; un caract�re. La taille du type C int est de
            ; 32 bits sur IA-32. Le caract�re doit �tre fourni
            ; sur la pile. Cf cours sur les sous-programmes.
            cmp	eax, 0
            
            jz	fin
            
            push    eax             ; Caract�re � afficher
            ; Met la valeur de eax dans la pile
            
            call    putchar         ; Appel de putchar
            ; Affiche sur la console la valeur du sommet de la pile
            
            add     esp, 4          ; Nettoyage de la pile apr�s appel
            ; On d�cale le pointeur de sommet de pile
            
            ; Fin de l'appel � putchar

            inc     ebx
            jmp     suivant

fin:         call    getchar
            pop     ebx

            ret

main        ENDP

            END
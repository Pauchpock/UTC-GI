; programme.asm
;
; MI01 - TP Assembleur 1
;
; Affiche un caract�re � l'�cran

TITLE programme.asm

.686
.MODEL FLAT, C

EXTERN      putchar:NEAR
EXTERN      getchar:NEAR

.DATA

cara        DB  'A'  ; On "d�clare" une �tiquette m�moire qui pointe sur le caract�re A


.CODE

; Sous-programme main, automatiquement appel� par le code de
; d�marrage 'C'

PUBLIC      main
main        PROC

            ; Conversion du caract�re en un double mot
            movzx   eax, byte ptr[cara]

            ; Pr�paration de l'appel � la fonction de
            ; biblioth�que 'C' putchar(int c) pour afficher
            ; un caract�re. La taille du type C int est de
            ; 32 bits sur IA-32. Le caract�re doit �tre fourni
            ; sur la pile.

            push    eax         ; Caract�re � afficher
            call    putchar     ; Appel de putchar (fonction C qui va r�aliser l'affichage d'un caract�re)
            add     esp, 4      ; Nettoyage de la pile apr�s appel
            ; Fin de l'appel � putchar

            call    getchar     ; Attente de l'appui sur "Entr�e"

            ret                 ; Retour au code de d�marrage 'C'

main        ENDP

            END
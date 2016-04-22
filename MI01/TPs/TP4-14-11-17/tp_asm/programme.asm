; programme.asm
;
; MI01 - TP Assembleur 1
;
; Affiche un caractère à l'écran

TITLE programme.asm

.686
.MODEL FLAT, C

EXTERN      putchar:NEAR
EXTERN      getchar:NEAR

.DATA

cara        DB  'A'  ; On "déclare" une étiquette mémoire qui pointe sur le caractère A


.CODE

; Sous-programme main, automatiquement appelé par le code de
; démarrage 'C'

PUBLIC      main
main        PROC

            ; Conversion du caractère en un double mot
            movzx   eax, byte ptr[cara]

            ; Préparation de l'appel à la fonction de
            ; bibliothèque 'C' putchar(int c) pour afficher
            ; un caractère. La taille du type C int est de
            ; 32 bits sur IA-32. Le caractère doit être fourni
            ; sur la pile.

            push    eax         ; Caractère à afficher
            call    putchar     ; Appel de putchar (fonction C qui va réaliser l'affichage d'un caractère)
            add     esp, 4      ; Nettoyage de la pile après appel
            ; Fin de l'appel à putchar

            call    getchar     ; Attente de l'appui sur "Entrée"

            ret                 ; Retour au code de démarrage 'C'

main        ENDP

            END
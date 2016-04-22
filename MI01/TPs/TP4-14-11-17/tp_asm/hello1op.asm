; hello1.asm
;
; MI01 - TP Assembleur 1
;
; Affiche une chaîne de caractères à l'écran

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

; Sous-programme main, automatiquement appelé par le code de
; démarrage 'C'
PUBLIC      main
main        PROC

            push    ebx             ; Sauvegarde pour le code 'C'
			; Met la valeur de ebx dans la pile
			
			mov ebx, [longueur]
			lea esi, [msg+ebx]
			; esi contient l'adresse du dernier caractère
			
            neg ebx
            ; ebx contient -12
            
            ; On suppose que la longueur de la chaîne est non nulle
            ; => pas de test de la condition d'arrêt au départ
suivant:    movzx   eax, byte ptr[ebx + esi]
			; on met le premier caractère de notre string dans eax

            ; Préparation de l'appel à la fonction de
            ; bibliothèque 'C' putchar(int c) pour afficher
            ; un caractère. La taille du type C int est de
            ; 32 bits sur IA-32. Le caractère doit être fourni
            ; sur la pile. Cf cours sur les sous-programmes.
            push    eax             ; Caractère à afficher
            ; Met la valeur de eax dans la pile
            
            call    putchar         ; Appel de putchar
            ; Affiche sur la console la valeur du sommet de la pile
            
            add     esp, 4          ; Nettoyage de la pile après appel
            ; On décale le pointeur de sommet de pile
            
            ; Fin de l'appel à putchar

            inc     ebx             ; Caractère suivant
            ; Incrémente ebx de 1
            
            jnz     suivant         ; si non, passer au suivant
            ; Si pas égaux on saute à l'étiquette 'suivant'

            call    getchar         ; Attente de l'appui sur "Entrée"
            pop     ebx
            ; Depile la pile et mets l'élément dans ebx

            ret                     ; Retour au code de démarrage 'C'

main        ENDP

            END
; IMAGE.ASM
;
; MI01 - TP Assembleur 2 à 5
;
; Réalise le traitement d'une image 32 bits.

.686
.MODEL FLAT, C

.DATA

.CODE

; **********************************************************************
; Sous-programme _process_image_asm
;
; Réalise le traitement d'une image 32 bits.
;
; Entrées sur la pile : Largeur de l'image (entier 32 bits)
;           Hauteur de l'image (entier 32 bits)
;           Pointeur sur l'image source (dépl. 32 bits)
;           Pointeur sur l'image tampon 1 (dépl. 32 bits)
;           Pointeur sur l'image tampon 2 (dépl. 32 bits)
;           Pointeur sur l'image finale (dépl. 32 bits)
; **********************************************************************
PUBLIC      process_image_asm
process_image_asm   PROC NEAR       ; Point d'entrée du sous programme

        push    ebp			; construction du cadre de pile (sauvegarde de ebp)
        mov     ebp, esp	; sauvegarde du pointeur de pile

		; SAUVEGARDE DES REGISTRES
        push    ebx
        push    esi	; image source
        push    edi	; image tmp1

		; multiplication de la largeur de l'image par la hauteur
        mov     ecx, [ebp + 8]
        imul    ecx, [ebp + 12]

        mov     esi, [ebp + 16] ; esi = image source (adresse du premier pixel de l'image)
        mov     edi, [ebp + 20] ; edi = image tmp1

        ;*****************************************************************
        ;*****************************************************************
        ; Ajoutez votre code ici
        ;*****************************************************************
        ;*****************************************************************
			  dec ecx
		    imul ecx,4

boucle: 
    movzx ebx, byte ptr [esi+ecx] ; on stocke la valeur du bleu
    imul ebx, 29d ; 0.114*256
    mov eax,ebx

    movzx ebx, byte ptr [esi+ecx+1] ; on stocke la valeur du vert
    imul ebx, 150d ; 0.587*256
    add eax,ebx

    movzx ebx, byte ptr [esi+ecx+2] ; on stocke la valeur du rouge
    imul ebx, 77d ; 0.299*256
    add eax,ebx
    shr eax,8

	; VRAI NOIR ET BLANC
    ;mov ah,al
    ;shl eax,8
    ;mov al,ah

	; PASSAGE EN ROUGE
	;shl eax, 16

    mov [edi+ecx], eax ; on sauvegarde la valeur du pixel que l'on copie dans l'image de destination

    sub ecx,4
    jne boucle
    
fin:
        pop     edi
        pop     esi
        pop     ebx

        pop     ebp

        ret                         ; Retour à la fonction MainWndProc

process_image_asm   ENDP
END

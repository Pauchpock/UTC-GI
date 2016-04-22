; IMAGE.ASM
;
; MI01 - TP Assembleur 2 � 5
;
; R�alise le traitement d'une image 32 bits.

.686
.MODEL FLAT, C
.MMX

.DATA

.CODE

; **********************************************************************
; Sous-programme _process_image_asm
;
; R�alise le traitement d'une image 32 bits.
;
; Entr�es sur la pile : Largeur de l'image (entier 32 bits)
;           Hauteur de l'image (entier 32 bits)
;           Pointeur sur l'image source (d�pl. 32 bits)
;           Pointeur sur l'image tampon 1 (d�pl. 32 bits)
;           Pointeur sur l'image tampon 2 (d�pl. 32 bits)
;           Pointeur sur l'image finale (d�pl. 32 bits)
; **********************************************************************
PUBLIC      process_image_mmx
process_image_mmx   PROC NEAR       ; Point d'entr�e du sous programme

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

	; Copie des constantes dans mm1
	mov eax, 150d ; GREEN
	mov ah, 77d ; RED
	shl eax, 8
	mov al, 29d ; BLUE
	movd mm1, eax

	pxor mm3, mm3
	punpcklbw mm1, mm3

	;jmp twopixels


boucle:
	movd mm0, dword ptr [esi+ecx] ; 32 bits
	
	pxor mm2, mm2
	punpcklbw mm0, mm2
	pmaddwd mm0, mm1
	movq mm2, mm0
	psrlq mm2, 32
	paddd mm0, mm2
	psrld mm0, 8
	movd eax, mm0

	mov [edi+ecx], eax ; on sauvegarde la valeur du pixel que l'on copie dans l'image de destination

	sub ecx,4
    jne boucle

	jmp fin

twopixels:
	sub ecx, 4

bouclee:
	movq mm0, qword ptr [esi+ecx] ; on charge deux pixels d'un coup (64 bits)

	pxor mm2, mm2
	punpckhbw mm2, mm0
	psrlw mm2, 8

	punpcklbw mm0, mm3

	pmaddwd mm0, mm1
	pmaddwd mm2, mm1

	movq mm4, mm0

	punpckldq mm4, mm2
	punpckhdq mm0, mm2

	paddd mm4, mm0
	psrld mm4, 8

	movq qword ptr [edi+ecx], mm4 ; on sauvegarde la valeur du pixel que l'on copie dans l'image de destination

	sub ecx,8
    jne bouclee

fin:
		; Lib�rer l'unit� MMX
		emms
        pop     edi
        pop     esi
        pop     ebx

        pop     ebp

        ret                         ; Retour � la fonction MainWndProc

process_image_mmx   ENDP
END

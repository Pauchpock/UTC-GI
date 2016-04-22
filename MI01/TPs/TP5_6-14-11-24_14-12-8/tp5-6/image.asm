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
    
    
;**************************************************** TP6 ********************************************
						mov     esi, [ebp + 20] ; tmp1
						mov     edi, [ebp + 24] ; tmp2
						
						; On stocke le nombre de lignes à traiter dans les bits de poids fort de ECX (hauteur)
						mov	ecx, [ebp + 12]
						sub		ecx, 2
						shl		ecx, 16
						
						mov	ebp, [ebp + 8] ; on stocke la longueur d'une ligne = le nombre de colonnes = largeur


						; On skip la première ligne et on passe à la deuxième case (+4)
						lea edi, [edi+ebp*4+4]
			
traitement_ligne:
						add ecx, ebp ; nombre de colonnes à traiter
						sub cx, 2

						;************************************************************************************************************************
						traitement_colonne:
												;************************************************************************************************
												
												;*********************************** Gx ******************************
												mov ebx, [esi]
												mov eax, [esi+ebp*4]
												imul eax, 2
												add ebx, eax
												add ebx, [esi+ebp*8] ; on saute 2 lignes
												neg ebx
												add ebx, [esi+8]
												mov eax, [esi+8+ebp*4]
												imul eax, 2
												add ebx, eax
												add ebx, [esi+8+ebp*8]
												jns pasneg ; SI POSITIF
												neg ebx

												pasneg:

												;*********************************** Gy ******************************
												mov edx, [esi+ebp*8]
												mov eax, [esi+4+ebp*8]
												imul eax, 2
												add edx, eax
												add edx, [esi+8+ebp*8]
												neg edx
												add edx, [esi]
												mov eax, [esi+4]
												imul eax,2
												add edx, eax
												add edx, [esi+8]
												jns pasneg2 ; SI POSITIF
												neg edx

												pasneg2:

												add ebx, edx

												neg ebx
												add ebx,255
												cmp ebx,0
												jg endd
												mov ebx,0

												endd:
												mov eax,ebx
												shl eax,8
												add ebx,eax
												shl eax,8
												add ebx,eax
												mov [edi], ebx
												
												;************************************************************************************************
												; On avance d'une case
												add edi, 4
												add esi, 4

												dec cx ; on décremente le nombre de colonnes à traiter
												cmp cx, 0
												jne traitement_colonne
						;************************************************************************************************************************
						
						; Passage à la deuxième case de la ligne suivante
						add edi, 8
						add esi, 8

						sub ecx, 65536 ; decremente de 1 les 16 bits de poids fort <=> decremente compteur de lignes

						cmp ecx,0
						jne traitement_ligne
    
fin:
        pop     edi
        pop     esi
        pop     ebx

        pop     ebp

        ret                         ; Retour à la fonction MainWndProc

process_image_asm   ENDP
END

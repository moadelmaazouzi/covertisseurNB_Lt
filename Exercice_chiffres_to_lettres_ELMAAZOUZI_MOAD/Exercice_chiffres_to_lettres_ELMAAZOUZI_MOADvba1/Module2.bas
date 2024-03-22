Attribute VB_Name = "Module2"
Sub maproce()
'lire un nobre sous form d une chaine

Dim machaine As String

machaine = InputBox("Veuillez entrer une valeur correct qui ne depasse pas de 15 chifres:")
'reglage du taile finale et conversion du chaine de nobre en tableau de nobre entiers
Dim i As Integer
Dim taille As Integer


If (Len(machaine) Mod 3) <> 0 Then

    taille = Len(machaine) + (3 - (Len(machaine) Mod 3))
Else
    taille = Len(machaine)
End If

Dim j As Integer
j = (3 - (Len(machaine) Mod 3))
Dim table(15) As Integer
'remplisage du table par des valeurs entiers
For i = 1 To taille
    
    If (Len(machaine) Mod 3) <> 0 Then
        
        If i <= j Then
            table(i) = 0
        Else
            table(i) = Mid(machaine, i - j, 1)
        End If
        
    Else
        table(i) = Mid(machaine, i, 1)
    End If
Next

Dim ch(20) As String
Dim k As Integer
j = 0


For i = 1 To taille + taille \ 3 Step 4
    ch(i) = Cells(table(j + 1) + 1, 1).Value
    ch(i + 1) = "cent"
    ch(i + 2) = Cells((table(j + 2) * 10 + table(j + 3) + 1), 1).Value
    
'parie du choix du milliar et les milliers
    
    If (taille - j = 12) Then
        ch(i + 3) = "milliard"
    ElseIf (taille - j = 9) Then
        ch(i + 3) = "million"
    ElseIf (taille - j = 6) Then
        ch(i + 3) = "mille"
    Else
        ch(i + 3) = ""
    End If
    
    j = j + 3
Next
'partie de filtrage des chaine qui contient la zero
j = 1
Dim ch1(20) As String
For i = 1 To taille + taille \ 3 Step 2
    If (ch(i) = "zero") Then
         
    ElseIf ((ch(i) = "un" And ch(i + 1) = "cent") Or (ch(i) = "un" And ch(i + 1) = "mille")) Then
        ch1(j) = ch(i + 1)
        j = j + 2
    Else
        ch1(j) = ch(i)
        ch1(j + 1) = ch(i + 1)
        j = j + 2
    End If
Next
Dim mlo As String
mlo = ""
For i = 1 To taille + taille \ 3
 mlo = mlo + " " + ch1(i)
Next
'affichage des resultas
Range("b4").Value = machaine
Range("c4").Value = mlo

End Sub


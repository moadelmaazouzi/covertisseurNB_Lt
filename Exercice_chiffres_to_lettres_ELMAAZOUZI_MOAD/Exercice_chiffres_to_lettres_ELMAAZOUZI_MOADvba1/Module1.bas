Attribute VB_Name = "Module1"
Sub fct1()
Dim cht As String
Dim chtl As String

cht = InputBox("Entrer une chaine qui contient un nombre decimale en utilusant la vigule:")
chtl = cht
tab1 = Split(cht, ",")
Dim cht1 As String
Dim cht2 As String
cht1 = tab1(0)
cht2 = tab1(1)

'LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
'lire un nobre sous form d une chaine
Dim machaine As String
Dim v As Integer
Dim i As Integer
Dim taille As Integer
Dim j As Integer
Dim table(15) As Integer
Dim ch(20) As String
Dim k As Integer
Dim ch1(20) As String
Dim mlo As String
Dim mlp As String
 mlp = ""
mlo = ""
For v = 1 To 2
    If (v = 1) Then
        machaine = cht1
    Else
        machaine = cht2
    End If

'reglage du taile finale et conversion du chaine de nobre en tableau de nobre entiers
    


    If (Len(machaine) Mod 3) <> 0 Then
    
        taille = Len(machaine) + (3 - (Len(machaine) Mod 3))
    Else
        taille = Len(machaine)
    End If

    
    j = (3 - (Len(machaine) Mod 3))
    
    'remplisage du table par des valeurs entiers
    If (v = 1) Then
    
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
    Else
        For i = 1 To taille
            If (Len(machaine) Mod 3) <> 0 Then
                If (i <= taille - j) Then
                    table(i) = Mid(machaine, i, 1)
                Else
                    table(i) = 0
                End If
            Else
                table(i) = Mid(machaine, i, 1)
            End If
        Next
    End If
    
        
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
    If (v = 1) Then
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
    Else
        For i = 1 To taille + taille \ 3 Step 1
            ch1(j) = ch(i)
            j = j + 1
        Next
    End If
    
    'patie final
    If (v = 1) Then
        For i = 1 To j - 1
         mlo = mlo + " " + ch1(i)
        Next
    Else
        For i = 1 To j - 1
         mlp = mlp + " " + ch1(i)
        Next
    End If

Next

'affichage des resultas
Range("b4").Value = cht1 + " ," + cht2
Range("c4").Value = mlo + "," + mlp

End Sub

















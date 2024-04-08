echo -ne "\E[H\E[2J" #очищаем экран
# echo -ne "\E[48:5;40m""\E[38:5;31m" #задаём чёрный фон и красный текст
echo -ne "\E[10;5H" #перемещаем курсор на 10 строку, 5 символ, выводим имя
echo -ne "\E(0" #входим в режим альтернативного вывода символов
echo -ne "lqqqqqqqqk" #рисуем верхнюю границу рамки
echo -ne "\E[11;5H" #рисуем левую границу рамки
echo -e "x"
echo -ne "\E[11;14H" #рисуем правую границу рамки
echo -e "x"
echo -ne "\E[12;5H"
echo -e "x"
echo -ne "\E[12;14H"
echo -e "x"
echo -ne "\E[13;5H"
echo -e "x"
echo -ne "\E[13;14H"
echo -e "x"
echo -ne "\E[14;5H"
echo -e "x"
echo -ne "\E[14;14H"
echo -e "x"
echo -ne "\E[15;5H"
echo -e "x"
echo -ne "\E[15;14H"
echo -e "x"
echo -ne "\E[16;5H"
echo -e "x"
echo -ne "\E[16;14H"
echo -e "x"
echo -ne "\E[17;5H"
echo -e "x"
echo -ne "\E[17;14H"
echo -e "x"
echo -ne "\E[18;5H"
echo -e "x"
echo -e "\E[11;6Haaaaaaaa" #рисуем цифру 5
echo -e "\E[12;6Haa\E[13;6Haa" 
echo -e "\E[14;6Haaaaaaaa"
echo -e "\E[15;12Haa\E[16;12Haa"
echo -e "\E[17;6Haaaaaaaa"
echo -ne "\E[18;5H"
echo -e "mqqqqqqqqj" #рисуем нижнюю границу рамки
echo -ne "\E(B" #выходим из режима альтернативного вывода символов
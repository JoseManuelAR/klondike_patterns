# klondike
To compile run the build.sh script<br />
<br />
To run the program execute the run.sh script<br />
<br />
Playing:<br />
<br />
x|m|f|u|r|l|s<br />
F1[ 0]: <><br />
F2[ 0]: <><br />
F3[ 0]: <><br />
F4[ 0]: <><br />
T1[ 1]: 2♥ <br />
T2[ 2]: 3♦  XX <br />
T3[ 3]: 4♥  XX  XX <br />
T4[ 4]: A♣  XX  XX  XX <br />
T5[ 5]: K♦  XX  XX  XX  XX <br />
T6[ 6]:10♥  XX  XX  XX  XX  XX <br />
T7[ 7]: Q♣  XX  XX  XX  XX  XX  XX <br />
 W[ 0]: <><br />
 D[24]: XX <br />
Enter a command:<br />
<br />
Available commands:<br />
Exit: x [Terminate program]<br />
Move cards: [From a pile to other] m \<ORIGIN\> \<DESTINATION\> \<NUMBEROFCARDS \[default = 1\]\><br />
Flip: [Move cards from remainder to waste] f<br />
Undo last movement: u<br />
Redo movement: r<br />
Load: [Load a game from a file] l \<FILE>\><br />
Save: [Save a game to a file] s \<FILE>\><br />
<br />
i.e.:<br />
T2 F1 --> Move 1 card from 2nd tableau (T2) to 1st foundation (F1)<br />
T4 T5 3 --> Move 3 cards from 4th tableau (T4) to 5th tableau (T5)<br />
D W --> Move 1 card from deck (D) to waste (W)<br />



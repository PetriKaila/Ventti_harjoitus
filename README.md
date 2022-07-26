# Ventti
Ventti peli C++ kurssin lopputyönä. 

##### Tekijä Petri Kaila ATIS21K

<img src="https://github.com/PetriKaila/Ventti_harjoitus/blob/main/media/Alkuvalikko.png" alt="Alkuvalikko" style="zoom:60%;" />

Pelissä on päävalikko josta löytyy mm. tutoriaali. Peli alkaa 1 näppäimestä ja kysyy ensimmäisenä nimeäsi. Valikossa on myös Toplista joka on 20:een. 
Toplistan nollaus, mikä poistaa Toplista.txt tiedoston.																									

## Asennus

Pelin voi kloonata suoraan Visual Studioon, tai vaihtoehtoisesti olen koittanut Qt Creatoria lataamalla ja purkamalla .zip paketin ja avaamalla CMakeList.txt![qt3](https://github.com/PetriKaila/Ventti_harjoitus/blob/main/media/qt3.png)

Qt Creatorin projectin konfigurointi.

## Sääntöjä

Ventissä tavoitteena on saada luku 21, tai mahdollisimman lähelle sitä. Jos kädessä olevat korttisi menevät yli 21, olet automaattisesti hävinnyt. Tässä versiossa pelataan vain jakajaa eli tietokonetta vastaan. Ässä on 1 tai 14 riippuen käsissäsi olevista korteista. Jos korttiesi summa on alle 7 on ässä on silloin 14. Jos päätät vielä tämän jälkeen kokeilla onneasi ja nostaa kortin, ja yhteissumaksi tulee yli seitsemän, muuttuu ässäkortti silloin ykköseksi. Vastaavasti, jos saat ässän ensimmäisenä, muuttuu se ykköseksi mikäli korttien yhteissumma ylittää 21. Pelin valikossa liikkuminen tapahtuu ilman enterin painallusta, ellei sitä erikseen pyydetä.

![Assa2](https://github.com/PetriKaila/Ventti_harjoitus/blob/main/media/Assa2.png)	

Esimerkki ässän käyttäytymisestä.

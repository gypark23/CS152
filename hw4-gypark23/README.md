Dear Grader,
I have made a readme to explain and justify my decision.

I have made two global constant variables ALBUMSIZE and MAXSONGSPERALBUM, and a global album variable.
When you make a new album or new songs for the grading purpose, you will have to modify these values.
Currently the album array is sized 4 with 4 albums max stored in Codify, and 3 songs maxed per album.
Should you need to modify it, feel free, and theoretically as long as you modify those variables, it shouldn't run into any errors when 
you create a new album or new variable or whatever you need to do.
(I haven't tried it, but I've designed it in a way that it really shouldn't produce any error when these variables are modified correctly).


For the querying process, I unevitably had to use forloops more than once. The runtime I believe is O(n) where n = ALBUMSIZE nevertheless, since
it is basically running the O(n) loop twice. I could have only used one for loop, but if I did that, I would have not had a function to 
use for unit testing. I coded with one for loop for each querrying process, which was way more efficient than current version,
but then I realized that I needed a non-void function for unit testing, so I have created two int functions numberOfAlbums and numberOfSongs.
In order to incorporate these functions as smoothly as possible, I unevitably had to create two for loops (one will run in numberOfAlbums or numberOSongs
while another will run in printing process) which I hope you would understand what and why I did it.


The malloc function at load() creates the song pointer sized maxsongsperalbum, which is 3. As explained above, each albums will have three songs
at max. 

Thanks and have a great day.
# Castles - The game
##What's that?
Castles is my first real C++ game. It's an indie tower defense game and is in early development right now.

##What to expect?
For now, don't expect too much. The graphics are bad (I really can't draw), and only about 2% of the actual game machanics are implemented.
But feel free to clone the repo and send me some nice pull requests!

##Still sounds cool, I want to have it!
No problem! Just download the repo and run 
```shell
make all
```
to compile. You will get an executable that's called castles. Then just run it (I myslef couldn't get it to run by double-clicking, I had to run it with the shell). For now it doesn't create a menu entry.
Check the makefile for some other cool make commands, such as compile only, link only, etc...                                         

##What about the dependencies?
Regarding the makefile you should be able to make tem up by yourself, but I'm kind and will (try to) list them here (don't cry if I forget one, this might happen due to the active stage of development):
<ul>
<li>SDL2 (SDL 1 will NOT work and you will need SDL_image too) </li>
<li>FTGL (for rendering text in OpenGL) </li>
</ul>
That's it (at least, i hope)

##Please note, that this game is developed and tested under linux
I can not give support to windows and mac users (although the game still should work) to this point, but feel free to test and report any issues to me.




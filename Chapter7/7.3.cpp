/*
Jukebox - money -> choose song -> play songs in FIFO order
setting - let users can skip the current song
queue songList
1. (subclass) choose song - called by money collector
2. (subclass) play song - called by choose song or a song ends => plays til the queue is empty
These two classes should work simutaneously => thread
so the list should be protected by mutex lock

money collector ->
collects money til it's enough for choosing a song
then until chossing a song, it shouldn't collect anymore.

CD - stores the song, and also the position of this CD
should make each song unique => shared_ptr int the storage or playing
 */

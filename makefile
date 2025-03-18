pilgrimage: game/pilgrimage.cc
	g++ game/pilgrimage.cc -o pilgrimage
exec: pilgrimage
	./pilgrimage
	rm pilgrimage

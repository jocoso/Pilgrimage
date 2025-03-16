pilgrimage: sample/sample.cc
	g++ sample/sample.cc -o pilgrimage
exec: pilgrimage
	./pilgrimage
	rm pilgrimage

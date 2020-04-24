Ecosystem: Algae.o Animal.o Bear.o Carnivores.o Deer.o Ecosystem.o Fox.o Grass.o Groundhog.o Herbivores.o main.o Maple.o Oak.o Pine.o Plant.o Rabbit.o Salmon.o Seeded.o Seedless.o Terrain.o Wolf.o
	g++ -o Ecosystem Algae.o Animal.o Bear.o Carnivores.o Deer.o Ecosystem.o Fox.o Grass.o Groundhog.o Herbivores.o main.o Maple.o Oak.o Pine.o Plant.o Rabbit.o Salmon.o Seeded.o Seedless.o Terrain.o Wolf.o
Algae.o: Algae.cpp Plant.h Seedless.h
	g++ -c Algae.cpp
Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp
Bear.o: Bear.cpp Animal.h Carnivores.h
	g++ -c Bear.cpp
Carnivores.o: Carnivores.cpp Animal.h Carnivores.h
	g++ -c Carnivores.cpp
Deer.o: Deer.cpp Animal.h Herbivores.h
	g++ -c Deer.cpp
Fox.o: Fox.cpp Animal.h Carnivores.h
	g++ -c Fox.cpp
Grass.o: Grass.cpp Plant.h Seedless.h
	g++ -c Grass.cpp
Groundhog.o: Groundhog.cpp Animal.h Herbivores.h
	g++ -c Groundhog.cpp
Herbivores.o: Herbivores.cpp
	g++ -c Herbivores.cpp
main.o: main.cpp
	g++ -c main.cpp
Maple.o: Maple.cpp Plant.h Seeded.h
	g++ -c Maple.cpp
Oak.o: Oak.cpp Plant.h Seeded.h
	g++ -c Oak.cpp
Pine.o: Pine.cpp Plant.h Seeded.h
	g++ -c Pine.cpp
Plant.o: Plant.cpp Plant.h
	g++ -c Plant.cpp
Rabbit.o: Rabbit.cpp Animal.h Herbivores.h
	g++ -c Rabbit.cpp
Salmon.o: Salmon.cpp Animal.h Herbivores.h
	g++ -c Salmon.cpp 
Seeded.o: Seeded.cpp Plant.h Seeded.h
	g++ -c Seeded.cpp
Seedless.o: Seedless.cpp Plant.h Seeded.h
	g++ -c Seedless.cpp
Wolf.o: Wolf.cpp Animal.h Carnivores.h
	g++ -c Wolf.cpp
main.o:	main.cpp Ecosystem.h
	g++ -c main.cpp
Ecosystem.o: Ecosystem.cpp Ecosystem.h Terrain.h Plant.h Seeded.h Seedless.h Animal.h Herbivores.h Carnivores.h
	g++ -c Ecosystem.cpp
Terrain.o: Terrain.cpp Terrain.h Plant.h Animal.h
	g++ -c Terrain.cpp

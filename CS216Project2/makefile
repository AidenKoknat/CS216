EXEC = Project2
HEADERS = card.h deck.h SortedLinkedList.h rank.h pokerhand.h
#(listing all header files here, separated by space)
OBJECTS = card.o deck.o SortedLinkedList.o rank.o pokerhand.o
#(listing all of your object files here, separated by space)
$(EXEC): $(OBJECTS)
	g++ $^ -o $@
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@
Project2: $(OBJECTS) Project2.o
	g++ $^ -o $@
clean:
	rm -i *.o testPA2 Project2
testPA2: $(OBJECTS) testPA2.o
	g++  $^ -o $@
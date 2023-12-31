all: obj MerkleNode.o MerkleTree.o TransactionNode.o Block.o main.o
	g++ -o main ./obj/*.o -lssl -lcrypto
obj:
	rm -rf obj
	mkdir obj
main.o: main.cpp ./includes/Block.hpp ./includes/TransactionNode.hpp
	g++ -c -o ./obj/main.o main.cpp
MerkleTree.o: ./obj/MerkleNode.o ./src/MerkleTree.cpp ./includes/MerkleTree.hpp
	g++ -c -o ./obj/MerkleTree.o ./src/MerkleTree.cpp -lssl -lcrypto
MerkleNode.o: ./src/MerkleNode.cpp ./includes/MerkleNode.hpp
	g++ -c -o ./obj/MerkleNode.o ./src/MerkleNode.cpp -lssl -lcrypto
TransactionNode.o: ./includes/TransactionNode.hpp ./src/TransactionNode.cpp
	g++ -c -o ./obj/TransactionNode.o ./src/TransactionNode.cpp
Block.o: ./obj/MerkleTree.o ./includes/Block.hpp ./src/Block.cpp
	g++ -c -o ./obj/Block.o ./src/Block.cpp -lssl -lcrypto
clean:
	rm -rf ./obj/*.o
	rm -rf main
	rm -rf obj
run:
	./main > test.txt
valgrind:
	valgrind --leak-check=full ./main
installLibs:
	sudo apt-get update
	sudo apt-get install libssl-dev
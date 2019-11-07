CC = g++-8
DEFAULT_GOAL = makeit
FLAGS = -l sqlite3

makeit:
	@echo "Main Make..."
	$(CC) -o main main.cpp $(FLAGS)
	@echo "Done!"

clean:
	@echo "Removing output files."
	@rm main
	@rm log.txt
cleano:
	@echo "Removing output files."
	@rm $(TRY2)

cleanall:
	@echo "Removing all files."

default:
	g++ exec.cpp ./Headers/*.h ./Classes/*.cpp -o exec -lX11 -lGL -lpthread -lpng -w && ./exec && rm exec 
# Linux build

LINUX_LIBRARY := ../../bin/libtraveling_wav.so

linux: ../../bin/tvgw_fileload.o ../../bin/tvgw_filewrite.o ../../bin/tvgw_dispose.o ../../bin/tvgw_converter.o
	g++ -shared -o $(LINUX_LIBRARY) ../../bin/*.o

../../bin/tvgw_fileload.o:
	g++ -fPIC -c cpp/tvgw_fileload.cpp -o ../../bin/tvgw_fileload.o

../../bin/tvgw_filewrite.o:
	g++ -fPIC -c cpp/tvgw_filewrite.cpp -o ../../bin/tvgw_filewrite.o

../../bin/tvgw_dispose.o:
	g++ -fPIC -c cpp/tvgw_dispose.cpp -o ../../bin/tvgw_dispose.o

../../bin/tvgw_converter.o:
	g++ -fPIC -c cpp/tvgw_converter.cpp -o ../../bin/tvgw_converter.o

# Clean

clean:
	rm ../../bin/*
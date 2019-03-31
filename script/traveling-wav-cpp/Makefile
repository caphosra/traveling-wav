# Linux build

COMPILER := g++ -std=gnu++14

LINUX_LIBRARY := ../../bin/libtraveling_wav.so

linux: ../../bin/tvgw_fileload.o ../../bin/tvgw_filewrite.o ../../bin/tvgw_dispose.o ../../bin/tvgw_converter.o
	$(COMPILER) -shared -o $(LINUX_LIBRARY) ../../bin/*.o

../../bin/tvgw_fileload.o:
	$(COMPILER) -fPIC -c cpp/tvgw_fileload.cpp -o ../../bin/tvgw_fileload.o

../../bin/tvgw_filewrite.o:
	$(COMPILER) -fPIC -c cpp/tvgw_filewrite.cpp -o ../../bin/tvgw_filewrite.o

../../bin/tvgw_dispose.o:
	$(COMPILER) -fPIC -c cpp/tvgw_dispose.cpp -o ../../bin/tvgw_dispose.o

../../bin/tvgw_converter.o:
	$(COMPILER) -fPIC -c cpp/tvgw_converter.cpp -o ../../bin/tvgw_converter.o

# Clean

clean:
	rm ../../bin/*.o & rm ../../bin/*.so
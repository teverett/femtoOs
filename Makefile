
image: 
	make -C src
	cp src/floppy.img .
clean:
	make -C src clean

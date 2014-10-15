
image: src/floppy.img
src/floppy.img:
	make -C src
	cp src/floppy.img .	
clean:
	make -C src clean
	rm -rf floppy.img


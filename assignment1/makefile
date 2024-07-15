.PHONY: all clean loops recursives recursived loopd

#create libraries
loops: libclassloops.a

recursives: libclassrec.a

loopd: libclassloops.so

recursived: libclassrec.so

#libraries compilation
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	gcc -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so 
	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so
	
#main files
mains: main.o libclassrec.a
	gcc -Wall -g main.o libclassrec.a -o mains

maindloop: main.o
	gcc -Wall -g main.o ./libclassloops.so -o maindloop

maindrec: main.o
	gcc -Wall -g main.o ./libclassrec.so -o maindrec

#c files compilation
basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -fPIC -c basicClassification.c -o basicClassification.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -fPIC -c advancedClassificationLoop.c -o advancedClassificationLoop.o

#main compilation
main.o: main.c NumClass.h
	gcc -Wall -g -c main.c -o main.o

#all
all: libclassloops.so libclassrec.so libclassrec.a libclassloops.a mains maindloop maindrec	

#clean
clean: 
	rm -f mains maindloop maindrec *.so *.a *.o			
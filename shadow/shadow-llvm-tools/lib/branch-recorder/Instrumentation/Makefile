all: Instrumentation.cpp
	llvm-gcc -c -emit-llvm *.cpp
	llvm-link *.o -o Instrumentation.bc

clean:
	rm *.o *.bc
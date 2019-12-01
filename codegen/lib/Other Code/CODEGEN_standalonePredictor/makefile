CC=gcc
CFLAGS=-I.
DEPS = main.h
OBJ = CODEGEN_standalonePredictor.o CODEGEN_standalonePredictor_data.o CODEGEN_standalonePredictor_initialize.o CODEGEN_standalonePredictor_terminate.o CompactClassificationTree.o main.o rtGetInf.o rtGetNaN.o rt_nonfinite.o


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	-rm *.o $(objects) main

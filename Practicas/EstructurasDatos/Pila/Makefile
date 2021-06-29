PROY=pila
DSTPATH=/usr/local/bin
CFLAGS=-Wall
COBJ=-c
LINKF=-lm
CC=gcc
ORIGINFILES=$(wildcard *.c)
OBJECTFILES=$(ORIGINFILES:.c=.o)

all:${PROY}

# % es cualquier archivo en la carpeta
# $< regresa la primer dependencia
%.o:%.c
	${CC} ${COBJ} $< ${CFLAGS}

# $^ Regresa la lista completa de dependencias completa
# $@ Regresa el nombre de la etiqueta
${PROY}:${OBJECTFILES}
	${CC} $^ -o $@ ${LINKF}

.PHONY:clean

install:all
	@if [ ! -d ${DSTPATH} ]; then\
		sudo mkdir ${DSTPATH}
	fi
	@sudo cp ${PROY} ${DSTPATH}
uninstall:
	@sudo rm ${DSTPATH}/${PROY}
clean:
	@rm -f *.o ${PROY}

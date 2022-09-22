.PHONY: all
all:
	$(CC) -shared native/URLEncoding.c -I$(JAVA_HOME)/include/linux -I$(JAVA_HOME)/include -lurlencoding -o liburlencodingjni.so

.PHONY: install
install:
	cp liburlencodingjni.so /usr/lib/liburlencodingjni.so

.PHONY: clean
clean: liburlencodingjni.so
	rm liburlencodingjni.so
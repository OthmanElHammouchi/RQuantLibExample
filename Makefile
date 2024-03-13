.PHONY: all
all:
	$(MAKE) attrs
	$(MAKE) install
	$(MAKE) clean

.PHONY: attrs
attrs:
	R -e 'Rcpp::compileAttributes(".", verbose = TRUE)'

.PHONY: install
install:
	R CMD INSTALL .

.PHONY: clean
clean:
	rm -rf src/*.o
	rm -rf src/*.so
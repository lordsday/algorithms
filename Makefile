default:
	@echo "Explicit target required"

.PHONY: default

all: sort
	cd array && $(MAKE)
	cd graph && $(MAKE)
	cd hash && $(MAKE)
	cd list && $(MAKE)
	cd queue && $(MAKE)
	cd search && $(MAKE)
	cd sort && $(MAKE)
	cd stack && $(MAKE)
	cd tree && $(MAKE)

clean:
	cd array && $(MAKE) clean
	cd graph && $(MAKE) clean
	cd hash && $(MAKE) clean
	cd list && $(MAKE) clean
	cd queue && $(MAKE) clean
	cd search && $(MAKE) clean
	cd sort && $(MAKE) clean
	cd stack && $(MAKE) clean
	cd tree && $(MAKE) clean

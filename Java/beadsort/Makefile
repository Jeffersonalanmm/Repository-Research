JCC = javac

BINDIR = bin

CLASSES_TO_TEST = The_Algorithms llama3_3_70b mistral_saba_24b

CLASS ?= The_Algorithms

SOURCES = The_Algorithms.java \
          llama3_3_70b.java \
          mistral_saba_24b.java

compile:
	@echo "==> Compiling all .java files..."
	@mkdir -p $(BINDIR)
	$(JCC) -d $(BINDIR) $(SOURCES)
	@echo "==> Compilation complete!"

mem: compile
	@echo "==> Starting memory analysis for all algorithms..."
	@for class in $(CLASSES_TO_TEST); do \
		echo ""; \
		echo "--- Measuring memory for class: $$class ---"; \
		/usr/bin/time -v java -cp $(BINDIR) $$class 2>&1 | grep "Maximum resident set size"; \
	done
	@echo ""
	@echo "==> Analysis complete."

clean:
	@echo "==> Removing directory: $(BINDIR)..."
	@rm -rf $(BINDIR)
	@echo "==> Cleanup complete."

.PHONY: compile mem-all mem clean
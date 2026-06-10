# targets
SPIDER =	spider
SCORPION =	scorpion

# sources
SPIDER_SRC =	spider.py
SCORPION_SRC =	scorpion.py
CONF_SRC =	requirements.txt

# pathes
PATH_SRCS =	./srcs
PATH_CONF =	./conf

# python interpreter
PYTHON =	python3

##########################################

SPIDER_MAIN =	$(PATH_SRCS)/$(SPIDER_SRC)
SCORPION_MAIN =	$(PATH_SRCS)/$(SCORPION_SRC)

all: $(SPIDER) $(SCORPION)

$(SPIDER):
	@echo "Setting up $(SPIDER)..."
	@printf '#!/bin/sh\nexec $(PYTHON) $(SPIDER_MAIN) "$$@"\n' > $(SPIDER)
	@chmod 755 $(SPIDER)
	@echo "Done: run with ./$(SPIDER) <url> [-r] [-l <depth>] [-p <output_dir>]"

$(SCORPION):
	@echo "Setting up $(SCORPION)..."
	@printf '#!/bin/sh\nexec $(PYTHON) $(SCORPION_MAIN) "$$@"\n' > $(SCORPION)
	@chmod 755 $(SCORPION)
	@echo "Done: run with ./$(SCORPION) <file1> [file2 ...]"

install:
	@echo "Installing dependencies..."
	python3 -m pip install -r $(PATH_CONF)/$(CONF_SRC)

clean:
	@find . -type d -name __pycache__ -exec rm -rf {} + 2>/dev/null || true
	@find . -name "*.pyc" -delete 2>/dev/null || true
	@echo "Cleaned."

fclean: clean
	@rm -f $(SPIDER) $(SCORPION)
	@echo "Full clean done."

dclean: fclean
	@rm -rf ./data
	@echo "Default data directory deleted."

re: fclean all

.PHONY: all install clean fclean dclean re

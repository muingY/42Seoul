DIRS = checker_srcs push_swap_srcs

all:
	@for d in $(DIRS); \
	do \
			$(MAKE) -C $$d; \
	done
	cp checker_srcs/checker checker
	cp push_swap_srcs/push_swap push_swap

clean:
	@for d in $(DIRS); \
	do \
			$(MAKE) -C $$d clean; \
	done

fclean:
	@for d in $(DIRS); \
	do \
			$(MAKE) -C $$d fclean; \
	done
	rm -f checker
	rm -f push_swap

re: fclean all

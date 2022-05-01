COMPOSEFILE = ./srcs/docker-compose.yml

up:
	sudo docker-compose -f $(COMPOSEFILE) up -d --build

stop:
	sudo docker-compose -f $(COMPOSEFILE) stop

down:
	sudo docker-compose -f $(COMPOSEFILE) down

start:
	sudo docker-compose -f $(COMPOSEFILE) start

ps:
	sudo docker-compose -f $(COMPOSEFILE) ps

re: stop up

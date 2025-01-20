NAME = inception
COMPOSE_PATH = ./srcs/docker-compose.yml

$(NAME) :
	sudo mkdir -p ${HOME}/data/mariadb ${HOME}/data/wordpress
ifeq ("$(wildcard .setup)", "")
	sudo chmod 777 /etc/hosts
	sudo echo "127.0.0.1 eunlee.42.fr" >> /etc/hosts
	sudo touch .setup
endif
	sudo docker-compose -f $(COMPOSE_PATH) up --force-recreate --build -d

.PHONY : all
all: $(NAME)

.PHONY : stop
stop:
	sudo docker-compose -f $(COMPOSE_PATH) down

.PHONY : clean
clean:
	sudo docker-compose -f $(COMPOSE_PATH) down -v --rmi all --remove-orphans

.PHONY : fclean
fclean: clean
	sudo rm -rf ${HOME}/data
	sudo docker system prune --volumes -a -f
	sudo docker network prune -f
	sudo docker volume prune -f

.PHONY : re
re: fclean all

.PHONY : restart
	sudo docker-compose -f $(COMPOSE_PATH) restart

.PHONY : ps
ps:
	sudo docker-compose -f $(COMPOSE_PATH) ps

.PHONY : access_mariadb
access_mariadb:
	sudo docker-compose -f ${COMPOSE_PATH} exec mariadb /bin/bash

.PHONY : access_wordpress
access_wordpress:
	sudo docker-compose -f ${COMPOSE_PATH} exec wordpress /bin/bash

.PHONY : access_nginx
access_nginx:
	sudo docker-compose -f ${COMPOSE_PATH} exec nginx /bin/bash
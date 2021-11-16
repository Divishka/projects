NAME = inception

YAML = ./srcs/docker-compose.yml

$(NAME):
			docker-compose -f $(YAML) up -d --build

all:		$(NAME)

up:
			docker-compose -f $(YAML) up -d
down:
			docker-compose -f $(YAML) down

clean:		down
			docker rmi nginx wordpress mariadb
			docker volume rm wordpress mariadb

re:			clean all

.PHONY:		all up down clean re

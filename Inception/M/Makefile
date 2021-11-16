YAML = ./srcs/docker-compose.yml

start:
	docker-compose -f $(YAML) up -d --build
up:
	docker-compose -f $(YAML) up -d
down:
	docker-compose -f $(YAML) down

clean: down
	docker rmi -f nginx mariadb wordpress
	docker volume rm wordpress db

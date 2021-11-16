YAML = ./srcs/docker-compose.yml
start:
	docker-compose -f srcs/docker-compose.yml up -d --build
up:
	docker-compose -f srcs/docker-compose.yml up -d
down:
	docker-compose -f srcs/docker-compose.yml down

clean: down
	docker rmi -f nginx mariadb wordpress
	docker volume rm wordpress db

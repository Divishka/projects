# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 11:23:12 by pllucian          #+#    #+#              #
#    Updated: 2021/06/17 12:13:37 by pllucian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

FROM debian:buster

RUN apt-get update && apt-get -y upgrade && \
apt-get -y install vim default-mysql-server

COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./docker-entrypoint.sh /

RUN chmod +x /docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT [ "/docker-entrypoint.sh" ]

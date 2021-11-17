FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y vim default-mysql-server
COPY ./database.sh /
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
RUN chmod +x /database.sh
EXPOSE 3306
ENTRYPOINT [ "/database.sh" ]

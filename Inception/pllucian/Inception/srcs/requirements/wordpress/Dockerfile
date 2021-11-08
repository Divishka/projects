FROM debian:buster

RUN apt-get update && apt-get -y upgrade && \
apt-get -y install vim wget php7.3 php7.3-fpm php7.3-mysql php7.3-xml

RUN wget -P /tmp/ https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

COPY ./wp-config.php /tmp/

COPY ./www.conf /etc/php/7.3/fpm/pool.d/

COPY ./docker-entrypoint.sh /

RUN chmod +x /docker-entrypoint.sh

EXPOSE 9000

ENTRYPOINT [ "/docker-entrypoint.sh" ]

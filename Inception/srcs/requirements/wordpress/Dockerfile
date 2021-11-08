FROM debian:buster

RUN apt-get update
RUN apt-get install -y \
	php7.3-fpm \
	php7.3-mysql \
	php7.3-xml \
	php7.3 \
	wget \
	vim

COPY ./conf/wp-config.php /tmp/
COPY ./conf/www.conf /etc/php/7.3/fpm.pool.d/
COPY ./conf/wordpress.sh / 
RUN chmod +x /wordpress.sh
EXPOSE 9000
ENTRYPOINT [ "/wordpress.sh" ]
# CMD [ "/usr/sbin/php-fpm7.3", "--nodaemonize" ]
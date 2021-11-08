FROM debian:buster

RUN apt-get update && apt-get -y upgrade && \
apt-get -y install vim nginx openssl

COPY ./default.conf /etc/nginx/sites-available/default

COPY ./docker-entrypoint.sh /

RUN chmod +x /docker-entrypoint.sh

EXPOSE 443

ENTRYPOINT [ "/docker-entrypoint.sh" ]

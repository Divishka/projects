FROM debian:buster

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install openssl vim nginx

COPY ./conf/default.conf /etc/nginx/sites-available/default
COPY ./conf/nginx.sh /
RUN chmod +x /nginx.sh
EXPOSE 443
ENTRYPOINT [ "/nginx.sh" ]
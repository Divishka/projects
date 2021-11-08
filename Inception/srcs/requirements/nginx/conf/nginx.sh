#!/bin/sh

openssl req -x509 -nodes -days 365 -subj \
"/C=RU/ST=Tatarstan/L=Kazan/O=21school/OU=aqua/CN=awhana" \
-newkey rsa:2048 -keyout /etc/nginx/nginx-selfsigned.key \
-out /etc/nginx/nginx-selfsigned.crt;

chown -R www-data:www-data /var/www/html/

exec nginx -g 'daemon off;'
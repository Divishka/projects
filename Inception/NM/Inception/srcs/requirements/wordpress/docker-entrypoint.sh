#!/bin/sh

service php7.3-fpm start
if [ ! -f /var/www/html/wp-config.php ]; then
	chmod +x /tmp/wp-cli.phar
	mv /tmp/wp-cli.phar /usr/local/bin/wp
	mkdir -p /var/www/html/
	wp core download --allow-root --locale=ru_RU --path=/var/www/html/
	mv /tmp/wp-config.php /var/www/html/
	wp core install --allow-root --url=$DOMAIN_NAME --title=$WEBSITE_NAME --admin_user=$WORDPRESS_DB_USER --admin_password=$WORDPRESS_DB_PASSWORD --admin_email=$EMAIL_ADDRESS --path=/var/www/html/
	wp user create --allow-root pllucian2 pllucian2@42.fr --role=author --user_pass=user2pass --path=/var/www/html/
	chown -R www-data:www-data /var/www/html/
fi
service php7.3-fpm stop

exec php-fpm7.3 --nodaemonize

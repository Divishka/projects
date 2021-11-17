#!/bin/sh
	
service php7.3-fpm start
if [ ! -f /var/www/html/wp-config.php ]; then
	chmod +x /tmp/wp-cli.phar
	mv /tmp/wp-cli.phar /usr/local/bin/wp
	mkdir -p /var/www/html
	wp core download --allow-root --path/var/www/html
	mv /tmp/wp-config.php /var/www/html/
	wp core install --allow-root \
					--url=${WORDPRESS_WEBSITE_URL_WITHOUT_HTTP} \
					--title=${WORDPRESS_WEBSITE_TITLE} \
					--admin_user=${WORDPRESS_ADMIN_USER}
					--admin_password=${WORDPRESS_ADMIN_PASSWORD}
					--admin_email=${WORDPRESS_ADMIN_EMAIL} \
					--path=/var/www/html/
	wp user create --allow-root ${USER_NAME} ${USER_EMAIL} \
					--user_pass=${USER_PASS} \
					--path=/var/www/html/
	chown -R www-data:www-data /var/www/html/
fi
service php7.3-fpm stop

exec php-fpm7.3 --nodaemonize

# !/bin/sh

# www.conf
echo "env[MARIADB_DB] = $MARIADB_DB" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_USER] = $MARIADB_USER" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_PWD] = $MARIADB_PWD" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_HOST] = $MARIADB_HOST" >> /etc/php/7.3/fpm/pool.d/www.conf

cd /var/www/html
if [ ! -f "/var/www/html/wp-config.php" ]; then
	cp /tmp/wp-config.php /var/www/html/wp-config.php
	sleep 5;
fi

if ! wp core --allow-root is-installed; then
	wp core install --allow-root --url=$WP_URL --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --path=/var/www/html
	wp user create --allow-root $WP_USER $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PWD --path=/var/www/html
fi

# /run/php/php7.3-fpm.pid 파일 자동 생성
service php7.3-fpm start
service php7.3-fpm stop

php-fpm7.3 --nodaemonize
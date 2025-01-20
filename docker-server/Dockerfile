FROM	debian:buster

RUN		apt-get -y update && apt-get -y upgrade
RUN		apt-get -y install \
		nginx \
		openssl \
		vim \
		php-fpm \
		mariadb-server \
		php-mysql \
		wget

# Step 1. Install nginx
COPY	./srcs/default /etc/nginx/sites-available/default

# Step 2. ssl
RUN		openssl req -newkey rsa:4096 -nodes -x509 -keyout localhost.dev.key -out localhost.dev.crt -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Eunlee/CN=localhost" 
RUN		mv localhost.dev.crt /etc/ssl/certs/ && mv localhost.dev.key /etc/ssl/private/
RUN		chmod 600 etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

# Step 3. Install phpmyadmin
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz \
		&& tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz \
		&& mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin \
		&& rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		rm /var/www/html/index.nginx-debian.html
COPY	./srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php

# Step 4. Install WordPress
RUN		wget https://wordpress.org/latest.tar.gz \
		&& tar -xvf latest.tar.gz \
		&& mv wordpress/ /var/www/html/ \
		&& chown -R www-data:www-data /var/www/html/wordpress \
		&& rm /latest.tar.gz

COPY	./srcs/wp-config.php /var/www/html/wordpress/wp-config.php

COPY	./srcs/run.sh /

EXPOSE	80 443

CMD		bash run.sh

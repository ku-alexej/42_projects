#!/bin/bash

cd

echo "[1/5] WP script"
echo "      Installing wp-cli..."
# WP Command Line Interface 
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
echo "      Installed wp-cli"

echo "[2/5] WP script"
if [ ! -f /var/www/html/wordpress/wp-config-sample.php ]; then
   
    # Listen to 9000
    sed -i 's/listen = \/run\/php\/php7.4-fpm.sock/listen = 9000/g' /etc/php/7.4/fpm/pool.d/www.conf
    # PHP in foreground
    sed -i 's/;daemonize = yes/daemonize = no/' /etc/php/7.4/fpm/php-fpm.conf

    # Download WP files
    echo "      Downloading and installing WP..."
    wp core download \
        --path='/var/www/html/wordpress' \
        --allow-root
    chmod -R 775 /var/www/html/wordpress
    chown -R www-data:www-data /var/www/html/wordpress
fi
echo "      WP was installed"

# Go to WP directory (possible use --path=/var/www/html/wordpress)
cd /var/www/html/wordpress

echo "[3/5] WP script"
if [ ! -f wp-config.php ]; then
    echo "      Configurating WP..."
    wp config create \
        --dbname=$DB_NAME \
        --dbuser=$DB_USER \
        --dbpass=$DB_USER_PASSWORD \
        --dbhost=$DB_HOST \
        --dbprefix=wp_ \
        --allow-root
fi
echo "      WP was configurated"

echo "[4/5] WP script"
if ! wp core is-installed --allow-root; then

    echo "      Installing WP and create admin..."
    wp core install \
        --url=akurochk.42.fr \
        --title="Inception by akurochk" \
        --admin_user=$WP_ADM \
        --admin_password=$WP_ADM_PASSWORD \
        --admin_email=$WP_ADM_EMAIL \
        --skip-email \
        --allow-root

    echo "      Creating user..."
    wp user create \
        $WP_USER \
        $WP_USER_EMAIL \
        --user_pass=$WP_USER_PASSWORD \
        --role=editor \
        --allow-root

    echo "      Update homepage..."
    wp option update home "https://akurochk.42.fr" --path=/var/www/html/wordpress --allow-root

    echo "      Update URL..."
    wp option update siteurl "https://akurochk.42.fr" --path=/var/www/html/wordpress --allow-root

# bonus - redis
    echo "      Add Redis config info..."
    sed -i "/\/\* That's all, stop editing! Happy publishing. \*\//i define('WP_REDIS_HOST', 'redis');\ndefine('WP_REDIS_PORT', 6379);" wp-config.php

    echo "      Install Redis plugin..."
    wp plugin install redis-cache \
        --activate \
        --allow-root

    echo "      Enable Redis..."
    wp redis enable \
        --allow-root
# end of bonus
fi;
echo "      WP was installed"

echo "[5/5] WP script"
echo "      Running php-fpm..."
php-fpm7.4 -F -R --nodaemonize

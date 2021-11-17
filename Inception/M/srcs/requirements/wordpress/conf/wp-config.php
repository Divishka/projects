<?php

define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'awhana' );
define( 'DB_PASSWORD', 'proverka2718281');
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

define( 'AUTH_KEY',         'RANDOMCYPTKEY' );
define( 'SECURE_AUTH_KEY',  'RANDOMCYPTKEY' );
define( 'LOGGED_IN_KEY',    'RANDOMCYPTKEY' );
define( 'NONCE_KEY',        'RANDOMCYPTKEY' );
define( 'AUTH_SALT',        'RANDOMCYPTKEY' );
define( 'SECURE_AUTH_SALT', 'RANDOMCYPTKEY' );
define( 'LOGGED_IN_SALT',   'RANDOMCYPTKEY' );
define( 'NONCE_SALT',       'RANDOMCYPTKEY' );

$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
?>

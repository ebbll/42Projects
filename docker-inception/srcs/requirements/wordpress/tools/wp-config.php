<?php
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('MARIADB_DB') );

/** MySQL database username */
define( 'DB_USER', getenv('MARIADB_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('MARIADB_PWD') );

/** MySQL hostname */
define( 'DB_HOST', getenv('MARIADB_HOST') );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('AUTH_KEY',         '{w?r,tpR|024d8*TiSW520[F=u.-1@jbHK=pc/nYzA|P}qK}?--Vl~X~.VPsNRxY');
define('SECURE_AUTH_KEY',  '*ecA%Ens@Z$|+Mr5=VCV$U|nr=vEJ50Ijleq3k8C~-Hvls!tOJI!|]Ao|Du=~(JM');
define('LOGGED_IN_KEY',    '-9`m`hQ4|#|.@?6v/V,$1/vYR4-V%_Uim&8jj&TLNaa>*K#bBzf+_6$/-R-+c-Zu');
define('NONCE_KEY',        '7nVv=:Pk)W6w5?:Q[=XE4jDuP=Gx.3+$^4S6&E_h~]-W6N#j!ctTb(eYiRE6o)D|');
define('AUTH_SALT',        '9cuF8IsI#0C5ToaG-pm y?|`qcZqZ!^7}HuV#2V-Y=o ~VSJ,GFEV^f<=Wnh25`E');
define('SECURE_AUTH_SALT', 'G^y+;)DbaSCBmQb*rTa<79B7>dW2#J&m;Az8=R{#J%whl )Q}DGl/H(K#K+Jy:<f');
define('LOGGED_IN_SALT',   ':.zr)EL--1.z:G{=GU!d:!CTx=Sq+@O&D6L,8!&|Qi!Wo_A)qCtH|0?oH|0qc@^c');
define('NONCE_SALT',       '+9tkT.q6;DcDB.Wo[;{`m34r*F( L@t]!G$1-_3t&NzEU1HQ&-)$~vQqo`1 z2s0');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
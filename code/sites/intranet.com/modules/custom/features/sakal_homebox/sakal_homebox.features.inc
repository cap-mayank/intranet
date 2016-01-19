<?php
/**
 * @file
 * sakal_homebox.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sakal_homebox_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_homebox().
 */
function sakal_homebox_homebox() {
  $homeboxes = array();

  $homeboxes['home'] = array(
    'regions' => 3,
    'cache' => 0,
    'color' => 0,
    'colors' => array(),
    'blocks' => array(
      'views_ipress_blocks-block_2' => array(
        'module' => 'views',
        'delta' => 'ipress_blocks-block_2',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -26,
      ),
      'sakal_utility_recent' => array(
        'module' => 'sakal_utility',
        'delta' => 'recent',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -26,
      ),
      'views_calendar-block_1' => array(
        'module' => 'views',
        'delta' => 'calendar-block_1',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -26,
      ),
      'views_ipress_blocks-post_of_the_day' => array(
        'module' => 'views',
        'delta' => 'ipress_blocks-post_of_the_day',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -26,
      ),
      'block_11' => array(
        'module' => 'block',
        'delta' => 11,
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => 'slider',
        'weight' => -28,
      ),
    ),
    'widths' => array(),
    'title' => 'Home',
    'path' => 'home',
    'menu' => 1,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 0,
    'roles' => array(
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}

<?php
/**
 * @file
 * units.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function units_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function units_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function units_node_info() {
  $items = array(
    'units' => array(
      'name' => t('Unites'),
      'base' => 'node_content',
      'description' => t('Sakal Unites should added here. Unites will display under Unites menulink of main menu.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

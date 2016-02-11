<?php
/**
 * @file
 * unites.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unites_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function unites_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function unites_node_info() {
  $items = array(
    'unites' => array(
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

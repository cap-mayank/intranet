<?php
/**
 * @file
 * quote_of_the_day.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function quote_of_the_day_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function quote_of_the_day_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function quote_of_the_day_node_info() {
  $items = array(
    'quote' => array(
      'name' => t('Quote'),
      'base' => 'node_content',
      'description' => t('This allows creation and management of a quote in rich text format.'),
      'has_title' => '1',
      'title_label' => t('Quote Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

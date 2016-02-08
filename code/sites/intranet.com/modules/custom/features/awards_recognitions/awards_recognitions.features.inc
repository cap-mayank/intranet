<?php
/**
 * @file
 * awards_recognitions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function awards_recognitions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function awards_recognitions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function awards_recognitions_node_info() {
  $items = array(
    'award' => array(
      'name' => t('Award'),
      'base' => 'node_content',
      'description' => t('It captures awards and recognition created for different users.'),
      'has_title' => '1',
      'title_label' => t('Award Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

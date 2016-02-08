<?php
/**
 * @file
 * holiday_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function holiday_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "multifield" && $api == "") {
    return array("version" => "");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function holiday_calendar_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function holiday_calendar_node_info() {
  $items = array(
    'holiday_calendar' => array(
      'name' => t('Holiday Calendar'),
      'base' => 'node_content',
      'description' => t('Provides widget for holiday calendar in home page. Admin can mange holidays and add a new holiday calendar year.'),
      'has_title' => '1',
      'title_label' => t('Holiday calendar year'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

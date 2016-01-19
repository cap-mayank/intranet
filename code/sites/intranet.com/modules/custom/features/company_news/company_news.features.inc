<?php
/**
 * @file
 * company_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function company_news_ctools_plugin_api($module = NULL, $api = NULL) {
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
function company_news_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function company_news_node_info() {
  $items = array(
    'company_news' => array(
      'name' => t('Company News'),
      'base' => 'node_content',
      'description' => t('Managing company specific news which are in the interest of employees.
News can belong to one of he departments such as HR, finance etc.'),
      'has_title' => '1',
      'title_label' => t('News Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

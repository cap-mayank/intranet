<?php
/**
 * @file
 * quick_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function quick_link_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function quick_link_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function quick_link_image_default_styles() {
  $styles = array();

  // Exported image style: icon.
  $styles['icon'] = array(
    'label' => 'icon',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 20,
          'height' => 20,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function quick_link_node_info() {
  $items = array(
    'quick_link' => array(
      'name' => t('Quick Link'),
      'base' => 'node_content',
      'description' => t('Quick Link'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

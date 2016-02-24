<?php
/**
 * @file
 * units.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function units_ctools_plugin_api($module = NULL, $api = NULL) {
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
function units_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function units_image_default_styles() {
  $styles = array();

  // Exported image style: units_images.
  $styles['units_images'] = array(
    'label' => 'units_images',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 380,
          'height' => 250,
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
function units_node_info() {
  $items = array(
    'units' => array(
      'name' => t('Units'),
      'base' => 'node_content',
      'description' => t('Sakal Units should added here. Units will display under Units menulink of main menu.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

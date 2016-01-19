<?php
/**
 * @file
 * sakal_properties.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sakal_properties_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sakal_properties_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sakal_properties_image_default_styles() {
  $styles = array();

  // Exported image style: property_image.
  $styles['property_image'] = array(
    'label' => 'property_image',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 259,
          'height' => 121,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: property_logo.
  $styles['property_logo'] = array(
    'label' => 'property_logo',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 68,
          'height' => 27,
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
function sakal_properties_node_info() {
  $items = array(
    'sakal_properties' => array(
      'name' => t('Sakal Properties'),
      'base' => 'node_content',
      'description' => t('Sakal Properties'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

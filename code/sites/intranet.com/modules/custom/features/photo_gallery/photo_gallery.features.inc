<?php
/**
 * @file
 * photo_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function photo_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
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
function photo_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function photo_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: photo_gallery_grid_image.
  $styles['photo_gallery_grid_image'] = array(
    'label' => 'photo_gallery_grid_image',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 106,
          'height' => 106,
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
function photo_gallery_node_info() {
  $items = array(
    'photo_gallery' => array(
      'name' => t('photo gallery'),
      'base' => 'node_content',
      'description' => t('photo gallery'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

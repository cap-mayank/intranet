<?php
/**
 * @file
 * cxo_s_messages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cxo_s_messages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cxo_s_messages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cxo_s_messages_image_default_styles() {
  $styles = array();

  // Exported image style: cxo-message-user.
  $styles['cxo-message-user'] = array(
    'label' => 'cxo-message-user',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 170,
          'height' => 180,
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
function cxo_s_messages_node_info() {
  $items = array(
    'cxo_messages' => array(
      'name' => t('CXO messages'),
      'base' => 'node_content',
      'description' => t('CXO messages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

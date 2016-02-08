<?php
/**
 * @file
 * event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function event_image_default_styles() {
  $styles = array();

  // Exported image style: cxo_and_event_widget.
  $styles['cxo_and_event_widget'] = array(
    'label' => 'cxo and event widget',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: event_widget_listing_style.
  $styles['event_widget_listing_style'] = array(
    'label' => 'Event widget listing style',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: photo_gallery_and_event.
  $styles['photo_gallery_and_event'] = array(
    'label' => 'photo gallery and event',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
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
function event_node_info() {
  $items = array(
    'event_calendar' => array(
      'name' => t('Event Calendar'),
      'base' => 'node_content',
      'description' => t('A content type to create events for calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

<?php
/**
 * @file
 * cluster_of_link.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_of_link_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "multifield" && $api == "") {
    return array("version" => "");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cluster_of_link_image_default_styles() {
  $styles = array();

  // Exported image style: all_application.
  $styles['all_application'] = array(
    'label' => 'all_application',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 90,
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
function cluster_of_link_node_info() {
  $items = array(
    'cluster_of_links' => array(
      'name' => t('Cluster Of Links'),
      'base' => 'node_content',
      'description' => t('cluster of links'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

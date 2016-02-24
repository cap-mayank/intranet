<?php
/**
 * @file
 * video_gallery.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function video_gallery_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_alert:admin/structure/block/manage/block/1/configure.
  $menu_links['navigation_alert:admin/structure/block/manage/block/1/configure'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'admin/structure/block/manage/block/1/configure',
    'router_path' => 'admin/structure/block/manage/%/%/configure',
    'link_title' => 'Alert',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage content of Alert Widget',
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'navigation_alert:admin/structure/block/manage/block/1/configure',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alert');

  return $menu_links;
}

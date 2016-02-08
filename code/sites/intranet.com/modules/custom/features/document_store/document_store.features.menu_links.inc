<?php
/**
 * @file
 * document_store.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function document_store_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_document-store:filedepot.
  $menu_links['management_document-store:filedepot'] = array(
    'menu_name' => 'management',
    'link_path' => 'filedepot',
    'router_path' => 'filedepot',
    'link_title' => 'Document Store',
    'options' => array(
      'identifier' => 'management_document-store:filedepot',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'management_content:admin/content',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Document Store');

  return $menu_links;
}

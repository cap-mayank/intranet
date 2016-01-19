<?php
/**
 * @file
 * cxo_s_messages.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cxo_s_messages_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_publish-your-message:node/add/cxo-messages.
  $menu_links['main-menu_publish-your-message:node/add/cxo-messages'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/cxo-messages',
    'router_path' => 'node/add',
    'link_title' => 'Publish Your Message',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_publish-your-message:node/add/cxo-messages',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Publish Your Message');

  return $menu_links;
}

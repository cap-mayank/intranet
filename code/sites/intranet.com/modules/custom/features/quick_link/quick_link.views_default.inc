<?php
/**
 * @file
 * quick_link.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function quick_link_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'quick_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Quick Links';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quick Links';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Field collection item: Link Icon (field_widget_link_icon:fid) */
  $handler->display->display_options['relationships']['field_widget_link_icon_fid']['id'] = 'field_widget_link_icon_fid';
  $handler->display->display_options['relationships']['field_widget_link_icon_fid']['table'] = 'field_data_field_widget_link_icon';
  $handler->display->display_options['relationships']['field_widget_link_icon_fid']['field'] = 'field_widget_link_icon_fid';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View All >';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'quick-links#overlay-context=content/current-page-current-date';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Link Icon */
  $handler->display->display_options['fields']['field_widget_link_icon']['id'] = 'field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['table'] = 'field_data_field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['field'] = 'field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['label'] = '';
  $handler->display->display_options['fields']['field_widget_link_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_link_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_widget_link_icon']['settings'] = array(
    'image_style' => 'icon',
    'image_link' => '',
  );
  /* Field: Field collection item: Widgets Link */
  $handler->display->display_options['fields']['field_widget_link']['id'] = 'field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['table'] = 'field_data_field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['field'] = 'field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['label'] = '';
  $handler->display->display_options['fields']['field_widget_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_link']['click_sort_column'] = 'url';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Link Icon */
  $handler->display->display_options['fields']['field_widget_link_icon']['id'] = 'field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['table'] = 'field_data_field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['field'] = 'field_widget_link_icon';
  $handler->display->display_options['fields']['field_widget_link_icon']['label'] = '';
  $handler->display->display_options['fields']['field_widget_link_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_link_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_widget_link_icon']['settings'] = array(
    'image_style' => 'icon',
    'image_link' => '',
  );
  /* Field: Field collection item: Widgets Link */
  $handler->display->display_options['fields']['field_widget_link']['id'] = 'field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['table'] = 'field_data_field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['field'] = 'field_widget_link';
  $handler->display->display_options['fields']['field_widget_link']['label'] = '';
  $handler->display->display_options['fields']['field_widget_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_widget_link']['click_sort_column'] = 'url';
  $handler->display->display_options['path'] = 'quick-links';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_widget_link_icon' => 'field_widget_link_icon',
    'field_widget_link' => 'field_widget_link',
    'nothing' => 'nothing',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_widget_link_icon' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_widget_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[nothing_1]';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $export['quick_links'] = $view;

  return $export;
}

<?php
/**
 * @file
 * unites.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function unites_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'units';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Units';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Units';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Unit Head name */
  $handler->display->display_options['fields']['field_unit_head']['id'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['table'] = 'field_data_field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['field'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['label'] = 'Head';
  /* Field: Content: Short Introduction */
  $handler->display->display_options['fields']['field_unit_intro']['id'] = 'field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['table'] = 'field_data_field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['field'] = 'field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['label'] = '';
  $handler->display->display_options['fields']['field_unit_intro']['element_label_colon'] = FALSE;
  /* Field: Content: Unit Images (field_unit_images:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_unit_images';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'unites' => 'unites',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Unit Images */
  $handler->display->display_options['fields']['field_unit_images']['id'] = 'field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['table'] = 'field_data_field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['field'] = 'field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['label'] = '';
  $handler->display->display_options['fields']['field_unit_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_unit_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_unit_images']['settings'] = array(
    'image_style' => 'photo_gallery_and_event',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_unit_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_unit_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Unit Head name */
  $handler->display->display_options['fields']['field_unit_head']['id'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['table'] = 'field_data_field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['field'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['label'] = 'Head';
  $handler->display->display_options['fields']['field_unit_head']['type'] = 'text_plain';
  /* Field: Content: Unit Email */
  $handler->display->display_options['fields']['field_unit_email']['id'] = 'field_unit_email';
  $handler->display->display_options['fields']['field_unit_email']['table'] = 'field_data_field_unit_email';
  $handler->display->display_options['fields']['field_unit_email']['field'] = 'field_unit_email';
  $handler->display->display_options['path'] = 'units';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Units';
  $handler->display->display_options['menu']['description'] = 'Sakal units';
  $handler->display->display_options['menu']['weight'] = '7';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Unit Images */
  $handler->display->display_options['fields']['field_unit_images']['id'] = 'field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['table'] = 'field_data_field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['field'] = 'field_unit_images';
  $handler->display->display_options['fields']['field_unit_images']['label'] = '';
  $handler->display->display_options['fields']['field_unit_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_unit_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_unit_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_unit_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_unit_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Short Introduction */
  $handler->display->display_options['fields']['field_unit_intro']['id'] = 'field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['table'] = 'field_data_field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['field'] = 'field_unit_intro';
  $handler->display->display_options['fields']['field_unit_intro']['label'] = '';
  $handler->display->display_options['fields']['field_unit_intro']['element_label_colon'] = FALSE;
  /* Field: Content: Unit Head name */
  $handler->display->display_options['fields']['field_unit_head']['id'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['table'] = 'field_data_field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['field'] = 'field_unit_head';
  $handler->display->display_options['fields']['field_unit_head']['label'] = 'Head';
  $export['units'] = $view;

  return $export;
}

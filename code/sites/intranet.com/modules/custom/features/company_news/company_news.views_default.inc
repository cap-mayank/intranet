<?php
/**
 * @file
 * company_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function company_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'company_news_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Company News View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Company News ';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  /* Relationship: Content: Brand (field_brand) */
  $handler->display->display_options['relationships']['field_brand_tid']['id'] = 'field_brand_tid';
  $handler->display->display_options['relationships']['field_brand_tid']['table'] = 'field_data_field_brand';
  $handler->display->display_options['relationships']['field_brand_tid']['field'] = 'field_brand_tid';
  /* Field: Taxonomy term: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['relationship'] = 'field_brand_tid';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Date */
  $handler->display->display_options['fields']['field_publishing_date']['id'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['table'] = 'field_data_field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['field'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['label'] = '';
  $handler->display->display_options['fields']['field_publishing_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publishing_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['table'] = 'field_data_field_brand';
  $handler->display->display_options['fields']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['label'] = '';
  $handler->display->display_options['fields']['field_brand']['element_label_colon'] = FALSE;
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
    'company_news' => 'company_news',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_department_tid']['id'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['table'] = 'field_data_field_department';
  $handler->display->display_options['filters']['field_department_tid']['field'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['operator'] = 'or';
  $handler->display->display_options['filters']['field_department_tid']['value'] = array();
  $handler->display->display_options['filters']['field_department_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator_id'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['label'] = 'Department Filter';
  $handler->display->display_options['filters']['field_department_tid']['expose']['description'] = 'Filter the news items according to department';
  $handler->display->display_options['filters']['field_department_tid']['expose']['operator'] = 'field_department_tid_op';
  $handler->display->display_options['filters']['field_department_tid']['expose']['identifier'] = 'field_department_tid';
  $handler->display->display_options['filters']['field_department_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no company news for applied criteria found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Thumbnail */
  $handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
  $handler->display->display_options['fields']['field_thumbnail']['relationship'] = 'field_brand_tid';
  $handler->display->display_options['fields']['field_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Brand */
  $handler->display->display_options['fields']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['table'] = 'field_data_field_brand';
  $handler->display->display_options['fields']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['fields']['field_brand']['label'] = '';
  $handler->display->display_options['fields']['field_brand']['element_label_colon'] = FALSE;
  /* Field: Field: Date */
  $handler->display->display_options['fields']['field_publishing_date']['id'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['table'] = 'field_data_field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['field'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['label'] = '';
  $handler->display->display_options['fields']['field_publishing_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publishing_date']['settings'] = array(
    'format_type' => 'announcement_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'company_news' => 'company_news',
  );
  /* Filter criterion: Content: Brand (field_brand) */
  $handler->display->display_options['filters']['field_brand_tid']['id'] = 'field_brand_tid';
  $handler->display->display_options['filters']['field_brand_tid']['table'] = 'field_data_field_brand';
  $handler->display->display_options['filters']['field_brand_tid']['field'] = 'field_brand_tid';
  $handler->display->display_options['filters']['field_brand_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_brand_tid']['expose']['operator_id'] = 'field_brand_tid_op';
  $handler->display->display_options['filters']['field_brand_tid']['expose']['label'] = 'Department ';
  $handler->display->display_options['filters']['field_brand_tid']['expose']['operator'] = 'field_brand_tid_op';
  $handler->display->display_options['filters']['field_brand_tid']['expose']['identifier'] = 'field_brand_tid';
  $handler->display->display_options['filters']['field_brand_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_brand_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_brand_tid']['vocabulary'] = 'brand';
  /* Filter criterion: Field: Location (field_location) */
  $handler->display->display_options['filters']['field_location_tid']['id'] = 'field_location_tid';
  $handler->display->display_options['filters']['field_location_tid']['table'] = 'field_data_field_location';
  $handler->display->display_options['filters']['field_location_tid']['field'] = 'field_location_tid';
  $handler->display->display_options['filters']['field_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_location_tid']['expose']['operator_id'] = 'field_location_tid_op';
  $handler->display->display_options['filters']['field_location_tid']['expose']['label'] = 'Venue ';
  $handler->display->display_options['filters']['field_location_tid']['expose']['operator'] = 'field_location_tid_op';
  $handler->display->display_options['filters']['field_location_tid']['expose']['identifier'] = 'field_location_tid';
  $handler->display->display_options['filters']['field_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_location_tid']['vocabulary'] = 'location';
  $handler->display->display_options['path'] = 'companynews';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View All';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'company_news_slider';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'flexslider_full',
    'image_link' => '',
  );
  /* Field: Field: Date */
  $handler->display->display_options['fields']['field_publishing_date']['id'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['table'] = 'field_data_field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['field'] = 'field_publishing_date';
  $handler->display->display_options['fields']['field_publishing_date']['label'] = '';
  $handler->display->display_options['fields']['field_publishing_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publishing_date']['settings'] = array(
    'format_type' => 'announcement_date_format',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'company_news' => 'company_news',
  );
  $export['company_news_view'] = $view;

  return $export;
}

<?php
/**
 * @file
 * anniversary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function anniversary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'birthdays';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Birthdays';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Birthday';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'anniversary_slider_settings';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Birthday Monthwise */
  $handler = $view->new_display('block', 'Birthday Monthwise', 'birthday_monthwise');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Birthday Monthwise';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Birthday (birthdays:day) */
  $handler->display->display_options['sorts']['birthdays_day']['id'] = 'birthdays_day';
  $handler->display->display_options['sorts']['birthdays_day']['table'] = 'field_data_birthdays';
  $handler->display->display_options['sorts']['birthdays_day']['field'] = 'birthdays_day';
  $handler->display->display_options['sorts']['birthdays_day']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Birthday (birthdays:month) */
  $handler->display->display_options['arguments']['birthdays_month']['id'] = 'birthdays_month';
  $handler->display->display_options['arguments']['birthdays_month']['table'] = 'field_data_birthdays';
  $handler->display->display_options['arguments']['birthdays_month']['field'] = 'birthdays_month';
  $handler->display->display_options['arguments']['birthdays_month']['default_action'] = 'default';
  $handler->display->display_options['arguments']['birthdays_month']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['birthdays_month']['default_argument_options']['code'] = 'return date(\'m\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['birthdays_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['birthdays_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['birthdays_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Anniversary Monthwise */
  $handler = $view->new_display('block', 'Anniversary Monthwise', 'anniversary_monthwise');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Anniversary Monthwise';
  $handler->display->display_options['display_description'] = 'The block displays users having work anniversary in configured interval of time.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Created month */
  $handler->display->display_options['arguments']['created_month']['id'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['table'] = 'users';
  $handler->display->display_options['arguments']['created_month']['field'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['default_action'] = 'default';
  $handler->display->display_options['arguments']['created_month']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['created_month']['default_argument_options']['code'] = 'return date(\'m\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['created_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Birthday Daywise */
  $handler = $view->new_display('block', 'Birthday Daywise', 'birthday_daywise');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Birthday Daywise';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Birthday (birthdays:month) */
  $handler->display->display_options['arguments']['birthdays_month']['id'] = 'birthdays_month';
  $handler->display->display_options['arguments']['birthdays_month']['table'] = 'field_data_birthdays';
  $handler->display->display_options['arguments']['birthdays_month']['field'] = 'birthdays_month';
  $handler->display->display_options['arguments']['birthdays_month']['default_action'] = 'default';
  $handler->display->display_options['arguments']['birthdays_month']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['birthdays_month']['default_argument_options']['code'] = 'return date(\'m\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['birthdays_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['birthdays_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['birthdays_month']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Birthday (birthdays:day) */
  $handler->display->display_options['arguments']['birthdays_day']['id'] = 'birthdays_day';
  $handler->display->display_options['arguments']['birthdays_day']['table'] = 'field_data_birthdays';
  $handler->display->display_options['arguments']['birthdays_day']['field'] = 'birthdays_day';
  $handler->display->display_options['arguments']['birthdays_day']['default_action'] = 'default';
  $handler->display->display_options['arguments']['birthdays_day']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['birthdays_day']['default_argument_options']['code'] = 'return date(\'d\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['birthdays_day']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['birthdays_day']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['birthdays_day']['summary_options']['items_per_page'] = '25';

  /* Display: Anniversary Daywise */
  $handler = $view->new_display('block', 'Anniversary Daywise', 'anniversary_daywise');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Anniversary Daywise';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Created month */
  $handler->display->display_options['arguments']['created_month']['id'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['table'] = 'users';
  $handler->display->display_options['arguments']['created_month']['field'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['default_action'] = 'default';
  $handler->display->display_options['arguments']['created_month']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['created_month']['default_argument_options']['code'] = 'return date(\'m\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['created_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_month']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Created day */
  $handler->display->display_options['arguments']['created_day']['id'] = 'created_day';
  $handler->display->display_options['arguments']['created_day']['table'] = 'users';
  $handler->display->display_options['arguments']['created_day']['field'] = 'created_day';
  $handler->display->display_options['arguments']['created_day']['default_action'] = 'default';
  $handler->display->display_options['arguments']['created_day']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['created_day']['default_argument_options']['code'] = 'return date(\'d\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['created_day']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_day']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_day']['summary_options']['items_per_page'] = '25';

  /* Display: Recent Joiner Monthwise */
  $handler = $view->new_display('block', 'Recent Joiner Monthwise', 'recent_joiner_monthwise');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Joiner';
  $handler->display->display_options['display_description'] = 'Monthwise recent joinee';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'anniversary_slider_settings';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Created year */
  $handler->display->display_options['arguments']['created_year']['id'] = 'created_year';
  $handler->display->display_options['arguments']['created_year']['table'] = 'users';
  $handler->display->display_options['arguments']['created_year']['field'] = 'created_year';
  $handler->display->display_options['arguments']['created_year']['default_action'] = 'default';
  $handler->display->display_options['arguments']['created_year']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['created_year']['default_argument_options']['code'] = 'return date(\'Y\');';
  $handler->display->display_options['arguments']['created_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: User: Created month */
  $handler->display->display_options['arguments']['created_month']['id'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['table'] = 'users';
  $handler->display->display_options['arguments']['created_month']['field'] = 'created_month';
  $handler->display->display_options['arguments']['created_month']['default_action'] = 'default';
  $handler->display->display_options['arguments']['created_month']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['created_month']['default_argument_options']['code'] = 'return date(\'m\', REQUEST_TIME);';
  $handler->display->display_options['arguments']['created_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_month']['summary_options']['items_per_page'] = '25';
  $export['birthdays'] = $view;

  return $export;
}

<?php
/**
 * @file
 * document_store.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function document_store_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'policy_and_procedures';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Policy Procedures';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Document Store';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'readroles' => 'readroles',
    'downloadroles' => 'downloadroles',
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: Content: Files (filedepot_folder_file:fid) */
  $handler->display->display_options['relationships']['filedepot_folder_file_fid']['id'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['relationships']['filedepot_folder_file_fid']['table'] = 'field_data_filedepot_folder_file';
  $handler->display->display_options['relationships']['filedepot_folder_file_fid']['field'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['relationships']['filedepot_folder_file_fid']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Filedepot Files: Title shown when adding the relationship */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'filedepot_files';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  $handler->display->display_options['relationships']['cid']['relationship'] = 'filedepot_folder_file_fid';
  /* Relationship: Filedepot Access: filedepot_categories with filedepot_access */
  $handler->display->display_options['relationships']['catid']['id'] = 'catid';
  $handler->display->display_options['relationships']['catid']['table'] = 'filedepot_access';
  $handler->display->display_options['relationships']['catid']['field'] = 'catid';
  $handler->display->display_options['relationships']['catid']['relationship'] = 'cid';
  $handler->display->display_options['relationships']['catid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'post_date';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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
    'filedepot_folder' => 'filedepot_folder',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Filedepot Access: Permission Type */
  $handler->display->display_options['filters']['permtype']['id'] = 'permtype';
  $handler->display->display_options['filters']['permtype']['table'] = 'filedepot_access';
  $handler->display->display_options['filters']['permtype']['field'] = 'permtype';
  $handler->display->display_options['filters']['permtype']['relationship'] = 'cid';
  $handler->display->display_options['filters']['permtype']['operator'] = 'allwords';
  $handler->display->display_options['filters']['permtype']['value'] = 'role';
  $handler->display->display_options['filters']['permtype']['group'] = 1;
  /* Filter criterion: Filedepot Access: View Access */
  $handler->display->display_options['filters']['view']['id'] = 'view';
  $handler->display->display_options['filters']['view']['table'] = 'filedepot_access';
  $handler->display->display_options['filters']['view']['field'] = 'view';
  $handler->display->display_options['filters']['view']['relationship'] = 'cid';
  $handler->display->display_options['filters']['view']['value']['value'] = '1';
  $handler->display->display_options['filters']['view']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'policy_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[nothing]';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: File ID */
  $handler->display->display_options['fields']['fid_1']['id'] = 'fid_1';
  $handler->display->display_options['fields']['fid_1']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['fid_1']['field'] = 'fid';
  $handler->display->display_options['fields']['fid_1']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['fid_1']['label'] = '';
  $handler->display->display_options['fields']['fid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid_1']['element_label_colon'] = FALSE;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'cxo_message_date_formate';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filemime']['filemime_image'] = TRUE;
  /* Field: Filedepot Files: File Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['rel'] = 'rel="lightframe[|width:400px; height:300px; scrolling: auto;]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View All ';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'policy-and-procedures';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: Readonly permission */
  $handler->display->display_options['fields']['readroles']['id'] = 'readroles';
  $handler->display->display_options['fields']['readroles']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['readroles']['field'] = 'readroles';
  $handler->display->display_options['fields']['readroles']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['readroles']['label'] = '';
  $handler->display->display_options['fields']['readroles']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['text'] = '<div class="readonly-mode"><img src="/sites/intranet.com/themes/intranet/images/emblem-readonly.png"/></div>';
  $handler->display->display_options['fields']['readroles']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['readroles']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['readroles']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['readroles']['element_default_classes'] = FALSE;
  /* Field: Filedepot Files: Download permission */
  $handler->display->display_options['fields']['downloadroles']['id'] = 'downloadroles';
  $handler->display->display_options['fields']['downloadroles']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['downloadroles']['field'] = 'downloadroles';
  $handler->display->display_options['fields']['downloadroles']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['downloadroles']['label'] = '';
  $handler->display->display_options['fields']['downloadroles']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['text'] = '<div class="download-mode"><img src="/sites/intranet.com/themes/intranet/images/download.png"/></div>';
  $handler->display->display_options['fields']['downloadroles']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['downloadroles']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['downloadroles']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: File Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['extension']['label'] = '';
  $handler->display->display_options['fields']['extension']['exclude'] = TRUE;
  $handler->display->display_options['fields']['extension']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'policy_page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'filemime' => 'filemime',
    'title' => 'title',
    'readroles' => 'readroles',
    'downloadroles' => 'downloadroles',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: File ID */
  $handler->display->display_options['fields']['fid_1']['id'] = 'fid_1';
  $handler->display->display_options['fields']['fid_1']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['fid_1']['field'] = 'fid';
  $handler->display->display_options['fields']['fid_1']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['fid_1']['label'] = '';
  $handler->display->display_options['fields']['fid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid_1']['element_label_colon'] = FALSE;
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filemime']['filemime_image'] = TRUE;
  /* Field: Filedepot Files: File Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: Readonly permission */
  $handler->display->display_options['fields']['readroles']['id'] = 'readroles';
  $handler->display->display_options['fields']['readroles']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['readroles']['field'] = 'readroles';
  $handler->display->display_options['fields']['readroles']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['readroles']['label'] = '';
  $handler->display->display_options['fields']['readroles']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['text'] = '<div class="readonly-mode"><img src="/sites/intranet.com/themes/intranet/images/emblem-readonly.png"/></div>';
  $handler->display->display_options['fields']['readroles']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['readroles']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['readroles']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['readroles']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: Category Id */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  /* Field: Filedepot Folders: Folder Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'filedepot_categories';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'cid';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Filedepot Files: File Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['extension']['exclude'] = TRUE;
  /* Field: Filedepot Files: Download permission */
  $handler->display->display_options['fields']['downloadroles']['id'] = 'downloadroles';
  $handler->display->display_options['fields']['downloadroles']['table'] = 'filedepot_files';
  $handler->display->display_options['fields']['downloadroles']['field'] = 'downloadroles';
  $handler->display->display_options['fields']['downloadroles']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['downloadroles']['label'] = '';
  $handler->display->display_options['fields']['downloadroles']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['text'] = '<div class="download-mode"><img src="/sites/intranet.com/themes/intranet/images/download.png"/></div>';
  $handler->display->display_options['fields']['downloadroles']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['path'] = 'node/[nid]/[fid_1]';
  $handler->display->display_options['fields']['downloadroles']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['downloadroles']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['downloadroles']['element_label_colon'] = FALSE;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'filedepot_folder_file_fid';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'document_store_date_formate';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M,d, 2015';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'By [name] &nbsp;&nbsp;&nbsp;&nbsp;[timestamp]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['path'] = 'policy-and-procedures';
  $export['policy_and_procedures'] = $view;

  return $export;
}

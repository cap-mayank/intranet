<?php
/**
 * @file
 * document_store.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function document_store_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-filedepot_folder-filedepot_folder_desc'.
  $field_instances['node-filedepot_folder-filedepot_folder_desc'] = array(
    'bundle' => 'filedepot_folder',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'filedepot_folder_desc',
    'label' => 'Folder Description',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-filedepot_folder-filedepot_folder_file'.
  $field_instances['node-filedepot_folder-filedepot_folder_file'] = array(
    'bundle' => 'filedepot_folder',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'filedepot_folder_file',
    'label' => 'Files',
    'required' => FALSE,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'filedepot',
      'file_extensions' => 'txt pdf xls doc',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'translatable' => 0,
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Files');
  t('Folder Description');

  return $field_instances;
}

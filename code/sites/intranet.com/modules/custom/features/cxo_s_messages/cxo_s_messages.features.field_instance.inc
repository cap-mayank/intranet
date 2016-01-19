<?php
/**
 * @file
 * cxo_s_messages.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cxo_s_messages_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cxo_messages-body'.
  $field_instances['node-cxo_messages-body'] = array(
    'bundle' => 'cxo_messages',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter  message here',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Message',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Message');
  t('Please enter  message here');

  return $field_instances;
}

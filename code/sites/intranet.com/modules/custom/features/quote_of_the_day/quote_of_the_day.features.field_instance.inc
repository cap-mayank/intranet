<?php
/**
 * @file
 * quote_of_the_day.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function quote_of_the_day_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-quote-body'.
  $field_instances['node-quote-body'] = array(
    'bundle' => 'quote',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter the quote along with optional specification of credits.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'body',
    'label' => 'Quote',
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
  t('Please enter the quote along with optional specification of credits.');
  t('Quote');

  return $field_instances;
}

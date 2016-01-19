<?php
/**
 * @file
 * quote_of_the_day.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function quote_of_the_day_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_quote'.
  $field_bases['field_quote'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_quote',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}

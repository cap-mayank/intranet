<?php
/**
 * @file
 * holiday_calendar.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function holiday_calendar_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_calendar_year'.
  $field_bases['field_calendar_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_calendar_year',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'month' => 0,
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_holiday'.
  $field_bases['field_holiday'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_holiday',
    'indexes' => array(
      'field_holiday_name_format' => array(
        0 => 'field_holiday_name_format',
      ),
      'field_location_tid' => array(
        0 => 'field_location_tid',
      ),
      'id' => array(
        0 => 'id',
      ),
    ),
    'locked' => 0,
    'module' => 'multifield',
    'settings' => array(
      'entity_translation_sync' => array(
        0 => 'id',
      ),
      'hide_blank_items' => 1,
    ),
    'translatable' => 0,
    'type' => 'multifield',
  );

  // Exported field_base: 'field_holiday_name'.
  $field_bases['field_holiday_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_holiday_name',
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

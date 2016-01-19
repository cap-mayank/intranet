<?php
/**
 * @file
 * holiday_calendar..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function holiday_calendar_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_holiday';
  $multifield->label = 'field_holiday';
  $multifield->description = '';
  $export['field_holiday'] = $multifield;

  return $export;
}

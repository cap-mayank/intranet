<?php
/**
 * @file
 * holiday_calendar.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function holiday_calendar_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique Calender year value';
  $rule->name = 'unique_calender_year_value';
  $rule->field_name = 'field_calendar_year';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'holiday_calendar';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      3 => 0,
      7 => 0,
      6 => 0,
      5 => 0,
      4 => 0,
      2 => 0,
      1 => 0,
    ),
    'errors' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'This calendar year already exists. please enter unique value.';
  $export['unique_calender_year_value'] = $rule;

  return $export;
}

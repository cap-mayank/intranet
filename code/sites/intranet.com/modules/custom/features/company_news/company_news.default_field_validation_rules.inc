<?php
/**
 * @file
 * company_news.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function company_news_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Cnews Invalid Future Date';
  $rule->name = 'cnews_future_invalid_date';
  $rule->field_name = 'field_publishing_date';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'company_news';
  $rule->validator = 'field_validation_date_range2_validator';
  $rule->settings = array(
    'cycle' => 'global',
    'min' => '',
    'max' => 'now',
    'reverse' => 0,
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
  $rule->error_message = 'Entering future date is not allowed.';
  $export['cnews_future_invalid_date'] = $rule;

  return $export;
}

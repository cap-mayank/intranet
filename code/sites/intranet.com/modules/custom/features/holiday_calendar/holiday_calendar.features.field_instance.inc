<?php
/**
 * @file
 * holiday_calendar.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function holiday_calendar_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'multifield-field_holiday-field_holiday_name'.
  $field_instances['multifield-field_holiday-field_holiday_name'] = array(
    'bundle' => 'field_holiday',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the occasion for which the holiday is planned.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_holiday_name',
    'label' => 'Holiday Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'multifield-field_holiday-field_location'.
  $field_instances['multifield-field_holiday-field_location'] = array(
    'bundle' => 'field_holiday',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select if the location is meant for particular one. (optional)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'multifield-field_holiday-field_publishing_date'.
  $field_instances['multifield-field_holiday-field_publishing_date'] = array(
    'bundle' => 'field_holiday',
    'deleted' => 0,
    'description' => 'Enter the date on which holiday shall be given.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_publishing_date',
    'label' => 'Holiday Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-holiday_calendar-field_holiday'.
  $field_instances['node-holiday_calendar-field_holiday'] = array(
    'bundle' => 'holiday_calendar',
    'default_value' => array(
      0 => array(
        'field_holiday_name' => array(
          'und' => array(
            0 => array(
              'value' => '',
            ),
          ),
        ),
        'field_publishing_date' => array(
          'und' => array(
            0 => array(
              'value' => '2016-01-11 19:15:00',
              'show_todate' => TRUE,
              'timezone' => 'Asia/Kolkata',
              'offset' => 19800,
              'offset2' => 19800,
              'value2' => '2016-01-11 19:15:00',
            ),
          ),
        ),
        'field_location' => array(
          'und' => array(
            0 => array(
              'tid' => NULL,
            ),
          ),
        ),
        'id' => NULL,
        'actions' => array(
          'remove_button' => 'Remove',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'multifield',
        'settings' => array(
          'view_mode' => 'default',
        ),
        'type' => 'multifield_default',
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
    'field_name' => 'field_holiday',
    'label' => 'Holiday',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => -3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter the date on which holiday shall be given.');
  t('Enter the occasion for which the holiday is planned.');
  t('Holiday');
  t('Holiday Date');
  t('Holiday Name');
  t('Location');
  t('Select if the location is meant for particular one. (optional)');

  return $field_instances;
}

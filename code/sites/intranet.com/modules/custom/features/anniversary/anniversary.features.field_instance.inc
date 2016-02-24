<?php
/**
 * @file
 * anniversary.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function anniversary_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-birthdays'.
  $field_instances['user-user-birthdays'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'triggers' => TRUE,
      ),
    ),
    'deleted' => 0,
    'description' => 'Please enter birthday.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'birthdays',
        'settings' => array(),
        'type' => 'birthdays_plaintext',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'birthdays',
    'label' => 'Birthday',
    'required' => 0,
    'settings' => array(
      'admin_mail' => 0,
      'dateformat' => 'd/m/Y',
      'datepicker' => 1,
      'hide_year' => 0,
      'triggers' => array(
        'description' => '',
        'title' => 'Fire triggers on birthdays',
        'user' => 0,
      ),
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'birthdays',
      'settings' => array(),
      'type' => 'birthdays_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'user-user-field__work_location'.
  $field_instances['user-user-field__work_location'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter your work location.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field__work_location',
    'label' => 'Location',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'user-user-field_designation'.
  $field_instances['user-user-field_designation'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter your designation.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_designation',
    'label' => 'Designation',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'user-user-field_email'.
  $field_instances['user-user-field_email'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter email of the employee.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'user-user-field_employee_joining_date'.
  $field_instances['user-user-field_employee_joining_date'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'triggers' => TRUE,
      ),
    ),
    'deleted' => 0,
    'description' => 'Please enter the date on which employee joined.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'birthdays',
        'settings' => array(),
        'type' => 'birthdays_plaintext',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_employee_joining_date',
    'label' => 'Employee Joining date',
    'required' => 0,
    'settings' => array(
      'admin_mail' => 0,
      'dateformat' => 'd/m/Y',
      'datepicker' => 1,
      'hide_year' => 0,
      'triggers' => array(
        'description' => '',
        'title' => 'Fire triggers on birthdays',
        'user' => 0,
      ),
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'birthdays',
      'settings' => array(),
      'type' => 'birthdays_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'user-user-field_first_name'.
  $field_instances['user-user-field_first_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter first name of employee.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_first_name',
    'label' => 'First Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'user-user-field_last_name'.
  $field_instances['user-user-field_last_name'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter last name.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_last_name',
    'label' => 'Last Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'user-user-field_offiice_phone_no'.
  $field_instances['user-user-field_offiice_phone_no'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the employee\'s office provided phone no.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_offiice_phone_no',
    'label' => 'Offiice Phone No',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'user-user-field_project'.
  $field_instances['user-user-field_project'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter the project which you are assigned to.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_project',
    'label' => 'Project',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Birthday');
  t('Designation');
  t('Email');
  t('Employee Joining date');
  t('Enter the employee\'s office provided phone no.');
  t('First Name');
  t('Last Name');
  t('Location');
  t('Offiice Phone No');
  t('Please enter birthday.');
  t('Please enter email of the employee.');
  t('Please enter first name of employee.');
  t('Please enter last name.');
  t('Please enter the date on which employee joined.');
  t('Please enter the project which you are assigned to.');
  t('Please enter your designation.');
  t('Please enter your work location.');
  t('Project');

  return $field_instances;
}

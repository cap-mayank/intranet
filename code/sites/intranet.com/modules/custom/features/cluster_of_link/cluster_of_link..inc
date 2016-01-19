<?php
/**
 * @file
 * cluster_of_link..inc
 */

/**
 * Implements hook_multifield_default_multifield().
 */
function cluster_of_link_multifield_default_multifield() {
  $export = array();

  $multifield = new stdClass();
  $multifield->disabled = FALSE; /* Edit this to true to make a default multifield disabled initially */
  $multifield->machine_name = 'field_link_details';
  $multifield->label = 'field_link_details';
  $multifield->description = '';
  $export['field_link_details'] = $multifield;

  return $export;
}

<?php
/**
 * @file
 * cluster_of_link.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cluster_of_link_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'multifield-field_link_details-field_clustor_link_icon'.
  $field_instances['multifield-field_link_details-field_clustor_link_icon'] = array(
    'bundle' => 'field_link_details',
    'deleted' => 0,
    'description' => 'Please upload link icon here',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'all_application',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_clustor_link_icon',
    'label' => 'Link Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '2 MB',
      'max_resolution' => '90x90',
      'min_resolution' => '50x50',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'multifield-field_link_details-field_link'.
  $field_instances['multifield-field_link_details-field_link'] = array(
    'bundle' => 'field_link_details',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter link title & url ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'multifield',
    'field_name' => 'field_link',
    'label' => 'Link',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-cluster_of_links-field_link_details'.
  $field_instances['node-cluster_of_links-field_link_details'] = array(
    'bundle' => 'cluster_of_links',
    'default_value' => NULL,
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
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_link_details',
    'label' => 'Link Details',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multifield',
      'settings' => array(),
      'type' => 'multifield_default',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-cluster_of_links-field_linktype'.
  $field_instances['node-cluster_of_links-field_linktype'] = array(
    'bundle' => 'cluster_of_links',
    'default_value' => array(
      0 => array(
        'value' => 'All Applications',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select Link Type',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_linktype',
    'label' => 'Link Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Link');
  t('Link Details');
  t('Link Icon');
  t('Link Type');
  t('Please enter link title & url ');
  t('Please upload link icon here');
  t('Select Link Type');

  return $field_instances;
}

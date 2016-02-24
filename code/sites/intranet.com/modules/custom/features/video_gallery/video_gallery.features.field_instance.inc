<?php
/**
 * @file
 * video_gallery.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function video_gallery_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-video_gallery-field_upload_video'.
  $field_instances['node-video_gallery-field_upload_video'] = array(
    'bundle' => 'video_gallery',
    'deleted' => 0,
    'description' => 'Please upload video here',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
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
    'field_name' => 'field_upload_video',
    'label' => 'Upload Video',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'videos',
      'file_extensions' => 'mp4 flv',
      'max_filesize' => '8 MB',
      'resup' => 1,
      'resup_autostart' => 0,
      'resup_max_filesize' => '4 GB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Please upload video here');
  t('Upload Video');

  return $field_instances;
}

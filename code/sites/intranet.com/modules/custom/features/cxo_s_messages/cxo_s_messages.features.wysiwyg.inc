<?php
/**
 * @file
 * cxo_s_messages.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function cxo_s_messages_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'ckeditor_extended',
    'settings' => array(
      'default' => TRUE,
      'user_choose' => FALSE,
      'show_toggle' => FALSE,
      'theme' => 'advanced',
      'language' => 'en',
      'block_formats' => '',
      'toolbar' => array(
        0 => array(
          0 => 'Source',
          1 => '|',
          2 => 'Bold',
          3 => 'Italic',
          4 => '|',
          5 => 'NumberedList',
          6 => 'BulletedList',
          7 => 'Blockquote',
          8 => '|',
          9 => 'JustifyLeft',
          10 => 'JustifyCenter',
          11 => 'JustifyRight',
          12 => '|',
          13 => 'Link',
          14 => 'Unlink',
          15 => '|',
          16 => 'Maximize',
          17 => 'Strike',
          18 => 'Underline',
          19 => 'JustifyBlock',
          20 => 'Undo',
          21 => 'Indent',
          22 => 'Redo',
          23 => 'Outdent',
        ),
        1 => array(
          0 => 'Anchor',
          1 => 'Superscript',
          2 => 'Subscript',
          3 => 'Copy',
          4 => 'ShowBlocks',
          5 => 'Table',
          6 => 'RemoveFormat',
          7 => 'DrupalImage',
          8 => 'Styles',
          9 => 'DrupalBreak',
          10 => 'SpecialChar',
          11 => '|',
          12 => 'Format',
          13 => 'Cut',
          14 => 'Paste',
          15 => 'PasteFromWord',
          16 => 'PasteText',
          17 => 'HorizontalRule',
          18 => '|',
        ),
      ),
      'format_list' => array(
        0 => 'p',
        1 => 'h1',
        2 => 'h2',
        3 => 'h3',
        4 => 'h4',
        5 => 'h5',
        6 => 'h6',
      ),
      'style_list' => array(
        0 => '',
      ),
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}

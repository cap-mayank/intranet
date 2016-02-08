<?php

function intranet_form_system_theme_settings_alter(&$form, $form_state) {

  $theme_path = drupal_get_path('theme', 'intranet');
  $form['settings'] = array(
      '#type' => 'vertical_tabs',
      '#title' => t('Theme settings'),
      '#weight' => 2,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
	  '#attached' => array(
					'css' => array(drupal_get_path('theme', 'intranet') . '/css/drupalet_base/admin.css'),
					'js' => array(
						drupal_get_path('theme', 'intranet') . '/js/drupalet_admin/admin.js',
					),
			),
  );

  $form['settings']['layout'] = array(
      '#type' => 'fieldset',
      '#title' => t('Layout settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );
  
  $form['settings']['layout']['bg_image_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to custom background image'),
      '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
      '#default_value' => theme_get_setting('bg_image_path','intranet'),
  );
  $form['settings']['layout']['bg_image_upload'] = array(
      '#type' => 'file',
      '#title' => t('Upload background image'),
      '#maxlength' => 40,
      '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
   );/*
  $form['settings']['layout']['intranet_disable_switch'] = array(
      '#title' => t('Switcher style'),
      '#type' => 'select',
      '#options' => array('on' => t('ON'), 'off' => t('OFF')),
      '#default_value' => theme_get_setting('intranet_disable_switch', 'intranet'),

  );
  $form['settings']['layout']['layout_settings'] = array(
      '#type' => 'select',
      '#title' => t('Layout'),
	  '#options' => array('boxed-margin'=>t('Boxed margin'),'full'=>t('Full'), 'boxed'=>t('Boxed')),
      '#default_value' => theme_get_setting('layout_settings', 'intranet'),
  );
   $form['settings']['layout']['styling'] = array(
      '#type' => 'select',
      '#title' => t('Styling'),
      '#options' => array(
			'ltr' => 'Default (LTR)',
			'rtl' => 'RTL Version',
      ),
      '#default_value' => theme_get_setting('styling', 'intranet'),
  );
  $form['settings']['layout']['color_scheme'] = array(
      '#type' => 'textfield',
      '#title' => t('Color scheme'),
	  '#id' => t('colorpickerField1'),
	   '#description'  => t('Please enter a color code. <i>For example: #FF000 (red)</i>. Getting the color code here: <a href="http://html-color-codes.info/" target="_blank">http://html-color-codes.info/</a><br/><p><i>Leave blank if you want to use the default color.</i></p>'),
      '#default_value' => theme_get_setting('color_scheme', 'intranet'),
  );
   $form['settings']['layout']['version_c'] = array(
      '#type' => 'select',
      '#title' => t('Version'),
      '#options' => array(
			'light' => 'Light',
			'dark' => 'Dark',
      ),
      '#default_value' => theme_get_setting('version_c', 'intranet'),
  );
 */
  $form['settings']['header'] = array(
      '#type' => 'fieldset',
      '#title' => t('Header settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );
  
  $form['settings']['header']['header_image_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to custom header image'),
      '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
      '#default_value' => theme_get_setting('header_image_path','intranet'),
    );
    $form['settings']['header']['header_image_upload'] = array(
      '#type' => 'file',
      '#title' => t('Upload header image'),
      '#maxlength' => 40,
      '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
    );

  
  $form['settings']['footer'] = array(
      '#type' => 'fieldset',
      '#title' => t('Footer settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );

  $form['settings']['footer']['footer_copyright_message'] = array(
      '#type' => 'textarea',
      '#title' => t('Footer copyright message'),
      '#default_value' => theme_get_setting('footer_copyright_message', 'intranet'),
  );

  $form['settings']['footer']['footer_columns'] = array(
      '#type' => 'hidden',
      '#default_value' => 6,
  );

  $form['settings']['footer']['footer_image_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to custom footer image'),
      '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'),
      '#default_value' => theme_get_setting('footer_image_path','intranet'),
    );
    $form['settings']['footer']['footer_image_upload'] = array(
      '#type' => 'file',
      '#title' => t('Upload footer image'),
      '#maxlength' => 40,
      '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
    );
	$form['#submit'][] = 'intranet_system_theme_settings_submit';
}

function intranet_system_theme_settings_submit($form, &$form_state) {
  $settings = array();
  $file = file_save_upload('footer_image_upload');
  $bg_imags = array(
	'bg_image_upload' => 'bg_image_path',
	'header_image_upload' => 'header_image_path',
	'footer_image_upload' => 'footer_image_path',
  );
  foreach ($bg_imags as $upload => $path) {
	    // Check for a new uploaded file, and use that if available.
	  if ($file = file_save_upload($upload)) {
		$parts = pathinfo($file->filename);
		$destination = 'public://' . $parts['basename'];
		$file->status = FILE_STATUS_PERMANENT;
	    if (file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
		 }
		  $form_state['values'][$path] = $destination;
	  }
  }  
}

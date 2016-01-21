<?php

global $base_url;

function intranet_preprocess_html(&$variables) {

  drupal_add_css(base_path() . path_to_theme() . '/styles/style.css', array('type' => 'external'));
  drupal_add_css(base_path() . path_to_theme() . '/styles/icons.css', array('type' => 'external'));
  drupal_add_css(base_path() . path_to_theme() . '/styles/animate.css', array('type' => 'external'));
  drupal_add_css(base_path() . path_to_theme() . '/styles/responsive.css', array('type' => 'external'));
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto:400,300,100,500', array('type' => 'external'));


  $styling = theme_get_setting('styling', 'intranet');
  if ($styling == 'rtl')
    drupal_add_css(base_path() . path_to_theme() . '/styles/rtl.css', array('type' => 'external'));

  //Version background
  $version = theme_get_setting('version_c', 'intranet');
  if ($version == 'dark')
    drupal_add_css(base_path() . path_to_theme() . '/styles/dark.css', array('type' => 'external'));


  drupal_add_css(base_path() . path_to_theme() . '/styles/update.css', array('type' => 'external'));

  //drupal_add_js(base_path().path_to_theme().'/js/jquery.min.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(base_path() . path_to_theme() . '/js/intranet.js', array('type' => 'file', 'scope' => 'footer'));

  drupal_add_js(base_path() . path_to_theme() . '/js/owl.carousel.min.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(base_path() . path_to_theme() . '/js/jquery.ticker.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(base_path() . path_to_theme() . '/js/custom.js', array('type' => 'file', 'scope' => 'footer'));

  $disable_switcher = theme_get_setting('intranet_disable_switch', 'intranet');
  if (empty($disable_switcher))
    $disable_switcher = 'on';
  if (!empty($disable_switcher) && $disable_switcher == 'on') {
    //Style
    drupal_add_js(base_path() . path_to_theme() . '/customizer/script.js', array('type' => 'file', 'scope' => 'footer'));
    drupal_add_css(base_path() . path_to_theme() . '/customizer/style.css', array('type' => 'external'));
    //End style
  }
  drupal_add_js(base_path() . path_to_theme() . '/js/jflickrfeed.js', array('type' => 'file', 'scope' => 'footer'));
  drupal_add_js(base_path() . path_to_theme() . '/js/update.js', array('type' => 'file', 'scope' => 'footer'));
}

function intranet_preprocess_page(&$vars) {

  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }

  //404 page
  $status = drupal_get_http_header("status");
  if ($status == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

  $br_banner_var = array(
    'path' => theme_get_setting('bg_image_path', 'intranet'),
  );
  $vars['bg_image'] = theme('image', $br_banner_var);

  $header_banner_var = array(
    'style_name' => 'header_banner',
    'path' => theme_get_setting('header_image_path', 'intranet'),
    'alt' => 'header_banner',
    'title' => 'Sakal header banner',
    'attributes' => array('class' => 'headerImage'),
  );
  $vars['header_image'] = theme('image_style', $header_banner_var);

  $footer_banner_var = array(
    'style_name' => 'footer_banner', 
    'path' => theme_get_setting('footer_image_path', 'intranet'),
    'alt' => 'footer_banner',
    'title' => 'Sakal footer banner',
    'attributes' => array('class' => 'footerImage'),
  );
  $vars['footer_image'] = theme('image_style', $footer_banner_var);
}

//custom main menu
function intranet_menu_tree__main_menu($variables) {
  $str = '';
  $str .= '<ul class="sf-menu sf-js-enabled sf-shadow">';
  $str .= $variables['tree'];
  $str .= '</ul>';

  return $str;
}

// Remove superfish css files.
function intranet_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);

//	unset($css[drupal_get_path('module', 'system') . '/system.base.css']);
}

function intranet_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#default_value'] = t('Search'); // Set a default value for the textfield
    $form['search_block_form']['#attributes']['id'] = array("mod-search-searchword");
    //disabled submit button
    //unset($form['actions']['submit']);
    unset($form['search_block_form']['#title']);
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search') {this.value = '';}";
  }
}

function intranet_textarea($variables) {
  $element = $variables['element'];
  $element['#attributes']['name'] = $element['#name'];
  $element['#attributes']['id'] = $element['#id'];
  $element['#attributes']['cols'] = $element['#cols'];
  $element['#attributes']['rows'] = $element['#rows'];
  _form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Override or insert variables into the node template.
 */
function intranet_preprocess_node(&$variables) {

  $node = $variables['node'];
  $field_items = field_get_items('node', $node, 'field_linktype');

  $link_type = $field_items[0]['value'];

  if ($variables['view_mode'] == 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }

  if($variables['type']=='cluster_of_links' && $link_type=='All Applications'){
	$content_array=$variables['field_link_details'];
	
	 $field_items1 = field_get_items('node', $node, 'field_link_details');
	
  foreach($field_items1  as $key => $value){
	  $multifield = _multifield_field_item_to_entity('field_link_details', $value);
      $subfield_link = field_get_items('multifield', $multifield, 'field_link');	  
	  $subfield_icon = field_get_items('multifield', $multifield, 'field_clustor_link_icon');
	  
      $link_url=  $subfield_link[0]['display_url'] ;
  	  $link_title=  $subfield_link [0]['title'] ;
      $img_path=$subfield_icon[0]['uri'];
      $image = array(
				   'style_name' => 'all_application',
				   'path' => $img_path,
				   'alt' => '',
				   'title' => ''
			   );
	  		   
      // link elements
      $text = theme('image_style', $image); // in your case it's an image
      $path = $link_url;
      $options = array(
        'attributes' => array(),
        'html' => true
      );
      $items[] = array(
        'data' => l($text, $path, $options),
        'id' => 'all_app_list_'.$key, 
      );
    }
	
	$attributes = array(
     'id' => 'all-app-list' 
    );
	$links_html=theme_item_list(array('items' => $items,  'type' => 'ul','title'=>'', 'attributes' => $attributes));
    $variables['all_applications_record']=$links_html;  
    $variables['theme_hook_suggestions'][] = 'node__teaser_all_app';
  }
  if ($variables['type'] == 'cluster_of_links' && $link_type == 'Quick Links' && ($variables['view_mode'] == 'teaser' || $variables['view_mode'] == 'full')) {
    $variables['theme_hook_suggestions'][] = 'node__teaser_quick_links';
  }
  if ($variables['type'] == 'cxo_messages' && $variables['view_mode'] == 'full') {
    $user = user_load($variables['user']->uid);

    if ($user->picture) {
      $variables['user_picture'] = theme_image_style(
        array(
          'style_name' => 'cxo-message-user',
          'path' => $user->picture->uri,
          'attributes' => array(
            'class' => 'avatar'
          ),
          'width' => "170",
          'height' => "180",
        )
      );
    }
	else{
	   $variables['user_picture'] = theme_image_style(
        array(
          'style_name' => 'cxo-message-user',
          'path' => 'public://detail-user.png',
          'attributes' => array(
            'class' => 'avatar'
          ),
          'width' => "170",
          'height' => "180",
        )
      );
		
	}
	 $variables['date']= date("M j, Y",strtotime($variables['date']));
	 $variables['submitted'] = t('!username on !datetime', 
      array('!username' => $variables['name'], '!datetime' => $variables['date']));
  }
}

function intranet_preprocess_user_login(&$variables) {
  $variables['form']['name']['#title'] = '';
  $variables['form']['name']['#description'] = '';
  $variables['form']['pass']['#title'] = '';
  $variables['form']['pass']['#description'] = '';
}

function intranet_preprocess_link(&$vars) {
  global $user;	
  if (user_is_logged_in() && $vars['path'] == 'user') {
    $vars['text']=check_plain(ucfirst($user->name));
  }	 
}
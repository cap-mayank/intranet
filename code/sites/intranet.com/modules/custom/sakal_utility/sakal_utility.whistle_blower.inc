<?php
/**
 * @file
 * sakal_utility_whistle_blower.inc
 */
 
 /**
 * whristle blower admin settings form to configure whislte blower widget & popup content
 */
function whistle_blower_admin_form($form, &$form_state) {
  $form['whistle_blower_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Whistle Blower Title'),
    '#default_value' => variable_get('whistle_blower_title'),
    '#size' => 50,
    '#maxlength' => 50,
    '#required' => TRUE,
  );
  $whistle_blower_content = variable_get('whistle_blower_content', array('format' => NULL));
  $whistle_blower_content= (is_array($whistle_blower_content)) ? $whistle_blower_content["value"] : $whistle_blower_content;
  $form['whistle_blower_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Whistle Blower Content'),   
    '#default_value' => $whistle_blower_content,
    '#resizable' => FALSE,
    '#wysiwyg' => TRUE,
    '#required' => TRUE,
    '#rows' => 5,
    '#maxlength' => 200,
  );
  
  $whistle_blower_report_incident_content = variable_get('whistle_blower_report_incident_content', array('format' => NULL));
  $whistle_blower_report_incident_content= (is_array($whistle_blower_report_incident_content)) ? $whistle_blower_report_incident_content["value"] : $whistle_blower_report_incident_content;
  $form['whistle_blower_report_incident_content'] = array(
    '#type' => 'text_format',
    '#title' => t('Whistle Blower Report Incident Content'),
    '#default_value' => $whistle_blower_report_incident_content,
    '#resizable' => FALSE, 
    '#wysiwyg' => TRUE,
    '#required' => TRUE,
    '#rows' => 5,
    '#maxlength' => 200,
  );
  
  $form['whistle_blower_to_email'] = array(
   '#type' => 'textfield',
   '#title' => t('Whistle Blower Receiver Email Address'),
   '#description' => t('Enter email-id to receive all comments.'),
     '#required' => TRUE,
    '#default_value' => variable_get('whistle_blower_to_email'),
    );
  return system_settings_form($form);
}

/**
 * Page callback: whristle blower admin settings to configure whistle blower widget & popup content
 */
function whistle_blower_comment_form($form, &$form_state) {
  ctools_include('modal');
  ctools_modal_add_js();   
  $form = array();
  $whistle_blower=variable_get('whistle_blower_report_incident_content');
  $whistle_blower= ( is_array($whistle_blower)) ? $whistle_blower["value"] : $whistle_blower;
  $popup_title= array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array('class' => 'popup_title'),
    '#value' => 'Report Incident'        
  );
  $popup_content= array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array('class' => 'popup_content'),
    '#value' => trim($whistle_blower)
  );
  $form['cutomtext'] = array(
    '#type' => 'item',
    '#markup' => render($popup_title) . render($popup_content),
  );
   $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => t('Comment'),
    '#resizable' => FALSE,
    '#rows' => 10,
    '#cols' => 60,
    '#description' => t('Please enter comment here'),
    '#required' => TRUE,
  );
  $form['department'] = array(
    '#type' => 'select',
    '#title' => t('Department'),
    '#options' => list_of_selected_taxonomy(),
    '#default_value' => '',
    '#description' => t('Please select deparment here'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Report'),
  );
  $form['#prefix'] = '<div id="container" class="whistle_form">';
  $form['#suffix'] = '</div>';
  return $form;
}
/**
 * Page callback: whristle blower Comement form submit 
 */
function whistle_blower_comment_form_submit(&$form, &$form_state) {
  global $user;
  $comment = check_plain($form_state['values']['comment']);
  $department=check_plain($form_state['values']['department']);
  
  if ($comment!='' && $department!='') {
    insert_into_whistle_blower_comment($comment, $department);
  
    //send mail 
    $param['comment']=$comment;
    $param['department']=$department;
    $param['user_name']=$user->name;
    $param['user_email']=$user->mail;
    try {
      $result=whistle_blower_send_mail($param);
      if ($result == TRUE) {
        $msg='Whistle Blower comment has been sent successfully';
      }   
    } 
    catch (Exception $e) {
      //echo 'Caught exception: ',  $e->getMessage(), "\n";
      watchdog('mail', 'Error in  e-mail sending due to %error', array('%error' =>$e->getMessage()), WATCHDOG_ERROR);
      $msg='Whistle Blower comment has not been sent ';    
    }
    $msg='Whistle Blower comment has been sent successfully';    
  }
  else{
    $msg='Unable to send comment due invalid values';
  }
  $msg1= array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#attributes' => array('class' => 'element-invisible'),
    '#value' => 'Status message'        
    );
   $msg2= array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#attributes' => array('class' => 'messages status', 'id' => 'container'),
    '#value' => render($msg1) . $msg
    );
  $posted_data= render($msg2);
  
  // Tell the browser to close the modal.
 // $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][]= ajax_command_replace('#container', $posted_data);  
}

/**
 * Page callback: insert values in db table
 */
function insert_into_whistle_blower_comment($comment, $department) {
  global $user;
  $query = db_insert('sakal_utility_whistle_blower_comment') // Table name no longer needs {}
        ->fields(array(
          'department_id' => $department,
          'uid' => $user->uid,
          'comment' => $comment,
           ))
        ->execute();

}
/**
 * Page callback:send mail afetr submititng comment form 
 */
function whistle_blower_send_mail($param) {
  $module = 'sakal_utility';
  $key = 'whistle_blower';
  $language=language_default();
  $whistle_blower_to=variable_get('whistle_blower_to_email');
  $to=$whistle_blower_to;
  $from = $param['user_email'];
  $params = array(
    'comment' => $param['comment'],
    'department' => get_taxonomy_name_by_id($param['department']), 
    'user_name' => $param['user_name'], 
    'subject' => 'Whistler Blower Comment', 
  );

  // Retrieve the responsible implementation for this message.
  $mail=drupal_mail($module, $key, $to, $language, $params, $from, TRUE);
  if ($mail['result']) {
    $result=TRUE; 
  }
  else{
    $error_msg = 'Failed to send the email';
    watchdog('canvas-email', $error_msg, array(), WATCHDOG_ALERT);
    $result=FALSE;
  }
  return $result;
}
/**
 * Function to get list of taxonomy term by there vocabulaory
 */
function list_of_selected_taxonomy($cat='brand') {
  
  $vocabulary = taxonomy_vocabulary_machine_name_load($cat);
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  /*
  $q=db_select('taxonomy_term_data', 'tta');
  $q->join('taxonomy_vocabulary', 'tv', 'tta.vid = tv.vid');
  $record=$q->fields('tta', array('tid', 'name'))
            ->condition('tv.machine_name', $cat, '=')
            ->execute()
            ->fetchAllAssoc('tid'); */
  $list=array();
  $list['']='--Select Department--';
  if (count($terms)>0) {
    foreach ($terms as $key => $value) {
      $list[$value->tid]=$value->name;
    }
  }
return $list;
}

/**
 * Function to get taxonomy term name by there id
 */
function get_taxonomy_name_by_id($id=NULL) {
  if ($id!=NULL) {
    $name = db_query("SELECT name FROM {taxonomy_term_data} WHERE tid = :id ", array(':id' => $id))->fetchField();
    return $name;
  }
  else
    return NULL;
}
/*
 * Whistle blower callback function after submiting comment form
 */
function whistle_blower_comment_callback($ajax) {
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('Comment Form'),
    );
    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $output = ctools_modal_form_wrapper('whistle_blower_comment_form', $form_state);
    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
    $output = $form_state['ajax_commands'];
    }
    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('whistle_blower_comment_form');
  }
}

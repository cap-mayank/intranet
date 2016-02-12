<?php
/**
 * @file
 * sakal_utility.views.inc
 */

/**
 * Implements hook_views_post_execute().
 */
function sakal_utility_views_post_execute(&$view) {
  global $base_url;  
  if ($view->name == 'policy_and_procedures') {
    
     $new_view=array();
    foreach ($view->result as $key => $value) {
      $insert=TRUE;
      $is_pdf= FALSE;
      if ($value->file_managed_field_data_filedepot_folder_file__filedepot_fil_4=='pdf') {   
        $is_pdf=TRUE;       
      }
      
      if ($value->downloadroles != 1 && $value->readonly == 1 && $is_pdf==TRUE) {        
        //$view->display['policy_block']->handler->display->handler->handlers['field']['title']->options['alter']['path'] = $base_url."/system/files/filedepot/".
        //$value->file_managed_field_data_filedepot_folder_file__filedepot_fil_6 . "/" . $value->file_managed_field_data_filedepot_folder_file__filedepot_fil_5;
      }
      elseif ($value->downloadroles == 0) { 
          unset($view->result[$key]); 
          $insert=FALSE;
        }
      if (isset($value->file_managed_field_data_filedepot_folder_file__filedepot_fil_2)) {
        $cid=$value->file_managed_field_data_filedepot_folder_file__filedepot_fil_2;
        if ($cid) {
          $value->filedepot_categories_filedepot_files_name=parent_folder($cid);
        }
      }
      if ($insert ==TRUE) {
        $new_view[]=$value;
      }
      
    }
    $view->result=$new_view;
    
  }
}
/*
 * Find root folder of file for document Store
 */
function parent_folder($child_id) {
  $pid='';
  $pid = db_query("
    select name, cid, @parent:=pid as prnt
    from
    (select @parent:= :cid ) a
    join
    (select * from {filedepot_categories} order by cid desc) b
    where
    @parent=cid having prnt=0", array(":cid" => $child_id))->fetchField();
  return $pid;
}

/**
 * Implements hook_views_data().
 * Exposed custom table in the view for document store filedepot_files
 * Exposed custom table for role base functionality of document store  filedepot_access
 */
function sakal_utility_views_data() {
  global $user;
  $data = array();
  $data['filedepot_files']['table']['base'] = array(
    'field' => 'fid',
    'title' => t('Filedepot Files'),
    'help' => t("Filedepot files base table"),
  );
  $data['filedepot_files']['table']['join']['file_managed'] = array(
    'left_field' => 'fid',
    'field' => 'drupal_fid',
  );
  $data['filedepot_files']['drupal_fid'] = array(
    'title' => t('Drupal File Id'),
    'help' => t('Some example content that references a node.'),
    'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  // Example integer field.
  $data['filedepot_files']['version'] = array(
    'title' => t('File Version'),
    'help' => t('File Version'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['filedepot_files']['cid'] = array(
    'title' => t('Category Id'),
    'help' => t('Some example content that references a node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'filedepot_categories', // The name of the table to join with.
      'base field' => 'cid', // The name of the field on the joined table.
      'field' => 'cid', //-- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('Default label for the relationship'),
      'title' => t('Title shown when adding the relationship'),
      'help' => t('More information on this relationship'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
   
  );
  
  $data['filedepot_files']['readroles'] = array(
    'title' => t('Readonly permission'),
    'help' => t('Readonly Permission.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
  );
  $data['filedepot_files']['downloadroles'] = array(
    'title' => t('Download permission'),
    'help' => t('Download Permission.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
  );
   $data['filedepot_files']['extension'] = array(
    'title' => t('File Extension'),
    'help' => t('File Extension.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
);
  
 // Applied Role base access 
 $data['filedepot_access']['table']['group'] = t('Filedepot Access');
 $data['filedepot_access']['table']['base'] = array(
    'field' => 'fid',
    'title' => t('Filedepot Access'),
    'help' => t("Filedepot Accesss base table"),
    );
  $data['filedepot_access']['table']['join']['filedepot_categories'] = array(
    'left_field' => 'cid',
    'field' => 'catid',
    );
    $data['filedepot_access']['catid'] = array(
    'title' => t('Access Category Id'),
    'help' => t('Some example content that references a node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'filedepot_categories', // The name of the table to join with.
      'base field' => 'cid', // The name of the field on the joined table.
      'field' => 'catid', //-- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('filedepot_categories with filedepot_access'),
      'title' => t('filedepot_categories with filedepot_access'),
      'help' => t('More information on this relationship'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
   
  );
  
   $data['filedepot_access']['permid'] = array(
    'title' => t('Permission Id'),
    'help' => t('Permission id.'),
    'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users', // The name of the table to join with.
      'base field' => 'uid', // The name of the field on the joined table.
      'field' => 'permid', //-- see hook_views_data_alter(); not needed here.
      'handler' => 'views_handler_relationship',
      'label' => t('filedepot_access_users'),
      'title' => t('filedepot_access_users'),
      'help' => t('More information on this relationship'),
    ),
   );
    $data['filedepot_access']['view'] = array(
    'title' => t('View Access'),
    'help' => t('View Access.'),
    'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
   );
   
   $data['filedepot_access']['permtype'] = array(
    'title' => t('Permission Type'),
    'help' => t('Permission Type.'),
    'field' => array(
        'handler' => 'views_handler_field',
    ),
    'sort' => array(
        'handler' => 'views_handler_sort',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_string',
    ),
);
  return $data;
}


/**
 * Implementation of hook_views_pre_render()
 * To remove file extension from file title
 */
function sakal_utility_views_pre_render(&$view) {
  global $base_url;
  $results = &$view->result;
  if (count($results)>0 && $view->name=='policy_and_procedures' ) {
    foreach ($results as $key => $result) {
      if (isset($result->file_managed_field_data_filedepot_folder_file__filedepot_fil_1)) {
         $view->result[$key]->file_managed_field_data_filedepot_folder_file__filedepot_fil_1 =
          preg_replace('/\\.[^.\\s]{3,4}$/',
            '',
            $result->file_managed_field_data_filedepot_folder_file__filedepot_fil_1);       
     
      }
    }
  }

  //$nodes = node_load_multiple(array_keys($result['node']));
  // Get current year and get the corresponding published holiday calendar which will be unique.
  if ($view->name == "birthdays" && $view-> current_display != "recent_joiner_monthwise") {
		$query = new EntityFieldQuery();
		$result = $query->entityCondition('entity_type', 'node')
			->entityCondition('bundle', 'holiday_calendar')
			->propertyCondition('status', NODE_PUBLISHED)
			->fieldCondition('field_calendar_year','value',date("Y").'-01-01 00:00:00','=')
			->execute();
		$node_id = 0;
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $node_id = node_load($nids[0])->nid;	
    }
		$view->display_handler->set_option('link_display', 'custom_url');
		$view->display_handler->set_option('link_url', 'node/'.$node_id);
	}
}
/**
 * Implementation of hook_views_query_alter()
 * To document store applied role base constraint
 */
function sakal_utility_views_query_alter(&$view, &$query) {
  global $user;
  if ($view->name == "policy_and_procedures" ) {
    $rids = array_keys($user->roles);    
    $subexpression=array();
    foreach ($rids as $key => $values) {
      $subexpression[]= "IF( 
      IF(
      file_managed_field_data_filedepot_folder_file__filedepot_files.readroles IS NULL, 0,
      FIND_IN_SET(
      '" . $values . "',file_managed_field_data_filedepot_folder_file__filedepot_files.readroles
      )
      )>0,1,0
      )";
    }
    $subexpression=implode(' , ', $subexpression);
    $query->set_distinct(TRUE);
    $query->add_field('', 'IF(GREATEST(' . $subexpression . ')>0,1,0)', 'readonly');
     
    $subexpression=array();
    foreach ($rids as $key => $values) {
      $subexpression[]= "IF(
      IF(
      file_managed_field_data_filedepot_folder_file__filedepot_files.downloadroles IS NULL,0, 
      FIND_IN_SET(
      '" . $values . "',file_managed_field_data_filedepot_folder_file__filedepot_files.downloadroles
      )
      )>0,1,0)";
    }
    $subexpression=implode(' , ', $subexpression);
    $query->add_field('', 'IF(GREATEST(' . $subexpression . ')>0,1,0)', 'downloadroles');
    $query->add_where_expression(0, "filedepot_categories_filedepot_files__filedepot_access.permid in ( :user_role)", array(':user_role' => $rids));
    
  }
}


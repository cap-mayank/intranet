<?php
/**
 * @file
 * sakal_utility.views.inc
 */

/**
 * Implements hook_views_post_execute().
 */
function sakal_utility_views_post_execute(&$view) {
  if ($view->name == 'policy_and_procedures') {
    $result_array=$view->result;
    foreach ($result_array as $key => $value) {
      if (isset($value->file_managed_field_data_filedepot_folder_file__filedepot_fil_2)) {
        $cid=$value->file_managed_field_data_filedepot_folder_file__filedepot_fil_2;
        if ($cid) {
          $value->filedepot_categories_filedepot_files_name=parent_folder($cid);
        }
      }
    }
  }
}

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


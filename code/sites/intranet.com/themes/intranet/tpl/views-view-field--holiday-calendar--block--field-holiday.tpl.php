<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
 
?>
<?php 
  print '<div class="holidayIcon"> </div><div class="emptyDiv">&nbsp;</div>';
  $holidays = $row->_field_data['nid']['entity']->field_holiday['und'];
  foreach ($holidays as $key=>$data) {
    print '<div class="holidaywrapper">';
    $date = new DateTime($data['field_publishing_date']['und'][0]['value']);
    $current_date = date('Y-m-d');
    $hdate = $date->format('Y-m-d');
    if ($hdate < $current_date) {
      print '<div class="tick">&nbsp;</div>';
    }
    else {
      print '<div class="untick">&nbsp;</div>';
    }
    print '<div class="holidayDateJF">'.$date->format('j F').'</div>';
    print '<div class="holidayDatel">'.$date->format('l').'</div>';
    print '<div class="holidayName">'.$data['field_holiday_name']['und'][0]['value'].'</div>';
    print '</div>';
  }
 ?>
 

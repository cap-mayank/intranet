<?php
$out = '';
//print_r($block);
//if($block->module=='widget') //remove title
//$block->subject='';

if ($block->region == 'sidebar_first' or $block->region == 'sidebar_second' or $block->region == 'content_bottom') {
  $out .= '<div class="widget ' . $classes . '">';
  $out .= render($title_suffix);
  if ($block->subject && !empty($block->subject)):
    $out .= '<div class="title">';
    $out .= '<h4>' . $block->subject . '</h4>';
    $out .= '</div>';
  endif;
  $out .= $content;
  $out .= '</div>';
}
elseif ($block->region == 'content') {
  $out .= '<div class="mbf clearfix ' . $classes . '">';
  $out .= render($title_suffix);
  if ($block->subject) {
    $out .= '<div class="title colordefault">';
    $out .= '<h4 ' . $title_attributes . '>' . $block->subject . '</h4>';
    $out .= '</div>';
  }
  $out .= $content;
  $out .= '</div>';
}
elseif ($block->region == 'left_bar' || $block->region == 'right_bar' || $block->region == 'top_news') {
  $out .= $content;
}
elseif ($block->region == 'footer_col_one' || $block->region == 'footer_col_two' || $block->region == 'footer_col_three' || $block->region == 'footer_col_four' || $block->region == 'footer_col_five'|| $block->region == 'footer_col_six') {
  $coulm_no = 0;
  switch($block->region){
    case 'footer_col_one' :
	  $coulm_no = 1;
	  break;
	case 'footer_col_two' :
	  $coulm_no = 2;
	  break;
	case 'footer_col_three' :
	  $coulm_no = 3;
	  break;
	case 'footer_col_four' :
	  $coulm_no = 4;
	  break;
	case 'footer_col_five' :
	  $coulm_no = 5;
	  break;
	case 'footer_col_six' :
	  $coulm_no = 6;
	  break;
  }
  $out .= '<div class="widget ' . $classes . '">';
  $out .= render($title_suffix);
  if ($block->subject):
    $out .= '<div class="accordion-section-title " href=".menu-name-menu-footer-menu-'.$coulm_no.'"><h4 ' . $title_attributes . '>' . $block->subject . '</h4></div>';
  endif;
  $out .= $content;
  $out .= '</div>';
}
else {
  $out .= '<div class="' . $classes . '">';
  $out .= render($title_prefix);
  $out .= $content;
  $out .= '</div>';
}
print $out;
?>
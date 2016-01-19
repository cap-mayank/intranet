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
elseif ($block->region == 'footer_col_one' || $block->region == 'footer_col_two' || $block->region == 'footer_col_three' || $block->region == 'footer_col_four') {

  $out .= '<div class="widget ' . $classes . '">';
  $out .= render($title_suffix);
  if ($block->subject):
    $out .= '<div class="title"><h4 ' . $title_attributes . '>' . $block->subject . '</h4></div>';
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
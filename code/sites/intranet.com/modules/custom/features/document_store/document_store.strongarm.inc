<?php
/**
 * @file
 * document_store.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function document_store_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_document_store_date_formate';
  $strongarm->value = 'M j, 2015';
  $export['date_format_document_store_date_formate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_extensions';
  $strongarm->value = 'jpg=jpg.gif, gif=gif.gif, bmp=bmp.gif, doc=doc.gif, docx=doc.gif, xls=xls.gif, xlsx=xls.gif
ppt=ppt.gif, pptx=ppt.gif, mpp=mpp.gif, pdf=pdf.gif, txt=txt.gif, zip=zip.gif
';
  $export['filedepot_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filedepot_yui_baseurl';
  $strongarm->value = '/sites/intranet.com/libraries/yahoolib/';
  $export['filedepot_yui_baseurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_global_upload_max_size';
  $strongarm->value = '3';
  $export['file_global_upload_max_size'] = $strongarm;

  return $export;
}

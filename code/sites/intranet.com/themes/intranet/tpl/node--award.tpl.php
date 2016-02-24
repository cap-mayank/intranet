<?php

/**
 * @file
 * Default theme implementation to display a node.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      $uri = 'public://';
      //$user_picture = !empty($content['body']['#object']->field_user_identity['und'][0]['entity']->picture)?file_create_url($content['body']['#object']->field_user_identity['und'][0]['entity']->picture->uri):file_create_url($uri).'/detail-user.png';
      print($user_picture);
      print('<div class="awardDetailUserName">'.$content['body']['#object']->field_user_identity['und'][0]['entity']->name.'</div>');
      print('<div class="awardDetailDesignation">'.$content['body']['#object']->field_user_identity['und'][0]['entity']->field_designation['und'][0]['value'].'</div>');
      print('<div class="awardDetailDate">'.date_format(date_create($content['body']['#object']->field_publishing_date['und'][0]['value']), 'l, F j, Y').'</div>');
      print('<div class="awardDetailBody">'.$content['body']['#object']->body['und'][0]['value'].'</div>');
    ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
<?php if ($content['#node']->comment and ! ($content['#node']->comment == 1 and $content['#node']->comment_count)) { ?>
  <div class="news_comments">
      <div class="dividerLatest">
        <h4>Comments (<?php print $content['#node']->comment_count; ?>)</h4>
        <div class="gDot"></div>
      </div>
      <div id="comment">
        <ul id="comment-list">
          <?php print render($content['comments']); ?>
        </ul>
      </div>
      <!-- /#comments -->
      <div class="dividerLatest">
        <h4>Leave a comment</h4>
        <div class="gDot"></div>
      </div>
      <?php print str_replace('resizable', '', render($content['comment_form'])); ?>
  </div>
<?php } ?>

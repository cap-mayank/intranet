<li class="comment">
	<?php 
		if($picture):
	?>
	<div class="avatar"><?php print $picture ?></div>
	<?php endif;?>
	<div class="comment-container" <?php if(!$picture) print 'style="margin-left:0px"';?>>
		<h4 class="comment-author"><a><?php print theme('username', array('account' => $content['comment_body']['#object'], 'attributes' => array('class' => 'url'))) ?></a></h4>
		<div class="comment-meta"><a  class="comment-date link-style1"><?php print t('!time ago',array('!time' => format_interval(time() - $content['comment_body']['#object']->created))); ?></a>
		<?php print render($content['links']) ?>
		</div>
		<div class="comment-body">
			<?php hide($content['links']); print render($content) ?>
		</div>
	</div>
</li>
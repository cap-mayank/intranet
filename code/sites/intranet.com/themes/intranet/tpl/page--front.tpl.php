<?php
	//Tracking code
	$layout_settings = theme_get_setting('layout_settings', 'intranet');
	
	if(empty($layout_settings) || !$layout_settings)
		$layout = 'boxed';
	$layout = $layout_settings;
?>
<div id="layout" class="<?php print $layout;?>">
		<?php include_once('header.tpl.php');?>
		<!-- /header -->

		<div class="page-content">
			<div class="row clearfix contentMargin">
				<div class="grid_12 alpha clearfix">
					<?php
						if ($page['top_news']):
					?>
					<div class="intranet_slider mbf">
						<div class="slider_a owl-carouseltheme">
							
							<div class="item clearfix">
							
							<?php 
								print render($page['top_news']);
							?>
							</div><!-- /slide -->

							<!-- /slide -->

						</div><!-- /slider -->
					</div>
							
					<?php	endif; ?>
					

					<div class="grid_12 omega posts righter clearfix">
						<?php
							if ($page['content'] || isset($messages)):
							if(drupal_is_front_page()) {
								unset($page['content']['system_main']['default_message']);
							}
							print $messages;
							print render($page['content']); 
						endif; 
						?>
					</div><!-- end grid9 -->
					<div class="grid_4 alpha sidebar sidebar_b">
					<?php
						if ($page['sidebar_first']):
							//print render($page['sidebar_first']);
						endif;
					?>
					
					</div><!-- end grid9 -->
					
				</div><!-- end grid9 -->

				<div class="grid_3 omega sidebar sidebar_a">
					<?php
						if ($page['sidebar_second']):
							//print render($page['sidebar_second']);
						endif;
					?>
					
					
				</div><!-- /grid3 sidebar A -->
				
			</div><!-- /row -->
			
		</div>
		<!-- /end page content -->
		<?php if ($page['content_bottom']): ?>
		      <div class="grid_full omega content_bottom_front">
					<?php  print render($page['content_bottom']); ?>
			  </div>	
			<?php endif; ?>
		<?php
			include_once('footer.tpl.php');
		?><!-- /footer -->

</div>
<?php
	//Tracking code
	$layout_settings = theme_get_setting('layout_settings', 'intranet');
	
	if(empty($layout_settings) || !$layout_settings)
		$layout = 'boxed';
	$layout = $layout_settings;
?>
<div id="layout" class="<?php print $layout;?> loginLayout">
		
		<div class="page-content loginPage">
			<div class="row clearfix">
			
				<div class="alpha">
					
					<div class="grid_4 alpha posts loginContainerright">
						<?php 						
						  if (isset($messages)):
                print $messages;
							endif;
						?>
              <div class="welcomeLogin"><h1>Welcome</h1><h6>to Sakal Intranet</h6></div>
              <div class="content user-login-container">
                <div class="login-header"><h1>Sakal</h1><h3>Intranet</h3></div>
                  <?php	if ($page['content'] || isset($messages)) ?>
                  <?php print render($page['content']); ?>
                  <php endif; ?>
                  <div class="welcomeLogin">Forgot Fassword</div>
              </div><!-- wellcome login -->
          </div><!-- end grid9 -->
        </div><!-- end grid9 -->
			</div><!-- /row -->
		</div><!-- /end page content -->
	</div><!-- /end page content -->
<?php
	$col_setting = theme_get_setting('footer_columns', 'intranet');
	$col='';
	if ($col_setting=='') {
		$col= 'grid_2';
	}
	if($col_setting==3){
		$col = 'grid_4';
	}if($col_setting >= 4){
		$col = 'grid_2';
	}
?>
<footer id="footer">
<?php print $footer_image;?>
	<div class="row clearfix">
		<?php
			if($page["footer_col_one"]):
		?>
		<div class="<?php echo $col;?>">
			<?php
				print render($page["footer_col_one"]);
			?>
		</div>
		<?php
			endif;
		?>
		
		<?php
			if($page["footer_col_two"]):
		?>
		<div class="<?php echo $col;?>">
			<?php
				print render($page["footer_col_two"]);
			?>
		</div>
		<?php
			endif;
		?>
		<?php
			if($page["footer_col_three"]):
		?>
		<div class="<?php echo $col;?>">
			<?php
				print render($page["footer_col_three"]);
			?>
		</div>
		<?php
			endif;
		?>
		<?php
			if($col_setting >= 4){
				if($page["footer_col_four"]):
			?>
			<div class="<?php echo $col;?>">
				<?php
					print render($page["footer_col_four"]);
				?>
			</div>
			<?php
				endif;
			}
		?>
      
    <?php
		if($col_setting >= 4){
				if($page["footer_col_five"]):
			?>
			<div class="<?php echo $col;?>">
				<?php
					print render($page["footer_col_five"]);
				?>
			</div>
			<?php
				endif;
			}
		?>
      	<?php
        if($col_setting >= 4){
          if($page["footer_col_six"]):
			?>
			<div class="<?php echo $col;?>">
				<?php
					print render($page["footer_col_six"]);
				?>
			</div>
			<?php
				endif;
			}
		?>
      	<div class="logo">
				<?php
					if($logo){
				?>
				<a href="<?php print check_url($front_page); ?>" title="<?php print $site_name; ?>"><img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" /></a>
				<?php }?>
				
			</div>
	</div>
	<!-- /row -->
	<div class="row clearfix">
		<div class="footer_last"><span class="copyright"><?php print theme_get_setting('footer_copyright_message', 'intranet'); ?></span>
			<div id="toTop" class="toptip" ><i class="icon-arrow-thin-up">Top</i></div>
		</div>
		<!-- /last footer -->
	</div>
	<!-- /row -->
</footer>
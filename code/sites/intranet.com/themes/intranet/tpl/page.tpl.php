<div id="layout" class="boxed-margin">
 <?php if (!empty($tabs['#primary']) || !empty($tabs['#secondary'])):
				?>
				<div class="tabsSettings"><span>&nbsp;</span>
				<?php
                print render($tabs);
				?>
				</div>
				<?php
              endif;
			  ?>
  <?php include_once('header.tpl.php'); ?>
  <!-- /header -->
  
  <div class="page-content">
    <div class="row clearfix contentMarginIP">
      <div class="grid_12 alpha clearfix">
        <?php if ($page['top_news']): ?>
          <div class="intranet_slider mbf">
            <div class="slider_a owl-carouseltheme">
              <div class="item clearfix">
                <?php print render($page['top_news']); ?>
              </div><!-- /slide -->
            </div><!-- /slider -->
          </div>
          <?php endif; ?>
          <div class="grid_full alpha posts clearfix">
          <?php
            //if ($breadcrumb):
              //print $breadcrumb;
            //endif; 
            if ($page['content']):
              if (drupal_is_front_page()) {
                unset($page['content']['system_main']['default_message']);
              }
              
            endif;
          ?>
          </div><!-- end grid9 -->
          <?php if (!empty($node)) : ?>
          <div class="grid_full page_title">	
            <?php
            $types = node_type_get_name($node->type);
            print render($types);
            ?>
        </div>
        <?php endif; ?>

        <?php if ($page['sidebar_first']): ?>
          <div class="grid_2 omega sidebar sidebar_b">
              <?php print render($page['sidebar_first']); ?>
          </div><!-- end grid9 -->
        <?php endif; ?>
        <?php if ($page['sidebar_second']): ?>
          <div class="grid_3 omega sidebar sidebar_a" style="float:right;">
              <?php print render($page['sidebar_second']); ?>
          </div><!-- /grid3 sidebar A -->
          <div class="grid_9 omega sidebar sidebar_b mainContent">
            <?php else: ?>
              <div class="grid_full omega sidebar sidebar_b mainContent">
                <?php endif; ?>

                <?php
                if (drupal_get_title())
                  print '<div class="title colordefault" style="clear: both;"><h4>' . drupal_get_title() . '</h4></div>';
                ?>


                <?php print render($page['content']); ?>
            </div><!-- end grid9 -->


        </div><!-- end grid9 -->
      </div><!-- /row -->
    </div>
  </div><!-- /end page content -->
<!-- footer -->
<?php include_once('footer.tpl.php'); ?>
<!-- /footer -->
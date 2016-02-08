<div id="layout" class="boxed-margin loginLayout">
  <div class="page-content loginPage">
    <div class="row clearfix">
      <div class="alpha">
        <div class="grid_4 alpha posts loginContainerright">
          <?php if (isset($messages)): ?>
            <?php print $messages; ?>
          <?php endif; ?>
          <div class="welcomeLogin"><h1>Welcome</h1><h6>to Sakal Intranet</h6></div>
          <div class="content user-login-container">
            <div class="login-header"><h1>Sakal</h1><h3>Intranet</h3></div>
            <?php if ($page['content'] || isset($messages)):  ?>
              <?php print render($page['content']); ?>
            <?php endif; ?>
          </div><!-- wellcome login -->
        </div><!-- end grid9 -->
      </div><!-- end grid9 -->
    </div><!-- /row -->
  </div><!-- /end page content -->
  <div style='display:none;'id="date_time"></div>
</div><!-- /end page content -->
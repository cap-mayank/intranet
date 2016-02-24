(function ($) {
Drupal.theme.prototype.happy_modal = function () {
  var html = '';
  html += '<div id="ctools-modal" class="popups-box">';
  
  html += '<div class="ctools-modal-content ctools-modal-happy-modal-content">';
  html += '<div class="modal-header"><a class="close" href="#">Close Window<img typeof="foaf:Image" src="http://local.intranet.com/profiles/intranet/modules/contrib/ctools/images/icon-close-window.png" alt="Close window" title="Close window"></a>';
  html += '<span id="modal-title" class="modal-title">Anniversary Wish</span></div>';
 // html += '    <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeImage + '</a></span>';
  html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
  html += '  </div>';
  html += '</div>';
  return html;
}
})(jQuery);
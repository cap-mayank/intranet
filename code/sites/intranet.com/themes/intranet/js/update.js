// JavaScript Document

jQuery(document).ready(function(){
	
	//Main menu
	jQuery('ul.sf-menu li a').each(function(){
		$rel = jQuery(this).attr('rel');
		jQuery(this).parent().addClass($rel);
		//alert($rel);
	});
	
	//Search form
	
	jQuery("#search-block-form .form-submit").addClass('tbutton small');
	
	//Top news
	jQuery(".cat-div-top-news a").addClass('cat color1');
	
	jQuery(".cat-post-of-the-day a").addClass('cat');
	jQuery(".cat_div_widget a").addClass('cat color1');
	
	jQuery("#edit-submit--2").addClass('tbutton small');
	jQuery(".block-menu ul li ul").removeClass('sf-menu');
});
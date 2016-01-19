jQuery(document).ready(function ($) {
	/*$('head').append('<link rel="stylesheet" type="text/css" href="customizer/style.css" media="screen" /><style id="themecolors" type="text/css"></style>');*/
	$('head').append('<style id="themecolors" type="text/css"></style>');
	$('body').append('<div class="style-picker"><div class="container bgChanger"><a href="#" class="handler" title="Live Styles Customizer">&nbsp;</a><div class="options clearfix"><div class="grid_6"><span> Layout </span><select name="layouts" id="layouts"><option value="full" class="fullval">Fullwide</option><option value="boxed" class="boxedval">Boxed</option><option value="boxed-margin" selected class="boxedmarginval">Boxed Margin</option></select></div><div class="grid_6"><span> Version </span><select name="version" id="version"><option value="light" class="lightval">Light</option><option value="dark" class="darkval">Dark</option></select></div><div class="cl"><a href="#" class="bgColor">Color Scheme<span id="bgHeaderColor" title="FF0078" style="background-color:#FF0078">&nbsp;</span></a></div></div></div></div>');
	$('.handler').click(function(){
		if ($(this).hasClass('closed')){
			$(this).next('.options').parent().animate({left:0}, 300, function(){
				$(this).find('.handler').removeClass('closed');
			});
		} else {
			$(this).parent().animate({left:'-244px'}, 300, function(){
				$(this).find('.handler').addClass('closed');
			});
		}
		return false;
	});
	$('.handler').parent().delay(1000).animate({left:'-244px'}, 300, function(){
		$(this).find('.handler').addClass('closed');
	});
	
	// L
	if ( $('#layouts').val() == 'full' )
		var prev_bg = $( 'body' ).css( 'background' );
	$('#layouts').change(function(){
		var layouts = $(this).val();
		if( layouts == 'full' ){
			$( '#layout' ).removeClass( 'boxed' ).removeClass( 'boxed-margin' ).addClass( 'full' );
		} else if(layouts == 'boxed') {
			$( '#layout' ).removeClass( 'full' ).removeClass( 'boxed-margin' ).addClass( 'boxed' );
		} else if(layouts == 'boxed-margin') {
			$( '#layout' ).removeClass( 'full' ).removeClass( 'boxed' ).addClass( 'boxed-margin' );
		}

		$(window).trigger('resize');
	});
	
	// V
	$('body').append('<div class="versionss"></div>');
	$('#version').change(function(){
		var version = $(this).val();
		if( version == 'light' ){
			$('.versionss').html('');
			$('.logo a').html('<img src="images/logo.png">');
		} else if(version == 'dark') {
			$('.versionss').html('<link rel="stylesheet" type="text/css" href="sites/all/themes/intranet/styles/dark.css" id="dark" media="screen" />');
			$('.logo a').html('<img src="sites/all/themes/intranet/images/logo_dark.png">');
		}
		$(window).trigger('resize');
	});
	
	// C Scheme
	$('.style-picker #bgHeaderColor').parent('a').ColorPicker({
		onChange:function(hsb, hex, rgb){
			$('.style-picker').find('#bgHeaderColor').css({backgroundColor:'#' + hex});
			$('style#themecolors').html('a:hover, #footer a:hover, #newsletters button:hover, #header .search button:hover { color: #' + hex + ' } #mobilepro:hover, .title.colordefault, .cat.colordefault, li.colordefault:hover > a, li.colordefault li:hover > a, li.current.colordefault, .share_post span, .pagination-tt ul li a, .wp-polls input.Buttons, .owl-theme .owl-controls.clickable .owl-buttons div:hover, .small_posts .s_thumb span, #layerBall:after, .inner_f, .right_icons a:hover, .search_icon i:hover, .search_icon i.activeated_search, #contactForm #sendMessage, .tags a:hover, #wp-calendar #today, .accordion-head-sign,.toggle-head-sign, .tbutton {background-color: #' + hex + ' !important} .s_form, #track_input:focus, #contactForm #senderName:focus, #contactForm #senderEmail:focus, #contactForm #message:focus {border-color: #' + hex + ' !important} ::selection{background:#' + hex + ' !important} ::-moz-selection{background:#' + hex + ' !important} .s_form:after {border-bottom: 6px solid #' + hex + '} #layerBall { box-shadow: 0 0 1px #' + hex + '}#layerBall:before {box-shadow: 0 0 4px #' + hex + '} .colordefault.title:after {border-top-color: #' + hex + ' !important} .colordefault.cat:after {border-left-color: #' + hex + ' !important} a.cat{background:#'+hex+'!important} .post_day .relative .cat:after, .cat-post-of-the-day a:after{border-left:5px solid #'+hex+'!important}');
			$('.colorss').html('<div class="colorss"><link rel="stylesheet" type="text/css" href="" media="screen"></div>');
		},
		onSubmit:function(hsb, hex, rgb, el){
			$(el).find('#bgHeaderColor').css({backgroundColor:'#' + hex});
			$(el).find('#bgHeaderColor').attr({title:hex});
			$(el).ColorPickerHide();
		},
		onBeforeShow:function(){
		    var hex = $('.style-picker').find('#bgHeaderColor').attr('title');
			$(this).ColorPickerSetColor(hex); 
		}
	});

	// BG
	$('.style-picker #bgColor').parent('a').ColorPicker({
		onChange:function(hsb, hex, rgb){
			$('.style-picker').find('#bgColor').css({backgroundColor:'#' + hex});
			$('body').css({'background':'#' + hex});
		},
		onSubmit:function(hsb, hex, rgb, el){
			$(el).find('#bgColor').css({backgroundColor:'#' + hex});
			$(el).find('#bgColor').attr({title:hex});
			$('body').css({'background':'#' + hex});
			$(el).ColorPickerHide();
		},
		onBeforeShow:function(){
		    var hex = $('.style-picker').find('#bgColor').attr('title');
			$(this).ColorPickerSetColor(hex); 
		}
	});
	$('.style-picker a.bgBody').click(function(){
		var imgUrl = $(this).attr('rel');
		$('#layout').removeClass('full').addClass('boxed-margin');
		$('body').css({'background-image':"url('"+imgUrl+"')", "background-attachment":"fixed", "background-position":"top center", "-webkit-background-size":"initial", "-moz-background-size":"initial", "background-size":"initial", "background-repeat":"repeat"});
		return false;
	});
	
});

(function(e){var t=function(){var t={},n,r=65,i,s='<div class="colorpicker"><div class="colorpicker_color"><div><div></div></div></div><div class="colorpicker_hue"><div></div></div><div class="colorpicker_new_color"></div><div class="colorpicker_current_color"></div><div class="colorpicker_hex"><input type="text" maxlength="6" size="6" /></div><div class="colorpicker_rgb_r colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_rgb_g colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_rgb_b colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_hsb_h colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_hsb_s colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_hsb_b colorpicker_field"><input type="text" maxlength="3" size="3" /><span></span></div><div class="colorpicker_submit"></div></div>',o={eventName:"click",onShow:function(){},onBeforeShow:function(){},onHide:function(){},onChange:function(){},onSubmit:function(){},color:"ff0000",livePreview:true,flat:false},u=function(t,n){var r=q(t);e(n).data("colorpicker").fields.eq(1).val(r.r).end().eq(2).val(r.g).end().eq(3).val(r.b).end()},a=function(t,n){e(n).data("colorpicker").fields.eq(4).val(t.h).end().eq(5).val(t.s).end().eq(6).val(t.b).end()},f=function(t,n){e(n).data("colorpicker").fields.eq(0).val(U(t)).end()},l=function(t,n){e(n).data("colorpicker").selector.css("backgroundColor","#"+U({h:t.h,s:100,b:100}));e(n).data("colorpicker").selectorIndic.css({left:parseInt(150*t.s/100,10),top:parseInt(150*(100-t.b)/100,10)})},c=function(t,n){e(n).data("colorpicker").hue.css("top",parseInt(150-150*t.h/360,10))},h=function(t,n){e(n).data("colorpicker").currentColor.css("backgroundColor","#"+U(t))},p=function(t,n){e(n).data("colorpicker").newColor.css("backgroundColor","#"+U(t))},d=function(t){var n=t.charCode||t.keyCode||-1;if(n>r&&n<=90||n==32){return false}var i=e(this).parent().parent();if(i.data("colorpicker").livePreview===true){v.apply(this)}},v=function(t){var n=e(this).parent().parent(),r;if(this.parentNode.className.indexOf("_hex")>0){n.data("colorpicker").color=r=F(B(this.value))}else if(this.parentNode.className.indexOf("_hsb")>0){n.data("colorpicker").color=r=P({h:parseInt(n.data("colorpicker").fields.eq(4).val(),10),s:parseInt(n.data("colorpicker").fields.eq(5).val(),10),b:parseInt(n.data("colorpicker").fields.eq(6).val(),10)})}else{n.data("colorpicker").color=r=I(H({r:parseInt(n.data("colorpicker").fields.eq(1).val(),10),g:parseInt(n.data("colorpicker").fields.eq(2).val(),10),b:parseInt(n.data("colorpicker").fields.eq(3).val(),10)}))}if(t){u(r,n.get(0));f(r,n.get(0));a(r,n.get(0))}l(r,n.get(0));c(r,n.get(0));p(r,n.get(0));n.data("colorpicker").onChange.apply(n,[r,U(r),q(r)])},m=function(t){var n=e(this).parent().parent();n.data("colorpicker").fields.parent().removeClass("colorpicker_focus")},g=function(){r=this.parentNode.className.indexOf("_hex")>0?70:65;e(this).parent().parent().data("colorpicker").fields.parent().removeClass("colorpicker_focus");e(this).parent().addClass("colorpicker_focus")},y=function(t){var n=e(this).parent().find("input").focus();var r={el:e(this).parent().addClass("colorpicker_slider"),max:this.parentNode.className.indexOf("_hsb_h")>0?360:this.parentNode.className.indexOf("_hsb")>0?100:255,y:t.pageY,field:n,val:parseInt(n.val(),10),preview:e(this).parent().parent().data("colorpicker").livePreview};e(document).bind("mouseup",r,w);e(document).bind("mousemove",r,b)},b=function(e){e.data.field.val(Math.max(0,Math.min(e.data.max,parseInt(e.data.val+e.pageY-e.data.y,10))));if(e.data.preview){v.apply(e.data.field.get(0),[true])}return false},w=function(t){v.apply(t.data.field.get(0),[true]);t.data.el.removeClass("colorpicker_slider").find("input").focus();e(document).unbind("mouseup",w);e(document).unbind("mousemove",b);return false},E=function(t){var n={cal:e(this).parent(),y:e(this).offset().top};n.preview=n.cal.data("colorpicker").livePreview;e(document).bind("mouseup",n,x);e(document).bind("mousemove",n,S)},S=function(e){v.apply(e.data.cal.data("colorpicker").fields.eq(4).val(parseInt(360*(150-Math.max(0,Math.min(150,e.pageY-e.data.y)))/150,10)).get(0),[e.data.preview]);return false},x=function(t){u(t.data.cal.data("colorpicker").color,t.data.cal.get(0));f(t.data.cal.data("colorpicker").color,t.data.cal.get(0));e(document).unbind("mouseup",x);e(document).unbind("mousemove",S);return false},T=function(t){var n={cal:e(this).parent(),pos:e(this).offset()};n.preview=n.cal.data("colorpicker").livePreview;e(document).bind("mouseup",n,C);e(document).bind("mousemove",n,N)},N=function(e){v.apply(e.data.cal.data("colorpicker").fields.eq(6).val(parseInt(100*(150-Math.max(0,Math.min(150,e.pageY-e.data.pos.top)))/150,10)).end().eq(5).val(parseInt(100*Math.max(0,Math.min(150,e.pageX-e.data.pos.left))/150,10)).get(0),[e.data.preview]);return false},C=function(t){u(t.data.cal.data("colorpicker").color,t.data.cal.get(0));f(t.data.cal.data("colorpicker").color,t.data.cal.get(0));e(document).unbind("mouseup",C);e(document).unbind("mousemove",N);return false},k=function(t){e(this).addClass("colorpicker_focus")},L=function(t){e(this).removeClass("colorpicker_focus")},A=function(t){var n=e(this).parent();var r=n.data("colorpicker").color;n.data("colorpicker").origColor=r;h(r,n.get(0));n.data("colorpicker").onSubmit(r,U(r),q(r),n.data("colorpicker").el)},O=function(t){var n=e("#"+e(this).data("colorpickerId"));n.data("colorpicker").onBeforeShow.apply(this,[n.get(0)]);var r=e(this).offset();var i=D();var s=r.top+this.offsetHeight;var o=r.left;if(s+176>i.t+i.h){s-=this.offsetHeight+176}if(o+356>i.l+i.w){o-=356}n.css({left:o+"px",top:s+"px"});if(n.data("colorpicker").onShow.apply(this,[n.get(0)])!=false){n.show()}e(document).bind("mousedown",{cal:n},M);return false},M=function(t){if(!_(t.data.cal.get(0),t.target,t.data.cal.get(0))){if(t.data.cal.data("colorpicker").onHide.apply(this,[t.data.cal.get(0)])!=false){t.data.cal.hide()}e(document).unbind("mousedown",M)}},_=function(e,t,n){if(e==t){return true}if(e.contains){return e.contains(t)}if(e.compareDocumentPosition){return!!(e.compareDocumentPosition(t)&16)}var r=t.parentNode;while(r&&r!=n){if(r==e)return true;r=r.parentNode}return false},D=function(){var e=document.compatMode=="CSS1Compat";return{l:window.pageXOffset||(e?document.documentElement.scrollLeft:document.body.scrollLeft),t:window.pageYOffset||(e?document.documentElement.scrollTop:document.body.scrollTop),w:window.innerWidth||(e?document.documentElement.clientWidth:document.body.clientWidth),h:window.innerHeight||(e?document.documentElement.clientHeight:document.body.clientHeight)}},P=function(e){return{h:Math.min(360,Math.max(0,e.h)),s:Math.min(100,Math.max(0,e.s)),b:Math.min(100,Math.max(0,e.b))}},H=function(e){return{r:Math.min(255,Math.max(0,e.r)),g:Math.min(255,Math.max(0,e.g)),b:Math.min(255,Math.max(0,e.b))}},B=function(e){var t=6-e.length;if(t>0){var n=[];for(var r=0;r<t;r++){n.push("0")}n.push(e);e=n.join("")}return e},j=function(e){var e=parseInt(e.indexOf("#")>-1?e.substring(1):e,16);return{r:e>>16,g:(e&65280)>>8,b:e&255}},F=function(e){return I(j(e))},I=function(e){var t={h:0,s:0,b:0};var n=Math.min(e.r,e.g,e.b);var r=Math.max(e.r,e.g,e.b);var i=r-n;t.b=r;if(r!=0){}t.s=r!=0?255*i/r:0;if(t.s!=0){if(e.r==r){t.h=(e.g-e.b)/i}else if(e.g==r){t.h=2+(e.b-e.r)/i}else{t.h=4+(e.r-e.g)/i}}else{t.h=-1}t.h*=60;if(t.h<0){t.h+=360}t.s*=100/255;t.b*=100/255;return t},q=function(e){var t={};var n=Math.round(e.h);var r=Math.round(e.s*255/100);var i=Math.round(e.b*255/100);if(r==0){t.r=t.g=t.b=i}else{var s=i;var o=(255-r)*i/255;var u=(s-o)*(n%60)/60;if(n==360)n=0;if(n<60){t.r=s;t.b=o;t.g=o+u}else if(n<120){t.g=s;t.b=o;t.r=s-u}else if(n<180){t.g=s;t.r=o;t.b=o+u}else if(n<240){t.b=s;t.r=o;t.g=s-u}else if(n<300){t.b=s;t.g=o;t.r=o+u}else if(n<360){t.r=s;t.g=o;t.b=s-u}else{t.r=0;t.g=0;t.b=0}}return{r:Math.round(t.r),g:Math.round(t.g),b:Math.round(t.b)}},R=function(t){var n=[t.r.toString(16),t.g.toString(16),t.b.toString(16)];e.each(n,function(e,t){if(t.length==1){n[e]="0"+t}});return n.join("")},U=function(e){return R(q(e))},z=function(){var t=e(this).parent();var n=t.data("colorpicker").origColor;t.data("colorpicker").color=n;u(n,t.get(0));f(n,t.get(0));a(n,t.get(0));l(n,t.get(0));c(n,t.get(0));p(n,t.get(0))};return{init:function(t){t=e.extend({},o,t||{});if(typeof t.color=="string"){t.color=F(t.color)}else if(t.color.r!=undefined&&t.color.g!=undefined&&t.color.b!=undefined){t.color=I(t.color)}else if(t.color.h!=undefined&&t.color.s!=undefined&&t.color.b!=undefined){t.color=P(t.color)}else{return this}return this.each(function(){if(!e(this).data("colorpickerId")){var n=e.extend({},t);n.origColor=t.color;var r="collorpicker_"+parseInt(Math.random()*1e3);e(this).data("colorpickerId",r);var i=e(s).attr("id",r);if(n.flat){i.appendTo(this).show()}else{i.appendTo(document.body)}n.fields=i.find("input").bind("keyup",d).bind("change",v).bind("blur",m).bind("focus",g);i.find("span").bind("mousedown",y).end().find(">div.colorpicker_current_color").bind("click",z);n.selector=i.find("div.colorpicker_color").bind("mousedown",T);n.selectorIndic=n.selector.find("div div");n.el=this;n.hue=i.find("div.colorpicker_hue div");i.find("div.colorpicker_hue").bind("mousedown",E);n.newColor=i.find("div.colorpicker_new_color");n.currentColor=i.find("div.colorpicker_current_color");i.data("colorpicker",n);i.find("div.colorpicker_submit").bind("mouseenter",k).bind("mouseleave",L).bind("click",A);u(n.color,i.get(0));a(n.color,i.get(0));f(n.color,i.get(0));c(n.color,i.get(0));l(n.color,i.get(0));h(n.color,i.get(0));p(n.color,i.get(0));if(n.flat){i.css({position:"relative",display:"block"})}else{e(this).bind(n.eventName,O)}}})},showPicker:function(){return this.each(function(){if(e(this).data("colorpickerId")){O.apply(this)}})},hidePicker:function(){return this.each(function(){if(e(this).data("colorpickerId")){e("#"+e(this).data("colorpickerId")).hide()}})},setColor:function(t){if(typeof t=="string"){t=F(t)}else if(t.r!=undefined&&t.g!=undefined&&t.b!=undefined){t=I(t)}else if(t.h!=undefined&&t.s!=undefined&&t.b!=undefined){t=P(t)}else{return this}return this.each(function(){if(e(this).data("colorpickerId")){var n=e("#"+e(this).data("colorpickerId"));n.data("colorpicker").color=t;n.data("colorpicker").origColor=t;u(t,n.get(0));a(t,n.get(0));f(t,n.get(0));c(t,n.get(0));l(t,n.get(0));h(t,n.get(0));p(t,n.get(0))}})}}}();e.fn.extend({ColorPicker:t.init,ColorPickerHide:t.hidePicker,ColorPickerShow:t.showPicker,ColorPickerSetColor:t.setColor})})(jQuery)
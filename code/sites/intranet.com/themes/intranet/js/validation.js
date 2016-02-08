(function ($) {
	  Drupal.behaviors.intranet = {
    attach: function (context, settings) {
		 //alert(settings.intranet.file_global_upload_max_size);
		
		  $(document).ready(function(){
		  var max_size_bytes=settings.intranet_settings.file_global_upload_max_size_bytes;
		  var max_size=settings.intranet_settings.file_global_upload_max_size;
		  $("input[type='file']").each(function( intIndex){
				var $this=	$(this);
			  $this.bind('change', function() {	
			  checkFileSize(this); });
			  
		  });
		  
		  function  checkFileSize(obj){
					//alert(obj.files[0].size);
					if(obj.files[0].size > max_size_bytes){
						alert("Selected file is unbale to upload it exceeds "+max_size+" MB, the maximum allowed size for uploads");
						$(obj).val("");			
					
						return false;
					}
		  }
			
		})
		
		 }
  };

		  
	
})(jQuery);